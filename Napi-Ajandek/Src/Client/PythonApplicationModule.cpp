//Find:
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

//Add under:
#ifdef ENABLE_DAILY_REWARD
	PyModule_AddIntConstant(poModule, "ENABLE_DAILY_REWARD", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_DAILY_REWARD", 0);
#endif
