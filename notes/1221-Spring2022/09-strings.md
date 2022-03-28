
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

* Concatenation is the operation of combining two strings together: you append one string to the end of the other string
* C does not have a concatenation operator instead you use a function:
* Instead C provides the `strcat`
* `char *strcat(char *dest, const char *src);`
  * it takes the contents of the `src` string and appends it to the end of the `dest` string
  * It is *your* responsibility to ensure that `dest` is big enough to hold the entire string
  * It is *your* responsibility to ensure that `src` is a valid, null-terminated string
  * It will take care of the null-terminator for you
* Byte limited version: `strncat`, it does NOT necesssarily take care of the null-terminating character for you
```c

    char message[1000];
    strcpy(message, "Hello");
    strcat(message, " World!!!\n");

    char shortMessage[100];
    shortMessage[0] = '\0';
    strncpy(shortMessage, message, 12);
    shortMessage[12] = '\0';

    strncat(shortMessage, "!!!!", 2);
    shortMessage[14] = '\0';
```

### Other Convenience Functions

* The `ctype.h` library provides many other useful functions for single characters
  * `isalpha(char c)` - returns true if `c` is an alpha-numeric character 0-9, a-z, A-Z
  * `isspace(char c)` - returns true for all whitespace characters, `\t, \n, ` (space character)
  * `isupper(c), islower(c)` true or false if `c` is an upper case letter or lower case letter
  * `toupper(c), tolower(c)` return the upper/lower case version of `c`, returns `c` itself if it is not a letter
  * `isdigit(c)` true for 0-9

```c
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char * toUpperCase(const char *s) {

  int n = strlen(s);
  //1. make a copy of the string...
  char *c = (char *) malloc( sizeof(char) * (n + 1) );

  //2. convert each letter into an upper case letter
  int i=0;
  while(s[i] != '\0') {
    //convert to an upper case
    c[i] = toupper(s[i]);
    i++;
  }
  c[i] = '\0';


  //3. return the new copy...
  return c;
}

void removeWhitespace(char *s) {

  int n = strlen(s);
  //1. make a copy of the string...
  char *copy = (char *) malloc( sizeof(char) * (n + 1) );

  int i=0;
  int j=0;
  while(s[i] != '\0') {
    //copy over but only if it is not a white space character...
    if( !isspace(s[i]) ) {
      copy[j] = s[i];
      j++;
    }
    i++;
  }
  copy[j] = '\0';
  strcpy(s, copy);
  free(copy);

  return;
}

int main(int argc, char **argv) {

    char msg[] = "Hello World how are you, today?";
    char *copy = toUpperCase(msg);
    printf("msg  = %s\n", msg);
    printf("copy = %s\n", copy);

    removeWhitespace(copy);
    printf("msg  = %s\n", msg);
    printf("copy = %s\n", copy);


    return 0;
}

```

### String Formatting

* `printf` will format a result to the standard output
* `sprintf` will format a result into a string instead

```c

    char buffer[1000];

    int x = 42;
    double pi = 3.14159;
    char name[] = "Bourke";

    sprintf(buffer, "Hello, %s, the answer is %d with pi = %f\n", name, x, pi);
    printf("%s\n", buffer);

```

### String Comparisons

* You *cannot* ever use `==` operator to compar strings!
* It ends up comparing memory addresses, NOT the contents of the strings!
* You use the function, `strcmp()`
* It takes two arguments: `a, b` which are both `const char *` (strings)
* It returns an integer:
  * *something* negative if `a < b`
  * zero if they are equal
  * *something* positive if `a > b` (`b < a`)
* Ordering is based on the ascii text table called "lexicographic" ordering, NOT dictionary order
* You can use `strcasecmp` to ignore casing in your comparison

```c

  char a[] = "Apple";
  char b[] = "apples";

  int r = strncasecmp(a, b, 5);

  if(r < 0) {
    printf("%s comes before %s\n", a, b);
  } else if(r > 0) {
    printf("%s comes before %s\n", b, a);
  } else {
    printf("%s and %s are equal!\n", a, b);
  }
int result;

result = strcmp("apple", "apple"); //0
result = strcmp("apple", "apples"); //negative
result = strcmp("apples", "apple"); //positive

result = strcmp("Apple", "apple"); //negative

result = strcmp("apples", "oranges"); //negative

result = strcasecmp("ApPlE", "apple"); //zero
```

### Tokenization

* Formatting: Comma Separated Values = CSV
* Each item is a *token*
* Each line is a record
* Splitting up the tokens on each line is called "tokenization"

```text
first,last,nuid,city,state,office
Chris,Bourke,35140602,Omaha,NE,103 Schorr
Margaret,Hamilton,1234,Lincoln,NE,105 Schorr
Joe,Smith,5678,Atlanta,GA,120 Foo

```

* You can tokenize a string based on any *delimiter* using `strtok`
  * `char * strtok(char *str, const char *delim)`
  * You provide with two arguments: the string you want to tokenize and the delimiter you want to tokenize on
  * The first call you provide the string, each subsequent call you provide `NULL` so that it continues to work on the same string
  * The return value can be used to determine if you are at the end of the string: when you are at the end it returns `NULL`


```text








```
