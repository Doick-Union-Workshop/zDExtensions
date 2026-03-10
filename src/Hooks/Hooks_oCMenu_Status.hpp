namespace GOTHIC_NAMESPACE
{
	// G1:	0x0042C420 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	// G1A:	0x00480370 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	// G2:	0x0047C8F0 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	// G2A:	0x0047DDC0 public: void __thiscall oCMenu_Status::InitForDisplay(void)
	auto Hook_oCMenu_Status_InitForDisplay = Union::CreateHook(
		reinterpret_cast<void*>(zSwitch(0x00476A20, 0x00480370, 0x0047C8F0, 0x0047DDC0)),
		&oCMenu_Status::Hook_InitForDisplay,
		Union::HookType::Hook_Detours
	);
	void __thiscall oCMenu_Status::Hook_InitForDisplay(void)
	{
		(this->*Hook_oCMenu_Status_InitForDisplay)();

		static auto logger = Utils::CreateLogger("zDExt::oCMenu_Status::InitForDisplay");
		const auto apiCall = DaedalusCall(parser, DCFunction("MENU_STATUS_API"), {});

		if (!apiCall.has_value()) {
			logger->Info(DAEDALUS_CALL_FAILED_MSG, "MENU_STATUS_API", CallErrorToString(apiCall.error()));
		}
	}
}
