
# ECEN 1940 - Computer Science I
## Searching & Sorting
### Spring 2022

## Introduction

* Processing data is a fundamental operation in Computer Science
* Two fundamental operations in processing data are *searching* and *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed

### Algorithms

* An Algorithm: a finite sequence of operations that defines a computational process for solving a problem
* All algorithms must be *correct*
* Algorithms != problems
* There may be more than one correct algorithm in which case you have other considerations: efficiency or complexity

## Searching

* Given a collection of elements $A = \{a_1, a_2, \ldots, a_n\}$ and a key $k$ element you want to search the collection to see if any element in it *matches* $k$
* In the context of C:
  * A collection is an array (0-indexing)
  * An element in the array is a `int` or `double` or `Airport`
  * Eventually: we will want a "generic" solution that can be "polymorphically" applied to any type
  * For now: consider just `int`s
  * Matching means (for `int`): `==`
  * Strings?  `strcmp`
* Demonstration: create a search function for integers.

## Design Considerations

* *What* are we searching: an array, or other data structure?  What are we searching for?  `int`, `double`, string, etc?  
* *HOW* are you searching:
  * Do you find the first?  The last?  Every instance?
  * If you have a structure: how do you match a structure?  Ex: `Airport`; criteria: lat/long, size, name, GPS ID, etc.
* What do you do for an unsuccessful search?

## Linear Search

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
* Partition around that element
* LEFT SIDE: [4, 9, 4, 34, 12, 2, 0 ] -42- RIGHT SIDE: [102]
* Second iteration: [4, 9, 4, 34, 12, 2, 0], pivot: 4
* Partition: LEFT: [4, 2, 0] -4- RIGHT: [9, 34, 12]
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

### Function Pointers in C

* How do we "pass" a function to another function?
* Doing so is referred to as a "callback" function: it allows the function that you give it to to "call it back"
* GUI = Graphical User Interface
* `qsort` also needs a callback function: a function that allows it to *order* things, $a, b$
* How do we do this?
* Consider: what is stored in memory?
  * Data
  * Files
  * Programs
  * Functions
* As a result, it makes sense to refer to the memory location of where a function is stored
* Demonstration of syntax


### Sorting in C

#### Comparator

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
* Demonstration
  * Avoid the difference trick: it doesn't work on `double` values and it risks overflow/underflow with integers
  * Avoid all "tricks"

#### `qsort`

* C provides a standard "quick sort" implementation

```c
void qsort(void *base,
           size_t nel,
           size_t size,
           int (*compar)(const void *, const void *));
```

* `base` - the array of stuff
  * Generic: `void *`
  * It does *NOT* have the `const` keyword
* `nel` - number of elements (the size of the array)
* `size` - the number of bytes each element takes: use the `sizeof()` macro!
* `compar` - a function pointer to the comparator you want to use

### Searching in C

#### Linear Search

* THe `search.h` library has `lfind` and `lsearch` functions

```c
void *lfind(const void *key,
            const void *base,
            size_t *nmemb,
            size_t size,
            int(*compar)(const void *, const void *));
```

#### Binary Search

* The standard library has a binary search implementation:

```c
void *bsearch(const void *key,
              const void *base,
              size_t nmemb,
              size_t size,
              int (*compar)(const void *, const void *));
```                    

### Demo Code

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <search.h>

#include "utils.h"

int NUM_COMPS = 0;

void selectionSort(int *arr, int n) {

  for(int i=0; i<n-1; i++) {
    //find the smallest element among
    // arr[i] thru arr[n-1]
    int minIndex = i;
    for(int j=i+1; j<n; j++) {
      NUM_COMPS++;
      if(arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }
    //swap arr[i], arr[minIndex]
    int temp = arr[i];
    arr[i] = arr[minIndex];
    arr[minIndex] = temp;
  }

}

int binarySearch(const int *arr, int n, int key) {

  //TODO: error handling...

  int leftIndex = 0;
  int rightIndex = n-1;
  while(leftIndex <= rightIndex) {
    int middleIndex = (rightIndex + leftIndex) / 2;
    NUM_COMPS++;
    if(arr[middleIndex] == key) {
      return middleIndex;
    } else if(key < arr[middleIndex]) {
      //search the left half...
      rightIndex = middleIndex - 1;
    } else if(arr[middleIndex] < key) {//TODO: remove this unnecessary demo code
      //search the right half...
      leftIndex = middleIndex + 1;
    }
  }
  return -1;

}

/**
 * Searches the given array for the key element, returning
 * the index of the first value it finds that matches the
 * key element.
 *
 * If no such element has been found, returns -1 or any other
 * error condition.
 */
int indexOf(const int *arr, int n, int key) {

  if(arr == NULL || n < 0) {
    return -1;
  }

  for(int i=0; i<n; i++) {
    NUM_COMPS++;
    if(arr[i] == key) {
      return i;
    }
  }
  return -1;

}

int main(int argc, char **argv) {

  srandom(time(NULL));

  int n = 9;
  //int *arr = generateRandomArray(n);

  int arr[] = {42, 4, 9, 4, 102, 34, 12, 2, 0};
  //int arr[] = {0, 2, 4, 4, 9, 12, 34, 42, 102};
  //int key = 10001;

  qsort(arr, n, sizeof(int), cmpIntDesc);

  //selectionSort(arr, n);
  for(int i=0; i<n; i++) {
    printf("%d, ", arr[i]);
  }
  printf("\n");

  //use lfind to find, 42...
  int key = 42;
  int *result = bsearch(&key, arr, n, sizeof(int), cmpIntDesc);
  printf("Found %d value at memory address %p\n", key, result);

  // int index = binarySearch(arr, n, key);
  // printf("%d found at index %d\n", key, index);
  //printf("Number of comparisons: %d\n", NUM_COMPS);

}
```

## Sorting and Searching Structures

* Demonstration

## Dead Week

* Fill out your course evaluations!

* Dead Week:
  * M: Review, Run?
  * W: Review
  * F: Help Session



```text











```
