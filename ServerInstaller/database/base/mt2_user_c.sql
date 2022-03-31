CREATE USER 'metin2'@'localhost' IDENTIFIED BY 'password';

GRANT SELECT, INSERT, UPDATE, DELETE ON `player`.* TO 'metin2'@'localhost';

GRANT SELECT, INSERT, UPDATE, DELETE ON `log`.* TO 'metin2'@'localhost';

GRANT SELECT, INSERT, UPDATE, DELETE ON `hotbackup`.* TO 'metin2'@'localhost';

GRANT SELECT, INSERT, UPDATE, DELETE ON `common`.* TO 'metin2'@'localhost';

GRANT SELECT, INSERT, UPDATE, DELETE ON `account`.* TO 'metin2'@'localhost';

