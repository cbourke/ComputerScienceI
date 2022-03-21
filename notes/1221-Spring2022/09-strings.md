
# ECEN 1940 - Computer Science I
## Strings
### Spring 2022

* In C, *strings* are ordered sequences of ASCII characters
* In C, strings are simply null-terminated arrays of character elements (`char`)
* In C, a string *MUST* be null-terminated: it must end with the special character, `\0`
  * It is *NOT* the endline character: `\n`
  * It is NOT zero `'0'`
  * It is NOT `NULL`
* A string is NOT valid in C unless it is null-terminated
* Any operations or other things you do with a string that is invalid are *undefined behavior*
* In C, *all strings must be terminated with the null terminating character!*

## Strings in C


* In C, strings are arrays of `char` elements
* Ex: `char str[10]` or `char *` (NOT `int *`)
* Declaring strings

```c

    //11 is too small to hold the null terminating character:
    //char firstName[11] = "christopher";

    //char firstName[12] = "christopher";
    char firstName[] = "christopher";

    //contents in a string can be changed using the regular array
    // index syntax:
    firstName[0] = 'C';

    //you can print strings using printf and the placeholder: %s
    printf("Hello, %s\n", firstName);

    firstName[5] = '\0';

    printf("Hello, %s\n", firstName);
```

## String Assignments

* Once you have created a static string, you *cannot* reassign it; you can only change individual characters in the array
* To assign a value to a string (place the contents of one string into another string), you use `strcpy()`
* It, along with many other functions that operate on strings can be found in the `string.h` library
  * `char * strcpy ( char * destination, const char * source );`
  * It *assumes* that `destination` is big enough to hold what you are copying!  INCLUDING the null terminating character
  * It *assumes* that the `source` is a valid, null-terminated string
  * It also takes care of the null terminator in the `destination` string for you
  * Note: the second argument/parameter is `const`, the first is not!
* Byte limited version: `strncpy`
  * it only copies the first `n` bytes (characters) in the source string
  * `char *strncpy(char *dest, const char *src, size_t n);`
  * It copies at most `n` characters over to the destination string
  * If the null terminating character occurs within the first `n` characters, it takes care of it for you (copies the null terminator)
  * If it is not within the first `n` characters, it will *NOT* copy the null terminator and YOU NEED TO TAKE CARE OF IT

```c


    //char firstName[20] = "christopher";
    //dynamically allocate enough space:
    char *fullName = (char *) malloc(sizeof(char) * 100);
    int n = strlen(fullName); //invalid
    fullName[0] = '\0'; //empty string
    n = strlen(fullName); //valid, length = 0
    char *firstName = (char *) malloc(sizeof(char) * 12);


    strcpy(fullName, "Christopher Michael Bourke");
    firstName[0] = '\0';
    firstName[11] = '\0';
    strlen(firstName); //valid

    strncpy(firstName, fullName, 11);
    //strncpy does not necessarily take care of the null terminator for you!
    // in this case you must manually take care of it:
    firstName[11] = '\0';

    printf("Hello, %s\n", firstName);

    //you can use pointer arithmetic and strncpy to get *substrings*
    char middleName[8];
    strncpy(middleName, &fullName[12], 7);
    middleName[8] = '\0';
    printf("middle name = %s\n", middleName);
```

## String length

* The length of a string is the number of characters in it, NOT including the null-terminating character
* `strlen` can be used to determine the length of a string

## String Processing

### Concatenation


### Tokenization

* Formatting: Comma Separated Values = CSV
* Each item is a *token*
* Each line is a record
* Splitting up the tokens on each line is called "tokenization"

```text
first,last,nuid,city,state,office
Chris,Bourke,35140602,Omaha,NE,103 Schorr
Bonita,Sharif,1234,Lincoln,NE,105 Schorr
Joe,Smith,5678,Atlanta,GA,120 Foo

```

```text








```
