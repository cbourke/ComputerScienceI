
# CSCE 155H - Computer Science I
## Algorithms, Searching & Sorting
### Fall 2025

# Introduction & Demonstration

* Huge part of Computer Science: data processing
* Fundamental operations: *searching*, *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed  

## Demo

* Demo: write a function to search a collection for a particular element
  * What is a collection? Array, list, etc.
  * What is an element?  `int, double, char, Student, Book`, etc.
  * What is your criteria?  ISBN, ratings, authors, etc.
  * The first one, second, last, all of them?
  * Minimum/Maximum/Median
* Pseudocode: fake code

## Linear Search

* Linear Search makes no assumptions about the input
* It simply checks every element until the end
* It sometimes gets lucky, but in the worst case it will make $n$ comparisons for a collection of size $n$
* It has a linear rate of growth
* For an array 10 times bigger, it will take 10 times longer

## Binary Search

* Is there a better way?
* If the array is sorted, then you can exploit that *structure*
* Idea:
  * You look at the middle element $m$
  * If that is what you are looking for, DONE
  * If the key $k < m$: search the left half
  * If the key $m < k$: search the right
  * Repeat until you either find it, or you have an empty array (unsuccessful search)

## Analysis

*  Linear search takes about $n$ comparisons to compute
* Binary search takes about $\log{(n)}$ comparisons
* Binary search is *expoentially* faster
* But: binary search requires the array to be sorted

# Sorting

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
* Complexity: $\approx n^2$ comparisons
* That means that every order of magnitude larger: 10x larger is going to be 100 times slower!

### Quick Sort

* You divide and conquer:
  * Choose a "pivot" element
  * Place elements LESS than the pivot to the left, greater to the right
  * "Recurse" on the left/right "partition"
  * until the size os $\leq 1$
* Quick sort makes (on average) $n\log{n}$ comparisons!


```text













```
