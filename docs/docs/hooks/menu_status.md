# Status Menu

This hook is triggered whenever the **Status Menu** (the character screen with stats) is opened and initialized for display.  
It allows you to run your own script function right after the status menu is set up.

When the status menu is displayed, the hook will try to call a Daedalus function named: `zDExt_Menu_Status_Hook` defined in `Scripts/Content` directory.

```dae title="Example usage"
func void zDExt_Menu_Status_Hook()
{
    zDExt_Menu_SetItemText("MENU_ITEM_PLAYERGUILD", "Necromancer");
};
```
