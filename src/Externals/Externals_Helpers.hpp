#pragma once

#include <optional>
#include "Utils/zDUtils/Logger/Logger.h"

namespace GOTHIC_NAMESPACE
{
    zREAL GetzVEC3Length2(const zVEC3& t_vec);
    bool InRange(zREAL v, zREAL min, zREAL max);
    float GetTimeAsFraction(const int t_hour, const int t_minutes);
    zCMenuItem* FindMenuItemByName(const zSTRING& t_name, zDUtils::Logger* t_logger = nullptr);
    void MenuItem_Release(zCMenuItem* t_menuItem);
    zCOption* GetOptionsLevel(const zSTRING& t_level);
    zCVob* FindVobByName(const zSTRING& t_name, zDUtils::Logger* t_logger = nullptr);
    int GetVobFloorPosition(zCVob* t_vob, zVEC3& t_pos);
    void SetVobOnFloor(zCVob* t_vob, zVEC3& t_pos);
    void SetVobPositionWorld(zCVob* t_vob, const zVEC3& t_pos);
    zREAL GetVobDistanceToPos2(zCVob* t_vob, zVEC3& t_pos, zBOOL t_dim2);
    std::optional<zVEC3> GetWaypointPosition(const zSTRING& t_pointName, zDUtils::Logger* t_logger = nullptr);
}
