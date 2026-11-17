
# CSCE 155E - Computer Science I
## Searching & Sorting
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
* How much time/effort/resources does this searching take?
  * How many comparisons does the algorithm make?

### Analysis

* Best case scenario: you get lucky and find it at the first element: number of comparisons: 1
* Worst case scenario: you make $n$ comparisons
* Average case scenario: $\approx \frac{n}{2}$
* In either case, there will be a *linear* growth rate for all inputs
* Input of size $n$ to $10n$: how many more comparisons would we have to make? You would make 10 times more comparisons = 10 times more work = 10 times slower
* This algorithm is called *linear search*

## Linear Search

* Linear Search makes no assumptions about the input
* It simply checks every element until the end
* Brute force: it searches until it finds what it is looking for or all elements have been examined
* Consequences:
  * Suppose $n$ is "large": $n = 1M$, that means there are up to $1M$ comparisons
  * Suppose $n \rightarrow 10n$ how many more comparisons does it now make?  10 times as many operations or 10 times as slow
* Is there a better way?

## Binary Search

* If the array is sorted, then you can exploit that *structure*
* Idea:
  * You look at the middle element $m$
  * If $m = k$: done, successful search
  * If $k < m$: search the left half of the array
  * If $m < k$: search in the right half of the array
* Each iteration cuts the size of the array in half!
* You continue until: you find what you are looking for OR you have an empty (sub)array, unsuccessful

### Analysis

* How much better is binary search than linear search?
* Aside: you can write a non-recursive version of binary search
* Non-trivial fact: binary search only requires about $\log_2{n}$ comparisons
* If you go from $n$ to $10n$, there are only a few more comparisons (not 10 times slower)
* THis is exponentially faster than linear search
* Clearly a sorted array is better than an unsorted array
* How do we sort? 

```text














```
