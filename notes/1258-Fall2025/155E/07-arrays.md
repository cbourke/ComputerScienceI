
# CSCE 155E - Computer Science I
## Arrays
### Fall 2025

* It is rare to only deal with 1 number of 1 character, or 1 piece of data
* Collections of data are used to store multiple instances of those things
* In C data is stored in arrays.  Arrays are collections of *similar* types of data
* Arrays only contain one type of data: `int`, `double`
* In general:
  * Arrays have a single name/identifier
  * To access individual *elements* in an array, you use an *index* (an integer)
  * Suppose we have an array named `arr` with `n` elements in it
  * Ex: first element is at `arr[0]`
  * Second element is at `arr[1]`
  * The last element is at `arr[n-1]`
  * This is known as 0-indexing

## Arrays in C:

### Static Arrays

* static arrays in C are allocated on the program *stack*
* They exist in a single stack frame
* There is no default value defined for uninitialized array values

```c

    //create a static array of integers that can hold 10 integers:
    int n = 10;
    int arr[10];

    //what is in arr right now?
    // who knows!?!
    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    arr[0] = 42;
    arr[1] = 10;
    arr[n-1] = 123;

    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    for(int i=0; i<n; i++) {
        arr[i] = 0;
    }

    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

    for(int i=0; i<9; i++) {
        printf("primes[%d] = %d\n", i, primes[i]);
    }
```

* You can iterate over the elements in an array using the "idiomatic" for-loop

### Bad Things can happen

* Going outside the bounds of the array has various consequences.
  * Stack Smashing event: you've destroyed/corrupted your own memory
  * Undefined behavior: may not crash, but you can no longer rely on the output
* Static arrays are extremely limited
  * Allocated on the stack
  * Stack memory is limited: 4MB, 8MB, (embedded systems), in kilobytes
  * Once full, a stack will then overflow (stack overflow)
  * You cannot typically hold "large" or even "moderate" amounts of data on the stack
  * What you need is a "dynamic array"

## Dynamic Arrays

* Dynamic arrays are allocated on the *heap* memory space instead of the tack
  * Heaps are the same memory but with fewer limitations
  * Stack memory is "efficient"; heap memory is less so
* How do you allocate memory on the heap?
* You do so by asking (requesting) the operating system for a "chunk" of memory
* To do this, you use the function `malloc()`: **m**emory **alloc**ation
* Signature: `void * malloc(size_t n)`
  * `size_t` can be treated as an integer
  * The input is the *number of bytes you want to allocate*
  * Generally you need to compute the number of bytes yourself!
  * To do that you can use `sizeof` to determine how many bytes each type takes:
  `sizeof(int), sizeof(double), sizeof(char)`
  * `malloc()` returns a `void *` pointer: this is a generic void pointer
  * A void pointer is a raw memory address
  * It can point to anything!  It can point to `int`s, `double`s, etc.
  * Generally we will cast the generic void pointer to the type we want: `(int *)`, `(double *)`

```c

    //create a static array of integers that can hold 10 integers:
    int n = 10;
    //int arr[10000000];

    int *arr = (int *) malloc( n * sizeof(int) );
    //the array is allocated and can be treated like a regular old array

    arr[0] = 42;
    arr[n-1] = 123;

    printf("first: %d\n", arr[0]);
    printf("last : %d\n", arr[n-1]);
```

* Similar functions: `calloc()`, `realloc()`
* Once you have successfully allocated memory, you can use it like any other array using square brackets and indices
* Same problems exist if you try to access memory that doesn't belong to you: undefined behavior, seg faults, etc.
* What happens if you run out of memory or ask for an invalid amount of memory?
* If `malloc()` fails to allocate memory (ran out or you asked for an invalid amount) it returns `NULL`

## Memory Management

* Once you allocate a chunk of dynamic memory, you can use it for however long you want
* Once you are done with it, you need to clean up after yourself
* You *should* give it back to the operating system so it can reuse it
* To give it back to the OS: you use `free()`
* Failure to free unused memory may result in a *memory leak*: more and more memory is allocated and never free'd until resources become scarce or not available; slowing down the system.

* Example:

```c
int n = 1000;
double *arr = (double *) malloc( sizeof(double) * n );

//TODO: do something with arr

//NOw we are done with it, so free it:
free(arr);
```

