
# CSCE 155E - Computer Science I
## Arrays
### Fall 2021

* It is really rare that you only deal with say one variable or one piece of data
* You usually want to process or operate on a *collection* of pieces of data
* In C, collections of similar pieces of data can be stored *arrays*
  * Arrays are a collection of variables of the same type
  * Arrays have a single identifier (name)
  * Elements inside an array can be accessed using an *index*: a number that identifies its position in the array
  * The first element is at index `0`
  * THe second element is at index `1`
  * If there are $n$ elements in an array, the last one is at index `n-1`
  * You use an index using the square brackets: `arr[0]` or `arr[i]`

## Static Arrays

* Static arrays are arrays of a fixed size that are allocated on the program's stack
* Styntax:

```c
//create an array that holds 10 integers:
int arr[10];

//create an array that can hold 20 doubles:

double brr[20];

```

Observations:
* Just as with uninitialized variables, the contents of an array are undefined
* Generally it could be zeros, it could be random garbage
* Once you have an array though, you can start setting the values using indexing and the normal assignment operator

```c
arr[0] = 42;
arr[1] = -5;
arr[2] = 3.5; //truncation
arr[9] = 42;

//invalid/undefined behavior:
arr[10] = 101;
arr[-10] = 102;
```

* Accessing elements outside an array is *undefined behavior*
  * MAY be a segmentation fault
  * MAY be a stack smashing
  * MAY simply corrupt your own memory
  * It may or may not result in bad consequences, but it is just not good!

## More Syntax

* You can declare an initialize a static array in one line:

```c
//you can create and initialize in one line:
int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

//but you don't have to specify the size:
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

//BUT, it then falls to you to keep track of the size!
```

## Bookkeeping

* In general in C, there is *absolutely no way* to determine the size of an array
* It falls to you, the programmer to *always* keep track of the size of an array
* To solve this, you simply keep track of the size of an array using another variable, typically `n`

```c


  int n = 10;
  int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  int sum = 0;

  //sum up the first 10 primes
  for(int i=0; i<n; i++) {
    sum += primes[i];
  }
  printf("The sum of the first 10 primes is %d\n", sum);
```

## Dynamic Arrays

* Static arrays are very limited
  * Since they are allocated on the stack, you don't have a lot of memory to work with
  * Since they are allocated on the stack, you can *never* return an array from a function!
* Alternative: dynamic arrays
* Dynamic arrays are arrays whose memory is allocated on the program "heap" instead of the program stack
* THe heap is a much larger but less organized chunk of memory
* In general, we ask the operating system for more memory; it either gives us a chunk of memory or an error
* You ask the OS for memory using the **m**emory **alloc**ation function: `malloc`
* Signature:
`void * malloc(size_t size);`
* Think of `size_t` as an integer: it represents the number of bytes you are asking for
* You can use the `sizeof()` macro to determine how many bytes each type of variable takes
  * Ex: `sizeof(int)` gives you the number of bytes that an integer takes
  * Ex: `sizeof(double)` gives you the number of bytes that a `double` takes
* `void *`:
  * `int *` is a pointer to an integer
  * `double *` is a pointer to a `double`
  * `void *` is a pointer to *anything*: it is a "generic void pointer"
  * It is just a raw memory address that can hold *any* data
* Having a single *generic* `malloc` function means we only have to worry about 1 function; we don't need multiple functions: `mallocForInt, mallocForDouble`

```c
int n = 10000000;
//dynamically allocate an array of integers:
int *arr = (int *) malloc(n * sizeof(int));

```

* More details:
  * If `malloc` fails for any reason it returns `NULL`
  * After allocation, you can treat the array as you would a static array using square brackets using indices `0` thru `n-1`
  * YOU STILL HAVE TO KEEP TRACK of the size of the array

## Memory Management

* Once you allocate a chunk of dynamic memory, you can use it for however long you want
* Once you are done with it, you need to clean it up
* You *should* give it back to the OS so it can be reused
* To give it back, you use the `free()` function: it frees up the memory that you allocated so it can be used again by other programs or reused/reallocated for your program
* 

```text







```
