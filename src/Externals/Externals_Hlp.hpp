#include <Windows.h>

namespace GOTHIC_NAMESPACE
{
    oCItem* zDExt_Hlp_GetItem(const int t_instance)
    {
        oCItem* item = nullptr; 
        zCPar_Symbol* sym = parser->GetSymbol(t_instance);

        if (sym)
        {
            if (sym->type == zPAR_TYPE_INSTANCE)
            {
                item = dynamic_cast<oCItem*>((zCVob*)sym->GetInstanceAdr());
            }

            if (!item)
            {
                item = zDYNAMIC_CAST<oCItem>(ogame->GetGameWorld()->SearchVobByName(sym->name));
            }
        }

        return item;
    }

    int zDExt_Hlp_IsValidVob(const zSTRING& t_vobName)
    {
        zCVob* vob = FindVobByName(t_vobName);
        return static_cast<int>(vob != nullptr);
    }

    oCNpc* zDExt_Hlp_GetNpcPlunderedByPlayer()
    {
        if (oCNpc::game_mode == NPC_GAME_PLUNDER)
        {
            return stealnpc;
        }

        return nullptr;
    }

    /*int zDExt_Hlp_StrCmp(const zSTRING& t_str1, const zSTRING& t_str2)
    {
        zSTRING str1{ t_str1 };
        str1.Upper();
        zSTRING str2{ t_str2 };
        str2.Upper();
        return static_cast<int>(str1 == str2);
    }*/
    

    int zDExt_Hlp_StrCmp()
    {
        zSTRING s1, s2;
        const auto par = zCParser::GetParser();

        par->GetParameter(s2);
        par->GetParameter(s1);

        (void)s1.Upper();
        (void)s2.Upper();

        int result = s1 == s2;
        par->SetReturn(result);
        return 0;
    }

    int zDExt_Hlp_IsOptionExists(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option)
    {
        auto options = GetOptionsLevel(t_level);
        return options->EntryExists(t_section, t_option);
    }

    int zDExt_Hlp_GetOptionIntValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const int t_defaultValue)
    {
        return GetOptionsLevel(t_level)->ReadInt(t_section, t_option, t_defaultValue);
    }

    float zDExt_Hlp_GetOptionFloatValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const float t_defaultValue)
    {
        return GetOptionsLevel(t_level)->ReadReal(t_section, t_option, t_defaultValue);
    }

    zSTRING zDExt_Hlp_GetOptionStringValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const zSTRING& t_defaultValue)
    {
        return GetOptionsLevel(t_level)->ReadString(t_section, t_option, t_defaultValue);
    }

    void zDExt_Hlp_SetOptionIntValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const int t_defaultValue)
    {
        GetOptionsLevel(t_level)->WriteInt(t_section, t_option, t_defaultValue, 0);
    }

    void zDExt_Hlp_SetOptionFloatValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const float t_defaultValue)
    {
        GetOptionsLevel(t_level)->WriteReal(t_section, t_option, t_defaultValue, 0);
    }

    void zDExt_Hlp_SetOptionStringValue(const zSTRING& t_level, const zSTRING& t_section, const zSTRING& t_option, const zSTRING& t_defaultValue)
    {
        GetOptionsLevel(t_level)->WriteString(t_section, t_option, t_defaultValue, 0);
    }

    int zDExt_Hlp_IsTestMode()
    {
        return ogame->game_testmode != 0;
    }
}
