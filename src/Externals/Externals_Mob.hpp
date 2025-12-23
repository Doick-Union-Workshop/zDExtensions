namespace GOTHIC_NAMESPACE
{
    static void Mob_SetFocusName(const zSTRING& t_mobName, const zSTRING& t_focusName)
    {
        if (t_mobName.IsEmpty()) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Mob_SetFocusName");

        zCVob* vob = FindVobByName(t_mobName, log);

        if (!vob) return;

        oCMOB* mob = vob->CastTo<oCMOB>();

        if (!mob)
        {
            log->Error("Vob found, but it's not an oCMob or its derived class: {0}", t_mobName.ToChar());
            return;
        }

        zSTRING focusName = Str_Upper(t_focusName);
        mob->SetName(focusName);
    }

    static zSTRING Mob_GetFocusName(const zSTRING& t_mobName)
    {
        if (t_mobName.IsEmpty()) return zSTRING{};

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Mob_GetFocusName");

        zCVob* vob = FindVobByName(t_mobName, log);

        if (!vob) return zSTRING{};

        oCMOB* mob = vob->CastTo<oCMOB>();

        if (!mob)
        {
            log->Warning("Vob found, but it's not an oCMob or its derived class: {0}", t_mobName.ToChar());
            return zSTRING{};
        }

        return mob->GetName();
    }

    static zSTRING Mob_GetScemeName(const zSTRING& t_mobName)
    {
        if (t_mobName.IsEmpty()) return zSTRING{};

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Mob_GetScemeName");

        zCVob* vob = FindVobByName(t_mobName, log);

        if (!vob) return zSTRING{};

        oCMOB* mob = vob->CastTo<oCMOB>();

        if (!mob)
        {
            log->Warning("Vob found, but it's not an oCMOB or its derived class: {0}", t_mobName.ToChar());
            return zSTRING{};
        }

        return mob->GetScemeName();
    }
}
