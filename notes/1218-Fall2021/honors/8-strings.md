
# CSCE 155H - Computer Science I
## Strings
### Fall 2021

* Strings are ordered sequences of characters (may be ASCII or Unicode)
* Different languages represent strings differently
* Most languages provide a standard library of functions to manipulate and process strings

## Strings in C

* In C, strings are simply arrays of characters, ie `char` array
* In C you can have static strings, `char s[]` or better, dynamic strings: `char *s;`
* ***But***: for a string to be valid in C, it *must* be ended (terminated) with a null-terminating character, `'\0'`
  * It is not the same thing as zero
  * It is not the same thing as the zero character: `'0'`
  * It is not `void`, it is not `NULL`
  * It is not the space, it is not the endline character, `\n`
* If an array of characters is *not* null-terminated, it is *not* a valid string and any operation on it is undefined behavior

```c
//create a static array of characters, ie a string:
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
name[0] = 'C';

//print the string:
printf("Hello, %s\n", name);

```

## String assignments

* after the initial declaration, you can manipulate individual characters in a string, BUT
* you cannot reassign the entire contents of a string using the usual assignment operator, `=`
* Instead, you can use the string library's `strcpy`
* The string library is in `string.h`
* `char *strcpy(char *dest, const char *src);`
  * First argument: the *destination*, the string you are copying *to*
  * Second argument: the source, what you are copying from
  * The second argument is read-only!
  * The order is similar to the assignment operator: you take the right one and put it into the left one
  * This function *assumes* that `dest` is big enough to hold the source string
  * This function *assumes* that the source string is a valid, null-terminated string
  * `strcpy` *will* copy the null terminator for you

```c
char fullName[100];
strcpy(fullName, "Christopher");
```

* Another useful function: `strlen`: it returns an integer indicating the number of characters, *not including the null-terminator*

### Another operation: String Concatenation

* you can concatenate (combine) two strings using `strcat`
* `char *strcat(char *dest, const char *src);`
  * It appends the contents of `src` to the end of the `dest` string
  * It assumes that `dest` is large enough, it assumes that `src` is properly null terminated
  * If so, it takes care of the null terminator for you

### Byte Limited Versions  

  * There is also `strncpy` and `strncat` that take a third argument: the maximum number of characters to copy/concatenate
  * IF either function sees the null terminating character within the first `n` bytes, it will be copied over
  * Otherwise, the null terminator will NOT be copied over: ***It becomes your responsibility to do so***
  * This is very useful to copy *substrings*

```c

    char fullName[100];
    strcpy(fullName, "Christopher M. Bourke");
    char shortName[6];
    //copy only the first 5 bytes of fullName:
    strncpy(shortName, fullName, 5);
    //take care of the null terminator:
    shortName[5] = '\0';

    //you can also use strcat/strcopy to get a substring:
    char team[] = "Nebraksa Cornhuskers";
    char shortTeam[100];
    //team[9] is where "Cornhuskers" begins...
    strncpy(shortTeam, &team[9], 4);
    shortTeam[5] = '\0';
    printf("shortTeam = %s\n", shortTeam);

```

## Other useful things

* The `string.h` library has several dozen other functions: RTM
* The `ctype.h` library has a lot of useful functions for individual characters:
  * `isspace(c)` is true if `c` is a space character (` , \n, \t`, etc.)
  * `isupper(c)` or `islower(c)`
  * Convert: `toupper(c)` `tolower(c)`
  * etc. RTM!

## Strings in Java

* Strings in Java are "built-in": you have a class `String`

## Strings in Java

* Strings in Java are "built-in": you have a class `String`
* You also have a "string library" (a collection of methods that can manipluate strings)
* Java strings are *NOT* null terminated: don't use the null terminator in Java!
* In Java, strings are *immutable*: once created, their contents *cannot be changed*




```text





```
