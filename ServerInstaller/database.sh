mysql -uroot -ppassword < database/base/db_create.sql
mysql -uroot -ppassword < database/base/mt2_user_c.sql

## Create clean metin2 db struct
mysql -uroot -ppassword account < database/account.sql
mysql -uroot -ppassword common < database/common.sql
mysql -uroot -ppassword log < database/log.sql
mysql -uroot -ppassword player < database/player.sql
