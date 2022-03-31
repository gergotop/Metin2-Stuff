mysql -uroot < database/base/db_create.sql
mysql -uroot < database/base/mt2_user_c.sql
mysql -uroot account < database/account.sql
mysql -uroot common < database/common.sql
mysql -uroot log < database/log.sql
mysql -uroot player < database/player.sql
