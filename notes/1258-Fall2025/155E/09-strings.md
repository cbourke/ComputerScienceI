
# CSCE 155E - Computer Science I
## Strings
### Fall 2025

* In C, *strings* are ordered sequences of ASCII characters
* In C, strings are simply null-terminated arrays of character elements (`char`)
* In C, a string *MUST* be null-terminated: it must end with the special character, `\0`
  * It is NOT the character zero: `'0'`
  * This is *NOT* the endline character: `\n`
  * This is *NOT* the same thing as `NULL` (pointer)
  * It is NOT teh same thing as the number zero: `0`
* A string is NOT valid in C unless it is null-terminated
* Any operations or other things you do with a string that is invalid are *undefined behavior*
* In C, *all strings must be terminated with the null terminating character!*

## Strings in C

* You can declare strings statically or dynamically just as you did with arrays
* IN C, strings are *mutable*: their contents can be changed!


```c

    char message[] = "hello World!";

    printf("message = %s\n", message);

    //change the first character:
    message[0] = 'H';

    printf("message = %s\n", message);

    //undefined behavior: out of bounds!
    //message[12] = '!';
    //printf("message = %s\n", message);

    char fullName[100] = "Christopher Michael Bourke";

    printf("Hello, %s\n", fullName);
    fullName[26] = ' ';
    fullName[27] = 'J';
    fullName[28] = 'r';
    fullName[29] = '.';
    fullName[30] = '\0';
    printf("Hello, %s\n", fullName);

    fullName = "Christopher Michael Bourke Jr.";

```

## String Assignments

* The string library, `string.h` provides many different functions that operate on strings!
* You cannot reassign an entire string after its declaration
* Instead, you have to use a function: `strcpy`
* `char * strcpy ( char * destination, const char * source );`
  * It copies the contents of `source` into `destination`
  * It is *assumed* that `destination` is big enough to hold the source
  * It is *assumed* that the `source` is a valid, null-terminated character
  * If not: bad things happen (seg fault, stack smashing, etc. - undefined behavior)
  * Ultimately, however, it does copy the null-terminator character for you
  * `const` ensures the function does not change the `source`
  * The lack of `const` in the `destination` implies it will change the contents!

## String Concatenation

* Concatenation: appending one string to the end of another
* Another useful function: `strcat`
* `char * strcat ( char * destination, const char * source );`
  * It has the same assumptions as `strcpy`
  * It will take the contents of `source` and *append* (add to the end) to `destination`, including the null terminating character

```c

    char fullName[100] = "Christopher Michael Bourke";

    printf("Hello, %s\n", fullName);

    strcat(fullName, " ");
    strcat(fullName, "Jr.");

    printf("Hello, %s\n", fullName);

```

## Dynamic Strings

* Static strings are fine, but have the same problems as static arrays: small, declared on the stack, etc.
* Dynamic strings can be allocated on the heap using `malloc`
* Just make sure that the size *includes* one more for the null-terminator!

```c
char *fullName = (char *) malloc( sizeof(char) * (26 + 1) );

strcpy(fullName, "christopher Michael Bourke");

fullName[0] = 'C';

printf("Hello, %s\n", fullName);

free(fullName);
```

# Demo

```c
/**
 * Chris Bourke
 *
 * Demo Code
 */
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <math.h>

/**
 * Creates and returns a new deep copy of the given string.
 */
char *copyStr(const char *s);

/**
 * Counts the number of characters (not including the null terminator)
 * in the given string and returns the result
 */
int stringLength(const char *s);

int main(int argc, char **argv) {

    char s[] = "hello World";
    char *c = copyStr(s);
    s[0] = 'H';

    printf("s (original) = %s\n", s);
    printf("c (copy)     = %s\n", c);

    return 0;
}

int stringLength(const char *s) {
    if(s == NULL) {
        return 0;
    }
    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    return i;
}

char *copyStr(const char *s) {

    if(s == NULL) {
        return NULL;
    }

    int n = strlen(s);
    char *copy = (char *) malloc( sizeof(char) * (n+1) );
    strcpy(copy, s);
    return copy;

}

```

## String Processing

* Strings can be manipulated character-by-character
* The `ctype.h` library provides many other useful functions for single characters:
  * `isalpha(char c)` - true if `c` is an alpha-numeric character `A-Z, a-Z, 0-9`
  * `isspace(char c)` - true if `c` is a space character (` , \t, \n, \r`)
  * `isupper(c), islower(c)` - true if `c` is an uppercase or lowercase character
  * `toupper(c), tolower(c)` - convert to the lower/upper equivalent
  * `isdigit(c)` - true for 0 - 9

```text
















```
