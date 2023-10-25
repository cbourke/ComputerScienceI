
# CSCE 155H - Computer Science I
## Strings
### Fall 2023

* A *string* is a sequence of characters
  * In C, *strings* are ordered sequences of ASCII characters
  * In Java, strings are Unicode characters; 🎃 (U+1F383), 👻 (U+1F47B)
  * In C, strings are *null-terminated* arrays of `char` elements
  * IN Java, strings are unicode `byte` arrays

## Strings in C

* In C, a *string* is a null-terminated array of `char` elements
* In C, you have characters in the array but at the end of the array, you need a *null-terminating* character: `\0`
  * It is NOT zero
  * It is NOT the endline character: `\n`
  * It is NOT `NULL`

```c

  //strings can be declared this way:
  char message[] = "hello World!";
  //strings are mutable: their contents can be changed:
  message[0] = 'H';

  char b[100] = "hello World!";
  b[0] = 'H';
  b[12] = '!';
  b[13] = '!';
  //always, ALWAYS, null-terminate your strings:
  b[14] = '\0';

  //this syntax creates a read-only string:
  char *c = "hello World!";
  //c[0] = 'H';
```

```c
char message[1000];

//print a string using the __ placeholder:
printf("message = %s\n", message);

//generally they are filled with garbage (no default value):
// for(int i=0; i<1000; i++) {
//   printf("message[%d] = %c (%d)\n", i, message[i], message[i]);
// }

message[0] = '\0';
printf("message = %s\n", message);
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

* Another useful function: `strlen`: it returns an integer indicating the number of characters, *not including the null-terminator*

### Another operation: String Concatenation

* you can concatenate (combine) two strings using `strcat`
* `char *strcat(char *dest, const char *src);`
  * It appends the contents of `src` to the end of the `dest` string
  * It assumes that `dest` is large enough, it assumes that `src` is properly null terminated
  * If so, it takes care of the null terminator for you

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
 * Takes a string and returns a new string that is all capitalized
 * Ex: "computer!" => "COMPUTER!"
 */
char *toCaps(const char *s) {

  int n = strlen(s);

  char *result = (char *) malloc( sizeof(char) * (n + 1) );

  for(int i=0; i<n; i++) {
    result[i] = toupper(s[i]);
  }
  result[n] = '\0';

  return result;

}

int main(int argc, char **argv) {

   char name[50] = "Chris Michael James Bourke";


   //invalid, cannot do this:
   //name = "Christopher Bourke";

   //you can manually assign each character...
   name[4] = 't';
   name[5] = 'o';
   name[6] = 'p';

   //copy over an entire string:
   // copy "Christopher" into name...
   strcpy(name, "Christopher");
   printf("Name = %s\n", name);

   //I want it to contain
   //Christopher Bourke
   //another useful function:
   //cat = concatenation (append to the end of the string)
   strcat(name, " ");
   strcat(name, "Michael");
   strcat(name, " ");
   strcat(name, "Bourke");
   printf("Name = %s\n", name);

   printf("Name = %s\n", name);

   //reverse my name:
   //strlen gives you the length of the string NOT including the null terminating character!
   //strlen gives you the number of characters before the first \0
   int n = strlen(name);
   printf("name is %d characters long\n", n);
   for(int i=0; i<n/2; i++) {
     char temp = name[i];
     name[i] = name[n - i - 1];
     name[n - i - 1] = temp;
   }
    printf("Name = %s\n", name);

  char *word = toCaps("computer!");
  printf("word = %s\n", word);


}
```

### Byte Limited Versions  

* THere are also `strncpy` and `strncat` that take a third argument: `n` and only copy over or concatenate over at most `n` bytes
  * It will copy `n` bytes unless it sees the `\0` first, at which point it stops
  * If it *doesnt'* see the null terminator, *it will not copy it*!
* THese allow you to do *substring* operations: extract only a *part* of a string, a "subpart"

## Other useful things

* The string library has a dozen other functions: RTM = Read The Manuaul
* The `ctype.h` library has other useful functions for single characters:
  * `toupper, tolower`, `isupper, islower`
  * `isspace(c)` is true if `c` is a space character: `\n, \t,  , `
* `sprintf` is a printf-like function that "prints" to a string

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

//TODO:
//char *substringLength(const char *s, int start, int length) {
//char *substringToTheEnd(const char *s, int start) {

/**
 * Takes a string and returns a *deep copy* of the
 * substring specified by the two indices, start, end
 * inclusive/exclusive
 */
char *substring(const char *s, int start, int end) {

  if(s == NULL) {
    return NULL;
  }
  int n = strlen(s);
  if(start < 0 || end < 0 || start > n || end > n || start > end) {
    return NULL;
  }

  char *result = (char *) malloc( sizeof(char) * (end - start + 1) );

  strncpy(result, &s[start], end-start);
  result[end-start] = '\0';

  return result;

}

int main(int argc, char **argv) {

  char *s = "Nebraska Cornhuskers";

  char state[50];

  strncpy(state, s, 8);
  state[8] = '\0';
  printf("state = %s\n", state);



  char *teamName = substring(s, 9, 20);
  printf("team = %s\n", teamName);

  char *vegetable = substring(s, 9, 9+4);
  printf("vegetable = %s\n", vegetable);

  char buffer[100];
  int a = 42;
  double foo = 10.2342342;
  char c = 'C';
  sprintf(buffer, "%d %.2f %c, %s", a, foo, c, teamName);
  printf("buffer = %s\n", buffer);

}

```

```text









```
