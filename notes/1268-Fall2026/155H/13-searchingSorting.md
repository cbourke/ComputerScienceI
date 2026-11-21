
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

## Sorting in Practice

* In general you do NOT need to write your own searching/sorting algorithms/functions
  * Lots of copy-pasta for different types
  * Lots of testing
  * Lots of debugging
  * Don't roll your own!
* You use one built-in generic sorting/searching algorithm/function/method
  * C: `qsort`
  * Java: `Collections.sort`
* However, the built-in functionality is *generic* so it doesn't know what the elements are or how to compare them.

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
```c
void qsort(void *base,
           size_t nel,
           size_t size,
           int (*compar)(const void *, const void *));
```

* Returns `void`: nothing to return; it modifies the array you give it (sorts it)
* `base`: is the array you want to sort; it is not `const`!
* `nel` is the size of the array (number of elements)
* `size` is the number of bytes each element takes: hint always use `sizeof()`
* `compar` is a function pointer to your comparator (more later); for now just know that you use the function's name

### Searching with `bsearch`

* Its a binary search implementation
* Signature:
```c
void* bsearch(const void *key,
              const void *base,
              size_t nel,
              size_t size,
              int (*comp)(const void*, const void*) );
```

```text















```
