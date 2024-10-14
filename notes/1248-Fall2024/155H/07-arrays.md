
# CSCE 155H - Computer Science I - Honors
## Arrays & Collections
### Fall 2024

* Almost never deal with just one piece of data
* Instead you deal with *collections* of data
* Both C and Java support old-school *arrays* collections of *similar* things (things of the same type: `int`, `double`, etc.) all stored *contiguously*
* In general:
  * Arrays have a single *identifier* (variable name)
  * YOu access each individual *element* using an *index*
  * Arrays always start at the 0-index
  * YOu use square brackets to access each element
  * Ex: first is at `arr[0]`, the second is at `arr[1]`, etc.
  * If there are `n` elements in an array the last one is at `arr[n-1]`

## Arrays in C

### Static Arrays

* "Static" here means that it has a fixed size when created and they are stored on the program's stack

```c

    int x;

    //integer array that holds 10 integers:
    int arr[10];
    int n = 10; //size of arr

    //a double array that can hold 20 doubles:
    int brr[20];

    arr[0] = 42;
    arr[9] = 101;
    //we're only screwing up our own memory; maybe we'll get away with it!
    //arr[10] = 1234;
    //arr[-1] = 4321;

    //there are no default values for arrays, likely garbage or 0xDEADBEEF
    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    //you need to set them:
    for(int i=0; i<n; i++) {
        arr[i] = 10 * i;
    }

    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
```

* Since static arrays are allocated on the stack, they exist inside stack frames, those stack frames are destroyed when the function returns
* Stack space is *very* limited: 4MB or 8MB or even kilobytes
* You cannot fit even a "small" array on the stack
* In Java: static arrays are NOT EVEN POSSIBLE!

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
  * a generic void pointers is a raw memory address that can point to *any* type!
  * The returned memory can be used for whatever type you want, this means only one function is necessary
  * When you get the pointer back, you *cast* it to the proper type

### Memory Management

* In C you have to keep track of a lot of things
* If you want to keep track of the *size* of an array, you need to put that into a variable, `n`
* There is NO way for you to determine the size of a *dynamic* array after it has been created
* ONce you are done using memory, you should clean it up
* You can "free" the memory back to the operating system using the function `free`
* Failure to free memory may lead to a memory leak: more and more memory is being taken by the program until it slows everything down and/or crashes
* In C you have to be good stewards of your resources

#### Pitfalls

* If `malloc` cannot allocate enough memory it returns: `NULL`
* If you attempt to access `free`'d memory it is *undeefined* behavior
* YOu cannot/should not "double" free memory: don't free it twice

## Java

* Java has arrays
* In Java: no memory management (no `malloc`, no `free`); instead you use the keyword `new`
* You don't need to keep track of the size of an array; `arr.length`
* Most of the syntax is the same
* There are default values: zeros
* Java has neat "enhanced for loops"...

```java

		int arr[] = new int[10];
		arr[0] = 42;
		arr[9] = 101;
//		arr[-1] = 123;
//		arr[10] = 123;

		for(int i=0; i<arr.length; i++) {
			System.out.println(arr[i]);
		}

		//for each integer x in the collection arr...
		for(int x : arr) {
			System.out.println(x);
		}
```

* Java has arrays.  They Suck.  Do not use them...
* Once created, they cannot change: they don't grow or shrink
* Instead in Java it is preferred to use *dynamic collections*: lists, sets, maps
* A `List` is an ordered collection of things (first, second, etc.)
  * Uses 0-indexing just like arrays
  * You can add things, remove things, it grows/shrinks automatically!

```java

		List<Integer> numbers = new ArrayList<>();
		//adds or "appends" t the end of the list...
		numbers.add(10);
		numbers.add(20);
		numbers.add(30);
		System.out.println(numbers);

		//adds at a particular index:
		numbers.add(1, 42);
		System.out.println(numbers);

		//remove
		numbers.remove(2);
		System.out.println(numbers);

		//get the element at index 2:
		int x = numbers.get(2);
		System.out.println(x);
		System.out.println(numbers);

		for(int i=0; i<numbers.size(); i++) {
			System.out.println(numbers.get(i));
		}

		for(Integer num : numbers) {
			System.out.println(num);
		}
```

#### Sets

* Sets are like lists but they hold things in an *unordered manner* and do not allow duplicates


```java

		Set<Integer> numbers = new HashSet<>();
		numbers.add(10);
		numbers.add(20);
		numbers.add(30);
		System.out.println(numbers);

		boolean result = numbers.add(10);
		System.out.println(result);
		System.out.println(numbers);

		numbers.add(42);
		System.out.println(numbers);

		numbers.remove(42);
		System.out.println(numbers);

		numbers.remove(42);
		System.out.println(numbers);

		if(numbers.contains(10)) {
			System.out.println("it contains 10");
		}

		for(Integer x : numbers) {
			System.out.println(x);
		}
```

#### Maps

```java

		//maps store things in a key-value pairing
		Map<String, Integer> m = new HashMap<>();
		m.put("Twenty", 20);
		m.put("Thirty", 30);
		m.put("Chris", 35140602);
		m.put("John", 35140602);

		System.out.println(m);

		//reassign key-value pairs:
		m.put("Twenty", 21);
		System.out.println(m);

		m.remove("Twenty");
		System.out.println(m);

		int myNUID = m.get("Chris");
		System.out.println(myNUID);

		for(String key : m.keySet()) {
			int value = m.get(key);
			System.out.println(key + " maps to " + value);
		}

		Map<Integer, String> reverse = new HashMap<>();
		for(String key : m.keySet()) {
			int value = m.get(key);
			reverse.put(value, key);
		}
		System.out.println(reverse);

		Map<Integer, Set<String>> nuidToPeople = new HashMap<>();
		for(String key : m.keySet()) {
			int value = m.get(key);
			Set<String> people = nuidToPeople.get(value);
			if(people == null) {
				//first time we've seen the value...
				people = new HashSet<>();
			}
			people.add(key);
			nuidToPeople.put(value, people);
		}
		System.out.println(nuidToPeople);

```

