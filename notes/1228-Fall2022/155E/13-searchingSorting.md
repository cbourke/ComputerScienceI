
# CSCE 155E - Computer Science I
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
* There may be more than one correct algorithm in which case you have other considerations: efficiency or complexity

## Searching

### Preliminaries

* What does searching mean?
  * what are you searching?  Array?  List, Set, Map, etc.
  * What are the elements you are searching among? integers? doubles? char?, Airports?  Teams?
  * How are you searching?
    * Students: Name?  NUID, SSN, GPA
    * Particular element $x$?
    * Maximum or minimum or median element?
    * Find all instances or the first or the last instance, etc.

## Linear Search

* Basic idea: given a collection of elements and a key element $k$, search through the collection and find an element that "matches" $k$
* Start with *pseudocode*: fake code that is not tied to a particular language
  * It doesn't use language-specific notation
  * Makes use of math notation
  * Abstract and general
* Good pseudocode can be translated into any particular programming language
* A linear search algorithm searches through a collection to find an element that matches a key
* How "efficient" or "complex" is linear search?
* In the worst case, linear search makes $n$ comparisons on an array of $n$ elements
* In the average case, linear search makes $\frac{n}{2}$ comparisons
* Perspective:
  * For an array of $n = 10^{12}$ (1 trillion) elements, it makes about 1 trillion comparisons in the worst case, 500 billion in the average case
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
* Divide and conquer algorithm: you partition around the pivot and recursively sort each sub array on each side until you reach an subarray of size of size 1 (or 0), stop
* Partition around that element: lesser elements to the left, greater to the right
* Analysis: omitted (beyond the scope of this course)
* End result: quick sort makes about $n\log{n}$ comparisons

## Sorting in Practice

* In general, you do not need or want to write your own searching/sorting algorithms!
  * Lots of copy-pasta for different types
  * Lots of testing
  * Lots of debugging, etc.
  * Don't roll your own!
* You use one built-in generic sorting/searching algorithm/function/method
* However, the built-in functionality is *generic* so it doesn't know what the elements are or how to compare them.
* You also need to define a *comparator function*

### In C: Comparator Functions

* A comparator function is a function that compares two ***things***, $a, b$ and returns:
  * it returns *something* negative if a < b
  * it returns zero if a is equal to b
  * it returns *something* positive if a > b (b < a)
* In C, the signature of a comparator *MUST* be:
  `int cmp(const void *a, const void *b)`
* It returns an integer (following the pattern above)
* It takes two arguments: generic void pointers
* The `const` keyword ensures that no changes are made by the comparator function
* Inside the function, you follow a general pattern:
  * You cast the generic void pointers as the actual types that you are comparing
  * You setup a if-else statement to return something negative, zero, or something positive depending on the relative ordering of your arguments

### Sorting with `qsort`

* Once you have a comparator function, you can use it in a call to the standard library's `qsort` function
```c
void qsort(void *base,
           size_t nel,
           size_t size,
           int (*compar)(const void *, const void *));
```

* `base` is the array of elements you are sorting
* `nel` is the number of elements in the array
* `size` is the number of bytes that each element takes in the array: use `sizeof()`
* `compar` is a function pointer to your comparator (more later); for now just know that you use the function's name

### Searching in C

```c
void *bsearch(const void *key,
              const void *base,
              size_t nmemb,
              size_t size,
              int (*compar)(const void *, const void *));
```

* It returns a pointer to ***an*** element matching the given key element
* If no such element is found, it returns `NULL`
* `bsearch` makes no changes to the array (thus the `const` keyword)
* The first argument is a "dummy key" that you are searching for

## Misc Issues

* Total Orders:
  * Sometimes you want to write comparators for only one or a subset of member variables/data
  * Other times you want a *total order*: there is NO possibility of a tie
  * To do so, you need to establish a universally unique identifier: ISBNs, EIDR, SSN ("natural" keys)
  * Sometimes there is no natural key: alternatives generate *surrogate* keys
  * Databases will typically handle "key management" for you
  * Otherwise: UUIDs are really nice
* Artificial vs Natural Sorting
  * YOu use some human-oriented criteria to sort
  * That means you cannot rely on built-in function or operators such as `strcmp` or `<`, `>`, etc.
  * Solution: create an enumerated type or some data structure to define the ordering; then you can use `<, >, ==`, etc.
* A sorting algorithm is *stable* if the original ordering of otherwise equal elements is preserved in the final sort
  * $2_a, 1, 2_b, 4$
  * Both $1, 2_a, 2_b, 4$ and $1, 2_b, 2_a, 4$ are sorted
  * But the first is *stable* the second is *unstable*



```text






```
