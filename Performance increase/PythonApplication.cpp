// Keress rá erre:

#ifdef __PERFORMANCE_CHECK__
	DWORD dwUpdateTime10=ELTimer_GetMSec();

// add hozzá felette

#ifdef ENABLE_DOG_MODE
	if (CPythonSystem::Instance().GetDogMode())
		m_kChrMgr.SetDogMode(CPythonSystem::Instance().GetDogMode());
#endif