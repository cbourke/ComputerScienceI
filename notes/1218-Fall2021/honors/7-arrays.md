
# CSCE 155H - Computer Science I - Honors
## Arrays & Collections
### Fall 2021


* It is rare to only deal with 1 number of 1 character, or 1 piece of data
* Collections of data are used to store multiple instances of those things
* In C and Java, we use *arrays* to store collections of *similar* things (things of the same type)
* In general:
  * Arrays have a single name (identifier)
  * You can access individual elements using an *index*
  * The first element is at index 0 (0-indexing)
  * The second is at index 1, etc.
  * The last (assuming it has `n` elements) is at index `n-1`
  * Indexing is done via square bracket syntax: `arr[0]`, or `arr[n-1]` or in general `arr[i]` (the ith element)

## Arrays in C

### Static Arrays

* Static arrays in C are arrays that are allocated on the stack
* Syntax:

```c
int arr[5];

for(int i=0; i<5; i++) {
  arr[i] = (i+1);
}
```

* Since static arrays are allocated on the stack, they exist inside stack frames, those stack frames are destroyed when the function returns
* Also: the stack size is *very limited*
* Remember: the stack space is small (10MB, `ulimit -a`), allocating even moderately large arrays will result in a stack overflow
* In Java: static arrays are not even possible

## Dynamic Arrays

* Dynamic arrays are allocated on the *heap*
* The heap is a much "larger" but "less organized" chunk of memory
* In C: you allocate memory on the heap by asking the operating system for a chunk of memory
* You ask for a chunk of memory using the **m**emory **alloc**ation function:
`void * malloc(size_t n)`
  * `void *` is a generic void pointer that can point to any raw memory address
  * A void pointer can point to any type of data!
  * If `malloc` returned a *specific* type of pointer, we would need 50 different versions of malloc: `mallocForIntegers`, `mallocForDoubles`, etc.
  * `size_t` can simply be thought of as an integer representing the *number of bytes* you are requesting
  * You can use the `sizeof()` macro to determine how many bytes each type takes
  * Ex: `sizeof(int)`, `sizeof(double)`
  * Upon success, `malloc` will return a valid pointer to a memory location that you can start using
  * Upon failure: `malloc` returns `NULL`
  * When you receive the pointer, you should cast it to whatever type of pointer you want to use: `(int *)` if it is an integer array, `(double *)` if it is a double array, etc.
* By default, no default values are defined in C, it *could* be zeros, it could be garbage, you should initialize the array properly

## Dynamic arrays in Java

* Java doesn't have `malloc`, instead you use the `new` keyword
* Example:

```java

int arr[] = new int[10];
double numbers[] = new double[20];
arr[0] = 42;
arr[9] = 101;
```

## Bookkeeping

* C has *manual memory management*: it falls to ***you*** the programmer to:
  * keep track of the size of an array you
  create
  * Pass that size to any function that you also pass the array to
  * Ensure that no illegal/undefined access occurs
  * You need to make sure you "clean up" the memory when you are done with it: you need to give it back to the operating system
  * To "give it back" you use the `free(arr);` function
  * Once freed, that memory no longer belongs to you; attempts to access it are *undefined* behavior
  * Attempts to free memory that doesn't belong to you are also undefined behavior
  * Failure to clean up memory after you are done using it may result in a *memory leak*
  * In C you need to be good stewards of your resources

### Java

* Java has no manual memory management: it is all taken care of by the Java *garbage collector*
  * Once an array or object is no longer in scope (no piece of code still has a reference to it), it is eligible for garbage collection
  * At certain increments, the JVM will reclaim memory automatically
  * You don't need to worry about a thing (mostly)!
  * No bookkeeping: you don't need to keep track of the size of arrays, it is available in `arr.length`
  * Arrays in Java suck, don't use them!

## Java Collections

* In Java, regular old arrays are terrible
* There are much better "dynamic collection data structures"

### Lists

* `List`s are ordered collections that use 0-indexing BUT
  * they grow and shrink dynamically and automatically as you put stuff and take stuff out!



```






```
