#include "Externals/Externals_Definitions.hpp"

namespace GOTHIC_NAMESPACE
{
	void Game_DefineExternals()
	{
		zDExt_DefineExternals();
	}

	void __fastcall oCGame_DefineExternals_Ulfi(oCGame* self, void* vtable, zCParser* parser);
	auto Hook_oCGame_DefineExternals_Ulfi = Union::CreateHook(SIGNATURE_OF(&oCGame::DefineExternals_Ulfi), &oCGame_DefineExternals_Ulfi, Union::HookType::Hook_Detours);
	void __fastcall oCGame_DefineExternals_Ulfi(oCGame* self, void* vtable, zCParser* parser)
	{
		Hook_oCGame_DefineExternals_Ulfi(self, vtable, parser);
		Game_DefineExternals();
	}
}
