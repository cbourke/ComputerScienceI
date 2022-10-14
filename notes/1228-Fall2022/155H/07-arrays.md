
# CSCE 155H - Computer Science I - Honors
## Arrays & Collections
### Fall 2022


* It is rare to deal with only one thing: one piece of data, 1 integer or 1 double, 1 character
* Collections of data are needed to store multiple instances of those things
* In C and Java we use *arrays* to store collections of *similar* elements
* In general:
  * Arrays have a single name (identifier)
  * You can access individual elements using an *index*
  * An index is an integer that represents the ordinal (placement) of an element
  * Indexing starts at 0
  * The first element is at index `0`
  * The second is at index `1`, etc.
  * If there are $n$ elements in an array, the last one is at index `n-1`
  * To access an element, use the square brackets:
    * `arr[0]`
    * `arr[1]`
    * `arr[i]` (use a variable, an *index* variable)
    * `arr[n-1]`

## Arrays in C

### Static Arrays

* We'll *start* with static arrays: arrays that are allocated on the program's call stack
* Very quickly, we will see the limitations of static arrays

```c
//create an array that can hold 5 integers:
int arr[5];
//assign some values...
arr[0] = 42;
arr[1] = 101;
arr[4] = 37;

//be careful with indexing:
//this is bad:
arr[-1] = 42;
arr[60] = 42;

//iterate over an array:
for(int i=-1; i<5; i++) {
  printf("arr[%d] = %d\n", i, arr[i]);
}
```

* Observations:
  * As with regular variables, no default values are set in an array, could be zero, could be garbage, etc.
  * You can use an idiomatic for loop to iterate over the elements in an array
  * Static arrays are allocated on the program stack which is *limited* (8MB); allocating too much memory (large arrays) on the stack is *not possible*
  * Accessing values outside of the array (negative index values or index values that exceed the size of the array) are *undefined behavior*:
    * They could end in a segmentation fault
    * They could simply end with garbage results
    * You *could* get away with it

* Times that static arrays are okay/good
  * When you have a limited number of values to store and
  * You know them upfront
  * Example

```c
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

```

#### Static Arrays in Java

* They don't exist

## Dynamic Arrays

* Dynamic arrays are allocated on the *heap*
* Heap is a much larger area of memory but less organized
* In C: you allocate memory on the heap by asking the operating system for a chunk of memory of a *particular size*
* Example: you want to store 100 integers; you would need to request `4 * 100` bytes of memory
* To do so, you use the **m**emory **alloc**ation function: `malloc`
* It has the following signature:
`void * malloc(size_t n)`
  * `size_t` can be though of as an integer
  * The return type is a *generic void pointer*: `void *`
  * What is `int *`?
  * What is `double *`?
  * What is `void *`?  It is a pointer to *anything*
  * A void pointer is a raw memory address: it can point to a memory address that stores an `int` or one that stores a `double`, etc.
* You ask `malloc` for a certain sized chunk of memory, it grants it and returns a pointer to it
  * `malloc` doesn't care how you use the memory, it is yours
  * We only want/need ONE `malloc` function; if it returned a *specific* pointer type we would need dozens and dozens of `malloc` functions: `mallocForInt`, `mallocForDouble`
* Demo

## Dynamic Arrays in Java

* In Java, you don't have pointers, nor memory management, nor `malloc`
* Instead, Java takes care of the memory management for you: you don't call the `free()` method to free up memory
* Instead of `malloc` you use the `new` keyword to create a new array

```java
// though it looks like a static array, it is not
int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

int x;

int n = 500;
int arr[] = new int[n];
arr[0] = 42;
arr[n - 1] = 101;

for (int i = 0; i < n; i++) {
  System.out.println(arr[i]);
}
```

* Observations:
  * Unlike C, Java does have a default value for array elements: 0, 0.0, for objects it is: `null`
  * You don't have to keep track of the size of an array in a variable, instead you can use `arr.length` property
  * Arrays in Java suck, don't use them unless you have to...

### Dynamic Collections in Java

