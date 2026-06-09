# WLD – world manipulation functions

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

Inserts a static interactive object (mob) into the world at a given location.

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
func void zDExt_Wld_InsertVobPos(var string vobName, var int posX, var int posY, var int posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertVobPos("SECRET_CHEST", 0, 0, 0);
```

## zDExt_Wld_InsertMobPos

Inserts a mob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertMobPos(var string vobName, var int posX, var int posY, var int posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobPos("SIGNPOST", 23120, 1400, 16795);
```

## zDExt_Wld_InsertMobInterPos

Inserts an interactive mob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertMobInterPos(var string vobName, var int posX, var int posY, var int posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobInterPos("EDDA_CAULDRON", 16795, 1400, 23120);
```

## zDExt_Wld_InsertMobContainerPos

Inserts a container mob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertMobContainerPos(var string vobName, var int posX, var int posY, var int posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobContainerPos("CAVALORN_CHEST", 16795, 23120, 1400);
```

## zDExt_Wld_InsertMobFirePos

Inserts a fire mob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertMobFirePos(var string vobName, var int posX, var int posY, var int posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobFirePos("CAVALORN_CAMPFIRE", 16795, 23120, 1400);
```

## zDExt_Wld_InsertMobDoorPos

Inserts a door mob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertMobDoorPos(var string vobName, var int posX, var int posY, var int posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobDoorPos("BOSPER_HOUSE_DOOR", 1400, 16795, 23120);
```

## zDExt_Wld_InsertMobBedPos

Inserts a bed mob into the world at exact coordinates.

```dae
func void zDExt_Wld_InsertMobBedPos(var string vobName, var int posX, var int posY, var int posZ) {};
```

- `vobName` – name of vob in the game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
zDExt_Wld_InsertMobBedPos("BOSPER_BED", 1400, 16795, 23120);
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

- `return` - name of player's portal room

```dae title="Example usage"
var string playerPortalRoom;
playerPortalRoom = zDExt_Wld_GetPlayerPortalRoom();

if (Hlp_StrCmp(playerPortalRoom, "hütte2"))
{
    //...
};
```

!!! note
    You can also use [zDExt_Npc_GetPortalRoom](http://localhost:8000/Doick-Union-Workshop/zDExtensions/externals/npc/#zdext_npc_getportalroom) instead.
