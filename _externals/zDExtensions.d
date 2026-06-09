// =========================================================
//
//  AI functions 
//
// =========================================================

/// Turns the NPC to the specified waypoint.
/// @param npc The NPC to perform the action on.
/// @param wp The name of the waypoint to turn to.
func void zDExt_AI_TurnToWP(var C_NPC npc, var string wp) {};

/// Turns the NPC to the specified VOB.
/// @param npc The NPC to perform the action on.
/// @param vob The name of the VOB to turn to.
func void zDExt_AI_TurnToVob(var C_NPC npc, var string vob) {};

/// Turns the NPC to the specified position.
/// @param npc The NPC to perform the action on.
/// @param posX The X coordinate of the position to turn to.
/// @param posY The Y coordinate of the position to turn to.
/// @param posZ The Z coordinate of the position to turn to.
func void zDExt_AI_TurnToPos(var C_NPC npc, var int posX, var int posY, var int posZ) {};

/// Calls the specified function on the NPC.
/// @param npc The NPC to perform the action on.
/// @param function The name of the function to call.
func void zDExt_AI_CallFunction(var C_NPC npc, var func function) {};

// =========================================================
//
//  Helper functions 
//
// =========================================================

/// Finds the item object by its instance name.
/// @param itemInstance The instance name of the item to find.
func C_Item zDExt_Hlp_GetItem(var int itemInstance) {};

/// Checks if the specified VOB exists in the game world.
/// @param vobName The name of the VOB to check.
func int zDExt_Hlp_IsValidVob(var string vobName) {};

/// Check if the specified level, section and option exists in the game configuration.
/// @param level The name of the level to check.
/// @param section The name of the section to check.
/// @param option The name of the option to check.
func int zDExt_Hlp_IsOptionExists(var string level, var string section, var string option) {};

func int zDExt_Hlp_GetOptionIntValue(var string level, var string section, var string option, var int defaultValue) {};

func float zDExt_Hlp_GetOptionFloatValue(var string level, var string section, var string option, var float defaultValue) {};

func string zDExt_Hlp_GetOptionStringValue(var string level, var string section, var string option, var string defaultValue) {};

func void zDExt_Hlp_SetOptionIntValue(var string level, var string section, var string option, var int defaultValue) {};

func void zDExt_Hlp_SetOptionFloatValue(var string level, var string section, var string option, var float defaultValue) {};

func void zDExt_Hlp_SetOptionStringValue(var string level, var string section, var string option, var string defaultValue) {};

/// Checks if the game is currently running in test mode.
func int zDExt_Hlp_IsTestMode() {};

// =========================================================
//
//  Log functions 
//
// =========================================================

/// Get the status of the specified log topic.
/// @param topicName The name of the log topic to check.
func int zDExt_Log_GetTopicStatus(var string topicName) {};

// =========================================================
//
//  Menu functions 
//
// =========================================================

/// Sets the text of the specified menu item.
/// @param name The name of the menu item to modify.
/// @param text The text to set.
/// @param line The line number of the menu item to modify.
/// @param drawNow Whether to draw the menu immediately.
func void zDExt_Menu_SetItemText(var string name, var string text, var int line, var int drawNow) {};

/// Gets the text of the specified menu item.
/// @param name The name of the menu item to get the text from.
/// @param line The line number of the menu item to get the text from.
func string zDExt_Menu_GetItemText(var string name, var int line) {};

// =========================================================
//
//  MOB functions 
//
// =========================================================

/// Sets the focus name of the specified MOB.
/// @param mobName The name of the MOB to set the focus name for.
/// @param focusName The focus name to set for the MOB.
func void zDExt_Mob_SetFocusName(var string mobName, var string focusName) {};

/// Gets the focus name of the specified MOB.
/// @param mobName The name of the MOB to get the focus name from.
/// @return The focus name of the MOB.
func string zDExt_Mob_GetFocusName(var string mobName) {};

/// Sets the scheme name of the specified MOB.
/// @param mobName The name of the MOB to set the scheme name for.
func string zDExt_Mob_GetScemeName(var string mobName) {};

// =========================================================
//
//  NPC functions 
//
// =========================================================

/// Gets the routine function name of the specified NPC e.g. `RTN_PRESTART_100`.
/// @param npc The NPC to get the routine function name from.
func string zDExt_Npc_GetRoutineFuncName(var C_NPC npc) {};

/// Gets the routine name of the specified NPC e.g. `PRESTART`.
/// @param npc The NPC to get the routine name from.
func string zDExt_Npc_GetRoutineName(var C_NPC npc) {};

/// Equips the specified item on the NPC.
/// @param npc The NPC to equip the item on.
/// @param itemInstance The instance name of the item to equip.
func void zDExt_Npc_EquipItem(var C_NPC npc, var int itemInstance) {};

