namespace GOTHIC_NAMESPACE
{
	// G1:	0x0042C420 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	// G1A:	0x0042F500 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	// G2:	0x0042E620 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	// G2A:	0x0042E940 public: virtual void __thiscall oCMenuSavegame::HandleSlotChange(int)
	auto Hook_oCMenuSavegame_HandleSlotChange = Union::CreateHook(
		reinterpret_cast<void*>(zSwitch(0x0042C420, 0x0042F500, 0x0042E620, 0x0042E940)),
		&oCMenuSavegame::Hook_HandleSlotChange
	);
	void __thiscall oCMenuSavegame::Hook_HandleSlotChange(int t_key)
	{
		(this->*Hook_oCMenuSavegame_HandleSlotChange)(t_key);

		if (!IsHookAPIRegistered(MENU_SAVELOADGAME_API)) return;

		static Utils::Logger* log = Utils::CreateLogger("zDExt::oCMenuSavegame::HandleSlotChange");
		const auto api = DaedalusCall(parserMenu, DCFunction(MENU_SAVELOADGAME_API), {});

		if (!api.has_value())
			LogDaedalusCallError(log, MENU_SAVELOADGAME_API, api.error());
	}
}