#pragma once

#include <ZenGin/zGothicAPI.h>

namespace GOTHIC_NAMESPACE
{
	void zDExt_Mob_SetFocusName(const zSTRING& t_mobName, const zSTRING& t_focusName);
	zSTRING zDExt_Mob_GetFocusName(const zSTRING& t_mobName);
	zSTRING zDExt_Mob_GetScemeName(const zSTRING& t_mobName);
	void zDExt_Mob_SetUseWithItem(const zSTRING& t_mobName, const zSTRING& t_itemInstance);
}
