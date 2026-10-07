
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

```text














```