* Arrays are of a fixed size: you create an array that grows or shrinks; if it is created with a size of 10, you cannot hold 11 elements, if you only hold 9 elements, you are wasting space
*

```java

		List<Integer> myNumbers = new ArrayList<>();

		//add always adds to the end of the list
		myNumbers.add(4);
		myNumbers.add(1);
		myNumbers.add(42);

		System.out.println(myNumbers);

		//add something to index 0
		myNumbers.add(0, 101);
		//add something to index 2
		myNumbers.add(2, 99);
		myNumbers.add(5, 1024);

		System.out.println(myNumbers);

		//get elements based on an index value:
		int x = myNumbers.get(0);
		System.out.println(x);

		//you can also iterate over a list:
		for(int i=0; i<myNumbers.size(); i++) {
			System.out.println(myNumbers.get(i));
		}

		//there's always a better way:
		//enhanced for loop
		for(int num : myNumbers) {
			System.out.println(num);
		}

		//you can take stuff out:
		System.out.println(myNumbers);
		myNumbers.remove(2);
		System.out.println(myNumbers);

    //Java also has Sets!
		//sets are unordered, unique elements
		//  there is no ordering: no first element, last, etc.
		//  no duplicates are allowed
		Set<String> names = new HashSet<>();
		names.add("Bob");
		names.add("Alice");
		names.add("Grace");
		names.add("42");
		names.add(Integer.toString(42));
		System.out.println(names);

		for(String name : names) {
			System.out.println(name);
		}

```

* Maps are great!

```java

		//maps map a key to a value of *ANY* TYPE
		Map<String, Integer> nameToNuid = new HashMap<>();
		nameToNuid.put("Chris", 35140602);
		nameToNuid.put("Alice", 1234);

		Map<Integer, String> nuidToName = new HashMap<>();
		nuidToName.put(35140602, "Chris");
		nuidToName.put(1234, "Alice");

		//look something up by the key:
		// again it maps a key => value
		int myNuid = nameToNuid.get("Chris");
		System.out.println(myNuid);
		String name = nuidToName.get(1234);
		System.out.println(name);

		//use a for loop to iterate:
		for(String s : nameToNuid.keySet()) {
			int x = nameToNuid.get(s);
			System.out.println(s + " maps to " + x);
		}
```

## Bookkeeping

* C has *manual memory management*: it falls to ***you*** the programmer to:
  * keep track of the size of an array you create
  * If you want to pass an array to a function, you need to tell the function how big the array is!
  * THere is NO WAY in C to determine (reliably) how big an array is just given the array
  * Ensure that no illegal/undefined access occurs
  * You need to make sure you "clean up" the memory when you are done with it: you need to give it back to the operating system
  * To "give it back" you use the `free(arr);` function
  * Once freed, that memory no longer belongs to you; attempts to access it are *undefined* behavior
  * Attempts to free memory that doesn't belong to you are undefined behavior
  * Failure to clean up memory properly leads to *memory leaks*
  * In C you need to be good stewards of resources

* Java:
  * No memory management; it is all taken care of by the Java Virtual Machine's Garbage Collector
  * Once an array or object is no longer in scope (no piece of code still has a reference to it), it is eligible for garbage collection
  * At certain increments, the JVM will reclaim memory automatically
  * You *mostly* don't need to worry about this!
  * No bookkeeping: you can use `arr.length` or `list.size()` to determine how big an array or collection is

## Multidimensional Arrays

* Both languages support multidimensional arrays
* 1-D Arrays: regular old arrays
* 2-D arrays: rows/columns; *tables*, *matrices*
* 3+ dimensions: rethink what you are doing

### Java
```java

		//create a 2-d array of integers that has dimensions
		//   5 x 10
		int table[][] = new int[5][10];

		//you can specify an entry using two indices:
		table[0][0] = 42; //set the upper left value to 42
		table[4][9] = 101; //set the lower right value to 101
		//row major form: the row is the first index, column the second
		for(int i=0; i<table.length; i++) {  //for each row
			System.out.printf("[ ");
			for(int j=0; j<table[i].length; j++) {  //for each column
				System.out.printf("%4d ", table[i][j]);
			}
			System.out.printf(" ] \n");
		}

```

