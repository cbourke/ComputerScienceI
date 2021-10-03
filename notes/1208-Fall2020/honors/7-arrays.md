
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
* Remember: the stack space is small (8MB, `ulimit -a`), allocating even moderately large arrays will result in a stack overflow
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
    for(Integer x : s) {
      System.out.println(x);
    }

```

### Maps

* Lists and arrays are limited in that they only "map" integer values 0 thru n-1 to other values
* At least a list is dynamic: it can grow/shrink as needed, but it is still limited by its indexing
* A map is a key-value pair data structure; it stores elements (values) using any arbitrary key (which can be any object)

```java

		//maps integers to strings
		Map<Integer, String> nuidToName = new HashMap<>();
		nuidToName.put(35140602, "Chris");
		nuidToName.put(12345678, "Joe");
		nuidToName.put(87654321, "Jill");
		//get stuff out:
		String name = nuidToName.get(35140602);
		System.out.println(name);
		String who = nuidToName.get(10);
		System.out.println(who);
		//replace stuff:
		nuidToName.put(35140602, "Christopher");
		name = nuidToName.get(35140602);
		System.out.println(name);
		//iterate:
		for(Integer key : nuidToName.keySet()) {
			String value = nuidToName.get(key);
			System.out.println(key + " maps to " + value);
		}

		Map<String, Integer> numbers = new HashMap<>();
		numbers.put("ten", 10);
		numbers.put("hundred", 100);
```

## Multidimensional Arrays

* Both languages support multidimensional arrays
* 1-D arrays: regular old arrays
* 2-D arrays: rows and columns, ie a *table* or *matrices*
* 3+ dimensions but rethink it

### Java

```java
int n = 2, m = 3;
//2 x 3 matrix, 2 rows, 3 columns
int matrix[][] = new matrix[n][m];
//by default all values will be zero,
//you can use 2 indices to access/set
matrix[0][0] = 42;
//lower right element:
matrix[1][2] = 21;
//get the length:
int numRows = matrix.length;
int numCols = matrix[0].length;
//row major form: row then column
```

### C

* In C, a 2-D array needs two pointers:
`int **matrix`
* The first pointer is a pointer to an *array of pointers*
* Then each pointer in the array is a pointer to a row of integers

```c

int n = 2, m = 3;
int **matrix = (int **) malloc(n * sizeof(int *));
for(int i=0; i<n; i++) {
  matrix[i] = (int *) malloc(m * sizeof(int));
}
//free up each row first
for(int i=0; i<n; i++) {
  free(matrix[i]);
}
//then free up the array of pointers
free(matrix);
```

## Deep vs Shallow copies

* a shallow copy is simply when 2 references (pointers) point to the same thing
* consequence: changes to one affect both

```c
  int n = 5;
  int *a = (int *) malloc(n * sizeof(int));
  for(int i=0; i<n; i++) {
    a[i] = (i+1) * 10;
  }
  //shallow copy
  int *b = a;
  a[0] = 42;
```

* a deep copy is a completely different and distinct copy of the original
* Changes to one do not affect the other
* Java version:

```java
int n = 5;
int a[] = new int[n];
for(int i=0; i<n; i++) {
  a[i] = (i+1) * 10;
}

int b[] = a;
a[0] = 42;
System.out.println(b[0]);
```

#### Deep copies

* In C, you can copy manually:
* OR you can look up and RTM `memcpy`

```c
#include <stdlib.h>
#include <stdio.h>


int *deepCopy(const int *arr, int n) {
  int *copy = (int *) malloc(n * sizeof(int));
  for(int i=0; i<n; i++) {
    copy[i] = arr[i];
    //arr[i] = 0;
  }
  return copy;
}
int main(int argc, char **argv) {

  int n = 5;
  int *a = (int *) malloc(n * sizeof(int));
  for(int i=0; i<n; i++) {
    a[i] = (i+1) * 10;
  }

  int *b = deepCopy(a, n);
  a[0] = 42;

}
```

* You can use the keyword `const` to prevent any changes to an array passed to a function

* Java:

```java

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Demo {

	public static int[] deepCopy(int arr[]) {
		int copy[] = new int[arr.length];
		for (int i = 0; i < arr.length; i++) {
			copy[i] = arr[i];
		}
		return copy;
	}

	public static void main(String args[]) {

		int n = 5;
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = (i + 1) * 10;
		}

		//int b[] = Demo.deepCopy(a);
		int b[] = Arrays.copyOf(a, a.length);
		a[0] = 42;
		System.out.println(b[0]);

		//lists sets and maps also have deep copy
		// functionality:
		List<String> names = new ArrayList<>();
		names.add("Chris");
		names.add("Joe");
		names.add("Jane");
		List<String> copyOfNames = new ArrayList<>(names);
		Set<String> copySet = new HashSet<>(names);
		names.add("Kris");
		System.out.println(names);
		System.out.println(copyOfNames);
		System.out.println(copySet);

		Map<Integer, String> nuidToName = new HashMap<>();
		nuidToName.put(35140602, "Chris");
		nuidToName.put(12345678, "Joe");
		nuidToName.put(87654321, "Jill");
		List<String> theNamesFromTheMap = new ArrayList<>(nuidToName.values());
		System.out.println(theNamesFromTheMap);

	}
}

```


```text







```
