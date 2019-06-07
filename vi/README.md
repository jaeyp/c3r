# vi/vim editor reference

## vi modes
<img src="./vi.modes.png" alt="vi three modes" width="600"/>

## Commands
### 0. undo & redo  ![](./star.png "important!") ![](./star.png "important!")
* **u**  
* **Ctrl+r**  

### 1. move (you can use arrow keys and page-up/page-down key)
* **w or W**	: Positions cursor to the next word  
* **b or B**	: Positions cursor to previous word  
* **(**	: Positions cursor to beginning of current sentence  
* **)**	: Positions cursor to beginning of next sentenct  
* **H**	: Move to top of screen  
* **M**	: Move to middle of screen  
* **L**	: Move to bottom of screen  
* **Ctrl+b**	: Moves backward one full screen  
* **Ctrl+f**	: Moves forward one full screen  
* **: along with x**	: Colon followed by a number would position the cursor on line number repregented by x  ![](./star.png "important!")
* **:$**	: Positions cursor to the last line  ![](./star.png "important!")

### 2. delete
* **dw**	: Deletes the current word  
* **dd**	: Deletes the current line  ![](./star.png "important!") ![](./star.png "important!")
* **5dd**	: Deletes current line and 4 lines below   ![](./star.png "important!") ![](./star.png "important!")
* **d^**	: Deletes from current cursor position to the beginning of the line  
* **d$**	: Deletes from current cursor position to the end of the line  
* **D**	: Deletes from current cursor position to the end of the line  
#### 2.1 remove newline
* **J**  

### 3. copy
* **yy**	: Copies the current line  ![](./star.png "important!") ![](./star.png "important!")  
* **5yy**	: Yank current line and 4 lines below   ![](./star.png "important!") ![](./star.png "important!")  

### 4. paste
* **p**		: Puts the copied text after the cursor	 ![](./star.png "important!") ![](./star.png "important!")
* **P**  	: Puts the copied text befor the cursor

### 5. repeat
* **.**		: Repeats the last change made in command mode  ![](./star.png "important!")

### 6. indentation  ![](./star.png "important!")  
* **>>**  
* **5>>**  
* **3<<**  

### 7. Search  ![](./star.png "important!") ![](./star.png "important!")
* **/word_to_find**	: Finds a word  
* **\***	: Finds the current word  
* **n**		: Moves forward  
* **N**		: Moves backward  

### 8. Save and Exit  ![](./star.png "important!") ![](./star.png "important!")
* **:q**	: Quit  
* **:q!**	: Quit without saving changes  
* **:w**	: Write  
* **:wq**	: Write and Quit  

---

### 9. block select
* **v**		: Start Visual mode characterwise  ![](./star.png "important!") ![](./star.png "important!")  
* **V**		: Start Visual mode linewise  ![](./star.png "important!") ![](./star.png "important!")  
* **Ctrl+v**	: Start Visual mode blockwise  
* **vw**  

### 10. Substraction 
* **:5,10s/a/b/g**			: from 5 line to 10 line  
* **:.,.+10s/a/b/g**		: from current line to current line + 10 line  
* **:%s/hello/world/gi**	: %s: whole line, i: ignore case, g: global (substract every cases)  

### 11. Multiple windows
* **:sp filename**	: Splits screen horizontally  
* **:vs filename**	: Splits screen vertically  
* **Ctrl+ww**		: Moves to other window  

### 12. Other tips
#### you can issue Linux commands from within your vi editor session
* **:!command_name_here** 	: Runs shell command and returns to command mode  
* **:!bash**				: Runs bash keeping current editing, type 'exit' + enter to return to vi  
#### line number toggle
* **:set nonu**	: Hides line number  
* **:set nu**	: Shows line number  
#### further reading
* **:help**  
##### about visual mode
* **:help visual-block**  
* **:help visual-operators**  
* **:help blockwise-operators**  

