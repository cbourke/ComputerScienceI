
# CSCE 155H - Computer Science I
## Algorithms, Searching & Sorting
### Fall 2022

# Introduction & Demonstration

* Huge part of Computer Science: data processing
* Fundamental operations: *searching*, *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed

## Preliminaries

* What does searching mean?
  * What are you searching?: Array?  List? Set? Map?
  * What are the elements you are searching? integer?  double?  char? Airports?  Teams?
  * How are you searching for it?
    * Find a particular element $x$
    * Find the maximum or minimum element
    * Find the median
    * Find all instances of a particular element
    * Student: NUID? Name? GPA?

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

## Binary Search

* Requires:
  * That you can "jump" to the middle indexed element for "free" (random access)
  * That the array is sorted!
  * Requires that your search criteria is the *exact same* as your sort criteria
* Is it better?
  * Binary search only makes about $\log_2{(n)}$ comparisons
  * This is $n$ vs $\log_2{(n)}$:
  * Linear search is exponentially *slower* than binary search
  * Binary search is exponentially *faster* than linear search
  * No doubt it is better
  * You should always use it!  If you can...
  * That means it pays to sort something or to maintain its order!

## Sorting

### Selection Sort

* Basic Idea:
  * Find the minimum or minimal element and place it at the beginning
  * Then go through the remaining $n-1$ elements, find the minimum and place it at the second place
  * In general: on the i-th iteration, the elements $0..i-1$ are already sorted!
  * What do you do with the remaining elements $i...n-1$?

### Quick Sort:

* Divide & Conquer strategy
* Choose a pivot element and *partition* around it: lesser elements to the left, greater to the right
* Place the pivot in the middle; recurse on each side
* Best and average case performance: quick sort performs $\approx n \log{(n)}$ comparisons

## Sorting in Practice

* In general, you do not need or want to write your own searching/sorting algorithms!
  * Lots of copy-pasta for different types
  * Lots of testing
  * Lots of debugging, etc.
  * Don't roll your own!
* You use one built-in generic sorting/searching algorithm/function/method
* However, the built-in functionality is *generic* so it doesn't know what the elements are or how to compare them.
* You also need to define a *comparator function* (C programming language) or a `Comparator` in Java

### In C: Comparator Functions
* In C, a *comparator function* is a function that compares two  generic elements $a, b$ and returns:
  * it returns *something* negative if a < b
  * it returns zero if a is equal to b
  * it returns *something* positive if a > b (b < a)
* In C, the signature of a comparator *MUST* be:

`int cmp(const void *a, const void *b)`

* returns an integer
* takes two arguments
* The use of `const` ensures that the function will not change `a, b`
* Inside the function, you follow a general pattern:
  * You cast the generic void pointers as the actual types that you are comparing
  * You setup a if-else statement to return something negative, zero, or something positive depending on the relative ordering of your arguments

### C: sorting

* Once you have a comparator function, you can use it in a call to the standard library's `qsort` function
```c
void qsort(void *base,
           size_t nel,
           size_t size,
           int (*compar)(const void *, const void *));
```

* `base` is the array of elements you are sorting
* `nel` is the number of elements in the array
* `size` is the number of bytes each element takes: use `sizeof()`
* `compar` is a *function pointer* to the comparator you want to use (more on that later): for now, just use the comparator function's name!

### Searching in C

```c
void *bsearch(const void *key,
              const void *base,
              size_t nmemb,
              size_t size,
              int (*compar)(const void *, const void *));
```

* Returns a pointer to a matching element if found
* If no such element is found, returns `NULL`
* `bsearch` does not make changes to the array (it is `const`)
* The first argument is a key that you are searching for

## Java

* 


```text










```
