//Suchen
#include "CheckLatestFiles.h"

//Darunter hinzufugen.
#ifdef ENABLE_PINGTIME
#include "PingManager.h"
#endif

//Suchen
CPythonApplication::CPythonApplication() :

//Unter >> m_dwRenderFPS(0), hinzufugen.
#ifdef ENABLE_PINGTIME
m_dwPingTime(0),
#endif

//Suchen
bool CPythonApplication::Process()

//Unter >> if (ELTimer_GetMSec() - s_dwCheckTime > 1000) hinzufugen.
#ifdef ENABLE_PINGTIME
	static DWORD	s_dwPingTime = 0;
	static DWORD	s_dwCheckTime2 = ELTimer_GetMSec();

	if (ELTimer_GetMSec() - s_dwCheckTime2 > 5000)
	{
		
		CPingManager CPingManager;
		m_dwPingTime = CPingManager.PingTimeRev();
		s_dwCheckTime2 = ELTimer_GetMSec();
	}
#endif