## Pitfalls:

* Once you have free'd memory it is NOT yours, you should *not* attempt to use it...
  * It may have been given away already!
  * Attempts to access free'd memory will result in *undefined behavior*
  * It *MAY* result in a seg fault
* You can only free memory once
  * "Double Free" may cause a segfault...
* There is **absolutely NO way** to determine the size of an array in C!!!
  * You need to do your own "bookkeeping"
  * Ignore stackoverflow misinformation

## Arrays and Functions

* You can pass arrays to functions just as you would any other pointer variable
* When you pass an "array" to a function, you are actually passing a *pointer*
* A pointer up to now has only ever pointed to ONE thing, now that pointer will point to an array = multiple things
* HOWEVER: you need to do your own "bookkeeping"
  * Any time you pass an array (pointer) to a function, you need to tell the function how *big* the array is (usually done with an integer `n`)
  * There is NO, ABSOLUTELY NO, way to tell how big a dynamically allocated array is in C!
* Careful: because arrays are passed by reference, the functions *can* make changes to them
  * You can prevent this by using the `const` keyword:
  `const int *arr`
  * If made `const` the compiler will detect attempts to change the array and not compile
* You can also write functions that *return* new arrays
  * `malloc` does this
  * Be careful: who "owns" memory?  It depends
  * If you are done using the memory *inside* the function, the function is responsible for `free`ing it
  * If you are *returning* the memory via a pointer to the calling function, then the calling function is responsible for `free`ing it
* Generally: ALWAYS free up memory when you are done with it
  * However, it is *sometimes* acceptable to ignore cleanup in the `main()` function at the end

```c
/**
 * Chris Bourke
 * 2025-09-12
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * Fills the given array of integers (of size n) with zeros.
 */
void zeroOut(int *arr, int n);

/**
 * Creates an integer array of size n and sets each value to 1.
 */
int * createOnesArray(int n);

/**
 * Prints the given array of n integers to the standard output
 * in a nicely formatted manner.
 */
void printArray(const int *arr, int n);

int main(int argc, char **argv) {

    int n = 10;
    int *arr = (int *) malloc( sizeof(int) * n );

    zeroOut(arr, n);

    printArray(arr, n);
    arr[0] = 123;
    printArray(arr, n);
    free(arr);

    int *brr = createOnesArray(n);
    printArray(brr, n);
    free(brr);

    return 0;
}

void zeroOut(int *arr, int n) {

    if(arr == NULL || n < 0) {
        return;
    }

    for(int i=0; i<n; i++) {
        arr[i] = 0;
    }
    return;
}

void printArray(const int *arr, int n){

    if(arr == NULL || n < 0) {
        return;
    }

    if(n < 1) {//not an error, but an exception *corner case*
        printf("[]\n");
        return;
    }
    printf("[");
    for(int i=0; i<n-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d", arr[n-1]);
    printf("]\n");
    return;
}

int * createOnesArray(int n){
    if(n < 0) {
        return NULL;
    }

    int *arr = (int *) malloc( sizeof(int) * n );
    for(int i=0; i<n; i++) {
        arr[i] = 1;
    }

    return arr;
}

```

## Pointers & Indices

* How arrays actually work...
* Arrays (names of arrays) are actually pointers that points to the *beginning* of a memory location that holds a bunch of elements in a contiguous manner
* Arrays are nothing more than the memory address of the first element in the array
* This is why indexing starts at 0: zero bytes offset from the first element
* This is all done by C using *pointer arithmetic*
* This is why we have to do our own bookkeeping

```c
int n = 10;
int *arr = (int *) malloc( sizeof(int) * n );

arr[0] = 42;
printf("first: %d\n", arr[0]);
*arr = 123;
printf("first: %d\n", arr[0]);

arr[1] = 43;
printf("second: %d\n", arr[1]);
//TODO: fix this
*(arr + sizeof(int)) = 200;
printf("second: %d\n", arr[1]);
```

## Shallow vs Deep Copies

A shallow copy is when two arrays share the same memory address
  * There is only ONE actual array in memory
  * Changes to one affect the other
* A deep copy is when you copy an array to another array so that they are *completely different arrays*
  * Changes to one do not affect the other
  * There are TWO actual arrays in TWO different memory locations

### Multidimensional Arrays

