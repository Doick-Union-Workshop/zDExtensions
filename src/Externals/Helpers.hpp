namespace GOTHIC_NAMESPACE
{
	zCVob* FindVobByName(const zSTRING& t_name, Utils::Logger* t_logger = nullptr)
	{
        zSTRING name{ t_name };
        name.Upper();

		zCVob* vob = ogame->GetGameWorld()->SearchVobByName(name);
        if (!vob && t_logger)
        {
            t_logger->Error("No Vob found with specified name: {0}", name.ToChar());
        }

		return vob;
	}

    int GetVobFloorPosition(zCVob* t_vob, zVEC3& t_pos)
    {
        zCWorld* world = t_vob->GetHomeWorld();
        if (!world)
        {
            return 0;
        }

        zREAL diff = t_vob->GetPositionWorld()[VY] - t_vob->bbox3D.mins[VY];

        if (world->TraceRayNearestHit(t_pos, zVEC3(0, -1000, 0), t_vob, zTRACERAY_STAT_POLY | zTRACERAY_VOB_IGNORE_NO_CD_DYN))
        {
            if (world->traceRayReport.foundPoly || world->traceRayReport.foundVob)
            {
                auto newPos = world->traceRayReport.foundIntersection;
                newPos[VY] += (diff + 4);
                t_pos = newPos;
                return 1;
            }
        }

        return 0;
    }

    void SetVobOnFloor(zCVob* t_vob, zVEC3& t_pos)
    {
        if (!GetVobFloorPosition(t_vob, t_pos))
        {
            zSTRING vobName = t_vob->GetObjectName();
            vobName.Upper();
            static Utils::Logger* logger = Utils::CreateLogger("zDExt::SetVobOnFloor");
            logger->Error("Cannot set to floor Vob with specified name: {0}", vobName.ToChar());
            return;
        }

        t_vob->SetPositionWorld(t_pos);
    }

    void SetVobPositionWorld(zCVob* t_vob, const zVEC3& t_pos)
    {
        if (!t_vob)
        {
            return;
        }

        const bool collDetectionStatic = t_vob->collDetectionStatic;
        const bool collDetectionDynamic = t_vob->collDetectionDynamic;
        t_vob->collDetectionStatic = 0;
        t_vob->collDetectionDynamic = 0;
        t_vob->SetPositionWorld(t_pos);
        t_vob->collDetectionStatic = collDetectionStatic;
        t_vob->collDetectionDynamic = collDetectionDynamic;
    }

    zREAL GetzVEC3Length2(const zVEC3& t_vec)
    {
        return t_vec.n[VX] * t_vec.n[VX] + t_vec.n[VY] * t_vec.n[VY] + t_vec.n[VZ] * t_vec.n[VZ];
    }

    bool InRange(zREAL v, zREAL min, zREAL max)
    {
        return v >= min && v <= max;
    }

    zREAL GetVobDistanceToPos2(zCVob* t_vob, zVEC3& t_pos, zBOOL t_dim2)
    {
        zVEC3 p1 = t_vob->GetPositionWorld();
        zVEC3 p2 = t_pos;
        zTBBox3D bbox = t_vob->bbox3D;

        if (t_dim2 || InRange(t_pos[VY], bbox.mins[VY], bbox.maxs[VY]))
        {
            p2[VY] = p1[VY];
        }

        return GetzVEC3Length2(p1 - p2);
    }

    zCMenuItem* FindMenuItemByName(const zSTRING& t_name, Utils::Logger* t_logger = nullptr)
    {
        zSTRING name{ t_name };
        name.Upper();

        zCMenuItem* menuItem = zCMenuItem::GetByName(name);
        if (!menuItem && t_logger)
        {
            t_logger->Error("No Menu Item found with specified name: {0}", name.ToChar());
        }

        return menuItem;
    }

    float GetTimeAsFraction(const int t_hour, const int t_minutes)
    {
        constexpr int totalMinutesInDay = 24 * 60;
        return static_cast<float>(t_hour * 60 + t_minutes) / static_cast<float>(totalMinutesInDay);
    }

    zVEC3 GetColorFromString(const zSTRING& t_str)
    {
        return zVEC3(
            (t_str.PickWord_Old(1, "\r\t ").ToFloat()),
            (t_str.PickWord_Old(2, "\r\t ").ToFloat()),
            (t_str.PickWord_Old(3, "\r\t ").ToFloat()));
    }

    void MenuItem_Release(zCMenuItem* t_menuItem)
    {
        if (!t_menuItem)
        {
            return;
        }

#if ENGINE >= Engine_G2
        t_menuItem->Release();
#else
        t_menuItem->m_iRefCtr--;

        if (t_menuItem->m_iRefCtr <= 0 && !t_menuItem->registeredCPP) {
            delete t_menuItem;
        }
#endif
    }

    zCOption* GetOptionsLevel(const zSTRING& t_level)
    {
        zSTRING level{ t_level };
        level.Upper();

        if (level == "MOD")
        {
            return zgameoptions;
        }
        return zoptions;
    }

    std::optional<zVEC3> GetWaypointPosition(const zSTRING& t_pointName, Utils::Logger* t_logger = nullptr)
    {
        zSTRING pointName{ t_pointName };
        pointName.Upper();

        if (zCWaypoint* waypoint = ogame->GetGameWorld()->wayNet->GetWaypoint(pointName))
        {
            return waypoint->GetPositionWorld();
        }

        if (t_logger)
        {
            t_logger->Warning("No Waypoint found with specified name: {0}. Looking for Vob...", pointName.ToChar());
        }

        if (zCVob* vob = FindVobByName(pointName, t_logger))
        {
            return vob->GetPositionWorld();
        }

        return std::nullopt;
    }
}
