# vi/vim reference

## vi modes
<img src="./vi.modes.png" alt="vi three modes" width="600"/>  

### iIoOaA
* **i**	: Inserts text before current cursor location  ![](./star.png "important!") ![](./star.png "important!") 
* **I**	: Inserts text at beginning of current line  
* **o**	: Creates a new line for text entry below cursor location  
* **O**	: Creates a new line for text entry above cursor location  
* **a** : Inserts text after current cursor location  ![](./star.png "important!") ![](./star.png "important!") 
* **A**	: Inserts text at end of current line  

---

## Commands
### 0. undo & redo  ![](./star.png "important!") ![](./star.png "important!")
* **u**  
* **Ctrl+r**  

### 1. move 
You can also use arrow keys or page-up/page-down keys or home/end keys
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
> #### remove newline
> * **J**  

### 3. copy
* **yy**	: Copies the current line  ![](./star.png "important!") ![](./star.png "important!")  
* **5yy**	: Yank current line and 4 lines below   ![](./star.png "important!") ![](./star.png "important!")  

### 4. paste
* **p**		: Puts the copied text after the cursor	 ![](./star.png "important!") ![](./star.png "important!")
* **P**  	: Puts the copied text befor the cursor

### 5. repeat
* **.**		: Repeats the last change made in command mode  ![](./star.png "important!")

### 6. indent  ![](./star.png "important!")  
* **>>**  
* **5>>**  
* **3<<**  

### 7. search  ![](./star.png "important!") ![](./star.png "important!")
* **/word_to_find**	: Finds a word  
* **\***	: Finds a word of current cursor position  
* **n**		: Moves forward  
* **N**		: Moves backward  
* **:noh**	: Clears highlight (no highlight)

### 8. save and exit  ![](./star.png "important!") ![](./star.png "important!")
* **:q**	: Quit  
* **:q!**	: Quit without saving changes  
* **:w**	: Write  
* **:wq**	: Write and Quit  

---

### 9. visual selection
* **v**		: Start Visual mode characterwise  ![](./star.png "important!") ![](./star.png "important!")  
* **V**		: Start Visual mode linewise  ![](./star.png "important!") ![](./star.png "important!")  
* **Ctrl+v**	: Start Visual mode blockwise  
* **vw**  

### 10. replace operation
* **:%s/foo/bar/**	: Replaces first occurrence of word foo with bar on all lines (The % is shorthand for all lines)	
* **:5,10s/old-string/new-string/g**	: Replaces all occurrences on lines 5 througth 10 ('g' indicates all occurrences)  ![](./star.png "important!")
* **:.,+10s/old-string/new-string/g**	: Replaces all occurrences at the current line for the next 10 lines
* **:%s/old-string/new-string/gi**	: Replaces case-insensitive all occurrences on all lines. ('i' indicates ignore case)  ![](./star.png "important!")

### 11. multiple windows
* **:sp filename**	: Splits screen horizontally   ![](./star.png "important!")
* **:vs filename**	: Splits screen vertically   ![](./star.png "important!")
* **Ctrl+ww**		: Moves cursor to other window   ![](./star.png "important!")
* **Ctrl+w \<Up\>**
* **Ctrl+w \<Down\>**
* **Ctrl+w \<Left\>**
* **Ctrl+w \<Right\>**

### 12. Other tips
#### You can issue Linux commands from within your vi editor session
* **:!command_name_here** 	: Runs shell command and returns to command mode  ![](./star.png "important!")
* **:!bash**				: Runs bash keeping current editing, type 'exit' + enter to return to vi  
#### Line number toggle
* **:set nonu**	: Hides line number  ![](./star.png "important!")
* **:set nu**	: Shows line number  ![](./star.png "important!")
#### Hex mode
* **:%!xxd**	: Turns into hex mode (% matches whole file as a range, ! execute, xxd shell command)  
* **:%!xxd -r**	: Turns back to text mode  
#### Further reading
* **:help**  ![](./star.png "important!")
> ##### About visual mode
> * **:help visual-block**  
> * **:help visual-operators**  
> * **:help blockwise-operators**  

---

## Ctags and Taglist and Cscope
To be continue...

---

## _.vimrc_ templates
[Jaey's](./.jaey_vimrc)
