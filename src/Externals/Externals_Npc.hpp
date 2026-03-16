namespace GOTHIC_NAMESPACE
{
	zSTRING Npc_GetRoutineFuncName(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return {};
		}

		zSTRING routine = t_npc->state.GetRoutineName();
		if (!Str_StartsWith(routine, "RTN_"))
		{
			return {};
		}

		return routine;
	}

	zSTRING Npc_GetRoutineName(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return {};
		}

		zSTRING routine = t_npc->state.GetRoutineName();
		zSTRING prefix = "RTN_";
		zSTRING suffix{ "_" + t_npc->idx };

		if (Str_StartsWith(routine, prefix))
		{
			routine.Delete(0, prefix.Length());
		}

		int rtnLen = routine.Length();

		if (Str_EndsWith(routine, suffix))
		{
			routine.Delete(rtnLen - suffix.Length(), rtnLen);
		}

		return routine;
	}

	void Npc_EquipItem(oCNpc* t_npc, const int t_itemInstance)
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

	int Npc_GetWalkMode(oCNpc* t_npc)
	{
		if (!t_npc || !t_npc->anictrl) {
			return -1;
		}

		return t_npc->anictrl->walkmode;
	}

	int Npc_IsStanding(oCNpc* t_npc)
	{
		if (!t_npc || !t_npc->anictrl) {
			return 0;
		}

		return t_npc->anictrl->IsStanding();
	}

	int Npc_IsWalking(oCNpc* t_npc)
	{
		if (!t_npc || !t_npc->anictrl) {
			return 0;
		}

		return t_npc->anictrl->IsWalking();
	}

	int Npc_HasOverlayMds(oCNpc* t_npc, const zSTRING& t_overlay)
	{
		if (!t_npc)
		{
			return 0;
		}

		zSTRING overlay{ t_overlay };
		overlay.Upper();

		return t_npc->activeOverlays.IsInList(overlay);
	}

	int Npc_HasTimedOverlayMds(oCNpc* t_npc, const zSTRING& t_overlay)
	{
		if (!t_npc)
		{
			return 0;
		}

		zSTRING overlay{ t_overlay };
		overlay.Upper();

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

	void Npc_Teleport(oCNpc* t_npc, const zSTRING& t_point)
	{
		if (!t_npc)
		{
			return;
		}

		zSTRING point{ t_point };
		point.Upper();
		t_npc->BeamTo(point);
	}

	void Npc_OpenDeadNpcInventory(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->OpenDeadNpc();
	}

	void Npc_CloseInventory(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->CloseInventory();
	}

	void Npc_CloseInventorySteal(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->CloseSteal();
	}

	void Npc_CloseDeadNpcInventory(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->CloseDeadNpc();
	}

	int Npc_GetDistToPos(oCNpc* t_npc, const int t_posX, const int t_posY, const int t_posZ)
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

	int Npc_GetDistToVob(oCNpc* t_npc, const zSTRING& t_vobName)
	{
		int dist = INT_MAX;

		if (!t_npc)
		{
			return dist;
		}

		static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Npc_GetDistToVob");
		zCVob* vob = FindVobByName(t_vobName, logger);
		if (!vob)
		{
			return dist;
		}

		dist = static_cast<int>(t_npc->GetDistanceToVob(*vob));
		return dist;
	}

	zSTRING Npc_GetVisualBody(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return {};
		}

		return t_npc->GetVisualBody();
	}

	zSTRING Npc_GetVisualHead(oCNpc* t_npc)
	{
		if (!t_npc)
		{
			return {};
		}

		return t_npc->GetVisualHead();
	}

	zSTRING Npc_GetPortalRoom(oCNpc* t_npc)
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
}
