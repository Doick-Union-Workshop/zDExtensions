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

## zDExt_Str_Capital

Returns a string with the first character uppercase and the remaining characters lowercase.

```dae
func string zDExt_Str_Capital(var string str) {};
```

- `str` – string to format
- `return` – formatted string

```dae title="Example usage"
var string str; str = zDExt_Str_Capital("start");
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

Returns a copy of the string with `length` characters removed starting at the zero-based `startIndex`.

```dae
func string zDExt_Str_Cut(var string str, var int startIndex, var int length) {};
```

- `str` – string to cut
- `startIndex` – the starting index
- `length` – number of characters to remove
- `return` – string after removing the specified range

```dae title="Example usage"
var string part;
part = zDExt_Str_Cut("CHEST_BIG", 5, 4); // Returns "CHEST"
```

## zDExt_Str_Length

Returns the length of the string.

```dae
func int zDExt_Str_Length(var string str) {};
```

- `str` – string to measure
- `return` – number of characters in the engine string

```dae title="Example usage"
var int length;
length = zDExt_Str_Length("CHEST_BIG"); // Returns 9
```

## zDExt_Str_Put

Returns a copy of the string with `value` inserted at the zero-based index.

```dae
func string zDExt_Str_Put(var string str, var string value, var int index) {};
```

- `str` – original string
- `value` – text to insert
- `index` – insertion position
- `return` – string containing the inserted text

```dae title="Example usage"
var string result;
result = zDExt_Str_Put("CHEST", "_BIG", 5); // Returns "CHEST_BIG"
```


## zDExt_Str_Format

Formats text using a variable number of arguments. It is available in both the content and menu parsers.

Supported placeholders are `%s` (string), `%i` (integer), `%f` (float), and `%b` (integer rendered as `True` or `False`). Supply the values in placeholder order, followed by the format string as the final argument. The implementation reads the format string first from the script stack and then processes placeholders from right to left.

```dae title="Example usage"
var string result;
result = zDExt_Str_Format("Hero", 10, "%s has %i gold");
// Returns "Hero has 10 gold"
```

Each placeholder requires a value of the corresponding type. Use a nonempty format string with the current implementation.
