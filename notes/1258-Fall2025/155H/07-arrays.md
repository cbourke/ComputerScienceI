
# CSCE 155H - Computer Science I - Honors
## Arrays & Collections
### Fall 2025

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

    //static array of integers of size 10:
    int arr[10];
    //set the first and last values:
    arr[0] = 42;
    arr[9] = 123;
    //it is best to keep track of the size of an array:
    int n = 10;

    //an array to hold 20 doubles:
    double brr[20];

    //what values are stored in arr at this point?
    //iterate over arr to find out:
    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    for(int i=0; i<n; i++) {
        arr[i] = (i + 1) * 10;
    }

    for(int i=0; i<n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }


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
  * You can treat `size_t` as an integer (you are asking for `n` bytes)
  * The return value is a "generic void pointer"
  * A generic void pointer is a raw memory address, it can point to *any* type of data
  * The returned memory can be used for whatever you want it to be
  * Generally when we receive the pointer, we'll *cast* it as the type that we intend to use it as

## Java

* No pointers in Java, no static arrays
* All arrays are allocated on the heap
* Demo:

```java

		//no static arrays in Java
		int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};

		//dynamic arrays use the *new* keyword:
		int arr[] = new int[10];
		//in Java there is a well-defined default value of: zero!

		arr[0] = 42;
		arr[arr.length-1] = 123;

		for(int i=0; i<arr.length; i++) {
			System.out.printf("arr[%d] = %d\n", i, arr[i]);
		}

		System.out.println(Arrays.toString(arr));

		//neato: enhanced for loop or "for each loop"
		for(int x : arr) {
			System.out.println(x);
		}

```

* In Java, we're immediately going to abandon arrays


```text







```
