
# Computer Science I
## CSCE 155E - Fall 2022
### Arrays

* It is rare that you only deal with say one variable or one piece of data
* You want to be able to process a *collection* of pieces of data
* In C, collections of _similar_ pieces of data are stored in *arrays*
  * Arrays are ordered collections of variables of the same type, `int` or `double`, etc.
  * Arrays have a name (identifier)
  * Elements in an array can be accessed using an *index*
  * Indices start at `0` and are all contiguous integers
  * If you have an array of integers named `arr`:
    * The first element is at `arr[0]`
    * The second is at `arr[1]`
    * The third is at `arr[2]`
    * etc.
    * YOU can index using a variable: `arr[i]` is the i-th element
    * THe last element (assuming there are $n$ elements) is at `arr[n-1]`

## Static Arrays

* Static arrays are arrays that are of a fixed size and allocated on the program stack

```c
int arr[5];
arr[0] = 42;
//careful: C has no default values for elements in an array!
// could be zero, could be garbage
arr[1] = 101;
arr[4] = 129;

//you can iterate over a the elements in an array
//using an idiomatic for loop:
for(int i=0; i<5; i++) {
    printf("arr[%d] = %d\n", i, arr[i]);
}
```

* Observations
  * There is no default value for array elements: it coudl be zero, it could be garbage, or deadbeef, etc.
  * Static arrays are allocated on the call stack which is *limited* in size (say ex: 8MB), you cannot create even moderately large arrays on the system stack, you need a different solution...
  * Attempts to access invalid indices are *undefined behavior*
  * Ex: `arr[-1]` or `arr[5]` (if size is 5)

## Dynamic Arrays

* To store even moderately large data, you need dynamic arrays
* Dynamic arrays are arrays whose memory is allocated on the *heap*
* In general: the heap is less organized but *much* larger than a stack
* For all types of arrays, but especially dynamic arrays, you need to do your own bookkeeping:
  * To create an array, you need to allocate new memory to store it (by making a request to the operating system)
  * WHen you are done using that memory, you need to give it back or "free" it up
  * This is known as memory management

### How do we do this?

* To alloate memory you use the ***m***emory ***alloc***ation function: `malloc`
* It has the following signature:
`void * malloc(size_t size)`
  * `size_t` can be treated as an integer
  * You basically ask `malloc` for a certain number of bytes indicated by `size`
  * To do this properly: use `sizeof()` and an integer to keep track of the number of elements in you array
  * *always* keep track of the size of an array in an integer variable, `n`
  * You can get how many bytes each type takes using `sizeof()`
    * `sizeof(int)`
    * `sizeof(double)`
    * `sizeof(char)`
  * `malloc` returns a "generic void pointer": `void *`
    * `int *` is a pointer to a memory location that holds an `int`
    * `double *` is pointer that points to a memory location that holds a `double`
    * `void *` is a pointer that can point to *anything*: it is pointing to a raw memory location that can hold anything, `int, double`, etc.
    * To deal with this, we typically typecast the returned point to the type of variable we want to store


```text





```
