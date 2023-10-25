
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

## String Processing

### String Length:

* The length of a string is the number of characters in it, NOT including the null-terminating character
* `strlen` can be used to determine the length of a string
* Creating and processing substrings:

```c
/**
 * Demo Code
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/**
 * This function returns a new string of the given string but
 * with all the letters capitalized.
 * Ex: "computer!" => "COMPUTER!"
 */
char *capitalize(const char *s) {

  if(s == NULL) {
    return NULL;
  }

  int n = strlen(s);
  char *result = (char *) malloc( sizeof(char) * (n + 1) );

  //most efficient
  for(int i=0; i<n; i++) {
    result[i] = toupper(s[i]);
  }
  result[n] = '\0';

  //less brittle (less error prone)
  // strcpy(result, s);
  // for(int i=0; i<n; i++) {
  //   result[i] = toupper(result[i]);
  // }
  //1. copy over the contents of s into result
  //2.  go through each character and convert it to upper case
  //3.  ?? Do we need to take care of something at the end?

  return result;

}

/**
 * Creates a new string that is a substring of the given string.
 * The new string will start at s[start] and be of the given length.
 *
 * "Go Nebraska Cornhuskers!", 3, 8
 * would result in "Nebraska"
 */
char *substring(const char *s, int start, int length) {

  //TODO: consider if invalid length is an error condition
  if(s == NULL || start < 0 || start >= strlen(s)) {
    return NULL;
  }
  char *result = (char *) malloc( sizeof(char) * (length + 1) );
  strncpy(result, &s[start], length);
  result[length] = '\0';

  return result;
}

//TODO: consider the following variations:
//char *substring(const char *s, int start, int end);
//char *substring(const char *s, int start);

int main(int argc, char **argv) {

  // char s[100] = "computer!";

  // int n = strlen(s);
  // printf("\"%s\" has %d characters!\n", s, n);

  // char *t = capitalize(s);
  // printf("\"%s\" \n", t);

  // free(t);

  //byte limited versions of strcpy and strcat:
  char *team = "Nebraska Cornhuskers";
  //want to get each substring by itself:
  char state[50];
  //strncpy is a byte limited version
  //  - it takes one more argument: n, the number of bytes/characters to copy
  //  - it only copies up to n bytes: if it sees the null terminator, it stops
  //  - if it does NOT see the null terminator, it does NOT copy it!
  strncpy(state, team, 8);
  state[8] = '\0';
  printf("state = %s\n", state);

  //strncpy can be used to compute "substrings", parts of the string
  //  that are "inside" the string
  char teamName[50];

  //team: char * (string)
  //team[9]: char
  //&team[9]: char *

  // it always starts at the beginning of a string
  //  I want it to start "in the middle" (at index 9)
  strncpy(teamName, &team[9], 11);
  teamName[11] = '\0';
  printf("teamName = %s\n", teamName);

  char *newState = substring("Go Nebraska Cornhuskers!", 3, 8);
  printf("newState = %s\n", newState);

  newState = substring("Go Nebraska Cornhuskers!", 0, 2);
  printf("newState = %s\n", newState);

  newState = substring("Go Nebraska Cornhuskers!", 12, 11);
  printf("newState = %s\n", newState);
}

```

```text













```
