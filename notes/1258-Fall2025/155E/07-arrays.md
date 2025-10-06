
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
* Failure to free unused memory may result in a *memory leak*: more and more memory is allocated and never free'd until resources become scarce or not availalbe; slowing down the system.


```text














```
