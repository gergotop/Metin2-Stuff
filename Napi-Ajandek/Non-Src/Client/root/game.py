[...]
if app.ENABLE_DAILY_REWARD:
	import uidailyreward

[...]

class GameWindow(ui.ScriptWindow):
	def __init__(self, stream):
		[...]
			
		if app.ENABLE_DAILY_REWARD:
			self.dailyReward = None

		[...]
	
		if app.ENABLE_DAILY_REWARD:
			self.dailyReward = uidailyreward.DailyRewardWindow()
			self.dailyReward.Hide()

		[...]

	def __del__(self):
		player.SetGameWindow(0)
		net.ClearPhaseWindow(net.PHASE_WINDOW_GAME, self)
		ui.ScriptWindow.__del__(self)

	[...]

	def Close(self):
		[...]
			
		if app.ENABLE_DAILY_REWARD and self.dailyReward:
			self.dailyReward.Destroy()
			self.dailyReward = None

		[...]

	[...]
	
	def __ServerCommand_Build(self):
		serverCommandList={
			[...]
			"dailyReward_open"	: self.dailyReward.Open, #ENABLE_DAILY_REWARD
			"dailyReward_set_reward"	: self.dailyReward.SetReward,
			[...]
		}

		[...]
		
	[...]