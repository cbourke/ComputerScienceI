
# CSCE 155H - Computer Science I - Honors
## Arrays & Collections
### Fall 2025

* Almost never deal with just one piece of data
* Instead you deal with *collections* of data
* Both C and Java support old-school *arrays* collections of *similar* things (things of the same type: `int`, `double`, etc.) all stored *contiguously*
* In general:
  * Arrays have a single *identifier* (variable name)
  * You can access individual *elements* in an array using an *index*
  * The first element is always at index `0`
  * YOu use square brackets to access each element
  * ex: first is at `arr[0]`, second: `arr[1]`, last (assuming there are `n` elements) is at `arr[n-1]`

## Arrays in C

### Static Arrays

* "static" means that they have a fixed size and are created and stored on the program's *stack*
* Static arrays are **extremely limited**
* Since static arrays are allocated on the stack, they exist inside stack frames, those stack frames are destroyed when the function returns
* Stack space is *extremely limited*: it could be 4MB, 8MB or even (embedded systems) limited to kilobytes
* You cannot fit even a "small" array on the stack
* In Java: static arrays are NOT EVEN POSSIBLE!

```c

    //static array of integers of size 10:
    int arr[10];
    //set the first and last values:
    arr[0] = 42;
    arr[9] = 123;
    //it is best to keep track of the size of an array:
    int n = 10;

    //an array to hold 20 doubles:
    double brr[20];

    //what values are stored in arr at this point?
    //iterate over arr to find out:
    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    for(int i=0; i<n; i++) {
        arr[i] = (i + 1) * 10;
    }

    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }


```

## Dynamic Arrays

* Dynamic arrays are allocated not on the stack but on the *heap*
  * Much larger
  * Less organized
  * Less efficient (in some ways)
* In C: you allocate memory on the heap by asking the OS = Operating System for a "chunk" of memory (however big you need)
* For example:
  * Want to store 10 million integers
  * We would ask for 40 million bytes (4 bytes each `int`)
* You use the function called `malloc` = *m*emory *alloc*ation
* Malloc:
  * Signature: `void * malloc(size_t n)`
  * You can treat `size_t` as an integer (you are asking for `n` bytes)
  * The return value is a "generic void pointer"
  * A generic void pointer is a raw memory address, it can point to *any* type of data
  * The returned memory can be used for whatever you want it to be
  * Generally when we receive the pointer, we'll *cast* it as the type that we intend to use it as

## Java

* No pointers in Java, no static arrays
* All arrays are allocated on the heap
* Demo:

```java

		//no static arrays in Java
		int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

		//dynamic arrays use the *new* keyword:
		int arr[] = new int[10];
		//in Java there is a well-defined default value of: zero!

		arr[0] = 42;
		arr[arr.length-1] = 123;

		for(int i=0; i<arr.length; i++) {
			System.out.printf("arr[%d] = %d\n", i, arr[i]);
		}

		System.out.println(Arrays.toString(arr));

		//neato: enhanced for loop or "for each loop"
		for(int x : arr) {
			System.out.println(x);
		}

```

* In Java, we're immediately going to abandon arrays

## Java

* Java has arrays
* In Java: no memory management (no `malloc`, no `free`); instead you use the keyword `new`
* You don't need to keep track of the size of an array; `arr.length`
* Most of the syntax is the same
* There are default values: zeros
* Java has neat "enhanced for loops"

### Better Java

* Java has arrays.  They Suck.  Do not use them...
* Once created, they cannot change: they don't grow or shrink
* Instead in Java it is preferred to use *dynamic collections*: lists, sets, maps
* Lists use 0-indexing
* You can do basic CRUD = Create Retrieve Update Destroy
* Demo
```java

		//collections are what you want in Java
		List<Integer> numbers = new ArrayList<>();
		//add adds the element to the *end* of the list
		numbers.add(10);
		numbers.add(20);
		numbers.add(30);
		System.out.println(numbers);
		//add 42 at index 0:
		numbers.add(0, 42);
		System.out.println(numbers);
		numbers.add(2, 123);
		System.out.println(numbers);

		//remove stuff:
		numbers.remove(1);
		System.out.println(numbers);

		//retrieve:
		//get the first element:
		int first = numbers.get(0);
		System.out.println(first);

		numbers.set(1, 321);
		System.out.println(numbers);

		numbers.clear();
		System.out.println(numbers);

		//size of the list:
		int n = numbers.size();

		numbers.add(10);
		numbers.add(20);
		numbers.add(30);
		numbers.add(10);
		System.out.println(numbers);

		for(int i=0; i<numbers.size(); i++) {
			System.out.println(numbers.get(i));
		}

		for(int x : numbers) {
			System.out.println(x);
		}
```

