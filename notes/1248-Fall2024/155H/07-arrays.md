
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

```text









```
