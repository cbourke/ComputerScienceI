
# CSCE 155E - Computer Science I
## Searching & Sorting
### CSCE 155E, Fall 2019

Searching & Sorting
====================

* Processing data is a fundamental operation in Computer Science
* Two fundamental operations in processing data are *searching* and *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed

## Searching

* *What* are you searching: an array or another data structure?  Strings, integers, doubles or user defined types (Students, Airports, etc.)
* *How* are you searching: not algorithmically but by what *criteria* are you searching?
* You could search for a particular element: minimum, maximum, median, mode, etc.
* How do you determine a successful or unsuccessful search?
* There are many basic and advanced criteria that you can search for: you have to be specific when coding, but be GENERAL when talking about algorithms

## Linear Search

```c
/**
 * This function searches the given array of integers
 * which is of size n for the given key element.
 * 
 * This function returns an index value of the
 * element that first matches the key.
 * 
 * This function returns -1 in the event that 
 * no such value is found or an error is encountered.
 */
int linearSearch(const int *arr, int n, int key) {
  if(arr == NULL || n < 0) {
    return -1;
  }
  for(int i=0; i<n; i++) {
    if(arr[i] == key) {
      return i;
    }
  }
  return -1;
} 

int linearSearchForDoubles(const double *arr, int n, double key) {
 if(arr == NULL || n < 0) {
   return -1;
 }
 for(int i=0; i<n; i++) {
   if(arr[i] == key) {
     return i;
   }
 }
 return -1;
} 

int linearSearchForStrings();
int linearSearchForAirportsByGPSId();
int linearSearchForAirportsByState();
```

* Practical Problem: the above solution is only
good for searching: integers
* Our ultimate goal: write ONE function that searches
ANY type of data by ANY criteria


## Binary Search

* Linear search requires about n/2 comparisons/operations on average
* Can you do better?
* Consider: what if the array is already sorted?
* Consider the middle element m at index n/2:
  * if the key is equal to m: stop, you found your needle in the haystack
  * if key < m: proceed to search in the left half of the array (indices 0 thru n/2-1)
  * if m < key: proceed to search in the right half of the array (indices n/2+1 thru n-1)
* Why does this help?  Each comparison removes about half of the array each time!
* There is a clear "recursive" or "divide and conquer" strategy to this algorithm
* We'll develop an *iterative* version of binary search

```c
#include <stdio.h>

int binarySearch(const int *arr, int n, int key) {
  int left = 0;
  int right = n-1;

  while(left <= right) {
    //bad in practice: susceptible to overflow:
    //int m = (left + right) / 2;
    //better solution:
    int m = left + (right - left) / 2;
    if(arr[m] == key) {
      return m;
    } else if(arr[m] < key) {
      //search the right half:
      left = m + 1;
    } else if(key < arr[m]) {
      //search the left half:
      right = m - 1;
    }
  }
  return -1;
}

int linearSearch(const int *arr, int n, int key) {
  if(arr == NULL || n < 0) {
    return -1;
  }
  for(int i=0; i<n; i++) {
    if(arr[i] == key) {
      return i;
    }
  }
  return -1;
}  

int main(void) {

  int n = 9;
//unsorted requires linear search:
//  int arr[] = {5, 9, 3, 4, 0, 1, 4, 5, 2};
  int arr[] = {0, 1, 2, 3, 4, 4, 5, 5, 9};
  int key = 5;
  int indexOf = binarySearch(arr, n, key);
  printf("found %d at index %d\n", key, indexOf);


  return 0;
}
```


### Analysis

