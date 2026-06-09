namespace GOTHIC_NAMESPACE
{
    void zDExt_Mob_SetFocusName(const zSTRING& t_mobName, const zSTRING& t_focusName)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Mob_SetFocusName");
        zCVob* vob = FindVobByName(t_mobName, logger);
        if (!vob)
        {
            return;
        }

        oCMOB* mob = vob->CastTo<oCMOB>();
        if (!mob)
        {
            logger->Error("Vob found, but it's not an oCMob or its derived class: {0}", t_mobName.ToChar());
            return;
        }

        zSTRING focusName{ t_focusName };
        (void)focusName.Upper();

        mob->SetName(focusName);
    }

    zSTRING zDExt_Mob_GetFocusName(const zSTRING& t_mobName)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Mob_GetFocusName");
        zCVob* vob = FindVobByName(t_mobName, logger);
        if (!vob)
        {
            return zSTRING{};
        }

        oCMOB* mob = vob->CastTo<oCMOB>();
        if (!mob)
        {
            logger->Warning("Vob found, but it's not an oCMob or its derived class: {0}", t_mobName.ToChar());
            return zSTRING{};
        }

        return mob->GetName();
    }

    zSTRING zDExt_Mob_GetScemeName(const zSTRING& t_mobName)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Mob_GetScemeName");

        zCVob* vob = FindVobByName(t_mobName, logger);
        if (!vob)
        {
            return zSTRING{};
        }

        oCMOB* mob = vob->CastTo<oCMOB>();
        if (!mob)
        {
            logger->Warning("Vob found, but it's not an oCMOB or its derived class: {0}", t_mobName.ToChar());
            return zSTRING{};
        }

        return mob->GetScemeName();
    }

    void zDExt_Mob_SetUseWithItem(const zSTRING& t_mobName, const zSTRING& t_itemInstance)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Mob_SetUseWithItem");
        zCVob* vob = FindVobByName(t_mobName, logger);
        if (!vob)
        {
            return;
        }

        oCMobInter* mob = vob->CastTo<oCMobInter>();
        if (!mob)
        {
            logger->Warning("Vob found, but it's not an oCMobInter or its derived class: {0}", t_mobName.ToChar());
            return;
        }

        zSTRING itemInstance{ t_itemInstance };
        (void)itemInstance.Upper();

        mob->SetUseWithItem(itemInstance);
    }
}
