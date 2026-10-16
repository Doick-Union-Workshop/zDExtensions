#include "Hooks/Hooks_Helpers.hpp"

namespace GOTHIC_NAMESPACE
{
	auto Hook_oCMenuSavegame_HandleSlotChange = Union::CreateHook(
		SIGNATURE_OF(&oCMenuSavegame::HandleSlotChange),
		&oCMenuSavegame::Hook_HandleSlotChange,
		Union::HookType::Hook_Detours
	);
	void __thiscall oCMenuSavegame::Hook_HandleSlotChange(int t_key)
	{
		(this->*Hook_oCMenuSavegame_HandleSlotChange)(t_key);

		const auto result = DaedalusCall(
			parserMenu,
			DCFunction("zDExt_Menu_SaveLoadGame_Hook"),
			eClearStack::CLEAR
		);

		if (!result.has_value())
		{
			static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::oCMenuSavegame::HandleSlotChange");
			logger->Info(
				DAEDALUS_CALL_FAILED_MSG,
				"zDExt_Menu_SaveLoadGame_Hook",
				DaedalusCallErrorToString(result.error())
			);
		}
	}
}