* A regular old array is a 1-D array (one dimensional)
* You can also have multidimensional arrays: 2D arrays, 3D arrays, 4D arrays, etc.
* Our focus: 2-D arrays
  * Rows and columns
  * Tables!
  * spreadsheets
  * Matrices
* In C a regular old array (1-D) of integers is `int *arr`
* A 2-D array `int **table`
* Once you ahve a 2-D array, you specify the row and the column index: `table[0][0]` is the `0`-row (first row), `0`-column (first column)
* The first index is usually the row, the second is the column (row-major form)
* Suppose you have a 2-D array with `n` rows and `m` columns, where is the *last* element (last row, last column)? `table[n-1][m-1]`
* How do we allocate memory for a 2-D array?

```c

    int n = 3; //3 rows
    int m = 5; //5 columns
    int **table = (int **) malloc( sizeof(int *) * n );
    for(int i=0; i<n; i++) {
        //initialize the i-th row
        table[i] = (int *) malloc( sizeof(int) * m );
    }

    table[0][0] = 42;
    table[n-1][m-1] = 123;

    for(int i=0; i<n; i++) {
        free(table[i]);
    }
    free(table);
```

### Exercises

* Write a function that takes an array of integers and returns a new array containing only the positive values from the original array
  * Input: `{5, -1, 0, 3, 6, 9, 42, -7, 10, -1, 43, 2, 34, 3, 23, 4, 43}`
  * Output `{5, 3, 6, 9, 42, 10, 43, 2, 34, 3, 23, 4, 43}`


```c
/**
 * Chris Bourke
 * 2025-09-12
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * Fills the given array of integers (of size n) with zeros.
 */
void zeroOut(int *arr, int n);

/**
 * Creates an integer array of size n and sets each value to 1.
 */
int * createOnesArray(int n);

/**
 * Prints the given array of n integers to the standard output
 * in a nicely formatted manner.
 */
void printArray(const int *arr, int n);

/**
 * TODO: write documentation
 */
int *getPositives(const int *arr, int n, int *sizeOfResult);

/**
 * Makes a deep copy of the given array of n integers and returns
 * the new array.
 */
int *deepCopy(const int *arr, int n);

int main(int argc, char **argv) {

    int n = 17;
    int sizeOfBrr;
    int arr[] = {5, -1, 0, 3, 6, 9, 42, -7, 10, -1, 43, 2, 34, 3, 23, 4, 43};
    int *brr = getPositives(arr, n, &sizeOfBrr);
    printArray(arr, n);
    printArray(brr, sizeOfBrr);

    return 0;
}

void zeroOut(int *arr, int n) {

    if(arr == NULL || n < 0) {
        return;
    }

    for(int i=0; i<n; i++) {
        arr[i] = 0;
    }
    return;
}

void printArray(const int *arr, int n){

    if(arr == NULL || n < 0) {
        return;
    }

    if(n < 1) {//not an error, but an exception *corner case*
        printf("[]\n");
        return;
    }
    printf("[");
    for(int i=0; i<n-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d", arr[n-1]);
    printf("]\n");
    return;
}

int * createOnesArray(int n){
    if(n < 0) {
        return NULL;
    }

    int *arr = (int *) malloc( sizeof(int) * n );
    for(int i=0; i<n; i++) {
        arr[i] = 1;
    }

    return arr;
}

int *deepCopy(const int *arr, int n) {

    if(arr == NULL || n < 0) {
        return NULL;
    }

    int *copy = (int *) malloc( sizeof(int) * n );
    for(int i=0; i<n; i++) {
        copy[i] = arr[i];
    }
    return copy;
}

int *getPositives(const int *arr, int n, int *sizeOfResult){

    //x 0. error handling
    if(arr == NULL || n < 0) {
        return NULL;
    }
    //0.5: count up the number of elements that need to be copied (one solution);
    //1. create the new array temporarily, make it big enough (another solution)
    int *temp = (int *) malloc( sizeof(int) * n );
    //2. for each element in arr:
    int j = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > 0) {
            //copy it over
            temp[j] = arr[i];
            j++;
        }
    }
    //now create a new copy that is *exactly* the size we need...
    int *result = deepCopy(temp, j);
    *sizeOfResult = j;
    free(temp);
    return result;
}
```



```text














```
