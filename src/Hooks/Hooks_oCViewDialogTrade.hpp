namespace GOTHIC_NAMESPACE
{
#if ENGINE == Engine_G2A
    void __fastcall oCViewDialogTrade_OnTransferLeft(Union::Registers& reg);
    auto PartialHook__oCViewDialogTrade_OnTransferLeft = Union::CreatePartialHook(reinterpret_cast<void*>(0x0068B888), &oCViewDialogTrade_OnTransferLeft);
    void __fastcall oCViewDialogTrade_OnTransferLeft(Union::Registers& reg)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::oCViewDialogTrade::OnTransferLeft");

        oCViewDialogTrade* self = reinterpret_cast<oCViewDialogTrade*>(reg.edi);
        oCItem* itm = reinterpret_cast<oCItem*>(reg.esi);

        int canSellItem = 1;

        zDE_SaveParserVars();

        parser->SetInstance("ITEM", itm);
        parser->SetInstance("SELF", self->NpcRight); // player
        parser->SetInstance("OTHER", self->NpcLeft); // trader

        const auto apiCall = DaedalusCall<int>(parser, DCFunction("C_PLAYERCANSELLITEM"), {});

        zDE_RestoreParserVars();

        if (apiCall.has_value())
        {
            canSellItem = *apiCall;
        }
        else
        {
            logger->Info(DAEDALUS_CALL_FAILED_MSG, "C_PLAYERCANSELLITEM", CallErrorToString(apiCall.error()));
        }

        if (!canSellItem)
        {
            logger->Info("Player cannot sell item: {0}", itm->GetInstanceName().ToChar());
            reg.eip = 0x0068BA3F; // return 1
        }
    }
#endif
}
