
# ECEN 194 - Computer Science I
## Strings
### Fall 2022


* In C, *strings* are ordered sequences of ASCII characters
* In C, strings are simply null-terminated arrays of character elements (`char`)
* At the end of every string there *must* be a null-terminating character: `\0`
  * It is *NOT* the same thing as `NULL`
  * It is not the same things `'0'`
  * It is *NOT* the endline character: `\n`
* A string is NOT valid in C unless it is null-terminated
* Any operations or other things you do with a string that is invalid are *undefined behavior*
* In C, *all strings must be terminated with the null terminating character*

## String Library

### String Assignments

* Once you have created a static string, you *cannot* reassign it; you can only change individual characters in the array
* To assign a value to a string (place the contents of one string into another string), you use `strcpy()`
* It, along with many other functions that operate on strings can be found in the `string.h` library
* Signature:

`char * strcpy(char *destination, const char *source);`
* It copies the contents of the `source` string into the `destination` string
* Assumptions: it assumes that `source` is a valid, null-terminated string (it *does* take care of copying the null-terminating character for you)
* Assumption: the `destination` string is big enough to store the `source` and the null terminating string!
* Observe: the use of the `const` keyword:

### String Length

* You can use the `strlen()` function to determine the length of a string
* It does *not* include the null terminating character!

### Concatenation

* The operation of "concatenating" strings means that one string is *appended* to the end of another
* In the C string library you can use `strcat()`
* Signature:

`char * strcat(char *destination, const char *source);`

* It appends the `source` string to the end of the `destination` string
* Same assumptions: `source` and `destination` are assumed to be valid strings; it assumes that `destination` is big enough to hold *both* strings

### Byte-Limited Versions

* For both `strcpy()` and `strcat()` have "byte-limited" versions: you can specify a third argument to limit the number of characters copied or concatenated
* `strncpy(a, b, n)`: copy the string `b` into `a` but only the first `n` characters
* `strncat(a, b, n)`: similar in that it only concatenates at most `n` bytes
* If either one does *not* see the null terminating character, in the first `n` bytes, it will not be copied; *it is on you to take care of it*!

```c

    char fullName[100];

    strcpy(fullName, "Christopher");
    printf("fullName = %s\n", fullName);
    strcat(fullName, " Michael");
    printf("fullName = %s\n", fullName);
    strcat(fullName, " Bourke");
    printf("fullName = %s\n", fullName);

    char first[6];
    strncpy(first, fullName, 5);
    //strncpy does not necessarily take care of the null terminator for you; you
    // MAY need to handle it yourself!
    first[5] = '\0';
    printf("first = %s\n", first);
```

* You can get substrings by indexing and then referencing:
* `&s[12]` gives you a string starting at index 12 (13th characcter)

```c
char fullName[100] = "Christopher Michael Bourke";
//fulName is a char * => char (indexing) => char *

char first[6];
strncpy(first, fullName, 5);
//strncpy does not necessarily take care of the null terminator for you; you
// MAY need to handle it yourself!
first[5] = '\0';
printf("first = %s\n", first);

char middle[8];
//want is "Michael"
strncpy(middle, &fullName[12], 7);
middle[7] = '\0';
printf("middle = %s\n", middle);
```

## String Comparisons

```c
    char a[] = "apple";
    char b[] = "apples";

    //using the == comparison for strings compares memory addresses
    // NOT the contents
    if(a == b) {
        printf("%s is equal to %s (using ==) \n", a, b);
    } else {
        printf("%s are NOT equal to %s (using ==) \n", a, b);
    }

    //you can use the strcmp function to compare the *contents* of strings:
    int result = strcmp(a, b);
    //it returns *something* negative if a < b
    if(result < 0) {
        printf("%s comes before %s (using strcmp)\n", a, b);
    } else if(result == 0) {
        //returns 0 if a = b
        printf("%s is equal to %s (using strcmp)\n", a, b);
    } else if(result > 0) {
        //returns *something* positive if a > b
        printf("%s comes after %s (using strcmp)\n", a, b);
    }

    //strcmp is NOT dictionary order; it is LEXICOGRAPHIC order: ASCII text table
    //strcasecmp can be used to ignore the case (lower/upper):
    result = strcasecmp(a, b);
    //it returns *something* negative if a < b
    if(result < 0) {
        printf("%s comes before %s (using strcasecmp)\n", a, b);
    } else if(result == 0) {
        //returns 0 if a = b
        printf("%s is equal to %s (using strcasecmp)\n", a, b);
    } else if(result > 0) {
        //returns *something* positive if a > b
        printf("%s comes after %s (using strcasecmp)\n", a, b);
    }

    //strncmp can be used to compare strings using a byte-limited version
    result = strncmp(a, b, 3);
    //it returns *something* negative if a < b
    if(result < 0) {
        printf("%s comes before %s (using strncmp using 3 letters)\n", a, b);
    } else if(result == 0) {
        //returns 0 if a = b
        printf("%s is equal to %s (using strncmp using 3 letters)\n", a, b);
    } else if(result > 0) {
        //returns *something* positive if a > b
        printf("%s comes after %s (using strncmp using 3 letters)\n", a, b);
    }
```

