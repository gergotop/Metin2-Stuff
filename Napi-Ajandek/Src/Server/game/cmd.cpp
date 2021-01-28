[...]
#ifdef ENABLE_DAILY_REWARD
ACMD(do_dailyreward_open);
ACMD(do_dailyreward_process);
#endif

[...]

struct command_info cmd_info[] =
{
	[...]
#ifdef ENABLE_DAILY_REWARD
	{ "dailyreward_open",	do_dailyreward_open,	0,	POS_DEAD,	GM_PLAYER	},
	{ "dailyreward_process",		do_dailyreward_process,			0,	POS_DEAD,	GM_PLAYER	},	
#endif
	[...]
	{ "\n",		NULL,			0,			POS_DEAD,	GM_IMPLEMENTOR	}  /* 반드시 이 것이 마지막이어야 한다. */
};

[...]