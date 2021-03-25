// Keress rá erre:

	public:
		void SetShow(bool bIsShow) { m_bIsShow = bIsShow; }

// Add hozzá alá:

#ifdef ENABLE_DOG_MODE
	public:
		DWORD GetOriginalRace();
		void SetOriginalRace(DWORD race);
		void ChangeRace(DWORD eRace, DWORD eShape);

	protected:
		DWORD m_dwOriginalRace;
#endif