namespace GOTHIC_NAMESPACE
{
    // API definitions
    static const zSTRING MENU_SAVELOADGAME_API  = "MENU_SAVELOADGAME_API";
    static const zSTRING MENU_STATUS_API        = "MENU_STATUS_API";
    static const zSTRING C_PLAYER_CAN_DROP_ITEM = "C_PLAYERCANDROPITEM";
    static const zSTRING C_PLAYER_CAN_SELL_ITEM = "C_PLAYERCANSELLITEM";
    static const zSTRING C_PLAYER_CAN_LOOT_NPC  = "C_PLAYERCANLOOTNPC";
    static const zSTRING C_CAN_FINISH_NPC       = "C_CANFINISHNPC";

    static oCNpcContainer* npcContainer         = nullptr;

    // API registration
    Union::Array<zSTRING> hookAPIs = {
        MENU_SAVELOADGAME_API,
        MENU_STATUS_API,
        C_PLAYER_CAN_DROP_ITEM,
        C_PLAYER_CAN_SELL_ITEM,
        C_PLAYER_CAN_LOOT_NPC,
        C_CAN_FINISH_NPC
    };
    Union::Array<zSTRING> registeredHookAPIs;
}
