# Server Installer Script

This shell script will automatically generate the server instance for you. It means that this script will install a fresh server based on @TMP files.
TMP Profile: https://hugames.hu/index.php?/profile/29-tmp4/

## Requirements
```bash
Operating system: FreeBSD 13.2-RELEASE
Database: MariaDB 10.11.4/ pkg install mariadb1011-server
```
## Installation

You have to clone this repository or download as zip to a random folder.

```bash
mkdir /home/
git clone https://github.com/gergotop/Metin2-Stuff/ then move the ServerInstaller folder to anywhere.
```
or you can download from here: http://down.pikdev.hu/installer.zip

## Usage

```bash
# create database structure
sh database.sh

# create server structure
sh server.sh

```
```bash
By default the mysql password is empty (there is no password for root so you can easily log in).
If you had set a password, you can specify the mysql user details in the database.sh. For example (mysql -u root -p yourpassword)

My installation method doesn't contains the builded game and db file.
```

## The database script
```bash
This script will do the following: 
-> 1. Creating metin2 user for the server
-> 2. Creating account, common, hotbackup, log, player database.
-> 3. Executing the sql scripts which inside the database folder.
-> 4. Done
```

## The server script
```bash
This script will do the following: 
-> 1. Creating server folder and tmp folder
-> 2. Fetching the serverfile from my server then extract.
-> 3. Removing the tar.gz file.
-> 4. Done.
```
