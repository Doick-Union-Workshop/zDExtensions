namespace GOTHIC_NAMESPACE
{
	static zSTRING Npc_GetRoutineFuncName(oCNpc* t_npc)
	{
		if (!t_npc) return zSTRING{};

		zSTRING routine = t_npc->state.GetRoutineName();

		if (!Str_StartsWith(routine, "RTN_"))
			return zSTRING{};
		return routine;
	}

	static zSTRING Npc_GetRoutineName(oCNpc* t_npc)
	{
		if (!t_npc) return zSTRING{};

		zSTRING routine = Npc_GetRoutineFuncName(t_npc);
		zSTRING prefix = "RTN_";
		zSTRING suffix = "_" + zSTRING(t_npc->idx);

		if (Str_StartsWith(routine, prefix))
			routine.Delete(0, prefix.Length());

		int rtnLen = routine.Length();

		if (Str_EndsWith(routine, suffix))
			routine.Delete(rtnLen - suffix.Length(), rtnLen);

		return routine;
	}

	static void Npc_EquipItem(oCNpc* t_npc, const int t_instance)
	{
		if (!t_npc || !t_instance) return;

		auto par = zCParser::GetParser();
		zCPar_Symbol* sym = par->GetSymbol(t_instance);
		oCItem* item = dynamic_cast<oCItem*>((zCVob*)sym->GetInstanceAdr());

		if (!item) return;

		t_npc->Equip(item);
	}

	static int Npc_GetWalkMode(oCNpc* t_npc)
	{
		if (!t_npc) return -1;

		zSTRING walkMode = t_npc->anictrl->GetWalkModeString();
		walkMode.Upper();

		if (walkMode == "RUN")
			return static_cast<int>(ANI_WALKMODE_RUN);
		else if (walkMode == "WALK")
			return static_cast<int>(ANI_WALKMODE_WALK);
		else if (walkMode == "SNEAK")
			return static_cast<int>(ANI_WALKMODE_SNEAK);
		else if (walkMode.IsEmpty())
			return static_cast<int>(ANI_WALKMODE_WATER);

		return -1;
	}

	static int Npc_IsStanding(oCNpc* t_npc)
	{
		if (!t_npc) return 0;

		return static_cast<int>(t_npc->anictrl->IsStanding());
	}

	static int Npc_IsWalking(oCNpc* t_npc)
	{
		if (!t_npc) return 0;

		return static_cast<int>(t_npc->anictrl->IsWalking());
	}

	static int Npc_HasOverlayMds(oCNpc* t_npc, const zSTRING& t_overlay)
	{
		if (!t_npc || t_overlay.IsEmpty()) return 0;

		zSTRING overlay = zSTRING(t_overlay).Upper();
		return t_npc->activeOverlays.IsInList(overlay);
	}

	static int Npc_HasTimedOverlayMds(oCNpc* t_npc, const zSTRING& t_overlay)
	{
		if (!t_npc || t_overlay.IsEmpty()) return 0;

		zSTRING overlay = zSTRING(t_overlay).Upper();
		auto list = t_npc->timedOverlays.GetNextInList();

		while (list)
		{
			if (list->GetData()->mdsOverlayName.Upper() == overlay)
				return 1;

			list = list->GetNextInList();
		}

		return 0;
	}

	static void Npc_Teleport(oCNpc* t_npc, const zSTRING& t_point)
	{
		if (!t_npc || t_point.IsEmpty()) return;

		zSTRING point = t_point;
		t_npc->BeamTo(point.Upper());
	}

	static void Npc_OpenDeadNpcInventory(oCNpc* t_npc)
	{
		if (!t_npc) return;

		t_npc->OpenDeadNpc();
	}

	static void Npc_CloseInventory(oCNpc* t_npc)
	{
		if (!t_npc) return;

		t_npc->CloseInventory();
	}

	static void Npc_CloseInventorySteal(oCNpc* t_npc)
	{
		if (!t_npc) return;

		t_npc->CloseSteal();
	}

	static void Npc_CloseDeadNpcInventory(oCNpc* t_npc)
	{
		if (!t_npc) return;

		t_npc->CloseDeadNpc();
	}

	static int Npc_GetDistToPos(oCNpc* t_npc, C_POSITION* t_position)
	{
		int dist = INT_MAX;

		if (!t_npc || !t_position) return dist;

		zVEC3 pos = zVEC3(
			(float)t_position->X,
			(float)t_position->Y,
			(float)t_position->Z);
		dist = static_cast<int>(t_npc->GetDistanceToPos2(pos, 1));
		return dist;
	}

	static int Npc_GetDistToVob(oCNpc* t_npc, const zSTRING& t_vobName)
	{
		int dist = INT_MAX;

		if (!t_npc || t_vobName.IsEmpty()) return dist;

		static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Npc_GetDistToVob");

		zCVob* vob = FindVobByName(t_vobName, log);

		if (!vob) return dist;

		dist = static_cast<int>(t_npc->GetDistanceToVob(*vob));
		return dist;
	}

	static zSTRING Npc_GetVisualBody(oCNpc* t_npc)
	{
		if (!t_npc) return zSTRING{};

		return t_npc->GetVisualBody();
	}

	static zSTRING Npc_GetVisualHead(oCNpc* t_npc)
	{
		if (!t_npc) return zSTRING{};

		return t_npc->GetVisualHead();
	}
}