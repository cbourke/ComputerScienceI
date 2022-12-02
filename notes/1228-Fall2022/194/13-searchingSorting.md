
# ECEN 194 - Computer Science I
## Searching & Sorting
### Fall 2022

## Introduction

* Processing data is a fundamental operation in Computer Science
* Two fundamental operations in processing data are *searching* and *sorting*
* Forms the basis or a preprocessing step for numerous algorithms
* Huge variety of algorithms have been developed

### Algorithms

* An Algorithm: a finite sequence of operations that defines a computational process for solving a problem
* All algorithms must be *correct* and *finite*
* Algorithms != Problems
* We can express an algorithm using *pseudocode*
* There may be more than one correct algorithm to solve a problem
* Given two or more algorithms that are *correct*; you need to then decide which one to use based on its *complexity*  or *efficiency*

## Searching

### Preliminaries

* What does searching mean?
  * What are you searching? Array? Lists, Sets, Maps, etc.
  * What are the elements that you are searching among? Integers? Doubles, chars?  Airport, Team?
  * How are you searching?
    * Student: By Name? NUID?  SSN?  GPA?
    * For a particular element, $x$
    * Maximum or minimum element?  Median?
    * Find all instances of $x$?  The first instance of $x$?  The last instance of $x$?

* Zero: $0$
* Empty Set: $\emptyset$
* Phi: $\phi$

### Linear Search

* A linear search algorithm searches through a collection to find an element that matches a key
* How "efficient" or "complex" is linear search?
* In the worst case, linear search makes $n$ comparisons on an array of $n$ elements
* In the average case, linear search makes $\frac{n}{2}$ comparisons
* Perspective:
  * For an array of $n = 10^{12}$ (1 trillion) elements, it makes about 1 trillion comparisons in the worst case, 500 billion in the average case
  * Consider the *growth rate* of the number of comparisons vs the size of the array
  * For linear search, either average or worst, doubling the input size doubles the time it takes to execute; increasing an order of magnitude: $n \rightarrow 10n$, requires ten times as much time to execute, etc.

### Binary Search

* Can we do better?
* If the array is sorted, we can cut it in half with one comparison: compare the key to the middle element
  * If equal: done
  * If key < middle: search in the left half
  * If middle < key: search in the right half
* Exponential speed up: $\approx \log{(n)}$ comparisons instead!
* Problem: requires the array to be sorted

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
  * Divide and conquer algorithm: you partition around the pivot and recursively sort each sub array on each side until you reach an subarray of size of size 1 (or 0), stop
  * Analysis: omitted (beyond the scope of this course)
  * End result: quick sort makes about $n\log{n}$ comparisons

## Searching & Sorting in Practice

* In general, you do not need or want to write your own searching/sorting algorithms
  * Lots of copy-pasta for different types
  * Lots of testing
  * Lots of debugging, etc.
  * Don't roll your own!
* `qsort` and other built-in algorithms know how to sort, they just don't know how to *order*
* The sorting algorithm doesn't know what type of elements it is sorting and therefore does not necessarily know how to *order*
* `qsort` needs to be told how to order those *things*
* A comparator function solves this problem
* A comparator function takes two generic *things* $a, b$ and returns an integer:
  * *Something* negative if $a$ comes before $b$
  * ZERO if $a$ "equals" $b$
  * *Something* positive if $a$ comes after $b$ ($b$ comes before $a$)

### Comparator Functions

* A *comparator* function is a function with the following signature

`int cmp(const void *a, const void *b)`

* It returns an integer with the following contract:
  * it returns *something* negative if a < b
  * it returns zero if a is equal to b
  * it returns *something* positive if a > b (b < a)
* `const`: the comparator will not (and cannot) make changes to the two input values
* Both are `void *` variables: a generic void pointer (it can point to any type of anything)
* If the function has *any other signature* it is NOT a comparator
* A comparator follows the same basic pattern:
  1. It typecasts the two values `a, b` into the *expected* types
  2. It makes a comparison between the state of the two variables, returning an integer value depending on the ordering

### `qsort`

* C provides a standard "quick sort" implementation

```c
void qsort(void *base,
           size_t nel,
           size_t size,
           int (*compar)(const void *, const void *));
```

* It does not return anything, it is only rearranging the array you give it
* `base`: the array you want sorted
* `nel`: the number of elements in the array
* `size`: the number of bytes each element in the array takes: use `sizeof()` to determine how many bytes each takes!
* `compar`: the comparator function that you want to use to order elements; generally: you just need to give the function's name

#### Binary Searching in C

* The standard library has a binary search implementation:

```c
void *bsearch(const void *key,
              const void *base,
              size_t nmemb,
              size_t size,
              int (*compar)(const void *, const void *));
```         

* Returns a pointer to **AN** element that matches the key
* Returns `NULL` if no such element           
* The first argument is a pointer to a key that you are searching for
* There is a `const` keyword in front of the array
* Otherwise it is exactly the same as `qsort`




```text










```
