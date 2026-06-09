namespace GOTHIC_NAMESPACE
{
	zSTRING zDExt_Str_Upper(const zSTRING& t_str)
	{
		zSTRING result{ t_str };
		(void)result.Upper();
		return result;
	}

	zSTRING zDExt_Str_Lower(const zSTRING& t_str)
	{
		zSTRING result{ t_str };
		(void)result.Lower();
		return result;
	}

	zSTRING zDExt_Str_Capital(const zSTRING& t_str)
	{
		zSTRING result{ t_str };
		(void)result.UpperFirstLowerRest();
		return result;
	}

	int zDExt_Str_StartsWith(const zSTRING& t_str, const zSTRING& t_prefix)
	{
		zSTRING str{ t_str };
		(void)str.Upper();

		zSTRING prefix{ t_prefix };
		(void)prefix.Upper();

		return str.Search(prefix, 0) == 0;
	}

	int zDExt_Str_EndsWith(const zSTRING& t_str, const zSTRING& t_suffix)
	{
		zSTRING str{ t_str };
		(void)str.Upper();

		zSTRING suffix{ t_suffix };
		(void)suffix.Upper();

		int suffixPos = str.Length() - suffix.Length();
		return str.Search(suffix, suffixPos) == suffixPos;
	}

	zSTRING zDExt_Str_Length(const zSTRING& t_str)
	{
		return t_str.Length();
	}

	zSTRING zDExt_Str_Cut(const zSTRING& t_str, const int t_start, const int t_end)
	{
		zSTRING str{ t_str };
		(void)str.Delete(t_start, t_end);
		return str;
	}

	zSTRING zDExt_Str_Put(const zSTRING& t_str, const zSTRING& t_value, const int t_idx)
	{
		zSTRING str{ t_str };
		(void)str.Insert(t_idx, t_value);
		return str;
	}

    int zDExt_Str_Format()
    {
        const auto parser = zCParser::GetParser();

        static zSTRING format = "";
        zSTRING parameter_s;
        int parameter_i;
        float parameter_f;

        parser->GetParameter(format);

		for (u_int i = format.Length() - 1; i > 1; --i)
		{
            if (format[i - 1] == '%') {
				switch (format[i])
				{
				case 's':
					parser->GetParameter(parameter_s);
					(void)format.Delete(i - 1, 2);
					(void)format.Insert(i - 1, parameter_s);
					break;
				case 'i':
					parser->GetParameter(parameter_i);
					parameter_s = parameter_i;
					(void)format.Delete(i - 1, 2);
					(void)format.Insert(i - 1, parameter_s);
					break;
				case 'f':
					parser->GetParameter(parameter_f);
					parameter_s = parameter_f;
					(void)format.Delete(i - 1, 2);
					(void)format.Insert(i - 1, parameter_s);
					break;
				case 'b':
					parser->GetParameter(parameter_i);
					parameter_s = parameter_i ? "True" : "False";
					(void)format.Delete(i - 1, 2);
					(void)format.Insert(i - 1, parameter_s);
					break;
				}
            }
        }

        parser->SetReturn(format);
        return 1;
    }
}
