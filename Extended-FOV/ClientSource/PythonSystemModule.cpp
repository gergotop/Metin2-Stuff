Keress rá erre:

PyObject * systemSetShadowLevel(PyObject * poSelf, PyObject * poArgs)
{
	int level;

	if (!PyTuple_GetInteger(poArgs, 0, &level))
		return Py_BuildException();

	if (level > 0)
		CPythonSystem::Instance().SetShadowLevel(level);

	return Py_BuildNone();
}

Add alá:

#ifdef ENABLE_FOV_OPTION
PyObject* systemSetExtendedFOV(PyObject* poSelf, PyObject* poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();
	CPythonSystem::Instance().SetExtendedFOV(iFlag);
	return Py_BuildNone();
}

PyObject* systemIsExtendedFOV(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().IsExtendedFOV());
}
#endif

Keress rá:

{ "SetShadowLevel", systemSetShadowLevel, METH_VARARGS },

Alá:

#ifdef ENABLE_FOV_OPTION
		{ "SetExtendedFOV",	systemSetExtendedFOV, METH_VARARGS },
		{ "IsExtendedFOV", systemIsExtendedFOV, METH_VARARGS },
#endif