# Hack 11.0 - Encapsulation
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
 - 5 points for student tester (it is OK to test a function
   transitively; i.e. if `createAirport` uses `initAirport`
   then you only need to test `createAirport`)
 - Remaining points distributed among several of our own test suites.


# Problem Statement

There are thousands of commercial, military, and local airports in the
US and around the world. The International Civil Aviation Organization
maintains a database of current and inactive airports around the world.
The database uniquely identifies each airport by an alphanumeric GPS
code. Further, each record contains the following pieces of data on each
airport:

-   The name of the airport

-   Its latitude in degrees in the range $[-90, 90]$ with negative
    values corresponding to the southern hemisphere

-   Its longitude in degrees in the range $[-180, 180]$ with negative
    values corresponding to the western hemisphere

-   The type of airport

-   Its elevation in (whole) feet above sea level

-   Its municipality and its country

Design a Java class to encapsulate these attributes to model an airport
record from the ICAO database. Also design several methods to support
your class including a constructor, getters, a `toString()`
method, etc. You will also implement several utility methods that use
your class to compute the air distance(s) between airport locations
using their latitude and longitude. Recall that the air distance $d$
between two latitude/longitude points can be estimated using the
Spherical Law of Cosines.

$$d = \arccos{(\sin(\varphi_1) \cdot \sin(\varphi_2) + \cos(\varphi_1) \cos(\varphi_2) \cos(\Delta) )} \cdot R$$
where

-   $\varphi_1$ is the latitude of location $A$, $\varphi_2$ is the
    latitude of location $B$

-   $\Delta$ is the difference between location $B$'s longitude and
    location $A$'s longitude

-   $R$ is the (average) radius of the earth, 6,371 kilometers

This formula assumes that latitude and longitude are in radians $r$,
$-\pi \leq r \leq \pi$. To convert from degrees $d$
($-180 \leq d \leq 180$) to radians $r$, you can use the simple formula:
$$r = \frac{d}{180} \pi$$

More details have been provided in a starter file,
`Airport.java`. You will need to design your class and implement
all of the specified methods.

# Instructions

-   In addition, you must create a main test driver program that
    demonstrates at least 3 cases per non-trivial function. Name this
    file `AirportTester.java` and hand it in.

-   You may (in fact are encouraged) to define any additional "helper"
    methods that may help you.
