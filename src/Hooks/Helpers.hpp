namespace GOTHIC_NAMESPACE
{
    oCNpc* zDE_oldSelfNpc = NULL;
    oCNpc* zDE_oldOtherNpc = NULL;
    oCNpc* zDE_oldVictimNpc = NULL;
    oCItem* zDE_oldItem = NULL;

    static void zDE_SaveParserVars()
    {
        zDE_oldSelfNpc = NULL;
        zDE_oldOtherNpc = NULL;
        zDE_oldVictimNpc = NULL;
        zDE_oldItem = NULL;

        auto sym = parser->GetSymbol("SELF");
        if (sym) {
            zDE_oldSelfNpc = dynamic_cast<oCNpc*>((zCVob*)sym->GetInstanceAdr());
        }

        sym = parser->GetSymbol("OTHER");
        if (sym) {
            zDE_oldOtherNpc = dynamic_cast<oCNpc*>((zCVob*)sym->GetInstanceAdr());
        }

        sym = parser->GetSymbol("VICTIM");
        if (sym) {
            zDE_oldVictimNpc = dynamic_cast<oCNpc*>((zCVob*)sym->GetInstanceAdr());
        }

        sym = parser->GetSymbol("ITEM");
        if (sym) {
            zDE_oldItem = dynamic_cast<oCItem*>((zCVob*)sym->GetInstanceAdr());
        }
    }

    static void zDE_RestoreParserVars()
    {
        parser->SetInstance("SELF", zDE_oldSelfNpc);
        parser->SetInstance("OTHER", zDE_oldOtherNpc);
        parser->SetInstance("VICTIM", zDE_oldVictimNpc);
        parser->SetInstance("ITEM", zDE_oldItem);
    }
}
