Keress rá erre:
		bool bShowSalesText; -> (typedef struct SConfig)

Add hozzá ezt a végére:

#ifdef ENABLE_FOV_OPTION
		bool bExtendedFOV;
#endif

Keress rá:
void SetShowSalesTextFlag(int iFlag);

Add hozzá ezt:

#ifdef ENABLE_FOV_OPTION
	bool IsExtendedFOV();
	void SetExtendedFOV(int iFlag);
#endif