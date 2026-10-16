#pragma once

#include <ZenGin/zGothicAPI.h>

namespace GOTHIC_NAMESPACE
{
	void zDExt_Mdl_SetVisualBody(oCNpc* t_npc, const zSTRING& t_body);
	void zDExt_Mdl_SetVisualBodyTexture(oCNpc* t_npc, const int t_bodyTexNr);
	void zDExt_Mdl_SetVisualBodySkinTexture(oCNpc* t_npc, const int t_bodySkinTexNr);
	void zDExt_Mdl_SetVisualHead(oCNpc* t_npc, const zSTRING& t_head);
	void zDExt_Mdl_SetVisualHeadTexture(oCNpc* t_npc, const int t_headTexNr);
	void zDExt_Mdl_SetVisualTeethTexture(oCNpc* t_npc, const int t_teethTexNr);
}
