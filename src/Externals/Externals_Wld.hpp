namespace GOTHIC_NAMESPACE
{
    template<typename T>
    void Wld_InsertVob(const zSTRING& t_vobName, const zSTRING& t_pointName)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Wld_InsertVob");

        zSTRING pointName{ t_pointName };
        pointName.Upper();

        auto pos = GetWaypointPosition(t_pointName, logger);
        if (!pos)
        {
            return;
        }

        zSTRING vobName{ t_vobName };
        vobName.Upper();

        T* vob = new T{};
        vob->SetVobName(vobName);
        ogame->GetGameWorld()->AddVob(vob);
        SetVobPositionWorld(vob, pos.value());
        vob->Release();
    }

    template<typename T>
    void Wld_InsertVobPos(const zSTRING& t_vobName, const int t_posX, const int t_posY, const int t_posZ)
    {
        zSTRING vobName{ t_vobName };
        vobName.Upper();

        T* vob = new T{};
        auto pos = zVEC3((float)t_posX, (float)t_posY, (float)t_posZ);

        vob->SetVobName(vobName);
        ogame->GetGameWorld()->AddVob(vob);
        SetVobPositionWorld(vob, pos);
        vob->Release();
    }

    int Wld_RemoveVob(const zSTRING& t_vobName)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Wld_RemoveVob");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return 0;
        }

        ogame->GetGameWorld()->RemoveVob(vob);
        return 1;
    }

    zSTRING Wld_GetPlayerPortalRoom()
    {
        if (zSTRING* name = ogame->GetPortalRoomManager()->curPlayerPortal)
        {
            return *name;
        }
        return {};
    }

    zSTRING Wld_GetWorldName()
    {
	    return ogame->GetGameWorld()->GetWorldName();
    }

    int Wld_SetRainTime(const int t_startHour, const int t_startMin, const int t_endHour, const int t_endMin)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Wld_SetRainTime");

        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());
        if (!skyCtrl)
        {
            logger->Error("zCSkyControler_Outdoor not found");
            return 0;
        }

        if (ogame->GetWorldTimer()->IsTimeBetween(t_startHour, t_startMin, t_endHour, t_endMin))
        {
            int startHour = (t_startHour + 12) % 24;
            int endHour = (t_endHour + 12) % 24;

            if (startHour > endHour)
            {
                logger->Error("Rain at 12 noon is not possible!");
                return 0;
            }

            float startF = GetTimeAsFraction(startHour, t_startMin);
            float endF = GetTimeAsFraction(endHour, t_endMin);

            skyCtrl->rainFX.timeStartRain = startF;
            skyCtrl->rainFX.timeStopRain = endF;

            return 1;
        }

        return 0;
    }

    void Wld_SetRainOn()
    {
        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());
        if (!skyCtrl)
        {
            return;
        }

        skyCtrl->rainFX.timeStartRain = 0;
        skyCtrl->rainFX.timeStopRain = 1.0f;
    }

    void Wld_SetRainOff()
    {
        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());
        if (!skyCtrl)
        {
            return;
        }

        skyCtrl->rainFX.timeStartRain = 0;
        skyCtrl->rainFX.timeStopRain = 0;
        skyCtrl->rainFX.soundVolume = 0;

        if (!skyCtrl->rainFX.outdoorRainFX)
        {
            return;
        }

		skyCtrl->rainFX.outdoorRainFX->UpdateSound(0);
    }

    void Wld_OverrideWorldFogColors(const int t_index, const zSTRING& t_color) // WIP
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Wld_OverrideWorldFogColors");

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
