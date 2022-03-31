# Server Installer Script

This shell script will automatically generate the server instance for you. It means that this script will install a fresh server based on @TMP files.
## Requirements
```bash
Operating system: FreeBSD 12.3-RELEASE
Database: MySQL56 Server / pkg install mysql56-server
Libs: Se below
```
You can download the libs from here: [http://down.serverrent.hu/libs.zip]() (Do not rewrite the files just place the missing ones which are required by the server)
## Installation

You have to clone this repository or download as zip to a random folder.

```bash
mkdir /home/
git clone https://github.com/gergotop/Metin2-Stuff/tree/master/ServerInstaller
```

## Usage

```bash
# create database structure
sh database.sh

# create server structure
sh game.sh

```

