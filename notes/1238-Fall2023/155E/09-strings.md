
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

### Other Convenience Functions

* The `ctype.h` library provides many other useful functions for single characters:
  * `isalpha(char c)` - true if `c` is an alpha-numeric character
  * `isspace(char c)` - true if `c` is a space character (` , \t, \n, \r`)
  * `isupper(c), islower(c)` - true if `c` is an uppercase or lowercase character
  * `toupper(c), tolower(c)` - convert to the lower/upper equivalent
  * `isdigit(c)` - true for 0 - 9

### String Formatting

* `printf` will format a result to the standard output
* `sprintf` will format a string and "print" it to another string

```c

  int a = 10;
  double b = 20.5;
  char *name = "Chris";

  char result[100];

  sprintf(result, "a = %d, %10.2f, hello %s", a, b, name);

  printf("result = %s\n", result);

```

## Tokenization

* Data is fundamental to CS
* Often data is given in textual manner: not  necessary for humans, but in a readable format
* CSV = Comma Separated Values
* TSV = Tab Separated Values
* These are "flat file" representations
* Basic tokenization: split up a string of data into separate *tokens* so we can process each
* C provides a function, `strtok`
* `char *strtok(char *str, const char *delim);`
  * First argument: the string you want to *tokenize*
  * Be careful: `strtok` *changes* your data string!
  * The second argument: a string of any delimiter(s) that you want to use!
  * Returns a pointer to the next token (ie you need to call this function several times to get each of the tokens)
  * Returns `NULL` when there are no more tokens!

```c

  char data[] = "Colour of Magic,Terry,Pratchett,1983,3.98";

  char *token;

  int count = 0;
  token = strtok(data, ",");
  while( token != NULL ) {
    count++;
    printf("token = %s\n", token);
    token = strtok(NULL, ",");
  }

```

### String Comparisons

* In C, you *cannot* use the `==` operator nor `!=` operator to test for string equality
* To properly compare strings use a *comparator* function: `strcmp`
  * It takes 2 strings as input: `a, b`
  * If the contents of `a` "come before" `b` then it returns ***something*** negative ($a < b$)
  * If the contents of `b` come before `a` then it returns ***something*** positive ($a > b$)
  * If the contents are the same, then it returns 0

```c

  char a[] = "9";
  char b[] = "123";
  /*
  Observations:
    * shorter strings come before longer strings (with the same beginning):
    apple < apples
    * Upper case letters come before ANY lower case:
    Banana < apple
    * numbers come before all letters:
    123 < apple
    * numbers follow the ascii table, not the values:
    123 < 9
    * These are all *lexicographic* orderings

  */

  // == and != compare *memory locations*!!!
  // printf("memory locations: %p and %p\n", a, b);
  //
  // if(a == b) {
  //   printf("a (%s) and b (%s) are equal!\n", a, b);
  // } else {
  //   printf("a (%s) and b (%s) are NOT equal!\n", a, b);
  // }

  if( strcmp(a, b) < 0 ) {
    printf("a (%s) < b (%s)\n", a, b);
  } else if( strcmp(a, b) > 0 ) {
    printf("a (%s) > b (%s)\n", a, b);
  } else {
    printf("a (%s) = b (%s)\n", a, b);
  }

  //case insensitive:
  // if( strcasecmp(a, b) < 0 ) {
  //   printf("a (%s) < b (%s)\n", a, b);
  // } else if( strcasecmp(a, b) > 0 ) {
  //   printf("a (%s) > b (%s)\n", a, b);
  // } else {
  //   printf("a (%s) = b (%s)\n", a, b);
  // }

```

```text













```
