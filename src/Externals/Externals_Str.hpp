#pragma once

#include <ZenGin/zGothicAPI.h>

namespace GOTHIC_NAMESPACE
{
	zSTRING zDExt_Str_Upper(const zSTRING& t_str);
	zSTRING zDExt_Str_Lower(const zSTRING& t_str);
	zSTRING zDExt_Str_Capital(const zSTRING& t_str);
	int zDExt_Str_StartsWith(const zSTRING& t_str, const zSTRING& t_prefix);
	int zDExt_Str_EndsWith(const zSTRING& t_str, const zSTRING& t_suffix);
	int zDExt_Str_Length(const zSTRING& t_str);
	zSTRING zDExt_Str_Cut(const zSTRING& t_str, const int t_start, const int t_end);
	zSTRING zDExt_Str_Put(const zSTRING& t_str, const zSTRING& t_value, const int t_idx);
	int zDExt_Str_Format();
}
