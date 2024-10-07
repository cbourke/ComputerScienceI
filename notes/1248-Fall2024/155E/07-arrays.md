
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

* ONce you have free'd memory it is NOT yours, you should *not* attempt to use it...
  * It may have been given away already!
  * Attempts to access free'd memory will result in *undefined behavior*
  * May result in seg faults
* You can only free memory once...
  * "Double Free" may cause a segfault...
```text










```
