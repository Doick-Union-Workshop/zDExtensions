namespace GOTHIC_NAMESPACE
{
#if ENGINE == Engine_G2A
    // G2A: 0x007538C0 protected: int __thiscall oCNpc::EV_DropVob(class oCMsgManipulate *)
    auto Hook_oCNpc_EV_DropVob = Union::CreateHook(reinterpret_cast<void*>(0x007538C0), &oCNpc::Hook_EV_DropVob);
    int __thiscall oCNpc::Hook_EV_DropVob(oCMsgManipulate* t_csg)
    {
        static Utils::Logger* log = Utils::CreateLogger("zDExt::oCNpc::EV_DropVob");
        zCModel* model = GetModel();
        SetBodyState(BS_INVENTORY);

        if (anictrl->IsStateAniActive(anictrl->_s_walk))
        {
            if (t_csg->IsInUse()) return 1;

            oCItem* itm = dynamic_cast<oCItem*>(t_csg->targetVob);
            int canDropItem = 1;

            if (IsHookAPIRegistered(C_PLAYER_CAN_DROP_ITEM))
            {
                parser->SetInstance("ITEM", itm);
                parser->SetInstance("SELF", this);
                const auto result = DaedalusCall<int>(parser, DCFunction(C_PLAYER_CAN_DROP_ITEM), {});

                if (result.has_value())
                    canDropItem = *result;
                else
                    LogDaedalusCallError(log, C_PLAYER_CAN_DROP_ITEM, result.error());
            }

            if (!canDropItem)
            {
                log->Info("Cannot drop item: {0}", itm->GetInstanceName().ToChar());
                return 1;
            }

            model->StartAni("T_STAND_2_IDROP", NULL);
        }
        else if (anictrl->IsStateAniActive(anictrl->s_idrop))
        {
            if (t_csg->targetVob) {
                DoDropVob(t_csg->targetVob);
            }
            else if (!slot.IsEmpty()) {
                RemoveFromSlot(t_csg->npcSlot, 1, 1);
            }
            else if (!t_csg->name.IsEmpty())
            {
                oCItem* item = RemoveFromInv(t_csg->name, 1);
                if (item) DoDropVob(item);
            }

            if (anictrl->t_idrop_2_stand)
            {
                anictrl->SetNextAni(anictrl->t_idrop_2_stand, anictrl->_s_walk);
                model->StartAni(anictrl->t_idrop_2_stand, NULL);
            }
            else {
                model->StartAni(anictrl->_s_walk, NULL);
            }

            t_csg->SetInUse(1);
        }

        return 0;
    }

    // G2A: 0x00762970 public: void __thiscall oCNpc::OpenDeadNpc(void)
    auto Hook_oCNpc_OpenDeadNpc = Union::CreateHook(reinterpret_cast<void*>(0x00762970), &oCNpc::Hook_OpenDeadNpc);
    void __thiscall oCNpc::Hook_OpenDeadNpc(void)
    {
        static Utils::Logger* log = Utils::CreateLogger("zDExt::oCNpc::OpenDeadNpc");

        stealnpc = GetFocusNpc();

        if (stealnpc)
        {
            if (stealnpc->IsDead() || stealnpc->IsUnconscious())
            {
                int canLootNpc = 1;

                if (IsHookAPIRegistered(C_PLAYER_CAN_LOOT_NPC))
                {
                    parser->SetInstance("OTHER", stealnpc);
                    parser->SetInstance("SELF", this);
                    const auto result = DaedalusCall<int>(parser, DCFunction(C_PLAYER_CAN_LOOT_NPC), {});

                    if (result.has_value())
                        canLootNpc = *result;
                    else
                        LogDaedalusCallError(log, C_PLAYER_CAN_LOOT_NPC, result.error());
                }

                if (!canLootNpc)
                {
                    log->Info("Cannot loot NPC: {0}", stealnpc->GetInstanceName().ToChar());
                    SetFocusVob(nullptr);
                    return;
                }

                if (npcContainer)
                {
                    delete npcContainer;
                    npcContainer = nullptr;
                }

                npcContainer = zNEW(oCNpcContainer)();
                npcContainer->SetOwner(stealnpc);

                if (!npcContainer->IsEmpty())
                {
                    zSTRING containerName = stealnpc->GetName(0);
                    npcContainer->SetName(containerName);
                    npcContainer->Open(0, 0, INV_MODE_PLUNDER);
                    OpenInventory(INV_MODE_DEFAULT);
                    npcContainer->Activate();
                    oCNpc::game_mode = NPC_GAME_PLUNDER;
                    return;
                }
            }
        }

        GetEM()->OnMessage(zNEW(oCMsgManipulate)(oCMsgManipulate::EV_CALLSCRIPT, PLAYER_PLUNDER_IS_EMPTY, -1), this);
    }

    // G2A: 0x00762B40 public: void __thiscall oCNpc::CloseDeadNpc(void)
    auto Hook_oCNpc_CloseDeadNpc = Union::CreateHook(reinterpret_cast<void*>(0x00762B40), &oCNpc::Hook_CloseDeadNpc);
    void __thiscall oCNpc::Hook_CloseDeadNpc(void)
    {
        if (!npcContainer) return;

        CloseInventory();
        npcContainer->Close();
        delete (npcContainer);
        npcContainer = nullptr;
        oCNpc::game_mode = NPC_GAME_NORMAL;
    }
#endif
}