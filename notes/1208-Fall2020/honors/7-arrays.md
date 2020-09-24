
# CSCE 155H - Computer Science I - Honors
## Arrays
### Fall 2020

* It is rare to only deal with 1 number of 1 character, or 1 piece of data
* Collections of data are used to store multiple instances of those things
* In C and Java, we use *arrays* to store collections of *similar* things (things of the same type)
* In general:
  * Arrays have a single name (identifier)
  * You can access individual elements using an *index*
  * The first element is at index 0 (0-indexing)
  * The second is at index 1, etc.
  * The last (assuming it has `n` elements) is at index `n-1`
  * Indexing is done via square bracket syntax: `arr[0]`, or `arr[n-1]` or in general `arr[i]` (the ith element)
  
## Arrays in C

### Static Arrays

* Static arrays in C are arrays that are allocated on the stack
* Syntax:

```c
int arr[5];
  
for(int i=0; i<5; i++) {
  arr[i] = (i+1);
}
```

* Since static arrays are allocated on the stack, they exist inside stack frames, those stack frames are destroyed when the function returns
* Remember: the stack space is small (8MB), allocating even moderately large arrays will result in a stack overflow
* In Java: static arrays are not even possible

## Dynamic Arrays

* Dynamic arrays are allocated on the heap
* THe heap is a much "larger" but "less organized" chunk of memory
* In C: you allocate memory on the heap by asking the operating system for a chunk of memory
* You ask for a chunk of memory using the **m**emory **alloc**ation function:
 `void * malloc(size_t n)`
  * `void *` is a generic void pointer that can point to any raw memory address
  * `size_t` can simply be seen as an integer: you end up asking for `n` bytes of memory
  * Upon success, `malloc` will return a valid pointer to a memory location that you can start using
  * Upon failure, it returns `NULL`
  * When you receive the pointer, you should cast it to whatever type of pointer you want to use: `(int *)` if it is an integer array, `(double *)` if it is a double array, etc.
* You can use `sizeof()` to determine how many bytes each type takes
* By default, no default values are defined in C, it *could* be zeros, it could be garbage, you should initialize the array properly
* In Java: the default values are zero!

## Dynamic arrays in Java

* Java doesn't have `malloc`, instead you use the `new` keyword
* Example:

```java

int arr[] = new int[10];
double numbers[] = new double[20];
arr[0] = 42;
arr[9] = 101;
```

## Bookkeeping

* C has *manual memory management*: it is on you, the programmer to 
  * keep track of the size of the arrays you create
  * Pass that size to any function(s) that you pass an array to
  * Ensure that you do not access values outside the array's range
  * You need to give it back to the OS once you are done with it
  * To give it back is to use the `free` function:
    `free(arr);`
  * Once freed, that memory no longer belongs to us, attempts to access are undefined behavior
  * Attempts to free memory that doesn't belong to you are also undefined behavior
  * Failure to clean up memory after you are done using it may result in a *memory leak*
  * In C you need to be good stewards of your resources
* Java has no manual memory management: it is all taken care of by the Java *garbage collector*
  * Once an array or object is no longer in scope (no piece of code still has a reference to it), it is eligible for garbage collection
  * At certain increments, the JVM will reclaim memory automatically
  * You don't need to worry about a thing (mostly)!
  * No bookkeeping: you don't need to keep track of the size of arrays, it is available in `arr.length`

## Java Collections

* In Java, regular old arrays are terrible
* There are much better "dynamic collection data structures"

### Lists

* `List`s are ordered collections that use 0-indexing, BUT
* They grow and shrink automatically as you add or remove elements
* To interact with a `List` or `ArrayList` you call various methods on it
* You also specify that a list holds a certain type of variable using *parameterization*

```java

		List<Integer> list = new ArrayList<>();
		list.add(10);
		list.add(20);
		list.add(30);
		list.add(2, 40);
		list.remove(0);
		System.out.println(list);
		int x = list.get(0);
		System.out.println(x);
		System.out.println("size = " + list.size());
		
		List<Double> numbers = new ArrayList<>();
		numbers.add(3.14);
		//NO: numbers.add("Hello");
		numbers.clear();
```

### Sets

* A set is a collection of unordered unique elements
* Unordered: there is no first element, second element, etc.
* Unique: you cannot add more than one instance of the same element (no duplicates)

```java

		Set<Integer> s = new HashSet<>();
		s.add(10);
		s.add(20);
		s.add(30);
		System.out.println(s);
		s.add(10);
		System.out.println(s);
```

```text







```