# Utility functions

## zDExt_GetIntArrayValue

Returns value of index in the array of integers.

```dae
func int zDExt_GetIntArrayValue(var string arr, var int index) {};
```

- `arr` – array of integers
- `index` – position of an element in an array
- `return` – value of index

```dae title="Example usage"
var int i; i = zDExt_GetIntArrayValue(self.hitChance, NPC_TALENT_1H);
```

## zDExt_GetStringArrayValue

Returns value of index in the array of strings.

```dae
func string zDExt_GetStringArrayValue(var string arr, var int index) {};
```

- `arr` – array of strings
- `index` – position of an element in an array
- `return` – value of index

```dae title="Example usage"
var string str; str = zDExt_GetStringArrayValue(TXT_GUILDS, GIL_VLK);
```

## zDExt_SetIntArrayValue

```dae
func void zDExt_SetIntArrayValue(var int arr, var int index, var int value) {};
```

- `arr` – array of integers
- `index` – position of an element in an array
- `value` – integer value to set

```dae title="Example usage"
zDExt_SetIntArrayValue(self.hitChance, NPC_TALENT_1H, 25);
```

## zDExt_SetStringArrayValue

```dae
func void zDExt_SetStringArrayValue(var string arr, var int index, var string value) {};
```

- `arr` – array of strings
- `index` – position of an element in an array
- `value` – string value to set

```dae title="Example usage"
var string arr[2];
arr[0] = "Test";
arr[1] = "Test2";
zDExt_SetStringArrayValue(arr, 1, "Test3");
```
