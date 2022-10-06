
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

* More Pitfalls:
  * Careful: once you have freed memory, *you cannot access it*; attempt to do so will result in... a segmentation fault: the memory no longer belongs to you
  * Careful: only free something once!  If you free it a second time (without reallocating it), it is a "double free" error: a segmentation fault

```text









```
