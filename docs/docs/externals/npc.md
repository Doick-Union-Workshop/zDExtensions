# NPC - character functions

## Npc_GetRoutineFuncName

Gets the function name of the NPC's current routine (e.g. `RTN_PRESTART_100`).

```dae
func string Npc_GetRoutineFuncName(var C_NPC npc) {};
```

- `npc` – instance of the NPC
- `return` - function name of the NPC's current routine

```dae title="Example usage"
if (Hlp_StrCmp(Npc_GetRoutineFuncName(self), "RTN_PreStart_100"))
{
    //...
};
```

## Npc_GetRoutineName

Gets the name of the NPC's current routine (e.g. `PRESTART`).

```dae
func string Npc_GetRoutineName(var C_NPC npc) {};
```

- `npc` – instance of the NPC
- `return` - name of the NPC's current routine

```dae title="Example usage"
if (Hlp_StrCmp(Npc_GetRoutineName(self), "PreStart"))
{
    //...
};
```

## Npc_EquipItem

Equips or unequips the specified item on the NPC.

```dae
func void Npc_EquipItem(var C_NPC npc, var int itemInstance) {};
```

- `npc` – instance of the NPC
- `itemInstance` - instance name of the item

```dae title="Example usage"
Npc_EquipItem(self, ItLsTorch);
```

## Npc_GetWalkMode

Gets the current walk mode of the NPC.

```dae
func int Npc_GetWalkMode(var C_NPC npc) {};
```

- `npc` – instance of the NPC
- `return` - integer value of walk mode

```dae title="Example usage"
if (Npc_GetWalkMode(self) == NPC_SNEAK)
{
    //...
};
```

## Npc_IsStanding

Checks if the NPC is currently standing still.

```dae
func int Npc_IsStanding(var C_NPC npc) {};
```

- `npc` – instance of the NPC
- `return` - `TRUE` if NPC is standing, `FALSE` otherwise

```dae title="Example usage"
if (Npc_IsStanding(self))
{
    //...
};
```

## Npc_IsWalking

Checks if the NPC is currently walking.

```dae
func int Npc_IsWalking(var C_NPC npc) {};
```

- `npc` – instance of the NPC
- `return` - `TRUE` if NPC is walking, `FALSE` otherwise

```dae title="Example usage"
if (Npc_IsWalking(self))
{
    //...
};
```

## Npc_HasOverlay

Checks if the NPC has the specified animation overlay active.

```dae
func int Npc_HasOverlay(var C_NPC npc, var string overlay) {};
```

- `npc` – instance of the NPC
- `return` - `TRUE` if NPC has overlay with specified name, `FALSE` otherwise

```dae title="Example usage"
if (Npc_HasOverlay(self, "Humans_Tired.mds"))
{
    //...
};
```

## Npc_HasTimedOverlay

Checks if the NPC has the specified timed animation overlay active.

```dae
func int Npc_HasTimedOverlay(var C_NPC npc, var string overlay) {};
```

- `npc` – instance of the NPC
- `return` - `TRUE` if NPC has overlay with specified name, `FALSE` otherwise

```dae title="Example usage"
if (Npc_HasTimedOverlay(self, "Humans_Sprint.mds"))
{
    //...
};
```

## Npc_OpenDeadNpcInventory

Opens NPC's plunder inventory.

```dae
func void Npc_OpenDeadNpcInventory(var C_NPC npc) {};
```

- `npc` – instance of the NPC

```dae title="Example usage"
Npc_OpenDeadNpcInventory(self);
```

## Npc_CloseInventory

Closes NPC's main inventory.

```dae
func void Npc_CloseInventory(var C_NPC npc) {};
```

- `npc` – instance of the NPC

```dae title="Example usage"
Npc_CloseInventory(self);
```

## Npc_CloseInventorySteal

Closes the steal inventory of `npc`'s focus NPC.

```dae
func void Npc_CloseInventorySteal(var C_NPC npc) {};
```

- `npc` – instance of the NPC

```dae title="Example usage"
Npc_CloseInventorySteal(self);
```

## Npc_CloseDeadNpcInventory

Closes NPC's plunder inventory.

```dae
func void Npc_CloseDeadNpcInventory(var C_NPC npc) {};
```

- `npc` – instance of the NPC

```dae title="Example usage"
Npc_CloseDeadNpcInventory(self);
```

## Npc_GetDistToPos

Gets the distance between the NPC and a given position in the world (in cm).

```dae
func int Vob_GetDistToPos(var string vobName, var C_Position position) {};
```

- `npc` – instance of the NPC
- `position` – coordinates (X, Y, Z) in the game world
- `return` - distance between NPC and position in cm

```dae title="Example usage"
var C_Position pos; pos = Wld_GetPos(16795, 23120, 1400);

if (Npc_GetDistToPos(hero, pos) <= 500)
{
    //...
};
```

## Npc_GetDistToVob

Gets the distance between the NPC and an vob (in cm).

```dae
func int Npc_GetDistToVob(var C_NPC npc, var string vobName) {};
```

- `npc` – instance of the NPC
- `vobName` – name of vob in game world
- `return` - distance between NPC and vob in cm

```dae title="Example usage"
if (Npc_GetDistToVob(hero, "CHEST_LOBART") <= 500)
{
    //...
};
```

## Npc_GetVisualBody

Gets the name of the NPC's visual body.

```dae
func string Npc_GetVisualBody(var C_NPC npc) {};
```

- `npc` – instance of the NPC
- `return` - name of the portal room

```dae title="Example usage"
var string body; body = Npc_GetVisualBody(hero);

if (Hlp_StrCmp(body, "HUM_BODY_NAKED0"))
{
    //...
};
```

## Npc_GetVisualHead

Gets the name of the NPC's visual head.

```dae
func string Npc_GetVisualHead(var C_NPC npc) {};
```

- `npc` – instance of the NPC
- `return` - name of the portal room

```dae title="Example usage"
var string head; head = Npc_GetVisualHead(hero);

if (Hlp_StrCmp(head, "HUM_HEAD_PONY"))
{
    //...
};
```

## Npc_GetPortalRoom

Gets the name of the portal room in which the NPC is currently located.

```dae
func string Npc_GetPortalRoom(var C_NPC npc) {};
```

- `npc` – instance of the NPC
- `return` - name of the portal room

```dae title="Example usage"
var string room; room = Npc_GetPortalRoom(hero);

if (Hlp_StrCmp(room, ""))
{
    //...
};
```
