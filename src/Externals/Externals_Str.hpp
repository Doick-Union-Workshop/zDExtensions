namespace GOTHIC_NAMESPACE
{
	static zSTRING Str_Upper(const zSTRING& t_str)
	{
		if (t_str.IsEmpty()) return zSTRING{};

		return zSTRING(t_str).Upper();
	}

	static zSTRING Str_Lower(const zSTRING& t_str)
	{
		if (t_str.IsEmpty()) return zSTRING{};

		return zSTRING(t_str).Lower();
	}

	static zSTRING Str_Capitel(const zSTRING& t_str)
	{
		if (t_str.IsEmpty()) return zSTRING{};

		return zSTRING(t_str).UpperFirstLowerRest();
	}

	static int Str_StartsWith(const zSTRING& t_str, const zSTRING& t_prefix)
	{
		if (t_str.IsEmpty() || t_prefix.IsEmpty()) return 0;

		zSTRING str = Str_Upper(t_str);
		zSTRING prefix = Str_Upper(t_prefix);

		return str.Search(prefix, 0) == 0;
	}

	static int Str_EndsWith(const zSTRING& t_str, const zSTRING& t_suffix)
	{
		if (t_str.IsEmpty() || t_suffix.IsEmpty()) return 0;

		zSTRING str = Str_Upper(t_str);
		zSTRING suffix = Str_Upper(t_suffix);
		int suffixPos = str.Length() - suffix.Length();

		return str.Search(suffix, suffixPos) == suffixPos;
	}

	static zSTRING Str_Cut(const zSTRING& t_str, const int t_start, const int t_end)
	{
		if (t_str.IsEmpty()) return 0;

		zSTRING str = Str_Upper(t_str);
		str.Delete(t_start, t_end);
		return str;
	}
}