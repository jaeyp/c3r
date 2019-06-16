## :sudoer

* **How to Give Root Permission to User**
```c
// run the following command to open sudoers file as root
visudo

// add the following line in the bottom of sudoers file
user_name ALL = NOPASSWD: ALL
```
