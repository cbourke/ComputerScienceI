
# Hack 1.0
## Computer Science I
### Department of Computer Science & Engineering
### University of Nebraska–Lincoln
#### Java Version

------------------------------------------------------------------------

Rubric {#rubric .unnumbered}
------

  --------------- -------------
  Category        Point Value
  Style           2
  Documentation   2
  Design          5
  Correctness     16
  **Total**       **25**
  --------------- -------------

For correctness:

-   Code itself needs to be correct: 4 pts

-   There should be more than one commit: 4 pts

-   All commits should have a descriptive comment: 3 pts

-   There must be at least 2 contributors: 5 pts

Problem Statement 
=================

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
without interfering with other developer’s copies or the main trunk.
Only when separate branches have to be merged into the trunk do
conflicting changes have to be addressed. Such a system allows multiple
developers to work on a very large and complex project in an organized
manner.

![Trunk, branches, and merging visualization of the Drupal
project](./hack1.0-files/repositorydiagram)

There are several widely used revision control systems including CVS
(Concurrent Versions System), SVN (Apache Subversion), and Git. SVN is a
*centralized* system: there is a single server that acts as the main
code repository. Individual developers can check out copies and branch
copies (which are also stored in the main repository).

Git is a *distributed* VCS meaning that multiple servers/computers act
as full repositories. Each copy on each developer’s machine *also*
contains a complete revision history. This makes git a decentralized
system. Code commits are committed to a local repository. Merging a
branch into another requires a push/pull request. Decentralizing the
system means that anyone’s machine can act as a code repository and can
lead to wider collaboration and independence since different parties are
no longer dependent on one master repository.

Git has become the de facto VCS system in software development. We have
provided several external resources below, but this Hack will walk you
through the basics of getting started. You will setup a project with git
using GitHub (<https://github.com>) as your remote server. You will then
collaborate with someone else to commit changes.

Installation
============

All of the instructions in this Hack will involve using GitHub’s Desktop
Client. The screenshots were from the Mac version of this program so it
may look slightly different on other systems. There are other
alternatives and if you wish to use them you are welcome to do so.

1.  Go to <https://github.com/> and sign up/register with an account if
    you have not already done so.

2.  Download and the client here: <https://desktop.github.com/>.

Creating a Repository
=====================

To focus on the git process, you will create and work with a simple
"Hello World"-style program but instead of printing "Hello World", it
will print your name.

1.  Create a new folder (call it ) somewhere on your computer and within
    it, create a source file with code in it that prints your name.

2.  Open your GitHub Desktop Client (you may need to sign in with your
    new GitHub credentials).

3.  Drag and drop your folder to the GitHub Desktop Client. It will look
    something like the following.

    ![image](./hack1.0-files/drag.png)

    Click and it should look something like the following.

    ![image](./hack1.0-files/setup.png)

    Provide a simple description and click

4.  If everything is successful, it should look something like the
    following.

    ![image](./hack1.0-files/postCreation.png)

    The GitHub client will have made an initial commit of the existing
    files for you.

5.  Push/publish your repository to GitHub.com by clicking at the top
    right. It should look look something like the following.

    ![image](./hack1.0-files/publish.png)

    Be sure that is *not selected* and click

6.  If successful, your repository should now be on GitHub. Point your
    web browser to <https://github.com/login/hello> where is replaced
    with your GitHub user name. You can browse your repository, view its
    history, etc.

Making Changes
==============

You’ll often make changes to you code that you should *commit* to your
repository. Though you may make changes and save them to a file, the
changes are not saved to the repository’s history. Committing is the
action that does this. Committing only changes your *local* repository,
the changes will still need to be *pushed* to GitHub. In this activity
you’ll make changes, commit them and then push them to GitHub.

1.  Open the file and add a line that prints your major. Be sure to save
    the file.

2.  The GitHub Client should "see" these changes. It should look
    something like the following.

    ![image](./hack1.0-files/change.png)

3.  Commit your changes by filling out the summary (required) and
    description. This is your chance to *document* why you made changes
    to your code. Then click . Your changes have now been committed to
    your repository.

    ![image](./hack1.0-files/commit.png)

4.  Push your changes to GitHub by clicking at the top right. You can
    verify that your changes have been published to GitHub by refreshing
    your web browser.

    ![image](./hack1.0-files/pushChange.png)

Collaborating With a Team
=========================

In this exercise, you’ll need to team up with at least one other person.
You’ll make them a collaborator on your project so they can make changes
and commit/push them to *your* repository on GitHub. Alternatively you
can have them make a pull request, but these instructions do not cover
that; refer to one of the resources below for how how to make push/pull
requests.

1.  On GitHub.com, click in your project.

2.  In the left menu, click

3.  Type in your partner’s GitHub user name and click

What your collaborator needs to do
----------------------------------

Together with your partner, walk through the following steps. These
steps should be done on *their* computer.

1.  Once you’ve sent an invite to collaborate, they need to accept it.

2.  Have them navigate their web browser to your GitHub repository and
    click and select . This will launch their GitHub Desktop Client and
    check out *your* code.

3.  Have them add 2 lines of code to print their name and their major.

4.  In the GitHub Client, follow the same procedure to commit and push
    their changes to your repository using the same procedure as above.

5.  Verify their changes by refreshing your repository. You can click on
    the and if you both did everything correctly, you’ll see multiple
    commits by multiple people:

    ![image](./hack1.0-files/completedRepo02.png)

    If you click on you can see the changes for each commit:

    ![image](./hack1.0-files/completedRepo03.png)

You are *highly encouraged* to start using git/GitHub (or something
similar) for all of your future assignments but be sure to commit code
to a *private* repository so that you do not violate the department’s
academic integrity policy.

Finishing Up
------------

1.  Put *your* GitHub URL into a plain text file named . Turn this file
    in using webhandin. Each individual student will need to hand in
    their own copy and will receive their own individual grade.

2.  Verify what you handed in by running the webgrader which will
    display the contents of your file.

This version of the hack assumes that you are in the online section or
have chosen to use the CS50 IDE. The following instructions can also be
used for *any* command line version of git.

Installation
============

Git is already installed on the CS50 IDE and so no further steps are
necessary (though you will need your GitHub account). However, we do
need to do some configuration before we start.

Run the following two commands in your CS50 IDE.

Where the email and name are substituted with your own. We recommend you
use the same email as you used to sign up on GitHub.

Creating a Repository
=====================

To focus on the git process, you will create and work with a simple
"Hello World"-style program but instead of printing "Hello World", it
will print your name.

1.  Create a new folder (call it ) at the root of your File Navigator
    and within it, create a source file with code in it that prints your
    name.

2.  Make this folder (and all of its contents) into a git repository by
    *initializing* it. In the console, change directories to this newly
    created directory and execute the following command:

    It will look something like the following.

    ![image](./hack1.0-files/cl-gitinit.png)

3.  This creates a repository on your CS50 IDE server, but it does *not*
    create a repository on GitHub. We need to do this separately. Go to
    your GitHub page (<https://github.com/login> where is replaced with
    your GitHub login) and in the upper right, select .

    ![image](./hack1.0-files/cl-githubNewRepo.png)

4.  Name your repo

    ![image](./hack1.0-files/cl-githubNewRepoName.png)

5.  Go back to your CS50 IDE

6.  We now need to make our first *commit* which will commit our
    code/changes to the repository. You can make as many edits as you
    want to your source code files and save them, but you only "save"
    them to your git repo when you *commit* these changes. Enter the
    following command.

    Which will tell git to add all files in your directory (and
    subdirectories) to the "index" so that changes and updates can be
    "staged" for the next commit. Don’t worry about the jargon for now,
    essentially this just tells git to add files to its consideration.

7.  Enter the following command.

    This commits your changes to the *local* repository (the repository
    on the CS50 IDE server). It should look something like the
    following.

    ![image](./hack1.0-files/cl-gitcommit)

8.  We will now *push* these changes to your *remote* GitHub repository.
    First, we need to specify your GitHub repository as the remote.
    Execute the following command:

    where is replaced with your GitHub login.

9.  Now we can push your commit(s) to the remote repository with the
    following command:

    It will likely prompt you for your GitHub login and password. Enter
    them and if successful, it should look something like the
    following.[^1]

    ![image](./hack1.0-files/cl-gitPush)

10. Your repository should now be on GitHub. Point your web browser to
    <https://github.com/login/hello> where is replaced with your GitHub
    user name. You can browse your repository, view its history, etc.

Git Ignore
----------

Often times there will be files or *artifacts* that you want to create,
save and work with in your file system *but* you don’t want them
committed to the repository. For example, when you compile your program,
you probably don’t want the executable file, to be committed to the repo
as you can always rebuild it. The executable file is not part of your
source code, but an *artifact* of your code. In general, we want git to
*ignore* these artifacts.

To do this, we can create a file. This is simply a plain text file that
contains file and directory names that git will ignore.

1.  In your CS50 IDE in the directory create a new file named .

2.  Edit it and add on a single line. Save this file.

3.  Commit and push this new file to your local and remote repositories
    by executing the series of commands:

    ``` {.text}
      git add .gitignore
      git commit -m 'added gitignore file'
      git push -u origin master
      
    ```

    It should look something like the following.

    ![image](./hack1.0-files/cl-gitignore)

There are many standard files for various types of projects that you may
find useful: <https://github.com/github/gitignore>

Making Changes
==============

You’ll often make changes to you code that you should periodically
commit to your repository. Though you may make changes and save them to
a file, the changes are not saved to the repository’s history.
Committing is the action that does this. Committing only changes your
*local* repository, the changes will still need to be *pushed* to
GitHub. In this activity you’ll make changes, commit them and then push
them to GitHub.

1.  Open the file and add a line that prints your major. Also, change
    the line that prints your name (add an exclamation point at the end
    or something). Be sure to save your file and compile and run your
    program to be sure it is correct.

2.  Git can automatically track these changes, to display the changes in
    your console execute the following command.

    Git will display all the changed files that are not yet *staged*
    (not yet added to the index to be committed). It should look
    something like the following.

    ![image](./hack1.0-files/cl-gitstatus)

    Note that the file is not listed (git is ignoring it as we directed
    it to!).

3.  Another useful tool allows you to view the changes or *differences*
    to a file. Execute the following command.

    It should look something like the following. Deletions (or edits)
    are displayed in red and additions in green.

    ![image](./hack1.0-files/cl-gitdiff)

4.  We can now commit and push our changes in the same way as our
    initial commit. Execute the following series of commands.

    ``` {.text}
      git add hello.c
      git commit -m 'added my major to the output'
      git push -u origin master  
      
    ```

Some observations/notes:

-   In our last commit, we did not use which would have added all
    (non-ignored) files. Adding everything at once can be convenient but
    in general commits should only include *related* changes and should
    be as *fine grained* as possible. You should not use commits as a
    catch-all/save-all operation.

-   You should *always* provide a good, descriptive commit message that
    accurately reflects your changes. Commit messages provide good
    documentation on your changes. For example, when fixing a bug, the
    commit message should reference the original issue or bug report.

Collaborating With a Team
=========================

In this exercise, you’ll need to team up with at least one other person.
You’ll make them a collaborator on your project so they can make changes
and commit/push them to *your* repository on GitHub. Alternatively you
can have them make a *pull request*, but these instructions do not cover
that; refer to one of the resources in the section for how how to make
push/pull requests.

1.  On the GitHub webpage, click in your project.

2.  In the left menu, click

3.  Click and type in your partner’s GitHub user name and click

What your collaborator needs to do
----------------------------------

Together with your partner, walk through the following steps. These
steps should be done on *their* computer.

1.  Once you’ve sent an invite to collaborate, they need to accept it.

2.  Your partner should create a new directory at the root of their CS50
    IDE (or whatever they are using) to hold *your* repository.

3.  Your partner should execute the following command inside of the new
    directory:

    Where again is replaced with your GitHub login. This clones the
    *remote* repository and now you have a *local* version of it!

4.  Your partner should add 2 lines of code to print their name and
    their major.

5.  Your partner should follow the same procedure to commit and push
    their changes to *your remote* repository using the same procedure
    as they did with theirs.

6.  Verify their changes by refreshing your repository on GitHub. You
    can click on the and if you both did everything correctly, you’ll
    see multiple commits by multiple people:

    ![image](./hack1.0-files/completedRepo02.png)

    If you click on you can see the changes for each commit:

    ![image](./hack1.0-files/completedRepo03.png)

Now, go back to *your* CS50 IDE. Remember, your partner’s changes were
*pushed* to your *remote* repository hosted on GitHub. If you look at
your file you won’t see their changes because this is your *local*
repository.

In order to get your partner’s changes you’ll need to *pull* their
changes from your remote repository to your local repository. To do
this, run the following command:

As long as there are no conflicting changes, all of your partner’s
changes should now be reflected in your local repository. Of course,
you’ll need to repeat this process for your partner’s repository (add
your name/major to their and commit it so they can pull your changes).

You are *highly encouraged* to start using git/GitHub (or something
similar) for all of your future assignments but be sure to commit code
to a *private* repository so that you do not violate the department’s
academic integrity policy.

Finishing Up
------------

1.  Put *your* GitHub URL into a plain text file named . Turn this file
    in using webhandin. Each individual student will need to hand in
    their own copy and will receive their own individual grade.

2.  Verify what you handed in by running the webgrader which will
    display the contents of your file.

Additional Instructions {#additional-instructions .unnumbered}
=======================

-   You are encouraged to collaborate with any number of students
    before, during, and after your scheduled hack session.

-   Each student is responsible for *their* repository, so if/when you
    team up with a partner, you’ll need to go through this Hack at least
    twice: once as the primary repository owner and once as a
    collaborator.

Additional Resources {#section:additionalResources .unnumbered}
====================

-   Video tutorial on Github Desktop:
    <https://www.youtube.com/watch?v=kFix7UDJ7LA>

-   Interactive git tutorial:
    <https://try.github.io/levels/1/challenges/1>

-   Pro Git, free online book: <https://git-scm.com/book/en/v2>

[^1]: Note, you *can* configure git to save your username and password;
    see
    <https://stackoverflow.com/questions/35942754/how-to-save-username-and-password-in-git-gitextension>
    for instructions. However, since CS50 IDE is a remote server you’d
    be saving your password in plaintext (very bad idea). That same link
    has instructions for using an SSH Key instead which is recommended.
