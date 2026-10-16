namespace GOTHIC_NAMESPACE
{
	void zDExt_AI_TurnToWP(oCNpc* t_npc, const zSTRING& t_pointName)
	{
		if (!t_npc)
		{
			return;
		}

		static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::AI_TurnToWP");
		auto pos = GetWaypointPosition(t_pointName, logger);
		auto const msg = new oCMsgMovement(oCMsgMovement::EV_TURNTOPOS, pos.value());
		t_npc->GetEM()->OnMessage(msg, t_npc);
	}

	void zDExt_AI_TurnToVob(oCNpc* t_npc, const zSTRING& t_pointName)
	{
		if (!t_npc)
		{
			return;
		}

		static zDUtils::Logger* logger = zDUtils::CreateLogger("zDExtensions::AI_TurnToVob");
		zCVob* vob = FindVobByName(t_pointName, logger);
		if (!vob) {
			return;
		}

		auto const msg = new oCMsgMovement(oCMsgMovement::EV_TURNTOPOS, vob->GetPositionWorld());
		t_npc->GetEM()->OnMessage(msg, t_npc);
	}

	void zDExt_AI_TurnToPos(oCNpc* t_npc, const float t_posX, const float t_posY, const float t_posZ)
	{
		if (!t_npc)
		{
			return;
		}

		auto pos = zVEC3(t_posX, t_posY, t_posZ);
		auto const msg = new oCMsgMovement(oCMsgMovement::EV_TURNTOPOS, pos);
		t_npc->GetEM()->OnMessage(msg, t_npc);
	}

	void zDExt_AI_CallFunction(oCNpc* t_npc, const BetterDaedalusExternals::DaedalusFunctionType t_function)
	{
		if (!t_npc)
		{
			return;
		}

		auto const msg = new oCMsgManipulate(oCMsgManipulate::EV_CALLSCRIPT, "", t_function.m_index);
		t_npc->GetEM()->OnMessage(msg, t_npc);
	}
}
