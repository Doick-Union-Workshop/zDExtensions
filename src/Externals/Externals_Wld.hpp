namespace GOTHIC_NAMESPACE
{
    template<typename T>
    static void Wld_InsertVob(const zSTRING& t_vobName, const zSTRING& t_pointName)
    {
        if (t_vobName.IsEmpty() || t_pointName.IsEmpty())
            return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Wld_InsertVob");

        zSTRING vobName = zSTRING(t_vobName).Upper();
        zSTRING pointName = zSTRING(t_pointName).Upper();
        T* vob = new T{};
        oCWorld* world = ogame->GetGameWorld();
        zCWaypoint* wp = world->wayNet->GetWaypoint(pointName);
        zVEC3 pos;

        if (wp) {
            pos = wp->GetPositionWorld();
        }
        else
        {
            zCVob* pointVob = FindVobByName(t_pointName, log);

            if (!pointVob)
            {
                log->Error("No Vob found with specified name: {0}", pointName.ToChar());
                vob->Release();
                return;
            }

            pos = pointVob->GetPositionWorld();
        }

        vob->SetVobName(vobName);
        world->AddVob(vob);
        SetVobPositionWorld(vob, pos);
        vob->Release();
    }

    template<typename T>
    static void Wld_InsertVobPos(const zSTRING& t_vobName, C_POSITION* t_vobPosition)
    {
        if (t_vobName.IsEmpty() || !t_vobPosition)
            return;

        zSTRING vobName = zSTRING(t_vobName).Upper();
        T* vob = new T{};
        zVEC3 pos = zVEC3(
            (float)t_vobPosition->X,
            (float)t_vobPosition->Y,
            (float)t_vobPosition->Z
        );
        vob->SetVobName(vobName);
        ogame->GetGameWorld()->AddVob(vob);
        SetVobPositionWorld(vob, pos);
        vob->Release();
    }

    static int Wld_RemoveVob(const zSTRING& t_vobName)
    {
        if (t_vobName.IsEmpty()) return 0;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Wld_RemoveVob");

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return 0;

        ogame->GetGameWorld()->RemoveVob(vob);
        vob->Release();
        return 1;
    }

    static C_POSITION* Wld_GetPos(const int t_posX, const int t_posY, const int t_posZ)
    {
        C_POSITION* vobPosition = new C_POSITION;
        vobPosition->X = t_posX;
        vobPosition->Y = t_posY;
        vobPosition->Z = t_posZ;
        return vobPosition;
    }

    static zSTRING Wld_GetPlayerPortalRoom()
    {
        if (zSTRING* name = ogame->GetPortalRoomManager()->curPlayerPortal)
            return *name;
        return zSTRING{};
    }

    static int Wld_IsDay()
    {
        return ogame->GetWorldTimer()->IsDay(); // 6,30-18,30
    }

    static int Wld_IsNight()
    {
		return ogame->GetWorldTimer()->IsNight(); // 18,30-6,30
    }

    static zSTRING Wld_GetWorldName()
    {
	    return ogame->GetGameWorld()->GetWorldName();
    }

    static int Wld_SetRainTime(const int t_startHr, const int t_startMin, const int t_endHr, const int t_endMin)
    {
        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Wld_SetRainTime");

        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());

        if (!skyCtrl)
        {
            log->Error("zCSkyControler_Outdoor not found");
            return 0;
        }

        if (ogame->GetWorldTimer()->IsTimeBetween(t_startHr, t_startMin, t_endHr, t_endMin))
        {
            int startHr = (t_startHr + 12) % 24;
            int endHr = (t_endHr + 12) % 24;

            if (startHr > endHr)
            {
                log->Error("Rain at 12 noon is not possible!");
                return 0;
            }

            float startF = GetTimeAsFraction(startHr, t_startMin);
            float endF = GetTimeAsFraction(endHr, t_endMin);

            skyCtrl->rainFX.timeStartRain = startF;
            skyCtrl->rainFX.timeStopRain = endF;

            return 1;
        }

        return 0;
    }

    static void Wld_SetRainOn()
    {
        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());

        if (!skyCtrl) return;

        skyCtrl->rainFX.timeStartRain = 0;
        skyCtrl->rainFX.timeStopRain = 1.0f;
    }

    static void Wld_SetRainOff()
    {
        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());

        if (!skyCtrl) return;

        skyCtrl->rainFX.timeStartRain = 0;
        skyCtrl->rainFX.timeStopRain = 0;
        skyCtrl->rainFX.soundVolume = 0;

        if (!skyCtrl->rainFX.outdoorRainFX) return;

		skyCtrl->rainFX.outdoorRainFX->UpdateSound(0);
    }

    static void Wld_OverrideWorldFogColors(const int t_index, const zSTRING& t_color) // WIP
    {
        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Wld_OverrideWorldFogColors");

        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());

        if (!skyCtrl)
        {
            log->Error("zCSkyControler_Outdoor not found");
            return;
        }

        zVEC3 color = GetColorFromString(t_color);
        skyCtrl->fogColorDayVariations.Insert(color);
    }
}
