#include "Utils/BetterDaedalusExternals.h"

namespace GOTHIC_NAMESPACE
{
	namespace BetterDaedalusExternals
	{
		void DefineExternals()
		{
			BaseExternalTable::DefineAll();
		}

		// G1:  0x006FB560 public: void __thiscall zCPar_DataStack::Clear(void)
		// G1A: 0x007359B0 public: void __thiscall zCPar_DataStack::Clear(void)
		// G2:  0x00745680 public: void __thiscall zCPar_DataStack::Clear(void)
		// G2A: 0x007A5180 public: void __thiscall zCPar_DataStack::Clear(void)
		void __fastcall zCPar_DataStack__Clear(zCPar_DataStack* t_this, void* t_reg);
		auto Hook_zCPar_DataStack__Clear = Union::CreateHook(reinterpret_cast<void*>(zSwitch(0x006FB560, 0x007359B0, 0x00745680, 0x007A5180)), &zCPar_DataStack__Clear, Union::HookType::Hook_Detours);
		void __fastcall zCPar_DataStack__Clear(zCPar_DataStack* t_this, void* t_reg)
		{
			Hook_zCPar_DataStack__Clear(t_this, t_reg);
			StringPool::ClearPool(t_this);
		}
	}
}