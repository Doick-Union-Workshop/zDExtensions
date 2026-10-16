#include "Hooks/Hooks_Helpers.hpp"

namespace GOTHIC_NAMESPACE
{
#if ENGINE == Engine_G2A
    void __fastcall oCViewDialogTrade_OnTransferLeft(Union::Registers& reg);
    auto PartialHook__oCViewDialogTrade_OnTransferLeft = Union::CreatePartialHook(
        reinterpret_cast<void*>(0x0068B888),
        &oCViewDialogTrade_OnTransferLeft
    );
    void __fastcall oCViewDialogTrade_OnTransferLeft(Union::Registers& reg)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::oCViewDialogTrade::OnTransferLeft");

        auto self = reinterpret_cast<oCViewDialogTrade*>(reg.edi);
        auto itm = reinterpret_cast<oCItem*>(reg.esi);
        auto player = self->NpcRight;
        auto trader = self->NpcLeft;

        int canSellItem = 1;

        const auto result = DaedalusCall<int>(
            parser,
            DCFunction("zDExt_Npc_CanPlayerSellItem"),
            eClearStack::CLEAR,
            player,
            trader,
            itm
        );

        if (result.has_value())
        {
            canSellItem = *result;
        }
        else
        {
            logger->Info(
                DAEDALUS_CALL_FAILED_MSG,
                "zDExt_Npc_CanPlayerSellItem",
                DaedalusCallErrorToString(result.error())
            );
        }

        if (!canSellItem)
        {
            logger->Info(
                "Player cannot sell {0} item: {1}",
                trader->GetInstanceName().ToChar(),
                itm->GetInstanceName().ToChar()
            );
            reg.eip = 0x0068BA3F; // return 1
        }
    }
#endif
}
