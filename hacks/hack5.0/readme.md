# Hack 5.0 - Functions & Testing
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
 - 9 points for student test cases
 - 7 points for the official test suite

# Problem Statement

To get some practice designing and using functions, you will create a
small library of utility functions by implementing the following
functions with the given prototypes and specified functionality.

1.  `double degreesToRadians(double degree);` - Write a function to
    convert degrees to radians using the formula
    $$\frac{d\cdot \pi}{180}$$

2.  Write a function to compute the air distance between two locations
    identified by their latitude/longitude.

    ``` c
    double getAirDistance(double originLatitude,
                          double originLongitude,
                          double destinationLatitude,
                          double destinationLongitude);
    ```

    The air distance between two latitude/longitude points can be
    calculated using the Spherical Law of Cosines:
    $$d = \arccos{(\sin(\varphi_1) \sin(\varphi_2) + \cos(\varphi_1) \cos(\varphi_2) \cos(\Delta) )} \cdot R$$
    where

    -   $\varphi_1$ is the latitude of location $A$ (origin),
        $\varphi_2$ is the latitude of location $B$ (destination)

    -   $\Delta$ is the difference between location $B$'s longitude and
        location $A$'s longitude

    -   $R$ is the (average) radius of the earth, 6,371 kilometers

    Note: the formula above assumes that latitude and longitude are
    measured in radians $r$, $-\pi \leq r \leq \pi$, but the function
    will expect the latitude/longitude to be in degrees. Latitude should
    be in the range $[-90, 90]$ and longitude in the range
    $[-180, 180]$. Negative values correspond to the southern and
    western hemispheres.

3.  An object traveling at a velocity $v$ experiences time dilation
    relative to a stationary object which is quantified by the Lorentz
    equation: $$T = \frac{t}{\sqrt{(1-\frac{v^2}{c^2})}}$$ where $t$ is
    the normal amount of lapsed time (stationary object) and $T$ is the
    dilated time experienced by the traveling object. For small
    velocities, the dilation is small, but for velocities approaching a
    *percentage* (on the scale $[0, 1]$) of the speed of light, $c$, the
    dilation becomes significant.

    For example, at 25% the speed of light, a year for the object
    traveling would correspond to 1.032796 years at the stationary
    object (or nearly 12 extra days). A person traveling at high
    velocity would experience "slowed" time relative to the stationary
    *frame*.

    Implement a function to compute the dilated time given the normal
    time $t$ (units may vary) and the *percentage* of the speed of light:

    $$\frac{v}{c}$$

    ``` c
    double lorentzTimeDilation(double t, double percentC);
    ```

# Instructions

-   Place your prototypes and documentation in a header file named
    `utils.h` and your source in a file named `utils.c`.

-   In addition, implement all of your test cases in a *test driver*
    file named `utilsTester.c` which should output the expected
    output, the actual output and a message on whether or not the test
    case passed. You must have at least 3 test cases for *each* of your
    functions. You should *not* prompt for input or use command line
    arguments. Your test cases should be hardcoded in your test driver's
    `main` function.
