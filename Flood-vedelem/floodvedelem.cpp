desc_manager.h

keresd: 
CClientPackageCryptInfo*	m_pPackageCrypt;

alá: 
	protected:
		std::set<std::string> flooders;
		friend class CInputHandshake;
		

desc_manager.cpp

keresd:
strlcpy(host, inet_ntoa(peer.sin_addr), sizeof(host));

alá:
	if (flooders.find(host) != flooders.end())
	{
		sys_log(0, "connection from %s was banned.", host);
		socket_close(desc);
		return NULL;
	}
	
input.cpp

keresd (ez a port security dolog) egész if ágat cseréld le

		if (IsEmptyAdminPage() || !IsAdminPage(inet_ntoa(d->GetAddr().sin_addr)))
		
erre:

#ifdef ENABLE_PORT_SECURITY
		if (IsEmptyAdminPage() || !IsAdminPage(inet_ntoa(d->GetAddr().sin_addr)))
		{
			sys_err("SOCKET_CMD: BLOCK FROM(%s)", d->GetHostName());
			DESC_MANAGER::instance().flooders.insert(d->GetHostName());
			DESC_MANAGER::instance().DestroyDesc(d);
			return -1;
		}
#endif	