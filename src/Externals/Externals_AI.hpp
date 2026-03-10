namespace GOTHIC_NAMESPACE
{
	void AI_TurnToWP(oCNpc* t_npc, const zSTRING& t_pointName)
	{
		if (!t_npc || t_pointName.IsEmpty()) {
			return;
		}

		static auto log = Utils::CreateLogger("zDExt::Externals::AI_TurnToWP");

		zSTRING pointName = zSTRING(t_pointName).Upper();
		zCWorld* world = ogame->GetGameWorld();
		zCWaypoint* wp = world->wayNet->GetWaypoint(pointName);

		if (wp)
		{
			t_npc->GetEM(0)->OnMessage(new oCMsgMovement(oCMsgMovement::EV_TURNTOPOS, wp->GetPositionWorld()), t_npc);
			return;
		}

		log->Warning("No Waypoint found with specified name: {0}. Looking for Vob...", pointName.ToChar());
		zCVob* vob = FindVobByName(t_pointName, log);

		if (!vob) {
			return;
		}

		t_npc->GetEM(0)->OnMessage(new oCMsgMovement(oCMsgMovement::EV_TURNTOPOS, vob->GetPositionWorld()), t_npc);
	}

	void AI_TurnToVob(oCNpc* t_npc, const zSTRING& t_pointName)
	{
		if (!t_npc || t_pointName.IsEmpty()) {
			return;
		}

		static auto log = Utils::CreateLogger("zDExt::Externals::AI_TurnToVob");

		zCVob* vob = FindVobByName(t_pointName, log);
		if (!vob) {
			return;
		}

		t_npc->GetEM(0)->OnMessage(new oCMsgMovement(oCMsgMovement::EV_TURNTOPOS, vob->GetPositionWorld()), t_npc);
	}

	void AI_CallFunction(const zSTRING& t_funcName, oCNpc* t_self, oCNpc* t_other)
	{
		if (!t_self || !t_other || t_funcName.IsEmpty()) {
			return;
		}

		zSTRING eventName = zSTRING(t_funcName).Upper();
		int function = parser->GetIndex(eventName);
		if (function <= 0) {
			return;
		}

		t_self->GetEM(0)->OnMessage(new oCMsgManipulate(oCMsgManipulate::EV_CALLSCRIPT, t_other, function), t_other);
	}
}
