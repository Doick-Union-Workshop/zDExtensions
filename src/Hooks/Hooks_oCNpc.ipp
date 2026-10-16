#include "Hooks/Hooks_Helpers.hpp"

namespace GOTHIC_NAMESPACE
{
    auto Hook_oCNpc_EV_DropVob = Union::CreateHook(
        SIGNATURE_OF(&oCNpc::EV_DropVob),
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

    auto Hook_oCNpc_OnDamage_Condition = Union::CreateHook(
        SIGNATURE_OF(&oCNpc::OnDamage_Condition),
        &oCNpc::Hook_OnDamage_Condition,
        Union::HookType::Hook_Detours
    );
    void __thiscall oCNpc::Hook_OnDamage_Condition(oCNpc::oSDamageDescriptor& t_descDamage)
    {
        (this->*Hook_oCNpc_OnDamage_Condition)(t_descDamage);

        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::oCNpc::OnDamage_Condition");

        int canKillNpc = 1;

        const auto result = DaedalusCall<int>(
            parser,
            DCFunction("zDExt_Npc_CanKill"),
            eClearStack::CLEAR,
            t_descDamage.pNpcAttacker, // attacker
            this // target
        );

        if (result.has_value())
        {
            canKillNpc = *result;
        }
        else
        {
            logger->Error(
                DAEDALUS_CALL_FAILED_MSG,
                "zDExt_Npc_CanKill",
                DaedalusCallErrorToString(result.error())
            );
        }

        if (t_descDamage.bIsDead && !canKillNpc)
        {
            logger->Info(
                "Cannot kill NPC: {0}",
                GetInstanceName().ToChar()
            );

            t_descDamage.bIsDead = 0;
            t_descDamage.bIsUnconscious = 1;
        }
    }
}
