
# CSCE 155H - Computer Science I - Honors
## Arrays & Collections
### Fall 2023

* Almost never deal with just one piece of data
* Instead, you process a *collection* of data
* In both C and Java we have *arrays*: collections of *similar* things (things of the same type)
* In general:
  * Arrays have a single name identifier
  * You access individual elements using an *index*
  * Arrays are always "0-index": the indexing starts at 0
  * You use square bracket notation to access them
  * Example: `arr[0]` is the first element
  * `arr[1]`, `arr[2]`, etc.
  * If an array holds $n$ elements then the last element is at `arr[n-1]`

## Arrays in C

### Static Arrays

* "Static" in this case means that they have a fixed size when they are created
* And: they are allocated on the stack!  


```c

    //create an array of integers that holds up to 10 elements:
    int n = 10;
    int arr[10];

    //what is stored in arr right now?
    //garbage!
    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    for(int i=0; i<n; i++) {
        arr[i] = (i + 10);
    }

    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

```

* Since static arrays are allocated on the stack, they exist inside stack frames, those stack frames are destroyed when the function returns
* Stack space is *very* limited: 4MB or 8MB or even kilobytes
* You cannot fit even a "small" array on the stack
* In Java: static arrays are NOT EVEN POSSIBLE!

* Accessing elements outside a valid array in C:
  * Stack smashing events
  * Segmentation Faults
  * Undefined/bad behavior
* Doing so in Java results in: `ArrayIndexOutOfBoundsException`

## Dynamic Arrays

* Dynamic arrays are allocated on the heap space:
  * Much much larger
  * Less organized
  * less efficient (in some ways)
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


```c
int n = 2147000000;
int *arr = NULL;
arr = (int *) malloc(sizeof(int) * n);

//if malloc fails for whatever reason, it returns NULL
if(arr == NULL) {
    printf("memory allocation failed, download more RAM...\n");
    exit(1);
}

//you can now use it as a "regular old" array:
arr[0] = 42;
arr[n-1] = 101;

printf("first and last: %d, %d\n", arr[0], arr[n-1]);
```

* Java:

```java

		int n = 2147000000;
		int arr[] = new int[n];

	    arr[0] = 42;
	    arr[n-1] = 101;

	    System.out.printf("first and last: %d, %d\n", arr[0], arr[n-1]);
```

## Java: Arrays Suck

* Once created, they cannot change: they don't grow or shrink
* Instead in Java it is preferred to use *dynamic collections*: lists, sets, maps
* A `List` is an ordered collection of things (first, second, etc.)
  * Uses 0-indexing just like arrays
  * You can add things, remove things, etc. and it grows or shrinks to accommodate them

```java

		List<Integer> myList = new ArrayList<>();
		System.out.println(myList);
		//add adds to the end of the list:
		myList.add(10);		
		System.out.println(myList);
		myList.add(20);
		myList.add(5);
		myList.add(30);
		System.out.println(myList);

		//duplicates are possible/allowed!
		myList.add(10);
		System.out.println(myList);

		myList.add(0, 42);
		System.out.println(myList);

		if(myList.contains(3)) {
			System.out.println("3 is in there!");
		} else {
			System.out.println("3 is NOT in there!");

		}

		//you cannot add non-integer types after the parameterization:
		//myList.add(3.14);
		//myList.add("Hello");
		List<String> names = new ArrayList<>();
		names.add("Chris");
		names.add("Matt");
		names.add("Witty");
		System.out.println(names);

		//you can use 0-based indexing to retrieve elements:
		int x = myList.get(2);
		System.out.println("x = " + x);
		for(int i=0; i<myList.size(); i++) {
			System.out.printf("myList[%d] = %d\n", i, myList.get(i));
		}

		//"for each" loop: Java's term: "enhanced for loop"
		for(Integer y : myList) {
			System.out.println("y = " + y);
		}

		System.out.println(myList);
		myList.remove(2);
		System.out.println(myList);

		System.out.println(myList);
		for(int i=0; i<myList.size(); i++) {
			myList.remove(0);		
		}

		//careful: this is a "ConcurrentModificationExcpetion"
//		for(Integer y : myList) {
//			myList.remove(0);
//		}

		myList.clear();
		System.out.println(myList);


```

* Sets are like lists but they hold things in an *unordered manner* and do not allow duplicates

```java

		Set<Integer> mySet = new HashSet<>();
		System.out.println(mySet);
		mySet.add(10);
		mySet.add(20);
		mySet.add(30);
		System.out.println(mySet);

		mySet.add(10);
		System.out.println(mySet);

		//add something to the "beginning" or to an index:
		//no indexing at all!  mySet.add(2, 42);

		for(Integer x : mySet) {
			System.out.println(x);
		}

		//you can but probably have a better solution:
		Set<List<Integer>> foo;

		//you can make a list into a set and a set into a list:
		List<Integer> mySetButOrdered = new ArrayList<>(mySet);
		System.out.println(mySetButOrdered);
		Collections.sort(mySetButOrdered);
		System.out.println(mySetButOrdered);

		List<String> names = new ArrayList<>();
		names.add("Chris");
		names.add("Matt");
		names.add("Chris");
		names.add("Witty");
		System.out.println(names);

		Set<String> uniqueNames = new HashSet<>(names);
		System.out.println(uniqueNames);
```

