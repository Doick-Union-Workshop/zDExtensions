namespace GOTHIC_NAMESPACE
{
	// G1:	0x0042C420 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	// G1A:	0x0042F500 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	// G2:	0x0042E620 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	// G2A:	0x0042E940 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	auto Hook_oCMenuSavegame_HandleSlotChange = Union::CreateHook(
		reinterpret_cast<void*>(zSwitch(0x0042C420, 0x0042F500, 0x0042E620, 0x0042E940)),
		&oCMenuSavegame::Hook_HandleSlotChange,
		Union::HookType::Hook_Detours
	);
	void __thiscall oCMenuSavegame::Hook_HandleSlotChange(int t_key)
	{
		(this->*Hook_oCMenuSavegame_HandleSlotChange)(t_key);

		const auto apiCall = DaedalusCall(parserMenu, DCFunction("MENU_SAVELOADGAME_API"), {});

		if (!apiCall.has_value())
		{
			static auto logger = Utils::CreateLogger("zDExt::oCMenuSavegame::HandleSlotChange");
			logger->Info(DAEDALUS_CALL_FAILED_MSG, "MENU_SAVELOADGAME_API", CallErrorToString(apiCall.error()));
		}
	}
}
