
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

```text








```
