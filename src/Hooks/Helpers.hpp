namespace GOTHIC_NAMESPACE
{
    void RegisterHookAPIs()
    {
        auto log = Utils::CreateLogger("zDExt::RegisterHookAPIs");
        int index;

        for (auto& name : hookAPIs)
        {
            index = parser->GetIndex(name);

            if (index <= 0)
                index = parserMenu->GetIndex(name);

            if (index > 0)
            {
                registeredHookAPIs.Insert(name);
                log->Info("Registered hook API: {0}", name.ToChar());
            }
            else {
                log->Warning("Failed to register {0}: {1}", name.ToChar(), DaedalusCallErrorToString(eCallFuncError::WRONG_SYMBOL));
            }
        }
    }

    inline bool IsHookAPIRegistered(const zSTRING& t_name)
    {
        return registeredHookAPIs.IsIn(t_name);
    }
}