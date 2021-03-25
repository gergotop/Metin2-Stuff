// keresd

void initsystemSetting()

// add alá

#ifdef ENABLE_DOG_MODE
PyObject* systemSetDogMode(PyObject* poSelf, PyObject* poArgs)
{
	int iFlag;
	if (!PyTuple_GetInteger(poArgs, 0, &iFlag))
		return Py_BuildException();

	CPythonSystem::Instance().SetDogMode(iFlag);

	return Py_BuildNone();
}

PyObject* systemGetDogMode(PyObject* poSelf, PyObject* poArgs)
{
	return Py_BuildValue("i", CPythonSystem::Instance().GetDogMode());
}
#endif

// keresd

		{ NULL,							NULL,							NULL }
	};

// add hozzá felette

#ifdef ENABLE_DOG_MODE
		{ "SetDogMode",				systemSetDogMode,				METH_VARARGS },
		{ "GetDogMode",				systemGetDogMode,				METH_VARARGS },
#endif