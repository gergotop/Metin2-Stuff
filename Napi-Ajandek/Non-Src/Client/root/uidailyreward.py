import ui
import event
import constInfo
import app
import uiCommon
import chat
import net
import playerSettingModule
import player
import localeInfo
import wndMgr


class DailyRewardWindow(ui.ScriptWindow):
	def __init__(self):
		ui.ScriptWindow.__init__(self)
		self.__LoadWindow()
	
	def __del__(self):
		ui.ScriptWindow.__del__(self)
		
	def __LoadWindow(self):
		try:
			PythonScriptLoader = ui.PythonScriptLoader()
			PythonScriptLoader.LoadScriptFile(self, "UIScript/dailyrewardwindow.py")
		except:
			import exception
			exception.Abort("DailyReward.LoadWindow.LoadObject")
			
		try:
			self.__BindObjects()
		except:
			import exception
			exception.Abort("DailyReward.LoadWindow.BindObject")
		
		self.__BindEvents()
	
	def __BindObjects(self):
		self.titlebar = self.GetChild("TitleBar")
		
		self.rewardSlot = self.GetChild("RewardSlot")
		self.giftButton = self.GetChild("GiftButton")


	def __BindEvents(self):
		self.titlebar.SetCloseEvent(ui.__mem_func__(self.Close))
		
		self.giftButton.SetEvent(ui.__mem_func__(self.OpenGift))

	def SetReward(self, vnum, count):
		self.rewardSlot.SetItemSlot(0, int(vnum), int(count))
	
	def OpenGift(self):
		net.SendChatPacket("/dailyreward_process")
		self.giftButton.Hide()

	def Open(self):
		self.SetCenterPosition()
		self.SetTop()
		self.Show()

	def OnPressEscapeKey(self):
		self.Close()
		return True
	
	def Close(self):
		self.rewardSlot.SetItemSlot(0, 0, 0)
		self.giftButton.Show()
		self.Hide()
		return True
		
	def Destroy(self):
		self.Close()
		self.ClearDictionary()
