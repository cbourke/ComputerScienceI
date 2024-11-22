
# CSCE 155H - Computer Science I
## Algorithms, Searching & Sorting
### Fall 2024

# Introduction & Demonstration

* Huge part of Computer Science: data processing
* Fundamental operations: *searching*, *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed  

## Demo

* Demo: write a function to search a collection for a particular element
  * Collection: array?  list? set?
  * searching/particular element: integers? doubles? students, books?
  * What criteria? ISBN, highest rating, etc.

## Linear & Binary Search

* Linear search uses $\approx n$ comparisons to search
* Binary search uses $\log{n}$ comparisons,
  * *exponentially* faster
  * Requires the array to be sorted

## Sorting

### Selection Sort

* Complexity: $\approx n^2$ comparisons

### QUick Sort

* YOu divide and conquer:
  * Choose a pivot element
  * Place elements less than it to the left, greater than it to the right
  * Recurse on the left/right "partition"
  * until the size of the subarray is $\leq 1$
* Quick sort makes (on average) $n\log{n}$ comparisons!

```text











```
