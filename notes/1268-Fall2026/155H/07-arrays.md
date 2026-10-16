
# CSCE 155H - Computer Science I - Honors
## Arrays & Collections
### Fall 2026

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
    //static array declaration:
    int arr[10];
    //creates an array of integers of size 10
    arr[0] = 42;
    arr[1] = 120;
    arr[9] = 12;

    for(int i=0; i<10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    //Observation: there are no default values in an array, most values will be garbage/DEADBEEF

    //what happens if we get too big...
    int brr[10000000];
    brr[0] = 42;
    brr[9999999] = 101;

    printf("First: %d, last: %d\n", brr[0], brr[999999]);

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
  * Think of `size_t` as an integer (the number of bytes you wish to allocate)
  * The return type is a *generic void pointer*: a pointer that can point to anything
  * Its just generic: it points to a generic memory location
  * The returned memory can be used for whatever you want it to be
  * Generally when we receive the pointer, we'll *cast* it as the type that we intend to use it as
  * In any error event, `malloc` will return `NULL`

## Java

* No pointers in Java, no static arrays
* All arrays are allocated on the heap

```java

		//create a "dynamic" array:
		//holds 10 integers
		//all initialized to 0
		int arr[] = new int[10];

		//this same syntax can be used in both languages:
		int primes[] = {2, 3, 5, 7, 11, 13, 17};

		for(int i=0; i<arr.length; i++) {
			System.out.printf("arr[%d] = %d\n", i, arr[i]);
		}

		//enhanced for loop:
		//for each x in the collection primes
		for(int x : primes) {
			System.out.println(x);
		}
```

* Arrays suck, don't use them unless you *have* to
* Java has much better *dynamic* collections
* Java has classes to support `List`s, `Set`s and `Map`s
* A Java `List` is a collection of *ordered* elements that allow duplicates

```java

		//List is a collection of:
		// ordered elements
		// that allows duplicates
		List<Integer> numbers = new ArrayList<>();
		//add always adds the element to the end of the list
		numbers.add(10);
		numbers.add(20);
		numbers.add(30);

		//only integers for this list:
		//numbers.add(10.5);
		//numbers.add("Hello");
		//duplicates are okay:
		numbers.add(10);
		System.out.println(numbers);

		//you can add at an arbitrary index:
		numbers.add(0, 42);
		System.out.println(numbers);

		numbers.add(2, 101);		
		System.out.println(numbers);

		numbers.add(0, 123);
		System.out.println(numbers);

		//you can remove stuff:
		int removedElement = numbers.remove(0);
		System.out.println(numbers);

		//retrieval:
		//get the first element:
		int x = numbers.get(0);
		System.out.println(x);

		//iterate:
		for(int i=0; i<numbers.size(); i++) {
			int y = numbers.get(i);
			System.out.println(y);
		}

		//enhanced for loop:
		for(int z : numbers) {
			System.out.println(z);
		}
```

* A `Set` is an *unordered* collection of *unique* elements

```java

		Set<String> names = new HashSet<>();

		names.add("Chris");
		names.add("Seiya");
		names.add("Jane");
		names.add("Chris");

		System.out.println(names);

		//unordered: there is no first element to get...
		//String name = names.get(0);

		//enhanced for loop is your option
		for(String name : names) {
			System.out.println(name);
		}

//		names.remove("Jane");
//		System.out.println(names);
//		//remove everything:
//		names.clear();
//		System.out.println(names);
//		//size of the set:
//		int n = names.size();

		//transform names to a list:
		List<String> namesList = new ArrayList<>(names);
		System.out.println(names);
		System.out.println(namesList);
		namesList.add("Chris");
		System.out.println(namesList);

		List<Integer> values = new ArrayList<>();
		values.add(10);
		values.add(10);
		values.add(20);
		values.add(30);

		Set<Integer> uniqueValues = new HashSet<>(values);
		System.out.println(uniqueValues);
```

* `Map`s are even better
* Lists: you use 0-indexing: they are all integers and they run 0 up to n - 1
* Sets: no indexing at all, just a "bag" of stuff
* Maps: key-value pairing data structure
* You can map any type to any type

```java

		Map<Integer, String> nuidToName = new HashMap<>();

		nuidToName.put(35140602, "Bourke");
		nuidToName.put(123, "Jones");
		nuidToName.put(987, "Doe");

		System.out.println(nuidToName);

		nuidToName.put(987, "Foo");
		System.out.println(nuidToName);

		//retrieve:		
		String me = nuidToName.get(35140602);
		System.out.println(me);
		String joe = nuidToName.get(456);
		System.out.println(joe);

		nuidToName.put(1111111, "Bourke");

		System.out.println(nuidToName);

		//iterate over a map:
		Set<Integer> keys = nuidToName.keySet();
		for(Integer key : keys) {
			String value = nuidToName.get(key);
			System.out.println(key + " maps to " + value);
		}
```

## Pitfalls with Arrays

* You must make sure that you are only accessing elements within the bounds of an array
  * C: segmentation fault, or a "stack smashing event" or just garbage results: *undefined behavior*
  * Java: `IndexOutOfBoundsException` is thrown
* What happens if you don't clean up after yourself?
  * C: you request memory through: `malloc()`
  * Once you are done with it, you should give it back
  * To do so: use the `free()` function (pass it the pointer to the dynamically allocated array)
  * Not freeing memory will lead to a *memory leak*
  * Pitfalls to free:
    * Do NOT free static memory
    ```c
    //don't free stack memory:
    int primes[] = {2, 3, 5, 7, 11, 13, 17};
    free(primes);
    ```
    * Do not access memory once it has been freed
    * Do not free something twice
    ```c

    int n = 1000000;
    int *arr = (int *) malloc( n * sizeof(int) );

    arr[0] = 42;
    arr[n-1] = 101;

    free(arr);
    //trying to access after freeing: undefined behavior -> seg fault
    //printf("first: %d\n", arr[0]);

    //double free error: you cannot free something twice
    free(arr);
    ```
    * **You** are responsible for memory management
    * Java: no memory management!
    * JVM takes care of all memory management

### Arrays & Functions

#### C

* When you pass an array to a function, *you also need to pass the size of the array*
* This is called "bookkeeping"
* There is absolutely NO WAY for you to determine the size of a dynamic array in C
* You have to pass the size of the array to any function that you wish to process it
* Make sure you are doing basic error handling
* You can put a `const` in front of the the array pointer to prevent changes
* You can also write functions that *return* new arrays
  * `malloc` does this


```c
/**
 * Author: Chris Bourke
 *
 * Demo Code
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>

/**
 * Utility function to print the given array of size n to the
 * standard output.
 */
void printArr(const int *arr, int n);

/**
 * Returns the sum of all elements in the given array of size n
 */
int sum(const int *arr, int n);

/**
 * Sums the given values in the array of size n, places the sum
 * into the pass-by-reference variable, returns an error code for
 * all bad inputs.
 */
int summation(const int *arr, int n, int *result);

/**
 * Creates a new array of size n and returns a pointer to
 * the new array.
 */
int *getOnesArray(int n);

/**
 * Creates a new array that contains only the positive
 * values stored in arr (which is of size n).
 *.                    i
 * input:  [5, -2, 7, -4, 5, 7, -1, 0]
 * output: [5, 7, 5, 7]
 *.               j
 */
int *getPositives(const int *arr, int n, int *newArrSize);

int main(int argc, char **argv) {


    int n = 10;
    int *arr = (int *) malloc( n * sizeof(int) );

    for(int i=0; i<n; i++) {
        arr[i] = (i + 1) * 10;
    }

    printArr(arr, n);
    int total = sum(arr, n);
    printf("Sum = %d\n", total);

    int total2;
    summation(arr, n, &total2);
    printf("Sum = %d\n", total2);

    int m = 10;
    int *ones = getOnesArray(m);
    printArr(ones, m);

    int brr[] = {5, -2, 7, -4, 5, 7, -1, 0};
    int newSize;
    int *pos = getPositives(brr, 8, &newSize);
    printArr(pos, newSize);

    return 0;
}

void printArr(const int *arr, int n) {

    if(n <= 0) {
        printf("[]\n");
        return;
    } else if(arr == NULL) {
        printf("(null)\n");
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
    if(arr == NULL || n <= 0) {
        return total;
    }
    for(int i=0; i<n; i++) {
        total += arr[i];
    }
    return total;
}

int summation(const int *arr, int n, int *result) {

    if(arr == NULL || n <= 0 || result == NULL) {
        return 1;
    }
    int total = 0;
    for(int i=0; i<n; i++) {
        total += arr[i];
    }
    //only screw with the pointer once:
    *result = total;
    return 0;
}

int *getOnesArray(int n) {

    if(n < 0) {
        return NULL;
    }

    int *arr = (int *) malloc(sizeof(int) * n);

    for(int i=0; i<n; i++) {
        arr[i] = 1;
    }

    return arr;
}

int *getPositives(const int *arr, int n, int *newArrSize) {
    //TODO: error handling

    //count up the number of positives:
    int numElements = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > 0) {
            numElements++;
        }
    }

    *newArrSize = numElements;

    int *result = (int *) malloc(sizeof(int) * numElements);
    int j = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > 0) {
            result[j] = arr[i];
            j++;
        }
    }

    return result;
}

```

### Multidimensional Arrays

* A regular old array is a 1-D array (one dimensional)
* You can also have multidimensional arrays: 2D arrays, 3D arrays, 4D arrays, etc.
* Our focus: 2-D arrays
  * Rows/Columns: Tables, spreadsheets
  * Math: matrices
* IF a 1-D array is `int *`
* A 2-D array is represented with `int **`

```c

  int numRows = 3;
  int numCols = 4;

  //create a 3 x 4 table/matrix
  int **table = (int **) malloc(sizeof(int *) * numRows);
  //setup each row:
  for(int i=0; i<numRows; i++) {
    //setup row i:
    table[i] = (int *) malloc(sizeof(int) * numCols);
  }

  table[0][0] = 42;
  table[2][3] = 101;

  //now we need to free everything...
  //first: free each row...
  for(int i=0; i<numRows; i++) {
    free(table[i]);
  }
  free(table);
```

```text












```
