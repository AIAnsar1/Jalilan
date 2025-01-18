
## Jalilan a BruteForce Attack Login & Password Cracker Tools with SSH


## About Jalilan

```bash
$ jalilan -h

    ::::::'##::::'###::::'##:::::::'####:'##::::::::::'###::::'##::: ##:
    :::::: ##:::'## ##::: ##:::::::. ##:: ##:::::::::'## ##::: ###:: ##:
    :::::: ##::'##:. ##:: ##:::::::: ##:: ##::::::::'##:. ##:: ####: ##:
    :::::: ##:'##:::. ##: ##:::::::: ##:: ##:::::::'##:::. ##: ## ## ##:
    '##::: ##: #########: ##:::::::: ##:: ##::::::: #########: ##. ####:
     ##::: ##: ##.... ##: ##:::::::: ##:: ##::::::: ##.... ##: ##:. ###:
    . ######:: ##:::: ##: ########:'####: ########: ##:::: ##: ##::. ##:
    
              OpenSSH Brute force tool 0.6.0   
                
              Powered By AlAyubi 
              Created By AiAnsar


usage: ./jalilan [-h] [-v] [-aA] [-D] [-P] [-T TARGETS.lst] [-C credentials.lst]
                [-t THREADS] [-f OUTPUT FORMAT] [-o OUTPUT.txt] [-F SCAN OUTPUT FORMAT] [-O SCAN_OUTPUT.txt] [TARGETS...]

-h, --help                This help
-v, --verbose             Verbose mode
-V, --verbose-sshlib      Verbose mode (sshlib)
-s, --scan                Scan mode
-D, --dry-run             Dry run
-P, --progress            Progress bar
-T, --targets <file>      Targets file
-C, --credentials <file>  Username and password file
-t, --threads <threads>   Max threads
-o, --output <file>       Output log file
-F, --format <pattern>    Output log format
                          Available placeholders:
                          %DATETIME%, %HOSTNAME%
                          %PORT%, %USERNAME%, %PASSWORD%
-O, --scan-output <file>  Output log file for scanner
-F, --scan-format <pattern> Output log format for scanner
                          Available placeholders:
                          %DATETIME%, %HOSTNAME%
                          %PORT%, %BANNER%.
                          Default:
                          "%HOSTNAME%:%PORT%\t%BANNER%\n"
-a, --allow-non-openssh   Accepts non OpenSSH servers
-A, --allow-honeypots     Allow servers detected as honeypots
    --timeout <seconds>   Sets connection timeout (Default: 3)
    --check-http <host>   Tries to open a TCP Tunnel after successful login
```

## Example usages
```bash
jalilan -T targets.txt -C combinations.txt -o result.log
jalilan -s -t 8 -C combinations.txt -o result.log 192.168.1.0/24
```

### Supported targets syntax

* 192.168.0.1
* 10.0.0.0/8
* 192.168.100.0/24:2222
* 127.0.0.1:2222

### Combinations file format
```
root root
root password
root $BLANKPASS
$TARGET root
root $TARGET
```


### Customizable output format

Output format can be easily customizable using the command line option `-f`

Example: `./jalilan -f "%HOSTNAME%:%PORT%|%USERNAME%|%PASSWORD%\n"`, which
produces an output like:

```
192.168.0.100:22|root|toor
192.168.0.105:22|ubnt|ubnt
```

#### Default value

`%DATETIME%\t%HOSTNAME%:%PORT%\t%USERNAME%\t%PASSWORD%\n`

```
2024/04/01 13:05:13     192.168.0.100:22     root    admin
```


### Customizable output format for scanner

Output format can be easily customizable using the command line option `-F`

Example: `./jalilan -F "%HOSTNAME%\t%PORT%\t%BANNER%\n"`, which
produces an output like:

```
192.168.0.100 22  SSH-2.0-OpenSSH_6.0p1 Debian-4+deb7u2
192.168.0.105 22  SSH-2.0-OpenSSH_9.2p1 Debian-2+deb12u2
```

#### Default value

`%HOSTNAME%:%PORT%\t%BANNER%\n`

```
192.168.0.100:22  SSH-2.0-OpenSSH_9.2p1 Debian-2+deb12u2
```

#### Placeholders


## Requirements
**jalilan** uses **libssh** - The SSH Library (http://www.libssh.org/)

```bash
brew install libssh
```

## Build

Requirements:

* `make`
* `gcc` compiler
* `libssh-dev`

```bash
git clone --depth=1 https://github.com/AIAnsar1/Jalilan.git
cd Jalilan
make
make install
```

## Static build

Requirements:

* `cmake`
* `llvm` compiler
* `make`
* `libssl-dev`
* `libz-dev`

```bash
git clone --depth=1 https://github.com/AIAnsar1/Jalilan.git
cd Jalilan
bash static-build.sh
make install
```