/// Get the walk mode of the specified NPC.
/// @param npc The NPC to get the walk mode from.
func int zDExt_Npc_GetWalkMode(var C_NPC npc) {};

/// Checks if the NPC is currently standing.
/// @param npc The NPC to check.
func int zDExt_Npc_IsStanding(var C_NPC npc) {};

/// Checks if the NPC is currently walking.
/// @param npc The NPC to check.
func int zDExt_Npc_IsWalking(var C_NPC npc) {};

/// Checks if the NPC has the specified overlay MDS.
/// @param npc The NPC to check.
/// @param overlay The name of the overlay MDS to check for.
func int zDExt_Npc_HasOverlayMds(var C_NPC npc, var string overlay) {};

/// Checks if the NPC has the specified timed overlay MDS.
/// @param npc The NPC to check.
/// @param overlay The name of the timed overlay MDS to check for.
func int zDExt_Npc_HasTimedOverlayMds(var C_NPC npc, var string overlay) {};

/// Opens the inventory of the specified NPC.
/// @param npc The NPC to open the inventory of.
func void zDExt_Npc_OpenDeadNpcInventory(var C_NPC npc) {};

/// Closes the inventory of the specified NPC.
/// @param npc The NPC to close the inventory of.
func void zDExt_Npc_CloseInventory(var C_NPC npc) {};

/// Closes the steal inventory of the specified NPC.
/// @param npc The NPC to close the steal inventory of.
func void zDExt_Npc_CloseInventorySteal(var C_NPC npc) {};

/// Closes the dead NPC inventory of the specified NPC.
/// @param npc The NPC to close the dead NPC inventory of.
func void zDExt_Npc_CloseDeadNpcInventory(var C_NPC npc) {};

/// Gets the distance from the NPC to the specified position.
/// @param npc The NPC to get the distance from.
/// @param posX The X coordinate of the position to get the distance to.
/// @param posY The Y coordinate of the position to get the distance to.
/// @param posZ The Z coordinate of the position to get the distance to.
func int zDExt_Npc_GetDistToPos(var C_NPC npc, var int posX, var int posY, var int posZ) {};

/// Gets the distance from the NPC to the specified VOB.
/// @param npc The NPC to get the distance from.
/// @param vobName The name of the VOB to get the distance to.
func int zDExt_Npc_GetDistToVob(var C_NPC npc, var string vobName) {};

/// Gets the visual body of the specified NPC.
/// @param npc The NPC to get the visual body from.
func string zDExt_Npc_GetVisualBody(var C_NPC npc) {};

/// Gets the visual head of the specified NPC.
/// @param npc The NPC to get the visual head from.
func string zDExt_Npc_GetVisualHead(var C_NPC npc) {};

/// Gets the name of the portal room of the specified NPC.
/// @param npc The NPC to get the portal room from.
func string zDExt_Npc_GetPortalRoom(var C_NPC npc) {};

/// Teleports the NPC to the specified point without AI queue.
/// @param npc The NPC to teleport.
/// @param point The point to teleport the NPC to.
func void zDExt_Npc_Teleport(var C_NPC npc, var string point) {};

// =========================================================
//
//  String functions 
//
// =========================================================

/// Converts the specified string to uppercase.
/// @param str The string to convert to uppercase.
func string zDExt_Str_Upper(var string str) {};

/// Converts the specified string to lowercase.
/// @param str The string to convert to lowercase.
func string zDExt_Str_Lower(var string str) {};

/// Gets the length of the specified string.
/// @param str The string to get the length of.
func int zDExt_Str_Length(var string str) {};

/// Converts the specified string to capital case.
/// @param str The string to convert to capital case.
func string zDExt_Str_Capitel(var string str) {};

/// Checks if the specified string starts with the specified prefix.
/// @param str The string to check.
/// @param prefix The prefix to check for.
func int zDExt_Str_StartsWith(var string str, var string prefix) {};

/// Checks if the specified string ends with the specified suffix.
/// @param str The string to check.
/// @param suffix The suffix to check for.
func int zDExt_Str_EndsWith(var string str, var string suffix) {};

/// Checks if the specified string contains the specified substring.
/// @param str The string to check.
/// @param startIndex The index to start the search from.
/// @param length The length of the substring to search for.
func string zDExt_Str_Cut(var string str, var int startIndex, var int length) {};

/// Replaces all occurrences of the specified substring in the string with the specified replacement.
/// @param str The string to perform the replacement on.
/// @param value The replacement string to replace the substring with.
/// @param index The index of the substring to replace.
func string zDExt_Str_Put(var string str, var string value, var int index) {};

/// Format the specified string with the provided arguments.
/// @param format The string to format.
/// @param ... The arguments to format the string with.
func string zDExt_Str_Format(var string format, ...) {}; 

