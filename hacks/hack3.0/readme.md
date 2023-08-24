# Hack 3.0 - Conditionals
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
 - Formatting variations are fine. You need to report *just as much*
   information as the expected output.
 - Points will be awarded proportionally per test case.

# Problem Statement

A cell phone broadband provider offers monthly data plans to its
customers. Each data plan is for 30 days and each plan gives customers a
certain number of Gigabytes (GB) which must be used each month or they
are lost (no "rollover"). The provider wants to help customers
understand if they are using their monthly data too quickly or if they
can afford to use more.

In this exercise, you will write an application for the company to help
customers track their mobile data usage. Write a program that reads the
following pieces of data as *command line arguments*.

-   Number of GB in the plan per 30 day period

-   The current day in the 30 day period (in the range 1, first day, 30
    for the last day)

-   The total number of GB used so far

The program should then compute whether the customer is over, under, or
right on the *average daily usage* of their plan. It should also inform
them of how many GB are left and how many, on average, they can use per
day for the rest of the 30 day period. Of course, if they've run out of
data, it should inform them of that too.

For example, if the user enters $15, 10, 13$ for each piece of data
respectively, your program should print out something similar to the
following.

``` text
10 days used, 20 days remaining
Average daily use: 1.300 GB/day

You are EXCEEDING your average daily use (0.500 GB/day).
Continuing this high usage, you'll exceed your data plan by
24 GB.

To stay below your data plan, use no more than 0.100 GB/day.
```

If the user is under their average daily use, a different message should
be presented:

```text
1 days used, 29 days remaining
Average daily use: 0.000 GB/day

You are at or below your average daily use (33.333 GB/day).
You can use up to 34.482 GB/day and stay below your data plan limit
```

A user may have also exceeded their usage:

```text
15 days used, 15 days remaining
Average daily use: 8.667 GB/day

You have already met your limit for this month.  Looks like you're getting some overage charges...
```


# Instructions

-   Design at least 3 test cases *before* you begin designing or
    implementing your program. Test cases are input-output pairs that
    are known to be correct using means other than your program
    (a calculator, online tool, etc.).

-   Identify any error conditions (invalid number of CLAs or invalid
    values) and output an appropriate error message to the user.  Be
    sure to include the term `ERROR` in your message.  For example:
    `ERROR: invalid number of days`.

-   Name your program `dataPlan.c`, and turn it in.
    Make sure that it runs and executes correctly in the grader.
