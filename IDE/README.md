Laboratory Work Nr.1
====================
##Title

Command Line Interface. CLI Editors. Setting Server Environment. Version Control Systems

##Main purposes of this lab work:

•Understanding and using CLI (basic level)

•Administration of a remote linux machine using SSH

•Ability to work remotely (remote code editing)

•Ability to work with VCS

##Mandatory Objectives:

####•Connect to a remote server via SSH:

This task was done by using GitBash on Windows. The command that helped me to do this was `ssh username@IP` 

####•Initialize a repository on server:

For starting to track an existing project in Git, I had to go to the project’s directory and type `git init` command in order to create a new subdirectory named .git that contains all of my necessary repository files — a Git repository skeleton.

####•Create a file in repository folder, write in your name, save it and commit it:

I solved this task doing the following steps:

```python
#Theese two steps are used for creating a new directory
mkdir Gusan_Gina_FAF_121
cd Gusan_Gina_FAF_121
# Theese steps are used for initialising an empty repository
mkdir git
cd git
git init
# Here I create the text file using Vim
vim text.txt 
#Next, I insert some text in this file and save it
:i
Gusan Gina
:wp
#Now I add this file and commit it on git
git add .
git commit -m "init lab 1 IDE"
```

##Objectives With Points:

####•Connect to server using public key (1 pt)

The process of solving this task began with the necessity of generating an RSA key pair. The command providing this is `ssh-keygen - t rsa`. Now, each user that does this has to send their public key to you or whoever is administrating the Git server. Next, I copied the contents of the .pub file using `cat ~/.ssh/id_rsa.pub` command. Then I appended them to my `authorized_keys` file:`cat /tmp/id_rsa.pub >> ~/.ssh/authorized_keys`.

####•Create 2 more branches with at least one unique committed file per branch (1 pt)

For this task, there are some basic steps for creating  and working with branches:

```python
git branch <name_of_the_first_branch>
git branch <name_of_the second_branch>
git checkout <name_of_the_first_branch> # switch to the first branch
git touch file.txt                      # add a new file
git add .
git commit -m "add new file"
git checkout <name_of_the_second_branch> # switch to the second branch
git touch file.txt                       # add a new file
git add .
git commit -m "add new file"
```

####•Set a branch to track a remote origin on which you are able to push (ex. github, bitbucket or a custom server) (1 pt)

This task is done using the next commands:

``` python
git remote add origin git@github.com:GinaGusan/IDE-Labs.git  # add a remote origin
git push -u origin master                                    # push
```

####•Reset a branch to previous commit, reset a branch to some specific commit (1 pt)

To reset the HEAD of the tree to the previous commit I used:

`git reset --hard HEAD`    

To reset the HEAD of the tree to some specific commit, I used:

`git reflog`

`git reset --hard ID`

####•Restore a reset branch back to its previous state (1 pt)

For restoring, I appied the same procedure. First, I used `git reflog` to see all the id's of the commits and I copied the needed one, then I restored it using `git reset --hard ID`.

####•GIT cherry-pick, rebase (1 pt)

For the existing commits, *cherry-pick* applies a change each one introduces, recording a new commit for each.

`git reflog`

`git checkout master`

`git cherry-pick <commit1>`

For rebasing, I had to create a new branch at *commit1*, which allows me to take all the changes that were committed on *commit1* branch and replay them on the *commit2* branch.

`git checkout -b branchx <commit1>`

`git rebase --onto master <commit2>`

####•Create a VCS hook (1 pt)

####•Make your CLI text editor to highlight code (1 pt)

####•Create a VCS alias (1 pt)

####•Master any CLI editor (ex. VIM). Learn 10 commands' sets (a/A/i/I/o/O is one set) to prove your mastery (1 pt)

####•Create your own server (ex. virtual machine) (2 pt)


