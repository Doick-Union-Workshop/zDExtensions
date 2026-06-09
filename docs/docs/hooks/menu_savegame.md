# Save/Load Game Menu

This hook is triggered whenever the player changes the savegame slot in the **Save/Load menu**.  
It allows you to run your own script function at that exact moment.  

When a slot is changed, the hook will try to call a Daedalus function named: `zDExt_Menu_SaveLoadGame_Hook` defined in `Scripts/System` directory.

```dae title="Example usage"
func void zDExt_Menu_SaveLoadGame_Hook()
{
    zDExt_Menu_SetItemText("MENUITEM_LOADSAVE_LEVELNAME_VALUE", "Valley of Mines");
};
```
