namespace GOTHIC_NAMESPACE
{
    void Mob_SetFocusName(const zSTRING& t_mobName, const zSTRING& t_focusName)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Mob_SetFocusName");
        zCVob* vob = FindVobByName(t_mobName, logger);
        if (!vob) {
            return;
        }

        oCMOB* mob = vob->CastTo<oCMOB>();
        if (!mob)
        {
            logger->Error("Vob found, but it's not an oCMob or its derived class: {0}", t_mobName.ToChar());
            return;
        }

        zSTRING focusName{ t_focusName };
        focusName.Upper();

        mob->SetName(focusName);
    }

    zSTRING Mob_GetFocusName(const zSTRING& t_mobName)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Mob_GetFocusName");
        zCVob* vob = FindVobByName(t_mobName, logger);
        if (!vob)
        {
            return {};
        }

        oCMOB* mob = vob->CastTo<oCMOB>();
        if (!mob)
        {
            logger->Warning("Vob found, but it's not an oCMob or its derived class: {0}", t_mobName.ToChar());
            return {};
        }

        return mob->GetName();
    }

    zSTRING Mob_GetScemeName(const zSTRING& t_mobName)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Mob_GetScemeName");

        zCVob* vob = FindVobByName(t_mobName, logger);
        if (!vob)
        {
            return {};
        }

        oCMOB* mob = vob->CastTo<oCMOB>();
        if (!mob)
        {
            logger->Warning("Vob found, but it's not an oCMOB or its derived class: {0}", t_mobName.ToChar());
            return {};
        }

        return mob->GetScemeName();
    }

    void Mob_SetUseWithItem(const zSTRING& t_mobName, const zSTRING& t_itemInstance)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Mob_SetUseWithItem");
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
        itemInstance.Upper();

        mob->SetUseWithItem(itemInstance);
    }
}