* Sets: **unordered** collections of **unique** elements

```java

		Set<String> names = new HashSet<>();
		names.add("Chris");
		names.add("Craig");
		names.add("Nico");

		System.out.println(names);

		//no ordering means no indices
		//String name = names.get(0);
		//1. convert the set to a list:
		List<String> namesOrdered = new ArrayList<>(names);
		String name = namesOrdered.get(0);

		//2. better:
		for(String n : names) {
			System.out.println(n);
		}

		names.remove("Craig");
		System.out.println(names);
		names.add("Craig");
		System.out.println(names);
		names.add("Craig");
		System.out.println(names);

```

#### Maps

* Maps are a key-value pair mapping
* Keys map to values

```java

		Map<String, Integer> nameToNuid = new HashMap<>();
		nameToNuid.put("Chris", 35140602);
		nameToNuid.put("Nico", 12345678);
		nameToNuid.put("Craig", 87654321);
		nameToNuid.put("Michael", 87654321);
		System.out.println(nameToNuid);

		Integer myNuid = nameToNuid.get("Chris");
		System.out.println(myNuid);

		Integer aNuid = nameToNuid.get("Kyle");
		System.out.println(aNuid);
		//better:
		if(nameToNuid.containsKey("Kyle")) {
			System.out.println("It does");
		} else {
			System.out.println("It don't");
		}

		//iteration:
		for(String name : nameToNuid.keySet()) {
			Integer nuid = nameToNuid.get(name);
			System.out.println(name + " maps to " + nuid);
		}
		System.out.println(nameToNuid.values());

		//replace via a key:
		nameToNuid.put("Michael", 11111111);
		nameToNuid.remove("Chris");
		System.out.println(nameToNuid);

```

## Pitfalls with Arrays in C

* In C **you** are responsible for managing memory and indices
* What happens when you try to access an invalid index?
  * Could be: stack smashing event (you are screwing up your own memory in a non-recoverable way)
  * Could be: "undefined behavior"
  * Could be: segmentation fault
  * Java: `IndexOutOfBoundsException` is thrown
* What happens when you don't clean up after yourself?
  * You borrow memory using `malloc()` from the operating system
  * What happens when you don't give it back?
  * This is known as a *memory leak*
  * To prevent it, use `free()`
  * However, use it correctly
  * Only free once you are done using
* **You** are responsible for memory management

### Arrays & Functions

* When you pass an array to a function, *you also need to pass the size of the array*
* There is ZERO, ABSOLUTELY ZERO way to tell the size of a dynamic array
* You can pass an array to a function
  * You can use `const` to make it so the function cannot make changes
* You can return an array from a function
  * `malloc()` does it, so can we!

### Shallow vs Deep Copies

* A *shallow* copy is when two references (pointers) point to the same chunk of memory
  * Changes to one affect the other
  * There is only *one* thing in memory
* A *deep* copy is when there are two separate arrays that have the same contents
  * There are two distinct things in memory
  * Changes to one do not affect the other
* Demo: write a function to do this!


```java

	    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	    int copy[] = Arrays.copyOf(primes, primes.length);
	    primes[0] = 42;
	    System.out.println(Arrays.toString(primes));
	    System.out.println(Arrays.toString(copy));

	    copy = Arrays.copyOf(primes, 5);
	    System.out.println(Arrays.toString(copy));

	    List<Integer> evens = new ArrayList<>();
		evens.add(2);
		evens.add(4);
		evens.add(6);
		evens.add(8);
		List<Integer> evensCopy = new ArrayList<>(evens);
		evensCopy.add(5);
		System.out.println(evens);
		System.out.println(evensCopy);
```

### Multidimensional Arrays

* A regular old array is a 1-D array (one dimensional)
* You can have 2-D arrays with *rows* and *columns*
  * Tables
  * Spreadsheet
  * Matrices
* Yes, you can have 3D, 4D, etc. arrays, but likely there is a better solution
* In C and Java you specify *two* indices: `table[i][j]` (row `i` and column `j`)
* To setup memory for a 2-D array you need:
  * An array of pointers!
  * Each pointer will point to a row (1-D) array of integers

