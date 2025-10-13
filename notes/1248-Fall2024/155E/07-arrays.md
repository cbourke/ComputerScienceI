
# CSCE 155E - Computer Science I
## Arrays
### Fall 2024

* It is rare to only deal with 1 number of 1 character, or 1 piece of data
* Collections of data are used to store multiple instances of those things
* In C data is stored in arrays.  Arrays are collections of *similar* types of data
* Arrays only contain one type of data: `int`, `double`
* In general:
  * Arrays have a single name (identifier)
  * To access individual *elements* you use an *index* (an integer)
  * An index is a number ranging from 0 up to $n-1$ if the array contains $n$ elements
  * IE: it is 0-indexed
  * Example: suppose we have an integer array called `arr` with $n$ elements
    * The first element is at `arr[0]`
    * The second element is at `arr[1]`
    * the last element is at `arr[n-1]`

## Arrays in C:

### Static Arrays

* Static arrays in C are allocated on the *stack*
* They exist in a single stack frame
* There is no default value defined for uninitialized array values (garbage, deadbeef, etc.)
* You iterate over elements in an array using an "idiomatic" for-loop

```c

  //create an array that holds 10 integers:
  int arr[10];

  //you can set/get elements:
  arr[0] = 42;
  arr[9] = 101;

  //what is stored in arr[1]? Who knows: 0? 1? garbage? 0XDEADBEEF
  for(int i=0; i<10; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  for(int i=0; i<10; i++) {
    arr[i] = i * 10;
  }

  for(int i=0; i<10; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

```

* going outside the bounds of the array has various conseqeuences.
  * Stack Smashing event: you've destroyed/corrupted your own memory
  * Or you could get away with it entirely!
  * Undefined behavior

* Static arrays are extremely limited
* They are limited to how big your stack memory space is!
* Typically stacks are limited to 4 or 8MB or even kilobytes
* You cannot typically hold "large" or even "moderate" amounts of data on the stack
* What you need is a *dynamic* array

## Dynamic Arrays

* Dynamic arrays are allocated on the *heap* memory space instead of the stack
  * Heaps are the same memory but have fewer limitations
  * But: whereas stack memory is "efficient", heap memory is less efficient and less organized
* How do you allocate memory on the heap?
* You do so by asking (requesting) the operating system for a "chunk" of memory
* To do this, you use the function `malloc()`: **m**emory **alloc**ation
* Signature: `void * malloc(size_t n)`
  * `size_t` can be treated as an inteer
  * The input is the *number of bytes you want to request*
  * Generally you need to compute the number of bytes that you need (malloc is not going to do the math for you)
  * To do that you can use `sizeof` to determine how many bytes each type takes:
  `sizeof(int), sizeof(double), sizeof(char)`
  * `malloc()` returns a `void *` pointer: this is a generic void pointer
  * A void pointer can point to *anything*: it is a raw memory address
  * we'll generally *cast* the pointer to the type we want: `(int *)`
  * Example

```c

  int n = 1000000000;
  int *arr = (int *) malloc( 1000 *n * sizeof(int) );

  //if malloc fails, it returns NULL
  if(arr == NULL) {
    printf("malloc failed to allocate that much memory\n");
    exit(1);
  }

  for(int i=0; i<n; i++) {
    arr[i] = 0;
  }

```

* Similar functions: `calloc()`, `realloc()` for similar behavior (`calloc` allocate the memory and zeros out all the bytes), realloc reallocates: expand or contract memorry if it is able to
* Once you have successfully allocated memory, you can use it like any other array using square brackets and indices
* Same problems exist if you try to access memory that doesn't belong to you: undefined behavior, seg faults, etc.
* If malloc fails to allocate the memory, `NULL` is returned

## Memory Management

* Once you allocate a chunk of dynamic memory, you can use it for however long you want
* Once you are done with it, you need to clean up after yourself
* You *should*  give it back to the operating system so it can reuse
* To give it back to the OS: you use `free`
* Failure to free unused memory may lead to a *memory leak*: more and more memory is allocated and never free'd until resources become scarce or not available: slows things down in the system

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
  * May result in seg faults
