
# Computer Science I
## ECEN 194 - Fall 2022
### Arrays

* It is rare that you only deal with say one variable or one piece of data
* You can store multiple pieces of data in a collection
* In C you use *arrays* to store elements of a similar type
  * Arrays are *ordered* collections of variables of the same type
  * Arrays have one single identifier (name)
  * You can access individual elements in the array using an *index*
  * The index is specified using the square bracket notation:
    * THe first element is at `arr[0]` (zero indexing: the first is at index 0)
    * The second is at `arr[1]`
    * the third is at `arr[2]`
    * YOu can use a variable as an index: `arr[i]` is the i-th element
    * If there are $n$ elements in an array, the last one is at `arr[n-1]`

## Static Arrays

* Static arrays are arrays that are of a fixed size and allocated on the program stack
* Note: we will quickly abandon static arrays...

```c


    //create a static array that can hold 5 integers:
    int arr[5];
    arr[0] = 42;
    arr[1] = 101;
    arr[4] = 109;

    for(int i=0; i<5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
```

* Observations:
  * There are no default values defined in C for any variables including the contents of an array (it could be zero, could be garbage, etc.)
  * Once you've created an array, you can use the square bracket syntax to access or set the elements of an array

* Pitfalls:
  * What happens if you attempt to access elements outside the array?
  * Ex: `arr[-1]`
  * Ex: `arr[5]`
  * Attempts to access elements outside the array are *undefined behavior*
  * They may result in a seg fault, they may result in bad output, it may not lead to a problem at all!
  * You are simply corrupting your own memory

* System stack memory is *extremely limited*
  * Usually you are limited on the order of megabytes or even kilobytes

# Better Solution: Dynamic Arrays

* Dynamic arrays are arrays whose memory is allocated on the system *heap* instead of the stack
* To allocate memory on the heap for use in an array you use the **m**emory **alloc**ation function: `malloc`
* Signature:
`void * malloc(size_t size)`
  * You can think of `size_t` as an integer: it correspondes to the number of bytes you want to allocate
  * YOu can use the `sizeof()` macro to determine how many bytes each type takes: `sizeof(int), sizeof(double)`
  * Don't hardcode values!
  * Upon successful allocation, `malloc` returns a pointer to the memory it allocated for you
  * `malloc` returns a *generic void pointer*: `void *`
  * `int *` is an integer pointer
  * `double *` is a double pointer
  * `void *` is a generic pointer: a raw memory address that can point to *any* type
  * `malloc` is written to return a generic pointer so you don't need multiple versions of it, if not, you need `mallocForInts`, `mallocForDouble`, `mallocForChar`
  * To ensure it points to the correct type, we *type cast* the returned pointer
* If you ask for too much memory or the system runs out (you hit a limit of some sort), `malloc` returns `NULL`

## Bookkeeping

