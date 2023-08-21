1.: Set sql_mode:

If you're using MySQL5.6 or higher, it is highly recommended to modify sql_mode from sql_mode=NO_ENGINE_SUBSTITUTION,STRICT_TRANS_TABLES to
sql_mode=NO_ENGINE_SUBSTITUTION in your /usr/local/my.cnf then restart the server, or you will have DATA TRUNCATED errors at importing.
If you don't have that file, just create it, here's the content you should put: https://pastebin.com/xNsP6pVA

2.: Create a user for the serverfile:

You have to create a metin2@localhost MySQL user with every Server Priviliges in order to make the serverfile work.
For password use the word "password" or you can change the password in CONFIG files and use your own password. 

a.) You can create this user in navicat -> user -> new user
Fill the username (metin2), the host (localhost), and the password (password) then on Server Priviliges tab tick everything and click Save.

b.) Or you can create it in the FreeBSD console:
mysql -u root -p
(It will ask for your root password, if it's empty then just press enter)
CREATE USER 'metin2'@'localhost' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON *.* TO 'metin2'@'localhost' WITH GRANT OPTION;

If you want a remote user (like root@% or somebody@%), you can create it the same way.

3.: How to import the databases:

a.) You can import them in the FreeBSD console:
mysql -u root -p
(It will ask for your root password, if it's empty then just press enter)
CREATE DATABASE database_name;
exit
mysql -u root -p database_name < /path/to/sql/file.sql
(It will ask again for your root password)

b.) Or use navicat: right click to the connection -> new database, once you created then right click to it -> execute sql file and select the .sql file.
