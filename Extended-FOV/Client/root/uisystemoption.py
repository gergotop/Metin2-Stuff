Keress rá:

class OptionDialog(ui.ScriptWindow): és a self._Load() alá másold be ezt:

		if app.ENABLE_FOV_OPTION:
			self.RefreshFOVOption()

Valahogy így nézzen ki:
class OptionDialog(ui.ScriptWindow):

	def __init__(self):
		ui.ScriptWindow.__init__(self)
		self.__Initialize()
		self.__Load()
		if app.ENABLE_FOV_OPTION:
			self.RefreshFOVOption()

Keress rá:
self.ctrlShadowQuality = 0

Alá:

		if app.ENABLE_FOV_OPTION:
			self.fovButtonList = []

Keress rá:
			self.tilingApplyButton=GetObject("tiling_apply")

Alá:

			if app.ENABLE_FOV_OPTION:
				self.fovButtonList.append(GetObject("fov_on"))
				self.fovButtonList.append(GetObject("fov_off"))

Keress rá:

		self.ctrlSoundVolume.SetEvent(ui.__mem_func__(self.OnChangeSoundVolume))

alá:

		if app.ENABLE_FOV_OPTION:
			self.__ClickRadioButton(self.fovButtonList, systemSetting.IsExtendedFOV())

keress rá:

		if musicInfo.fieldMusic==musicInfo.METIN2THEMA:
			self.selectMusicFile.SetText(uiSelectMusic.DEFAULT_THEMA)
		else:
			self.selectMusicFile.SetText(musicInfo.fieldMusic[:MUSIC_FILENAME_MAX_LEN])

Alá:

		if app.ENABLE_FOV_OPTION:
			self.fovButtonList[0].SAFE_SetEvent(self.__OnClickFOVButton, 1) # on
			self.fovButtonList[1].SAFE_SetEvent(self.__OnClickFOVButton, 0) # off


Keress rá:

		if musicInfo.fieldMusic != "":
			snd.FadeInMusic("BGM/" + musicInfo.fieldMusic)

Alá:

	if app.ENABLE_FOV_OPTION:
		def __OnClickFOVButton(self, flag):
			self.__ClickRadioButton(self.fovButtonList, flag)
			systemSetting.SetExtendedFOV(flag)
			self.RefreshFOVOption()

		def RefreshFOVOption(self):
			if systemSetting.IsExtendedFOV():
				self.fovButtonList[1].SetUp()
				self.fovButtonList[0].Down()
			else:
				self.fovButtonList[1].Down()
				self.fovButtonList[0].SetUp()

