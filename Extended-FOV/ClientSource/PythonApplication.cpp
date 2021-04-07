Keress rá:

void CPythonApplication::RenderGame()
{
	if (!PERF_CHECKER_RENDER_GAME)
	{
		float fAspect=m_kWndMgr.GetAspect();
		float fFarClip=m_pyBackground.GetFarClip();
		m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE, fAspect, 100.0, fFarClip);

Így nézzen ki:

void CPythonApplication::RenderGame()
{
	if (!PERF_CHECKER_RENDER_GAME)
	{
		float fAspect=m_kWndMgr.GetAspect();
		float fFarClip=m_pyBackground.GetFarClip();

#ifdef ENABLE_FOV_OPTION
		if (CPythonSystem::instance().IsExtendedFOV())
			m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE * 2.5, fAspect, 100.0, fFarClip);
		else
			m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE, fAspect, 100.0, fFarClip);
#else
		m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE, fAspect, 100.0, fFarClip);
#endif

Keress rá:
float fFarClip=m_pyBackground.GetFarClip();
m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE, fAspect, 100.0, fFarClip);

Így nézzen ki:

#ifdef ENABLE_FOV_OPTION
	if (CPythonSystem::instance().IsExtendedFOV())
		m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE * 2.5, fAspect, 100.0, fFarClip);
	else
		m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE, fAspect, 100.0, fFarClip);
#else
	m_pyGraphic.SetPerspective(CAMERA_PERSPECTIVE, fAspect, 100.0, fFarClip);
#endif

Keress rá:
float fFarClip = CPythonBackground::Instance().GetFarClip();
s.SetPerspective(30.0f, fAspect, 100.0f, fFarClip);

Így nézzen ki:

#ifdef ENABLE_FOV_OPTION
		if (CPythonSystem::instance().IsExtendedFOV())
			s.SetPerspective(CAMERA_PERSPECTIVE * 2.5, fAspect, 100.0f, fFarClip);
		else
			s.SetPerspective(CAMERA_PERSPECTIVE, fAspect, 100.0f, fFarClip);
#else
		s.SetPerspective(30.0f, fAspect, 100.0f, fFarClip);
#endif


