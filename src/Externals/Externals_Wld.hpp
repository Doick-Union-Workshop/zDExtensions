namespace GOTHIC_NAMESPACE
{
    template<typename T>
    void Wld_InsertVob(const zSTRING& t_vobName, const zSTRING& t_pointName)
    {
        if (t_vobName.IsEmpty() || t_pointName.IsEmpty()) {
            return;
        }

        static auto logger = Utils::CreateLogger("zDExt::Externals::Wld_InsertVob");

        zSTRING vobName = Str_Upper(t_vobName);
        zSTRING pointName = Str_Upper(t_pointName);
        T* vob = new T{};
        oCWorld* world = ogame->GetGameWorld();
        zCWaypoint* wp = world->wayNet->GetWaypoint(pointName);
        zVEC3 pos;

        if (wp) {
            pos = wp->GetPositionWorld();
        }
        else
        {
            zCVob* pointVob = FindVobByName(t_pointName, logger);
            if (!pointVob)
            {
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
    void Wld_InsertVobPos(const zSTRING& t_vobName, const int t_posX, const int t_posY, const int t_posZ)
    {
        if (t_vobName.IsEmpty()) {
            return;
        }

        zSTRING vobName = Str_Upper(t_vobName);
        T* vob = new T{};
        zVEC3 pos = zVEC3(
            (float)t_posX,
            (float)t_posY,
            (float)t_posZ);
        vob->SetVobName(vobName);
        ogame->GetGameWorld()->AddVob(vob);
        SetVobPositionWorld(vob, pos);
        vob->Release();
    }

    int Wld_RemoveVob(const zSTRING& t_vobName)
    {
        if (t_vobName.IsEmpty()) {
            return 0;
        }

        static auto logger = Utils::CreateLogger("zDExt::Externals::Wld_RemoveVob");

        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob) {
            return 0;
        }

        ogame->GetGameWorld()->RemoveVob(vob);
        return 1;
    }

    zSTRING Wld_GetPlayerPortalRoom()
    {
        if (zSTRING* name = ogame->GetPortalRoomManager()->curPlayerPortal) {
            return *name;
        }

        return zSTRING{};
    }

    zSTRING Wld_GetWorldName()
    {
	    return ogame->GetGameWorld()->GetWorldName();
    }

    int Wld_SetRainTime(const int t_startHr, const int t_startMin, const int t_endHr, const int t_endMin)
    {
        static auto logger = Utils::CreateLogger("zDExt::Externals::Wld_SetRainTime");

        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());
        if (!skyCtrl)
        {
            logger->Error("zCSkyControler_Outdoor not found");
            return 0;
        }

        if (ogame->GetWorldTimer()->IsTimeBetween(t_startHr, t_startMin, t_endHr, t_endMin))
        {
            int startHr = (t_startHr + 12) % 24;
            int endHr = (t_endHr + 12) % 24;

            if (startHr > endHr)
            {
                logger->Error("Rain at 12 noon is not possible!");
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

    void Wld_SetRainOn()
    {
        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());
        if (!skyCtrl) {
            return;
        }

        skyCtrl->rainFX.timeStartRain = 0;
        skyCtrl->rainFX.timeStopRain = 1.0f;
    }

    void Wld_SetRainOff()
    {
        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());
        if (!skyCtrl) {
            return;
        }

        skyCtrl->rainFX.timeStartRain = 0;
        skyCtrl->rainFX.timeStopRain = 0;
        skyCtrl->rainFX.soundVolume = 0;

        if (!skyCtrl->rainFX.outdoorRainFX) {
            return;
        }

		skyCtrl->rainFX.outdoorRainFX->UpdateSound(0);
    }

    void Wld_OverrideWorldFogColors(const int t_index, const zSTRING& t_color) // WIP
    {
        static auto logger = Utils::CreateLogger("zDExt::Externals::Wld_OverrideWorldFogColors");

        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());
        if (!skyCtrl)
        {
            logger->Error("zCSkyControler_Outdoor not found");
            return;
        }

        zVEC3 color = GetColorFromString(t_color);
        skyCtrl->fogColorDayVariations.Insert(color);
    }
}
