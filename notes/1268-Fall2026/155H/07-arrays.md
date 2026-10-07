
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

```text












```
