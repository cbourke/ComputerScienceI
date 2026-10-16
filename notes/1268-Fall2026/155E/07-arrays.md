
# CSCE 155E - Computer Science I
## Arrays
### Fall 2026

* It is rare to only deal with 1 number of 1 character, or 1 piece of data
* Collections of data are used to store multiple instances of those things
* In C data is stored in arrays.  Arrays are collections of *similar* types of data
* Arrays only contain one type of data: `int`, `double`
* In general:
  * Arrays will have one single name (identifier), `arr`
  * To access individual *elements* in an array, you use an *index* (an integer)
  * Suppose we have an array named `arr` with `n` elements in it
  * The first element is at `arr[0]`
  * The second is at `arr[1]`
  * The last element is at `arr[n-1]`
  * This is known as "0-indexing"
* Pitfalls:
  * Do not go outside the size of an array: undefined behavior, segfaults, etc. or it may just corrupt your program's program
  * Ex: `arr[-1]` is invalid
  * Ex: `arr[n]` is invalid

## Arrays in C:

### Static Arrays

* static arrays in C are allocated on the program *stack*
* They exist in a single stack frame
* This is extremely limited
  * Stack space is limited to 4MB, 8MB or maybe even KB
  * You can never return array stack data from a function: because the stack frame is destroyed after it returns


```c

    //static array that can hold 10 integers:
    int arr[10];
    arr[0] = 42;
    arr[9] = 101;
    //observation: uninitalized values can be anything, garbage, deadbeef, etc.
    for(int i=0; i<10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    //illegal, but we got away with:
    arr[-1] = 142;
    printf("arr[-1] = %d\n", arr[-1]);

    //illegal and we got caught: stack smashing event killed our program!
    arr[10] = 1234;
    printf("arr[10] = %d\n", arr[10]);
```

### Bad Things can happen

* Going outside the bounds of the array has various consequences.
  * Stack Smashing event: you've destroyed/corrupted your own program's memory
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
  * Stack memory is "efficient" and "organized" but the heap is less so
* How do you allocate memory on the heap?
* You do so by asking (requesting) the operating system (OS) for a "chunk" of memory
* To do this, you use the function `malloc()`: **m**emory **alloc**ation
* Signature: `void * malloc(size_t n)`
  * `size_t`: an internal integer that represents a number of bytes; for our purposes: treat it as an integer
  * The input is the *number of bytes you want to allocate*
  * Generally you need to compute the number of bytes yourself!
  * To do that you can use `sizeof` to determine how many bytes each type takes: `sizeof(int), sizeof(double), sizeof(char)`
  * Return value: `void *`: this is a generic "void" pointer
    * Normal pointers: `int *` points to an integer
    * `void *` points to a raw memory address: it can point to anything!
    * Generally we will force the returned pointer to the be the appropriate type through typecasting: `(int *)` forces it to become an `int` pointer
* Demonstration

```c

    int n = 1000000;

    int *arr = (int *) malloc( n * sizeof(int) );
    //the array is allocated and can be treated like a regular old array

    arr[0] = 42;
    arr[n-1] = 123;

    printf("first: %d\n", arr[0]);
    printf("last : %d\n", arr[n-1]);
```

* Similar functions: `calloc()`, `realloc()`
* In the event of failure, `malloc` and other functions will return `NULL`
* Once you have successfully allocated memory, you can use it like any other array using square brackets and indices
* Same problems exist if you try to access memory that doesn't belong to you: undefined behavior, seg faults, etc.
* What happens if you run out of memory or ask for an invalid amount of memory? It returns `NULL`

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

## Pitfalls

* Once you've free'd memory it is no longer yours, you should *not* attempt to use it
  * It may have already been given to another process to use
  * Attempts to access it are *undefined behavior* and
  * May result in a segfault
* You can only free memory once:
  * `free`ing it twice may result in a seg fault or "double free" error
* Keep in mind: there is NO, absolutely NO way to reliably determine the size of a dynamic in C
  * You are resopnsible for *bookkeeping*: keeping the size of an array in a second `int` variable

```c

        int n = 10000000;
        int *arr = (int *) malloc(n * sizeof(int));
        arr[0] = 42;
        arr[n-1] = 101;
        free(arr);
        //attempting to access memory after you have freed is
        // corruption of data
        // segmentation fault
        //printf("first: %d last: %d\n", arr[0], arr[n-1]);

        //freeing something that doesn't belong to you
        // ie freeing it twice: segmentation fault or "double free error"
        //free(arr);

        //freeing something that does belong to us, but may
        // corrupt our data:
        //munmap_chunk(): invalid pointer
        //Aborted (core dumped)
        int x = 42;
        int *p = &x;
        free(p);
```

## Arrays and Functions

* You can pass an array to a function just as you would any other pointer variable
* When you do, you always have to include the *size* of the array in an `int` variable (typically `int n` or `int size` or `int numElements`): C only has manual bookkeeping
* Careful: because arrays are passed by reference, the functions *can* make changes to them
  * You can prevent this by using the `const` keyword:  
   `const int *arr`
  * If made `const` the compiler will prevent any changes
* You can also write functions that *return* new arrays
  * `malloc` does this
  * Write a function that returns a particular type of array

### Multidimensional Arrays

* A regular old array is a 1-D array (one dimensional)
* You can also have multidimensional arrays: 2D arrays, 3D arrays, 4D arrays, etc.
* Our focus: 2-D arrays
  * Rows & Columns: tables, spreadsheets
  * Mathematics: matrices
* IF a 1-D array is `int *`
* A 2-d array is an `int **`

```c
int numRows = 3;
int numCols = 4;
//want to create a 3 x 4 table/matrix
int **table = (int **) malloc(numRows * sizeof(int *) );
//now create each row...
for(int i=0; i<numRows; i++) {
  //create the i-th row...
  table[i] = (int *) malloc(numCols * sizeof(int) );
}

//use it like a 2-d array:
table[0][0] = 42;
table[2][3] = 101;

for(int i=0; i<numRows; i++) {
  for(int j=0; j<numCols; j++) {
    table[i][j] = i * 10 + j;
  }
}

for(int i=0; i<numRows; i++) {
  //free the i-th row
  free(table[i]);
}
free(table);
```

## Misc

### Shallow vs Deep Copies

* A shallow copy is when two arrays share the same memory address
  * There is only actually ONE array
  * Changes to one will affect both of them
* A deep copy is when you copy an array to another array so that they are *completely different arrays*
  * Changes to one do not affect the other
  * There are TWO actual arrays in TWO different memory locations

### Pointer Arithmetic

* How arrays actually work...
* Arrays (names of arrays) are actually pointers that points to the *beginning* of a memory location that holds a bunch of elements in a contiguous manner
* Arrays are nothing more than the memory address of the first element in the array
* This is why indexing starts at 0: zero bytes offset from the first element
* This is all done by C using *pointer arithmetic*
* This is why we have to do our own bookkeeping!  




```text














```
