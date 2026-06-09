namespace GOTHIC_NAMESPACE
{
    template<typename T>
    void zDExt_Wld_InsertVob(const zSTRING& t_vobName, const zSTRING& t_pointName)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Wld_InsertVob");

        zSTRING pointName{ t_pointName };
        (void)pointName.Upper();

        auto pos = GetWaypointPosition(t_pointName, logger);
        if (!pos)
        {
            return;
        }

        zSTRING vobName{ t_vobName };
        (void)vobName.Upper();

        T* vob = new T{};
        vob->SetVobName(vobName);
        ogame->GetGameWorld()->AddVob(vob);
        SetVobPositionWorld(vob, pos.value());
        vob->Release();
    }

    template<typename T>
    void zDExt_Wld_InsertVobPos(const zSTRING& t_vobName, const int t_posX, const int t_posY, const int t_posZ)
    {
        zSTRING vobName{ t_vobName };
        (void)vobName.Upper();

        T* vob = new T{};
        auto pos = zVEC3((float)t_posX, (float)t_posY, (float)t_posZ);

        vob->SetVobName(vobName);
        ogame->GetGameWorld()->AddVob(vob);
        SetVobPositionWorld(vob, pos);
        vob->Release();
    }

    int zDExt_Wld_RemoveVob(const zSTRING& t_vobName)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Wld_RemoveVob");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return 0;
        }

        ogame->GetGameWorld()->RemoveVob(vob);
        return 1;
    }

    zSTRING zDExt_Wld_GetPlayerPortalRoom()
    {
        if (zSTRING* name = ogame->GetPortalRoomManager()->curPlayerPortal)
        {
            return *name;
        }

        return {};
    }

    zSTRING zDExt_Wld_GetWorldName()
    {
	    return ogame->GetGameWorld()->GetWorldName();
    }

    void zDExt_Wld_SetWeatherType(const int t_weatherType)
    {
#if ENGINE >= Engine_G2
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Wld_SetWeatherType");
        oCWorld* world = ogame->GetGameWorld();

        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());
        if (!skyCtrl)
        {
            logger->Error("zCSkyControler_Outdoor not found");
            return;
        }

        skyCtrl->SetWeatherType(static_cast<zTWeather>(t_weatherType));
#endif
    }

    int zDExt_Wld_GetWeatherType()
    {
#if ENGINE >= Engine_G2
        oCWorld* world = ogame->GetGameWorld();
        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(world->GetActiveSkyControler());
        return skyCtrl ? static_cast<int>(skyCtrl->GetWeatherType()) : -1;
#endif
        return -1;
    }

    int zDExt_Wld_SetRainTime(const int t_startHour, const int t_startMin, const int t_endHour, const int t_endMin)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Wld_SetRainTime");

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

    void zDExt_Wld_SetRainOn()
    {
        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());
        if (!skyCtrl)
        {
            return;
        }

        skyCtrl->rainFX.timeStartRain = 0;
        skyCtrl->rainFX.timeStopRain = 1.0f;
    }

    void zDExt_Wld_SetRainOff()
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

    void zDExt_Wld_OverrideWorldFogColors(const int t_index, const zSTRING& t_color) // WIP
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Wld_OverrideWorldFogColors");

        zCSkyControler_Outdoor* skyCtrl = dynamic_cast<zCSkyControler_Outdoor*>(ogame->GetGameWorld()->GetActiveSkyControler());
        if (!skyCtrl)
        {
            logger->Error("zCSkyControler_Outdoor not found");
            return;
        }

        zVEC3 color = GetColorFromString(t_color);
        skyCtrl->fogColorDayVariations.Insert(color);
    }

    void zDExt_Wld_ChangeLevel(const zSTRING& t_worldName, const zSTRING& t_waypoint)
    {
        const zSTRING transformedWorldName =
            [&]()
        {
            zSTRING name{ t_worldName };
            (void)name.Upper();

            if (const size_t pos = std::string_view(t_worldName.ToChar()).find_last_of(".");
                pos == std::string::npos
                || std::string_view(t_worldName.ToChar()).substr(pos) != ".ZEN")
            {
                name += ".ZEN";
            }

            return name;
        }();

        if (transformedWorldName == ogame->GetGameWorld()->GetWorldFilename().Upper())
        {
            return;
        }

        ogame->TriggerChangeLevel(transformedWorldName, t_waypoint);
    }
}
