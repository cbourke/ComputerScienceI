
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

```text







```
