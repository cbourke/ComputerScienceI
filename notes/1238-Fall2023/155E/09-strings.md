
# CSCE 155E - Computer Science I
## Strings
### Fall 2023

* In C, *strings* are ordered sequences of ASCII characters
* In C, strings are simply null-terminated arrays of character elements (`char`)
* In C, a string *MUST* be null-terminated: it must end with the special character, `\0`
  * This is *NOT* the endline character: `\n`
  * This is *NOT* the same thing as `NULL` (pointer)
  * It is NOT zero `0` it is not the ASCII character `'0'`
* A string is NOT valid in C unless it is null-terminated
* Any operations or other things you do with a string that is invalid are *undefined behavior*
* In C, *all strings must be terminated with the null terminating character!*

## Strings in C

* Strings are simply arrays of `char` elements
* You can declare a string very similar to how you delcared arrays of integers or doubles

```c
char name[10] = "chris";

//create a string large *enough* (+1 for the null terminator)
char name[] = "Christopher";

//you can create strings that are even bigger:
char name[100] = "Christopher Michael James Bourke";
```

* You can use the `%s` placeholder in `printf` to print strings

```c

printf("name = %s\n", name);


```

* You can also "truncate" a string by setting any of its characters to the null terminating character:

```c
char name[] = "Christopher";
  name[5] = '\0';

  printf("name = %s\n", name);

  name[5] = 't';
  printf("name = %s\n", name);
```

* Strings are *mutable*: their contents can be changed
* The size of the array CANNOT be changed; it does not grow or shrink at all

* You *cannot* assign a string after you have declared it.

## String Assignments

* The string library, `string.h` provides many different functions that make operating on strings easy
* To *copy* the contents of one string into another, you use `strcpy`
* `char * strcpy ( char * destination, const char * source );`
  * You are copying into the `destination` string
  * It is assumed that the `destination` string is big enough to hold the `source` string
  * If not: bad things happen (Segmentation faults, stack smashing, etc.)
  * It copies *from* the `source` which is assumed to be null-terminated
  * Ultimately it copies over the null terminator for you!
  * Observe: the `source` is `const`
* `char * strcat ( char * destination, const char * source );`
  * It *concatenates* the `source` string to the *end* of the `destination` string
  * Same assumptions as `strcpy`

```text













```
