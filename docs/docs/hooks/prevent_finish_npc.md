# Prevent finishing NPCs

!!! info "Engine restrictions"
    It's only available for **Gothic 2 Addon (G2A)**!

This hook is triggered whenever an NPC tries to **finish another NPC** while they are unconscious.
It extends the default finishing system by allowing custom script conditions to determine whether finishing is allowed.

To control finishing behavior, define the following Daedalus function: `zDExt_Npc_CanFinishAttack` defined in `Scripts/Content` directory.

- `attacker` – NPC performing the finishing attack
- `target` – NPC being finished
- `return` – `FALSE` (zero) to block the action; `TRUE` (nonzero) to allow it. If the script call fails, the action is allowed and the failure is logged.

```dae title="Example usage"
func int zDExt_Npc_CanFinishAttack(var C_NPC attacker, var C_NPC target)
{
    if (!Hlp_IsValidNpc(attacker) || !Hlp_IsValidNpc(target))
    { 
        return FALSE;
    };

    if (Npc_IsPlayer(attacker))
    {
        AI_PlayAni(attacker, "T_NO");
        return FALSE;
    };

    return TRUE;
};
```
