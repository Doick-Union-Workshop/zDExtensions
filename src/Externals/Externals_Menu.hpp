namespace GOTHIC_NAMESPACE
{
    void Menu_SetItemText(const zSTRING& t_name, const zSTRING& t_text, const int t_line, const int t_drawNow)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Menu_SetItemText");

        zSTRING name{ t_name };
        name.Upper();

        zCMenuItem* menuItem = FindMenuItemByName(name, logger);
        if (!menuItem)
        {
            return;
        }

        menuItem->SetText(t_text, t_line, t_drawNow);
        MenuItem_Release(menuItem);
    }

    zSTRING Menu_GetItemText(const zSTRING& t_name, const int t_line)
    {
        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Menu_GetItemText");

        zSTRING name{ t_name };
        name.Upper();

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

    // For menu parser
    int Menu_SetItemText_Old()
    {
        auto const par = zCParser::GetParser();

        zSTRING menuItemName, menuItemText;
		int line, drawNow;

        par->GetParameter(drawNow);
        par->GetParameter(line);
        par->GetParameter(menuItemText);
        par->GetParameter(menuItemName);

        menuItemName.Upper();

        static auto logger = Utils::CreateLogger("zDExt::Externals::Menu_SetItemText_Old");
        auto menuItem = FindMenuItemByName(menuItemName, logger);
        if (!menuItem)
        {
            return 0;
        }

        menuItem->SetText(menuItemText, line, drawNow);
        MenuItem_Release(menuItem);
        return 0;
    }

    int Menu_GetItemText_Old()
    {
        static zSTRING result = "";
        auto const par = zCParser::GetParser();

        zSTRING menuItemName;
        int line;

        par->GetParameter(line);
        par->GetParameter(menuItemName);

        menuItemName.Upper();

        static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::Menu_GetItemText_Old");
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
