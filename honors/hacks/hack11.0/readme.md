---
date:  
subtitle: |
  Computer Science I -- Java\
  Encapsulation\
  Department of Computer Science & Engineering\
  University of Nebraska--Lincoln
title: Hack 11.0
---

------------------------------------------------------------------------

# Problem Statement {#problem-statement .unnumbered}

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
your class including a constructor, getters, a `toString()`{.java}
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
`Airport.java`{.text}. You will need to design your class and implement
all of the specified methods.

# Instructions {#instructions .unnumbered}

-   In addition, you must create a main test driver program that
    demonstrates at least 3 cases per non-trivial function. Name this
    file `AirportTester.java`{.text} and hand it in.

-   You are encouraged to collaborate any number of students before,
    during, and after your scheduled hack session.

-   You may (in fact are encouraged) to define any additional "helper"
    methods that may help you.

-   Include the name(s) of everyone who worked together on this activity
    in your source file's header.

-   Turn in all of your files via webhandin, making sure that it runs
    and executes correctly in the webgrader. Each individual student
    will need to hand in their own copy and will receive their own
    individual grade.
