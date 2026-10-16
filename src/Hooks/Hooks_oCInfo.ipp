namespace GOTHIC_NAMESPACE
{
    /*
     *
     * Created by Gratt-5r2, 2022
     * Original source: https://github.com/Gratt-5r2/zParserExtender/blob/master/zParserExtender/InfoMan.cpp
     * Reimplemented because for some reason the original hook does not work.
     *
     */
    auto Hook_oCInfo_Info = Union::CreateHook(
        SIGNATURE_OF(&oCInfo::Info),
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
