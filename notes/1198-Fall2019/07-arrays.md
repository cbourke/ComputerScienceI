
# CSCE 155E - Computer Science I
## Arrays
### Fall 2019

* It is really rare that you only deal with say one variable or one piece of data
* You usually want to operate on a *collection* of pieces of data
* In C, collections of similar pieces of data can be stored in *arrays*
  * Arrays are a collection of variables of the same type
  * Arrays have a single identifier (name)
  * Elements in an array can be accessed using an *index*: the first element is at index 0, the second is at index 1, etc.  
  * If there are $n$ elements in an array, the last one is at index $n - 1$
  * Indexing is achieved using square brackets
  
## Static Arrays

* Static arrays are arrays of a fixed size that are allocated on top of the program stack
* Syntax

```c
//create an array that can hold 10 integers:
int arr[10];

//create an array that can hold 20 double values:
double numbers[20];
```

* Observation: just like other uninitialized variables, the contents of an array have no default values
* Demonstration
* Once you have an array, you can set individual values using an index and the normal assignment operator

```c
arr[0] = 42;
arr[1] = -5;
arr[2] = 3.14; //arr[2] has a value of 3

//set the last value to 102:
arr[9] = 102;

//what happens here?:
arr[10] = 5;
arr[-1] = 6;
```

* Accessing elements outside of an array is *undefined behavior*
  * MAY be a seg fault
  * MAY simply screw up (corrupting your own) your own memory
  * It MAY not result in any bad consequences

## Convenience Syntax

* You can initialize a static array using convenient syntax:

```c
int n = 7;
int primes[] = {2, 3, 5, 7, 11, 13, 17};
```

* In general, there is no way to determine the size of an array after it has been created in C
* In C, you *must* keep track of the size of every array, this is known as "memory management"
* It is *your* responsibility to keep track of the size of every array
* Consequence: if you pass an array to a function, you also need to *pass in an integer that represents the size of the array*
* This is also known as "bookkeeping": keeping track of the size of an array in an `int` variable
* Bookkeeping is necessary in order to iterate over an array
* Example:

```c

  int n = 100;
  int arr[100];

  for(int i=0; i<n; i++) {
    arr[i] = 0;
  }

  for(int i=0; i<n; i++) {
    printf("%d\n", arr[i]);
  }
```

## VLAs: Variable Length Arrays

* You *can* set the size of an array using a variable:
```c
int n = 100;
int arr[n]; //of size 100
```

* But in general, you *shouldn't* do this
* In fact, you should not use static arrays in general unless they are very small
* You end up abusing the stack space (which is 
  relatively small)
* Example: attempt to create a "moderately" large array on the stack
  
## Dynamic Arrays

`ulimit -a`
`free -ht`
* Alternative: use dynamic arrays
* Dynamic arrays are arrays that are allocated on the program "heap" instead of the program stack
* The heap is a larger, but less "well organized" chunk of memory
* However, the heap is *much larger*
* In general, you "ask" the operating system for some chunk of memory on the heap (of some specified) size, and it either accommodates you or refuses
* The way that you "ask" for memory is to ask for a memory allocation 
* Using the function `malloc`
* `malloc` takes only one argument: the number of bytes you want to allocate
* `malloc` returns a *pointer* to the memory location at which the memory was allocated (IF successful)
* `malloc` will return `NULL` if it was unsuccessful
* More details:
  * `malloc` actually returns a "generic `void` pointer"
  * Actual signature: `void * malloc(size_t size);`
  * This means that there not dozens of different `malloc` functions, there is only one that returns "a chunk" of memory
  * It is your responsibility to use this memory for whatever purpose you have: use it as an array of integer, or use it as an array of doubles
  * In general the way you do this is by type casting: you case the returned generic void pointer into the pointer type you want

```c
int *a; //pointer to a integer
double *b; //pointer to a double
void *c; //generic pointer

int *arr = (int *) malloc(...);
double *numbers = (double *) malloc(...);

arr[0] = 42;
arr[1] = 102;
```

* After successful allocation, you can use an array from malloc like a static array using regular old indexing

* In general you don't hardcode the number of bytes you want to use with `malloc`
* Some systems an integer may be only 2 bytes, some it maybe 4, or 3 or 8, etc.
* You can use the "macro" `sizeof` to determine how many bytes a certain type takes on that particular system

```c
int n = 100;
int *arr = (int *) malloc(n * sizeof(int));

double *numbers = (double *) malloc(n * sizeof(double));

arr[0] = 42;
arr[n-1] = 102;

printf("%d\n", arr[0]);
printf("%d\n", arr[n-1]);
```

### Memory Management

* Once you allocate a chunk of dynamic memory and are done using it, you need to clean up after yourself
* Failure to clean up after yourself may result in a *memory leak* eventually leading to a program failure when you've run out of memory 
* To clean up memory you free it up using the `free` function: simply pass in the pointer to the memory you want to *deallocate*

```c
//free up the integer array:
free(arr);
//free up the numbers array:
free(numbers);
```

* attempts to access the contents of freed memory are *undefined behavior*
* attempts to free already freed memory ("double freeing") are also undefined behavior
* freeing memory that does not belong to you is undefined behavior

## (Mini) Review