* You can only free memory once...
  * "Double Free" may cause a segfault...
* There is ***NO*** way to determine the size of an array
  *  You need do your own bookkeeping
  * Ignore stackoverflow misinformation

## Arrays and Functions

* YOU can pass arrays to functions just as you would any other pointer variable
* When you pass an "array" to a function, you are passing a pointer to that array
* HOWEVER: you need to do your own "bookkeeping"
  * Any time you pass an array (pointer) to a function you need to tell the function how big it is (usually with an integer variable `n`)
  * There is NO, ABSOLUTELY NO, way to tell how big a dynamically allocated array is in C!
* Careful: because arrays are passed by reference, the functions *can make changes to
  * You can prevent this by making the array "read-only" using the `const` keyword
* You can also write functions that *return* new arrays
  * `malloc` does this
  * We can do it too, however they ***must*** be dynamic arrays
  * Be careful: who "owns" memory?  It depends
  * If you are done using the memory *inside* the function, the function is responsible for `free`ing it
  * If you are returning the memory (via a pointer) to the calling function, then the calling function is responsible for `free`ing it
* Generally: ALWAYS free up memory when you are done with it
  * However, it is sometimes acceptable to ignore cleanup in the `main()` function at the end

## Pointers & Indices

* How do arrays actually work...
* Arrays (names of arrays) are actually pointers that points to the *beginning* of a memory location that holds a bunch of elements in a contiguous manner
* Arrays are nothing more than the memory address of the first element in the array
* This is why indexing starts at 0: zero bytes offset from the first element
* This is also why we have to do our own bookkeeping

## Shallow vs Deep Copies

* A shallow copy is when two arrays share the same memory address
  * There is only ONE actual array in memory
  * Changes to one affect the other
* A deep copy is when you copy an array to another array so that they are *completely different arrays*
  * Changes to one do not affect the other
  * There are TWO actual arrays in TWO different memory locations

```c

  int n = 5;
  int *arr = (int *) malloc( sizeof(int) * n );
  for(int i=0; i<n; i++) {
      arr[i] = 10 * (i+1);
  }

  //shallow copy of a:
  int *b = arr;

  //b[0] = 42;

  for(int i=0; i<n; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
  }

  b = (int *) malloc( sizeof(int) * n );

  for(int i=0; i<n; i++) {
    //copy over elements...
    b[i] = arr[i];
  }

  b[0] = 42;
```

## Exercises

* Write a function that takes an array of integers and returns a new array containing only the positive values from the original array
  * Input: `{5, -1, 0, 3, 6, 9, 42, -7, 10, -1, 43, 2, 34, 3, 23, 4, 43}`
  * Output `{5, 3, 6, 9, 42, 10, 43, 2, 34, 3, 23, 4, 43}`

### Multidimensional Arrays

* A regular old array is a 1-D array (one dimensional)
* You can also have multidimensional arrays: 2D arrays, 3D arrays, 4D arrays, etc.
* Our focus: 2-D arrays
  * Rows and columns
  * There are *tables*
  * Spreadsheets (kinda)
  * Matrices
* In C a regular old array of integers is `int *arr`
* A 2-D array is `int **mat`
* Once you ahve a 2-D array, you specify the row and the column index: `table[0][0]` is the `0`-row (first row), `0`-column (first column)
* Suppose that there are `n` rows and `m` columns
  * THe bottom right most value is at `table[n-1][m-1]`
* The first index is the row, the second is the column (row-major form)
* How do we allocate memory for a 2-D array?


```c
int n = 3, m = 5;
//setup a row of n *pointers*
int **table = (int **) malloc( sizeof(int*) * n );
//setup each row:
for(int i=0; i<n; i++) {
  //setup the i-th row:
  table[i] = (int *) malloc( sizeof(int) * m);
}

for(int i=0; i<n; i++) {
  for(int j=0; j<m; j++) {
    table[i][j] = i * j;
  }
}

//memory leak: TODO fix

    for(int i=0; i<n; i++) {
        free(table[i]);
    }
    free(table);
```

```text














```
