# SNOWCRASH

## Introduction
You will find in this repository the complete solutions for the project Snowcrash.
Once the VM provided with this project properly installed, you should be able to log through ssh as user `level00`, using the password `level00`

```bash
$ ssh level00@localhost -p 4343
	   _____                      _____               _
	  / ____|                    / ____|             | |
	 | (___  _ __   _____      _| |     _ __ __ _ ___| |__
	  \___ \| '_ \ / _ \ \ /\ / / |    | '__/ _` / __| '_ \
	  ____) | | | | (_) \ V  V /| |____| | | (_| \__ \ | | |
	 |_____/|_| |_|\___/ \_/\_/  \_____|_|  \__,_|___/_| |_|

  Good luck & Have fun

          10.0.2.15
level00@localhost's password:
level00@SnowCrash:~$
```
<br />

Once logged inm your goal is to find the password that will allow you to log as user `flagXX`, *XX* being the number of the level you are currently logged to.
Once logged in as `flagXX`, you'll be able to use the command `getflag` to obtain the flag for this level.
The flag will be used to log as the next user.

```bash
level00@SnowCrash:~$ su flag00
Password:
Dont forget to launch getflag !
flag00@SnowCrash:~$ getflag
Check flag.Here is your token : ?????????????????
flag00@SnowCrash:~$ su level01
Password:
level01@SnowCrash:~$ _
```
<br />

## Repository organization
In every `levelXX` directory, you'll find a `flag` file, containing the flag for this level.

```bash
$ ls -l level00
total 9
-rw-r--r--  1 marene  2013_paris    26 Jul 13 12:59 flag
drwxr-xr-x  2 marene  2013_paris  4096 Jul 13 12:34 ressource
```
<br />

You will also find a `ressource` subdirectory that will contain a `solution` file, that contains the walkthrough of the level to obtain the flag.
In those `ressource` subdirectory, you may as weel find other files (scripts for example), that were used to obtain the flag, as explained in the corresponding `solution` file.

```bash
$ ls -l ./level05/ressource
total 3
-rw-r--r--  1 marene  2013_paris   38 May 30 18:26 script.sh
-rw-r--r--  1 marene  2013_paris  741 May 30 18:26 solution
```

## snowcrash.sh
snowcrash.sh is a basic utility script that helps you keep track of your current level and password to access this level.
All passwords are stored into their appropriate user directory in the file `.pass`
The VM informations (IP and port) are stored in `./.snowcrash\_ip`
The current user informations are stored in ./.key
just launch `./snowcrash.sh` to log through ssh as the current registered user. The password will be copied into your clipboard

```bash
$ ls -l ./level01/.pass
-rw-r--r--  1 marene  2013_paris  26 Jul 13 11:32 ./level01/.pass

$ ls -la ./.snowcrash_ip
-rw-r--r--  1 marene  2013_paris  31 Jul 13 11:29 ./.snowcrash_ip

$ ls -la ./.key
-rw-r--r--  1 marene  2013_paris  33 Jul 13 13:37 ./.key
```
### Options
 - `--update-user levelXX` : If `levelYY` exists (*ie* if the directory `levelXX` exists and contains a `.pass` file), change the current user to `levelYY` and logs you as it
 - `--update-vm ip port` : Changes the registered ip and port for the snowcrash vm
 - `--add-user levelXX password` : If `levelXX` doesn't already exists, create a `levelXX` directory and write the provided password in `levelXX/.pass`
 - `--whoami` : Shows which user is currently registered
 - `--whatvm` : Shows current VM's port and IP
 -- `--no-connect` : Prompts the ssh command line used to connect, but does not actually try to log in
