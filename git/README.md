# Git
(_written by **Jaehyun**_)  
## Dataflows
![](./git.dataflows.png)  
[from patrick zahnd's blog](https://www.patrickzahnd.ch/blog.html)
### Extra Information
* **git revert**  
* **git stash** - The command saves your local modifications away and reverts the working directory to match the HEAD commit.
---

## Repository
### Types of git objects
* **commit** object 
* **tree** object (`directory`)  
* **blob** object (`file`)   
* **tag** object  

### project/.git/objects (`Local Repository`)
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

_This image was created by **Jaehyun**_  

```bash
# commit object
~$ git cat-file 4c1492d -p
tree ec7ca6359f5e3a85bfe3177e418c3c1a177ba971
parent 68b280bf6bf97934c297d4c1f1be2f8ab76448cc
author jaeyp <jp.inseoul@gmail.com> 1563603494 +0000
committer jaeyp <jp.inseoul@gmail.com> 1563603494 +0000


# tree object
~$ git cat-file ec7ca6 -p
100644 blob f47cb2045f130d56b12a40b1ab207bd492281c17	.gitignore
100644 blob 0b8b24197f3d09520cd41ad4b29ae405f93f869c	LICENSE
100644 blob b6d590ebba2788fdc4cefa170c0823323a52685b	README.md
040000 tree 8a7f5376e19aa4c92850d0317ceeae72bfd6ad9c	book
040000 tree 8d8341d53fab3df308344f3cec49980a1fff1076	cmake
040000 tree 5443b255396138d40b4553659e5294ef0f19d6ce	doc
040000 tree 6ee45962dd61c82b1f649791296c9ecdd8760836	ec2
040000 tree 6e9b2dfd9d896212590d99105a700a5b3ad712b1	git
040000 tree 6614da418cbe7c160b40fff971c6cad97e215836	meeting_minutes
040000 tree 955740235ce358c0bc87c87f55095e7ede070018	misc
040000 tree 50ffde6b6658f53450b728e9fcbbcacaa87a961a	shell
040000 tree 3e2ed9d3401f4d993bd4673b5d5a4c662513bc82	vi


# blob object
~$ git cat-file 0b8b24 -p
BSD 2-Clause License

Copyright (c) 2019, Jaehyun Park
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
...

```

### HEADs
* **HEAD** names the commit on which you based the changes in the working tree.  
* **FETCH_HEAD** records the branch which you fetched from a remote repository with your last git fetch invocation.  
* **ORIG_HEAD** is created by commands that move your HEAD in a drastic way, to record the position of the HEAD before their operation, so that you can easily change the tip of the branch back to the state before you ran them.  
* **MERGE_HEAD** records the commit(s) which you are merging into your branch when you run git merge.  

---

## Index (`Staging Area`)
### project/.git/index
```bash
# Display staged objects  
~$ git ls-files -s  
```
![](./git.index.format.png)  
_This image was created by **Jaehyun**_  

---

## Utilities and files
### decomp.py
[source code](./decomp.py)  
* Decompressing object file using zlib  
* Calculating SHA-1 hash sum from decompressed data  

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

## Useful Commands
* Switch remote repository
```bash
# you don't have to remove an existing .git folder
~$ git remote add origin <repository-url>
~$ git pull origin master --allow-unrelated-histories
~$ git push origin master
# you might face with conflicts (e.g. in README.md)
```

* Reload ~/.gitconfig  
```bash
~$ git init
```

* Get first 10 commits' log   
```bash
~$ git log -n 10
```

* Get next 10 commits' log skip first 20  
```bash
~$ git log --skip=20 -n 10
```

* Find ROOT commit  
```bash
~$ git rev-list --max-parents=0 HEAD
```

* Clone the repository and checkout the specific commit  
```bash
~$ git clone -n <repository-name> # no checkout of HEAD
~$ git checkout <commit-sha> # set the HEAD of master to point to <commit-sha>
```

* Clone the repository and checkout the specific commit into a branch  
```bash
~$ git clone -n <repository-name> # no checkout of HEAD
~$ git checkout -b <new-branch> <commit-sha> # set the HEAD of master to point to <commit-sha> into <new-branch>

```

* Rollback commit  

If codes were already pushed to a remote server
```bash
# revert
#         ┏-------┓           
#         |       V
# o---o---X---o---O

~$ git revert <commit-sha>
~$ git push origin master

# reset (not recommended)
#             ┏---┓           
#             V   |
# o---o---o---O---X
~$ git reset --hard <commit-sha>
~$ git push -f origin master

```

Else (when codes were NOT pushed to a remote server)
```bash
# The '--soft' parameter (Reset only HEAD, but keep Staged and Committed changes)
# resets HEAD to another commit.
#     HEAD            INDEX        working copy
# ------------- != ------------- = -------------
#   <1234567>        <abcdefg>       <abcdefg>
~$ git reset --soft <commit-sha>
~$ git commit -a # add and commit

# The '--mixed'(default) parameter (Reset HEAD, also reset changes to Unstaged status, but keep Committed changes)
# resets HEAD to another commit
# , and will reset the index to match it.
#     HEAD           INDEX         working copy
# ------------- = ------------- != -------------
#   <1234567>       <1234567>        <abcdefg>
~$ git reset (--mixed) <commit-sha>
~$ git commit

# The '--hard' parameter (Reset HEAD, also reset changes to Unstaged and Uncommitted status)
# resets HEAD to another commit
# , resets the index to match it
# , and resets the working copy to match it as well.
#     HEAD           INDEX        working copy
# ------------- = ------------- = -------------
#   <1234567>       <1234567>       <1234567>
~$ git reset --hard <commit-sha>

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
