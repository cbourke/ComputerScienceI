
# CSCE 155E - Computer Science I
## Searching & Sorting
### Fall 2025

# Introduction & Demonstration

* Huge part of Computer Science: data processing
* Fundamental operations: *searching*, *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed

##

* Demo: write a function to search a collection for a particular element
  * What are elements?  `int`?  `double`?  `char *`, `Earthquake`
  * What is a collection? C: arrays, other languages: list, set, map, or other data structures
  * What criteria?  Books: by author, by title, by isbn, etc.
  * What matching criteria: minimum/maximum, equality

## Intuitive Notions

* Larger inputs will take longer time to compute
* But: by how much?
* And: how can we quantify that?
* Before: let's improve the code

### Improving Efficiency

* If the array were *sorted*, how could you exploit that?

```c
int key = 8;
int unsorted[] = {5, 3, 8, 4, 1, 2, 8, 4, 5};
...
int sorted[]   = {1, 2, 3, 4, 4, 5, 5, 8, 8};
                  ^           ^           ^
                  left        middle      right

```

#### Binary Search

* Basic Idea: if the array is sorted, you can exploit that for efficient searching
* Compare your key to the "middle" element $m$
  * If $k = m$: done, you found what you are looking for
  * If $k < m$: search the left half of the array
  * If $m < k$: search the right half of the array
  * Each time you "recurse" you update your left/right index, you effectively cut the array in half each and every time

#### Analysis

* Linear search requires about $n$ comparisons/operations in the worst case for arrays
* Binary search only requires $\approx\log{(n)}$
* Note: all our logs are base-2 unless otherwise stated (we are self respecting computer scientists)
* Binary search is *exponentially* faster than linear search!
* HOWEVER: it requires that the array be *sorted* first!

## Sorting

* How do we sort?

### Selection Sort

* Idea: you search the array for the minimum element then swap it with the first
* Repeat: this idea
  * $i$-th iteration: find the minimum among $i, \ldots, n-1$
  * Swap $i$ and the minimum element
  * Stop when $0, \ldots, n-2$ are sorted, the last element $n-1$ is automatically where it needs to be

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
* `nel` number of elements: size of the array
* `size` is the number of bytes that *each* element in the array takes; ie: `sizeof()`
* `compar` is a function pointer to your comparator (more later); for now just know that you use the function's name

```text














```
