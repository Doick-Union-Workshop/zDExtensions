#pragma once

#include <ZenGin/zGothicAPI.h>

namespace GOTHIC_NAMESPACE
{
	oCItem* zDExt_Hlp_GetItem(const int t_instance);
	int zDExt_Hlp_IsValidVob(const zSTRING& t_vobName);
	oCNpc* zDExt_Hlp_GetNpcPlunderedByPlayer();
	int zDExt_Hlp_StrCmp();
	int zDExt_Hlp_IsOptionExists(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option);
	int zDExt_Hlp_GetOptionIntValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const int t_defaultValue);
	float zDExt_Hlp_GetOptionFloatValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const float t_defaultValue);
	zSTRING zDExt_Hlp_GetOptionStringValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const zSTRING& t_defaultValue);
	void zDExt_Hlp_SetOptionIntValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const int t_defaultValue);
	void zDExt_Hlp_SetOptionFloatValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const float t_defaultValue);
	void zDExt_Hlp_SetOptionStringValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const zSTRING& t_defaultValue);
	int zDExt_Hlp_IsTestMode();
	int zDExt_Hlp_GetPlayerStatus();
}
