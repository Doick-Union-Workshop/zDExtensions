# Prevent looting NPCs by player

!!! info "Engine restrictions"
    It's only available for **Gothic 2 Addon (G2A)**!

This hook is triggered whenever the player tries to **loot an NPCs** while they are unconscious or dead.
It extends the default looting system by allowing custom script conditions to determine whether looting is allowed.

To control looting behavior, define the following Daedalus function: `zDExt_Npc_CanPlayerPlunder` defined in `Scripts/Content` directory.

- `plunderer` – NPC opening the plunder inventory
- `target` – NPC being looted
- `return` – `FALSE` (zero) to block the action; `TRUE` (nonzero) to allow it. If the script call fails, the action is allowed and the failure is logged.

```dae title="Example usage"
func int zDExt_Npc_CanPlayerPlunder(var C_NPC plunderer, var C_NPC target)
{
    if (!Hlp_IsValidNpc(plunderer) || !Hlp_IsValidNpc(target))
    {
        return FALSE;
    };

    if (Hlp_GetInstanceID(target) == NONE_100_Xardas)
    {
        AI_PlayAni(plunderer, "T_DONTKNOW");
        return FALSE;
    };

    return TRUE;
};
```
