namespace GOTHIC_NAMESPACE
{
	static void AI_TurnToWP(oCNpc* t_npc, const zSTRING& t_pointName)
	{
		if (!t_npc || t_pointName.IsEmpty())
			return;

		static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::AI_TurnToWP");

		zSTRING pointName = zSTRING(t_pointName).Upper();
		zCWorld* world = ogame->GetGameWorld();
		zCWaypoint* wp = world->wayNet->GetWaypoint(pointName);

		if (wp)
		{
			t_npc->GetEM(0)->OnMessage(new oCMsgMovement(oCMsgMovement::EV_TURNTOVOB, (zCVob*)wp), t_npc);
			return;
		}

		log->Warning("No Waypoint found with specified name: {0}. Looking for Vob...", pointName.ToChar());
		zCVob* vob = FindVobByName(t_pointName, log);

		if (!vob) return;

		t_npc->GetEM(0)->OnMessage(new oCMsgMovement(oCMsgMovement::EV_TURNTOVOB, vob), t_npc);
	}

	static void AI_TurnToVob(oCNpc* t_npc, const zSTRING& t_pointName)
	{
		if (!t_npc || t_pointName.IsEmpty())
			return;

		static Utils::Logger* log = Utils::CreateLogger("zDExt::Externals::AI_TurnToVob");

		zCVob* vob = FindVobByName(t_pointName, log);

		if (!vob) return;

		t_npc->GetEM(0)->OnMessage(new oCMsgMovement(oCMsgMovement::EV_TURNTOVOB, vob), t_npc);
	}
}