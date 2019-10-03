
# CSCE 155E - Computer Science I
## Arrays
### Fall 2019

* It is really rare that you only deal with say one variable or one piece of data
* You usually want to operate on a *collection* of pieces of data
* In C, collections of similar pieces of data can be stored in *arrays*
  * Arrays are a collection of variables of the same type
  * Arrays have a single identifier (name)
  * Elements in an array can be accessed using an *index*: the first element is at index 0, the second is at index 1, etc.  
  * If there are $n$ elements in an array, the last one is at index $n - 1$
  * Indexing is achieved using square brackets
  
## Static Arrays

* Static arrays are arrays of a fixed size that are allocated on top of the program stack
* Syntax

```c
//create an array that can hold 10 integers:
int arr[10];

//create an array that can hold 20 double values:
double numbers[20];
```

* Observation: just like other uninitialized variables, the contents of an array have no default values
* Demonstration
* Once you have an array, you can set individual values using an index and the normal assignment operator

```c
arr[0] = 42;
arr[1] = -5;
arr[2] = 3.14; //arr[2] has a value of 3

//set the last value to 102:
arr[9] = 102;

//what happens here?:
arr[10] = 5;
arr[-1] = 6;
```

* Accessing elements outside of an array is *undefined behavior*
  * MAY be a seg fault
  * MAY simply screw up (corrupting your own) your own memory
  * It MAY not result in any bad consequences

## Convenience Syntax

* You can initialize a static array using convenient syntax:

```c
int n = 7;
int primes[] = {2, 3, 5, 7, 11, 13, 17};
```

* In general, there is no way to determine the size of an array after it has been created in C
* In C, you *must* keep track of the size of every array, this is known as "memory management"
* It is *your* responsibility to keep track of the size of every array
* Consequence: if you pass an array to a function, you also need to *pass in an integer that represents the size of the array*
* This is also known as "bookkeeping": keeping track of the size of an array in an `int` variable
* Bookkeeping is necessary in order to iterate over an array
* Example:

```c

  int n = 100;
  int arr[100];

  for(int i=0; i<n; i++) {
    arr[i] = 0;
  }

  for(int i=0; i<n; i++) {
    printf("%d\n", arr[i]);
  }
```

## VLAs: Variable Length Arrays

* You *can* set the size of an array using a variable:
```c
int n = 100;
int arr[n]; //of size 100
```

* But in general, you *shouldn't* do this
* In fact, you should not use static arrays in general unless they are very small
* You end up abusing the stack space (which is 
  relatively small)
* Example: attempt to create a "moderately" large array on the stack
  
## Dynamic Arrays

* Alternative: use dynamic arrays
* Dynamic arrays are arrays that are allocated on the program "heap" instead of the program stack
* The heap is a larger, but less "well organized" chunk of memory
* However, the heap is *much larger*
* In general, you "ask" the operating system for some chunk of memory on the heap (of some specified) size, and it either accommodates you or refuses
* The way that you "ask" for memory is to ask for a memory allocation 
* Using the function `malloc`
* `malloc` takes only one argument: the number of bytes you want to allocate
* `malloc` returns a *pointer* to the memory location at which the memory was allocated (IF successful)
* `malloc` will return `NULL` if it was unsuccessful
* More details:
  * `malloc` actually returns a "generic `void` pointer"
  * Actual signature: `void * malloc(size_t size);`
  * This means that there not dozens of different `malloc` functions, there is only one that returns "a chunk" of memory
  * It is your responsibility to use this memory for whatever purpose you have: use it as an array of integer, or use it as an array of doubles
  * In general the way you do this is by type casting: you case the returned generic void pointer into the pointer type you want

```c
int *a; //pointer to a integer
double *b; //pointer to a double
void *c; //generic pointer

int *arr = (int *) malloc(...);
double *numbers = (double *) malloc(...);

arr[0] = 42;
arr[1] = 102;
```

* After successful allocation, you can use an array from malloc like a static array using regular old indexing

* In general you don't hardcode the number of bytes you want to use with `malloc`
* Some systems an integer may be only 2 bytes, some it maybe 4, or 3 or 8, etc.
* You can use the "macro" `sizeof` to determine how many bytes a certain type takes on that particular system

```c
int n = 100;
int *arr = (int *) malloc(n * sizeof(int));

double *numbers = (double *) malloc(n * sizeof(double));

arr[0] = 42;
arr[n-1] = 102;

printf("%d\n", arr[0]);
printf("%d\n", arr[n-1]);
```

### Memory Management

* Once you allocate a chunk of dynamic memory and are done using it, you need to clean up after yourself
* Failure to clean up after yourself may result in a *memory leak* eventually leading to a program failure when you've run out of memory 
* To clean up memory you free it up using the `free` function: simply pass in the pointer to the memory you want to *deallocate*

```c
//free up the integer array:
free(arr);
//free up the numbers array:
free(numbers);
```

* attempts to access the contents of freed memory are *undefined behavior*
* attempts to free already freed memory ("double freeing") are also undefined behavior
* freeing memory that does not belong to you is undefined behavior
* 


  