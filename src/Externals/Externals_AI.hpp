#pragma once

#include <ZenGin/zGothicAPI.h>
#include "Utils/BetterDaedalusExternals.h"

namespace GOTHIC_NAMESPACE
{
	void zDExt_AI_TurnToWP(oCNpc* t_npc, const zSTRING& t_pointName);
	void zDExt_AI_TurnToVob(oCNpc* t_npc, const zSTRING& t_pointName);
	void zDExt_AI_TurnToPos(oCNpc* t_npc, const float t_posX, const float t_posY, const float t_posZ);
	void zDExt_AI_CallFunction(oCNpc* t_npc, const BetterDaedalusExternals::DaedalusFunctionType t_function);
}
