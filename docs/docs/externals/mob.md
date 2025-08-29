# MOB – interactive object functions

## Mob_SetFocusName

Sets the focus name of specified oCMOB in the game world.

```dae
func void Mob_SetFocusName(var string mobName, var string focusName) {};
```

- `mobName` – name of the mob (interactive vob) in the game world
- `focusName`

```dae title="Example usage"
Mob_SetFocusName("CHEST_LOBART", "MOBNAME_CHAIR");
```

## Mob_GetFocusName

Gets focus name of specified oCMOB in the game world.

```dae
func string Mob_GetFocusName(var string mobName) {};
```

- `mobName` – name of the mob (interactive vob) in the game world
- `return` – focus name of oCMOB

```dae title="Example usage"
var string focusName;
focusName = Mob_GetFocusName("CHEST_LOBART");

if (Hlp_StrCmp(focusName, MOBNAME_CHEST))
{
    //...
};
```

## Mob_GetScemeName

Gets the sceme name (interaction scheme) of a specified oCMobInter.

```dae
func string Mob_GetScemeName(var string mobName) {};
```

- `mobName` – name of the mob (interactive vob) in the game world
- `return` – sceme name. If the mob is not found or is not an interactive object, it's an empty string

```dae title="Example usage"
var string sceme;
sceme = Mob_GetScemeName("LEVER_GATE_01");
```
