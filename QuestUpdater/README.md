# Quest Updater
## 

Ez a program azért készült, hogy könnyebben lehessen questeket frissíteni. Én már meguntam, hogy mindig PuTTY-n kellett mappákba lépegetni, majd ./qc xy parancsokat kiadni. Így hát létrehoztam egy nagyon egyszerű programot, hogy sok mindenkinek megkönnyítsem a dolgát.

## Követelmények
- .NET Framework 4.7.2
- SSH szerver


## A programról

- A program a Renci.SShNet packaget használja.
- A szerver adatokat egy Parameters.xml fájlba menti el és onnan tölti be minden indításkor.
- A megadott adatok nem továbbítódnak külső adatbázisba vagy fájlokba.
- A paraméterek kitöltésével már csak a quest nevét kell megadnod és mehet a frissítés. Mivel sokan .lua kiterjesztéssel dolgoznak ezért a fájl kiterjesztés nincs korlátozva.


A program folyamatosan kapni fog frissítéseket, hamarosan egy szerver kezelőt is tartalmazni fog.

## Telepítés

A programhoz futtatásához szükséges [.NET Framework 4.7.2](https://dotnet.microsoft.com/download/dotnet-framework/net472) verziója.

A quest frissítőt le klónozzunk egy általunk válaszott mappába és kész is vagyunk

```
git clone https://github.com/gergotop/Metin2-Stuff/tree/master/QuestUpdater
```