## Dynamic Strings

* Recall that static arrays are VERY LIMITED

### Other Convenience Functions

* The `ctype.h` library provides many other useful functions for single characters
  * `isspace(c)` returns true if `c` is a whitespace character
  * `isupper(c)` returns true if `c` is an uppercase letter
  * `islower(c)` returns true if `c` is a lowercase letter
  * `toupper(c), tolower(c)` return the upper/lower case version of `c`, returns `c` itself if it is not a letter
  * `isdigit(c)` true for 0-9

### Tokenization

* Formatting: Comma Separated Values = CSV
* Each item is a *token*
* Each line is a record
* Splitting up the tokens on each line is called "tokenization"

```text
first,last,nuid,city,state,office
Chris,Bourke,35140602,Omaha,NE,103 Schorr
Margaret,Hamilton,1234 A Street,Lincoln,NE,105 Schorr
Joe,Smith,5678,Atlanta,GA,120 Foo

```

* You can tokenize a string based on any *delimiter* using `strtok`


```c
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

char *deepStringCopy(const char *original) {

  int n = strlen(original);
  char *copy = (char *) malloc( sizeof(char) * (n + 1) );
  strcpy(copy, original);

  return copy;
}

char *removeAllWhitespaceCopy(const char *s) {
  //TODO: implement
  return NULL;
}

/**
 * This function takes a string s and modifies it by removing
 * all whitespace from it.
 *
 * Ex: " H e\tl l\no  " => "Hello"
 */
void removeAllWhitespace(char *s) {

  if(s == NULL) {
    return;
  }

  int n = strlen(s);
  char *temp = (char *) malloc( sizeof(char) * (n + 1) );
  int j = 0;
  for(int i=0; i<n; i++) {
    if( !isspace(s[i]) ) {
      temp[j] = s[i];
      j++;
    }
  }
  //null terminate it manually:
  temp[j] = '\0';

  strcpy(s, temp);
  free(temp);

  return;
}

/**
 * iterates through the given string s and counts up the number
 * of occurrences of the given character c
 */
int countChars(const char *s, char c) {

  if(s == NULL) {
    return 0;
  }

  int count = 0;
  int i=0;
  while( s[i] != '\0' ) {
    if(s[i] == c) {
      count++;
    }
    i++;
  }

  return count;

}

/**
 * This function takes a string s and two index values, start and
 * end and creates and returns a new string that is the sub string of s
 * containing characters from [start, end]
 *
 * "Hello World!!" (start = 6, 10) would give back "World"
 */
char *getSubstring(const char *s, int start, int end) {

  if(s == NULL) {
    return NULL;
  }
  int n = strlen(s);

  if(start < 0 || start > end || n <= end) {
    return NULL;
  }

  //want to create a new string of size...
  int newSize = end - start + 1;
  char *substring = (char *) malloc( sizeof(char) * (newSize + 1) );

  //s is a char * (string)
  //when you index, s[14] you are referring to ONE element
  // one element in s is a char
  // to get the string starting at s[14] you use &
  // char => char *

  strncpy(substring, &s[start], newSize);
  substring[newSize] = '\0';

  return substring;

}


int main(int argc, char **argv) {

    char data[] = "Chris,Bourke,35140602,Omaha,NE,103 Schorr";

    //call strtok the first time:
    //it returns a pointer to the firs token...
    char *token = strtok(data, ",");
    //each call after the first, you don't provide the string, just the delimiter:
    // it returns NULL if there are no more tokens
    while(token != NULL) {
      //process the token...
      printf("token = %s\n", token);
      token = strtok(NULL, ",");
    }

    return 0;
}
```


```text









```