```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <errno.h>

/**
 * Sums the given elements in the integer array (of size n).
 */
int sum(const int *arr, int n);

/**
 * Sums the given elements in the integer array (of size n).
 * Returns a non-zero error code for any error.
 */
int sumByRef(const int *arr, int n, int *total);

/**
 * Creates an array of the given size and fills it with 1s,
 * returns the resulting array.
 */
int *onesArray(int n);

/**
 * Prints the given array of n integers to the standard output.
 */
void printArray(int *arr, int n);

/**
 * Returns a new copy of the given array of size n with its elements
 * reversed.
 */
int *reverseCopy(const int *arr, int n);

/**
 * Creates a new copy of the given array but only with even values
 * stored in it.
 *
 * Ex: input: [2, 6, 3, 7, 5, 4, 6, 9] => [2, 6, 4, 6]
 */
int *filterOutOdds(const int *arr, int n, int *newSize);

/**
 * Creates and returns a new, deep copy of the given array of
 * n integers
 */
int *deepCopy(const int *arr, int n);

int main(int argc, char **argv) {

    // int n = 9;
    // int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

    // int *b = deepCopy(primes, n);

    // primes[0] = 42;

    // printArray(primes, n);
    // printArray(b, n);

    // int s = sum(primes, n);
    // printf("sum of primes is %d\n", s);

    // int *ones = onesArray(n);
    // printArray(ones, n);

    // free(ones);

    // int sizeOfFiltered;
    // int *filteredPrimes = filterOutOdds(primes, n, &sizeOfFiltered);
    // printArray(filteredPrimes, sizeOfFiltered);

    int n = 3;
    int m = 5;
    int **table;
    table = (int **) malloc( sizeof(int *) * n );
    for(int i=0; i<n; i++) {
        table[i] = (int *) malloc( sizeof(int) * m );
    }
    table[0][0] = 42;
    table[n-1][m-1] = 123;

    for(int i=0; i<n; i++) {
        free(table[i]);
    }
    free(table);

    return 0;


}

int sum(const int *arr, int n) {

    if(arr == NULL || n < 0) {
        return 0;
    }

    int total = 0;
    for(int i=0; i<n; i++) {
        total += arr[i];
    }
    return total;

}

int sumByRef(const int *arr, int n, int *total) {

    if(arr == NULL || n < 0) {
        return 1;
    } else if(total == NULL) {
        return 2;
    }

    *total = 0;
    for(int i=0; i<n; i++) {
        *total += arr[i];
    }

    return 0;

}

int *onesArray(int n) {

    if(n < 0) {
        return NULL;
    }

    int *result = (int *) malloc( sizeof(int) * n );
    for(int i=0; i<n; i++) {
        result[i] = 1;
    }

    return result;
}

void printArray(int *arr, int n) {


    if(arr == NULL || n < 0) {
        printf("null\n");
        return;
    }

    printf("[");
    for(int i=0; i<n-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[n-1]);
    return;
}

int *reverseCopy(const int *arr, int n) {

    if(arr == NULL || n < 0) {
        return NULL;
    }

    int *reversed = (int *) malloc( sizeof(int) * n );
    for(int i=0; i<n; i++) {
        reversed[i] = arr[n-i-1];
    }

    return reversed;
}

int *filterOutOdds(const int *arr, int n, int *newSize) {
    //TODO: error handling

    //create a temporary space to hold all of the number
    //. BUT only copy over the evens
    int j = 0;
    int *temp = (int *) malloc( sizeof(int) * n );
    for(int i=0; i<n; i++) {
        if(arr[i] % 2 == 0) {
            temp[j] = arr[i];
            j++;
        }
    }
    //now you know how big the result should be: newSize
    *newSize = j;
    int *result = (int *) malloc( sizeof(int) * j );
    for(int i=0; i<j; i++) {
        result[i] = temp[i];
    }
    free(temp);

    return result;


}

int *deepCopy(const int *arr, int n) {

    if(arr == NULL || n < 0) {
        return NULL;
    }
    int *copy = (int *) malloc( sizeof(int) * n );
    memcpy(copy, arr, sizeof(int) * n );
    // for(int i=0; i<n; i++) {
    //     copy[i] = arr[i];
    // }

    return copy;
}
```

## Java multidimensional arrays

* Demo:

```java
int table[][] = new int[3][5];
for(int i=0; i<table.length; i++) {
  for(int j=0; j<table[i].length; j++) {
    table[i][j] = i * 10 + j;
  }
}

for(int i=0; i<table.length; i++) {
  System.out.println(Arrays.toString(table[i]));
}
```

```text












```
