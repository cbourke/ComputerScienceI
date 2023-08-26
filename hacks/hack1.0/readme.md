# Hack 1.0 - Getting Started With Git
**[School of Computing](https://computing.unl.edu/)**  
**[College of Engineering](https://engineering.unl.edu/)**  
**[University of Nebraska-Lincoln](https://unl.edu)**  
**[University of Nebraska-Omaha](https://http://unomaha.edu/)**  

# Introduction

Hack session activities are small weekly programming assignments
intended to get you started on full programming assignments. You may
complete the hack on your own, but you are *highly encouraged* to work
with another student and form a hack pair. Groups larger than 2 are not
allowed. However, you may discuss the problems *at a high level* with
other students or groups. You may not share code directly.

If you choose to form a Hack Pair, you *must*:

1.  Both join a hack pair on Canvas (go to People then Groups)

2.  You must both work on the hack equally; it must be an equal effort
    by both partners. Do not undermine your partner's learning
    opportunity and do not undermine your own by allowing one parter to
    do all the work.

3.  You may both turn in a copy, but only one will be graded (generally
    the one whose last name comes first alphabetically).

## Rubric

You are graded based on style, documentation, design and correctness.
For detail, see the general course rubric.

| Category      | Points |
|---------------|--------|
| Style         | 2      |
| Documentation | 2      |
| Design        | 5      |
| Correctness   | 16     |
| Total         | 25     |

For correctness:

-   Code itself needs to be correct: 4 pts

-   There should be more than one commit: 4 pts

-   All commits should have a descriptive comment: 3 pts

-   There must be at least 2 contributors: 5 pts

# Problem Statement

An essential tool when developing software is a *version control system*
(VCS). As you develop software you will make changes, add features, fix
bugs, etc. and it is necessary to keep track of your changes and to
ensure that your code and other artifacts are backed up and protected by
being stored on a reliable server (or multiple servers) instead of just
one machine.

A *version control system* allows you to "check-in" or *commit* changes
to a code project. It keeps track of all changes and allows you to
"branch" a code base into a separate copy so that you can develop
features or enhancements in isolation of the main code base (often
called the "trunk" in keeping with the tree metaphor). Once a branch is
completed (and well-tested and reviewed), it can then be *merged* back
into the main trunk and it becomes part of the project.

These systems are not only used for organizational and backup purposes,
but are absolutely essential when developing software as part of a team.
Each team member can have their own working copy of the project code
without interfering with other developer's copies or the main trunk.
Only when separate branches have to be merged into the trunk do
conflicting changes have to be addressed. Such a system allows multiple
developers to work on a very large and complex project in an organized
manner.

![Trunk, branches, and merging visualization of the Drupal
project](./images/repositorydiagram.png)

There are several widely used revision control systems including CVS
(Concurrent Versions System), SVN (Apache Subversion), and Git. SVN is a
*centralized* system: there is a single server that acts as the main
code repository. Individual developers can check out copies and branch
copies (which are also stored in the main repository).

Git is a *distributed* VCS meaning that multiple servers/computers act
as full repositories. Each copy on each developer's machine *also*
contains a complete revision history. This makes git a decentralized
system. Code commits are committed to a local repository. Merging a
branch into another requires a push/pull request. Decentralizing the
system means that anyone's machine can act as a code repository and can
lead to wider collaboration and independence since different parties are
no longer dependent on one master repository.

Git has become the de facto VCS system in software development. We have
provided several external resources below, but this Hack will walk you
through the basics of getting started. You will setup a project with git
using GitHub (<https://github.com>) as your remote server. You will then
collaborate with someone else to commit changes.

This version of the hack assumes that you are using the CS50 IDE, a
VS Code codespaces instance provided for free by the good folks at
Harvard: <https://code.cs50.io/>.  

# Installation

Git should already be installed on your IDE and so no further steps are
necessary (though you will need your GitHub account). However, we do
need to do some configuration before we start.

Run the following two commands in your IDE terminal:

`git config --global user.email "youremail@huskers.unl.edu"`

`git config --global user.name "Your Name"`

Where the email and name are substituted with your own. We recommend you
use the same email and user name (login) as you used to sign up on GitHub.

# Creating a Repository

To focus on the git process, you will create and work with a simple
"Hello World"-style program but instead of printing "Hello World", it
will print your name.

1.  Create a new folder (call it `hello`) in your `/hacks/` directory.

2.  Create a `hello.c` source file in your new folder with code that
    prints your name.  Make sure it compiles and runs.

3.  Make this folder (and all of its contents) into a git repository by
    *initializing* it. Before you do, make sure your terminal is in the
    correct directory (the `hello` directory you just created). Recall the
    following commands from the previous lab:

    -   `pwd` - lists what directory you are currently in

    -   `cd hello` - changes your current directory to
        `hello`

    -   `ls` - lists the files in the current directory

    -   Also remember that you need to be in `/workspaces/CS1/` to use git, so
        before you run the initialization, make sure you are in
        `/workspaces/CS1/hacks/hello`

    ![image](./images/cl-pwd.png)

    In the console, change directories to this newly created
    `hello` directory and execute the following command:

    `git init`

    It might look something like the following.

    ![image](./images/cl-gitinit.png)

4.  This creates a repository in your IDE, but it does *not*
    create a repository on GitHub. We need to do this separately. Go to
    your GitHub page (<https://github.com/login> where `login` is
    replaced with your GitHub login) and in the upper right, select
    `New repository`.

    ![image](./images/cl-githubNewRepo.png)

5.  Name your repo `hello` and *make sure it is public* (this is
    the default).

    ![image](./images/cl-githubNewRepoName.png)

6.  Go back to your IDE

7.  We now need to make our first *commit* which will commit our
    code/changes to the repository. You can make as many edits as you
    want to your source code files and save them, but you only "save"
    them to your git repo when you *commit* these changes. Enter the
    following command.

    `git add --all`

    Which will tell git to add all files in your directory (and
    subdirectories) to the "index" so that changes and updates can be
    "staged" for the next commit. Don't worry about the jargon for now,
    essentially this just tells git to add files for its consideration.

8.  Enter the following command.

    `git commit -m 'initial commit'`

    This commits your changes to the *local* repository (the repository
    on the IDE). It should look something like the following.

    ![image](./images/cl-gitcommit.png)

## Pushing Changes

We will now *push* these changes (in the repository on your IDE)
to your *remote* GitHub repository (stored on GitHub's servers).

1. First, we need to play nice with GitHub.  The default "branch"
   in git is named `master` but the default branch on GitHub is
   named `main`.  To rename your local branch, run:

   `git branch -m main`

2. Next, you need to generate a *Personal Access Token*.  GitHub
   doesn't allow you to simply enter your password, they require
   you to generate a cryptographic token and use that instead.  A
   step-by-step process can be found here:

   <https://docs.github.com/en/github/authenticating-to-github/keeping-your-account-and-data-secure/creating-a-personal-access-token>

   ***Be sure to follow these instructions carefully***: you need to
   click "repo" (Full control of private repositories).  Also be sure
   to use a *classic token* and **not** a "fine grained" token.

3. Now we need to "connect" your *local* repository to the *remote*
   repository so that git knows where to push changes.  To do so,
   run the following command.

   `git remote add origin https://LOGIN:TOKEN@github.com/LOGIN/hello.git`

   Where both `LOGIN` are replaced with your GitHub login and `TOKEN`
   is replaced with your generated token.

4.  Now we can push your commit(s) to the remote repository with the
    following command:

    `git push -u origin main`

    It should look something like the following

    ![image](./images/cl-gitpush2.png)

5. Your repository should now be on GitHub. Point your web browser to
    <https://github.com/LOGIN/hello> where `LOGIN` is replaced
    with your GitHub user name. You can browse your repository, view its
    history, etc.

NOTE: If you mistyped something above, you can fix it as follows.

  -   You can use `git remote -v` to list the remote URL
      and verify that it is wrong

  -   Fix it by running

        `git remote set-url origin https://LOGIN:TOKEN@github.com/LOGIN/hello.git`

        with the correct values for `LOGIN` and `TOKEN`


## Git Ignore

Often times there will be files or *artifacts* that you want to create,
save and work with in your file system *but* you don't want them
committed to the repository. For example, when you compile your
`hello.c` program, you probably don't want the executable file,
`a.out` to be committed to the repo since you can always rebuild it.
The executable file is not part of your source code, but an *artifact*
of your code. In general, we want git to *ignore* these artifacts.

To do this, we can create a `.gitignore` file. This is simply a
plain text file that contains file and directory names that git will
ignore.

1.  In your IDE in the `hello` directory create a new file
    named `.gitignore`.

2.  Edit it and add `a.out` on a single line. Save this file.

3.  Commit and push this new file to your local and remote repositories
    by executing the series of commands:

    ``` text
      git add .gitignore
      git commit -m 'added gitignore file'
      git push -u origin main
    ```

    It should look something like the following.

    ![image](./images/cl-gitignore.png)

There are many standard `.gitignore` files for various types of
projects that you may find useful: <https://github.com/github/gitignore>

# Making Changes

You'll often make changes to you code that you should periodically
commit to your repository. Though you may make changes and save them to
a file, the changes are not saved to the repository's history.
Committing is the action that does this. Committing only changes your
*local* repository, the changes will still need to be *pushed* to
GitHub. In this activity you'll make changes, commit them and then push
them to GitHub.

1.  Open the `hello.c` file and add a line that prints your
    major. Also, change the line that prints your name (add an
    exclamation point at the end or something). Be sure to save your
    file and compile and run your program to be sure it is correct.

2.  Git can automatically track these changes, to display the changes in
    your console execute the following command.

    `git status`

    Git will display all the changed files that are not yet *staged*
    (not yet added to the index to be committed). It should look
    something like the following.

    ![image](./images/cl-gitstatus.png)

    Note that the `a.out` file is not listed (git is ignoring it
    as we directed it to!).

3.  Another useful tool allows you to view the changes or *differences*
    to a file. Execute the following command.

    `git diff hello.c`

    It should look something like the following. Deletions (or edits)
    are displayed in red and additions in green.

    ![image](./images/cl-gitdiff.png)

4.  We can now commit and push our changes in the same way as our
    initial commit. Execute the following series of commands.

    ``` text
      git add hello.c
      git commit -m 'added my major to the output'
      git push -u origin main  
    ```

Some observations/notes:

-   In our last commit, we did not use `git add --all` which
    would have added all (non-ignored) files. Adding everything at once
    can be convenient but in general commits should only include
    *related* changes and should be as *fine grained* as possible. You
    should not use commits as a catch-all/save-all operation.

-   You should *always* provide a good, descriptive commit message that
    accurately reflects your changes. Commit messages provide good
    documentation on your changes. For example, when fixing a bug, the
    commit message should reference the original issue or bug report.

# Collaborating With a Team

In this exercise, you'll need to team up with at least one other person.
You'll make them a collaborator on your project so they can make changes
and commit/push them to *your* repository on GitHub. Alternatively you
can have them make a *pull request*, but these instructions do not cover
that; refer to one of the resources in the [Additional
Resources](#section:additionalResources) section for how how to make
push/pull requests.

1.  On the GitHub webpage, click `Settings` in your project.

2.  In the left menu, click `Manage access`

3.  Click `Invite a collaborator` and type in your partner's
    GitHub user name and click `Add`.  Your partner will need
    to accept the invite (they can wait for an email notification
    or they can go to your repo's GitHub page and see the invite
    notice).

## What your collaborator needs to do

Together with your partner, walk through the following steps. These
steps should be done on *their* computer.

1.  Once you've sent an invite to collaborate, they need to accept it.

2.  Your partner should create a new directory at the root of their
    IDE (or whatever they are using) to hold *your* repository.

3.  Your partner should execute the following command inside of the new
    directory:

    `git clone https://github.com/YOURLOGIN/hello`

    Where again `YOURLOGIN` is replaced with your GitHub login. This
    clones the *remote* repository and now you have a *local* version of
    it!

4.  Your partner should add 2 lines of code to print their name and
    their major.

5.  Your partner will need to set the remote repository with their token.
    Run the following command:

    `git remote set-url origin https://PARTNERLOGIN:PARTNERTOKEN@github.com/YOURLOGIN/hello.git`

    Where `PARTNERLOGIN` and `PARTNERTOKEN` are your partner's GitHub
    login and Personal Access Token and `YOURLOGIN` is your login.  Observe
    what this is doing: your partner is using their credentials (login and
    token) to access *your* repository.

6.  Your partner should follow the same procedure to commit and push
    their changes to *your remote* repository using the same procedure
    as they did with theirs.

7.  Verify their changes by refreshing your repository on GitHub. You
    can click on the `hello.c` and if you both did everything
    correctly, you'll see multiple commits by multiple people:

    ![image](./images/completedRepo02.png)

    If you click on `History` you can see the changes for each
    commit:

    ![image](./images/completedRepo03.png)

Now, go back to *your* IDE. Remember, your partner's changes were
*pushed* to your *remote* repository hosted on GitHub. If you look at
your `hello.c` file you won't see their changes because this is
your *local* repository.

In order to get your partner's changes you'll need to *pull* their
changes from your remote repository to your local repository. To do
this, run the following command:

`git pull`

As long as there are no conflicting changes, all of your partner's
changes should now be reflected in your local repository. Of course,
you'll need to repeat this process for your partner's repository (add
your name/major to their and commit it so they can pull your changes).

You are *highly encouraged* to start using git/GitHub (or something
similar) for all of your future assignments but be sure to commit code
to a *private* repository so that you do not violate the department's
academic integrity policy.

## Finishing Up

1.  Put the URL for *your* GitHub repository into a plain text file
    named `readme.md` and turn in this file.  If you paired
    up with a partner (in Canvas), be sure *both* your GitHub URLs are in the
    `readme.md` file.  The contents of your file should look
    *something* like this:

    ``` text
       https://github.com/cbourke/hello
    ```

    or, if you worked in a pair:

    ``` text
       https://github.com/cbourke/hello
       https://github.com/mypartner/hello
    ```

2.  **Be sure your repo is public**

# Additional Resources

-   Video tutorial on Github Desktop:
    <https://www.youtube.com/watch?v=kFix7UDJ7LA>

-   Interactive git tutorial:
    <https://try.github.io/levels/1/challenges/1>

-   Pro Git, free online book: <https://git-scm.com/book/en/v2>
