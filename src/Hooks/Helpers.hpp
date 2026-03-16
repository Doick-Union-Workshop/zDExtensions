namespace GOTHIC_NAMESPACE
{
    oCNpc* zDE_oldSelfNpc = nullptr;
    oCNpc* zDE_oldOtherNpc = nullptr;
    oCNpc* zDE_oldVictimNpc = nullptr;
    oCItem* zDE_oldItem = nullptr;

    void zDE_SaveParserVars()
    {
        zDE_oldSelfNpc = nullptr;
        zDE_oldOtherNpc = nullptr;
        zDE_oldVictimNpc = nullptr;
        zDE_oldItem = nullptr;

        zCPar_Symbol* sym = parser->GetSymbol("SELF");
        if (sym)
        {
            zDE_oldSelfNpc = dynamic_cast<oCNpc*>((zCVob*)sym->GetInstanceAdr());
        }

        sym = parser->GetSymbol("OTHER");
        if (sym)
        {
            zDE_oldOtherNpc = dynamic_cast<oCNpc*>((zCVob*)sym->GetInstanceAdr());
        }

        sym = parser->GetSymbol("VICTIM");
        if (sym)
        {
            zDE_oldVictimNpc = dynamic_cast<oCNpc*>((zCVob*)sym->GetInstanceAdr());
        }

        sym = parser->GetSymbol("ITEM");
        if (sym)
        {
            zDE_oldItem = dynamic_cast<oCItem*>((zCVob*)sym->GetInstanceAdr());
        }
    }

    void zDE_RestoreParserVars()
    {
        parser->SetInstance("SELF", zDE_oldSelfNpc);
        parser->SetInstance("OTHER", zDE_oldOtherNpc);
        parser->SetInstance("VICTIM", zDE_oldVictimNpc);
        parser->SetInstance("ITEM", zDE_oldItem);
    }
}
