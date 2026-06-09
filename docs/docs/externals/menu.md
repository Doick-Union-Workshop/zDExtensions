# Menu functions

## zDExt_Menu_GetItemText

Returns value of text on first line (`0` by default) of specified menu item.

```dae
func string zDExt_Menu_GetItemText(var string menuItemName, var int line) {};
```

- `menuItemName`
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

- `menuItemName`
- `value` – text value to set
- `line` – index of text lines array
- `drawNow`

```dae title="Example usage"
zDExt_Menu_SetItemText("MENU_ITEM_PLAYERGUILD", "Necromancer", 0, TRUE);
```
