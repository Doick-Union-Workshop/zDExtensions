# Dropping items by NPCs

This hook is triggered when an NPC processes an AI/event-based **drop item** action. It supports all four engines and is not restricted to the player.
It lets you control whether an item can be dropped by using a script condition.

When an item is about to be dropped, the hook checks for a Daedalus function: `zDExt_Npc_CanDropItem` defined in `Scripts/Content` directory.

- `npc` – NPC dropping the item
- `itm` – item being dropped
- `return` – `FALSE` (zero) to block the action; `TRUE` (nonzero) to allow it. If the script call fails, the action is allowed and the failure is logged.

```dae title="Example usage"
func int zDExt_Npc_CanDropItem(var C_NPC npc, var C_ITEM itm)
{
    if (!Hlp_IsValidItem(itm))
    {
        return FALSE;
    };

    if (Hlp_GetInstanceID(itm) == ItMi_InnosEye_Mis)
    {
        Print("You cannot drop this unique item!");
        return FALSE;
    };

    return TRUE;
};
```
