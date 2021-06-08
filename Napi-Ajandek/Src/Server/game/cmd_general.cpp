[...]
#ifdef ENABLE_DAILY_REWARD
ACMD(do_dailyreward_open)
{
	if (!ch)
		return;
	
	if (ch->GetQuestFlag("daily_reward.can_open_dreward") < get_global_time())
	{
		ch->ChatPacket(CHAT_TYPE_COMMAND, "dailyReward_open");
	}
	else
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("daily_reward_not_yet")); //<- hu_string (locale_string)
		return;
	}
}

ACMD(do_dailyreward_process)
{
	if (!ch)
		return;
	
	int REWARDS[][2] = { //int REWARDS[] [JUTALMAK SZÁMA] = {. 
		{30006, 1}, // {Tárgy ID, Mennyiség}
		{30007, 1}, // {Tárgy ID, Mennyiség}
	};
	
	if (ch->GetQuestFlag("daily_reward.can_open_dreward") < get_global_time())
	{
		int random = number(0, sizeof(REWARDS)/sizeof(*REWARDS)-1);
		
		int dr_vnum = REWARDS[random][0];
		int dr_vnum_count = REWARDS[random][1];	

		ch->SetQuestFlag("daily_reward.can_open_dreward", get_global_time()+86400);
		ch->ChatPacket(CHAT_TYPE_COMMAND, "dailyReward_set_reward %i %i", dr_vnum, dr_vnum_count);
		ch->AutoGiveItem(dr_vnum, dr_vnum_count);
	}
	else
	{
		ch->ChatPacket(CHAT_TYPE_INFO, LC_TEXT("daily_reward_not_yet"));
		return;
	}
}
#endif

[...]