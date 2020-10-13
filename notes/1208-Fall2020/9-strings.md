
# CSCE 155E - Computer Science I
## Strings
### Fall 2020

* In C, *strings* are ordered sequences of ASCII characters
* In C, strings are simply null-terminated arrays of character elements (`char`)
* Most languages provide a robust library to process strings, C provides the `#include <string.h>` library
* In C, *all strings must be terminated with the null terminating characgter!*
* The null terminating character is the `\0` character
  * It is NOT the same thing as zero
  * It is NOT the same thing as `NULL`
  * It has a value of zero in the ASCII text table
* If you don't null terminate your strings, MANY of the string library functions will not operate correctly

## Strings in C

* In C, strings are arrays of `char` elements
* You can declare a string similar to how you declared arrays of integers or doubles, etc.

```c
char name[30] = "christopher";

//assign to an array of an exact:
char name[] = "christopher";
```

* Strings in C are *mutable*: the contents of a string can be changed

```c
name[0] = 'C';
```

* You can use the `%s` placeholder in `printf` to print strings

```c
printf("Hello %s\n", name);
```

* You can also "truncate" a string by setting any of its characters to the null terminating character:

```c
name[5] = '\0';

name[0] = 'J';
name[1] = 'o';
name[2] = 'e';
name[3] = '\0';
```

## String Assignments

* You CANNOT use the assignment operator `=` to assign a *new* value to a string!
* There is a nice "string copy" function in the standard string library: `strcpy`
* `char * strcpy ( char * destination, const char * source );`
* `strcpy` copies the contents of the `source` string into the `destination` string
  * It *assumes* that `source` is properly null terminated string
  * It *assumes* that the `destination` is big enough to hold the contents of `source`
  * Notice: the `source` is declared as `const` (it is read only)
* Byte-limited version: `strncpy`
  * `char *strncpy(char *dest, const char *src, size_t n);`
  * It copies at most `n` characters over to the destination string
  * If the null terminating character occurs within the first `n` characters, it takes care of it for you (copies the null terminator)
  * If it is not within the first `n` characters, it will *NOT* copy the null terminator and YOU NEED TO TAKE CaRE OF IT
  
## String length

* The length of a string is the number of characters in it, *NOT* counting the null terminating character
* To compute the length of a given string you can use the string library's `strlen` function

## Exercise 

* A *shallow* copy is simply a reference copy: changes to one element affect both
* A *deep* copy is where you copy the contents of (say) a string into a completely new string so that changes to one do not affect the other

```c

/**
 * Creates a new deep copy of the given string and
 * returns the new string
 */
char * deepStringCopy(const char *src) {
  if(src == NULL) {
    return NULL;
  }
  char *copy = (char *) malloc(sizeof(char) * (strlen(src) + 1) );
  strcpy(copy, src);
  return copy;
}

int main(int argc, char **argv) {

  //create a dynamic string big enough to hold "Christopher":
  char *name = (char *) malloc( sizeof(char) * 100 );

  strcpy(name, "christopher Michael James Bourke");

  char * correctedName = deepStringCopy(name);

  printf("original = %s\n", name);
  printf("copy     = %s\n", correctedName);

  correctedName[0] = 'C';

  printf("original = %s\n", name);
  printf("copy     = %s\n", correctedName);

  return 0;
}
```

## Concatenation

* Concatenation is the operation of combining two strings together: you append one string to the end of another string
* C does not have a concatenation operator (ie "Chris" + " " + "Bourke")
* Instead, you need to use a function: `strcat`
* `char *strcat(char *dest, const char *src);`
  * It appends the contents of `src` to the end of the `dest` string
  * It assumes that `src` is null terminated
  * It assumes that `dest` is big enough to hold both strings
* You can use `strncat` to concatenate at most `n` bytes

## String Processing

```text








```