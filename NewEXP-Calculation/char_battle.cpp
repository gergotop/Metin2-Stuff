Keress rá erre: static void GiveExp(LPCHARACTER from, LPCHARACTER to, int iExp)

Cseréld le az egészet erre:

#ifdef ENABLE_NEWEXP_CALCULATION
#define NEW_GET_LVDELTA(me, victim) aiPercentByDeltaLev[MINMAX(0, (victim + 15) - me, MAX_EXP_DELTA_OF_LEV - 1)]
typedef long double rate_t;
static void GiveExp(LPCHARACTER from, LPCHARACTER to, int iExp)
{
	if (test_server && iExp < 0)
	{
		to->ChatPacket(CHAT_TYPE_INFO, "exp(%d) overflow", iExp);
		return;
	}
	// decrease/increase exp based on player<>mob level
	rate_t lvFactor = static_cast<rate_t>(NEW_GET_LVDELTA(to->GetLevel(), from->GetLevel())) / 100.0L;
	iExp *= lvFactor;
	// start calculating rate exp bonus
	int iBaseExp = iExp;
	rate_t rateFactor = 100;
	if (distribution_test_server)
		rateFactor *= 3;

	rateFactor += CPrivManager::instance().GetPriv(to, PRIV_EXP_PCT);
	if (to->IsEquipUniqueItem(UNIQUE_ITEM_LARBOR_MEDAL))
		rateFactor += 20;
	if (to->GetMapIndex() >= 660000 && to->GetMapIndex() < 670000)
		rateFactor += 20;
	if (to->GetPoint(POINT_EXP_DOUBLE_BONUS))
		if (number(1, 100) <= to->GetPoint(POINT_EXP_DOUBLE_BONUS))
			rateFactor += 30;
	if (to->IsEquipUniqueItem(UNIQUE_ITEM_DOUBLE_EXP))
		rateFactor += 50;

	switch (to->GetMountVnum())
	{
		case 20110:
		case 20111:
		case 20112:
		case 20113:
			if (to->IsEquipUniqueItem(71115) || to->IsEquipUniqueItem(71117) || to->IsEquipUniqueItem(71119) ||
					to->IsEquipUniqueItem(71121) )
			{
				rateFactor += 10;
			}
			break;

		case 20114:
		case 20120:
		case 20121:
		case 20122:
		case 20123:
		case 20124:
		case 20125:
			rateFactor += 30;
			break;
	}

	if (to->GetPremiumRemainSeconds(PREMIUM_EXP) > 0)
		rateFactor += 50;
	if (to->IsEquipUniqueGroup(UNIQUE_GROUP_RING_OF_EXP))
		rateFactor += 50;
	if (to->GetPoint(POINT_PC_BANG_EXP_BONUS) > 0)
	{
		if (to->IsPCBang())
			rateFactor += to->GetPoint(POINT_PC_BANG_EXP_BONUS);
	}
	rateFactor += to->GetMarriageBonus(UNIQUE_ITEM_MARRIAGE_EXP_BONUS);
	rateFactor += to->GetPoint(POINT_RAMADAN_CANDY_BONUS_EXP);
	rateFactor += to->GetPoint(POINT_MALL_EXPBONUS);
	rateFactor += to->GetPoint(POINT_EXP);
	// useless (never used except for china intoxication) = always 100
	rateFactor = rateFactor * static_cast<rate_t>(CHARACTER_MANAGER::instance().GetMobExpRate(to))/100.0L;
	// apply calculated rate bonus
	iExp *= (rateFactor/100.0L);
	if (test_server)
		to->ChatPacket(CHAT_TYPE_INFO, "base_exp(%d) * rate(%Lf) = exp(%d)", iBaseExp, rateFactor/100.0L, iExp);
	// you can get at maximum only 10% of the total required exp at once (so, you need to kill at least 10 mobs to level up) (useless)
	iExp = MIN(to->GetNextExp() / 10, iExp);
	// it recalculate the given exp if the player level is greater than the exp_table size (useless)
	iExp = AdjustExpByLevel(to, iExp);
	if (test_server)
		to->ChatPacket(CHAT_TYPE_INFO, "exp+minGNE+adjust(%d)", iExp);
#ifdef NEW_PET_SYSTEM
	if (to->GetNewPetSystem()) {
		if (to->GetNewPetSystem()->IsActivePet() && to->GetNewPetSystem()->GetLevelStep() < 4) {
			int tmpexp = iExp * 9 / 20;
			iExp = iExp - tmpexp;
			to->GetNewPetSystem()->SetExp(tmpexp, 0);
		}
	}
#endif
	// set
	to->PointChange(POINT_EXP, iExp, true);
	from->CreateFly(FLY_EXP, to);
	// marriage
	{
		LPCHARACTER you = to->GetMarryPartner();
		if (you)
		{
			// sometimes, this overflows
			DWORD dwUpdatePoint = (2000.0L/to->GetLevel()/to->GetLevel()/3)*iExp;

			if (to->GetPremiumRemainSeconds(PREMIUM_MARRIAGE_FAST) > 0 ||
					you->GetPremiumRemainSeconds(PREMIUM_MARRIAGE_FAST) > 0)
				dwUpdatePoint *= 3;

			marriage::TMarriage* pMarriage = marriage::CManager::instance().Get(to->GetPlayerID());

			// DIVORCE_NULL_BUG_FIX
			if (pMarriage && pMarriage->IsNear())
				pMarriage->Update(dwUpdatePoint);
			// END_OF_DIVORCE_NULL_BUG_FIX
		}
	}
}
#else
static void GiveExp(LPCHARACTER from, LPCHARACTER to, int iExp)
{
	// 레벨차 경험치 가감비율
	iExp = CALCULATE_VALUE_LVDELTA(to->GetLevel(), from->GetLevel(), iExp);

	// 외부 테스트 서버 경험치 3배 보너스
	if (distribution_test_server)
		iExp *= 3;

	int iBaseExp = iExp;

	// 점술, 회사 경험치 이벤트 적용
	iExp = iExp * (100 + CPrivManager::instance().GetPriv(to, PRIV_EXP_PCT)) / 100;

	// 게임내 기본 제공되는 경험치 보너스
	{
		// 노동절 메달
		if (to->IsEquipUniqueItem(UNIQUE_ITEM_LARBOR_MEDAL))
			iExp += iExp * 20 /100;

		// 사귀타워 경험치 보너스
		if (to->GetMapIndex() >= 660000 && to->GetMapIndex() < 670000) 
			iExp += iExp * 20 / 100; // 1.2배 (20%)

		// 아이템 경험치 두배 속성
		if (to->GetPoint(POINT_EXP_DOUBLE_BONUS))
			if (number(1, 100) <= to->GetPoint(POINT_EXP_DOUBLE_BONUS))
				iExp += iExp * 30 / 100; // 1.3배 (30%)

		// 경험의 반지 (2시간짜리)
		if (to->IsEquipUniqueItem(UNIQUE_ITEM_DOUBLE_EXP))
			iExp += iExp * 50 / 100;

		switch (to->GetMountVnum())
		{
			case 20110:
			case 20111:
			case 20112:
			case 20113:
				if (to->IsEquipUniqueItem(71115) || to->IsEquipUniqueItem(71117) || to->IsEquipUniqueItem(71119) ||
						to->IsEquipUniqueItem(71121) )
				{
					iExp += iExp * 10 / 100;
				}
				break;

			case 20114:
			case 20120:
			case 20121:
			case 20122:
			case 20123:
			case 20124:
			case 20125:
				// 백사자 경험치 보너스
				iExp += iExp * 30 / 100;
				break;
		}
	}

	// 아이템 몰 판매 경험치 보너스
	if (LC_IsHongKong() || LC_IsEurope() || LC_IsCanada())
	{
		// 아이템 몰: 경험치 결제
		if (to->GetPremiumRemainSeconds(PREMIUM_EXP) > 0)
		{
			iExp += (iExp * 50 / 100);
		}

		if (to->IsEquipUniqueGroup(UNIQUE_GROUP_RING_OF_EXP) == true)
		{
			iExp += (iExp * 50 / 100);
		}

		// PC방 아템 경치 보너스
		if (to->GetPoint(POINT_PC_BANG_EXP_BONUS) > 0)
		{
			if (to->IsPCBang() == true)
				iExp += (iExp * to->GetPoint(POINT_PC_BANG_EXP_BONUS)/100);
		}

		// 결혼 보너스
		iExp += iExp * to->GetMarriageBonus(UNIQUE_ITEM_MARRIAGE_EXP_BONUS) / 100;
	}
	else if (/*LC_IsNewCIBN() || */LC_IsBrazil())
	{
		// 아이템 몰: 경험치 결제
		if (to->GetPremiumRemainSeconds(PREMIUM_EXP) > 0)
		{
			iExp += iExp;
		}

		if (to->IsEquipUniqueGroup(UNIQUE_GROUP_RING_OF_EXP) == true)
		{
			iExp += iExp;
		}

		// PC방 아템 경치 보너스
		if (to->GetPoint(POINT_PC_BANG_EXP_BONUS) > 0)
		{
			if (to->IsPCBang() == true)
				iExp += (iExp * to->GetPoint(POINT_PC_BANG_EXP_BONUS)/100);
		}

		// 결혼 보너스
		iExp += iExp * to->GetMarriageBonus(UNIQUE_ITEM_MARRIAGE_EXP_BONUS) / 100;
	}
	else
	{
		// 아이템 몰: 경험치 결제
		if (to->GetPremiumRemainSeconds(PREMIUM_EXP) > 0)
		{
			iExp += (iExp * 20 / 100);
		}

		if (to->IsEquipUniqueGroup(UNIQUE_GROUP_RING_OF_EXP) == true)
		{
			iExp += (iExp * 20 / 100);
		}

		// PC방 아템 경치 보너스
		if (to->GetPoint(POINT_PC_BANG_EXP_BONUS) > 0)
		{
			if (to->IsPCBang() == true)
				iExp += (iExp * to->GetPoint(POINT_PC_BANG_EXP_BONUS)/100);
		}

		// 결혼 보너스
		iExp += iExp * to->GetMarriageBonus(UNIQUE_ITEM_MARRIAGE_EXP_BONUS) / 100;
	}

	iExp += (iExp * to->GetPoint(POINT_RAMADAN_CANDY_BONUS_EXP)/100);
	iExp += (iExp * to->GetPoint(POINT_MALL_EXPBONUS)/100);
	iExp += (iExp * to->GetPoint(POINT_EXP)/100);

/*	if (speed_server)
	{
		iExp += iExp * CSpeedServerManager::ExpBonus();

	}
*/
	if (test_server)
	{
		sys_log(0, "Bonus Exp : Ramadan Candy: %d MallExp: %d PointExp: %d", 
				to->GetPoint(POINT_RAMADAN_CANDY_BONUS_EXP),
				to->GetPoint(POINT_MALL_EXPBONUS),
				to->GetPoint(POINT_EXP)
			   );
	}

	// 기획측 조정값 2005.04.21 현재 85%
	iExp = iExp * CHARACTER_MANAGER::instance().GetMobExpRate(to) / 100;

	// 경험치 한번 획득량 제한
	iExp = MIN(to->GetNextExp() / 10, iExp);

	if (test_server)
	{
		if (quest::CQuestManager::instance().GetEventFlag("exp_bonus_log") && iBaseExp>0)
			to->ChatPacket(CHAT_TYPE_INFO, "exp bonus %d%%", (iExp-iBaseExp)*100/iBaseExp);
	}

	iExp = AdjustExpByLevel(to, iExp);

/*#ifdef NEW_PET_SYSTEM
	if (to->GetNewPetSystem()) {
		if (to->GetNewPetSystem()->IsActivePet() && to->GetNewPetSystem()->GetLevelStep() < 4) {
			int tmpexp = iExp * 9 / 20;
			iExp = iExp - tmpexp;
			to->GetNewPetSystem()->SetExp(tmpexp, 0);
		}
	}
#endif*/

	to->PointChange(POINT_EXP, iExp, true);
	from->CreateFly(FLY_EXP, to);

	{
		LPCHARACTER you = to->GetMarryPartner();
		// 부부가 서로 파티중이면 금슬이 오른다
		if (you)
		{
			// 1억이 100%
			DWORD dwUpdatePoint = 2000*iExp/to->GetLevel()/to->GetLevel()/3;

			if (to->GetPremiumRemainSeconds(PREMIUM_MARRIAGE_FAST) > 0 || 
					you->GetPremiumRemainSeconds(PREMIUM_MARRIAGE_FAST) > 0)
				dwUpdatePoint = (DWORD)(dwUpdatePoint * 3);

			marriage::TMarriage* pMarriage = marriage::CManager::instance().Get(to->GetPlayerID());

			// DIVORCE_NULL_BUG_FIX
			if (pMarriage && pMarriage->IsNear())
				pMarriage->Update(dwUpdatePoint);
			// END_OF_DIVORCE_NULL_BUG_FIX
		}
	}
}
#endif


