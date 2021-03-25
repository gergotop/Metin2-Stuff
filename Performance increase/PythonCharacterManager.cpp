// Add hozzá ezt a funkciót

#ifdef ENABLE_DOG_MODE
void CPythonCharacterManager::SetDogMode(bool bStatus)
{
	CInstanceBase* pMainInstance = GetMainInstancePtr();

	for (auto& it : m_kAliveInstMap)
	{
		CInstanceBase* pInstance = it.second;
		const CPythonNonPlayer::TMobTable* pMobTable = CPythonNonPlayer::Instance().GetTable(pInstance->GetRace());
		if (pInstance && pMainInstance && pMainInstance != pInstance && (pInstance->IsEnemy() || pInstance->IsStone()) && pMobTable && pMobTable->bRank < 4)
		{
			if ((bStatus))
			{
				if (pInstance->GetOriginalRace() == pInstance->GetRace() && pInstance->GetRace() != 101)
					pInstance->ChangeRace(101, 0);
			}
			else
			{
				if (pInstance->GetRace() == 101 && pInstance->GetOriginalRace() != pInstance->GetRace())
				{
					pInstance->SetRace(pInstance->GetOriginalRace());
					pInstance->GetGraphicThingInstancePtr()->SetShape(0, 0.0f);
					pInstance->GetGraphicThingInstancePtr()->RefreshActorInstance();
					pInstance->Refresh(CRaceMotionData::NAME_WAIT, false);
				}
			}
		}
	}
}

#endif