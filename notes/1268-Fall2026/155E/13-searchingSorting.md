
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

## Sorting

* How do we sort?

### Selection Sort

* Idea: you search the array for the minimum element then swap it with the first
* Repeat: this idea
  * $i$-th iteration: find the minimum among $i, \ldots, n-1$
  * Swap $i$ and the minimum element
  * Stop when $0, \ldots, n-2$ are sorted, the last element $n-1$ is automatically where it needs to be
* The number of comparisons that selection sort makes on an array of size $n$ is approximately $n^2$

### Quick Sort

* It is quick!
* Idea: choose a pivot element (say the first element)
* Divide and conquer algorithm: you partition around the pivot and recursively sort each sub array on each side until you reach an subarray of size of size 1 (or 0), stop
* Partition around that element: lesser elements to the left, greater to the right
* End result: quick sort makes about $\approx n\log{n}$ comparisons

## Sorting in Practice

* In general, you do not need or want to write your own searching/sorting algorithms!
  * Lots of copy-pasta for different types
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
  * No `const` means: `qsort` will be making changes to the array!
  * It is a generic `void` pointer so that it can sort *anything*
* `nel` number of elements: size of the array
* `size` is the number of bytes each element in `base` takes: ie `sizeof()`
* `compar` is a function pointer (more later) to your comparator; for now just know that you use the function's name

```text














```
