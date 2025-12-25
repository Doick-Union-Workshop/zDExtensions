---
status: new
---

# Prevent finishing NPCs

!!! info "Engine restrictions"
    It's only available for **Gothic 2 Addon (G2A)**!

This hook is triggered whenever the player tries to **finish an NPC** while they are unconscious.
It extends the default finishing system by allowing custom script conditions to determine whether finishing is allowed.

To control finishing behavior, define the following Daedalus function: `C_CanFinishNpc`.

- `self` - NPC performing the finishing move
- `other` - target NPC

```dae title="Example usage"
func int C_CanFinishNpc()
{
    if (!Hlp_IsValidNpc(self) || !Hlp_IsValidNpc(other)) { 
        return FALSE;
    };

	if (Npc_IsPlayer(self))
	{
		AI_PlayAni(self, "T_NO");
		return FALSE;
	};

	return TRUE;
};
```