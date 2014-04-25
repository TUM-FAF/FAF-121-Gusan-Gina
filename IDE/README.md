Laboratory Work Nr.1
====================
Title
-----
Command Line Interface. CLI Editors. Setting Server Environment. Version Control Systems

##Main purposes of this lab work:

•Understanding and using CLI (basic level)

•Administration of a remote linux machine using SSH

•Ability to work remotely (remote code editing)

•Ability to work with VCS

####Mandatory Objectives:

•Connect to a remote server via SSH:

This task was done by using GitBash on Windows. The command that helped me to do this was `ssh username@IP` 

•Initialize a repository on server:

For starting to track an existing project in Git, I had to go to the project’s directory and type `git init` command in order to create a new subdirectory named .git that contains all of my necessary repository files — a Git repository skeleton.

•Create a file in repository folder, write in your name, save it and commit it:

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

####Objectives With Points:

•Connect to server using public key (1 pt)

•Create 2 more branches with at least one unique committed file per branch (1 pt)

•Set a branch to track a remote origin on which you are able to push (ex. github, bitbucket or a custom server) (1 pt)

•Reset a branch to previous commit, reset a branch to some specific commit (1 pt)

•Restore a reset branch back to its previous state (1 pt)

•GIT cherry-pick, rebase (1 pt)

•Create a VCS hook (1 pt)

•Make your CLI text editor to highlight code (1 pt)

•Create a VCS alias (1 pt)

•Master any CLI editor (ex. VIM). Learn 10 commands' sets (a/A/i/I/o/O is one set) to prove your mastery (1 pt)

•Create your own server (ex. virtual machine) (2 pt)


