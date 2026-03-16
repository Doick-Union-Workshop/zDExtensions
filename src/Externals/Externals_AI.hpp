namespace GOTHIC_NAMESPACE
{
	void AI_TurnToWP(oCNpc* t_npc, const zSTRING& t_pointName)
	{
		if (!t_npc)
		{
			return;
		}

		static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::AI_TurnToWP");
		auto pos = GetWaypointPosition(t_pointName, logger);
		auto msg = new oCMsgMovement(oCMsgMovement::EV_TURNTOPOS, pos.value());
		t_npc->GetEM()->OnMessage(msg, t_npc);
	}

	void AI_TurnToVob(oCNpc* t_npc, const zSTRING& t_pointName)
	{
		if (!t_npc)
		{
			return;
		}

		static Utils::Logger* logger = Utils::CreateLogger("zDExt::Externals::AI_TurnToVob");
		zCVob* vob = FindVobByName(t_pointName, logger);
		if (!vob) {
			return;
		}

		auto msg = new oCMsgMovement(oCMsgMovement::EV_TURNTOPOS, vob->GetPositionWorld());
		t_npc->GetEM()->OnMessage(msg, t_npc);
	}

	void AI_TurnToPos(oCNpc* t_npc, const int t_posX, const int t_posY, const int t_posZ)
	{
		if (!t_npc)
		{
			return;
		}

		auto pos = zVEC3((float)t_posX, (float)t_posY, (float)t_posZ);
		auto msg = new oCMsgMovement(oCMsgMovement::EV_TURNTOPOS, pos);
		t_npc->GetEM()->OnMessage(msg, t_npc);
	}

	void AI_CallFunction(const zSTRING& t_funcName, oCNpc* t_self, oCNpc* t_other)
	{
		if (!t_self || !t_other)
		{
			return;
		}

		zSTRING funcName{ t_funcName };
		funcName.Upper();

		int funcIdx = parser->GetIndex(funcName);
		if (funcIdx <= 0)
		{
			return;
		}

		auto msg = new oCMsgManipulate(oCMsgManipulate::EV_CALLSCRIPT, t_other, funcIdx);
		t_self->GetEM()->OnMessage(msg, t_other);
	}
}