* In C, you have *manual memory management*: it is *your* responsibility to ensure that you are not:
  * Accessing invalid indices
  * Keeping track of the size of the array (so you don't do the first one)
  * You need to communicate to any function the size of the array os it doesn't access invalid indices
  * You need to clean up after yourself: once you are done using dynamically allocated memory, free it up: `free()`

```c
for(int i=0; i<1000; i++) {
        int n = 5000000;
        int *arr = (int *) malloc( n * sizeof(int) );
        //TODO: do something with arr....
        arr[0] = 42;
        arr[n-1] = 42;
        sleep(1);
        free(arr);
    }
```

## More Pitfalls:
  * Careful: once you have freed memory, *you cannot access it*; attempt to do so will result in... a segmentation fault: the memory no longer belongs to you
  * Careful: only free something once!  If you free it a second time (without reallocating it), it is a "double free" error: a segmentation fault

## Memory Management

* Once you allocate a chunk of dynamic memory, you can use it however long you want in your program
* Once you are done with it you should clean it up
* You can *free* up memory (give it back to the heap or to the OS) using the `free()` function
* You simply pass in the pointer to the dynamically allocated memory
* Don't Dos:
  * Don't "double" free an array (you cannot free something twice)
  * Don't free your stack
  * Don't free `NULL` or invalid variables
  * Don't try to use an array after it has been free'd
* Always remember to free your memory when you are done with it
* Failure to do so will lead to "memory leaks"

## Arrays & Functions

* You can pass arrays to a function and have that function process the data
* You can return arrays from functions
* All of this is done through pointers: pass-by-reference
* Also, when you pass an array to a function, you need to tell it how big it is!
* The `const` keyword can be placed in front of an array parameter to make the promise that no changes will be made to the contents of the array
* You cannot return static arrays from a function!  They are destroyed when the stack frame is popped off the top!
* ALWAYS ALWAYS ALWAYS use the `-Wall` flag

### Who "owns" memory?

* Which function or piece of code is responsible for cleaning up memory (freeing it)?
* In general: what ever piece of code "owns" the memory is responsible for cleaning it up
* Example: If a  function only allocates temporary that it does not return, *the function* is responsible
* Example: if the function *returns* the memory, it is *transferring* ownership to the calling function

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * Sums the given array of integers (of size n) and returns
 * the total.
 */
int sum(const int *arr, int n) {

    if(arr == NULL || n < 0) {
        return 0;
    }

    int total = 0;
    for(int i=0; i<n; i++) {
        total += arr[i];
        //arr[i] = 0;
    }
    return total;

}

void printArray(const int *arr, int n) {

    if(arr == NULL || n < 0) {
        printf("(null)\n");
        return;
    }

    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/**
 * Creates an array of the given size (n) and fills it
 * with ones.  Returns NULL for invalid inputs.
 */
int *getOnesArray(int n) {

    if(n <= 0) {
        return NULL;
    }

    int *result = (int *) malloc( n * sizeof(int) );

    for(int i=0; i<n; i++) {
        result[i] = 1;
    }
    //wrong: you cannot return it... free(result);
    return result;
}

/**
 * This function takes an array of integers (of size n) and
 * creates and returns a new array containing only the even
 * values from the original array.
 *
 * Ex:         [5, 6, 8, 9, 2, 3, 4, 1, 0]
 * Will return [6, 8, 2, 4, 0]
 */
int *getEvens(const int *arr, int n, int *sizeOfResult) {

    //TODO: error handling

    //1. count how many even values there are in arr...
    int numEvens = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] % 2 == 0) {
            numEvens++;
        }
    }
    *sizeOfResult = numEvens;

    //2. initialize the result array...
    int *result = (int *) malloc( numEvens * sizeof(int) );

    //3. iterate over the array arr and if the i-th element is
    //   even, add it to the result array
    int j = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] % 2 == 0) {
            //even, add it to the result array:
            result[j] = arr[i];
            j++;
        }
    }
    //NOPE free(result);
    return result;

}

int main(int argc, char **argv) {

    int n = 8;
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

    printArray(primes, n);
    int total = sum(primes, n);
    printf("sum of first 8 primes is %d\n", total);
    printArray(primes, n);
    int m = 10;
    int *ones = getOnesArray(m);
    printArray(ones, m);
    free(ones);

    int sizeOfFoo = 9;
    int foo[] = {5, 6, 8, 9, 2, 3, 4, 1, 0};
    int sizeOfEvens;
    int *evens = getEvens(foo, sizeOfFoo, &sizeOfEvens);
    printArray(evens, sizeOfEvens);
    free(evens);


    return 0;
}
```

## Multidimensional Arrays

* Regular arrays are 1-D arrays (one dimensional)
* 2-D arrays have rows and columns: matrices, tables
* 3-D arrays: rows, columns, aisles, 4-D, etc.: rethink what you're doing
* A regular array is a pointer: `int *`
* A 2-D array is an array of pointers to pointers: `int **`
* You have an array of pointers, each of which points to a "row" of elements/values/integers

```c

    //create a 2-D table that is 3 rows, 5 columns
    int numRows = 3;
    int numCols = 5;

    //create an array of pointers:
    int **table = (int **) malloc( numRows * sizeof(int*) );
    for(int i=0; i<numRows; i++) {
        //set up the i-th row of numCols size:
        table[i] = (int *) malloc( numCols * sizeof(int) );
    }
    //set the top left element to 42:
    table[0][0] = 42;
    //set the bottom right element to 101
    table[2][4] = 101;

    for(int i=0; i<numRows; i++) {  //for each row...
        for(int j=0; j<numCols; j++) {  //for each column...
            printf("%4d ", table[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<numRows; i++) {  //for each row...
        //free the row
        free(table[i]);
    }
    free(table);
```



```text









```
