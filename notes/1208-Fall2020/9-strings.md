
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

### Substring

* Often you want to get a part of a string or a "substring"
* To do this in C you can use `strncpy`

```c

  char name[] = "Christopher Michael Bourke";
  char shortName[6];
  //copy the first 5 bytes:
  strncpy(shortName, name, 5);
  shortName[5] = '\0';

  printf("Hello, %s\n", shortName);

  char middleName[8];
  strncpy(middleName, &name[12], 8);
  middleName[7] = '\0';

  printf("Hello, %s\n", middleName);
```

### Other Convenience Functions

* The `ctype.h` library provides many other useful functions for single characters:
  * `isalpha(char c)` - true if `c` is an alpha-numeric character
  * `isspace(char c)` - true if `c` is a space character (` , \t, \n, \r`)
  * `isupper(c), islower(c)` - true if `c` is an uppercase or lowercase character
  * `toupper(c), tolower(c)` - convert to the lower/upper equivalent
  * `isdigit(c)` - true for 0 - 9

### String Formatting

* Recall that `printf` formats a string and prints it to the standard output
* You also have a `sprintf` formats a string and "prints" it to a given string buffer

```c

  char firstName[] = "Chris";
  char lastName[] = "Bourke";

  char buffer[1000];
  sprintf(buffer, "%s, %s", lastName, firstName);

  char *formattedName = (char *) malloc(sizeof(char) * (strlen(buffer) + 1));
  strcpy(formattedName, buffer);
  printf("hello, %s\n", formattedName);
  free(formattedName);
```

### String Tokenizing

* Often data is formatted: CSV, TSV (flat file formats)
* CSV = Comma Separated Value data, TSV = Tab Separated Value
* Example: `"Chris,Bourke,35140602,Omaha,NE,103 Schorr"`
* Each *token* of data is separated by a *delimiter*
* We want to "split" the data into their separate tokens and process each one by itself
* C provides a function, `strtok`
* `char *strtok(char *str, const char *delim);`
* It takes two arguments:
  * the first one is the string you want to tokenize
  * The second is a string containing the delimiter(s) you want to use
  * The return value is the next token
  * Note: `strtok` ends up modifying your string!
  * Each subsequent cll to `strtok` should pass `NULL` for the first argument in order for it to continue tokenizing the same string!
  * IF there are no more tokens, it returns `NULL`

```c

  char data[] = "Chris,Bourke,35140602,Omaha,NE,103 Schorr";

  char *token = strtok(data, ",");
  while(token != NULL) {
    printf("token = %s\n", token);
    token = strtok(NULL, ",");
  }
```

### String Comparisons

* In C, `strcmp` is used to compare the *contents* of two strings
* Remember: you CANNOT use the `==` operator
* The `==` operator only compares memory addresses (and besides it cannot tell you that one string is less than or greater than another)
* To properly compare strings use a *comparator* function: `strcmp`
  * It takes two strings, `a`, `b`
  * The return value is always an integer
  * It returns *something* negative if `a` comes before `b`
  * It returns zero if `a` and `b` have the same contents
  * It returns *something* positive if `b` comes before `a`
* Ordering is based on the ASCII text table!  It is *lexicographic* ordering, not alphabetic  
* You can also use `strcasecmp` to ignore casing! (it is a case-insensitive version)
* another alternative: `strncmp` which only compares the first `n` characters; also: `strncasecmp`

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


```text








```
