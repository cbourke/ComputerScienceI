
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

## String Processing

* Strings can be manipulated character-by-character
* The `ctype.h` library provides many other useful functions for single characters:
  * `isalpha(char c)` - true if `c` is an alpha-numeric character
  * `isspace(char c)` - true if `c` is a space character (` , \t, \n, \r`)
  * `isupper(c), islower(c)` - true if `c` is an uppercase or lowercase character
  * `toupper(c), tolower(c)` - convert to the lower/upper equivalent
  * `isdigit(c)` - true for 0 - 9

### Formatting

* `printf` will format a result to the standard output
* `sprintf` will format a result to a *string*

```c
    int x = 42;
    double y = 3.14;
    char c = 'C';

    char buffer[1000];
    sprintf(buffer, "x = %d, y = %20.2f, c = %c, str = %s\n", x, y, c, str);

    printf("buffer = %s\n", buffer);
```

### Substrings

* A substring of a string is a part of it (may begin inside the string)
* For example: `"Husker"` is a substring of `"Go Husker Football!!"`
* Goal: write a function that returns a substring of a given string

### Byte Limited Versions

* `strcpy` and `strcat` both copy/concatenate the entire string (beginning to end)
* `strncpy` and `strncat` are *byte-limited* versions of copy/concatenate
  * Each takes a third argument: `n` and copies/concats *at most* `n` characters/bytes
  * If it sees the null-terminating character before `n` bytes, it stops and copies `\0` for you!
  * HOwever, if it does *not* see the null-terminator in the first `n` bytes, it **does not insert it for you!**

```c

  char str[] = "Go Husker Football!!";
  char result[100];

  //type of str: char * (a string)
  //want to start at index 3: str[3]
  //type of str[3]: char (a single character: we've dereferenced it!)
  //strcpy needs a string to copy from
  //regular variable -> pointer: &
  char *startingString = &str[3];
  strncpy(result, startingString, 6);
  result[6] = '\0';
```

```c
/**
 * Demonstration code template.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * Given startIndex and a length, returns a new string starting at the given
 * index and of the given length
 *
 */
char *getSubstring(const char *s, int startIndex, int length);

/**
 * This function creates a new string (copy) of the given string with all
 * whitespace removed.
 *
 * Example: "Go Husker Football!!" => "GoHuskerFootball!!
 */
char *removeWhitespace(const char *s);

int main(int argc, char **argv) {

    char str[] = "Go Husker Football!!";

    char *substr = getSubstring(str, 3, 6);
    printf("substr = \"%s\"\n", substr);
    free(substr);

    substr = getSubstring(str, 10, 8);
    printf("substr = \"%s\"\n", substr);
    free(substr);

    char *noWhiteSpace = removeWhitespace(str);
    printf("noWhiteSpace = \"%s\"\n", noWhiteSpace);
    free(noWhiteSpace);


    return 0;

}

char *getSubstring(const char *s, int startIndex, int length) {

  //TODO: think about others
  if(s == NULL || startIndex < 0 || startIndex >= strlen(s)) {
    return NULL;
  }

  char *newStr = (char *) malloc( sizeof(char) * (length + 1) );

  //copy over s to newStr but of given length starting at the given startIndex
  strncpy(newStr, &s[startIndex], length);
  newStr[length] = '\0';

  return newStr;

}

char *removeWhitespace(const char *s) {
    //TODO: error handling

    //1. create a new string (that is the correct size?)
    //1a How many characters are going to be removed?
    int numSpaces = 0;
    for(int i=0; i<strlen(s); i++) {
        if( isspace(s[i]) ) {
            numSpaces++;
        }
    }
    char *result = (char *) malloc( sizeof(char) * (strlen(s) - numSpaces + 1) );
    int j = 0;
    for(int i=0; i<strlen(s); i++) {
        if( !isspace(s[i]) ) {
            //copy it over
            result[j] = s[i];
            j++;
        }
    }
    result[j] = '\0';
    return result;

}

```

```text










```
