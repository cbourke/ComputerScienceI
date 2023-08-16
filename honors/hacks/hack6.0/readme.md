# Hack 6.0 - Functions, Error Handling & Unit Testing
## Java Edition
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
 - 16 points for the JUnit tests: you must pass all and there should be
   at least 115+3 = 118 total; JUnit must be used, no custom testing
   - 4 points for writing 3 of your own test methods (you must use JUnit)
   - 12 points for our tests (115 total)

# Problem Statement

In this hack you'll get some more practice writing methods, error
handling and enumerated types. There are several different ways to model
colors including RGB and CMYK. RGB is generally used in displays and
models a color with three values in the range $[0, 255]$ corresponding
to the red, green and blue "contribution" to the color. For example, the
triple $(255, 255, 0)$ corresponds to a full red and green (additive)
value which results in yellow. CMYK or Cyan-Magenta-Yellow-Black is a
model used in printing where four colors of ink are combined to make
various colors. In this system, the four values are on the scale
$[0, 1]$. Write functions to convert between these models.

1.  Write a function to convert from an RGB color model to CMYK. To
    convert to CMYK, you first need to scale each integer value to the
    range $[0, 1]$ by simply computing
    $$r' = \frac{r}{255}, \quad g' = \frac{g}{255}, \quad b' = \frac{b}{255}$$
    and then using the following formulas:

    $$k = 1-\max\{r', g', b'\}$$
    $$c = \frac{(1-r'-k)}{(1-k)}$$
    $$m = \frac{(1-g'-k)}{(1-k)}$$
    $$y = \frac{(1-b'-k)}{(1-k)}$$

    Your method should have the following signature:

    `public static CMYK rgbToCMYK(RGB color)`

    Note that one edge case is black, when $(r,g,b) = (0,0,0)$ which
    would lead to a division by zero in the formulas. The equivalent
    CMYK values are $(0,0,0,1)$.

2.  Write a function to convert from CMYK to RGB using the following
    formulas.

    $$r = 255 \cdot (1 - c) \cdot (1-k)$$
    $$g = 255 \cdot (1 - m) \cdot (1-k)$$
    $$b = 255 \cdot (1 - y) \cdot (1-k)$$

    Results should be rounded. Your method should have the following signature:

    `public static RGB cmykToRGB(CMYK color)`

The `RGB` and `CMYK` classes have been provided for you.
See the `main` method of each class for examples on how to create
and use *instances* of each class.

Place both methods in a source file named `ColorUtils.java` in
the package `unl.soc`. For both methods, identify any and all
error conditions and throw an `IllegalArgumentException` with an
appropriate error message.

# Instructions

-   You may (in fact are encouraged) to define any additional "helper"
    functions that you find useful.

-   A testing file, `ColorUtilsTests.java` has been provided that
    uses JUnit (<https://junit.org/junit5/>), a unit testing framework
    for Java. We have already written several test cases for you. Using
    these examples, implement your test cases using JUnit for your two
    functions. You are required to add at least 3 test methods.

    The starter file should be sufficient to demonstrate how to use
    JUnit, but the full documentation can be found here:
    <https://junit.org/junit5/docs/current/api/>.  Instructions
    on how to add JUnit to your Eclipse project can be found below.

-   Turn in both `ColorUtils.java` and `ColorUtilsTests.java` source files.

# Installing and Using JUnit 5 in Eclipse

## Installing

First, we need to add the JUnit library to your project.

1. Right-click your project in the Project Explorer
2. Select "Build Path" and then "Add Libraries..."
3. Select JUnit then "Next"; make sure to select JUnit 5 and click "Finish"

You should be able to copy any provided JUnit source code
into your project now.  

## Using JUnit

To run a JUnit test suite, simply open the testing file and hit the
"play" button as you would a normal program.  Eclipse will
automatically compile a report of the number of tests passed or
failed along with any messages provided for failed test cases.

Note that there is no `main` method in a JUnit test suite.  Instead,
JUnit uses "reflection" to automatically find unit tests (methods
identified by the `@Test` annotation) and run them.  

## Other Items

### Manually Installing

If for some reason JUnit 5 is not available as an option, you can download
and install it manually in your project.  

* On the JUnit website, https://junit.org/junit5/ click the "Platform" tag
  under the "Latest Release" section
* Click the download icon for "junit-platform-console-standalone" and select
"jar" (this should download a file named `junit-platform-console-standalone-1.7.0.jar`)
* Create a `lib` folder in your Eclipse project and drag/drop/copy the downloaded
jar file to this directory.
* Right click the copied jar file and select "Build Path" and then "Add to Build Path"

### Project Setup

In larger Java projects it is typical to keep source code and
testing code in separate locations.  With JUnit this is usually
done by putting source code in a `src/main/java` folder and JUnit
test code in a `src/test/java` folder.  In addition, JUnit tests are
usually located in the same package structure as the classes
they are testing.

To setup your Eclipse project this way:
1. Right-click your project and select "Build Path" and select "New Source Folder"
2. Create the source folder `src/main/java` (repeat this for `src/test/java`)
3. Move any code you might have had in the original `src` folder to the appropriate new folder
