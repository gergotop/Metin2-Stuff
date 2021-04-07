Keress rá erre: 
void CPythonSystem::SetDefaultConfig()

És az aljára másold be ezt:
#ifdef ENABLE_FOV_OPTION
	m_Config.bExtendedFOV = false;
#endif


Keress rá erre:
bool CPythonSystem::IsAutoTiling()
{
	if (m_Config.bSoftwareTiling == 0)
		return true;

	return false;
}

Alá:
#ifdef ENABLE_FOV_OPTION
bool CPythonSystem::IsExtendedFOV()
{
	return m_Config.bExtendedFOV;
}
void CPythonSystem::SetExtendedFOV(int iFlag)
{
	m_Config.bExtendedFOV = iFlag == 1 ? true : false;
}
#endif


Keress rá erre:
		else if (!stricmp(command, "SHOW_SALESTEXT"))
			m_Config.bShowSalesText = atoi(value) == 1 ? true : false;

Add hozzá ezt:
#ifdef ENABLE_FOV_OPTION
		else if (!stricmp(command, "EXTENDED_FOV"))
			m_Config.bExtendedFOV = atoi(value) == 1 ? true : false;
#endif

Keress rá erre:
	if (m_Config.bShowSalesText == 0)
		fprintf(fp, "SHOW_SALESTEXT			%d\n", m_Config.bShowSalesText);

Add hozzá ezt:
#ifdef ENABLE_FOV_OPTION
	fprintf(fp, "EXTENDED_FOV				%d\n", m_Config.bExtendedFOV);
#endif

Keress rá erre:
	m_Config.bShowSalesText = true; -> (void CPythonSystem::SetDefaultConfig())

Add hozzá ezt a végére:
#ifdef ENABLE_FOV_OPTION
	m_Config.bExtendedFOV = false;
#endif


