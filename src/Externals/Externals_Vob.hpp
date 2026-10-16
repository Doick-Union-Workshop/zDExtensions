#pragma once

#include <ZenGin/zGothicAPI.h>

namespace GOTHIC_NAMESPACE
{
	void zDExt_Vob_RotateWorld(const zSTRING& t_vobName, const float t_posX, const float t_posY, const float t_posZ);
	void zDExt_Vob_RotateLocal(const zSTRING& t_vobName, const float t_posX, const float t_posY, const float t_posZ);
	void zDExt_Vob_SetVisual(const zSTRING& t_vobName, const zSTRING& t_visualName);
	void zDExt_Vob_SetToFloor(const zSTRING& t_vobName);
	void zDExt_Vob_MoveTo(const zSTRING& t_vobName, const zSTRING& t_pointName);
	void zDExt_Vob_MoveToPos(const zSTRING& t_vobName, const float t_posX, const float t_posY, const float t_posZ);
	void zDExt_Vob_SetCollisionDetection(const zSTRING& t_vobName, const int t_dynamicCollDet, const int t_staticCollDet);
	int zDExt_Vob_GetDistToPos(const zSTRING& t_vobName, const float t_posX, const float t_posY, const float t_posZ);
	int zDExt_Vob_GetDistToNpc(const zSTRING& t_vobName, oCNpc* t_npc);
	zSTRING zDExt_Vob_GetPortalRoom(const zSTRING& t_vobName);
}