* Arrays are collections of elements that can be accessed using *zero-indexing*
* Static arrays are allocated on the stack and are thus limited
* In general, prefer *dynamic arrays* allocated on the heap
* To create dynamic arrays: use `malloc`
* Memory management: memory must be `free` after you are done with it

```c
#include <stdlib.h>
#include <stdio.h>

int main() {
  
  int n = 5;
  
  int a[5];
  int *b = (int *) malloc(n * sizeof(int));
  
  for(int i=0; i<n; i++) {
    a[i] = (i+1) * 10;
    b[i] = (i+1) * 10;
  }
  free(b);  
  b = (int *) malloc(n * sizeof(int));

  for(int i=0; i<n; i++) {
    b[i] = (i+1) * 100;
  }
  

  return 0;
}
```

## Using arrays with functions

* Remember: when passing an array to a function, you need to do your own *bookeeping*: you also need to pass in the *size* of the array using a separate variable
* To pass an array to a function, you pass a *pointer* (and the size of the array)
* Because an array's identifier (name) is already a pointer, when you pass an array, you only pass the name of the array
* Since arrays are passed by reference, no ampersand is needed when calling this function
* Technically speaking, the square brackets automatically dereference and do some "pointer arithmetic": each element is $n$ bytes (`int` this would be 4 for a `double` would be 8, etc).  The compiler is doing our pointer arithmetic for us
  * The first element is at index `0` equivalently `arr + 0 * 4`
  * The second element is at index `1` equivalently, `arr + 1 * 4`
  * The third element is at index `2` equivalently, `arr + 2 * 4`
* Problem: since the array is passed by reference, we can make changes to it!
* To prevent a function from modifying the contents of an array you can use the keyword `const`
* Example: write a function that takes an array and sums its elements

```c
/**
 * This function takes an integer array of size
 * n and returns the sum of its elements.
 */
int sum(const int *arr, int n) {
  int total = 0;
  for(int i=0; i<n; i++) {
    total += arr[i];
  }
  return total;
}
```

* `const` gives a "promise" that no changes will be made to the elements in the array
* In general, be conservative: if you are *not* going to be making changes, design your functions to use `const`
* Observation: when we pass in an array (`primes`) we are passing a *pointer* (a reference, a memory location); inside the function, using the square brackets *dereferences* automatically for us

## Return arrays from functions

* You can write functions that return arrays
* To return an array, you simply return a pointer
* In general you *cannot* (and certainly *should not* return a static array)
* Example: Design a function that creates an array of a particular size and fills it with ones, returning the resulting array

```c
int * getOnesArray(int n) {
  int *arr = (int *) malloc(n * sizeof(int));
  for(int i=0; i<n; i++) {
    arr[i] = 1;
  }
  return arr;
}
```

### Shallow vs Deep Copies

* Example: write a function to create a copy of an array
* A *shallow* copy of an array only makes a pointer point to the same array:

```c
#include <stdlib.h>
#include <stdio.h>

int main() {
  
  int n = 5;
  int *a = (int *) malloc(n * sizeof(int));
  for(int i=0; i<n; i++) {
    a[i] = (i+1) * 10;
  }
  
  int *b = a;
  b[0] = 42;
  printf("%d\n", a[0]);

  return 0;
}
```

* A *deep* copy is a brand new (separate) memory location containing the same elements

```c
#include <stdlib.h>
#include <stdio.h>

/**
 * This function takes an integer array of size
 * n and returns a new *deep copy* of it.
 */
int * copyOf(const int *arr, int n) {

  int *copy = (int *) malloc(n * sizeof(int));
  for(int i=0; i<n; i++) {
    copy[i] = arr[i];
  }
  return copy;
  
}

int main() {
  
  int n = 5;
  int *a = (int *) malloc(n * sizeof(int));
  for(int i=0; i<n; i++) {
    a[i] = (i+1) * 10;
  }
  

  int *b = copyOf(a, n);
  b[0] = 42;
  printf("%d\n", a[0]);

  // if you are *interested*, RTM:
  //alternatively:
  b = (int *) malloc(n * sizeof(int));
  memcpy(b, a, n * sizeof(int));

  return 0;
}
```

## Multidimensional arrays

* You can have arrays with more than one "dimension"
* 1-D arrays: regular old arrays
* 2-D arrays: rows and columns (tables or matrices)
* 3-D arrays: rows, columns and aisles or "lanes"
* 4+-D arrays: 
* In general, limit consideration to at most 2 dimensions
* If you find you are "needing" more dimensions, you might instead want a *structure*
* In C, a pointer `int *arr` points to a one-dimensional array
* To point to a 2-D array, you need to use `int **arr`
* In fact, an `int **arr` is a pointer to an *array of pointers*

```c
int n = 3, m = 4;//3 rows, 4 columns
int **matrix = NULL;
matrix = (int **) malloc(n * sizeof(int *));
for(int i=0; i<n; i++) {
  //setup the i-th "row":
  matrix[i] = (int *) malloc(m * sizeof(int));
}

matrix[0][0] = 42;
matrix[2][3] = 101;
```

* Once you are done with a 2-D array, how do you clean up?
* To do this, you need to free up each row first, THEN the array of pointers

```c
for(int i=0; i<n; i++) {
  free(matrix[i]);
}
free(matrix);
```

* What about arrays of `char`s?






  