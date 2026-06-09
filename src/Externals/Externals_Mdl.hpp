namespace GOTHIC_NAMESPACE
{
	void zDExt_Mdl_SetVisualBody(oCNpc* t_npc, const zSTRING& t_body)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->body_visualName = t_body;
	}

	void zDExt_Mdl_SetVisualBodyTexture(oCNpc* t_npc, const int t_bodyTexNr)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->body_TexVarNr = t_bodyTexNr;
	}

	void zDExt_Mdl_SetVisualBodySkinTexture(oCNpc* t_npc, const int t_bodySkinTexNr)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->body_TexColorNr = t_bodySkinTexNr;
	}

	void zDExt_Mdl_SetVisualHead(oCNpc* t_npc, const zSTRING& t_head)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->head_visualName = t_head;
	}

	void zDExt_Mdl_SetVisualHeadTexture(oCNpc* t_npc, const int t_headTexNr)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->head_TexVarNr = t_headTexNr;
	}

	void zDExt_Mdl_SetVisualTeethTexture(oCNpc* t_npc, const int t_teethTexNr)
	{
		if (!t_npc)
		{
			return;
		}

		t_npc->teeth_TexVarNr = t_teethTexNr;
	}
}
