
# CSCE 155H - Computer Science I
## Strings
### Fall 2022

* Strings are ordered sequences of characters (may be ASCII or Unicode)
* Different languages represent strings differently
* Most languages provide a standard library of functions to manipulate and process strings


## Strings in C

* In C, strings are simply arrays of characters: `char` (ASCII *only*)
* In C you can have static strings, `char s[]` or better, dynamic strings: `char *s;`
* ***BUT***: for a string to be *valid* in C, it ***MUST*** end (be terminated) with a null terminating character: `\0`
  * It is NOT zero, `0`
  * It is NOT the character `'0'`
  * It is NOT `NULL` (it is not a pointer!)
  * It is not `void`, etc. etc. etc.
  * It is not the endline character! `\n`
* If an array of `char`s is not null-terminated, it is NOT a valid string and any operation on it is *undefined behavior*

```c
//create a static array of characters; ie a string:
char message[] = "hello World!";

```

* In the example above, the compiler will take care of the null terminator for you
* So the actual size of the array is 13 (1 additional to account for the null terminator)

```c
char name[100] = "chris";
```

* You *can* create arrays that are larger and "waste space"
* In C, all strings are *mutable*: you can change their contents


```c

  char name[100] = "chris";
  printf("name = %s\n", name);
  name[0] = 'C';
  name[5] = 'o';
  name[6] = 'p';
  name[7] = 'h';

  //this will not work:
  //name = "Christopher";

  //this will:
  strcpy(name, "Christopher");

  printf("name = %s\n", name);

```

## String assignments

* after the initial declaration, you can manipulate individual characters in a string, BUT
* you cannot reassign the entire contents of a string using the usual assignment operator, `=`
* Instead, you must use the string library's `strcpy` function
* The string library is in `string.h`
* `char *strcpy(char *dest, const char *src);`
  * copies the contents of `src` into the string `dest` (right-to-left, just like the assignment operator!)
  * The `const` in front of the `src` string indicates *no changes* will be made to `src`
  * The lack of a `const` in the `dest` means it *will* be changed
  * It is *your responsibility* to ensure that the `src` string is a valid string
  * It is *your responsibility* to ensure that the `dest` string is big enough to hold the source PLUS the null terminating character!

## Other Basic Operations

* You can determine how long a string is (the number of characters in it) using: `strlen()`
  * It only works on valid strings
  * It does *not* include the null terminating character

### Concatenation

* String concatenation simply means appending one string to the end of another string
* To do this in C, you use a function: `strcat()`
* `char *strcat(char *dest, const char *src);`
  * It appends the `src` string to the *end* of the `dest` string
  * It assumes that *both* are valid strings
  * It will take care of the null terminating character for you
  * It assumes that the `dest` is big enough to hold both strings!

### Byte Limited Versions  

* There is also `strncpy` and `strncat` that take a third argument: the maximum number of characters to copy/concatenate
* IF either function sees the null terminating character within the first `n` bytes, it will be copied over and it will end its copying (it only copies "at most" $n$ bytes, it stops either at $n$ bytes or the null terminating character!)
* Otherwise, the null terminating character becomes *your* responsibility
* It can be used to create *substrings*!




```text









````
