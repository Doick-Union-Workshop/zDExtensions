# Menu functions

Both functions are available in the content and menu parsers.

## zDExt_Menu_GetItemText

Returns the text at the specified line of a menu item. The line argument is required; pass `0` for the first line.

```dae
func string zDExt_Menu_GetItemText(var string menuItemName, var int line) {};
```

- `menuItemName` – name of the menu item (case-insensitive)
- `line` – index of text lines array
- `return` – text value of menu item

```dae title="Example usage"
var string playerGuild;
playerGuild = zDExt_Menu_GetItemText("MENU_ITEM_PLAYERGUILD", 0);

if (Hlp_StrCmp(playerGuild, "Necromancer"))
{
    //...
};
```

## zDExt_Menu_SetItemText

Sets value of specified menu item.

```dae
func void zDExt_Menu_SetItemText(var string menuItemName, var string value, var int line, var int drawNow) {};
```

- `menuItemName` – name of the menu item (case-insensitive)
- `value` – text value to set
- `line` – index of text lines array
- `drawNow` – `TRUE` to request immediate drawing, `FALSE` otherwise

```dae title="Example usage"
zDExt_Menu_SetItemText("MENU_ITEM_PLAYERGUILD", "Necromancer", 0, TRUE);
```
