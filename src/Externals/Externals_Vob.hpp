namespace GOTHIC_NAMESPACE
{
    void Vob_Rotate(const zSTRING& t_vobName, const int t_posX, const int t_posY, const int t_posZ)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Vob_Rotate");
        logger->Warning("This function is deprecated. Use Vob_RotateLocal or Vob_RotateWorld instead.");
    }

    void Vob_RotateWorld(const zSTRING& t_vobName, const int t_posX, const int t_posY, const int t_posZ)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Vob_RotateWorld");
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

    void Vob_RotateLocal(const zSTRING& t_vobName, const int t_posX, const int t_posY, const int t_posZ)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Vob_RotateLocal");
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

    void Vob_SetVisual(const zSTRING& t_vobName, const zSTRING& t_visualName)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Vob_SetVisual");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return;
        }

        zSTRING visualName{ t_visualName };
        visualName.Upper();

        zCVisual* visual = zCVisual::LoadVisual(visualName);
        vob->SetVisual(visual);
        visual->Release();
    }

    void Vob_SetToFloor(const zSTRING& t_vobName)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Vob_SetToFloor");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return;
        }

        auto pos = vob->GetPositionWorld();
        SetVobOnFloor(vob, pos);
    }

    void Vob_MoveTo(const zSTRING& t_vobName, const zSTRING& t_pointName)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Vob_MoveTo");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return;
        }

        zSTRING pointName{ t_pointName };
        pointName.Upper();

        auto pos = GetWaypointPosition(pointName, logger);
        SetVobPositionWorld(vob, pos.value());
    }

    void Vob_MoveToPos(const zSTRING& t_vobName, const int t_posX, const int t_posY, const int t_posZ)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Vob_MoveToPos");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return;
        }

        auto pos = zVEC3((float)t_posX, (float)t_posY, (float)t_posZ);
        SetVobPositionWorld(vob, pos);
    }

    void Vob_SetCollisionDetection(const zSTRING& t_vobName, const int dynamicCollDet, const int staticCollDet)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Vob_SetCollisionDetection");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return;
        }

        vob->collDetectionDynamic = dynamicCollDet;
        vob->collDetectionStatic = staticCollDet;
    }

    int Vob_GetDistToPos(const zSTRING& t_vobName, const int t_posX, const int t_posY, const int t_posZ)
    {
        int dist = INT_MAX;

        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Vob_GetDistToPos");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return dist;
        }

        auto pos = zVEC3((float)t_posX, (float)t_posY, (float)t_posZ);
        dist = static_cast<int>(GetVobDistanceToPos2(vob, pos, 1));
        return dist;
    }

    int Vob_GetDistToNpc(const zSTRING& t_vobName, oCNpc* t_npc)
    {
        int dist = INT_MAX;

        if (!t_npc)
        {
            return dist;
        }

        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Vob_GetDistToNpc");
        zCVob* vob = FindVobByName(t_vobName, logger);
        if (!vob)
        {
            return dist;
        }

        dist = static_cast<int>(vob->GetDistanceToVob(*t_npc));
        return dist;
    }

    zSTRING Vob_GetPortalRoom(const zSTRING& t_vobName)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Vob_GetPortalRoom");
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
