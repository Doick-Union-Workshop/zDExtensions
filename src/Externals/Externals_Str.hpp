namespace GOTHIC_NAMESPACE
{
	zSTRING Str_Upper(const zSTRING& t_str)
	{
		zSTRING result{ t_str };
		result.Upper();
		return result;
	}

	zSTRING Str_Lower(const zSTRING& t_str)
	{
		zSTRING result{ t_str };
		result.Lower();
		return result;
	}

	zSTRING Str_Capitel(const zSTRING& t_str)
	{
		zSTRING result{ t_str };
		result.UpperFirstLowerRest();
		return result;
	}

	int Str_StartsWith(const zSTRING& t_str, const zSTRING& t_prefix)
	{
		zSTRING str{ t_str };
		str.Upper();
		zSTRING prefix{ t_prefix };
		prefix.Upper();
		return str.Search(prefix, 0) == 0;
	}

	int Str_EndsWith(const zSTRING& t_str, const zSTRING& t_suffix)
	{
		zSTRING str{ t_str };
		str.Upper();
		zSTRING suffix{ t_suffix };
		suffix.Upper();
		int suffixPos = str.Length() - suffix.Length();
		return str.Search(suffix, suffixPos) == suffixPos;
	}

	zSTRING Str_Cut(const zSTRING& t_str, const int t_start, const int t_end)
	{
		zSTRING str{ t_str };
		str.Delete(t_start, t_end);
		return str;
	}

	zSTRING Str_Put(const zSTRING& t_str, const zSTRING& t_value, const int t_idx)
	{
		zSTRING str{ t_str };
		str.Insert(t_idx, t_value);
		return str;
	}

    int Str_Format_Ext()
    {
        const auto parser = zCParser::GetParser();
        static zSTRING format;
        zSTRING parameter_s;
        int parameter_i;
        float parameter_f;

        parser->GetParameter(format);

        for (u_int i = format.Length() - 1; i > 0; i--)
		{
            if (format[i - 1] == '%') {
				switch (format[i])
				{
				case 's':
					parser->GetParameter(parameter_s);
					format.Delete(i - 1, 2);
					format.Insert(i - 1, parameter_s);
					break;
				case 'i':
					parser->GetParameter(parameter_i);
					parameter_s = parameter_i;
					format.Delete(i - 1, 2);
					format.Insert(i - 1, parameter_s);
					break;
				case 'f':
					parser->GetParameter(parameter_f);
					parameter_s = parameter_f;
					format.Delete(i - 1, 2);
					format.Insert(i - 1, parameter_s);
					break;
				case 'b':
					parser->GetParameter(parameter_i);
					parameter_s = parameter_i ? "True" : "False";
					format.Delete(i - 1, 2);
					format.Insert(i - 1, parameter_s);
					break;
				}
            }
        }

        parser->SetReturn(format);
        return 1;
    }
}
