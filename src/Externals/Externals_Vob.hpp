namespace GOTHIC_NAMESPACE
{
    static void Vob_Rotate(const zSTRING& t_vobName, C_POSITION* t_vobPosition)
    {
        if (t_vobName.IsEmpty() || !t_vobPosition) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_Rotate");

        if (!wld) return 0;

        zREAL diff = t_vob->GetPositionWorld()[VY] - t_vob->bbox3D.mins[VY];

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return;

        const bool collDetectionStatic = vob->collDetectionStatic;
        const bool collDetectionDynamic = vob->collDetectionDynamic;
        vob->collDetectionStatic = 0;
        vob->collDetectionDynamic = 0;

        vob->RotateWorldX((float)t_vobPosition->X);
        vob->RotateWorldY((float)t_vobPosition->Y);
        vob->RotateWorldZ((float)t_vobPosition->Z);

        vob->collDetectionStatic = collDetectionStatic;
        vob->collDetectionDynamic = collDetectionDynamic;
    }

    static void Vob_SetVisual(const zSTRING& t_vobName, const zSTRING& t_visualName)
    {
        if (t_vobName.IsEmpty()) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_SetVisual");

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return;

        zSTRING visualName = zSTRING(t_visualName).Upper();
        vob->SetVisual(zCVisual::LoadVisual(visualName));
    }

    static void Vob_SetToFloor(const zSTRING& t_vobName)
    {
        if (t_vobName.IsEmpty()) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_SetToFloor");

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return;

        zVEC3 pos = vob->GetPositionWorld();
        SetVobOnFloor(vob, pos);
    }

    static void Vob_MoveTo(const zSTRING& t_vobName, const zSTRING& t_pointName)
    {
        if (t_vobName.IsEmpty() || t_pointName.IsEmpty())
            return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_MoveTo");

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return;

        zSTRING pointName = zSTRING(t_pointName).Upper();
        oCWorld* world = ogame->GetGameWorld();
        zCWaypoint* wp = world->wayNet->GetWaypoint(pointName);
        zVEC3 pos;

        if (wp) {
            pos = wp->GetPositionWorld();
        }
        else
        {
            zCVob* pointVob = world->SearchVobByName(pointName);
            if (!pointVob) return;
            pos = pointVob->GetPositionWorld();
        }

        SetVobPositionWorld(vob, pos);
    }

    static void Vob_MoveToPos(const zSTRING& t_vobName, C_POSITION* t_vobPosition)
    {
        if (t_vobName.IsEmpty() || !t_vobPosition) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_MoveToPos");

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return;

        zVEC3 pos = zVEC3(t_vobPosition->X, t_vobPosition->Y, t_vobPosition->Z);
        SetVobPositionWorld(vob, pos);
    }

    static void Vob_SetCollisionDetection(const zSTRING& t_vobName, const int dynamicCollDet, const int staticCollDet)
    {
        if (t_vobName.IsEmpty()) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_SetCollisionDetection");

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return;

        vob->collDetectionDynamic = dynamicCollDet;
        vob->collDetectionStatic = staticCollDet;
    }

        if (!vob)
        {
            log->Warning("No Vob found with specified name: {0}", vobName.ToChar());
            return;
        }

        vob->collDetectionDynamic = dynamicCollDet;
        vob->collDetectionStatic = staticCollDet;
    }
}