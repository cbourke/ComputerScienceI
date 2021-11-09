
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

Aside

* suppose that the algorithm was "inefficient", suppose it took $n^2$ comparisons!

```text





```
