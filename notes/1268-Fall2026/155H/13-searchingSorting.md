
# CSCE 155H - Computer Science I
## Algorithms, Searching & Sorting
### Fall 2026

# Introduction & Demonstration

* Huge part of Computer Science: data processing
* Fundamental operations: *searching*, *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed  

## Demo

* Demo: write a function to search a collection for a particular element
  * What is a collection? List, array, set, etc.
  * What is an element?  `int, double, char, Student, Book`, etc.
  * What is your criteria?  ISBN, ratings, authors, etc.
  * The first one, second, last, all of them?
  * Minimum/Maximum/Median
* Pseudocode: fake code

## Linear Search

* Linear Search makes no assumptions about the input
* It simply checks every element until the end
* Brute force: it searches until it finds what it is looking for or all elements have been examined
* Sometimes it is lucky: you make one comparison and you are done!
* Worst case scenario: you make $n$ comparisons (last element matches or unsuccessful search)
* $t(n) = n$: linear function, thus "linear" search
* Consequences:
  * Suppose $n$ is "large": $n = 1M$, that means there are up to $1M$ comparisons
  * Suppose $n \rightarrow 10n$ how many more comparisons does it now make?  10 times as many operations or 10 times as slow
  * What is the "growth rate" of such a function?
* Is there a better way?

## Binary Search

* If the array is sorted, then you can exploit that *structure*
* Idea:
  * You look at the middle element $m$
  * If $m = e_k$: done, successful search
  * If $e_k < m$: search the left half
  * If $m < e_k$: search in the right half
  * Repeat until you either find an element (stop) OR you end up with an empty sub-array (unsuccessful search)
* Observation: binary search fails if the array is not sorted!  How do we sort?


### Analysis

* How much better is binary search than linear search?
* Aside: you can write a non-recursive version of binary search
* Non-trivial fact: binary search only requires about $\log_2{n}$ comparisons
* If you go from $n$ to $10n$, there are only a few more comparisons (not 10 times slower)
* The rate of growth is *diminishing* as $n$ grows
* Linear search is *exponentially* slower than binary search

# Sorting

* Given an (ordered) collection of elements, rearrange them so that they are sorted (according to some criteria)
* Lots of different sorting algorithms, each with different properties
* We'll examine two of them...

### Selection Sort

* Each iteration you select the minimum among the remaining elements and place it where it needs to be
* First iteration: $i = 0$
  * Search elements $0\ldots n-1$ for the minimum, $m$
  * Swap $a_0$ and $m$
* Second iteration: $i = 1$
  * Search elements $1\ldots n-1$ for the minimum, $m$
  * Swap $a_1$ and $m$
* Third iteration: $i = 2$
  * Search elements $2\ldots n-1$ for the minimum $m$
  * Swap $a_2$ and $m$
* $i$-th iteration:
  * Search elements $i\ldots n-1$ for the minimum $m$
  * Swap $a_i$ and $m$
* Repeat for $i = 0, \ldots n-2$

### Quick Sort

* You divide and conquer:
  * Choose a "pivot" element
  * Place elements LESS than the pivot to the left, greater to the right
  * "Recurse" on the left/right "partition"
  * until the size is $\leq 1$
* Quick sort makes (on average) $n\log{n}$ comparisons!
  * Quasilinear


```text















```
