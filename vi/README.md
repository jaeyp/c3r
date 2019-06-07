# vi/vim editor reference

## vi modes
<img src="./vi.modes.png" alt="vi three modes" width="600"/>

## command mode
### 1. move
* **w or W**	: Positions cursor to the next word  
* **b or B**	: Positions cursor to previous word  
* **(**	: Positions cursor to beginning of current sentence  
* **)**	: Positions cursor to beginning of next sentenct  
* **H**	: Move to top of screen  
* **M**	: Move to middle of screen  
* **L**	: Move to bottom of screen  
* **: along with x**	: Colon followed by a number would position the cursor on line number repregented by x  
* **:$**	: Positions cursor to the last line  
* **Ctrl+b**	: Moves backward one full screen  
* **Ctrl+f**	: Moves forward one full screen  

### 2. delete
* **dw**	: Deletes the current word  
* **dd**	: Deletes the current line  ![](./star.16x16.png "important!")
* **5dd**	: Deletes current line and 4 lines below  
* **d^**	: Deletes from current cursor position to the beginning of the line  
* **d$**	: Deletes from current cursor position to the end of the line  
* **D**	: Deletes from current cursor position to the end of the line  

### 3. copy
**yy**  
**5yy**	: Yank current line and 4 lines below  

### 4. paste
**p**  
**P**  

### 5. repeat
**.**  

### 6. remove newline
**J**  

### 7. block select
**v**  
**vw**  

### 8. indentation
**>>**  
**5>>**  
**3<<**  

### 9. undo & redo
**u**  
**Ctrl+r**  

## last line mode
:q		- quit
:q!		- quit without saving changes
:w		- write
:wq		- write and quit
:line_number	- move cursor position
:$		- move to end line

## Search
/word_to_find
*		- find current word
n		- move forward
N		- move backward

## Multiple windows
:sp filename	- split screen horizontally
:vs filename	- split screen vertically
Ctrl+ww		- move to other window

## Substraction
:5,10s/a/b/g		- from 5 line to 10 line
:.,.+10s/a/b/g		- from current line to current line + 10 line
:%s/hello/world/gi	- %s: whole line, i: ignore case, g: global (substract every cases)

## Other tips
### you can issue Linux commands from within your vi editor session
:!command_name_here 	- run shell commands and returns to command mode
:!bash			- run bash keeping current editing, type 'exit' + enter to return to vi
### line number toggle
:set nonu
:set nu

