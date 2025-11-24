
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
  * until the size is $\leq 1$
* Quick sort makes (on average) $n\log{n}$ comparisons!

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
```c
void qsort(void *base,
           size_t nel,
           size_t size,
           int (*compar)(const void *, const void *));
```

* `base` is the array of elements you are sorting
* `nel` is the size of the array (number of elements)
* `size` is the number of bytes each element takes: hint always use `sizeof()`
* `compar` is a function pointer to your comparator (more later); for now just know that you use the function's name
* Example...

```text













```
