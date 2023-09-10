# Hack 13.0 - Searching & Sorting
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
 - 4 points for student tester; they need 5 airports
 - 12 for official test suite

# Problem Statement

You will use the implementation of your `Airport` class from a
previous hack to develop several reports that will require you to sort
and search (a subset of) the International Civil Aviation Organization
database for particular airports.

We have provided a source file, `AirportUtils.java` with several
comparators and methods you need to implement. Details are provided in
the documentation.

The `generateReports()` takes a list of `Airport`s and
should produce the following reports which should all be output to the
standard output.

-   To help you troubleshoot, you should print out the list of airports
    in the original order to the standard output.

-   Sort the airports by each of the 8 comparators and print them out (8
    reports total).

-   Search for and print out the airport in the array that is closest
    (via air distance) to Lincoln. Lincoln is located at 40.8507N,
    96.7581W.

-   Search for and print out the airport that is the geographic
    west-east median of the given airports with respect to
    longitude.  With 0-indexed arrays, the median is the element at index
    `n/2` when sorted. This relies on truncation to give the middle
    index of odd-sized arrays and prefers the "right" element for
    even-sized arrays.

-   Search for an airport located in the city New York (city would be
    `New York` and the country would be `US`) and print it
    out if it exists. If no such airport exists, print out an
    appropriate message.

-   Search for an airport whose type is `large_airport` and print
    it out if it exists. If no such airport exists, print out an
    appropriate message.

# Instructions

-   Hand in both your `Airport.java` and
    `AirportUtils.java` source files. You may add any utility
    methods you wish but you must *not* change any of the signatures of
    the required methods.

-   In addition, you must create a `main` method in your
    `AirportUtils.java` class that tests your reports with at
    least least 5 airports.

-   You may (in fact are encouraged) to define any additional "helper"
    methods that may help you.

-   To facilitate grading, formatting your output must be done
    in a very specific way.  First, we've provided an outline of the
    `generateReports()` method that you should follow.
    Second, when you format and/or print out a single airport it should
    be on *one line* and you should print out each piece of data in order.
    Some examples:

    ```text
    OMA   normal          Eppley Airfield      41.30 -95.89 150 Omaha      US
    ORD   huge            O'Hare               41.97 -87.91 125 Chicago    US
    YYZ   large           Pearson              43.60 -79.60  25 Toronto    CN
    LGA   international   LaGuardia            40.78 -73.87  50 New York   US
    ```
