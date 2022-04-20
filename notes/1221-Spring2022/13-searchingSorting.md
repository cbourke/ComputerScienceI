
# ECEN 1940 - Computer Science I
## Searching & Sorting
### Spring 2022

## Introduction

* Processing data is a fundamental operation in Computer Science
* Two fundamental operations in processing data are *searching* and *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed

### Algorithms

* An Algorithm: a finite sequence of operations that defines a computational process for solving a problem
* All algorithms must be *correct*
* Algorithms != problems
* There may be more than one correct algorithm in which case you have other considerations: efficiency or complexity

## Searching

* Given a collection of elements $A = \{a_1, a_2, \ldots, a_n\}$ and a key $k$ element you want to search the collection to see if any element in it *matches* $k$
* In the context of C:
  * A collection is an array (0-indexing)
  * An element in the array is a `int` or `double` or `Airport`
  * Eventually: we will want a "generic" solution that can be "polymorphically" applied to any type
  * For now: consider just `int`s
  * Matching means (for `int`): `==`
  * Strings?  `strcmp`
* Demonstration: create a search function for integers.

## Design Considerations

* *What* are we searching: an array, or other data structure?  What are we searching for?  `int`, `double`, string, etc?  
* *HOW* are you searching:
  * Do you find the first?  The last?  Every instance?
  * If you have a structure: how do you match a structure?  Ex: `Airport`; criteria: lat/long, size, name, GPS ID, etc.
* What do you do for an unsuccessful search?

## Linear Search

* A linear search algorithm searches through a collection to find an element that matches a key
* How "efficient" or "complex" is linear search?
* In the worst case, linear search makes $n$ comparisons on an array of $n$ elements
* In the average case, linear search makes $\frac{n}{2}$ comparisons
* Perspective:
  * For an array of $n = 10^{12}$ (1 trillion) elements, it makes about 1 trillion comparsions in the worst case, 500 billion in the average case
  * Consider the *growth rate* of the number of comparisons vs the size of the array
  * For linear search, either average or worst, doubling the input size doubles the time it takes to execute; increasing an order of magnitude: $n \rightarrow 10n$, requires ten times as much time to execute, etc.

## Sorting

### Selection Sort

* Basic Idea:
  * Go through the array, select the smallest element and swap it with the first element
  * Repeat: go through the array, find the (i-th smallest) next smallest element, swapt it with the i-th element
  * We start by examining the entire array: elements 0 thru n-1 (finding the smallest among them), swap it with `arr[0]`
  * Second iteration: we examing elements `arr[1]` thru `arr[n-1]`, find the smallest element, swap it with `arr[1]`
  * Third iteration: we examin elements `arr[2]` thru `arr[n-1]`, finding the smallest element, swap it with `arr[2]`
  * `i`-th iteration: examine elements `arr[i]` thru `arr[n-1]` swap it with `arr[i]`
  * Stop when `i = n-2`

### Quick Sort

* It is quick!
* Idea: choose a pivot element (say the first element)
* Partition around that element
* LEFT SIDE: [4, 9, 4, 34, 12, 2, 0 ] -42- RIGHT SIDE: [102]
* Second iteration: [4, 9, 4, 34, 12, 2, 0], pivot: 4
* Partition: LEFT: [4, 2, 0] -4- RIGHT: [9, 34, 12]
* Divide and conquer algorithm: you partition around the pivot and recursively sort each sub array on each side until you reach an subarray of size of size 1 (or 0), stop
* Analysis: omitted (beyond the scope of this course)
* End result: quick sort makes about $n\log{n}$ comparisons

```text











```
