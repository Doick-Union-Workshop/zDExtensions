#pragma once

#include <ZenGin/zGothicAPI.h>

namespace GOTHIC_NAMESPACE
{
	zSTRING zDExt_Npc_GetRoutineFuncName(oCNpc* t_npc);
	zSTRING zDExt_Npc_GetRoutineName(oCNpc* t_npc);
	void zDExt_Npc_EquipItem(oCNpc* t_npc, const int t_itemInstance);
	void zDExt_Npc_EquipArmor(oCNpc* t_npc, const int t_itemInstance);
	void zDExt_Npc_UnequipArmor(oCNpc* t_npc, const int t_itemInstance);
	int zDExt_Npc_GetWalkMode(oCNpc* t_npc);
	int zDExt_Npc_IsStanding(oCNpc* t_npc);
	int zDExt_Npc_IsWalking(oCNpc* t_npc);
	int zDExt_Npc_HasOverlayMds(oCNpc* t_npc, const zSTRING& t_overlay);
	int zDExt_Npc_HasTimedOverlayMds(oCNpc* t_npc, const zSTRING& t_overlay);
	void zDExt_Npc_Teleport(oCNpc* t_npc, const zSTRING& t_point);
	void zDExt_Npc_OpenDeadNpcInventory(oCNpc* t_npc);
	void zDExt_Npc_CloseDeadNpcInventory(oCNpc* t_npc);
	void zDExt_Npc_CloseInventory(oCNpc* t_npc);
	void zDExt_Npc_OpenInventorySteal(oCNpc* t_npc);
	void zDExt_Npc_CloseInventorySteal(oCNpc* t_npc);
	int zDExt_Npc_GetDistToPos(oCNpc* t_npc, const float t_posX, const float t_posY, const float t_posZ);
	int zDExt_Npc_GetDistToVob(oCNpc* t_npc, const zSTRING& t_vobName);
	zSTRING zDExt_Npc_GetVisualBody(oCNpc* t_npc);
	zSTRING zDExt_Npc_GetVisualHead(oCNpc* t_npc);
	zSTRING zDExt_Npc_GetPortalRoom(oCNpc* t_npc);
	void zDExt_Npc_SetAsPlayer(oCNpc* t_npc);
	void zDExt_Npc_TakeItem(oCNpc* t_npc, oCItem* t_item);
	void zDExt_Npc_DropItem(oCNpc* t_npc, oCItem* t_item);
}
