namespace GOTHIC_NAMESPACE
{
	zSTRING zDExt_Npc_GetRoutineFuncName(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return {};
		}

		zSTRING routine = t_npc->state.GetRoutineName();
		if (!zDExt_Str_StartsWith(routine, "RTN_"))
		{
			return {};
		}

		return routine;
	}

	zSTRING zDExt_Npc_GetRoutineName(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return {};
		}

		zSTRING routine = t_npc->state.GetRoutineName();
		zSTRING prefix = "RTN_";
		zSTRING suffix{ "_" + t_npc->idx };

		if (zDExt_Str_StartsWith(routine, prefix))
		{
			(void)routine.Delete(0, prefix.Length());
		}

		int rtnLen = routine.Length();

		if (zDExt_Str_EndsWith(routine, suffix))
		{
			(void)routine.Delete(rtnLen - suffix.Length(), rtnLen);
		}

		return routine;
	}

	void zDExt_Npc_EquipItem(oCNpc* t_npc, const int t_itemInstance)
	{
		if (!t_npc || !t_itemInstance)
		{
			return;
		}

		zCPar_Symbol* sym = parser->GetSymbol(t_itemInstance);
		oCItem* item = dynamic_cast<oCItem*>((zCVob*)sym->GetInstanceAdr());
		if (!item)
		{
			return;
		}

		t_npc->Equip(item);
	}

	void zDExt_Npc_EquipArmor(oCNpc* t_npc, const int t_itemInstance)
	{
		if (!t_npc || !t_itemInstance)
		{
			return;
		}

		zCPar_Symbol* sym = parser->GetSymbol(t_itemInstance);
		oCItem* item = dynamic_cast<oCItem*>((zCVob*)sym->GetInstanceAdr());
		if (!item)
		{
			return;
		}

		t_npc->EquipArmor(item);
	}

	void zDExt_Npc_UnequipArmor(oCNpc* t_npc, const int t_itemInstance)
	{
		if (!t_npc || !t_itemInstance)
		{
			return;
		}

		oCItem* item = t_npc->GetEquippedArmor();
		if (!item)
		{
			return;
		}

		t_npc->EquipArmor(item);
	}

	int zDExt_Npc_GetWalkMode(oCNpc* t_npc)
	{
		if (!t_npc || !t_npc->anictrl)
		{
			return -1;
		}

		return t_npc->anictrl->walkmode;
	}

	int zDExt_Npc_IsStanding(oCNpc* t_npc)
	{
		if (!t_npc || !t_npc->anictrl)
		{
			return 0;
		}

		return t_npc->anictrl->IsStanding();
	}

	int zDExt_Npc_IsWalking(oCNpc* t_npc)
	{
		if (!t_npc || !t_npc->anictrl)
		{
			return 0;
		}

		return t_npc->anictrl->IsWalking();
	}

	int zDExt_Npc_HasOverlayMds(oCNpc* t_npc, const zSTRING& t_overlay)
	{
		if (!t_npc)
		{
			return 0;
		}

		zSTRING overlay{ t_overlay };
		(void)overlay.Upper();

		return t_npc->activeOverlays.IsInList(overlay);
	}

	int zDExt_Npc_HasTimedOverlayMds(oCNpc* t_npc, const zSTRING& t_overlay)
	{
		if (!t_npc)
		{
			return 0;
		}

		zSTRING overlay{ t_overlay };
		(void)overlay.Upper();

		auto list = t_npc->timedOverlays.GetNextInList();
		while (list)
		{
			if (list->GetData()->mdsOverlayName.Upper() == overlay) {
				return 1;
			}

			list = list->GetNextInList();
		}

		return 0;
	}

	void zDExt_Npc_Teleport(oCNpc* t_npc, const zSTRING& t_point)
	{
		if (!t_npc)
		{
			return;
		}

		zSTRING point{ t_point };
		(void)point.Upper();
		t_npc->BeamTo(point);
	}

	void zDExt_Npc_OpenDeadNpcInventory(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->OpenDeadNpc();
	}

	void zDExt_Npc_CloseDeadNpcInventory(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->CloseDeadNpc();
	}

	void zDExt_Npc_CloseInventory(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->CloseInventory();
	}

	void zDExt_Npc_OpenInventorySteal(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->OpenSteal();
	}

	void zDExt_Npc_CloseInventorySteal(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->CloseSteal();
	}

	int zDExt_Npc_GetDistToPos(oCNpc* t_npc, const int t_posX, const int t_posY, const int t_posZ)
	{
		int dist = INT_MAX;

		if (!t_npc)
		{
			return dist;
		}

		auto pos = zVEC3((float)t_posX, (float)t_posY, (float)t_posZ);
		dist = static_cast<int>(t_npc->GetDistanceToPos2(pos, 1));
		return dist;
	}

	int zDExt_Npc_GetDistToVob(oCNpc* t_npc, const zSTRING& t_vobName)
	{
		int dist = INT_MAX;

		if (!t_npc)
		{
			return dist;
		}

		static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Npc_GetDistToVob");
		zCVob* vob = FindVobByName(t_vobName, logger);
		if (!vob)
		{
			return dist;
		}

		dist = static_cast<int>(t_npc->GetDistanceToVob(*vob));
		return dist;
	}

	zSTRING zDExt_Npc_GetVisualBody(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return {};
		}

		return t_npc->GetVisualBody();
	}

	zSTRING zDExt_Npc_GetVisualHead(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return {};
		}

		return t_npc->GetVisualHead();
	}

	zSTRING zDExt_Npc_GetPortalRoom(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return {};
		}

		if (const zSTRING* portal = t_npc->GetSectorNameVobIsIn())
		{
			return *portal;
		}

		return {};
	}

	void zDExt_Npc_SetAsPlayer(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->SetAsPlayer();
	}

	void zDExt_Npc_TakeItem(oCNpc* t_npc, oCItem* t_item)
	{
		if (!t_npc || !t_item)
		{
			return;
		}

		t_npc->DoTakeVob(t_item);
	}

	void zDExt_Npc_DropItem(oCNpc* t_npc, oCItem* t_item)
	{
		if (!t_npc || !t_item)
		{
			return;
		}

		t_npc->DoDropVob(t_item);
	}
}
