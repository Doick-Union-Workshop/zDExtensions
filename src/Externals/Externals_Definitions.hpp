namespace GOTHIC_NAMESPACE
{
#define BetterDaedalusExternalWithCustomName(name, function) BetterDaedalusExternals::DaedalusExternal<#name,function>

	BetterExternalDefinition(parser,
		/* MENU */
		BetterDaedalusExternal(zDExt_Menu_SetItemText),
		BetterDaedalusExternal(zDExt_Menu_GetItemText),
		/* STR */
		BetterDaedalusExternal(zDExt_Str_Upper),
		BetterDaedalusExternal(zDExt_Str_Lower),
		BetterDaedalusExternal(zDExt_Str_Capital),
		BetterDaedalusExternal(zDExt_Str_StartsWith),
		BetterDaedalusExternal(zDExt_Str_EndsWith),
		BetterDaedalusExternal(zDExt_Str_Length),
		BetterDaedalusExternal(zDExt_Str_Cut),
		BetterDaedalusExternal(zDExt_Str_Put),
		/* AI */
		BetterDaedalusExternal(zDExt_AI_TurnToWP),
		BetterDaedalusExternal(zDExt_AI_TurnToVob),
		BetterDaedalusExternal(zDExt_AI_TurnToPos),
		BetterDaedalusExternal(zDExt_AI_CallFunction),
		/* NPC */
		BetterDaedalusExternal(zDExt_Npc_GetRoutineFuncName),
		BetterDaedalusExternal(zDExt_Npc_GetRoutineName),
		BetterDaedalusExternal(zDExt_Npc_EquipItem),
		BetterDaedalusExternal(zDExt_Npc_GetWalkMode),
		BetterDaedalusExternal(zDExt_Npc_IsStanding),
		BetterDaedalusExternal(zDExt_Npc_IsWalking),
		BetterDaedalusExternal(zDExt_Npc_HasOverlayMds),
		BetterDaedalusExternal(zDExt_Npc_HasTimedOverlayMds),
		BetterDaedalusExternal(zDExt_Npc_OpenDeadNpcInventory),
		BetterDaedalusExternal(zDExt_Npc_CloseDeadNpcInventory),
		BetterDaedalusExternal(zDExt_Npc_CloseInventory),
		BetterDaedalusExternal(zDExt_Npc_OpenInventorySteal),
		BetterDaedalusExternal(zDExt_Npc_CloseInventorySteal),
		BetterDaedalusExternal(zDExt_Npc_Teleport),
		BetterDaedalusExternal(zDExt_Npc_GetDistToPos),
		BetterDaedalusExternal(zDExt_Npc_GetDistToVob),
		BetterDaedalusExternal(zDExt_Npc_GetVisualBody),
		BetterDaedalusExternal(zDExt_Npc_GetVisualHead),
		BetterDaedalusExternal(zDExt_Npc_GetPortalRoom),
		BetterDaedalusExternal(zDExt_Npc_SetAsPlayer),
		BetterDaedalusExternal(zDExt_Npc_TakeItem),
		BetterDaedalusExternal(zDExt_Npc_DropItem),
		BetterDaedalusExternal(zDExt_Npc_EquipArmor),
		BetterDaedalusExternal(zDExt_Npc_UnequipArmor),
		/* HLP */
		BetterDaedalusExternal(zDExt_Hlp_GetItem),
		BetterDaedalusExternal(zDExt_Hlp_IsValidVob),
		BetterDaedalusExternal(zDExt_Hlp_GetNpcPlunderedByPlayer),
		BetterDaedalusExternal(zDExt_Log_GetTopicStatus),
		BetterDaedalusExternal(zDExt_Hlp_IsOptionExists),
		BetterDaedalusExternal(zDExt_Hlp_GetOptionIntValue),
		BetterDaedalusExternal(zDExt_Hlp_GetOptionFloatValue),
		BetterDaedalusExternal(zDExt_Hlp_GetOptionStringValue),
		BetterDaedalusExternal(zDExt_Hlp_SetOptionIntValue),
		BetterDaedalusExternal(zDExt_Hlp_SetOptionFloatValue),
		BetterDaedalusExternal(zDExt_Hlp_SetOptionStringValue),
		BetterDaedalusExternal(zDExt_Hlp_IsTestMode),
		/* WLD */
		BetterDaedalusExternal(zDExt_Wld_RemoveVob),
		BetterDaedalusExternal(zDExt_Wld_SetRainTime),
		BetterDaedalusExternal(zDExt_Wld_SetRainOn),
		BetterDaedalusExternal(zDExt_Wld_SetRainOff),
		BetterDaedalusExternal(zDExt_Wld_GetPlayerPortalRoom),
		BetterDaedalusExternal(zDExt_Wld_GetWorldName),
		BetterDaedalusExternal(zDExt_Wld_OverrideWorldFogColors),
		BetterDaedalusExternal(zDExt_Wld_ChangeLevel),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertVob, zDExt_Wld_InsertVob<zCVob>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertMob, zDExt_Wld_InsertVob<oCMOB>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertMobInter, zDExt_Wld_InsertVob<oCMobInter>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertMobContainer, zDExt_Wld_InsertVob<oCMobContainer>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertMobFire, zDExt_Wld_InsertVob<oCMobFire>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertMobDoor, zDExt_Wld_InsertVob<oCMobDoor>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertMobBed, zDExt_Wld_InsertVob<oCMobBed>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertVobPos, zDExt_Wld_InsertVobPos<zCVob>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertMobPos, zDExt_Wld_InsertVobPos<oCMOB>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertMobInterPos, zDExt_Wld_InsertVobPos<oCMobInter>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertMobContainerPos, zDExt_Wld_InsertVobPos<oCMobContainer>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertMobFirePos, zDExt_Wld_InsertVobPos<oCMobFire>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertMobDoorPos, zDExt_Wld_InsertVobPos<oCMobDoor>),
		BetterDaedalusExternalWithCustomName(zDExt_Wld_InsertMobBedPos, zDExt_Wld_InsertVobPos<oCMobBed>),
		/* VOB */
		BetterDaedalusExternal(zDExt_Vob_MoveTo),
		BetterDaedalusExternal(zDExt_Vob_MoveToPos),
		BetterDaedalusExternal(zDExt_Vob_SetCollisionDetection),
		BetterDaedalusExternal(zDExt_Vob_RotateWorld),
		BetterDaedalusExternal(zDExt_Vob_RotateLocal),
		BetterDaedalusExternal(zDExt_Vob_SetVisual),
		BetterDaedalusExternal(zDExt_Vob_GetDistToPos),
		BetterDaedalusExternal(zDExt_Vob_GetDistToNpc),
		BetterDaedalusExternal(zDExt_Vob_SetToFloor),
		BetterDaedalusExternal(zDExt_Vob_GetPortalRoom),
		/* MOB */
		BetterDaedalusExternal(zDExt_Mob_SetFocusName),
		BetterDaedalusExternal(zDExt_Mob_GetFocusName),
		BetterDaedalusExternal(zDExt_Mob_GetScemeName),
		BetterDaedalusExternal(zDExt_Mob_SetUseWithItem),
		/* MDL */
		BetterDaedalusExternal(zDExt_Mdl_SetVisualBody),
		BetterDaedalusExternal(zDExt_Mdl_SetVisualBodyTexture),
		BetterDaedalusExternal(zDExt_Mdl_SetVisualBodySkinTexture),
		BetterDaedalusExternal(zDExt_Mdl_SetVisualHead),
		BetterDaedalusExternal(zDExt_Mdl_SetVisualHeadTexture),
		BetterDaedalusExternal(zDExt_Mdl_SetVisualTeethTexture)
	);

	/*BetterExternalDefinition(menuParser,
		BetterDaedalusExternalWithName(Menu_SetItemText),
		BetterDaedalusExternalWithName(Menu_GetItemText),
		BetterDaedalusExternalWithName(Hlp_StrCmp)
	);*/

	void zDExt_DefineExternals()
	{
		// TODO: Add BDE definitions when PopVarAddress and array passing are supported
		parser->DefineExternal("zDExt_GetIntArrayValue", zDExt_GetArrayValue<int>,
			zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_VOID);
		parser->DefineExternal("zDExt_GetStringArrayValue", zDExt_GetArrayValue<zSTRING>,
			zPAR_TYPE_STRING, zPAR_TYPE_STRING, zPAR_TYPE_INT, zPAR_TYPE_VOID);
		parser->DefineExternal("zDExt_SetIntArrayValue", zDExt_SetArrayValue<int>,
			zPAR_TYPE_VOID, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_VOID);
		parser->DefineExternal("zDExt_SetStringArrayValue", zDExt_SetArrayValue<zSTRING>,
			zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_INT, zPAR_TYPE_STRING, zPAR_TYPE_VOID);
		parser->DefineExternal("zDExt_Str_Format", zDExt_Str_Format,
			zPAR_TYPE_STRING, (zPAR_TYPE_INSTANCE + 1), zPAR_TYPE_VOID);

		// TODO: Change definitons to BetterDaedalusExternal when multi parser definitons are supported
		parserMenu->DefineExternal("zDExt_Menu_SetItemText", zDExt_Menu_SetItemText_MP,
			zPAR_TYPE_VOID, zPAR_TYPE_STRING, zPAR_TYPE_STRING, zPAR_TYPE_INT, zPAR_TYPE_INT, zPAR_TYPE_VOID);
		parserMenu->DefineExternal("zDExt_Menu_GetItemText", zDExt_Menu_GetItemText_MP,
			zPAR_TYPE_STRING, zPAR_TYPE_STRING, zPAR_TYPE_INT, zPAR_TYPE_VOID);
		parserMenu->DefineExternal("zDExt_Hlp_StrCmp", zDExt_Hlp_StrCmp,
			zPAR_TYPE_INT, zPAR_TYPE_STRING, zPAR_TYPE_STRING, zPAR_TYPE_VOID);
		parserMenu->DefineExternal("zDExt_Str_Format", zDExt_Str_Format,
			zPAR_TYPE_STRING, (zPAR_TYPE_INSTANCE + 1), zPAR_TYPE_VOID);

		BetterDaedalusExternals::DefineExternals();
	}
}
