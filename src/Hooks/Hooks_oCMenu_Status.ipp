#include "Hooks/Hooks_Helpers.hpp"

namespace GOTHIC_NAMESPACE
{
	auto Hook_oCMenu_Status_InitForDisplay = Union::CreateHook(
		SIGNATURE_OF(&oCMenu_Status::InitForDisplay),
		&oCMenu_Status::Hook_InitForDisplay,
		Union::HookType::Hook_Detours
	);
	void __thiscall oCMenu_Status::Hook_InitForDisplay(void)
	{
		(this->*Hook_oCMenu_Status_InitForDisplay)();

		const auto result = DaedalusCall(
			parser,
			DCFunction("zDExt_Menu_Status_Hook"),
			eClearStack::CLEAR
		);

		if (!result.has_value())
		{
			static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::oCMenu_Status::InitForDisplay");
			logger->Info(
				DAEDALUS_CALL_FAILED_MSG,
				"zDExt_Menu_Status_Hook",
				DaedalusCallErrorToString(result.error())
			);
		}
	}
}
