namespace GOTHIC_NAMESPACE
{
    struct ParserVarsBackup
    {
        oCNpc* self = nullptr;
        oCNpc* other = nullptr;
        oCNpc* victim = nullptr;
        oCItem* item = nullptr;

        template<typename T>
        T* GetInstance(const char* name)
        {
            if (auto sym = parser->GetSymbol(name))
            {
                return dynamic_cast<T*>((zCVob*)sym->GetInstanceAdr());
            }

            return nullptr;
        }

        void Save()
        {
            self = GetInstance<oCNpc>("SELF");
            other = GetInstance<oCNpc>("OTHER");
            victim = GetInstance<oCNpc>("VICTIM");
            item = GetInstance<oCItem>("ITEM");
        }

        void Restore() const
        {
            parser->SetInstance("SELF", self);
            parser->SetInstance("OTHER", other);
            parser->SetInstance("VICTIM", victim);
            parser->SetInstance("ITEM", item);
        }
    };

    inline ParserVarsBackup globalParserVars;
}
