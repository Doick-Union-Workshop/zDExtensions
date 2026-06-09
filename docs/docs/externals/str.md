# String functions

## zDExt_Str_Upper

Gets string with uppercase.

```dae
func string zDExt_Str_Upper(var string str) {};
```

- `str` – string to format
- `return` – formatted string

```dae title="Example usage"
var string str; str = zDExt_Str_Upper("Start");
Print(str); // Returns "START"
```

## zDExt_Str_Lower

Gets string with lowercase.

```dae
func string zDExt_Str_Lower(var string str) {};
```

- `str` – string to format
- `return` – formatted string

```dae title="Example usage"
var string str; str = zDExt_Str_Lower("Start");
Print(str); // Returns "start"
```

## zDExt_Str_Capitel

Gets string with capitelcase.

```dae
func string zDExt_Str_Capitel(var string str) {};
```

- `str` – string to format
- `return` – formatted string

```dae title="Example usage"
var string str; str = zDExt_Str_Capitel("start");
Print(str); // Returns "Start"
```

## zDExt_Str_StartsWith

Checks whether a string starts with a given prefix (case-insensitive).

```dae
func int zDExt_Str_StartsWith(var string str, var string prefix) {};
```

- `str` – string to check
- `prefix` – the prefix to compare against
- `return` – `TRUE` if the string starts with the given prefix, otherwise returns `FALSE`

```dae title="Example usage"
if (zDExt_Str_StartsWith("GATE_MAIN", "GATE"))
{
    //...
};
```

## zDExt_Str_EndsWith

Checks whether a string ends with a given suffix (case-insensitive).

```dae
func int zDExt_Str_EndsWith(var string str, var string suffix) {};
```

- `str` – string to check
- `suffix` – the suffix to compare against
- `return` – `TRUE` if the string ends with the given suffix, otherwise returns `FALSE`

```dae title="Example usage"
if (zDExt_Str_EndsWith("CHEST_BIG", "_BIG"))
{
    //...
};
```

## zDExt_Str_Cut

Gets a substring (slice) of a string between two given indices.

```dae
func string zDExt_Str_Cut(var string str, var int startIndex, var int length) {};
```

- `str` – string to cut
- `startIndex` – the starting index
- `length` – number of characters to extract
- `return` – extracted substring. If the input is invalid, returns an empty string

```dae title="Example usage"
var string part;
part = zDExt_Str_Cut("CHEST_BIG", 5, 4); // Returns "CHEST"
```
