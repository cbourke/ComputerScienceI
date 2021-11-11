
# CSCE 155E - Computer Science I
## Searching & Sorting
### Fall 2021

# Introduction

* Algorithm: a finite sequence of operations that defines a computational process for solving a problem
* All algorithms must be *correct*
* Algorithms != Problems
* There may be more than one "correct" algorithm that solves  a problem
* Not all algorithms are created equally
* Some algorithms are more efficient than others
* Ex: Maliciously Compliant painter

## Searching

* Given a collection of elements and a *key* element $k$ you want to search the collection to see if any element *matches* $k$
* In the context of C:
  * A collection is an array
  * An element is simply an item in the array (to start out with, we'll consider integers)
  * A key is an element of the same type
  * "Matches"? integers: `==`, for strings: `strcmp`, airports?
* Let's start with a search function for integers...

### Design Considerations

* *What* are you searching: an array, or other data structure?  Strings?  Integers?  Airports?  etc.
* *How* are you searching:
  * Do you find the first one, the last one, all of them?
  * If you have a structure, `Airport`: how do you know the airport matches your search criteria
  * Criteria:
    * You could find the first, last, (max or min)
    * You can search based on a structure's state: partially or wholly, etc.
  * What do you do for an unsuccessful search?

## Linear Search

* A linear search algorithm searches through a collection to find an element that matches a key
* The complexity of an algorithm in general is the amount of work or resources that the algorithm uses to perform its computation
* Linear search: the idea of "work" is time
* What takes time in our linear search implementations?
  * The amount of work = number of comparisons made by the algorithm
* How many comparisons does linear search execute on an array of size $n$?
  * Best case scenario: you find it at index 0, performing only 1 comparison
  * Worst case scenario: you find it at the last index or you don't find it at all, resulting in $n$ comparisons
  * Average case: you will likely make about $\approx \frac{n}{2}$ comparisons
* Linear search makes a linear number of comparisons
* If you increase the input size (the size of the input array) then the amount of work increases by a linear amount
* Size: n -> 10n; suppose an input of n took 10 seconds, an input of 10n takes 100 seconds!

## Binary Search

* A *sorted* array has *structure* that can be exploited
* Idea:
  * Examine the middle element, if it matches the key, stop (you found what you're looking for)
  * If the middle element is greater than the element you are search for, repeat your search in the lower half (left half)
  * If the middle elements is less than the element you are searching for, repeat your search in the upper half (right half)
  * repeat until you found what you are looking for OR you don't find it and the array "partition" is now empty
* In either case, you have cut the input in half each time
* this is a divide and conquer style algorithm
* Recursive implementation
* Non-recursive implementation

### Analysis

* For an array of size $n$, we perform at most $\log{(n)}$ comparisons!
* Contrast that with linear search: $n$ comparisons


## Selection Sort

* Basic idea:
  * go through and find the smallest element and swap it with the first
  * go through the remaining $n-1$ elements and find the smallest among those, swapping it with the second
  * repeat until you have the first $n-1$ sorted
  * The last element will be where it needs to be!

## Quick Sort

* It is quick!

## Searching & Sorting in Practice

* In general, you do not need or want to write your own searching/sorting algorithms
* Lots of copy-pasta for different types
* Lots of testing
* Lots of debugging, etc.
* Don't roll your own!
* qsort and other built-in algorithms know how to sort, they just don't know how to *order*
* They don't know what the elements are in the given array, they coudl be integers, doubles, films, etc.
* `qsort` needs to be told how to order those *things*
* A comparator function solves this problem
* A comparator function takes two generic *things* $a, b$ and returns an integer:
  * *Something* negative if $a$ comes before $b$
  * ZERO if $a$ "equals" $b$
  * *Something* positive if $a$ comes after $b$ ($b$ comes before $a$)





```text





```
