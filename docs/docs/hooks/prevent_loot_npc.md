# Prevent looting NPCs by player

!!! info "Engine restrictions"
    It's only available for **Gothic 2 Addon (G2A)**!

This hook is triggered whenever the player tries to **loot an NPCs** while they are unconscious or dead.
It extends the default looting system by allowing custom script conditions to determine whether looting is allowed.

To control looting behavior, define the following Daedalus function: `C_PlayerCanLootNpc`.

- `self` - player
- `other` - NPC to loot

```dae title="Example usage"
func int C_PlayerCanLootNpc()
{
    if (!Hlp_IsValidNpc(self) || !Hlp_IsValidNpc(other)) { 
        return false;
    };

    if (Hlp_GetInstanceID(other) == NONE_100_Xardas)
    {
        AI_PlayAni(self, "T_DONTKNOW");
        return false;
    };

    return true;
};
```
