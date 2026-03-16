namespace GOTHIC_NAMESPACE
{
	int Cast_InstanceIsVob(zCObject* t_instance)
	{
		if (!t_instance)
		{
			return 0;
		}

		return (int)(t_instance->CastTo<zCVob>());
	}
}
