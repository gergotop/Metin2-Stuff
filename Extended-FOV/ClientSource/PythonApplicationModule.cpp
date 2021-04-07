#if defined(ENABLE_FOV_OPTION)
	PyModule_AddIntConstant(poModule, "ENABLE_FOV_OPTION", true);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_FOV_OPTION", false);
#endif