### C

```c

		//create a 2-d array of integers that has dimensions
		//   5 x 10
    int numRows    = 5;
    int numColumns = 10;

    int **table = (int **) malloc( numRows * sizeof(int *) );
    for(int i=0; i<numRows; i++) {
      //allocate the i-th row:
      table[i] = (int *) malloc( numColumns * sizeof(int) );
    }

		//you can specify an entry using two indices:
		table[0][0] = 42; //set the upper left value to 42
		table[4][9] = 101; //set the lower right value to 101
		//row major form: the row is the first index, column the second

    //careful: though it may look like they are all zeros, there is no
    //defined default value for array or table entries
		for(int i=0; i<numRows; i++) {  //for each row
			printf("[ ");
			for(int j=0; j<numColumns; j++) {  //for each column
				printf("%4d ", table[i][j]);
			}
			printf(" ] \n");
		}
    for(int i=0; i<numRows; i++) {
      //free the i-th row:
      free(table[i]);
    }
    free(table);
```

## Arrays & Functions

### C

* When you pass an array to a function, you need to pass its *pointer*: `int *arr`
* When you do this, you need to *also* pass in the size of the array (basic bookkeeping)
* You can use the `const` keyword to prevent a function from making changes to your array

```c
int sum(const int *arr, int n) {

  int total = 0;
  for(int i=0; i<n; i++) {
    total += arr[i];
    //arr[i] = -1;
  }
  return total;

}
```

* You can also design functions to *return* an array
* When error handling with arrays, and you are returning a pointer, the only pointer you can return in the event of an error is `NULL`

## Misc

### Who owns memory

* If a function creates *temporary* memory that it uses to process data, it *owns* it; it is responsible for cleaning it up
* If a function returns a chunk of memory, it is transferring ownership to the calling function; that function is then responsible for it
* Generally: if you have memory that is owned by `main()` you can kinda sorta get away without cleaning it up

### How array memory works

* Why do we use 0-indexing in arrays?
* Arrays are actually memory addresses
* Indices are actually memory *offsets* from the beginning of the array
* THe array variable name is a memory address that starts at the beginning of the array
* The next element is a certain number of bytes "over"
* Ex:
  * Say we have an integer array named `arr`
  * The first element `arr[0]` is at memory location `arr`
  * The second element `arr[1]` is at memory location `arr + 4` (4 bytes over for an integer)
  * `arr[2]` is at memory location `arr + 8`

### Shallow vs Deep copies

* Example: a shallow copy
* A shallow copy is when you have more than one reference to the *same* thing (array)
* Changes to the array are reflected in *both* references!
* A *deep copy* is a completely separate copy of an array
* YOu can easily write a deepcopy function for common arrays
* If you don't want to write your own, you can use `memcpy`

```java

		List<Integer> numbers = new ArrayList<>();
		numbers.add(10);
		numbers.add(20);
		numbers.add(30);
		numbers.add(40);
		numbers.add(50);


		//Shallow copy:
		List<Integer> foo = numbers;

		System.out.println(numbers);
		System.out.println(foo);
		foo.add(60);
		System.out.println(numbers);
		System.out.println(foo);

		//Deep copy:
		foo = new ArrayList<>();
		for(Integer x : numbers) {
			foo.add(x);
		}
		System.out.println("=============");
		System.out.println(numbers);
		System.out.println(foo);
		foo.add(70);
		System.out.println(numbers);
		System.out.println(foo);

		//deep copy via a copy constructor:
		List<Integer> bar = new ArrayList<>(numbers);
		System.out.println(bar);

		//deep copies of arrays:
		int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
		int deepCopyOfPrimes[] = Arrays.copyOf(primes, primes.length + 2);
		System.out.println(Arrays.toString(deepCopyOfPrimes));
```

```text








```
