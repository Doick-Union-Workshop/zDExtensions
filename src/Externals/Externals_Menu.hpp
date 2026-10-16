#pragma once

#include <ZenGin/zGothicAPI.h>

namespace GOTHIC_NAMESPACE
{
	void zDExt_Menu_SetItemText(const zSTRING& t_name, const zSTRING& t_text, const int t_line, const int t_drawNow);
	zSTRING zDExt_Menu_GetItemText(const zSTRING& t_name, const int t_line);
	int zDExt_Menu_SetItemText_MP();
	int zDExt_Menu_GetItemText_MP();
}