// =========================================================
//
//  Utils functions 
//
// =========================================================

/// Gets the value of the specified integer array element.
/// @param arr The name of the integer array to get the value from.
/// @param index The index of the integer array element to get the value from.
func int zDExt_GetIntArrayValue(var string arr, var int index) {};

/// Gets the value of the specified string array element.
/// @param arr The name of the string array to get the value from.
/// @param index The index of the string array element to get the value from.
func string zDExt_GetStringArrayValue(var string arr, var int index) {};

/// Sets the value of the specified integer array element.
/// @param arr The name of the integer array to set the value in.
/// @param index The index of the integer array element to set the value in.
/// @param value The value to set the integer array element to.
func void zDExt_SetIntArrayValue(var int arr, var int index, var int value) {};

/// Sets the value of the specified string array element.
/// @param arr The name of the string array to set the value in.
/// @param index The index of the string array element to set the value in.
/// @param value The value to set the string array element to.
func void zDExt_SetStringArrayValue(var string arr, var int index, var string value) {};

// =========================================================
//
//  VOB functions 
//
// =========================================================

/// Rotates the specified VOB locally by the specified rotation values.
/// @param vobName The name of the VOB to rotate.
/// @param rotX The rotation value around the X axis to rotate the VOB by.
/// @param rotY The rotation value around the Y axis to rotate the VOB by.
/// @param rotZ The rotation value around the Z axis to rotate the VOB by.
func void zDExt_Vob_RotateLocal(var string vobName, var int rotX, var int rotY, var int rotZ) {};

/// Rotates the specified VOB in world space by the specified rotation values.
/// @param vobName The name of the VOB to rotate.
/// @param rotX The rotation value around the X axis to rotate the VOB by.
/// @param rotY The rotation value around the Y axis to rotate the VOB by.
/// @param rotZ The rotation value around the Z axis to rotate the VOB by.
func void zDExt_Vob_RotateWorld(var string vobName, var int rotX, var int rotY, var int rotZ) {};

/// Moves the specified VOB to the specified point.
/// @param vobName The name of the VOB to move.
/// @param pointName The name of the point to move the VOB to.
func void zDExt_Vob_MoveTo(var string vobName, var string pointName) {};

/// Moves the specified VOB to the specified position.
/// @param vobName The name of the VOB to move.
/// @param posX The X coordinate of the position to move the VOB to.
/// @param posY The Y coordinate of the position to move the VOB to.
/// @param posZ The Z coordinate of the position to move the VOB to.
func void zDExt_Vob_MoveToPos(var string vobName, var int posX, var int posY, var int posZ) {};

/// Sets the specified VOB to the floor.
/// @param vobName The name of the VOB to set to the floor.
func void zDExt_Vob_SetToFloor(var string vobName) {};

/// Sets the visual of the specified VOB.
/// @param vobName The name of the VOB to set the visual of.
/// @param visualName The name of the visual to set for the VOB.
func void zDExt_Vob_SetVisual(var string vobName, var string visualName) {};

/// Sets the collision detection of the specified VOB.
/// @param vobName The name of the VOB to set the collision detection of.
/// @param dynamicCollDet The dynamic collision detection to set for the VOB.
/// @param staticCollDet The static collision detection to set for the VOB.
func void zDExt_Vob_SetCollisionDetection(var string vobName, var int dynamicCollDet, var int staticCollDet) {};

/// Gets the distance from the specified VOB to the specified position.
/// @param vobName The name of the VOB to get the distance from.
/// @param posX The X coordinate of the position to get the distance to.
/// @param posY The Y coordinate of the position to get the distance to.
/// @param posZ The Z coordinate of the position to get the distance to.
func int zDExt_Vob_GetDistToPos(var string vobName, var int posX, var int posY, var int posZ) {};

/// Gets the distance from the specified VOB to the specified NPC.
/// @param vobName The name of the VOB to get the distance from.
/// @param npc The NPC to get the distance to.
func int zDExt_Vob_GetDistToNpc(var string vobName, var C_NPC npc) {};

/// Gets the name of the portal room of the specified VOB.
/// @param vobName The name of the VOB to get the portal room from.
func string zDExt_Vob_GetPortalRoom(var string vobName) {};

// =========================================================
//
//  World functions 
//
// =========================================================

/// Inserts a VOB with the specified name at the specified point in the game world.
/// @param vobName The name of the VOB to insert.
/// @param pointName The name of the point to insert the VOB at.
func void zDExt_Wld_InsertVob(var string vobName, var string pointName) {};

/// Inserts a MOB with the specified name at the specified point in the game world.
/// @param vobName The name of the MOB to insert.
/// @param pointName The name of the point to insert the MOB at.
func void zDExt_Wld_InsertMob(var string vobName, var string pointName) {};

