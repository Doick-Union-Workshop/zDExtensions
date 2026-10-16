#pragma once

#include <ZenGin/zGothicAPI.h>
#include "Externals/Externals_Helpers.hpp"

namespace GOTHIC_NAMESPACE
{
	int zDExt_Wld_RemoveVob(const zSTRING& t_vobName);
	zSTRING zDExt_Wld_GetPlayerPortalRoom();
	zSTRING zDExt_Wld_GetWorldName();
	void zDExt_Wld_SetWeatherType(const int t_weatherType);
	int zDExt_Wld_GetWeatherType();
	int zDExt_Wld_SetRainTime(const int t_startHour, const int t_startMin, const int t_endHour, const int t_endMin);
	void zDExt_Wld_SetRainOn();
	void zDExt_Wld_SetRainOff();
	void zDExt_Wld_ChangeLevel(const zSTRING& t_worldName, const zSTRING& t_waypoint);

    template<typename VobT>
    void zDExt_Wld_InsertVob(const zSTRING& t_vobName, const zSTRING& t_pointName)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Wld_InsertVob");

        auto pos = GetWaypointPosition(t_pointName, logger);
        if (!pos)
        {
            return;
        }

        zSTRING vobName{ t_vobName };
        (void)vobName.Upper();

        auto* vob = new VobT{};
        vob->SetVobName(vobName);
        ogame->GetGameWorld()->AddVob(vob);
        SetVobPositionWorld(vob, pos.value());
        vob->Release();
    }

    template<typename VobT>
    void zDExt_Wld_InsertVobPos(const zSTRING& t_vobName, const float t_posX, const float t_posY, const float t_posZ)
    {
        zSTRING vobName{ t_vobName };
        (void)vobName.Upper();

        auto* vob = new VobT{};
        auto pos = zVEC3(t_posX, t_posY, t_posZ);

        vob->SetVobName(vobName);
        ogame->GetGameWorld()->AddVob(vob);
        SetVobPositionWorld(vob, pos);
        vob->Release();
    }
}
