// keresd

			bool			bShowSalesText;

//add alá
#ifdef ENABLE_DOG_MODE
			bool			bDogMode;
#endif

// keresd

};

// add felé

#ifdef ENABLE_DOG_MODE
		void							SetDogMode(int iFlag);
		bool							GetDogMode();
#endif
