# uls

`uls` is a command-line utility for macOS that recreates the functionality of the standard `ls` command.

## Table of Contents

- [Overview](#overview)
- [Implemented Options](#implemented-options)
- [Usage Examples](#usage-example)
- [Installation & Building](#installation--building)
- [License](#license)

## Overview

This console utility works as a system utility `ls` and implements basic functionality of this command:

- the usage: usage: uls [-l] [file ...]
- list of directory contents without flags
- processing of _file_ operands for files and directories
- the _-l_ flag, which is one of the most useful flags
- the view of extended file attributes and access control lists (ACL)
- error handling, as in the original _ls_ . Output uls as the program name instead of ls where necessary
- the multicolumn output format when the option _-l_ isn't specified

> [!WARNING]  
> The program builds only on MacOS.

## Implemented options

```
     -@      Display extended attribute keys and sizes.

     -1      Force output to be one entry per line. This is the default when output is not to a terminal.

     -A      List all entries including those starting with a dot .
             Except for . and ..

     -a      List all entries including those starting with a dot .

     -C      Force multi-column output.

     -c      Use time when file status was last changed for sorting or printing.

     -G      Enable colour output.

     -l      List in long format. Ownership, Date/Time etc
             For terminal output, a total sum of all the file sizes is
             output on a line before the long listing.
             If the file is a symbolic link the pathname of the linked-to file is
             preceded by ->

     -R      Recursively list subdirectories encountered.

     -r      Reverse the order of the sort to get reverse lexicographical
             order or the oldest entries first.

     -S      Sort files by size.

     -T      When used with the -l option, display complete time
             information for the file, including month, day,
             hour, minute, second, and year.

     -t      Sort by time modified (most recently modified first) before
             sorting the operands by lexicographical order.

     -u      Use time of last access, instead of last modification of the file
             for sorting (-t) or printing (-l).
```

## Usage example

```shell
>./uls -z | cat -e
uls: illegal option -- z
usage: uls [-l] [file ...]

>./uls xxx
uls: xxx: No such file or directory

>./uls
dir1 dir2 dir3 file1 file2 file3 file4 file5

>./uls | cat -e
dir1$
dir2$
dir3$
file1$
file2$
file3$
file4$
file5$

>./uls dir1 dir2 file1 file2 file3
file1 file2 file3
dir1:
A.txt  E.txt  I.txt M.txt  Q.txt  U.txt  Y.txt
B.txt  F.txt  J.txt N.txt  R.txt  V.txt  Z.txt
C.txt  G.txt  K.txt O.txt  S.txt  W.txt
D.txt  H.txt  L.txt P.txt  T.txt  X.txt

dir2: # empty directory
>./uls -l | cat -e
total 0
drwxr-xr-x 4 neo staff 128 May 17 15:15 dir1$
drwxr-xr-x 2 neo staff  64 May 17 14:57 dir2$
drwxr-xr-x 2 neo staff  64 May 17 14:57 dir3$
-rw-r--r-- 1 neo staff   0 May 17 14:56 file1$
-rw-r--r-- 1 neo staff   0 May 17 14:56 file2$
-rw-r--r-- 1 neo staff   0 May 17 14:56 file3$
-rw-r--r-- 1 neo staff   0 May 17 14:56 file4$
-rw-r--r-- 1 neo staff   0 May 17 14:56 file5$
```

## Installation & Building

```shell
# Clone repository
git clone https://github.com/neffarrty/uls.git

# Enter the project directory
cd uls/

# Run Make to build and install
make install
```

## License

This software is licensed under the [MIT](./LICENSE) license.
