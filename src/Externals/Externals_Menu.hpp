namespace GOTHIC_NAMESPACE
{
    void zDExt_Menu_SetItemText(const zSTRING& t_name, const zSTRING& t_text, const int t_line, const int t_drawNow)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Menu_SetItemText");

        zSTRING name{ t_name };
        (void)name.Upper();

        zCMenuItem* menuItem = FindMenuItemByName(name, logger);
        if (!menuItem)
        {
            return;
        }

        menuItem->SetText(t_text, t_line, t_drawNow);
        MenuItem_Release(menuItem);
    }

    zSTRING zDExt_Menu_GetItemText(const zSTRING& t_name, const int t_line)
    {
        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Menu_GetItemText");

        zSTRING name{ t_name };
        (void)name.Upper();

        zCMenuItem* menuItem = FindMenuItemByName(name, logger);
        if (!menuItem)
        {
            return {};
        }

        zSTRING result = menuItem->GetText(t_line);
        if (result.IsEmpty())
        {
            logger->Info("Menu item {0} has no value at {1} text line.", name.ToChar(), t_line);
        }

        MenuItem_Release(menuItem);
        return result;
    }

    // MENU PARSER
    int zDExt_Menu_SetItemText_MP()
    {
        auto const par = zCParser::GetParser();

        zSTRING menuItemName, menuItemText;
		int line, drawNow;

        par->GetParameter(drawNow);
        par->GetParameter(line);
        par->GetParameter(menuItemText);
        par->GetParameter(menuItemName);

        (void)menuItemName.Upper();

        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Menu_SetItemText_MP");
        auto menuItem = FindMenuItemByName(menuItemName, logger);
        if (!menuItem)
        {
            return 0;
        }

        menuItem->SetText(menuItemText, line, drawNow);
        MenuItem_Release(menuItem);
        return 0;
    }

    int zDExt_Menu_GetItemText_MP()
    {
        static zSTRING result = "";
        auto const par = zCParser::GetParser();

        zSTRING menuItemName;
        int line;

        par->GetParameter(line);
        par->GetParameter(menuItemName);

        (void)menuItemName.Upper();

        static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::Menu_GetItemText_MP");
        zCMenuItem* menuItem = FindMenuItemByName(menuItemName, logger);
        if (!menuItem)
        {
            par->SetReturn(result);
            return 0;
        }

        result = menuItem->GetText(line);
        if (result.IsEmpty())
        {
            logger->Info("Menu item {0} has no value at {1} text line.", menuItemName.ToChar(), line);
        }

        MenuItem_Release(menuItem);
        par->SetReturn(result);
        return 0;
    }
}
