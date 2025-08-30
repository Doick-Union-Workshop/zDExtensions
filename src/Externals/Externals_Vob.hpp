namespace GOTHIC_NAMESPACE
{
    static void Vob_Rotate(const zSTRING& t_vobName, C_POSITION* t_vobPosition)
    {
        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_Rotate");
        log->Warning("Vob_Rotate is deprecated. Use Vob_RotateLocal or Vob_RotateWorld instead.");
    }

    static void Vob_RotateWorld(const zSTRING& t_vobName, C_POSITION* t_vobPosition)
    {
        if (t_vobName.IsEmpty() || !t_vobPosition) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_RotateWorld");

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

    static void Vob_RotateLocal(const zSTRING& t_vobName, C_POSITION* t_vobPosition)
    {
        if (t_vobName.IsEmpty() || !t_vobPosition) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_RotateLocal");

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return;

        const bool collDetectionStatic = vob->collDetectionStatic;
        const bool collDetectionDynamic = vob->collDetectionDynamic;
        vob->collDetectionStatic = 0;
        vob->collDetectionDynamic = 0;

        vob->RotateLocalX((float)t_vobPosition->X);
        vob->RotateLocalY((float)t_vobPosition->Y);
        vob->RotateLocalZ((float)t_vobPosition->Z);

        vob->collDetectionStatic = collDetectionStatic;
        vob->collDetectionDynamic = collDetectionDynamic;
    }

    static void Vob_SetVisual(const zSTRING& t_vobName, const zSTRING& t_visualName)
    {
        if (t_vobName.IsEmpty()) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_SetVisual");

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return;

        zSTRING visualName = Str_Upper(t_visualName);
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
        if (t_vobName.IsEmpty() || t_pointName.IsEmpty()) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_MoveTo");

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return;

        zSTRING pointName = Str_Upper(t_pointName);
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

    static int Vob_GetDistToPos(const zSTRING& t_vobName, C_POSITION* t_position)
    {
        int dist = INT_MAX;

        if (!t_vobName.IsEmpty() || !t_position) return dist;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_GetDistToPos");

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return dist;

        zVEC3 pos = zVEC3(
            (float)t_position->X,
            (float)t_position->Y,
            (float)t_position->Z);
        dist = static_cast<int>(GetVobDistanceToPos2(vob, pos, 1));
        return dist;
    }

    static int Vob_GetDistToNpc(const zSTRING& t_vobName, oCNpc* t_npc)
    {
        int dist = INT_MAX;

        if (!t_npc || t_vobName.IsEmpty()) return dist;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_GetDistToNpc");

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return dist;

        dist = static_cast<int>(vob->GetDistanceToVob(*t_npc));
        return dist;
    }

    static zSTRING Vob_GetPortalRoom(const zSTRING& t_vobName)
    {
        if (!t_vobName.IsEmpty()) return zSTRING{};

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Vob_GetPortalRoom");

        zCVob* vob = FindVobByName(t_vobName, log);

        if (!vob) return zSTRING{};

        if (auto portal = vob->GetSectorNameVobIsIn())
            return *portal;
        return zSTRING{};
    }
}