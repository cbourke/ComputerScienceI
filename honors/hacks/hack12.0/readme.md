---
date:  
subtitle: |
  Computer Science I -- Java\
  Recursion & Memoization\
  Department of Computer Science & Engineering\
  University of Nebraska--Lincoln
title: Hack 12.0
---

------------------------------------------------------------------------

# Problem Statement {#problem-statement .unnumbered}

A binomial coefficient, "$n$ choose $k$" is a number that corresponds to
the number of ways to *choose* $k$ items from a set of $n$ distinct
items. You may be familiar with some the notations, $C(n,k)$ or $C_n^k$
or ${}_{n}C_k$, but most commonly this is written as $${n \choose k}$$
and read as "$n$ choose $k$". There is an easy to compute formula
involving factorials: $${n \choose k} = \frac{n!}{(n-k)!k!}$$ For
example, if we have $n = 4$ items, say $\{a, b, c, d\}$ and want to
choose $k=2$ of them, then there are
$${4 \choose 2} = \frac{4!}{(4-2)!2!} = 6$$ ways of doing this. The six
ways are: $$\{a, b\}, \{a, c\}, \{a, d\}, \{b, c\}, \{b, d\}, \{c, d\}$$
There are a lot of other interpretations and applications for binomial
coefficients, but this hack will focus on computing their value using a
different formula, Pascal's Rule[^1]:
$${n \choose k} = {n-1 \choose k} + {n-1 \choose k-1}$$ which is a
recursive formula. The base cases for Pascal's Rule are when $k = 0$ and
$n = k$. In both cases, the value is 1. When $k = 0$, we are not
choosing any elements and so there is only one way of doing that
(i.e. choose nothing). When $n = k$ we are choosing every element, again
there is only one way of doing that.

## Writing a Naive Recursion {#writing-a-naive-recursion .unnumbered}

Create a class named `Binomial`{.text} and implement and test the
following method *using a recursive* solution:

`public static long choose(int n, int k)`{.java}

which takes $n$ and $k$ and computes ${n\choose k}$ using Pascal's Rule.
Note that the return type is a `long`{.java} which is a 64-bit integer
allowing you to compute values up to
$$2^{63}-1 = 9,223,372,036,854,775,807$$ (a little over 9 quintillion).
Write a `main`{.java} method that takes $n$ and $k$ as command line
arguments and outputs the result to the standard output so you can
easily test it.

## Benchmarking {#benchmarking .unnumbered}

Run your program on values of $n, k$ in Table
[1](#table:easyValues){reference-type="ref"
reference="table:easyValues"} and time (roughly) how long it takes your
program to execute. You can check your solutions with an online tool
such as <https://www.wolframalpha.com/>.

::: {#table:easyValues}
   $n$   $k$
  ----- -----
    4     2
   10     5
   32    16
   34    17
   36    18

  : Test Values
:::

Now formulate an estimate of how long your program would take to execute
with larger values. You can make a *rough* estimate how many method
calls are made using the binomial value itself. That is, to compute
${n \choose k}$ using Pascal's Rule would make *about* ${n \choose k}$
method calls.

Use the running time of your program from the test values to estimate
how long your program would run for the values in Table
[2](#table:hardValues){reference-type="ref"
reference="table:hardValues"}.

::: {#table:hardValues}
    ${n \choose k}$                           value
  ------------------- -----------------------------
   ${54 \choose 27}$        = 1,946,939,425,648,112
   ${56 \choose 28}$        = 7,648,690,600,760,440
   ${58 \choose 29}$       = 30,067,266,499,541,040
   ${60 \choose 30}$      = 118,264,581,564,861,424
   ${62 \choose 31}$      = 465,428,353,255,261,088
   ${64 \choose 32}$    = 1,832,624,140,942,590,534
   ${66 \choose 33}$    = 7,219,428,434,016,265,740

  : Larger Values
:::

## Improving Performance with Memoization {#improving-performance-with-memoization .unnumbered}

You'll now improve your program's performance using memoization to avoid
unnecessary repeated recursive calls.

1.  First, change your return type to use Java's `BigInteger`{.java}
    class. This is an arbitrary precision number class meaning that it
    can represent arbitrarily large integer values. You won't be able to
    use the normal arithmetic operators however. Instead, you'll need to
    RTM and use the class's methods to add and perform other operations.
    See the documentation here:
    <https://docs.oracle.com/en/java/javase/14/docs/api/java.base/java/math/BigInteger.html>

2.  To "cache" values so that you are not continually repeating the same
    calculations over-and-over you *could* use a table, but let's use a
    *smart data structure*: a `Map`{.java}.

    This map will be used to map a pair of input values, $(n,k)$ to the
    value of the binomial ${n \choose k}$. The problem is that we want
    to use the combination of two values as a single key. To do so,
    we've provided a `Pair`{.java} class that allows you to pair two
    objects together to use as a key.

    Create and instantiate a static map of the following type:

    `Map<Pair<Integer, Integer>, BigInteger>`{.java}

3.  Modify your `binomial`{.java} method to use this map to store and
    use values to avoid unnecessary repeated recursive calls. Your
    method should have the following signature:

    `public static BigInteger binomial(int n, int k)`{.java}

    When the method needs to compute ${n \choose k}$ it checks the map
    first: if the value has already been computed (is not `null`{.java})
    then it returns that value. Otherwise, it performs the recursive
    computation. Before returning the value, however, it should store it
    (*cache* it) in the map so that subsequent computations avoid the
    recursion.

4.  Rerun your program with the values in Tables
    [1](#table:easyValues){reference-type="ref"
    reference="table:easyValues"} and
    [2](#table:hardValues){reference-type="ref"
    reference="table:hardValues"} to verify they work and note the
    difference in running time.

# Instructions {#instructions .unnumbered}

-   All your code should be in the class file, `Binomial.java`{.text}
    along with full documentation.

-   You are encouraged to collaborate any number of students before,
    during, and after your scheduled hack session.

-   Include the name(s) of everyone who worked together on this activity
    in your source file's header.

-   Turn in all of your files via webhandin, making sure that it runs
    and executes correctly in the webgrader. Each individual student
    will need to hand in their own copy and will receive their own
    individual grade.

[^1]: Which can be used to generate Pascal's Triangle,
    <https://en.wikipedia.org/wiki/Pascals_triangle>
