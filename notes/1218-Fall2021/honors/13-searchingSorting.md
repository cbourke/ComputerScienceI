
# CSCE 155H - Computer Science I
## Algorithms, Searching & Sorting
### Fall 2021

# Introduction & Demonstration

* Huge part of Computer Science: data processing
* Fundamental operations: *searching*, *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed

## Linear Search

* Basic Idea; given a collection of elements and a key element $k$, search through the collection to find any element that "matches" $k$
* What are you searching?  An array, a list, set
* What is it a collection of? Integers, doubles, strings, airports, etc.
* How are you searching?
* Searching for a particular element or the first or the last, max or the min, or all elements that match your search criteria
* More generally: you take an algorithm perspective and design *pseudocode*

### Analysis

* A linear algorithm performs a number of operations (for our purposes, we'll focus on comparisons)
* Best case scenario: it takes 1 comparison (finds it at index 0)
* Worst case scenario: $n$ comparisons (for a collection of size $n$); happens when it is at index $n-1$ or unsuccessful search
* Average case: you make about $\approx \frac{n}{2}$ comparisons
* Can we do better?

## Binary Search

* Suppose that the input array is sorted
* Being sorted gives the array *structure*; structure can be exploited
* Search for the key $k$ in a sorted array
* Look at the middle element: $m$
  * If it is equal to your key, you are done: success
  * If the key is less than the middle element $k < m$: search in the lower/left half
  * If the key is greater than the middle element: $m < k$: search in the upper (right) half
  * until you either find it or you have an array of size 0 (unsuccessful search)
* This is a divide and conquer style algorithm that *may* be implemented recursively

## Searching and Sorting in Practice

* In general you do not write your own searching/sorting algorithms
* You use one built-in generic sorting/searching algorithm/function/method
* However, the built-in functionality is *generic* so it doesn't know what the elements are or how to compare them.
* You also need to define a *comparator function* (C) or a `Comparator` in Java

### Comparators in C

* In C, a *comparator function* is a function that compares two  generic elements $a, b$ and returns:
  * it returns *something* negative if a < b
  * it returns zero if a is equal to b
  * it returns *something* positive if a > b (b < a)
* In C the signature of a comparator function *MUST* Be:

`int cmp(const void *a, const void *b)`

* returns an integer
* takes two arguments
* both use `const` and so are unchangeable
* both are *generic void pointers*
* Inside the function you follow a general pattern:
  * You cast the generic void pointers as the actual types that you are comparing
  * You setup a if-else statement to return something negative, zero, or something positive depending on the relative ordering of your arguments
* Exercise: write a comparator function for integers that orders them in increasing order.

### `Comparator`s in Java

* Typically you define an *anonymous* in-line class

```java
List<Integer> numbers = ...;

Comparator<Integer> cmpInt = new Comparator<Integer>() {

  public int compare(Integer a, Integer b) {
     if(a < b) {
       return -1;
     } else if(a > b) {
       return 1;
     } else {
       return 0;
     }
     return a.compareTo(b);
  }

};

Collections.sort(numbers, cmpInt);

```

### Understanding Comparators: Function Pointers

* In a computer, everything is stored in memory:
  * Data
  * Files
  * Programs
* You can create a pointer that points to a specific function in your program

```c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int foo(double x, int y, char c) {
    return 0;
}

double funMath(double input, double (*f)(double)) {
  return f(input);
}


int main(int argc, char **argv) {

  //an integer and integer pointer:
  int x = 42;
  int *ptrToX = &x;

  //create a pointer to a function that returns an integer and
  // takes 3 arguments: double, int, char
  int (*ptrToFunc)(double, int, char);
  ptrToFunc = &foo;
  //or better, shorter, equivalent:
  ptrToFunc = foo;
  //invalid/warning:
  //ptrToFunc = sin;

  double (*ptrToSin)(double);
  ptrToSin = sin;

  double y = sin(3.14159);
  printf("y = %f\n", y);

  y = ptrToSin(3.14159);
  printf("y = %f\n", y);

  //printf("the function sin is stored at memory location %p\n", ptrToSin);
  y = funMath(3.14159, sin);
  printf("y = %f\n", y);

  y = funMath(3.14159, cos);
  printf("y = %f\n", y);

  y = funMath(3.14159, tan);
  printf("y = %f\n", y);

  y = funMath(3.14159, sqrt);
  printf("y = %f\n", y);

}
```

### Sorting in C

* C provides a standard "quick sort" implementation

```c
void qsort(void *base,
           size_t nel,
           size_t size,
           int (*compar)(const void *, const void *));
```

* `void *base` is the array you are sorting
* `nel` is the number of elements
* `size` is the number of bytes each element takes
* `compar` is a *function pointer*; a reference to the comparator you want to use!  


### Searching in C

```c
void *bsearch(const void *key,
              const void *base,
              size_t nmemb,
              size_t size,
              int (*compar)(const void *, const void *));
```

* Returns a pointer to a matching element if found
* If no such element is found, returns `NULL`
* `bsearch` does not make changes to the array (it is `const`)
* The first argument is a key that you are searching for

Demo
```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * This comparator orders student structres in
 * ascending order with respect to last name/first name
 */
int cmpStudentByName(const void *a, const void *b) {
  const Student *x = (const Student *) a;
  const Student *y = (const Student *) b;

  int result = strcmp(x->lastName, y->lastName);
  if(result == 0) {
    //same last name, look now to the first:
    return strcmp(x->firstName, y->firstName);
  } else {
    return result;
  }
}

/**
 * This comparator orders integer in ascending order
 */
int cmpInt(const void *a, const void *b) {
  //1. cast the pointers into the *expected type*:
  const int *x = (const int *) a;
  const int *y = (const int *) b;

  if( *x < *y ) {
    return -1;
  } else if( *x > *y ) {
    return 1;
  } else {
    return 0;
  }
}

/**
 * This comparator orders doubles in ascending order
 */
int cmpDouble(const void *a, const void *b) {
  //1. cast the pointers into the *expected type*:
  const double *x = (const double *) a;
  const double *y = (const double *) b;

  if( *x < *y ) {
    return -1;
  } else if( *x > *y ) {
    return 1;
  } else {
    return 0;
  }
}

/**
 * This comparator orders integer in descending order
 */
int cmpIntDesc(const void *a, const void *b) {
  return cmpInt(b, a);
}

int main(int argc, char **argv) {

  int n = 9;
  int numbers[] = {42, 4, 9, 4, 102, 34, 12, 2, 0};
  for(int i=0; i<n; i++) {
    printf("%d, ", numbers[i]);
  }
  printf("\n");

  qsort(numbers, n, sizeof(int), cmpInt);
  for(int i=0; i<n; i++) {
    printf("%d, ", numbers[i]);
  }
  printf("\n");

  qsort(numbers, n, sizeof(int), cmpIntDesc);
  for(int i=0; i<n; i++) {
    printf("%d, ", numbers[i]);
  }
  printf("\n");


  qsort(numbers, n, sizeof(int), cmpDouble);
  for(int i=0; i<n; i++) {
    printf("%d, ", numbers[i]);
  }
  printf("\n");


  //for binary search to work it needs to be sorted with the
  //  **SAME** comparator!!
  qsort(numbers, n, sizeof(int), cmpIntDesc);
  //search for 42:
  int key = 42;
  int *result = bsearch(&key, numbers, n, sizeof(int), cmpDouble);
  if(result == NULL) {
    printf("no such element %d exists\n", key);
  } else {
    printf("element found at memory address %p containing value %d\n", result, *result);
  }


}
```

Demo - Java
```java
package unl.cse;

import java.time.LocalDate;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Demo {

	public static void main(String args[]) {

		List<Integer> numbers = Arrays.asList(42, 4, 9, 4, 102, 34, 12, 2, 0);

		Comparator<Integer> cmpInt = new Comparator<>() {

			@Override
			public int compare(Integer a, Integer b) {
				return a.compareTo(b);
//				if(a < b) {
//					return -1;
//				} else if(a > b) {
//					return 1;
//				} else {
//					return 0;
//				}
			}

		};

		Comparator<String> cmpStringDesc = new Comparator<>() {

			@Override
			public int compare(String o1, String o2) {
				return o2.compareTo(o1);
			}

		};

		System.out.println(numbers);
		Collections.sort(numbers, cmpInt);
		System.out.println(numbers);
		Collections.sort(numbers);

		List<String> names = Arrays.asList("Zoe", "Adam", "Bob", "Alice");
		Collections.sort(names);
		System.out.println(names);
		Collections.sort(names, cmpStringDesc);
		System.out.println(names);

		int result = Collections.binarySearch(numbers, 42);
		System.out.println(result);

		result = Collections.binarySearch(numbers, 421);
		System.out.println(result);

		result = Collections.binarySearch(names, "Adam");
		System.out.println(result);

		result = Collections.binarySearch(names, "Adam", cmpStringDesc);
		System.out.println(result);

//		result = Collections.binarySearch(names, "Adam", cmpInt);
//		System.out.println(result);

		Comparator<Student> cmpStudentByName = new Comparator<>() {

			@Override
			public int compare(Student a, Student b) {

				int result = a.getLastName().compareTo(b.getLastName());
				if (result == 0) {
					// same last name, look now to the first:
					return a.getFirstName().compareTo(b.getFirstName());
				} else {
					return result;
				}
			}

		};

		Comparator<Student> c = Comparator
				.comparing(Student::getLastName)
				.thenComparing(Student::getFirstName)
				.thenComparing(Student::getAge);

	}
}

```

```text






```
