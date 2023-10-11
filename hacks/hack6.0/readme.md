# Hack 6.0 - Functions, Error Handling & Unit Testing
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
other students or groups. You may not share code directly outside your
pair.

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
 - Your program(s) *must* compile and run on the grader
 - 16 points for the cmocka tests: you must pass all and there should be
   at least 27 total; cmocka must be used, no custom testing
   - 12 points for our tests
   - 4 points for your tests (-4 if no original)

# Problem Statement

In this hack you'll get some more practice writing functions that
utilize pass-by-reference (pointers), error handling and enumerated
types. There are several different ways to model colors including RGB
and CMYK. RGB is generally used in displays and models a color with
three values in the range $[0, 255]$ corresponding to the red, green and
blue "contribution" to the color. For example, the triple
$(255, 255, 0)$ corresponds to a full red and green (additive) value
which results in yellow. CMYK or Cyan-Magenta-Yellow-Black is a model
used in printing where four colors of ink are combined to make various
colors. In this system, the four values are on the scale $[0, 1]$. Write
functions to convert between these models.

1.  Write a function to convert from an RGB color model to CMYK. To
    convert to CMYK, you first need to scale each integer value to the
    range $[0, 1]$ by computing
    $$r' = \frac{r}{255}, \quad g' = \frac{g}{255}, \quad b' = \frac{b}{255}$$
    and then using the following formulas:

    $$k = 1-\max\{r', g', b'\}$$
    $$c = \frac{(1-r'-k)}{(1-k)}$$
    $$m = \frac{(1-g'-k)}{(1-k)}$$
    $$y = \frac{(1-b'-k)}{(1-k)}$$

    Your function should have the following signature:

    `int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k)`

    Identify any and all error conditions and use the return value to
    indicate an error code (0 for no error, non-zero value(s) for error
    conditions). Note that one edge case is black, when
    $(r,g,b) = (0,0,0)$ which would lead to a division by zero in the
    formulas. The equivalent CMYK values are $(0,0,0,1)$.

2.  Write a function to convert from CMYK to RGB using the following
    formulas.

    $$r = 255 \cdot (1 - c) \cdot (1-k)$$
    $$g = 255 \cdot (1 - m) \cdot (1-k)$$
    $$b = 255 \cdot (1 - y) \cdot (1-k)$$

    Results should be rounded. Your function should have the following signature:

    `int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b)`

    Identify any and all error conditions and use the return value to
    indicate an error code (0 for no error, non-zero value(s) for error
    conditions).

# Instructions

-   You may (in fact are encouraged) to define any additional "helper"
    functions that you find useful.

-   Place your prototypes and documentation in a header file named
    `colorUtils.h` and your source in a file named
    `colorUtils.c`.

-   A testing file, `utilsTester.c` has been provided that uses
    cmocka (<https://cmocka.org/>), a unit testing framework for C. We
    have already written several (24) test cases for you. Using these
    examples, implement your *at least 3 more* test cases using cmocka
    for your two functions for a total of *at least* 27.

    The starter file should be sufficient to demonstrate how to use
    cmocka, but the full documentation can be found here:
    <https://api.cmocka.org/>. A `makefile` has also been
    provided to help you easily compile your files.
