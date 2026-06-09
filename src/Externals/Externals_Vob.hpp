namespace GOTHIC_NAMESPACE
{
    void zDExt_Vob_RotateWorld(const zSTRING& t_vobName, const int t_posX, const int t_posY, const int t_posZ)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Vob_RotateWorld");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return;
        }

        const bool collDetectionStatic = vob->collDetectionStatic;
        const bool collDetectionDynamic = vob->collDetectionDynamic;
        vob->collDetectionStatic = 0;
        vob->collDetectionDynamic = 0;

        vob->RotateWorldX((float)t_posX);
        vob->RotateWorldY((float)t_posY);
        vob->RotateWorldZ((float)t_posZ);

        vob->collDetectionStatic = collDetectionStatic;
        vob->collDetectionDynamic = collDetectionDynamic;
    }

    void zDExt_Vob_RotateLocal(const zSTRING& t_vobName, const int t_posX, const int t_posY, const int t_posZ)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Vob_RotateLocal");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return;
        }

        const bool collDetectionStatic = vob->collDetectionStatic;
        const bool collDetectionDynamic = vob->collDetectionDynamic;
        vob->collDetectionStatic = 0;
        vob->collDetectionDynamic = 0;

        vob->RotateLocalX((float)t_posX);
        vob->RotateLocalY((float)t_posY);
        vob->RotateLocalZ((float)t_posZ);

        vob->collDetectionStatic = collDetectionStatic;
        vob->collDetectionDynamic = collDetectionDynamic;
    }

    void zDExt_Vob_SetVisual(const zSTRING& t_vobName, const zSTRING& t_visualName)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Vob_SetVisual");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return;
        }

        zSTRING visualName{ t_visualName };
        (void)visualName.Upper();

        zCVisual* visual = zCVisual::LoadVisual(visualName);
        vob->SetVisual(visual);
        visual->Release();
    }

    void zDExt_Vob_SetToFloor(const zSTRING& t_vobName)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Vob_SetToFloor");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return;
        }

        auto pos = vob->GetPositionWorld();
        SetVobOnFloor(vob, pos);
    }

    void zDExt_Vob_MoveTo(const zSTRING& t_vobName, const zSTRING& t_pointName)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Vob_MoveTo");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return;
        }

        zSTRING pointName{ t_pointName };
        (void)pointName.Upper();

        auto pos = GetWaypointPosition(pointName, logger);
        SetVobPositionWorld(vob, pos.value());
    }

    void zDExt_Vob_MoveToPos(const zSTRING& t_vobName, const int t_posX, const int t_posY, const int t_posZ)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Vob_MoveToPos");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return;
        }

        auto pos = zVEC3((float)t_posX, (float)t_posY, (float)t_posZ);
        SetVobPositionWorld(vob, pos);
    }

    void zDExt_Vob_SetCollisionDetection(const zSTRING& t_vobName, const int dynamicCollDet, const int staticCollDet)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Vob_SetCollisionDetection");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return;
        }

        vob->collDetectionDynamic = dynamicCollDet;
        vob->collDetectionStatic = staticCollDet;
    }

    int zDExt_Vob_GetDistToPos(const zSTRING& t_vobName, const int t_posX, const int t_posY, const int t_posZ)
    {
        int dist = INT_MAX;

        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Vob_GetDistToPos");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return dist;
        }

        auto pos = zVEC3((float)t_posX, (float)t_posY, (float)t_posZ);
        dist = static_cast<int>(GetVobDistanceToPos2(vob, pos, 1));
        return dist;
    }

    int zDExt_Vob_GetDistToNpc(const zSTRING& t_vobName, oCNpc* t_npc)
    {
        int dist = INT_MAX;

        if (!t_npc)
        {
            return dist;
        }

        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Vob_GetDistToNpc");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return dist;
        }

        dist = static_cast<int>(vob->GetDistanceToVob(*t_npc));
        return dist;
    }

    zSTRING zDExt_Vob_GetPortalRoom(const zSTRING& t_vobName)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Vob_GetPortalRoom");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return {};
        }

        if (auto portal = vob->GetSectorNameVobIsIn())
        {
            return *portal;
        }

        return {};
    }
}
