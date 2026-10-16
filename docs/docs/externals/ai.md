# AI – functions for working with AI

## zDExt_AI_TurnToWP

Queues an AI action that turns an NPC towards a waypoint. If no waypoint matches, the function also searches for a freepoint or another vob with that name. The target point must exist.

```dae
func void zDExt_AI_TurnToWP(var C_NPC npc, var string wp) {};
```

- `npc` – instance of the NPC
- `wp` – name of waypoint in the game world

```dae title="Example usage"
zDExt_AI_TurnToWP(self, "WP_START");
```

## zDExt_AI_TurnToVob

Queues an AI action that turns an NPC towards a freepoint or vob in the world. If the vob is not found, no action is queued.

```dae
func void zDExt_AI_TurnToVob(var C_NPC npc, var string vob) {};
```

- `npc` – instance of the NPC
- `vob` – name of freepoint or vob in the game world

```dae title="Example usage"
zDExt_AI_TurnToVob(self, "CHEST_LOBART");
```

## zDExt_AI_TurnToPos

Queues an AI action that turns the NPC towards the specified world position.

```dae
func void zDExt_AI_TurnToPos(var C_NPC npc, var float posX, var float posY, var float posZ) {};
```

- `npc` – NPC to turn
- `posX`, `posY`, `posZ` – world coordinates in cm

```dae title="Example usage"
zDExt_AI_TurnToPos(self, 16795.0, 1400.0, 23120.0);
```

## zDExt_AI_CallFunction

Queues a script function call on the NPC through its AI event manager. Pass a function reference with no arguments.

```dae
func void zDExt_AI_CallFunction(var C_NPC npc, var func function) {};
```

- `npc` – NPC whose AI queue receives the call
- `function` – reference to the Daedalus function to execute

```dae title="Example usage"
func void MyQueuedAction()
{
    Print("Queued action executed");
};

zDExt_AI_CallFunction(self, MyQueuedAction);
```
