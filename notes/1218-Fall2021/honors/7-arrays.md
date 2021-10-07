
# CSCE 155H - Computer Science I - Honors
## Arrays & Collections
### Fall 2021


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
* Also: the stack size is *very limited*
* Remember: the stack space is small (10MB, `ulimit -a`), allocating even moderately large arrays will result in a stack overflow
* In Java: static arrays are not even possible

## Dynamic Arrays

* Dynamic arrays are allocated on the *heap*
* The heap is a much "larger" but "less organized" chunk of memory
* In C: you allocate memory on the heap by asking the operating system for a chunk of memory
* You ask for a chunk of memory using the **m**emory **alloc**ation function:
`void * malloc(size_t n)`
  * `void *` is a generic void pointer that can point to any raw memory address
  * A void pointer can point to any type of data!
  * If `malloc` returned a *specific* type of pointer, we would need 50 different versions of malloc: `mallocForIntegers`, `mallocForDoubles`, etc.
  * `size_t` can simply be thought of as an integer representing the *number of bytes* you are requesting
  * You can use the `sizeof()` macro to determine how many bytes each type takes
  * Ex: `sizeof(int)`, `sizeof(double)`
  * Upon success, `malloc` will return a valid pointer to a memory location that you can start using
  * Upon failure: `malloc` returns `NULL`
  * When you receive the pointer, you should cast it to whatever type of pointer you want to use: `(int *)` if it is an integer array, `(double *)` if it is a double array, etc.
* By default, no default values are defined in C, it *could* be zeros, it could be garbage, you should initialize the array properly

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

* C has *manual memory management*: it falls to ***you*** the programmer to:
  * keep track of the size of an array you
  create
  * Pass that size to any function that you also pass the array to
  * Ensure that no illegal/undefined access occurs
  * You need to make sure you "clean up" the memory when you are done with it: you need to give it back to the operating system
  * To "give it back" you use the `free(arr);` function
  * Once freed, that memory no longer belongs to you; attempts to access it are *undefined* behavior
  * Attempts to free memory that doesn't belong to you are also undefined behavior
  * Failure to clean up memory after you are done using it may result in a *memory leak*
  * In C you need to be good stewards of your resources

### Java

* Java has no manual memory management: it is all taken care of by the Java *garbage collector*
  * Once an array or object is no longer in scope (no piece of code still has a reference to it), it is eligible for garbage collection
  * At certain increments, the JVM will reclaim memory automatically
  * You don't need to worry about a thing (mostly)!
  * No bookkeeping: you don't need to keep track of the size of arrays, it is available in `arr.length`
  * Arrays in Java suck, don't use them!

## Java Collections

* In Java, regular old arrays are terrible
* There are much better "dynamic collection data structures"

### Lists

* `List`s are ordered collections that use 0-indexing BUT
  * they grow and shrink dynamically and automatically as you put stuff and take stuff out!
  * To interact with a `List` or `ArrayList` you call various methods on it
  * You also specify that a list holds a certain type of variable using *parameterization*

```java

		List<Integer> myList = new ArrayList<>();

		myList.add(10);
		myList.add(20);
		myList.add(30);

		System.out.println(myList);

		myList.add(0, 42);

		System.out.println(myList);

		myList.remove(1);

		System.out.println(myList);

		for(int i=0; i<myList.size(); i++) {
			System.out.println(myList.get(i));
		}

		for(Integer x : myList) {
			System.out.println(x);			
		}
```

### Sets

* Sets are *unordered* collections of *unique* elements

```java

		Set<Integer> s = new HashSet<>();
		s.add(10);
		s.add(20);
		s.add(30);
		System.out.println(s);

		for(Integer x : s) {
			System.out.println(x);
		}

		s.remove(30);
		System.out.println(s);

		//adding duplicates?
		s.add(20);
		s.add(20);
		System.out.println(s);


    		List<Integer> numbers = new ArrayList<>();

    		numbers.add(10);
    		numbers.add(10);
    		numbers.add(20);
    		numbers.add(30);
    		numbers.add(30);
    		numbers.add(30);
    		System.out.println(numbers);

    		Set<Integer> uniqueElements = new HashSet<>(numbers);
    		System.out.println(uniqueElements);
```

### Maps

* A map is a key-value collection: you can store elements *of any type* using a key of any type!
* At least a list is dynamic: it can grow/shrink as needed, but it is still limited by its indexing
* A map is a key-value pair data structure; it stores elements (values) using any arbitrary key (which can be any object)

```java

		Map<Integer, String> m = new HashMap<>();

		m.put(10, "ten");
		m.put(2, "two");
		m.put(42, "forty-two");
		System.out.println(m);

		//get an element by its key:
		String s = m.get(42);
		System.out.println(s);
		m.put(42, "answer");
		System.out.println(m);

		//iterate over the elements:
		for(Integer key : m.keySet()) {
			System.out.println(key + " maps to " + m.get(key));
		}

		//iterate over the elements by value:
		for(String str : m.values()) {
			System.out.println(str);
		}
```

## Multidimensional Arrays

* Both languages support multidimensional arrays
* 1-D arrays: regular old arrays
* 2-D arrays: rows and columns, ie a *table* or *matrices*
* 3+ dimensions but rethink it

### Java

```java

		//3 rows, 4 column table:
		int table[][] = new int[3][4];
		//set the top left most element:
		table[0][0] = 42;
		//set the bottom right most element:
		table[2][3] = 101;

		for(int i=0; i<table.length; i++) {//for each row...
			System.out.printf("[");
			for(int j=0; j<table[i].length; j++) {//for each column in row i...
				System.out.printf("%4d", table[i][j]);				
			}
			System.out.print("]\n");
		}
```

### C

```c
    //3 rows, 4 column table:
    int n = 3;
    int m = 4;
    int **table = (int **) malloc(n * sizeof(int *));
    for(int i=0; i<n; i++) {
      table[i] = (int *) malloc(m * sizeof(int));
    }

    int value = 10;
    for(int i=0; i<n; i++) {//for each row...
      for(int j=0; j<m; j++) {//for each column in row i...
        table[i][j] = value;
        value += 10;
      }
    }

    int *a = NULL;
    *a = 42;

    //clean up...
    //clean up...
    for(int i=0; i<n; i++) {//for each row...
      //free it...
      free(table[i]);
    }
    free(table);
```

## Deep vs Shallow copies

* A *shallow* copy of an array is simply when 2 references (pointers in C or variables in Java) refer to the same thing
* A *deep copy* is when 2 references refer to completely different areas of memory with the same contents

```c

//this function creates a *deep copy* of the given
// array of integers
int * deepCopyInt(int *arr, int n) {
  int *c = (int *) malloc(n * sizeof(int));
  for(int i=0; i<n; i++) {
    c[i] = arr[i];
  }
  return c;
}

int main() {

  int n = 5;
  int *a = (int *) malloc(n * sizeof(int));
  for(int i=0; i<n; i++) {
    a[i] = (i+1) * 10;
  }

  int * b = deepCopyInt(a, n);

  a[0] = 42;
  printf("b[0] = %d\n", b[0]);



  return 0;
}
```

### Java

```java

		int a[] = new int[5];
		for (int i = 0; i < a.length; i++) {
			a[i] = (i + 1) * 10;
		}

		int b[] = a;
//		a[0] = 42;
//		System.out.printf("b[0] = %d\n", b[0]);

		//deep copy
		b = Arrays.copyOf(a, a.length);
		a[0] = 42;
		System.out.println(Arrays.toString(a));
		System.out.println(Arrays.toString(b));
```

```











```
