# WLD – world manipulation functions

The insert functions create new objects of the named engine class. They do not clone existing objects or configure a visual, inventory, or interaction state. `vobName` becomes the new object name (converted to uppercase). Set a visual separately with `zDExt_Vob_SetVisual`. The point-based variants do nothing when the target point is missing.

## zDExt_Wld_InsertVob

Inserts a vob into the world at the position of a given waypoint, freepoint, or another vob.

```dae
func void zDExt_Wld_InsertVob(var string vobName, var string pointName) {};
```

- `vobName` – name of vob in the game world
- `pointName` – name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
zDExt_Wld_InsertVob("SECRET_CHEST", "WP_START");
```

## zDExt_Wld_InsertMob

Inserts an `oCMOB` object into the world at a given location.

```dae
func void zDExt_Wld_InsertMob(var string vobName, var string pointName) {};
```

- `vobName` – name of vob in the game world
- `pointName` – name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
zDExt_Wld_InsertMob("SIGNPOST", "WP_START");
```

## zDExt_Wld_InsertMobInter

Inserts an interactive mob (e.g., cauldron, forge) into the world at a given location.

```dae
func void zDExt_Wld_InsertMobInter(var string vobName, var string pointName) {};
```

- `vobName` – name of vob in the game world
- `pointName` – name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobInter("EDDA_CAULDRON", "WP_START");
```

## zDExt_Wld_InsertMobContainer

Inserts a container mob (e.g., chest) into the world at a given location.

```dae
func void zDExt_Wld_InsertMobContainer(var string vobName, var string pointName) {};
```

- `vobName` – name of vob in the game world
- `pointName` – name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobContainer("CAVALORN_CHEST", "WP_START");
```

## zDExt_Wld_InsertMobFire

Inserts a fire mob (e.g., campfire, torch) into the world at a given location.

```dae
func void zDExt_Wld_InsertMobFire(var string vobName, var string pointName) {};
```

- `vobName` – name of vob in the game world
- `pointName` – name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobFire("CAVALORN_CAMPFIRE", "WP_START");
```

## zDExt_Wld_InsertMobDoor

Inserts a door mob into the world at a given location.

```dae
func void zDExt_Wld_InsertMobDoor(var string vobName, var string pointName) {};
```

- `vobName` – name of vob in the game world
- `pointName` – name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobDoor("BOSPER_HOUSE_DOOR", "NW_CITY_BOSPER_HOUSE_ENTRANCE");
```

## zDExt_Wld_InsertMobBed

Inserts a bed mob into the world at a given location.

```dae
func void zDExt_Wld_InsertMobBed(var string vobName, var string pointName) {};
```

- `vobName` – name of vob in the game world
- `pointName` – name of waypoint, freepoint or vob in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobBed("BOSPER_BED", "NW_CITY_BOSPER_HOUSE_BED");
```

## zDExt_Wld_InsertVobPos

Inserts a vob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertVobPos(var string vobName, var float posX, var float posY, var float posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertVobPos("SECRET_CHEST", 0.0, 0.0, 0.0);
```

## zDExt_Wld_InsertMobPos

