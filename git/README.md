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
### Branches

* Push a new local branch to a remote Git repository and track it
```bash
# 1.create a local feature branch
~$ git checkout -b feature_branch_name

# 2.edit, add and commit your files

# 3.push updates to the remote feature branch and set it as upstream branch
~$ git push -u origin feature_branch_name

# what is upstream branch? (-u/--set-upstream)
# the “upstream branch” is the remote branch hosted on a remote Git repository
# it allows us to use argument-less git-pull (from upstream) or git-push (to upstream)

# Check current upstream branch
~$ git branch -vv

# continue with feature branch
// modify codes
~$ git add .
~$ git commit -m 'comments'
// before push it, merge master or base branch first.
~$ git merge origin/master
// resolve confilicts if there is
// then, push it into upstream branch
~$ git push
```

* checkout a remote branch
```bash
~$ git checkout -t origin/remote_branch_name
or
~$ git checkout --track origin/remote_branch_name
or
~$ git fetch -all
~$ git checkout remote_branch_name
```

* checkout a remote branch with different name
```bash
~$ git checkout -b local_branch_name -t origin/remote_branch_name
```

* Delete a branch
```bash
# delete branch locally
~$ git branch -d localBranchName

# delete branch remotely
~$ git push origin --delete remoteBranchName
```

* Delete a remote branch
```bash
~$ git branch -a
# *master
#  test
#  remote/origin/master
#  remote/origin/test

~$ git push origin --delete test
# To <URL of your repository>.git
#  - [deleted]         test
```

*  Update branches which are no longer exist on the remote
```bash
~$ git fetch --prune
~$ git pull --prune
or set automatic prune with git fetch or pull
~$ git config --global fetch.prune true
```

* Change branch name
```bash
# If you want to rename a branch while pointed to any branch, do:
~$ git branch -m <oldname> <newname>

# If you want to rename the current branch, you can do:
~$ git branch -m <newname>
```

### Commons

* Add a new repository
```bash
~$ git init

# you don't have to remove an existing .git folder
~$ git remote add origin <repository-url>

# pull new data from repository
~$ git pull origin master

# error: git couldn't find remote ref
~$ git push origin master
```

* Move to a new remote repository removing history
```bash
# 1. create a new repository on github
# 2. reinitialize existing git repository (no need to delete existing .git directory)
~$ git init
# 3. switch remote repository
~$ git remote set-url origin <new repository-url>
# 4. pull new data from new repository
~$ git pull origin master --allow-unrelated-histories
# 5. resolve conflict and upload source codes to a new repository
~$ git add .
~$ git commit -m "initial commit"
~$ git push origin master
```

* Switching remote repository
```bash
~$ git clone <repository1-url> <dir>
~$ cd <dir>

# check a current remote repository
~$ git remote -v # check a current remote repository
```
If there is a current remote repository, then switch the repository
```bash
~$ git remote set-url origin <repository2-url>
~$ git remote -v # check a remote repository switched

# pull new data from repository2
~$ git pull origin master --allow-unrelated-histories

# push old data to repository2
~$ git add .
~$ git commit -m "switch repository"
~$ git push origin master
```

* Checkout to a specific folder
```bash
# To checkout everything from your HEAD (or <commit-checksum>) to a specific out directory:
~$ git --work-tree=/path/to/outputdir checkout HEAD -- .

# To checkout a subdirectory or file from your HEAD to a specific directory:
~$ git --work-tree=/path/to/outputdir checkout HEAD -- subdirname

# Minor note - you do need an absolute path as shell tilde expansion doesn't occur, 
# i.e. --work-tree=/home/thomasg/okcopy rather than --work-tree=~/okcopy 
# (possibly using a relative path while sitting inside the same git tree works too, 
# but that way lies madness and git status outputs in R'lyehian)
```

* Checking remote repository
```bash
~$ git remote [-v | --verbose]
```

* Rollback unwanted changes
```bash
~$ git checkout -- .\src\importIcons.ts
```

* Amend(change) the message of the latest pushed commit
```bash
~$ git commit --amend -m "new commit message"
```

* Squash all commits through rebase
```bash
# 1a.squash last two commits into one
~$ git rebase -i HEAD~~

# 1b.squash all commits including master into one
~$ git rebase -i --root  

# 1c.squash all commits in current branch into one
~$ git rebase -i master

# 2.change pick to squash(or fixup) of commits that you want to squash then save
----------------------------
pick eaa86c3 added f01
squash(or fixup) 4f08444 modified f01
squash(or fixup) 868526b modified f01 again
squash(or fixup) 9caaff1 modified f01 again again
squash(or fixup) a5258da edited test history
----------------------------

# 3.change commit message if you want
~$ git commit --amend -m "new commit message"

# 4.push to the remote branch (upstream)
git push --force-with-lease
```


* Setting up to track remote branch from local branch
```bash
# git branch --set-upstream-to=<remote-path>/<remote-branch>
~$ git branch --set-upstream-to=origin/master
# git branch -u <remote-path>/<remote-branch>
~$ git branch -u origin/develop-uat
# git branch <local-branch> -u <remote-path>/<remote-branch>
~$ git branch ALT-1654 -u origin/ALT-1654
```

* Undo a Git Add
```bash
~$ git reset
```

* Tagging
```bash
# Listing tags
~$ git tag

# Creating tags (Lightweight)
~$ git tag v1.0.0

# Tagging later
~$ git tag -a v1.0.1 <commit-checksum> # e.g. 9fceb02

# Push up all tags to remote server at once
~$ git push origin --tags

# Deleting tags
~$ git tag -d v1.0.0

# Remove tags from remote server
~$ git push origin :v1.0.0
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

## TroubleShooting
### Errors while pulling

* error: The following untracked working tree files would be overwritten by merge(or checkout)
```bash
# the problem is caused by some untracked working tree files. So just solving these untracked files solves this problem.
# Solutions: Open SourceTree through the command line, enter the local version warehouse directory, directly executed
~$ git clean -d -fx
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
