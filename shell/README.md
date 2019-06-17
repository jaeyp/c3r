# Shell 
(written by Jaehyun)  
## Defination
A **shell** is a program that provides the traditional, text-only user interface for Linux and other Unix-like operating systems.  
Its primary is to read commands that are typed into a console or terminal window (emulator) in a GUI and then execute them.  
A **shell** is **an interface between the user and the internal parts of the operating system** (kernel). 
  
A **shell prompt**, also referred to as a command prompt is a character or set of characters at the start of the command line that indicates that the shell is ready to receive commands.  
It usually is, or ends with, a dollar sign($) for ordinary users and a pound sign(#) for the root (i.e., administrative) user.  
[Reference](http://www.linfo.org/shell.html)  

## Types of Shells
* **_sh_** (the Bourne Shell)  
_sh_ is the original UNIX shell.  

* **_bash_** (Bourne-again shell)  ![](./star.png "important!") ![](./star.png "important!")  
_bash_ is the default shell on Linux.  
_bash_ is a superset of sh and it was written for the [GNU](https://www.gnu.org/home.en.html) project.  

* **_ash_** (the Almquist shell)  
_ash_ is a clone of sh.  

* **_csh_** (the C shell)  
_csh_ has a syntax that resembles that of the C programming language.  

* **_ksh_** (the Korn shell)  
_ksh_ is a superset of sh.  

* **_tcsh_** (the TENEX C shell)  
_tcsh_ is based on csh but also has programmable file name completion, command line editing, a command history mechanism and other features lacking in csh.  

* **_zsh_** (the Z shell)  
_zsh_ is similar to ksh, but it also includes many features from csh.  

## Bash
[Reference Manual](https://tiswww.case.edu/php/chet/bash/bashref.html#Shell-Syntax)  
[Programming - Introduction HOW-TO](http://tldp.org/HOWTO/Bash-Prog-Intro-HOWTO.html)  

## _.bashrc_ templates
[Jayden's]()  
[Yiloing's]()  

## Common Bash commands and Linux utilities
* **man** : an interface to the on-line reference manuals
```c
// check this manual has only section 1  
man -a cat	// cat is a executable program  
// open reference manual section 2 of write  
man 2 write	// write(2) is a function from unistd.h which provides access to the POSIX operating system API.  
// the manual section of printf is 3  
man printf	// printf(3) is a function from stdio.h which is a part of C library to perform Input/Output operations.  
```

* **cd** : an interface to change the current directory
```c
// move to the root directory
cd /	// '/' represents the first directory in your filesystem hierarchy  
// move to the home directory
cd	or	cd ~	// '~' represents home directory  
// move to the parent directory
cd ..	// '..' represents parent directory  
```

* **ls** : an interface to list directory contents of files and directories
```c
// dispaly long listing information about the file/directory
ls -l
// display all the hidden files in the directory in long listing  
ls -al
// display all the hidden files in the directory in long listing with special character
ls -alF	// 'F' classifies the file with different special character for different kind of files
		// / - directory
		// nothing - file
		// @ - link file
		// * - executable file
```

* **mkdir** : an interface to create a directory
```c
// create a directory named 'mom'
mkdir mom  
// create a directory named 'mom', set to specific permission  
mkdir -m 644 mom  or  mkdir -m u=rw,g=r,o=r mom	// 644 represents that the user can read and write, and group and others can only read  
```

* **grep** : an interface to search for a specified text in a file
```c
// search for the string 'command' in the file named 'mom' insensitively
grep -i "command" mom
// search for the string 'command' in all the files under the current directory 
grep -r "command" *  
```

* **ps** : an interface to display processes running on the system. It comes with 2 systax styles and here is UNIX/LINUX style below
```c
// display every process on the system
ps -e
// display every process on the system in full format listing  
ps -ef
// display the processes named partially 'apache'
ps -ef | grep apache
```
