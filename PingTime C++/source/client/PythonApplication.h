//Suchen
		DWORD GetRenderFPS()		{ return m_dwRenderFPS; }

//Darunter hinzufugen
#ifdef ENABLE_PINGTIME
		DWORD GetPingTime()		{ return m_dwPingTime; }
#endif

//Suchen
DWORD						m_dwFaceCount;

//Darunter hinzufugen
#ifdef ENABLE_PINGTIME
		DWORD						m_dwPingTime;
#endif