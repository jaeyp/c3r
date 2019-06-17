# Git
(written by Jaehyun)  
## Dataflows
![](./git.dataflows.png)  
[from patrick zahnd's blog](https://www.patrickzahnd.ch/blog.html)
### Commands
* **git revert**  
* **git stash** - The command saves your local modifications away and reverts the working directory to match the HEAD commit.
---

## Repository
### Types of git objects
* **commit** object 
* **tree** object 
* **blob** object  
* **tag** object  

### project/.git/objects
```bash
# Display commit logs (revision history)  
~$ git log --oneline  
# Display the object type  
~$ git cat-file <object> -t  
# Display the object contents  
~$ git cat-file <object> -p  
# Display the tree-object contents  
~$ git ls-tree <object>  
```
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
```bash
# Display staged objects  
~$ git ls-files -s  
```
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
### Basic Conflict Workflow
```bash
# Update the remote-tracking branches
~$ git fetch
# Merge or rebase all updates fetched to working directory
~$ git merge/rebase
# or Do it together
~$ git pull

# Check conflict
~$ git status

# Resolve conflict manually
# The area where a pair of conflicting changes happened is marked with markers <<<<<<<, =======, and >>>>>>>.
~$ vi <conflict file>
# Add resolved contents to the index
~$ git add <conflict file>
# Conclude the conflict merge/rebase
~$ git merge/rebase --continue

# Update remote repository
~$ git push origin master
```

### Feature Branch Workflow
* Create new local feature branch (feature developer)  
```bash
# Create new branch
~$ git branch feature
# Switch to new branch
~$ git checkout feature
```

* Update local feature works to remote feature branch (feature developer)  
```bash
# Push current work
# 	-u: add upstream reference, then we can use argument-less git-push later.
~$ git push -u origin feature
# Push another work
~$ git push
```

* Merge feature branch to master branch (source code revision manager)  
```bash
# Switch branch to master
~$ git checkout master
# Fetch a remote feature branch
~$ git fetch origin feature		# update the remote feature branch
# Merge it to a local master branch as below
#        A---B---C origin/feature (remote feature branch)
#       /         \
#  D---E---F---G---H master (local master branch)
~$ git merge origin/feature		# merge origin/feature to local master
# or Rebase a remote feature branch to a local mster
#                A'--B'--C' origin/feature
#               /
#  D---E---F---G master
~$ git rebase master origin/feature	# git rebase <upstream> <repository>
# Update remote master repository
~$ git push origin master
```

* Delete feature branch merged  
```bash
# Delete a local branch 'feature'
~$ git branch -d feature
# Delete a remote branch 'origin/feature'
~$ git push origin --delete feature
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
