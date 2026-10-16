namespace GOTHIC_NAMESPACE
{
    /*
     *
     * Created by Gratt-5r2, 2022
     * Original source: https://github.com/Gratt-5r2/zParserExtender/blob/master/zParserExtender/InfoMan.cpp
     * Reimplemented because for some reason the original hook does not work.
     *
     */

     // G1:  0x006658A0 public: void __thiscall oCInfo::Info(void)
     // G1A: 0x00692DC0 public: void __thiscall oCInfo::Info(void)
     // G2:  0x006A5EE0 public: void __thiscall oCInfo::Info(void)
     // G2A: 0x00703970 public: void __thiscall oCInfo::Info(void)
    auto Hook_oCInfo_Info = Union::CreateHook(
        reinterpret_cast<void*>(zSwitch(0x006658A0, 0x00692DC0, 0x006A5EE0, 0x00703970)),
        &oCInfo::Hook_Info,
        Union::HookType::Hook_Detours
    );
    void oCInfo::Hook_Info(void)
    {
        zCPar_Symbol* sym = parser->GetSymbol("DIA_CURRENTINSTANCE");
        if (sym && (sym->type == zPAR_TYPE_INT || sym->type == zPAR_TYPE_INSTANCE))
        {
            sym->SetValue(instance, 0);
        }

        (this->*Hook_oCInfo_Info)();
    }
}
