## :sudoer
(_writtn by **Jayden**_)

### Intro
The /etc/sudoers file controls who can run what commands as what users on what machines and can also control special things such as whether you need a password for particular commands. The file is composed of aliases (basically variables) and user specifications (which control who can run what).

For Ubuntu 8.10: The default editor for visudo has changed to sensible-editor. sensible-editor defaults to nano now, and select-editor (which will run by default the first time) allows you to select another one.

### Aliases
There are four kinds of aliases: User_Alias, Runas_Alias, Host_Alias and Cmnd_Alias. Each alias definition is of the form:
	
	Alias_Type NAME = item1, item2, ...

Where Alias_Type is one of User_Alias, Runas_Alias, Host_Alias or Cmnd_Alias. A name is a string of uppercase letters, numbers and underscores starting with an uppercase letter. You can put several aliases of the same type on one line by separating them with colons (:) as so:
	
	Alias_Type NAME1 = item1, item2 : NAME2 = item3

You can include other aliases in an alias specification provided they would normally fit there. For example you can use a user alias wherever you would normally expect to see a list of users (for example in a user or runas alias).

There are also built in aliases called ALL which match everything where they are used. If you used ALL in place of a user list it matches all users for example. If you try and set an alias of ALL it will be overridden by this built in alias so don't even try.

* **How to Give Root Permission to User**
```c
// run the following command to open sudoers file as root
visudo

// add the following line in the bottom of sudoers file
user_name ALL = NOPASSWD: ALL
```