/// Inserts an interactive MOB with the specified name at the specified point in the game world.
/// @param vobName The name of the interactive MOB to insert.
/// @param pointName The name of the point to insert the interactive MOB at.
func void zDExt_Wld_InsertMobInter(var string vobName, var string pointName) {};

/// Inserts a container MOB with the specified name at the specified point in the game world.
/// @param vobName The name of the container MOB to insert.
/// @param pointName The name of the point to insert the container MOB at.
func void zDExt_Wld_InsertMobContainer(var string vobName, var string pointName) {};

/// Inserts a fire MOB with the specified name at the specified point in the game world.
/// @param vobName The name of the fire MOB to insert.
/// @param pointName The name of the point to insert the fire MOB at.\
func void zDExt_Wld_InsertMobFire(var string vobName, var string pointName) {};

/// Inserts a door MOB with the specified name at the specified point in the game world.
/// @param vobName The name of the door MOB to insert.
/// @param pointName The name of the point to insert the door MOB at.
func void zDExt_Wld_InsertMobDoor(var string vobName, var string pointName) {};

/// Inserts a bed MOB with the specified name at the specified point in the game world.
/// @param vobName The name of the bed MOB to insert.
/// @param pointName The name of the point to insert the bed MOB at.
func void zDExt_Wld_InsertMobBed(var string vobName, var string pointName) {};

/// Inserts a VOB with the specified name at the specified position in the game world.
/// @param vobName The name of the VOB to insert.
/// @param posX The X coordinate of the position to insert the VOB at.
/// @param posY The Y coordinate of the position to insert the VOB at.
/// @param posZ The Z coordinate of the position to insert the VOB at.
func void zDExt_Wld_InsertVobPos(var string vobName, var int posX, var int posY, var int posZ) {};

/// Inserts a MOB with the specified name at the specified position in the game world.
/// @param vobName The name of the MOB to insert.
/// @param posX The X coordinate of the position to insert the MOB at.
/// @param posY The Y coordinate of the position to insert the MOB at.
/// @param posZ The Z coordinate of the position to insert the MOB at.
func void zDExt_Wld_InsertMobPos(var string vobName, var int posX, var int posY, var int posZ) {};

/// Inserts an interactive MOB with the specified name at the specified position in the game world.
/// @param vobName The name of the interactive MOB to insert.
/// @param posX The X coordinate of the position to insert the interactive MOB at.
/// @param posY The Y coordinate of the position to insert the interactive MOB at.
/// @param posZ The Z coordinate of the position to insert the interactive MOB at.
func void zDExt_Wld_InsertMobInterPos(var string vobName, var int posX, var int posY, var int posZ) {};

/// Inserts a container MOB with the specified name at the specified position in the game world.
/// @param vobName The name of the container MOB to insert.
/// @param posX The X coordinate of the position to insert the container MOB at.
/// @param posY The Y coordinate of the position to insert the container MOB at.
/// @param posZ The Z coordinate of the position to insert the container MOB at.
func void zDExt_Wld_InsertMobContainerPos(var string vobName, var int posX, var int posY, var int posZ) {};

/// Inserts a fire MOB with the specified name at the specified position in the game world.
/// @param vobName The name of the fire MOB to insert.
/// @param posX The X coordinate of the position to insert the fire MOB at.
/// @param posY The Y coordinate of the position to insert the fire MOB at.
/// @param posZ The Z coordinate of the position to insert the fire MOB at.
func void zDExt_Wld_InsertMobFirePos(var string vobName, var int posX, var int posY, var int posZ) {};

/// Inserts a door MOB with the specified name at the specified position in the game world.
/// @param vobName The name of the door MOB to insert.
/// @param posX The X coordinate of the position to insert the door MOB at.
/// @param posY The Y coordinate of the position to insert the door MOB at.
/// @param posZ The Z coordinate of the position to insert the door MOB at.
func void zDExt_Wld_InsertMobDoorPos(var string vobName, var int posX, var int posY, var int posZ) {};

/// Inserts a bed MOB with the specified name at the specified position in the game world.
/// @param vobName The name of the bed MOB to insert.
/// @param posX The X coordinate of the position to insert the bed MOB at.
/// @param posY The Y coordinate of the position to insert the bed MOB at.
/// @param posZ The Z coordinate of the position to insert the bed MOB at.
func void zDExt_Wld_InsertMobBedPos(var string vobName, var int posX, var int posY, var int posZ) {};

/// Removes the specified VOB from the game world.
/// @param vobName The name of the VOB to remove.
func int zDExt_Wld_RemoveVob(var string vobName) {};

/// Gets the name of the portal room of the specified point.
func string zDExt_Wld_GetPlayerPortalRoom() {};
