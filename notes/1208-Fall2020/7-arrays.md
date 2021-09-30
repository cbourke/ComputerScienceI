
# CSCE 155E - Computer Science I
## Arrays
### Fall 2020

* It is really rare that you only deal with say one variable or one piece of data
* You usually want to process or operate on a *collection* of pieces of data
* In C, collections of similar pieces of data can be stored *arrays*
  * Arrays are a collection of variables of the same type
  * Arrays have a single identifier (name)
  * Elements in an array can be accessed using an *index*: the first element is always at index 0.  The second is at index 1, etc.
  * If there are `n` element in an array, the last one is at index `n-1`
  * Indexing is achieved using square brackets: `a[0]` would be the first element

## Static Arrays

* Static arrays are arrays of a fixed size that are allocated on top of the program stack
* Syntax:

```c
//create an array that can hold 10 integers:
int arr[10];

//create an array that can hold 20 doubles:
double numbers[20];
```

Observations:
* Just like any other uninitialized variables, the contents of the an array have no default values
* Generally, there is random garbage stored in uninitialized arrays
* Once you have an array though, you can start setting the values using indexing and the normal assignment operator

```c
arr[0] = 42;
arr[1] = -5;
arr[2] = 3.5; //truncation: results in 3
arr[9] = 42; //sets the last value

//uh oh:
arr[10] = 101;
arr[-1] = 102;
```

* Accessing elements outside an array is *undefined behavior*
  * MAY be a segmentation fault
  * MAY be a stack smashing
  * MAY simply corrupt your own memory
  * It may or may not result in bad consequences, but it is just not good!

## More Syntax

* You can declare an initialize a static array in one line:

```c
int n = 7;
int primes[] = {2, 3, 5, 7, 11, 13, 17};
```

* In general, there is NO WAY to determine the size of an array after it has been created in C
* In C, YOU *must* keep track of the size of every array that you create; this is known as *memory management*
* Also called "bookkeeping"
* It is *your* responsibility to keep track of all the sizes of every array
* Consequence: if you pass an array to a function, you *also* need to pass the *size* of the array to the function (in general this is a separate integer value)
* Example: declare an array of size 100, set each element equal to 1, 2, 3, ... 100, then print the elements in the array then sum up all values

```c

  int n = 100;
  int arr[100];

  for(int i=0; i<n; i++) {
    arr[i] = (i+1);
  }

  int sum;
  for(int i=0; i<n; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
    sum += arr[i];
  }
  printf("total = %d\n", sum);
```

## Dynamic Arrays

* Static arrays are very limited
  * Since they are allocated on the stack, you don't have a lot of memory to work with
  * Since they are allocated on the stack, you can *never* return an array from a function!
* Alternative: dynamic arrays
* Dynamic arrays are arrays whose memory is allocated on the program "heap" instead of the program stack
* The Heap is a much larger but "less organized" chunk of memory
* In general, we ask the operating system for more memory; it either gives us a chunk of memory or an error
* The way you ask for memory is through **m**emory **alloc**ation
* The function you use to do this is `malloc`
* Signature:

`void * malloc(size_t size);`

* Think of `size_t` as an integer: it corresponds to the number of bytes you wish to allocate
* You can use the `sizeof` macro to determine how many bytes each type of variable takes
  * `sizeof(int)` will give you the number of bytes for each `int`
  * `sizeof(double)` gives you the number of bytes for each `double`
  * Ultimately, you use `sizeof` and multiply by the number of elements you want to store
* `void *` is a generic "void" pointer:
  * It is simply a raw memory address
  * It can point to any memory location
  * If we didn't use a generic pointer, then we would have to have multiple functions: `mallocForInts`, `mallocForDoubles`
  * To deal with it, we generally use a typecast to force the returned pointer to become a particular kind of pointer, `int *` or a `double *`, etc.
* Example

```c
int n = 10000000;
int *arr = (int *) malloc(n * sizeof(int));

for(int i=0; i<n; i++) {
    arr[i] = i + 1;
}

//or an array of doubles:
double *brr = (double *) malloc(n *sizeof(double));
brr[0] = 3.1415;
brr[n-1] = 42.5;
```

* More Details
  * If `malloc` fails for any reason, it returns `NULL`
  * After allocation you can treat the array like a regular old array using square brackets for indexing, the first element is still at index zero, last element is still at index `n-1`
  * YOU STILL HAVE TO KEEP TRACK of the size of the array

## Memory Management

* Once you allocate a chunk of dynamic memory, you can use it however you want
* Once you are done with it, you clean it up
* If you do not clean up memory, then you potentially have a *memory leak*: you allocate a bunch of memory over and over and never give it back
* It will eventually cause your system to come to a halt (huge slow down)
* Once you are done with the memory, you can give it back to the operating system so the OS can reallocate it to either your program or to others
* To give the memory back you `free` it up:

```c
int *arr = (int *) malloc(n * sizeof(int));
//use the array...

//free up the memory:
free(arr)
```

* You simply have to give the pointer to the `free` function
* Attempts to access freed memory are undefined behavior
* If you try to `free` memory twice it will result in a (usually) "double free" corruption
* Being good stewards of your memory and doing good bookkeeping is known as "memory management"


## Using arrays with functions

* Passing an array to a function
  * All arrays are actually memory addresses
  * Thus all arrays are simply pointers
  * To pass an array to a function, you pass a pointer
  * In other words you pass by reference
