# Git Reference

---

## Dataflows
![](./git.dataflows.png)
[from patrick zahnd's blog](https://www.patrickzahnd.ch/blog.html)

---

## Repository
### Types of git objects
* **commit** object 
* **tree** object 
* **blob** object  
* **tag** object  

### project/.git/objects
<img src="./git.repository.svg" alt="git repository objects" width="1000"/>  

_This image was created by jaeyp_  

### HEADs
* **HEAD** names the commit on which you based the changes in the working tree.  
* **FETCH_HEAD** records the branch which you fetched from a remote repository with your last git fetch invocation.  
* **ORIG_HEAD** is created by commands that move your HEAD in a drastic way, to record the position of the HEAD before their operation, so that you can easily change the tip of the branch back to the state before you ran them.  
* **MERGE_HEAD** records the commit(s) which you are merging into your branch when you run git merge.  

---

## Index
### project/.git/index
![](./git.index.format.png)  
_This image was created by jaeyp_  

---

## Utilities and files
### decomp.py
* Decompressing object file using zlib  
* Calculating SHA-1 hash sum from decompressed data  
[code](./decomp.py)  

### .gitconfig
[reference (jaeyp)](./gitconfig_jaeyp)  

---

## Collaborating
```bash
# Create new branch
~$ git branch hotfix
# Switch to new branch
~$ git checkout hotfix

# Push current work
# 	-u: add upstream reference, then we can use argument-less git-push later.
~$ git push -u origin hotfix
# Push another work
~$ git push

# Merge hotfix to master
~$ git checkout master
~$ git fetch origin hotfix
~$ git merge origin/hotfix
~$ git push origin master
```

---

## References
```bash
# Git all commands  
~$ git help -a  

# Git manuals  
~$ git help -m  

# Git guides  
~$ git help -g  	
```
[Bitbucket Tutorials](https://www.atlassian.com/git/tutorials/learn-git-with-bitbucket-cloud)  
[Understanding Git - Index](https://hackernoon.com/understanding-git-index-4821a0765cf)  
[Git original document](https://github.com/git/git/tree/master/Documentation)  
[Git index format from original document](https://github.com/git/git/blob/master/Documentation/technical/index-format.txt)  
[Types of git objects](https://matthew-brett.github.io/curious-git/git_object_types.html)
