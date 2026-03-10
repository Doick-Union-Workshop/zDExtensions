namespace GOTHIC_NAMESPACE
{
#if ENGINE == Engine_G2A
    // G2A: 0x007538C0 protected: int __thiscall oCNpc::EV_DropVob(class oCMsgManipulate *)
    auto Hook_oCNpc_EV_DropVob = Union::CreateHook(
        reinterpret_cast<void*>(0x007538C0),
        &oCNpc::Hook_EV_DropVob,
        Union::HookType::Hook_Detours
    );
    int __thiscall oCNpc::Hook_EV_DropVob(oCMsgManipulate* t_csg)
    {
        static auto logger = Utils::CreateLogger("zDExt::oCNpc::EV_DropVob");

        int canDropItem = 1;

        oCItem* itm = dynamic_cast<oCItem*>(t_csg->targetVob);

        zDE_SaveParserVars();

        parser->SetInstance("ITEM", itm);
        parser->SetInstance("SELF", this);

        const auto apiCall = DaedalusCall<int>(parser, DCFunction("C_PLAYERCANDROPITEM"), {});

        zDE_RestoreParserVars();

        if (apiCall.has_value()) {
            canDropItem = *apiCall;
        } else {
            logger->Info(DAEDALUS_CALL_FAILED_MSG, "C_PLAYERCANDROPITEM", CallErrorToString(apiCall.error()));
        }

        if (!canDropItem)
        {
            logger->Info("Cannot drop item: {0}", itm->GetInstanceName().ToChar());
            return 1;
        }

        return (this->*Hook_oCNpc_EV_DropVob)(t_csg);
    }

    void __fastcall oCNpc_OpenDeadNpc(Union::Registers& reg);
    auto PartialHook__oCNpc_OpenDeadNpc = Union::CreatePartialHook(reinterpret_cast<void*>(0x007629A1), &oCNpc_OpenDeadNpc);
    void __fastcall oCNpc_OpenDeadNpc(Union::Registers& reg)
    {
        static auto logger = Utils::CreateLogger("zDExt::oCNpc::OpenDeadNpc");

        auto self = reinterpret_cast<oCNpc*>(reg.edi);
        auto target = stealnpc;

        int canLootNpc = 1;

        zDE_SaveParserVars();

        parser->SetInstance("SELF", self);
        parser->SetInstance("OTHER", target);

        const auto apiCall = DaedalusCall<int>(parser, DCFunction("C_PLAYERCANLOOTNPC"), {});

        zDE_RestoreParserVars();

        if (apiCall.has_value()) {
            canLootNpc = *apiCall;
        }
        else {
            logger->Info(DAEDALUS_CALL_FAILED_MSG, "C_PLAYERCANLOOTNPC", CallErrorToString(apiCall.error()));
        }

        if (!canLootNpc)
        {
            logger->Info("Player cannot loot NPC: {0}", target->GetInstanceName().ToChar());
            reg.eip = 0x00762B23; // return;
        }
    }

    void __fastcall oCNpc_EV_AttackFinish(Union::Registers& reg);
    auto PartialHook__oCNpc_EV_AttackFinish = Union::CreatePartialHook(reinterpret_cast<void*>(0x00751C7F), &oCNpc_EV_AttackFinish);
    void __fastcall oCNpc_EV_AttackFinish(Union::Registers& reg)
    {
        static auto logger = Utils::CreateLogger("zDExt::oCNpc::EV_AttackFinish");

        auto self = reinterpret_cast<oCNpc*>(reg.esi);
        auto target = reinterpret_cast<oCNpc*>(reg.ebx);

        int canFinishNpc = 1;

        zDE_SaveParserVars();

        parser->SetInstance("SELF", self);
        parser->SetInstance("OTHER", target);

        const auto apiCall = DaedalusCall<int>(parser, DCFunction("C_CANFINISHNPC"), {});

        zDE_RestoreParserVars();

        if (apiCall.has_value()) {
            canFinishNpc = *apiCall;
        }
        else {
            logger->Info(DAEDALUS_CALL_FAILED_MSG, "C_CANFINISHNPC", CallErrorToString(apiCall.error()));
        }

        if (!canFinishNpc)
        {
            logger->Info("Cannot finish NPC: {0}", target->GetInstanceName().ToChar());
            reg.eax = 1;
            reg.eip = 0x007522B3;
        }
    }
#endif
}
