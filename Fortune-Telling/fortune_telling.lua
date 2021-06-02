-------------------------------------------------
-- Öregasszony jóslás locale.lua és questlib.lua
-- nélkül.
-- Magyarosítva by P3NG3R
-------------------------------------------------
quest fortune_telling begin
    state start begin
		when oldwoman.chat."Jóslás" begin
			local fortune_telling =
			{
			--  { prob	0	item	money	remove money
				{ 1,	0,	20,	20,	0	}, -- 10
				{ 499,	0,	10,	10,	0	}, -- 5
				{ 2500,	0,	5,	5,	0	}, -- 1
				{ 5000,	0,	0,	0,	0	},
				{ 1500,	0,	-5,	-5,	20000	},
				{ 499,	0,	-10,	-10,	20000	},
				{ 1,	0,	-20,	-20,	20000	},
			}
			local fortune_words =
			{
				{
					"A szerencse embere.",
					"...Ez nem létezik![ENTER]"..
					"Az aurád.. arany színben ragyog..[ENTER]"..
					"Ma nem tudsz rosszat tenni, ezt garantálom![ENTER]"..
					"Olyan szerencséd van ma mintha nem is ember lennél.[ENTER]"..
					"Ilyen alkalom biztos, hogy egy életben[ENTER]"..
					"egyszer adódik![ENTER]"..
					"Használd ki![ENTER]"
				},
				{
					"Nagy szerencse",
					"Ilyet is ritkán mondok, de ez a nap a tiéd.[ENTER]"..
					"Olyan karmát érzed az aurádon, hogy az eszméletlen![ENTER]"..
					"Nem tudom elképzelni, hogy mi rossz történhetne veled ma..[ENTER]"..
					"Szinte semmi![ENTER]"..
					"Ragadd meg az alkalmat és most csinálj dolgokat.[ENTER]"..
					"Ilyen nem sokszor van.[ENTER]"
				},
				{
					"Szerencse.",
					"Ma szerencséd van..[ENTER]"..
					"Ilyenkor érdemes a fontosabb teendõket rendezni.[ENTER]"..
					"A szerencse múlandó, ezt ne feledd![ENTER]"
				},
				{
					"Se jó, se rossz.",
					"Ma neked se szerencséd, se peched nincs.[ENTER]"..
					"Ilyen esetekben nem ajánlatos komoly dolgokat[ENTER]"..
					"csinálni, mert nem biztos, hogy sikerül.[ENTER]"..
					"A szerencse fénye már látható az égen, de nem neked szól.[ENTER]"
				},
				{
					"Pech.",
					"A mai nem a te napod..[ENTER]"..
					"Lehetséges, hogy beléd csap egy villám![ENTER]"..
					"Légy óvatos és kerüld a bajt.[ENTER]"..
					"Hamarosan elmúlik a Pech...[ENTER]"
				},
				{
					"Nagy Pech.",
					"Ma nagyon szerencsétlen napod van..[ENTER]"..
					"Szerintem ne kezdj bele semmi fontos dologba,[ENTER]"..
					"biztos kudarc az eredmény![ENTER]"..
					"Húzd meg magad a sötétben, amíg[ENTER]"..
					"elmúlik a felhõ a fejed felõl..![ENTER]"
				},
				{
					"A Pech embere.",
					"...Ajj-ajj, ezt ne..[ENTER]"..
					"Az aurád a legsötétebb színben pulzál![ENTER]"..
					"Ez semmi jót nem jelent![ENTER]"..
					"Ma iszonyatos pech-re számíthatsz.[ENTER]"..
					"Vegyél Kama varázslat talizmánt, talán azzal[ENTER]"..
					"csökken a pech-ed...[ENTER]"..
					"Ma szerintem ne menj sehová,[ENTER]"..
					"mert csak baj lesz![ENTER]"
				},
			}
			if pc.get_level() < 20 then
				say_title(mob_name(9006)..":")
				say("Ez a jóslás igen csak fárasztó, de egy olyannak")
				say("mint te nem tudok jósolni, hiszen még kicsi vagy.")
				say("Érd el a 20. Szintet és gyere vissza hozzám.")
			elseif get_time()-pc.getqf("time")<8*60*60 then
				local passed_time = get_time() - pc.getqf("time")
				say_title(mob_name(9006)..":")
				say("Nehány jós nõ, már az elsõ jóslás után")
				say("bemondja az unalmast... Én nem!")
				say("")
				say("Én nap mint nap több embernek is jósolok.")
				say("De egy embernek egy nap csak egyszer tudok.")
				say("Neked ma már jósoltam.. Szeretnéd megtudni mi")
				say("volt a jóslat?")
				wait()
				say_title(mob_name(9006)..":")
				say("")
				local idx = pc.getqf("idx")
				if idx!=0 then
					say_reward(string.format("A mai jóslatod: %s",fortune_words[idx][1]))
					say("")
					if pc.getqf("talisman") == 0 and fortune_telling[idx][5]>0 then
						local talisman_cost = fortune_telling[idx][5]
						wait()
						say_title(mob_name(9006)..":")
						say("Nekem van egy különleges talizmánom,")
						say("amely használatával megnövekedik a szerencséd")
						say("A Pech pedig csökken vele.")
						say("")
						say("A tárgyak fejlesztésénél is jól jöhet,")
						say("mert megnövelheti a javítási esélyt is.")
						say("")
						say_reward("Szeretnél vásárolni a talizmánból?")
						local s = select("Igen","Nem")
						if s == 1 then
							if pc.get_gold() < talisman_cost then
								say_title(mob_name(9006)..":")
								say("Nincs elég Yangod a talizmán megvásárlásához!")
								say(string.format("A Talizmán ára: %d Yang", talisman_cost))
								pc.setqf("talisman", 0)
							else
								pc.give_item2(70052,1)
								pc.changegold(-talisman_cost)
								pc.setqf("talisman", 1)
							end
						else
							return
						end
					end
				end
			else
				local gold = 7777
				say_title(mob_name(9006)..":")
				say("Szeretnél jósoltatni?")
				say("Persze jóhoz fordultál, én tudok jósolni..")
				say("Mint mindennek, ennek is megvan a maga ára.")
				say(string.format("A jóslás ára: %d Yang.", gold))
				local s = select('Jósoltatni', 'Csöves vagyok')
				if s == 1 then
					if pc.get_gold() < 7777 then
						say_title(mob_name(9006)..":")
						say("Nincs nálad elegendõ Yang a jóslathoz!")
					else
						n = number(1,10000)
						local i
						local idx
						for i = 1, table.getn(fortune_telling) do
							if n<=fortune_telling[i][1] then
								idx = i
								break
							else
								n = n - fortune_telling[i][1]
							end
						end
						i = idx
						say(fortune_words[i][2])
						local t = {}
						n = 0
						local j
						for j = 2,4 do
							if fortune_telling[i][j] != 0 then
								n=n+1
								t[n] = j
							end
						end
						if n>0 then
							n = number(1, n)
							__give_char_priv(t[n]-1, fortune_telling[i][t[n]])
						end
						pc.setqf("time", get_time())
						pc.setqf("idx", i)
						pc.change_gold(-gold)
						if fortune_telling[i][5]>0 then
							wait()
							say(fortune_words[i][3])
							say_reward("Akarsz vásárolni egy talizmánt?")
							local talisman_cost = fortune_telling[i][5]
							local s = select("Igen","Nem")
							if s== 1 then
								if pc.get_gold() < talisman_cost then
									say_title(mob_name(9006)..":")
									say("Nincs elég Yangod a talizmán megvásárlásához!")
									say(string.format("A Talizmán ára: %d Yang", talisman_cost))
									pc.setqf("talisman", 0)
								else
									pc.give_item2(70052,1)
									pc.changegold(-talisman_cost)
									pc.setqf("talisman", 1)
								end
							elseif s == 2 then
								say_title(mob_name(9006)..":")
								say("Hát jó, de ne gyere panaszkodni, ha")
								say("nem lesz szerencséd, mert én segíteni akartam!")
								pc.setqf("talisman", 0)
							end
						end
					end
				elseif s == 2 then
					say_title(mob_name(9006)..":")
					say("Hát ebben az esetben, gyere vissza ha")
					say("lesz elég Yangod a jóslathoz.")
				end
			end
		end
    end
end

