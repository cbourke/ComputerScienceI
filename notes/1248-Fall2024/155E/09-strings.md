
# CSCE 155E - Computer Science I
## Strings
### Fall 2024

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
* You can declare a string in the same way as you would declare an integer array
* IN C, strings are *mutable*: their contents can be changed!

```c

    char message[] = "hello World!";

    printf("message = %s\n", message);

    message[0] = 'H';

    printf("message = %s\n", message);

    message[12] = '!';

    printf("message = %s\n", message);

    char name[100] = "Christopher Michael Bourke";

    printf("Hello, %s\n", name);

    //unsafe, but probably okay
    name[26] = '!';
    //sometimes you have to manually add the null terminator:
    name[27] = '\0';

    printf("Hello, %s\n", name);

    name[5] = '\0';

    printf("Hello, %s\n", name);

    name[5] = 'X';

    printf("Hello, %s\n", name);

```

* Even though strings are mutable, their *size* cannot be changed (just like arrays)
* You *cannot* assign a string after you have declared it.

## String Assignments

* The string library, `string.h` provides many different functions that operate on strings!
* To *copy* the contents of one string into another, you use `strcpy`
* `char * strcpy ( char * destination, const char * source );`
  * It copies the contents of `source` into `destination`
  * It is *assumed* that `destination` is big enough to hold the source
  * It is *assumed* that the `source` is a valid, null-terminated string
  * If not: bad things happen (Segmentation faults, stack smashing, etc.)
  * Ultimately, however, it does copy the null-terminator character for you
  * `const` ensures the function does not change the `source`
  * The lack of `const` in the `destination` implies it will change the contents!
* Another useful function: `strcat`
  * `cat` = concatenation: to append one string to the end of another string
  * `char * strcat ( char * destination, const char * source );`
  * It has the same assumptions as `strcpy`
  * It will take the contents of `source` and *append* (add to the end) to `destination`

## Dynamic Strings

* Static strings are fine, but we have the same problems and limitations as static arrays
* `strlen` can be used to determine the length of a string: it returns the number of characters *NOT* including the null terminating character

```c
/**
 * Demonstration code template.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char * deepStringCopy(const char *s);

/**
 * Converts the given string so that all characters are uppercase
 * For example, "goodbye" -> "GOODBYE"
 */
void toUpperCase(char *s);

int main(int argc, char **argv) {

    //cannot use static strings for "large" strings
    //    char novel[100000000] = "Once upon a time...";
    int n = 100000000;
    char *novel = (char *) malloc( sizeof(char) * n );
    strcpy(novel, "Once upon a time...");

    printf("my novel = %s\n", novel);

    //strlen computes the length of a string, not including the null terminator
    int m = strlen(novel);
    printf("length of string: %d\n", m);

    char name[] = "Christopher";
    //shallow copy
    char *copyOfName = name;
    printf("copy of my name = %s\n", copyOfName);

    //deep copy:

    copyOfName = deepStringCopy(name);
    printf("copy of my name = %s\n", copyOfName);

    toUpperCase(novel);
    printf("my novel = %s\n", novel);

    free(copyOfName);
    free(novel);

}

char * deepStringCopy(const char *s) {

    char *copy = (char *) malloc( (strlen(s) + 1) * sizeof(char) );
    strcpy(copy, s);
    return copy;
}

void toUpperCase(char *s) {
  for(int i=0; i<strlen(s); i++) {
    if( islower(s[i]) ) {
      s[i] = toupper(s[i]);
    }
  }
}
```

```text










```
