
# CSCE 155E - Computer Science I
## Searching & Sorting
### Fall 2023

# Introduction & Demonstration

* Huge part of Computer Science: data processing
* Fundamental operations: *searching*, *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed

## Demonstration

* Demo: write a function to search a collection for a particular element
* C: write a function to search an array for a particular integer

## Searching and Sorting in Practice

* In general you do not write your own searching/sorting algorithms
* You use one built-in generic sorting/searching algorithm/function/method
* However, the built-in functionality is *generic* so it doesn't know what the elements are or how to compare them.
* Basic strategy:
  * Write generic algorithms/functions that can take *any* type of array
  * You have to pass in a another component to the function that is responsible for *comparing* elements: a *comparator*

### Comparators in C

* In C, a *comparator function* is a function that compares two  generic elements $a, b$ and returns:
  * it returns *something* negative if $a < b$
  * it returns zero if $a = b$
  * it returns *something* positive if $a > b$ ($b < a$)
* In C the signature of a comparator function *MUST* Be:

`int cmp(const void *a, const void *b)`

* It returns an integer as per the pattern above: negative, positive, zero
* Do NOT assume anything about the actual value: `-42, -1, -101`
* It takes two *generic void pointers*
  * It allows you to compare *any* type of values
* Inside the function you follow the following pattern:
  1. You cast the generic void pointers as the type that you expect (an `int`, `double`, `Airport`)
  2. You can use the state/value of the type and determine the relative ordering; return something negative, positive, zero
* Exercise: write a comparator for integers (in ascending order)

### Searching in C: use the built-in search library

* There is a search library: `#include <search.h>`
* There is a function called: `lfind`
```c
void * lfind(const void *key,
             const void *base,
             size_t *nel,
             size_t width,
             int (*compar)(const void *, const void *));
```

* `key` is a pointer to the key value you are searching for!
* `base` is the array you want to search
* `nel` is the number of elements (size of the array)
  * **Take care**: this is pass by reference for some reason
* `width` is the number of bytes each element takes
* `compar` is the comparator function you want to use to compare
* Return type/value: it is a *pointer* to the first element that matches your search criteria!  
* If successful: a valid pointer is returned
* If unsuccessful: it return `NULL`

## Linear Search

* A linear search algorithm searches through a collection to find an element that matches a key
* The complexity of an algorithm in general is the amount of work or resources that the algorithm uses to perform its computation
* Example: what is the amount of "work" that linear search performs?
  * What operation is the most important: how items/elements are compared.
  * How many operations does it perform?
* Linear search is an *adaptive* algorithm:
  * Best case scenario: you get lucky and find it at the first index, number of comparisons: 1
  * Worst case: unsuccessful search or you get all the way to the end; if there are $n$ elements in the array you make $n$ comparisons
  * Average: $\approx \frac{n}{2}$ comparisons *on average*
  * It doesn't matter: there are a linear number of comparisons
* If you have
  * 1 billion elements; you can expect to perform 500 million comparisons
  * If you have an array of size $n$ and you increase it to a size of $2n$, how many *more* comparisons do you need to make? Twice as many.
* Can we do better?

## Binary Search

* Binary Search only requires $\log_2{(n)}$ comparisons for an array of $n$ elements
  * To search an array of 1 billion elements requires only $\log_2{(10^{12})} = 40$
  * To go from an array of size $n$ to an array of size $2n$ only requires 1 more comparison
  * This is *exponentially* faster than linear search


```text















```
