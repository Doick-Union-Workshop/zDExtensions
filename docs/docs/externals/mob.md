# MOB – interactive object functions

## zDExt_Mob_SetFocusName

Sets the focus name of specified oCMOB in the game world.

```dae
func void zDExt_Mob_SetFocusName(var string mobName, var string focusName) {};
```

- `mobName` – name of the mob (interactive vob) in the game world
- `focusName` – focus name identifier, converted to uppercase before being set

```dae title="Example usage"
zDExt_Mob_SetFocusName("CHEST_LOBART", "MOBNAME_CHAIR");
```

## zDExt_Mob_GetFocusName

Gets focus name of specified oCMOB in the game world.

```dae
func string zDExt_Mob_GetFocusName(var string mobName) {};
```

- `mobName` – name of the mob (interactive vob) in the game world
- `return` – focus name of oCMOB

```dae title="Example usage"
var string focusName;
focusName = zDExt_Mob_GetFocusName("CHEST_LOBART");

if (Hlp_StrCmp(focusName, MOBNAME_CHEST))
{
    //...
};
```

## zDExt_Mob_GetScemeName

Gets the scheme name of an `oCMOB` or a derived class. The external name retains the engine spelling `Sceme`.

```dae
func string zDExt_Mob_GetScemeName(var string mobName) {};
```

- `mobName` – name of the mob (interactive vob) in the game world
- `return` – sceme name. If the mob is not found or is not an interactive object, it's an empty string

```dae title="Example usage"
var string sceme;
sceme = zDExt_Mob_GetScemeName("LEVER_GATE_01");
```

## zDExt_Mob_SetUseWithItem

Sets the item instance required to use an interactive mob (`oCMobInter` or a derived class). If the vob is missing or is not an interactive mob, no change is made.

```dae
func void zDExt_Mob_SetUseWithItem(var string mobName, var string itemInstance) {};
```

- `mobName` – name of the interactive mob in the world
- `itemInstance` – item instance name as a string; converted to uppercase

```dae title="Example usage"
zDExt_Mob_SetUseWithItem("LEVER_GATE_01", "ITMI_KEY_GATE");
```
