#Suchen in class GameWindow(ui.ScriptWindow):
self.__ProcessPreservedServerCommand()

#Darunter hinzufügen
		self.pingLine = None
		if app.ENABLE_PINGTIME:
			self.pingLine = ui.TextLine()
			self.pingLine.SetFontName(localeInfo.UI_DEF_FONT_LARGE)
			self.pingLine.SetFontColor(1.0,1.0,1.0)
			self.pingLine.SetPosition((wndMgr.GetScreenWidth() - 130) / 2, 207)
			
#Suchen in def Close(self):
			self.interface=None

#Darunter hinzufügen
		if app.ENABLE_PINGTIME:
			self.pingLine = None

#Suchen in def __BuildDebugInfo(self):
		self.ViewDistance.SetPosition(0, 0)
		
#Darunter hinzufügen
		if app.ENABLE_PINGTIME:
			self.pingLine.SetWindowHorizontalAlignCenter()
			self.pingLine.SetHorizontalAlignCenter()
			self.pingLine.SetFeather()
			self.pingLine.SetOutline()
			self.pingLine.Show()
			
#Suchen in def OnUpdate(self):
		self.interface.BUILD_OnUpdate()

#Darunter hinzufügen
		if app.ENABLE_PINGTIME:
			nPing = app.GetPingTime()
			self.pingLine.SetText("PING: %s" % (nPing))