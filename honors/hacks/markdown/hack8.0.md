
# Hack 8.0
**Computer Science I**
> Department of Computer Science & Engineering  
> University of Nebraska–Lincoln  
> Java Version
------------------------------------------------------------------------

## Problem Statement

To get more practice working with strings, you will write several
functions that involve operations on strings. In particular, implement
the following functions with the described behavior. You *must* use the
given signatures.

1.  Write a function that replaces instances of a given character with a
    different character in a string.\
    \
    Which will replace any instance of the character stored in with the
    character stored in in the string .

2.  Write a function that takes a string and creates a new copy of it
    but with instances of a given character replaced with a different
    character.\
    \

3.  Write a function that takes a string and removes all instances of a
    certain character from it.\
    \
    When removing characters, all subsequent characters should be
    shifted down. Take care that you handle the null terminating
    character properly.

4.  Write a function that takes a string and creates a new copy of it
    but with all instances of a specified character removed from it.\
    \
    Take care that the new copy does not waste memory.

5.  Write a function that takes a string and splits it up to an *array*
    of strings. The split will be length-based: the function will also
    take an integer $n$ and will split the given string up into strings
    of length $n$. It is possible that the last string will not be of
    length $n$. You will not need to communicate how large the resulting
    array is as the calling function knows the string length and $n$.\
    For example, if we pass

    with $n = 3$ then it should return an array of size 9 containing the
    strings , , , , , , , ,

Instructions {#instructions .unnumbered}
============

-   Place all your function prototypes into a file named and and their
    definitions in a file named .

-   In addition, create a main test driver program called that
    demonstrates at least 3 cases per function to verify their output.
    Hand in your tester.

-   You are encouraged to collaborate any number of students before,
    during, and after your scheduled hack session.

-   You may (in fact are encouraged) to define any additional “helper”
    functions that may help you.

-   Include the name(s) of everyone who worked together on this activity
    in your source file’s header.

-   Turn in all of your files via webhandin, making sure that it runs
    and executes correctly in the webgrader. Each individual student
    will need to hand in their own copy and will receive their own
    individual grade.
