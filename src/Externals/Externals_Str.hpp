namespace GOTHIC_NAMESPACE
{
	static zSTRING Str_Upper(const zSTRING& t_str)
	{
		return zSTRING(t_str).Upper();
	}

	static zSTRING Str_Lower(const zSTRING& t_str)
	{
		return zSTRING(t_str).Lower();
	}

	static zSTRING Str_Capitel(const zSTRING& t_str)
	{
		return zSTRING(t_str).UpperFirstLowerRest();
	}

	static zSTRING Str_StartsWith(const zSTRING& t_str, const zSTRING& t_prefix)
	{
		return t_str.Search(t_prefix, 0) == 0;
	}

	static zSTRING Str_EndsWith(const zSTRING& t_str, const zSTRING& t_suffix)
	{
		int suffixPos = t_str.Length() - t_suffix.Length();
		return t_str.Search(t_suffix, suffixPos) == suffixPos;
	}
}