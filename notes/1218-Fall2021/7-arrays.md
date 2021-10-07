
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
* You simply have to give the pointer to the `free()` function

```c
int *arr = (int *) malloc(n * sizeof(int));
//use the array...

//free up the memory:
free(arr)
```

* You must make sure you are *done* with the memory before freeing it: once freed, the memory is no longer yours
* Attempting to free something twice results in a "double free" error
* Being good stewards of your memory and doing good bookkeeping is known as "memory management"

### Who "owns" memory?

* If you allocate memory inside a function: does the function "own" the memory or not?
* Whatever piece of code "own" the memory is responsible for also cleaning it up
* If a function only allocates memory for temporary use and does not return it, it is responsible: it owns it and it *must* free it
* If the function returns the array, the *calling function* owns it

```c

#include <stdlib.h>
#include <stdio.h>

//TODO: document!
int sum(int *arr, int n) {

  int total = 0;
  for(int i=0; i<n; i++) {
    total += arr[i];
  }
  return total;
}

/**
 * This function creates a new dynamic array
 * of the given size n filled with 1s
 */
int * getOnesArray(int n) {
  if(n < 0) {
    return NULL;
  }
  //create the array of the given size:
  int *arr = (int *) malloc(n * sizeof(int));
  for(int i=0; i<n; i++) {
    arr[i] = 1;
  }
  //wrong: free(arr);
  return arr;
}

int main(int argc, char **argv) {

  int n = 10;
  int *arr = (int *) malloc(n * sizeof(int));
  for(int i=0; i<n; i++) {
    arr[i] = (i+1) * 10;
  }
  int total = sum(arr, n);
  printf("total = %d\n", total);
  for(int i=0; i<n; i++) {
    printf("%d\n", arr[i]);
  }
  //this is proper but not necessary in the main:
  free(arr);

  arr = getOnesArray(n);
  for(int i=0; i<n; i++) {
    printf("%d\n", arr[i]);
  }
  free(arr);

    return 0;

}
```

## Using arrays with functions

* Passing an array to a function
  * All arrays are actually memory addresses
  * Thus all arrays are simply pointers
  * To pass an array to a function, you pass a pointer
  * In other words you pass by reference
* Example: design a function to compute the sum of elements in an integer array

* Observations:
  * When you pass an array to a function, you also have to pass its size!
  * `int *` can be a SINGLE integer variable OR it can be an entire array of integer variables
  * The way that arrays actually work is that the array/pointer name (identifier) is simply pointing to the first element in the array  
* You can also return arrays from a function
    * The return type is simply a pointer
    * Careful: you cannot also directly return the size of the array!
  * Demonstration:
    * Write a function that creates a new array of integers all initialized to zeros
    * Write a function that *returns a new array* containing only the even integers of a given array
```c

/**
 * This function takes an array of integers
 * and returns a *new* array containing all of
 * the positive values in the array.
 */
int * getPositives(int *arr, int n, int *sizeOfResult) {

  //iterate through the array and find out how
  // many integers are positives...
  int numPos = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] > 0) {
      numPos++;
    }
  }
  int *result = (int *) malloc(numPos * sizeof(int));
  int indexOfResult = 0;
  for(int i=0; i<n; i++) {
    if(arr[i] > 0) {
      //put the ith value into result...
      result[indexOfResult] = arr[i];
      //increment indexOfResult
      indexOfResult++;
    }
  }
  *sizeOfResult = numPos;
  return result;
}
```

## Other Issues

### Multidimensional Arrays

* A regular old array is a 1-D array
* You can have a 2-D array with both *rows* and *columns*:
  * IE Matrices or
  * tables
* 3D, 4D, etc. arrays are possible, but not recommended
* In C a regular old array is `int *arr`
* Consequently to have a 2-D array, you use `int **mat`
* To index a 2-D array, you provide both the row number and the column number: `arr[3][4]` is the 4th row, 5th column

```c

int main() {

  //create a 3 x 5 table/matrix/2D array
  int n = 3;
  int m = 5;
  //create an array of POINTERS to point to each row
  int **table = (int **) malloc(n * sizeof(int *));  
  for(int i=0; i<n; i++) {
    table[i] = (int *) malloc(m * sizeof(int));
  }

  //set values in the table:
  int v = 10;
  for(int i=0; i<n; i++) { //for each row...
    for(int j=0; j<m; j++) {
      table[i][j] = v;
      v += 10;
    }
  }  

  return 0;
}
```

## Protecting Arrays

* If you pass an array to a function, that function can *change the contents*
* Often we will want to *prevent* changes to an array
* You can use the `const` keyword to indicate that you will not make changes
* If you use `const` and *do* make changes, the compiler will issue an error!

## Freeing 2-D Arrays

* You need to make sure you clean up each row before deleting the array of pointers or you will have a memory leak

```c


  int n = 3;
  int m = 4;
  int **table = (int **) malloc(sizeof(int *) * n);
  for(int i=0; i<n; i++) {
    table[i] = (int *) malloc(sizeof(int) * m);
    for(int j=0; j<m; j++) {
      table[i][j] = (i+j+1) * 10;
    }
  }

  for(int i=0; i<n; i++) {
    free(table[i]);
  }  
  free(table);
```

## Shallow vs Deep Copies

* A *shallow* copy of an array is when two references reference the same memory location
* Changes to one reference (pointer/array) will affect the other

```c


int n = 5;
int *a = (int *) malloc(sizeof(int) * n);
for(int i=0; i<n; i++) {
  a[i] = (i+1) * 10;
}
//shallow copy:
int *b = a;
a[0] = 42;
printf("b[0] = %d\n", b[0]);
```
* a *deep* copy of an array is a distinct array (different memory address) but with the same values

```c
int * deepCopy(int *arr, int n) {
  if(arr == NULL || n < 0) {
    return NULL;
  }

  int *c = (int *) malloc(sizeof(int) * n);
  if(c == NULL) {
    return NULL;
  }
  for(int i=0; i<n; i++) {
    c[i] = arr[i];
  }
  return c;
}
```

```text











```
