# Prevent killing NPCs

This hook supports all four engines. Define `zDExt_Npc_CanKill` in `Scripts/Content` to control whether damage may mark an NPC as dead.

The function runs after the engine evaluates damage conditions, including damage that is not fatal. If the engine marks the target as dead and the function returns `FALSE`, the hook clears the dead flag and sets the unconscious flag. It does not cancel damage or restore health. It is separate from [finishing attacks](prevent_finish_npc.md).

- `attacker` – NPC causing the damage; may be a null instance for damage without an NPC attacker
- `target` – NPC receiving the damage
- `return` – `FALSE` (zero) to replace the dead state with unconsciousness; `TRUE` (nonzero) to keep the engine result. A failed script call keeps the engine result and logs the failure.

```dae title="Example usage"
func int zDExt_Npc_CanKill(var C_NPC attacker, var C_NPC target)
{
    if (!Hlp_IsValidNpc(target))
    {
        return TRUE;
    };

    if (Hlp_GetInstanceID(target) == NONE_100_Xardas)
    {
        return FALSE;
    };

    return TRUE;
};
```
