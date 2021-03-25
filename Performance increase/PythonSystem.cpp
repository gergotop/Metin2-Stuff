// keresd

	m_Config.bShowSalesText		= true;

// add alá

#ifdef ENABLE_DOG_MODE
	m_Config.bDogMode = false;
#endif

// keresd

		else if (!stricmp(command, "SHOW_SALESTEXT"))
			m_Config.bShowSalesText = atoi(value) == 1 ? true : false;

// add alá

#ifdef ENABLE_DOG_MODE
		else if (!stricmp(command, "DOG_MODE_ON"))
			m_Config.bDogMode = atoi(value) == 1 ? true : false;
#endif

// keresd

	fprintf(fp, "\n");

	fclose(fp);
	return true;

// add felé

#ifdef ENABLE_DOG_MODE
	fprintf(fp, "DOG_MODE_ON			%d\n", m_Config.bDogMode);
#endif

// add hozzá alatta mint funkció

#ifdef ENABLE_DOG_MODE
void CPythonSystem::SetDogMode(int iFlag)
{
	m_Config.bDogMode = iFlag == 1 ? true : false;

	CPythonCharacterManager& rkChrMgr = CPythonCharacterManager::Instance();
	rkChrMgr.SetDogMode(m_Config.bDogMode);
}

bool CPythonSystem::GetDogMode()
{
	return m_Config.bDogMode;
}
#endif
