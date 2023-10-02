
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

```text







```
