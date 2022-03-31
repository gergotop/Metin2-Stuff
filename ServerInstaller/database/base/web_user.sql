CREATE USER 'web'@'%' IDENTIFIED BY 'user';

GRANT SELECT, INSERT, UPDATE, DELETE ON `player`.* TO 'web'@'%';

GRANT SELECT, INSERT, UPDATE, DELETE ON `log`.* TO 'web'@'%';

GRANT SELECT, INSERT, UPDATE, DELETE ON `hotbackup`.* TO 'web'@'%';

GRANT SELECT, INSERT, UPDATE, DELETE ON `common`.* TO 'web'@'%';

GRANT SELECT, INSERT, UPDATE, DELETE ON `account`.* TO 'web'@'%';

