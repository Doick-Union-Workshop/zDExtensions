namespace GOTHIC_NAMESPACE
{
    void __fastcall oCViewDialogTrade_OnTransferLeft(Union::Registers& reg);
    auto PartialHook__oCViewDialogTrade_OnTransferLeft = Union::CreatePartialHook(
        reinterpret_cast<void*>(zSwitch(0x0, 0x0, 0x0, 0x0068B888)),
        &oCViewDialogTrade_OnTransferLeft
    );
    void __fastcall oCViewDialogTrade_OnTransferLeft(Union::Registers& reg)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::oCViewDialogTrade::OnTransferLeft");

        auto self = reinterpret_cast<oCViewDialogTrade*>(reg.edi);
        auto itm = reinterpret_cast<oCItem*>(reg.esi);

        int canSellItem = 1;

        globalParserVars.Save();
        parser->SetInstance("ITEM", itm);
        parser->SetInstance("SELF", self->NpcRight); // player
        parser->SetInstance("OTHER", self->NpcLeft); // trader

        const auto apiCall = DaedalusCall<int>(parser, DCFunction("zDExt_Npc_CanPlayerSellItem"), eClearStack::CLEAR);

        globalParserVars.Restore();

        if (apiCall.has_value())
        {
            canSellItem = *apiCall;
        }
        else
        {
            logger->Info(DAEDALUS_CALL_FAILED_MSG, "zDExt_Npc_CanPlayerSellItem", CallErrorToString(apiCall.error()));
        }

        if (!canSellItem)
        {
            logger->Info("Player cannot sell item: {0}", itm->GetInstanceName().ToChar());
            reg.eip = 0x0068BA3F; // return 1
        }
    }
}
