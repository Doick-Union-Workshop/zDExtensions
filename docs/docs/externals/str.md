# String functions

## Str_Upper

Returns string with uppercase.

```dae
var string Str_Upper(var string str) {};
```

- `str` - string to format
- `return` - formatted string

```dae title="Example usage"
var string str; str = Str_Upper("Start");
Print(str); // Returns "START"
```

## Str_Lower

Returns string with lowercase.

```dae
var string Str_Lower(var string str) {};
```

- `str` - string to format
- `return` - formatted string

```dae title="Example usage"
var string str; str = Str_Lower("Start");
Print(str); // Returns "start"
```

## Str_Capitel

Returns string with capitelcase.

```dae
var string Str_Capitel(var string str) {};
```

- `str` - string to format
- `return` - formatted string

```dae title="Example usage"
var string str; str = Str_Capitel("start");
Print(str); // Returns "Start"
```

## Str_StartsWith

Checks whether a string starts with a given prefix (case-insensitive).

```dae
func int Str_StartsWith(var string str, var string prefix) {};
```

- `str` - string to check
- `prefix` - the prefix to compare against
- `return` - `TRUE` if the string starts with the given prefix, otherwise returns `FALSE`

```dae title="Example usage"
if (Str_StartsWith("GATE_MAIN", "GATE"))
{
    //...
};
```

## Str_EndsWith

Checks whether a string ends with a given suffix (case-insensitive).

```dae
func int Str_EndsWith(var string str, var string suffix) {};
```

- `str` - string to check
- `suffix` – the suffix to compare against
- `return` - `TRUE` if the string ends with the given suffix, otherwise returns `FALSE`

```dae title="Example usage"
if (Str_EndsWith("CHEST_BIG", "_BIG"))
{
    //...
};
```

## Str_Cut

Gets a substring (slice) of a string between two given indices.

```dae
func string Str_Cut(var string str, var int startIndex, var int length) {};
```

- `str` – string to cut
- `startIndex` – the starting index
- `length` – number of characters to extract
- `return` - extracted substring. If the input is invalid, returns an empty string

```dae title="Example usage"
var string part;
part = Str_Cut("CHEST_BIG", 5, 4); // Returns "CHEST"
```
