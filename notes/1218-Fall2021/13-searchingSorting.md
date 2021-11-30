
# CSCE 155E - Computer Science I
## Searching & Sorting
### Fall 2021

# Introduction

* Algorithm: a finite sequence of operations that defines a computational process for solving a problem
* All algorithms must be *correct*
* Algorithms != Problems
* There may be more than one "correct" algorithm that solves  a problem
* Not all algorithms are created equally
* Some algorithms are more efficient than others
* Ex: Maliciously Compliant painter

## Searching

* Given a collection of elements and a *key* element $k$ you want to search the collection to see if any element *matches* $k$
* In the context of C:
  * A collection is an array
  * An element is simply an item in the array (to start out with, we'll consider integers)
  * A key is an element of the same type
  * "Matches"? integers: `==`, for strings: `strcmp`, airports?
* Let's start with a search function for integers...

### Design Considerations

* *What* are you searching: an array, or other data structure?  Strings?  Integers?  Airports?  etc.
* *How* are you searching:
  * Do you find the first one, the last one, all of them?
  * If you have a structure, `Airport`: how do you know the airport matches your search criteria
  * Criteria:
    * You could find the first, last, (max or min)
    * You can search based on a structure's state: partially or wholly, etc.
  * What do you do for an unsuccessful search?

## Linear Search

* A linear search algorithm searches through a collection to find an element that matches a key
* The complexity of an algorithm in general is the amount of work or resources that the algorithm uses to perform its computation
* Linear search: the idea of "work" is time
* What takes time in our linear search implementations?
  * The amount of work = number of comparisons made by the algorithm
* How many comparisons does linear search execute on an array of size $n$?
  * Best case scenario: you find it at index 0, performing only 1 comparison
  * Worst case scenario: you find it at the last index or you don't find it at all, resulting in $n$ comparisons
  * Average case: you will likely make about $\approx \frac{n}{2}$ comparisons
* Linear search makes a linear number of comparisons
* If you increase the input size (the size of the input array) then the amount of work increases by a linear amount
* Size: n -> 10n; suppose an input of n took 10 seconds, an input of 10n takes 100 seconds!

## Binary Search

* A *sorted* array has *structure* that can be exploited
* Idea:
  * Examine the middle element, if it matches the key, stop (you found what you're looking for)
  * If the middle element is greater than the element you are search for, repeat your search in the lower half (left half)
  * If the middle elements is less than the element you are searching for, repeat your search in the upper half (right half)
  * repeat until you found what you are looking for OR you don't find it and the array "partition" is now empty
* In either case, you have cut the input in half each time
* this is a divide and conquer style algorithm
* Recursive implementation
* Non-recursive implementation

### Analysis

* For an array of size $n$, we perform at most $\log{(n)}$ comparisons!
* Contrast that with linear search: $n$ comparisons


## Selection Sort

* Basic idea:
  * go through and find the smallest element and swap it with the first
  * go through the remaining $n-1$ elements and find the smallest among those, swapping it with the second
  * repeat until you have the first $n-1$ sorted
  * The last element will be where it needs to be!

## Quick Sort

* It is quick!

## Searching & Sorting in Practice

* In general, you do not need or want to write your own searching/sorting algorithms
* Lots of copy-pasta for different types
* Lots of testing
* Lots of debugging, etc.
* Don't roll your own!
* qsort and other built-in algorithms know how to sort, they just don't know how to *order*
* They don't know what the elements are in the given array, they coudl be integers, doubles, films, etc.
* `qsort` needs to be told how to order those *things*
* A comparator function solves this problem
* A comparator function takes two generic *things* $a, b$ and returns an integer:
  * *Something* negative if $a$ comes before $b$
  * ZERO if $a$ "equals" $b$
  * *Something* positive if $a$ comes after $b$ ($b$ comes before $a$)

### Function Pointers in C

* How do we "pass" a function to another function?
* Doing so is generally referred to as a "callback" it allows the function to call the other function "back"
* GUI = Graphical User Interfaces
* `qsort`: it needs a comparator (a function) in order to "order" items
* How do we do this?
* Consider: what is stored in memory?
  * Data is stored in memory
  * files are stored in memory
  * Your program is stored in memory
  * functions are stored in memory
* As a result, you can create a pointer that points to a function!
* Syntax: suppose we want to create a pointer to a function that takes a `double, int, char` and returns an `int`; we'd create a pointer that looks like:

```c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int foo(double x, int y, char c) {
    return x * y;
}

double runMath(double input, double (*f)(double)) {
    return f(input);
}


int main(int argc, char **argv) {


    //creates a function pointer that can point to any function
    // that 1. takes a double/int/char as inputs and returns an integer
    int (*ptrToFunc)(double, int, char);

    //what does ptrToFunc point to right now?
    // it is undefined

    //let's make it point to NULL:
    ptrToFunc = NULL;

    //let's make it point to foo():
    ptrToFunc = &foo;
    //OR even shorter:
    ptrToFunc = foo;
    //a function name itself is its reference

    //you can invoke a funtion like usual:
    int result = foo(3.5, 10, 'H');

    //or you can invoke it via its pointer:
    result = ptrToFunc(3.5, 10, 'H');

    double y = sqrt(2.0);
    printf("y = %f\n", y);

    double (*mathPtr)(double);
    //careful: make sure the types match!
    //mathPtr = foo;

    mathPtr = tan;
    y = mathPtr(2.0);
    printf("y = %f\n", y);

    y = runMath(2.0, sqrt);
    printf("y = %f\n", y);

    y = runMath(2.0, sin);
    printf("y = %f\n", y);

    y = runMath(2.0, tan);
    printf("y = %f\n", y);


}
```

### Sorting using `qsort`

#### Creating Comparators in C

* A *comparator function* has the following signature:


`int cmp(const void *a, const void *b)`

* It returns an integer with the following contract:
  * it returns *something* negative if a < b
  * it returns zero if a is equal to b
  * it returns *something* positive if a > b (b < a)
* `const`: the comparator will not (cannot) make any changes to the input values
* Both are `void *` variables: it is a generic void pointer (it can point to anything and any type)
* A comparator follows a basic pattern:
  * First, it typecasts the given variables into a *specific* (nongeneric) type
  * You make a comparison based on the state of the variables
* Avoid the difference trick
* Avoid all tricks
* Make liberal use of other code

#### `qsort`

* C provides a standard "quick sort" implementation

```c
void qsort(void *base,
           size_t nel,
           size_t size,
           int (*compar)(const void *, const void *));
```

* `base` - the array you want sorted
  * Generic array of things/stuff
  * It does *not* have the `const` keyword: it will change hte array you give it!
* `nel` - number of elements (the size of the array)
* `size` - the number of bytes each element takes (use `sizeof()`!)
* `compar` is a function pointer that points to a comparator

#### `bsearch`

* a standard binary search implementation is available:

```c
void *bsearch(const void *key,
              const void *base,
              size_t nmemb,
              size_t size,
              int (*compar)(const void *, const void *));
```

* Difference: `const` with the array, it won't be making any changes to the array
* Difference: new first argument, `const void *key`
* It returns a generic void pointer:

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "film.h"

/**
 * This comparator orders integers in
 * ascending order
 */
int cmpIntAsc(const void *a, const void *b) {
  //1. cast them into a proper (expected) type
  const int *x = (const int *) a;
  const int *y = (const int *) b;

  if( *x < *y ) {
    //in order
    return -1;
  } else if( *x > *y ) {
    //out of order
    return 1;
  } else {
    //equal
    return 0;
  }
}


/**
 * This comparator orders integers in
 * descending order
 */
int cmpIntDesc(const void *a, const void *b) {
  return cmpIntAsc(b, a);
}


/**
 * This comparator orders doubles in
 * ascending order
 */
int cmpDoubleAsc(const void *a, const void *b) {
  //1. cast them into a proper (expected) type
  const double *x = (const double *) a;
  const double *y = (const double *) b;

  if( *x < *y ) {
    //in order
    return -1;
  } else if( *x > *y ) {
    //out of order
    return 1;
  } else {
    //equal
    return 0;
  }
}

int main(int argc, char **argv) {

  Person denis = {
      "Denis",
      "Villenueve",
      {
          1967, 10, 3
      }
  };

  Film *arr = (Film *) malloc(sizeof(Film) * 3);
  initFilm(&arr[0], "1234", "Arrival", denis, 8.5);
  initFilm(&arr[1], "10.5240/D15F-5FCE-B8D0-FA2B-EF6A-D", "Dune", denis, 9.0);
  initFilm(&arr[2], "5678", "Blade Runner 2049", denis, 9.9);

  Film *filmKey = createFilm("", "Blade Runner 2049", denis, 0.0);

  int n = 9;
  int numbers[] = {42, 4, 9, 4, 102, 34, 12, 2, 0};
  for(int i=0; i<n; i++) {
    printf("%d, ", numbers[i]);
  }
  printf("\n");
  qsort(numbers, n, sizeof(int), cmpIntAsc);
  for(int i=0; i<n; i++) {
    printf("%d, ", numbers[i]);
  }
  printf("\n");
  qsort(numbers, n, sizeof(int), cmpIntDesc);
  for(int i=0; i<n; i++) {
    printf("%d, ", numbers[i]);
  }
  printf("\n");

  //takeaway: always use the appropriate comparator!
  qsort(numbers, n, sizeof(int), cmpDoubleAsc);
  for(int i=0; i<n; i++) {
    printf("%d, ", numbers[i]);
  }
  printf("\n");

  //bsearch demo:
  //1. sort it
  qsort(numbers, n, sizeof(int), cmpIntAsc);
  //search for 42 in numbers:


  int key = 42;
  int *result;
  result = bsearch(&key, numbers, n, sizeof(int), cmpIntAsc);
  if(result == NULL) {
    printf("no such element (%d) found\n", key);
  } else {
    printf("element found (%d) at memory location %p containingn the value %d\n", key, result, *result);
  }

}
```




```text





```