* Suppose you have an array of $n$ elements
* How many comparisons does linear search perform to search the given array?
  * Best case scenario: you find the key at the first element: one comparison!
  * Worst case scenario: you find the key at the end of the array (or you don't find it at all): $n$ comparisons
  * Average case scenario: naive analysis:
    $$\frac{n + 1}{2} \approx \frac{n}{2}$$
  * Both the average and worst cases are *linear*
* Binary Search?
  * Derivation: whitepaper and in the book
  * Only takes about $\log_2{(n)}$ comparisons

#### Perspective

* Suppose you have a database of $10^{12}$ (1 trillion) elements
  * If unsorted you would have to use linear search to find a particular element:
    $$500 \times 10^{11}$$
  500 billion comparisons
  * If sorted (indexed) then you can exploit the sort using binary search:
    $$\log_2{(10^{12})} < 40$$

* Another perspective: suppose you "double" the input size of an array
  $$n \rightarrow 2n$$
  * linear search: the number of comparisons goes from
  $$\frac{n}{2} \rightarrow n$$
  The number of comparisons doubles
  * binary search:
  $$\log_2{(n)} \rightarrow \log_2{(2n)} = \log_2{(n)} + \log_2{(2)} = \log_2{(n)} + 1$$

## Sorting

* Huge variety of sorting algorithms with different algorithmic strategies and different performances

### Selection Sort

* Basic Idea: search through the array and find the minimal element, swap it with the first element, `a[0]`
  * Repeat: find the second smallest among the remaining $n-1$ elements, swap it with `a[1]`
  * In general: on the $i$-th iteration, the first $i-1$ elements have been sorted, search the remaining $n-i$ elements and find the minimum, swap it with `a[i]`

* Analysis
    * How many comparisons does selection sort make on an array of size $n$?
    * Selection sort requires about $n^2$ operations, it is a "quadratic" sorting algorithm
    * IN practice, quadratic sorting algorithms are NOT feasible,
    * For any even moderately large data set, quadratic algorithms are not feasible

### Quick Sort

    * Basic Idea:
        * Choose a *pivot* element in the array
        * Partition all other elements around the pivot: place element smaller to the left, larger to the right
        * Repeat by recursing on the left partition and the right partition
        * Until your partition becomes of size 0 or 1
    * Analysis:
      * Quick Sort make an average number of comparisons proportional to 
$$\approx n\log{(n)}$$

### Comparison

* Selection sort: $n^2$ vs Quick Sort $n\log{(n)}$
* Mathematical perspective: $n\log{(n)}$ is a smaller and smaller growing function (quasilinear function)
* Consider doubling the input size, $n$:
  * Selection sort would have the number of comparisons go from:
$$n^2 \rightarrow (2n)^2 = 4n^2$$
  * Doubling the input size, quadruples the number of operations that selection sort performs
  * Quick sort would have the number of comparisons go from:
$$n\log{(n)} \rightarrow 2n\log{(2n)} = 2n\log{(2)} + 2n\log{(n)} = 2n\log{n} + 2n$$
  * Doubling the input size only doubles the number of operations (roughly)
  
* Practical perspective: Consider sorting a "large" array of 1 trillion elements: $10^{12}$:
    * Selection Sort: 
    $$(10^{12})^2 = 10^{24}$$
    (1 septillion operations), at 7TFlops -> 4 million years
    * Quick Sort:
    $$10^{12}\log{(10^{12})} = 12 \cdot 10^{12}\log{10}$$
    Only about 40 seconds with a 7TFLOP computer
    
## Searching & Sorting in Practice

* In practice: you don't roll your own: you shouldn't have to write your own implementations unless there is a Very Good Reason to do so.
* In practice you use the built-in searching and sort implementations provided by the language or standard libraries
* To avoid multiple implementations you use *generic* programming
* To avoid multiple implementations you use a comparator function
* A comparator function takes to "things", a, b and determines their relative ordering:
  * it returns *something* negative if a < b
  * it returns zero if a is equal to b
  * it returns *something* positive if a > b (b < a)

### Comparators in C

* In C a *comparator function* has the following signature:

`int cmp(const void *a, const void *b)`

* `void *` is a *generic* void pointer: it can point to *anytype of data* (this is nothing more than a generic memory location)
* It is the comparator's responsibility to "recover" the type of variable in order to do its comparison
* The return type is an `int`: something negative, positive or zero depending on the relative ordering of `a` and `b`
* Inside the comparator, you follow a general pattern:
  * you type cast the generic pointers into the type of data you intend to compare
  * You then apply the logic to compare them
  * You then return an integer corresponding to the relative ordering of the two elements
* Once you have a comparator, you need to use it
* Sorting: the C standard library has a nice generic sorting function:

```c
void qsort(void *base,
           size_t nel,
           size_t size,
           int (*compar)(const void *, const void *));
```

* `void *base` is the array you want to sort
* `nel` is the number of elements (size of the array)
* `size` is the number of bytes each element takes
* `compar` is a *function pointer* to the comparator you want to use to order elements

### Function Pointers

* How can we "pass" a function to another function as a parameter?
* Doing so are generally referred to as "callbacks" (function passed to other functions so that those functions can call the functions)
* Example: GUIs: you can define a button that when clicked, performs some action; to do this, you need a way to register the function that should be called when someone clicks the button: registering a callback
* Example: `qsort` needs a way to order elements, you "pass in" a comparator function using a pointer to it
* But: a function is code stored in memory, thus it has a *memory address*
* It makes sense that you can create a pointer that points to a function (just like you can create a pointer that points to an integer)

```c
//create a pointer called ptrToFunc that can
// point to any function that returns an integer
// and takes three arguments: (int, double, char)
int (*ptrToFunc)(int, double, char);

//declare a pointer that can point to math's sqrt function
double (*ptrToSqrt)(double);

//what does ptrToSqrt point to?

```


```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int nuid;
  char *firstName;
  char *lastName;
  double gpa;
} Student;


int cmpDouble(const void *a, const void *b) {

  const double *x = (const double *)a;
  const double *y = (const double *)b;

  if(*x < *y) {
    //in order so return something negative
    return -1;
  } else if(*x > *y) {
    //out of order, so return:
    return 1;
  } else {
    //equal so return
    return 0;
  }
}

/**
 * This comparator orders two Student instances
 * by GPA in descending order
 */
int cmpStudentByGpa(const void *a, const void *b) {
  const Student *x = (const Student *)a;
  const Student *y = (const Student *)b;
  return cmpDouble(&(y->gpa), &(x->gpa));
}

/**
 * This comparator takes two Student instances and orders
 * them by last name, first name
 */
int cmpStudentByName(const void *a, const void *b) {
  const Student *x = (const Student *)a;
  const Student *y = (const Student *)b;

  int result = strcmp(x->lastName, y->lastName);
  if(result == 0){ 
    //have the same last name, break ties using hte
    //first name:
    return strcmp(x->firstName, y->firstName);
  } else {
    return result;
  }
}

int cmpInt(const void *a, const void *b) {

  const int *x = (const int *)a;
  const int *y = (const int *)b;

  if(*x < *y) {
    //in order so return something negative
    return -1;
  } else if(*x > *y) {
    //out of order, so return:
    return 1;
  } else {
    //equal so return
    return 0;
  }
}

int cmpIntDesc(const void *a, const void *b) {
  return cmpInt(b, a);
}

int main(void) {

  int n = 9;
  int arr[] = {5, 9, 3, 4, 0, 1, 4, 5, 2};
  qsort(arr, n, sizeof(int), cmpIntDesc);
  for(int i=0; i<n; i++) {
    printf("%d, ", arr[i]);
  }

  return 0;
}
```


```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int cmpDouble(const void *a, const void *b) {

  const double *x = (const double *)a;
  const double *y = (const double *)b;

  if(*x < *y) {
    //in order so return something negative
    return -1;
  } else if(*x > *y) {
    //out of order, so return:
    return 1;
  } else {
    //equal so return
    return 0;
  }
}

int cmpInt(const void *a, const void *b) {

  const int *x = (const int *)a;
  const int *y = (const int *)b;

  if(*x < *y) {
    //in order so return something negative
    return -1;
  } else if(*x > *y) {
    //out of order, so return:
    return 1;
  } else {
    //equal so return
    return 0;
  }
}
int linearSearch(const void *key, const void *base, int n, size_t size,
           int (*compar)(const void *, const void *)) {

  //you want the i-th element: base[i]
  // base + i * number of bytes each element takes
  // base[i] is at memory location: base + i * size
  for(int i=0; i<n; i++) {
    if(compar( (base + i * size), key) == 0) {
      return i;
    }
  }
  return -1;
}

double runMath(double x, double (*ptrToFunc)(double)) {
  return ptrToFunc(x);
}

int main(void) {

  // int x = 42;
  // int *ptrTox = &x;
  // *ptrTox = 101;

  //declare a pointer that can point to math's sqrt function
  double (*ptrToSqrt)(double);

  //what does ptrToSqrt point to?
  //nothing, or uninitialized 

  //make it point to sqrt:
  ptrToSqrt = &sqrt;
  //or simply:
  ptrToSqrt = sqrt;


  double y = ptrToSqrt(2.0);
  printf("square root of 2 is %f\n", y);

  double x = M_PI;
  y = runMath(x, sin);
  printf("y = %f\n", y);

  y = runMath(x, sqrt);
  printf("y = %f\n", y);

  int n = 9;
  int arr[] = {5, 9, 3, 4, 0, 1, 4, 5, 2};
  int key = 9;
  int index = linearSearch(&key, arr, n, sizeof(int), cmpInt);
  printf("found %d at index %d\n", key, index);

  n = 4;
  double brr[] = {3.14, 5.2, 33.4, 10.5};
  double k = 10.5;
  index = linearSearch(&k, brr, n, sizeof(double), cmpDouble);
  printf("found %f at index %d\n", k, index);

  return 0;
}
```

