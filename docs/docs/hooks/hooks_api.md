# Hooks API

Some features in the project are customizable and require configuration to work correctly. To support this, zDExtensions provide an API (Application Programming Interface) through special hook functions.  

These hooks allow you to extend or override parts of the game by writing your own script functions in Daedalus, which are executed at specific events (e.g., when opening a menu or selecting a save slot).

!!! info "Engine restrictions"
    Some hooks are only available on specific engines. For example, certain hooks may work **only in Gothic 1** or **only in Gothic 2 Addon (G2A)**. Always check the hook documentation to see which engine it supports. If this information is missing, it means that the hook supports all 4 engines.

## Callback signatures

Define callbacks in the appropriate parser: `Scripts/System` for the save/load menu and `Scripts/Content` for the other callbacks. Use the exact function name, argument order, and return type shown on each page. NPC and item arguments are passed explicitly; use those parameters instead of assuming that global `self`, `other`, or `item` are set by the hook.

| Callback | Parameters | Return | Engines |
| --- | --- | --- | --- |
| `zDExt_Menu_SaveLoadGame_Hook` | none | `void` | G1, G1A, G2, G2A |
| `zDExt_Menu_Status_Hook` | none | `void` | G1, G1A, G2, G2A |
| `zDExt_Npc_CanDropItem` | `C_NPC npc`, `C_Item itm` | `int` | G1, G1A, G2, G2A |
| `zDExt_Npc_CanPlayerSellItem` | `C_NPC player`, `C_NPC trader`, `C_Item itm` | `int` | G2A |
| `zDExt_Npc_CanPlayerPlunder` | `C_NPC plunderer`, `C_NPC target` | `int` | G2A |
| `zDExt_Npc_CanFinishAttack` | `C_NPC attacker`, `C_NPC target` | `int` | G2A |
| `zDExt_Npc_CanKill` | `C_NPC attacker`, `C_NPC target` | `int` | G1, G1A, G2, G2A |

Action permission callbacks return zero to block an action and a nonzero value to allow it. If an enabled callback cannot be called because its signature is invalid, the action is allowed and the error is logged.
