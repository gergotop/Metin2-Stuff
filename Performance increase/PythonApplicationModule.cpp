#ifdef ENABLE_DOG_MODE
	PyModule_AddIntConstant(poModule, "ENABLE_DOG_MODE", 1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_DOG_MODE", 0);
#endif