Inserts a mob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertMobPos(var string vobName, var float posX, var float posY, var float posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobPos("SIGNPOST", 23120.0, 1400.0, 16795.0);
```

## zDExt_Wld_InsertMobInterPos

Inserts an interactive mob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertMobInterPos(var string vobName, var float posX, var float posY, var float posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobInterPos("EDDA_CAULDRON", 16795.0, 1400.0, 23120.0);
```

## zDExt_Wld_InsertMobContainerPos

Inserts a container mob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertMobContainerPos(var string vobName, var float posX, var float posY, var float posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobContainerPos("CAVALORN_CHEST", 16795.0, 23120.0, 1400.0);
```

## zDExt_Wld_InsertMobFirePos

Inserts a fire mob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertMobFirePos(var string vobName, var float posX, var float posY, var float posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobFirePos("CAVALORN_CAMPFIRE", 16795.0, 23120.0, 1400.0);
```

## zDExt_Wld_InsertMobDoorPos

Inserts a door mob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertMobDoorPos(var string vobName, var float posX, var float posY, var float posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobDoorPos("BOSPER_HOUSE_DOOR", 1400.0, 16795.0, 23120.0);
```

## zDExt_Wld_InsertMobBedPos

Inserts a bed mob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertMobBedPos(var string vobName, var float posX, var float posY, var float posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobBedPos("BOSPER_BED", 1400.0, 16795.0, 23120.0);
```

## zDExt_Wld_RemoveVob

Removes a specified vob from the game world.

```dae
func int zDExt_Wld_RemoveVob(var string vobName) {};
```

- `vobName` – name of vob in the game world
- `return` – `TRUE` if the vob has been correctly removed, `FALSE` otherwise

```dae
if (zDExt_Wld_RemoveVob("CHEST_LOBART"))
{
    Print("Vob successfully removed");
};
```

## zDExt_Wld_GetPlayerPortalRoom

Gets name of portal room where the player currently is.

```dae
func string zDExt_Wld_GetPlayerPortalRoom() {};
```

- `return` – name of the player's portal room, or an empty string when no portal is active

```dae title="Example usage"
var string playerPortalRoom;
playerPortalRoom = zDExt_Wld_GetPlayerPortalRoom();

if (Hlp_StrCmp(playerPortalRoom, "hütte2"))
{
    //...
};
```

!!! note
    You can also use [zDExt_Npc_GetPortalRoom](npc.md#zdext_npc_getportalroom) instead.

## zDExt_Wld_GetWorldName

Returns the current game world name.

```dae
func string zDExt_Wld_GetWorldName() {};
```

- `return` – world name returned by the engine

```dae title="Example usage"
var string worldName;
worldName = zDExt_Wld_GetWorldName();
```

## zDExt_Wld_SetRainTime

Sets the rain interval on the active outdoor sky controller only if the current game time is within the requested interval. Intervals crossing noon are rejected.

```dae
func int zDExt_Wld_SetRainTime(var int startHour, var int startMin, var int endHour, var int endMin) {};
```

- `startHour`, `endHour` – hours in the range 0–23
- `startMin`, `endMin` – minutes in the range 0–59
- `return` – `TRUE` if the interval was set; `FALSE` outside the interval, for an unsupported interval, or without an outdoor sky controller

```dae title="Example usage"
if (zDExt_Wld_SetRainTime(18, 0, 23, 0))
{
    Print("Rain interval set");
};
```

## zDExt_Wld_SetRainOn

Sets the rain interval to cover the full day. Does nothing without an outdoor sky controller.

```dae
func void zDExt_Wld_SetRainOn() {};
```

```dae title="Example usage"
zDExt_Wld_SetRainOn();
```

## zDExt_Wld_SetRainOff

Clears the rain interval and mutes rain sound. Does nothing without an outdoor sky controller.

```dae
func void zDExt_Wld_SetRainOff() {};
```

```dae title="Example usage"
zDExt_Wld_SetRainOff();
```

## zDExt_Wld_OverrideWorldFogColors

Adds a color to the outdoor sky controller's daytime fog color variations. This function is a work in progress: `index` is currently ignored and existing colors are not replaced.

```dae
func void zDExt_Wld_OverrideWorldFogColors(var int index, var string color) {};
```

- `index` – currently unused
- `color` – three space-separated color components, parsed as floats

```dae title="Example usage"
zDExt_Wld_OverrideWorldFogColors(0, "100 120 140");
```

## zDExt_Wld_ChangeLevel

Requests a level change and specifies the destination waypoint. Does nothing when the destination is the current world.

```dae
func void zDExt_Wld_ChangeLevel(var string worldName, var string waypoint) {};
```

- `worldName` – destination filename; use an uppercase `.ZEN` extension or omit the extension
- `waypoint` – destination waypoint name

```dae title="Example usage"
zDExt_Wld_ChangeLevel("NEWWORLD.ZEN", "START");
```

!!! note "Weather type functions"
    `zDExt_Wld_SetWeatherType` and `zDExt_Wld_GetWeatherType` have C++ implementations but are not registered as externals in the current build. They cannot currently be called from Daedalus.
