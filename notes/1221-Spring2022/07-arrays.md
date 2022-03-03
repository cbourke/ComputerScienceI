
# Computer Science I
## ECEN 1940 - Spring 2022
### Arrays

* It is rare that you only deal with say one variable or one piece of data
* You usually want to process or operate on a *collection* of pieces of data
* In C, collections of similar pieces of data can be stored *arrays*
  * Arrays are collections of variables of the same type
  * Arrays have a single identifier (name)
  * Elements inside an array can be accessed using an *index*: this is a number (an integer) that identifies its position in the array
  * The first element is at index `0`
  * The second element is at index `1`
  * IF there are $n$ elements in an array, the last one is at index `n-1`
  * You can use an index using the square brackets:
    * `arr[0]` the first element
    * `arr[1]` is the second
    * `arr[i]`

## Static Arrays

* Static arrays are arrays of a fixed size that are allocated on a program's stack
* Syntax:

```c
//create an array that holds 10 integers:
int arr[10];

//create an array of 20 doubles:
double brr[20];

```

* Observations:
  * Just as with uninitialized variables, the default content of an array is undefined
  * Generally it could be zero, but it could be random garbage (`0xDEADBEEF`)
  * Once you have an array, you can access its elements using indices 0 thru n-1

* Pitfalls:
  * What happens when you access elements outside of your array?
  * Ex: `arr[-1] = 42;`
  * Ex: `arr[10] = 100;`
  * MAY be a segmentation fault
  * MAY be a stack smashing
  * MAY simply corrupt your own memory
  * It may or may not result in bad consequences, but it is just not good!

## More Syntax

* YOu can immediately initialize the contents of a static array using the curly bracket syntax:

```c
int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

//but you don't have to specify the size:
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

//BUT, it then falls to you to keep track of the size!
```

## Bookkeeping

* In C, bookkeeping means manually tracking how bit an array is: in general there is no interoperable way of determining the size of an array after it has been created
* You *always* should keep track of the size of an array in a variable (integer)
* When you pass an array to a function, you also need to pass the size of the array
* If you return an array from a function, the calling function needs a way to determine how big it is
* Typically such variables are `n` or `sizeOfArr`, `numberOfElements`

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

## Dynamcic Arrays

* Static array are very limited
  * Since they are allocated on the stack, you dno't have a lot of memory to work with
* Solution: to allocate more memory on the *heap*
* The heap is less organized, but much larger!
* Dynamic arrays are allocated *dynamically* on the heap instead of the program stack
* In general, we ask the operating system for more memory; it either gives us a chunk of memory or an error
* You ask the OS for memory using the **m**emory **alloc**ation function: `malloc`
* Signature:
`void * malloc(size_t size)`
  * Think of `size_t` as an integer: it corresponds to the number of *bytes* you want to allocate
  * How many bytes do you want?
  * Generally you can use the `sizeof()` macro to determine how many bytes a specific type takes
  * Ex: `sizeof(int)` (4), `sizeof(double)` (8)
* The return type is a "generic void pointer"
  * `int *` is a pointer to an integer
  * `double *` is a pointer to a double
  * `void *` is a pointer to a raw memory address
  * Generally you *should* cast the pointer to the appropriate type
* `malloc()` only returns on generic void pointer
  * If it didn't, what would it return?
  * With one version of malloc, we don't have to create new versions for each new type

### More details

* If `malloc` fails for any reason it returns `NULL`
* After allocation, you can treat the array like a regular old array, indexing from 0 up to `n-1`
* Attempts to access memory outside that array are *undefined behavior*
  * It *may* result in a seg fault
  * It *may* do nothing
  * It *may* simply corrupt your own memory
* You still need to keep track of the size of an array; in general there is no way to determine the size of an array: certain *never* for a dynamic array
  * Just keep track of the size of an array in a variable (easiest)
* Other functions:
  * `calloc`
  * `realloc`
  * RTFM = Read The (freakin') Manual

## Memory Management

* Once you allocate a chunk of dynamic memory, you can use it however long you want in your program
* Once you are done with it you should clean it up
* You can *free* up memory (give it back to the heap or to the OS) using the `free()` function
* You simply pass in the pointer to the dynamically allocated memory
* Don't Do What Donny Don't Does:
  * Don't "double" free an array (you cannot free something twice)
  * Don't free your stack
  * Don't free `NULL` or invalid variables
  * Don't try to use an array after it has been free'd
* Always remember to free your memory when you are done with it
* Failure to do so will lead to "memory leaks"

### Who "owns" memory?

* Which function or functions are responsible for cleaning up the memory?
* Whatever piece of code "own" the memory is responsible for also cleaning it up
* If a function only allocates memory for temporary use and does not return it, it is responsible: it owns it and it *must* free it
* If the function returns the array, the *calling function* owns it

```c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>


int doSomethingComplicated() {
    int n = 1000000;
    int *arr = (int *) malloc(n * sizeof(int));
    //TODO: do something with those integers...
    //doSomethignComplicated is responsible...
    free(arr);
    return 0;

}

/**
 * This function creates a new dynamic integer array of the
 * given size and initializes each value to 1.
 */
int *getOnesArray(int n) {
    int *result = (int *) malloc(n * sizeof(int));
    for(int i=0; i<n; i++) {
        result[i] = 1;
    }
    //bad: free(result);
    return result;
}

int main(int argc, char **argv) {

    doSomethingComplicated();
    int *ones = getOnesArray(1000000);
    printf("middle = %d\n", ones[999999]);
    free(ones);

    return 0;
}
```

## Using arrays with functions

* Passing an array to a function
  * All arrays are actually memory addresses
  * Thus all arrays are simply pointers
  * To pass an array to a function, you pass a pointer
  * In other words you pass by reference
  * In addition, you *must* pass the size of an array to the function
* Example: design a function to compute the sum of elements in an integer array

```text







```
