namespace GOTHIC_NAMESPACE
{
    // G1:  0x006ADE00 protected: int __thiscall oCNpc::EV_DropVob(class oCMsgManipulate *)
    // G1A: 0x006E15B0 protected: int __thiscall oCNpc::EV_DropVob(class oCMsgManipulate *)
    // G2:  0x006F4A90 protected: int __thiscall oCNpc::EV_DropVob(class oCMsgManipulate *)
    // G2A: 0x007538C0 protected: int __thiscall oCNpc::EV_DropVob(class oCMsgManipulate *)
    auto Hook_oCNpc_EV_DropVob = Union::CreateHook(
        reinterpret_cast<void*>(zSwitch(0x006ADE00, 0x006E15B0, 0x006F4A90, 0x007538C0)),
        &oCNpc::Hook_EV_DropVob,
        Union::HookType::Hook_Detours
    );
    int __thiscall oCNpc::Hook_EV_DropVob(oCMsgManipulate* t_csg)
    {
        if (!t_csg)
        {
            return (this->*Hook_oCNpc_EV_DropVob)(t_csg);
        }

        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::oCNpc::EV_DropVob");

        int canDropItem = 1;

        auto itm = dynamic_cast<oCItem*>(t_csg->targetVob);
        if (!itm)
        {
            return (this->*Hook_oCNpc_EV_DropVob)(t_csg);
        }

        const auto result = DaedalusCall<int>(
            parser,
            DCFunction("zDExt_Npc_CanDropItem"),
            eClearStack::CLEAR,
            this,
            itm
        );

        if (result.has_value())
        {
            canDropItem = *result;
        }
        else
        {
            logger->Info(
                DAEDALUS_CALL_FAILED_MSG,
                "zDExt_Npc_CanDropItem",
                DaedalusCallErrorToString(result.error())
            );
        }

        if (!canDropItem)
        {
            logger->Info(
                "Cannot drop item: {0}",
                itm->GetInstanceName().ToChar()
            );
            return 1;
        }

        return (this->*Hook_oCNpc_EV_DropVob)(t_csg);
    }

#if ENGINE == Engine_G2A
    void __fastcall oCNpc_OpenDeadNpc(Union::Registers& reg);
    auto PartialHook__oCNpc_OpenDeadNpc = Union::CreatePartialHook(
        reinterpret_cast<void*>(0x007629A1),
        &oCNpc_OpenDeadNpc
    );
    void __fastcall oCNpc_OpenDeadNpc(Union::Registers& reg)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::oCNpc::OpenDeadNpc");

        auto self = reinterpret_cast<oCNpc*>(reg.edi);
        auto target = stealnpc;

        int canLootNpc = 1;

        const auto result = DaedalusCall<int>(
            parser,
            DCFunction("zDExt_Npc_CanPlayerPlunder"),
            eClearStack::CLEAR,
            self,
            target
        );

        if (result.has_value())
        {
            canLootNpc = *result;
        }
        else
        {
            logger->Info(
                DAEDALUS_CALL_FAILED_MSG,
                "zDExt_Npc_CanPlayerPlunder",
                DaedalusCallErrorToString(result.error())
            );
        }

        if (!canLootNpc)
        {
            logger->Info(
                "Player cannot loot NPC: {0}",
                target->GetInstanceName().ToChar()
            );
            reg.eip = 0x00762B23; // return;
        }
    }

    void __fastcall oCNpc_EV_AttackFinish(Union::Registers& reg);
    auto PartialHook__oCNpc_EV_AttackFinish = Union::CreatePartialHook(
        reinterpret_cast<void*>(0x00751C7F),
        &oCNpc_EV_AttackFinish
    );
    void __fastcall oCNpc_EV_AttackFinish(Union::Registers& reg)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::oCNpc::EV_AttackFinish");

        auto self = reinterpret_cast<oCNpc*>(reg.esi);
        auto target = reinterpret_cast<oCNpc*>(reg.ebx);

        int canFinishNpc = 1;

        const auto result = DaedalusCall<int>(
            parser,
            DCFunction("zDExt_Npc_CanFinishAttack"),
            eClearStack::CLEAR,
            self,
            target
        );

        if (result.has_value())
        {
            canFinishNpc = *result;
        }
        else
        {
            logger->Error(
                DAEDALUS_CALL_FAILED_MSG,
                "zDExt_Npc_CanFinishAttack",
                DaedalusCallErrorToString(result.error())
            );
        }

        if (!canFinishNpc)
        {
            logger->Info(
                "Cannot finish NPC: {0}",
                target->GetInstanceName().ToChar()
            );
            reg.eax = 1;
            reg.eip = 0x007522B3;
        }
    }

#endif

}
