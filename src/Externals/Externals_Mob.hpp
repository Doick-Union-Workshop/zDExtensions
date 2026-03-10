namespace GOTHIC_NAMESPACE
{
    void Mob_SetFocusName(const zSTRING& t_mobName, const zSTRING& t_focusName)
    {
        if (t_mobName.IsEmpty()) {
            return;
        }

        static auto log = Utils::CreateLogger("zDExt::Externals::Mob_SetFocusName");

        zCVob* vob = FindVobByName(t_mobName, log);
        if (!vob) {
            return;
        }

        oCMOB* mob = vob->CastTo<oCMOB>();
        if (!mob)
        {
            log->Error("Vob found, but it's not an oCMob or its derived class: {0}", t_mobName.ToChar());
            return;
        }

        zSTRING focusName = Str_Upper(t_focusName);
        mob->SetName(focusName);
    }

    zSTRING Mob_GetFocusName(const zSTRING& t_mobName)
    {
        if (t_mobName.IsEmpty()) {
            return zSTRING{};
        }

        static auto log = Utils::CreateLogger("zDExt::Externals::Mob_GetFocusName");

        zCVob* vob = FindVobByName(t_mobName, log);
        if (!vob) {
            return zSTRING{};
        }

        oCMOB* mob = vob->CastTo<oCMOB>();
        if (!mob)
        {
            log->Warning("Vob found, but it's not an oCMob or its derived class: {0}", t_mobName.ToChar());
            return zSTRING{};
        }

        return mob->GetName();
    }

    zSTRING Mob_GetScemeName(const zSTRING& t_mobName)
    {
        if (t_mobName.IsEmpty()) {
            return zSTRING{};
        }

        static auto log = Utils::CreateLogger("zDExt::Externals::Mob_GetScemeName");

        zCVob* vob = FindVobByName(t_mobName, log);
        if (!vob) {
            return zSTRING{};
        }

        oCMOB* mob = vob->CastTo<oCMOB>();
        if (!mob)
        {
            log->Warning("Vob found, but it's not an oCMOB or its derived class: {0}", t_mobName.ToChar());
            return zSTRING{};
        }

        return mob->GetScemeName();
    }

    void Mob_SetUseWithItem(const zSTRING& t_mobName, const zSTRING& t_itemInstance)
    {
        if (t_mobName.IsEmpty() || t_itemInstance.IsEmpty()) {
            return;
        }

        static auto log = Utils::CreateLogger("zDExt::Externals::Mob_SetUseWithItem");

        zCVob* vob = FindVobByName(t_mobName, log);
        if (!vob) {
            return;
        }

        oCMobInter* mob = vob->CastTo<oCMobInter>();
        if (!mob)
        {
            log->Warning("Vob found, but it's not an oCMobInter or its derived class: {0}", t_mobName.ToChar());
            return;
        }

        zSTRING itemInstanceStr = zSTRING(t_itemInstance).Upper();
        mob->SetUseWithItem(itemInstanceStr);
    }
}
