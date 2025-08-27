namespace GOTHIC_NAMESPACE
{
	zCVob* FindVobByName(const zSTRING& t_name, Utils::Logger* t_logger = nullptr)
	{
		zSTRING name = zSTRING(t_name).Upper();
		zCVob* vob = ogame->GetGameWorld()->SearchVobByName(name);

		if (!vob && t_logger)
			t_logger->Error("No Vob found with specified name: {0}", name.ToChar());

		return vob;
	}

    int GetVobFloorPosition(zCVob* t_vob, zVEC3& t_pos)
    {
        zCWorld* wld = t_vob->GetHomeWorld();

        if (!wld) return 0;

        zREAL diff = t_vob->GetPositionWorld()[VY] - t_vob->bbox3D.mins[VY];

        if (wld->TraceRayNearestHit(t_pos, zVEC3(0, -1000, 0), t_vob, zTRACERAY_STAT_POLY | zTRACERAY_VOB_IGNORE_NO_CD_DYN))
        {
            if (wld->traceRayReport.foundPoly || wld->traceRayReport.foundVob)
            {
                zVEC3 newPos = wld->traceRayReport.foundIntersection;
                newPos[VY] += diff + 4;
                t_pos = newPos;
                return 1;
            }
        }

        return 0;
    }

    void SetVobOnFloor(zCVob* t_vob, zVEC3& t_pos)
    {
        static Utils::Logger* log = Utils::CreateLogger("zDExt::SetVobOnFloor");

        if (!GetVobFloorPosition(t_vob, t_pos))
        {
            zSTRING vobName = t_vob->GetObjectName();
            vobName.Upper();
            log->Error("Cannot set to floor Vob with specified name: {0}", vobName.ToChar());
            return;
        }

        t_vob->SetPositionWorld(t_pos);
    }

    void SetVobPositionWorld(zCVob* t_vob, const zVEC3& t_pos)
    {
        if (!t_vob || t_pos == zVEC3{}) return;

        const bool collDetectionStatic = t_vob->collDetectionStatic;
        const bool collDetectionDynamic = t_vob->collDetectionDynamic;
        t_vob->collDetectionStatic = 0;
        t_vob->collDetectionDynamic = 0;
        t_vob->SetPositionWorld(t_pos);
        t_vob->collDetectionStatic = collDetectionStatic;
        t_vob->collDetectionDynamic = collDetectionDynamic;
    }

    inline zREAL GetzVEC3Length2(const zVEC3& t_vec)
    {
        return t_vec.n[VX] * t_vec.n[VX] + t_vec.n[VY] * t_vec.n[VY] + t_vec.n[VZ] * t_vec.n[VZ];
    }

#define	zInRange(a,low,high)	(((a)>=(low)) && ((a)<=(high)))

    zREAL GetVobDistanceToPos2(zCVob* t_vob, zVEC3& t_pos, zBOOL t_dim2)
    {
        zVEC3 p1 = t_vob->GetPositionWorld();
        zVEC3 p2 = t_pos;
        zTBBox3D bbox = t_vob->bbox3D;

        if (t_dim2 || zInRange(t_pos[VY], bbox.mins[VY], bbox.maxs[VY]))
            p2[VY] = p1[VY];
        return GetzVEC3Length2(p1 - p2);
    }

    zCMenuItem* FindMenuItemByName(const zSTRING& t_name, Utils::Logger* t_logger = nullptr)
    {
        zSTRING name = zSTRING(t_name).Upper();
        zCMenuItem* menuItem = zCMenuItem::GetByName(name);

        if (!menuItem && t_logger)
            t_logger->Error("No Menu Item found with specified name: {0}", name.ToChar());

        return menuItem;
    }

    float GetTimeAsFraction(const int t_hour, const int t_minutes)
    {
        int totalMinutesInDay = 24 * 60;
        int totalMinutes = t_hour * 60 + t_minutes;
        return static_cast<float>(totalMinutes) / static_cast<float>(totalMinutesInDay);
    }

    zVEC3 GetColorFromString(const zSTRING& t_str)
    {
        return zVEC3(
            (t_str.PickWord_Old(1, "\r\t ").ToFloat()),
            (t_str.PickWord_Old(2, "\r\t ").ToFloat()),
            (t_str.PickWord_Old(3, "\r\t ").ToFloat()));
    }
}