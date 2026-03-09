namespace GOTHIC_NAMESPACE
{
	inline constexpr const char* DAEDALUS_CALL_FAILED_MSG = "Failed to call {0}: {1}";

	inline const char* CallErrorToString(eCallFuncError t_error)
	{
		switch (t_error)
		{
		case eCallFuncError::WRONG_SYMBOL:    return "Function not found";
		case eCallFuncError::WRONG_ARGS_SIZE: return "Invalid number of arguments";
		case eCallFuncError::WRONG_ARG_TYPE:  return "Invalid argument type";
		case eCallFuncError::WRONG_RET_VAL:   return "Invalid return type";
		default:                              return "Unknown error";
		}
	}
}
