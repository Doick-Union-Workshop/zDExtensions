#include <Windows.h>

namespace GOTHIC_NAMESPACE
{
    oCItem* Hlp_GetItem(const int t_instance)
    {
        oCItem* item = nullptr;
        zCPar_Symbol* sym = parser->GetSymbol(t_instance);
        if (!sym)
        {
            return item;
        }

        if (sym->type == zPAR_TYPE_INSTANCE)
        {
            item = dynamic_cast<oCItem*>((zCVob*)sym->GetInstanceAdr());
        }

        if (!item)
        {
            item = dynamic_cast<oCItem*>(ogame->GetGameWorld()->SearchVobByName(sym->name));
        }

        return item;
    }

    int Hlp_IsValidVob(zCVob* t_vob)
    {
        return static_cast<int>(t_vob != nullptr);
    }

    oCNpc* Hlp_GetNpcPlunderedByPlayer()
    {
        if (oCNpc::game_mode == NPC_GAME_PLUNDER)
        {
            return stealnpc;
        }
        return nullptr;
    }

    // For menu parser

    /*
    static int Hlp_StrCmp(const zSTRING& t_str1, const zSTRING& t_str2)
    {
        return static_cast<int>(Str_Upper(t_str1) == Str_Upper(t_str2));
    }
    */

    int Hlp_StrCmp()
    {
        zSTRING s1, s2;
        const auto par = zCParser::GetParser();

        par->GetParameter(s2);
        par->GetParameter(s1);

        int result = Str_Upper(s1) == Str_Upper(s2);
        par->SetReturn(result);
        return 0;
    }

    int Hlp_IsOptionExists(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option)
    {
        auto options = GetOptionsLevel(t_level);
        return options->EntryExists(t_section, t_option);
    }

    int Hlp_GetOptionIntValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const int t_defaultValue)
    {
        return GetOptionsLevel(t_level)->ReadInt(t_section, t_option, t_defaultValue);
    }

    float Hlp_GetOptionFloatValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const float t_defaultValue)
    {
        return GetOptionsLevel(t_level)->ReadReal(t_section, t_option, t_defaultValue);
    }

    zSTRING Hlp_GetOptionStringValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const zSTRING& t_defaultValue)
    {
        return GetOptionsLevel(t_level)->ReadString(t_section, t_option, t_defaultValue);
    }

    void Hlp_SetOptionIntValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const int t_defaultValue)
    {
        GetOptionsLevel(t_level)->WriteInt(t_section, t_option, t_defaultValue, 0);
    }

    void Hlp_SetOptionFloatValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const float t_defaultValue)
    {
        GetOptionsLevel(t_level)->WriteReal(t_section, t_option, t_defaultValue, 0);
    }

    void Hlp_SetOptionStringValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const zSTRING& t_defaultValue)
    {
        GetOptionsLevel(t_level)->WriteString(t_section, t_option, t_defaultValue, 0);
    }

    int Hlp_IsDevModeActive()
    {
        return ogame->game_testmode != 0;
    }
}
