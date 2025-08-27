namespace GOTHIC_NAMESPACE
{
    static void Menu_SetItemText(const zSTRING& t_name, const zSTRING& t_text, const int t_line, const int t_drawNow)
    {
        if (t_name.IsEmpty()) return;

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Menu_SetItemText");

        zSTRING name = zSTRING(t_name).Upper();
        zCMenuItem* menuItem = FindMenuItemByName(name, log);

        if (!menuItem) return;

        menuItem->SetText(t_text, t_line, t_drawNow);
#if ENGINE > Engine_G2
        menuItem->Release();
#else
        delete menuItem;
#endif
    }

    static zSTRING Menu_GetItemText(const zSTRING& t_name, const int t_line)
    {
        if (t_name.IsEmpty()) return zSTRING{};

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Menu_GetItemText");

        zSTRING name = zSTRING(t_name).Upper();
        zCMenuItem* menuItem = FindMenuItemByName(name, log);

        if (!menuItem) return zSTRING{};

        zSTRING result = menuItem->GetText(t_line);

        if (result.IsEmpty())
        {
            log->Warning("Menu item '{0}' has no value at {1} text line.", name.ToChar(), t_line);
        }

#if ENGINE > Engine_G2
        menuItem->Release();
#else
        delete menuItem;
#endif
        return result;
    }

    // For menu parser
    static int Menu_SetItemText_Old()
    {
        auto const par = zCParser::GetParser();

        zSTRING menuItemName, menuItemText;
		int line, drawNow;

        par->GetParameter(drawNow);
        par->GetParameter(line);
        par->GetParameter(menuItemText);
        par->GetParameter(menuItemName);

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Menu_SetItemText_Old");

        menuItemName.Upper();
        zCMenuItem* menuItem = FindMenuItemByName(menuItemName, log);

        if (!menuItem) return 0;

        menuItem->SetText(menuItemText, line, drawNow);
#if ENGINE >= Engine_G2
        menuItem->Release();
#else
        delete menuItem;
#endif
        return 0;
    }

    static int Menu_GetItemText_Old()
    {
        static zSTRING result = "";
        auto const par = zCParser::GetParser();

        zSTRING menuItemName;
        int line;

        par->GetParameter(line);
        par->GetParameter(menuItemName);

        static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::Menu_GetItemText_Old");

        menuItemName.Upper();
        zCMenuItem* menuItem = FindMenuItemByName(menuItemName, log);

        if (!menuItem)
        {
            par->SetReturn((zSTRING&)result);
            return 0;
        }

        result = (zSTRING&)menuItem->GetText(line);

        if (result.IsEmpty())
            log->Warning("Menu item '{0}' has no value at {1} text line.", menuItemName.ToChar(), line);

#if ENGINE >= Engine_G2
        menuItem->Release();
#else
        delete menuItem;
#endif
        par->SetReturn(result);
        return 0;
    }
}