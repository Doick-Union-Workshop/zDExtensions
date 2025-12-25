# VOB – functions for object manipulation

## Vob_RotateLocal

Rotates a specified vob by given angles in local scope.

```dae
func void Vob_RotateLocal(var string vobName, var int rotX, var int rotY, var int rotZ) {};
```

- `vobName` – name of vob in the game world
- `rotX` – rotation angle around X axis (degrees)
- `rotY` – rotation angle around Y axis (degrees)
- `rotZ` – rotation angle around Z axis (degrees)

```dae title="Example usage"
Vob_RotateLocal("CHEST_LOBART", 0, 180, 90);
```

## Vob_RotateWorld

Rotates a specified vob by given angles in global scope.

```dae
func void Vob_RotateWorld(var string vobName, var int rotX, var int rotY, var int rotZ) {};
```

- `vobName` – name of vob in the game world
- `rotX` – rotation angle around X axis (degrees)
- `rotY` – rotation angle around Y axis (degrees)
- `rotZ` – rotation angle around Z axis (degrees)

```dae title="Example usage"
Vob_RotateWorld("CHEST_LOBART", 0, 180, 90);
```

## Vob_MoveTo

Moves a specified vob to the position of a given waypoint, freepoint, or another vob.

```dae
func void Vob_MoveTo(var string vobName, var string pointName) {};
```

- `vobName` – name of vob in game world
- `pointName` – name of waypoint, freepoint or vob in game world

```dae title="Example usage"
Vob_MoveTo("CHEST_LOBART", "START");
```

## Vob_MoveToPos

Moves a specified vob to the exact coordinates (X, Y, Z) in the game world.

```dae
func void Vob_MoveToPos(var string vobName, var int posX, var int posY, var int posZ) {};
```

- `vobName` – name of vob in game world
- `posX` – X coordinate in the game world
- `posY` – Y coordinate in the game world
- `posZ` – Z coordinate in the game world

```dae title="Example usage"
Vob_MoveToPos("CHEST_LOBART", 16795, 23120, 1400);
```

## Vob_SetToFloor

Sticks a vob with a specified name to the ground.

```dae
func void Vob_SetToFloor(var string vobName) {};
```

- `vobName` – name of vob in game world

```dae title="Example usage"
Vob_SetToFloor("CHEST_LOBART");
```

## Vob_SetVisual

Sets the visual of a specified vob in the game world.

```dae
func void Vob_SetVisual(var string vobName, var string visualName) {};
```

- `vobName` – name of vob in game world
- `visualName` – name of assets (e.g. 3DS, ASC or MDS)

```dae title="Example usage"
Vob_SetVisual("CHEST_LOBART", "CHESTBIG_OCCHESTLARGELOCKED.MDS");
```

## Vob_SetCollisionDetection

Enables or disables dynamic and static collision detection for a specified vob.

```dae
func void Vob_SetCollisionDetection(var string vobName, var int dynamicCollDet, var int staticCollDet) {};
```

- `vobName` – name of vob in game world
- `dynamicCollDet` – dynamic collision detection
- `staticCollDet` – static collision detection

```dae title="Example usage"
Vob_SetCollisionDetection("CHEST_LOBART", FALSE, TRUE);
```

## Vob_GetDistToPos

Gets the distance between a specified vob and a given position in the world (in cm).

```dae
func int Vob_GetDistToPos(var string vobName, var int posX, var int posY, var int posZ) {};
```

- `vobName` – name of vob in game world
- `posX` – X coordinate of target position
- `posY` – Y coordinate of target position
- `posZ` – Z coordinate of target position
- `return` – distance between vob and position in cm

```dae title="Example usage"
if (Vob_GetDistToPos("CHEST_LOBART", 16795, 23120, 1400) <= 500)
{
    //...
};
```

## Vob_GetDistToNpc

Gets the distance between the vob and an NPC (in cm).

```dae
func int Vob_GetDistToNpc(var string vobName, var C_NPC npc) {};
```

- `vobName` – name of vob in game world
- `npc` – instance of the NPC
- `return` – distance between vob and NPC in cm

```dae title="Example usage"
if (Vob_GetDistToNpc("CHEST_LOBART", hero) <= 500)
{
    //...
};
```

## Vob_GetPortalRoom

Gets the name of the portal room in which the specified vob is currently located.

```dae
func string Vob_GetPortalRoom(var string vobName) {};
```

- `vobName` – name of vob in game world
- `return` – name of portal room

```dae title="Example usage"
var string room; room = Vob_GetPortalRoom("CHEST_LOBART");

if (Hlp_StrCmp(room, ""))
{
    //...
};
```