```java
//suppose you had a list of zip codes, some repeats
		// you want to determine how many times a zip code appears
		// 68508 => 20
		Random r = new Random();
		List<Integer> zipCodes = new ArrayList<>();
		for(int i=0; i<100000; i++) {
			zipCodes.add(r.nextInt(1000));
		}
		System.out.println(zipCodes);

		//  zipCode -> count of the zipCode
		Map<Integer, Integer> zipsToCounts = new HashMap<>();
		for(Integer zipCode : zipCodes) {
			//have we seen this zipCode yet?
			Integer x = zipsToCounts.get(zipCode);
			if(x == null) {
				zipsToCounts.put(zipCode, 1);
			} else {
				zipsToCounts.put(zipCode, x+1);
			}
		}
		for(Integer zipCode : zipsToCounts.keySet()) {
			System.out.printf("%5d -> %d\n", zipCode, zipsToCounts.get(zipCode));
		}
```

## Pitfalls with Arrays in C

* In C **you** are responsible for *memory management*
* You have to keep track of how big arrays are when you create them
* You have to clean up after yourself (`free`) and don't double-`free` or attempt to used `free`d memory, etc.
* **You** are responsible for memory management

### Arrays & Functions

* When you pass an array to a function, *you also need to pass the size of the array*
* There is ZERO, ABSOLUTELY ZERO way to tell the size of a dynamic array in C!
* Using `sizeof` in any form is *wrong*

```c
/**
 * Demonstration code template.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/**
 * Prints the given integer array (of a given size n)
 */
void printArray(const int *arr, int n);

/**
 * Computes the sum of the elements in the given integer array (of size n)
 */
int sum(const int *arr, int n);

/**
 * Returns a new array of the given size (n) filled with ones
 */
int *onesArray(int n);


int main(int argc, char **argv) {

    int n = 10;

    int *arr = (int *) malloc(n * sizeof(int));

    for(int i=0; i<n; i++) {
        arr[i] = 10 * (i+1);
    }
    printArray(arr, n);

    int total = sum(arr, n);
    printf("total = %d\n", total);
    printArray(arr, n);

    return 0;
}

void printArray(const int *arr, int n) {

    if(arr == NULL) {
        printf("null\n");
        return;
    } else if(n < 0) {
        printf("[]\n");
        return;
    }

    printf("[");
    for(int i=0; i<n-1; i++) {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[n-1]);
}

int sum(const int *arr, int n) {

    int total = 0;
    for(int i=0; i<n; i++) {
        total += arr[i];
    }
    return total;
}

int *onesArray(int n) {

    int *result = (int *) malloc( n * sizeof(int) );
    //int result[n];
    for(int i=0; i<n; i++){
        result[i] = 1;
    }
    return result;
}
```

* Use the `const` keyword to make an array read-only
* You pass an array to a function as a pointer!
* Be sure to also pass its size!

### Cleaning Up

* Once you are done with a chunk of memory you should give it back!
* Failure to give it back can lead to a *memory leak*: you constantly take memory and never give back, eventually...
* To give memory back that you no longer need, you use the `free()` function and simply pass in the pointer
* After free'd memory cannot be accessed (or *should not be*)
* you cannot (should not) free memory twice
* Who owns memory?
  * When a function returns memory, it does *NOT* own it, the calling function owns it and is responsible for it
  * When a function receives memory it *DOES* own it and is responsible for it
  * In general, ALL memory should be cleaned up; exception: it is sort-of, kind-of okayish to not free up memory in the `main()`

### Shallow vs Deep Copies

* A *shallow* copy is when two references (pointers) point to the same chunk of memory
  * Changes to one affect the other!
  * There is only ONE thing in memory
* You can have a *deep* copy of an array
  * Changes to one do not affect the other
  * There are two distinct things in memory

* Exercise: implement a function that "filters" an array and returns a new array containing only positive values
  * Ex: `{5, 3, -1, 0, 4, -5}`
  * Output: `{5, 3, 4}`

### Multidimensional Arrays

* A regular old array is a 1-D array (one dimensional)
* You can have 2-D arrays with *rows* and *columns*
  * Table (spreadsheet)
  * Matrix
* YOU *can* have 3D, 4D, etc. arrays, but likely there is a better solution
* In C you specify *two* indices: `table[i][j]` (row `i` and column `j`)
* To setup memory for a 2-D array you need:
  * An array of pointers
  * Each pointer will point to a row

```c
int n = 3;
int m = 5;

//initialize an array of integer pointers...
// initialize n pointers, one to each row...
int **table = (int **) malloc( sizeof(int *) * n );
//for each row i, initialize the array for that row...
for(int i=0; i<n; i++) {
  table[i] = (int *) malloc( sizeof(int) * m );
}

for(int i=0; i<n; i++) {
  for(int j=0; j<m; j++) {
    table[i][j] = i * j;
  }
}

for(int i=0; i<n; i++) {
  free(table[i]);
}
free(table);
```

```text









```
