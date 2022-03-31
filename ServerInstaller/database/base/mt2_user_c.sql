CREATE USER 'metin2'@'localhost' IDENTIFIED BY 'password';

GRANT SELECT, INSERT, UPDATE, DELETE ON `srv1_player`.* TO 'metin2'@'localhost';

GRANT SELECT, INSERT, UPDATE, DELETE ON `srv1_log`.* TO 'metin2'@'localhost';

GRANT SELECT, INSERT, UPDATE, DELETE ON `srv1_hotbackup`.* TO 'metin2'@'localhost';

GRANT SELECT, INSERT, UPDATE, DELETE ON `srv1_common`.* TO 'metin2'@'localhost';

GRANT SELECT, INSERT, UPDATE, DELETE ON `srv1_account`.* TO 'metin2'@'localhost';

