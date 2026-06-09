# HLP – help functions

## zDExt_Hlp_GetItem

Finds an item object by its instance name.

```dae
func C_Item zDExt_Hlp_GetItem(var int itemInstance) {};
```

- `itemInstance` – instance name of the item
- `return` – link to item object

```dae title="Example usage"
var C_Item torch; torch = zDExt_Hlp_GetItem(ItLsTorch);
```

## zDExt_Hlp_IsValidVob

Checks if vob is in the game world.

```dae
func int zDExt_Hlp_IsValidVob(var instance object) {};
```

- `object` – any instance
- `return` – `TRUE` or `FALSE`

## zDExt_Hlp_GetNpcPlunderedByPlayer

Gets the NPC is currently plundered by the player.

```dae
func C_NPC zDExt_Hlp_GetNpcPlunderedByPlayer() {};
```

- `return` – instance of the NPC

## zDExt_Hlp_IsOptionExists

Checks whether an options section or a specific option entry exists in a given options level.

```dae
func int zDExt_Hlp_IsOptionExists(var string level, var string section, var string option) {};
```

- `level` – options level name (e.g. `Gothic` level)
- `section` – section name inside the options file
- `option` – option name; if empty, the function checks for section existence
- `return` – `TRUE` if the section or option exists, `FALSE` otherwise

```dae title="Example usage"
// Check if a section exists
if (zDExt_Hlp_IsOptionExists("Gothic", "ENGINE", ""))
{
    // Section exists
};

// Check if a specific option exists
if (zDExt_Hlp_IsOptionExists("Gothic", "ENGINE", "ZMAXFPS"))
{
    // Option exists
};
```

## zDExt_Hlp_GetOptionIntValue

Reads an integer option value from the specified options level.

```dae
func int zDExt_Hlp_GetOptionIntValue(var string level, var string section, var string option, var int defaultValue) {};
```

- `level` – options level name
- `section` – section name
- `option` – option name
- `defaultValue` – value returned when option is missing
- `return` – integer value of the option

```dae title="Example usage"
var int val; val = zDExt_Hlp_GetOptionIntValue("Gothic", "ENGINE", "ZMAXFPS", 60);
```

## zDExt_Hlp_GetOptionFloatValue

Reads a floating-point option value from the specified options level.

```dae
func float zDExt_Hlp_GetOptionFloatValue(var string level, var string section, var string option, var float defaultValue) {};
```

- `level` – options level name
- `section` – section name
- `option` – option name
- `defaultValue` – value returned when option is missing
- `return` – float value of the option

```dae title="Example usage"
var float val; val = zDExt_Hlp_GetOptionFloatValue("Gothic", "ENGINE", "zWindAngleVelo", 9.0);
```

## zDExt_Hlp_GetOptionStringValue

Reads a string option value from the specified options level.

```dae
func string zDExt_Hlp_GetOptionStringValue(var string level, var string section, var string option, var string defaultValue) {};
```

- `level` – options level name
- `section` – section name
- `option` – option name
- `defaultValue` – value returned when option is missing
- `return` – string value of the option

```dae title="Example usage"
var string str; str = zDExt_Hlp_GetOptionStringValue("Gothic", "ZMULTILOGUE", "LoggerLevelUnion", "INFO");
```

## zDExt_Hlp_SetOptionIntValue

Writes an integer option value to the specified options level.

```dae
func void zDExt_Hlp_SetOptionIntValue(var string level, var string section, var string option, var int value) {};
```

- `level` – options level name
- `section` – section name
- `option` – option name
- `value` – integer value to write

```dae title="Example usage"
Hlp_SetOptionIntValue("Gothic", "ENGINE", "ZMAXFPS", 60);
```

## zDExt_Hlp_SetOptionFloatValue

Writes a floating-point option value to the specified options level.

```dae
func void zDExt_Hlp_SetOptionFloatValue(var string level, var string section, var string option, var float value) {};
```

- `level` – options level name
- `section` – section name
- `option` – option name
- `value` – float value to write

```dae title="Example usage"
zDExt_Hlp_SetOptionFloatValue("Gothic", "ENGINE", "zWindAngleVelo", 9.0);
```

## zDExt_Hlp_SetOptionStringValue

Writes a string option value to the specified options level.

```dae
func void zDExt_Hlp_SetOptionStringValue(var string level, var string section, var string option, var string value) {};
```

- `level` – options level name
- `section` – section name
- `option` – option name
- `value` – string value to write

```dae title="Example usage"
zDExt_Hlp_SetOptionStringValue("Gothic", "ZMULTILOGUE", "LoggerLevelUnion", "WARN");
```

## zDExt_Hlp_IsTestMode

Returns whether the game is currently running in developer/test mode.

```dae
func int zDExt_Hlp_IsTestMode() {};
```

- `return` – `TRUE` if developer/test mode is active, `FALSE` otherwise

```dae title="Example usage"
if (zDExt_Hlp_IsTestMode())
{
    Print("Dev mode active");
};
```