```java

		Random r = new Random();
		List<Integer> zipCodes = new ArrayList<>();
		for(int i=0; i<1000; i++) {
			zipCodes.add(r.nextInt(1000));
		}
		System.out.println(zipCodes);

		Set<Integer> uniqueZipCodes = new HashSet<>(zipCodes);
		System.out.println("Number of codes: " + uniqueZipCodes.size() );

		//goal: create a list of unique codes and the number of times they appear
		//first attempt:
		for(int i=0; i<1000; i++) {
			System.out.printf("zipcode %3d: ", i);
			//how many times does the zipcode i appear in zipCodes:
			int counter = 0;
			for(Integer x : zipCodes) {
				if(x == i) {
					counter++;
				}
			}
			System.out.printf("%d\n", counter);
		}

		//think of the data this way:
		// zipcode => number of times it appears
		// 849 => 2
		Map<Integer, Integer> counts;

    m.put("Chris", 27);
    		m.put("Jackie", 42);
    		//reassign values:
    		m.put("Chris", 24);

    		//retrieve values using the key:
    		int x = m.get("Chris");
    		System.out.println(x);

    		if(m.containsKey("Chris")) {
    			System.out.println("contains it!");
    		} else {
    			System.out.println("nope!");
    		}

    		Integer y = m.get("Pete");
    		System.out.println(y);

```

```java

		List<String> zipCodes = getData(); //.subList(0, 100);
		//maps are key => value data structures
		Map<String, Integer> m = new HashMap<>();
		//for each element in zipCodes...
		for(String zipCode : zipCodes) {
			//   get the value from the map m
			Integer count = m.get(zipCode);
			//   IF this is the first time, initialize it to 0
			if(count == null) {
				count = 0;
			}
			//   increment the counter and put it back in the map
			count++;
			m.put(zipCode, count);			
		}

		//for each key...
		List<String> orderedZipCodes = new ArrayList<>(m.keySet());
		Collections.sort(orderedZipCodes);
		for(String zipCode : orderedZipCodes) {
			int count = m.get(zipCode);
			System.out.printf("%s => %d\n", zipCode, count);
		}

		//what is the most common and least common zip code (counts) in our data set?
		List<Integer> counts = new ArrayList<>(m.values());
		Collections.sort(counts);
		int minCount = counts.get(0);
		int maxCount = counts.get(counts.size()-1);
		System.out.printf("min/max = %d, %d\n", minCount, maxCount);

		//print all the "minimum count" zip codes:
		for(String zipCode : m.keySet()) {
			int count = m.get(zipCode);
			if(count == minCount) {
				System.out.println("min zip Code: " + zipCode);
			}
			if(count == maxCount) {
				System.out.println("max zip code: " + zipCode);
			}
		}
```

## Pitfalls with Arrays in C

* In C **you** are responsible for *memory management*
* You have to keep track of the size of arrays that you create
* You have to clean up after yourself when you no longer need the memory
* You have to be responsible with the memory

### Arrays & Functions

* When you pass an array to a function, *you also need to pass the size of the array*
* There is ZERO, ABSOLUTELY ZERO way to tell the size of a dynamic array in C!
* Using `sizeof` in any form is *wrong*

* Passing an array as a *return* value *from* a function?
* If so, it *MUST* be a dynamically allocated array (using `malloc()`)

* In both instances: you should protect your data!
* You can make an array `const` to prevent a function from making changes to it!  In general this should *always* be done unless you have a Very Good Reason to change the data

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
* YOu should generally prefer *deep copies*: different and distinct memory locations but the same *content*

### Multidimensional Arrays

* A regular old array is a 1-D array (one dimensional)
* You can have 2-D arrays with *rows* and *columns*
  * matrices
  * table
* YOU *can* have 3D, 4D, etc. arrays, but likely there is a better solution
* In C you specify *two* indices: `table[i][j]` (row `i` and column `j`)
* To setup memory for a 2-D array you need:
  * An array of pointers
  * Each pointer will point to a row

```c
/**
 * Demo Code
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

int sum(const int *arr, int n) {
  int total = 0;
  for(int i=0; i<n; i++) {
    total += arr[i];
    //arr[i] = 42;
  }
  return total;
}

int * getOnesArray(int n) {

  int *result = (int *) malloc( n * sizeof(int) );
  for(int i=0; i<n; i++) {
    result[i] = 1;
  }
  //bad: free(result);
  return result;

}

//look up memcpy
int * deepCopyInt(const int *arr, int n) {
  int *deepCopy = (int *) malloc( n * sizeof(int) );
  for(int i=0; i<n; i++) {
    deepCopy[i] = arr[i];
  }
  return deepCopy;
}

int main(int argc, char **argv) {

  int n = 9;
  int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
  int total = sum(primes, n);
  for(int i=0; i<n; i++) {
    printf("primes[%d] = %d\n", i, primes[i]);
  }
  printf("total = %d\n", total);

  int *ones = getOnesArray(n);
  for(int i=0; i<n; i++) {
    printf("ones[%d] = %d\n", i, ones[i]);
  }

  int *arr = (int *) malloc( 100000 * sizeof(int) );
  arr[0] = 42;
  arr[999] = 101;
  //....

  free(arr);

  //bad: printf("arr[0] = %d\n", arr[0]);

  //free(arr);

  //shallow copy:
  int *b = ones;
  b[0] = 42;
  for(int i=0; i<n; i++) {
    printf("ones[%d] = %d\n", i, ones[i]);
  }
  for(int i=0; i<n; i++) {
    printf("b[%d] = %d\n", i, b[i]);
  }

  //deep copy of the primes array...
  int *deepCopy = (int *) malloc( n * sizeof(int) );
  for(int i=0; i<n; i++) {
    deepCopy[i] = primes[i];
  }
  for(int i=0; i<n; i++) {
    printf("deepCopy[%d] = %d\n", i, deepCopy[i]);
  }
  deepCopy[0] = 101;
  for(int i=0; i<n; i++) {
    printf("primes[%d] = %d\n", i, primes[i]);
  }


}


```


```text









```
