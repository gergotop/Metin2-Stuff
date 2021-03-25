// Keress rá erre:

bool CInstanceBase::Create(const SCreateData& c_rkCreateData)
{
	IAbstractApplication::GetSingleton().SkipRenderBuffering(300);

	SetInstanceType(c_rkCreateData.m_bType);

	if (!SetRace(c_rkCreateData.m_dwRace))
		return false;


// Add hozzá ezt:

#ifdef ENABLE_DOG_MODE
	SetOriginalRace(c_rkCreateData.m_dwRace);
#endif

// Keress rá erre:

	m_dwEmoticonTime = 0;

// Add alá ezt:

#ifdef ENABLE_DOG_MODE
	m_dwOriginalRace = 0;
#endif

// Keress rá erre:

void CInstanceBase::SpecialEffectCheck(bool isWeapon)

// } után add hozzá :

#ifdef ENABLE_DOG_MODE
DWORD CInstanceBase::GetOriginalRace()
{
	return m_dwOriginalRace;
}

void CInstanceBase::SetOriginalRace(DWORD race)
{
	m_dwOriginalRace = race;
}

void CInstanceBase::ChangeRace(DWORD eRace, DWORD eShape)
{
	m_dwRace = eRace;

	if (!m_GraphicThingInstance.SetRace(eRace))
		return;

	m_GraphicThingInstance.SetShape(eShape, 0.0f);

	m_GraphicThingInstance.RefreshActorInstance();
	Refresh(CRaceMotionData::NAME_WAIT, false);
}
#endif