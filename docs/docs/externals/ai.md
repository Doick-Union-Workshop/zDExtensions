# AI – functions for working with AI

## zDExt_AI_TurnToWP

Turns an NPC to a specified waypoint in the world.

```dae
func void zDExt_AI_TurnToWP(var C_NPC npc, var string wp) {};
```

- `npc` – instance of the NPC
- `wp` – name of waypoint in the game world

```dae title="Example usage"
zDExt_AI_TurnToWP(self, "WP_START");
```

## zDExt_AI_TurnToVob

Turns an NPC to a specified freepoint or vob in the world. It works similarly to `zDExt_AI_TurnToWP`.

```dae
func void zDExt_AI_TurnToVob(var C_NPC npc, var string vob) {};
```

- `npc` – instance of the NPC
- `vob` – name of freepoint or vob in the game world

```dae title="Example usage"
zDExt_AI_TurnToVob(self, "CHEST_LOBART");
```
