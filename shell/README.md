# Shell 

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

## Common Bash commands and Linux utilities
* **man** : an interface to the on-line reference manuals
```c
// check this manual has section 1  
man cat	// cat is executable program  
// open reference manual section 2 of write  
man 2 write	// write(2) is a function from unistd.h which provides access to **the POSIX operating system API**.  
// check printf manual section is 3  
man printf	// printf(3) is a function from stdio.h which is a part of **C library** to perform Input/Output operations.  
```

## _.bashrc_ templates
[Jayden's]()  
[Yiloing's]()  

