//Suchen
PyObject * appGetRenderFPS(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonApplication::Instance().GetRenderFPS());
}

//Darunter hinzufugen
#ifdef ENABLE_PINGTIME
PyObject * appGetPingTime(PyObject * poSelf, PyObject * poArgs)
{
	return Py_BuildValue("i", CPythonApplication::Instance().GetPingTime());
}
#endif

//Suchen
		{ "GetRenderFPS",				appGetRenderFPS,				METH_VARARGS },
		
//Darunter hinzufugen
#ifdef ENABLE_PINGTIME
		{ "GetPingTime",				appGetPingTime,					METH_VARARGS },
#endif

//Suchen
#ifdef ENABLE_NEW_EQUIPMENT_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_NEW_EQUIPMENT_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_NEW_EQUIPMENT_SYSTEM",	0);
#endif

//Darunter hinzufugen
#ifdef ENABLE_PINGTIME
	PyModule_AddIntConstant(poModule, "ENABLE_PINGTIME",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_PINGTIME",	0);
#endif