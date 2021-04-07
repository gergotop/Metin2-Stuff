//Suchen
static std::string gs_stServerInfo;

//Daruber hinzufugen
#ifdef ENABLE_PINGTIME
const char * global_ip;
#endif

//Suchen
PyObject* netConnectToAccountServer(PyObject* poSelf, PyObject* poArgs)

//Abandern (Beispiel)
PyObject* netConnectToAccountServer(PyObject* poSelf, PyObject* poArgs)
{
	char* addr;
	if (!PyTuple_GetString(poArgs, 0, &addr))
		return Py_BuildException();

	int port;
	if (!PyTuple_GetInteger(poArgs, 1, &port))
		return Py_BuildException();

	char* account_addr;
	if (!PyTuple_GetString(poArgs, 2, &account_addr))
		return Py_BuildException();

	int account_port;
	if (!PyTuple_GetInteger(poArgs, 3, &account_port))
		return Py_BuildException();

#ifdef ENABLE_PINGTIME
	global_ip = addr;
#endif
	
	CAccountConnector & rkAccountConnector = CAccountConnector::Instance();
	rkAccountConnector.Connect(addr, port, account_addr, account_port);

	return Py_BuildNone();
}