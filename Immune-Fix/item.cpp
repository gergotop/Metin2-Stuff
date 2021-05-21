Keress rá erre bool CItem::EquipTo(LPCHARACTER ch, BYTE bWearCell) majd ezen belül pedig erre: for (int i = 0; i < WEAR_MAX_NUM; ++i)

Az egész for ciklust cseréld le, hogy így nézzen ki:

#ifdef __IMMUNE_FIX__
	for (int i = 0; i < WEAR_MAX_NUM; ++i)
	{
		if (item = m_pOwner->GetWear(i))
		{
			if (item->GetImmuneFlag() != 0)
				SET_BIT(dwImmuneFlag, m_pOwner->GetWear(i)->GetRealImmuneFlag());
			if (item->GetAttributeCount() > 0)
			{
				if (item->HasAttr(APPLY_IMMUNE_STUN))
					SET_BIT(dwImmuneFlag, IMMUNE_STUN);
				if (item->HasAttr(APPLY_IMMUNE_SLOW))
					SET_BIT(dwImmuneFlag, IMMUNE_SLOW);
				if (item->HasAttr(APPLY_IMMUNE_FALL))
					SET_BIT(dwImmuneFlag, IMMUNE_FALL);
			}
		}
	}

	m_pOwner->SetImmuneFlag(dwImmuneFlag);
#else
	for (int i = 0; i < WEAR_MAX_NUM; ++i)
	{
		if (item = m_pOwner->GetWear(i))
		{
			if (item->GetImmuneFlag() != 0)
				SET_BIT(dwImmuneFlag, item->GetImmuneFlag());
			if (item->GetAttributeCount() > 0)
			{
				if (item->HasAttr(APPLY_IMMUNE_STUN))
					SET_BIT(dwImmuneFlag, IMMUNE_STUN);
				if (item->HasAttr(APPLY_IMMUNE_SLOW))
					SET_BIT(dwImmuneFlag, IMMUNE_SLOW);
				if (item->HasAttr(APPLY_IMMUNE_FALL))
					SET_BIT(dwImmuneFlag, IMMUNE_FALL);
			}
		}
	}

	m_pOwner->SetImmuneFlag(dwImmuneFlag);
#endif