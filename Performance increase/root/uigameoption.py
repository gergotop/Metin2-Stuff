# keresd

		self.RefreshShowSalesText()

# add alá

		if app.ENABLE_DOG_MODE:
			self.RefreshDogMode()

# keresd

		self.showsalesTextButtonList = []

# add alá

		if app.ENABLE_DOG_MODE:
			self.dogModeButtonList = []

# keresd

			self.showsalesTextButtonList.append(GetObject("salestext_off_button"))

# add alá

			if app.ENABLE_DOG_MODE:
				self.dogModeButtonList.append(GetObject("dog_mode_open"))
				self.dogModeButtonList.append(GetObject("dog_mode_close"))

# keresd

		#global MOBILE
		if MOBILE:
			self.inputMobileButton.SetEvent(ui.__mem_func__(self.__OnChangeMobilePhoneNumber))
			self.deleteMobileButton.SetEvent(ui.__mem_func__(self.__OnDeleteMobilePhoneNumber))

# add alá

		if app.ENABLE_DOG_MODE:
			self.dogModeButtonList[0].SAFE_SetEvent(self.__OnClickDogButton)
			self.dogModeButtonList[1].SAFE_SetEvent(self.__OffClickDogButton)

# keresd

	def Refresh(self):

# add hozzá

		if app.ENABLE_DOG_MODE:
			self.RefreshDogMode()

# def refresh után add hozzá ezeket

	if app.ENABLE_DOG_MODE:
		def __OnClickDogButton(self):
			systemSetting.SetDogMode(True)
			self.RefreshDogMode()

		def __OffClickDogButton(self):
			systemSetting.SetDogMode(False)
			self.RefreshDogMode()

		def RefreshDogMode(self):
			if systemSetting.GetDogMode():
				self.dogModeButtonList[0].Down()
				self.dogModeButtonList[1].SetUp()
			else:
				self.dogModeButtonList[0].SetUp()
				self.dogModeButtonList[1].Down()