* Example: design a function to compute the sum of elements in an integer array

```c

int sumArray(int *arr, int n) {

  int sum = 0;
  for(int i=0; i<n; i++) {
      sum += arr[i];
  }
  return sum;
}
```

* Observations:
  * When you pass an array to a function, you also have to pass its size!
  * `int *` can be a SINGLE integer variable OR it can be an entire array of integer variables
  * The way that arrays actually work is that the array/pointer name (identifier) is simply pointing to the first element in the array  

* You can also return arrays from a function
  * The return type is simply a pointer
  * Careful: you cannot also directly return the size of the array!
* Demonstration:
  * Write a function that creates a new array of integers all initialized to zeros
  * Write a function that *returns a new array* containing only the even integers of a given array

```c
#include <stdlib.h>
#include <stdio.h>

int *getZerosArray(int n) {
  int *arr = (int *) malloc(n * sizeof(int));
  for(int i=0; i<n; i++) {
    arr[i] = 0;
  }
  return arr;
}

/**
 * This function takes an array of integers and
 * returns a new array filled with only even values
 * from the array.
 *
 * The size of the resulting array is communicated
 * back to the calling function by using the pass-by-reference
 * variable, newSize
 *
 */
int *getEvens(int *arr, int n, int *newSize) {

  //0. error checking
  if(arr == NULL || n <= 0 || newSize == NULL) {
    return NULL;
  }

  //1. iterate through an array to determine
  //  how big of a new array you need
  int count = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] % 2 == 0) {
      count++;
    }
  }
  //2. allocate memory for the new array:
  int *result = (int *) malloc(count * sizeof(int));

  //3. copy over the even values:
  int index = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] % 2 == 0) {
      result[index] = arr[i];
      index++;
    }
  }

  //4. set newSize to count:
  *newSize = count;

  return result;
}

int main(int argc, char **argv) {

  int n = 10;
  int *arr = getZerosArray(n);

  // for(int i=0; i<n; i++) {
  //     printf("arr[%d] = %d\n", i, arr[i]);
  // }

  int brr[] = {2, 3, 4, 6, 10, 4, 2, 3, 1, 4};
  int newSize;
  int *bEvens = getEvens(brr, 10, &newSize);

  for(int i=0; i<newSize; i++) {
      printf("bEvens[%d] = %d\n", i, bEvens[i]);
  }

}
```

## Other Issues

### Pointer Arithmetic

* The square bracket syntax is actual "syntactic sugar" for pointer arithmetic
* When passing an array to a function, no ampersand is necessary
* The name of an array is its memory address!  It is already a pointer, so no need to change it into a pointer
* By default, all arrays are passed-by-reference
* Without the square brackets, we'd have to determine which memory location the second element is at, the third, etc.
  * Suppose we have an integer array, `arr`
  * The first element is at memory location `arr` (or `arr[0]` ie 0 bytes away from `arr`) or equivalently, `arr + 0`
  * The second element is 4 bytes away: `arr + 4`
  * The third element is 8 bytes away: `arr + 8`
  * In general, the $i$-th element is `i * 4` bytes away: `arr + 4 * i`, `arr + sizeof(int) * i`
  * It is far more convenient to write `arr[0]`, `arr[1]`, `arr[2]`, `arr[i]`

## Constant Arrays

* If you don't want a function to make changes to your array, you can declare it as `const` (constant)
* This makes your array (nearly) read-only
* Attempts to change a `const` array can be detected by the compiler and it results in a compiler error
* In general, any function that does *not* make changes to an array should declare them as `const`
* In general, non-`const` arrays are *assumed* to be changed by the function

## Shallow Versus Deep Copies

* When references are copied, they are only *shallow* copies: changes to an array through one reference are "seen" by the second reference
* Alternatively: if you want a totally distinct copy, you want a *deep copy*: you want two completely different arrays stored in two completely different memory addresses.
* Use deep copies when you *don't* want changes to the original (or you want to retain the original data)

## Multidimensional Arrays

* You can always have arrays with more than one "dimension"
* 1-D arrays: regular old arrays
* 2-D arrays: rows and columns (tables, matrices)
* 3-D arrays: rows, columns, aisles or "lanes"
* 4-D arrays: Nah
* In general, limit consideration to 2-D arrays at most
* In C, a pointer `int *arr` points to a 1-D array
* Consequently, an `int **mat` points to a 2-D array
* essentially, the `**` points to an array of pointers
* Each pointer in the array points to its own 1-D array!
* Demo:

```c

  int n = 3;
  int m = 2;
  int **mat = (int **) malloc(n * sizeof(int*));
  for(int i=0; i<n; i++) {
    mat[i] = (int *) malloc(m * sizeof(int));
  }
  mat[0][0] = 42;
  mat[0][1] = 101;

  mat[1][0] = 3;
  mat[1][1] = 20;

  mat[2][0] = 17;
  mat[2][1] = 34;

  //print out the matrix:
  for(int i=0; i<n; i++) { //for each row...
    printf("[ ");
    for(int j=0; j<m; j++) { //for each column in row i...
      printf("%3d ", mat[i][j]);
    }
    printf("]\n");
  }

  //clean up
  //free up each row first...  
  for(int i=0; i<n; i++) {
    free(mat[i]);
  }
  free(mat);
```

* What about arrays of `char` values?  Strings (after the midterm)

* Next: some tooling: profiler (static analysis tool) and a (proper) debugger
```text












```
