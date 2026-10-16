# Selling items by player

!!! info "Engine restrictions"
    It's only available for **Gothic 2 Addon (G2A)**!

This hook is triggered whenever the player tries to **sell an item** to an NPC during a trade.  
It extends the default trading system by allowing script conditions to decide whether an item can be sold.  

When the player attempts to sell an item, the hook looks for the following Daedalus function: `zDExt_Npc_CanPlayerSellItem` defined in `Scripts/Content` directory.

- `player` – player selling the item
- `trader` – NPC receiving the item
- `itm` – item being sold
- `return` – `FALSE` (zero) to block the action; `TRUE` (nonzero) to allow it. If the script call fails, the action is allowed and the failure is logged.

```dae title="Example usage"
func int zDExt_Npc_CanPlayerSellItem(var C_NPC player, var C_NPC trader, var C_ITEM itm)
{
    if (!Hlp_IsValidItem(itm))
    {
        return FALSE;
    };

    if (Hlp_GetInstanceID(itm) == ItMi_InnosEye_Mis)
    {
        Print("You cannot sell this unique item!");
        AI_PlayAni(player, "T_NO");
        AI_PlayAni(trader, "T_DONTKNOW");
        return FALSE;
    };

    return TRUE;
};
```
