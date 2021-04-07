
# Hack 7.0
**Computer Science I**
> Department of Computer Science & Engineering  
> University of Nebraska–Lincoln  
> Java Version
------------------------------------------------------------------------

## Problem Statement

To get more practice working with arrays, you will write several
functions that involve operations on arrays. In particular, implement
the following functions.

1.  Write a function that, given an integer array and an integer $x$
    determines if the array contains $x$ anywhere within the array. It
    should return true if it does, false otherwise.

2.  Write a function that, given an integer array and an integer $x$,
    determines if the array contains $x$ within the range of the two
    provided indices $ i\;and\; j $ (including both indices). It should
    return true if it does, false otherwise.

3.  Write a function that, given an array of integers, its size and a
    “new size” creates a new deep copy of the array. However, instead of
    its original size, the new array should be of the new size. If the
    new size is less than the old size, only the first elements should
    be copied over. If the new size is greater than the original size,
    then the new array should be padded out with zeros.

4.  Write a function that, given an array of integers and its size,
    reverses the elements in the array. For example, if the original
    array was the new array should be .

5.  Write a similar function that creates and returns a new copy of the
    given array but with its elements in reverse order.

Image Manipulation {#image-manipulation .unnumbered}
------------------

You’ll get more practice with 2-dimensional arrays by writing several
functions to manipulate images. We’ve adapted a C image library, the
“stb” library, and written several *wrapper functions* to load and save
images. Wrapper functions are functions that call other functions but
may have some “glue code” to make the control flow or data compatible.
In this case, our wrapper functions convert/translate the stb library’s
image representation into an RGB pixel representation. We’ve defined a
structure that holds 3 integer values one for each of the red, green,
and blue color values. We’ll cover structures in detail later on, but it
won’t prevent you from working with them.

You can declare and use a type like you would an or :

``` {.c}
//a single pixel:
Pixel p;
//an array of n pixels:
Pixel *p = (Pixel *) malloc(sizeof(Pixel) * n);

//swap two pixels:
Pixel a, b;
...
Pixel temp = a;
a = b;
b = temp;
```

An $h \times w$ (height by width) image can be represented as a two
dimensional array of types; in particular: . Everything we’ve covered
using two dimensional arrays of types applies to types.

We’ve provided a library of functions to load and save a file (you’ll
need to RTM) and specified several function signatures for functions you
need to implement.

-   should produce a deep copy of the given image.

-   should flip the image horizontally as depicted in Figure
    \[image:pointersHFlip\].

    ![Original Image](hack7.0-files/pointers.png)

    ![Flipped
    Horizontally[]{data-label="image:pointersHFlip"}](hack7.0-files/pointersHFlip)

-   should flip the image vertically as depicted in Figure
    \[image:pointersVFlip\].

    ![Flipped
    Vertically[]{data-label="image:pointersVFlip"}](hack7.0-files/pointersVFlip)

-   should produce a new image that is rotated 90 degrees clockwise.
    This function must produce a new image because an $h \times w$ sized
    image that has been rotated will be a $w \times h$ image. This
    operation is depicted in Figure \[image:pointersRotated\].

    ![Rotated
    Clockwise[]{data-label="image:pointersRotated"}](hack7.0-files/pointersRotated)

Instructions {#instructions .unnumbered}
============

-   For the warm-up, place all your function prototypes into a file
    named and and their definitions in a file named . You will need to
    turn these in via webhandin.

-   In addition, you’ll want to create a main test driver program that
    demonstrates at least 3 cases per function to verify their output.
    You need not hand in this test file, however.

-   For the Image Manipulation section, you can use the starter code
    provided here:

    <https://github.com/cbourke/CSCE155-Hack7.0>

    However, you only need to handin and

-   You should test all your functions with an image (load it,
    manipulate it and save it) of your choice.

-   As a first step, you should add documentation to all your functions.
    Use this as an opportunity to discuss how the functions should work
    and to *whiteboard* your designs and solutions with other students.

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
