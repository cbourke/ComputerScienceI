
# CSCE 155E - Computer Science I
## Arrays
### Fall 2023

* It is rare to only deal with 1 number of 1 character, or 1 piece of data
* Collections of data are used to store multiple instances of those things
* In C data is stored in arrays.  Arrays are collections of *similar* types of data
* In general:
  * Arrays have a single name (identifier)
  * To access individual elements in an array you use an *index*
  * An index is a number ranging from 0 up to $n-1$ where $n$ is the number of elements in the array
  * This is referred to as zero-indexing
  * Example: suppose we have an array called `arr` with $n$ elements
    * The first element is at `arr[0]`
    * The second is at `arr[1]`
    * The last is at `arr[n-1]`

## Arrays in C:

### Static Arrays

* Static arrays in C are allocated on the stack
* They exist in a single stack frame
* There is no default value defined for uninitialized array values (garbage, deadbeef, etc.)
* You can iterate over elements in an array using an "idiomatic" for loop


```c

    //create an array that can hold 10 integers:
    int arr[10];

    //what's stored in arr as of right now?
    for(int i=0; i<10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    //set each value...
    for(int i=0; i<10; i++) {
        arr[i] = (i+1);
    }

    for(int i=0; i<10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
```

* Accessing invalid indices may lead to:
  * Garbage results
  * Segmentation faults
  * Undefined Behavior

* Static arrays are extremely limited
* They are allocated on the stack which is limited to (say) 8MB, 4MB, kilobytes
* You cannot/should not abuse the stack space to store data (even moderately large amounts)
* Instead, you need to create *dynamic arrays*

## Dynamic Arrays

* Dynamic arrays are allocated on the *heap* memory space instead of the stack
  * The "heap" is a much less organized memory space, but
  * It is much larger!  Only limited by the actual computing hardware (memory, harddrive, etc.)
  * It is generally less efficient
* How do you allocate memory on the heap?
* You ask the operating system for a "chunk" of memory
* To do this, you use the function `malloc()`: **m**emory **alloc**ation
* Signature: `void * malloc(size_t n)`
  * `size_t` can be treated as an integer
  * You are asking `malloc()` for `n` bytes of memory
  * Generally you need to compute the size of memory you need
  * To do that you can use `sizeof()` along with a variable
  * The `malloc()` function returns a *generic void pointer*
  * A void pointer points to a raw memory location (not necessarily one that contains an `int` or a `double`, etc.)
  * A void pointer can point to *any* type of memory location
  * Generally you *type cast* it as the type of pointer you want
  * Upon failure `malloc()` will return a `NULL` pointer

```c

    //allocate enough space for 1000 integers:
    int n = 8000000000;
    int *arr = (int *) malloc(sizeof(int) * n);
    printf("n = %d\n", n);
    //works upto this point, but only because the "allocation" failed...
    //you can check for invalid allocations because malloc will return NULL
    if(arr == NULL) {
        printf("allocation failed, not much we can do...\n");
        exit(1);
    }


    arr[0] = 42;
    arr[n-1] = 101;

    printf("first, last: %d, %d\n", arr[0], arr[n-1]);

    //allocate enough memory for 2000 doubles:
    int m = 2000;
    double *brr = (double *) malloc(sizeof(double) * m);

```

* Similar functions: `calloc()`, `realloc()` for similar behavior
* Once you have successfully allocated memory, you can use it like any other array using square brackets and indices
* Same problems exist if you try to access memory outside the bounds of you array: undefined behavior, seg faults, etc.

## Memory Management

* Once you allocate a chunk of dynamic memory, you can use it for however long you want
* Once you are done with it, you need to clean up after yourself
* You *should* give it back, *deallocate* the memory once you are done using it so that other processes (or your own program) can use the memory
* If you fail to do so you may have a "memory leak"
* eventually you will either run out of memory or the system becomes slow and non-responsive
* To *de*allocate memory you use the `free()` function to free the memory up (give it back to the OS)
* Example:

```c
int n = 1000;
double *arr = (double *) malloc( sizeof(double) * n );

//TODO: do something with arr

//NOw we are done with it, so free it:
free(arr);

```

## Pitfalls:
* Once you have free'd the memory, you **cannot** still use it!
  * It may have been given away already!
  * Attempts to access free'd memory will result in *undefined behavior*
  * May result in seg faults
* You should not attempt to free memory more than once!
  * May result in seg faults
* YOu should not free up memory that is not dynamically allocated
  * Example: do *NOT* attempt to free a static array
* You can make no assumption about what is stored in an uninitialized array, it could be zeros, it could be garbage, etc.
* Not freeing memory leads to memory leaks

## Arrays and Functions

* YOU can pass arrays to functions just as you would any other pointer variable
* HOWEVER: you need to do your own "bookkeeping"
  * Any time you pass an array to a function, you need to tell the function how big the array is!
  * There is NO, ABSOLUTELY NO, way to tell how big a dynamically allocated array is in C!
* Careful: because arrays are passed by reference, the functions *can make changes to them!*
  * You can prevent this by making the array *read only*
  * To do this you can use the `const` keyword
* You can also write functions that *return* new arrays
   * They MUST be dynamically allocated arrays
   * Be careful: who "owns" memory?
* If a function returns memory, it does NOT own it
* If a function receives memory, it DOES own it and is responsible for it!
* Generally: ALWAYS free up memory when you are done with it
  * However, it is sometimes acceptable to ignore cleanup in the `main()` function at the end
* If a function creates memory *temporarily* and does not return it, that function is responsible for cleaning it up!
* Who is responsible for managing memory? You are!

## Exercise

* Write a function that takes an integer array and returns a *new* array but only containing the positive values in the array
* Write a function that creates a *copy* of a given array
  * "Shallow" copy: a reference copy
  * "Deep" copy: a completely different and unique copy


```text












```
