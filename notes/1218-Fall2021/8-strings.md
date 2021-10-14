
# CSCE 155E - Computer Science I
## Strings
### Fall 2021

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

* Once you create a string, you *CANNOT* use the assignment operator to reassign its values!

```c
char name[] = "Chris";
//you CANNOT do:
name = "Joe";
```

## String Assignments

* The string library, `string.h` provides many different functions that make operating on strings easy
* To *copy* the contents of one string into another, you use `strcpy`
* `char * strcpy ( char * destination, const char * source );`
* `strcpy` copies the contents of the `source` string into the `destination` string
  * It *assumes* that `destination` is big enough to hold what you are copying!  INCLUDING the null terminating character
  * It *assumes* that the `source` is a valid, null-terminated string
  * Notice: the `source` is declared as `const` (it is read only)
* Byte-limited version: `strncpy`
  * `char *strncpy(char *dest, const char *src, size_t n);`
  * It copies at most `n` characters over to the destination string
  * If the null terminating character occurs within the first `n` characters, it takes care of it for you (copies the null terminator)
  * If it is not within the first `n` characters, it will *NOT* copy the null terminator and YOU NEED TO TAKE CARE OF IT

## String length

* The length of a string is the number of characters in it, NOT including the null-terminating character
* `strlen` can be used to determine the length of a string

```c

char * deepStringCopy(const char * s) {
  //TODO: error handling
  char *copy = (char *) malloc( (strlen(s) + 1) * sizeof(char));
  strcpy(copy, s);
  return s;
}
```

## String Processing

### Concatenation

* Concatenation is the operation of combining two strings together: you append one string to the end of the other
* C does not have a concatenation operator (some languages let you use the `+` operator, C does *not*)
* Instead C provides the `strcat`
* `char *strcat(char *dest, const char *src);`
  * It appends the contents of `src` to the end of the `dest` string
  * It assumes that `src` is null terminated
  * It assumes that `dest` is big enough to hold both strings
* You can use `strncat` to concatenate at most `n` bytes

### Substrings

* A *substring* is simply just a part of a string
* There no "substring" function in the string library, but you can use a combination of pointers and strcat/strcpy to get the same effect.

```c
char name[] = "Christopher Michael Bourke";
char shortName[6];
strncpy(shortName, name, 5);
shortName[5] = '\0';

char middleName[8];
strncpy(middleName, &name[12], 7);
middleName[7] = '\0';

printf("hello, %s\n", shortName);
printf("hello, %s\n", middleName);
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

    int a = 42;
    double b = 3.14;
    char name[] = "Chris";
    char result[1000];

    printf("Hello, %s, your number is %d, pi is %f\n", name, a, b);
    sprintf(result, "Hello, %s, your number is %d, pi is %f\n", name, a, b);
    printf("result = %s\n", result);

```

## Tokenization

* Often data is given in a textual but formatted manner: CSV, TSV (flat files)
* CSV = Comma Separated Value data
* Example: `"Chris,Bourke,35140602,Omaha,NE,103 Schorr"`
* Each *token* of data is separated by a *delimiter*
* We want to "split" the data into their separate tokens and process each one by itself
* C provides a function, `strtok`
* `char *strtok(char *str, const char *delim);`
  * The first argument is the string you want to tokenize
  * The second argument is a string containing (multiple) delimiters
  * The return value is the *next* token
  * The first call you pass in the string you want to tokenize
  * Each subsequent call, you pass in `NULL` for the first argument to *continue* the tokenization
  * When there are no more tokens, `strtok` returns `NULL`
* Note:
  * `strtok` will NOT include the delimiters in the token
  * ***As a consequence***: it changes the string you give it!!!

```c

    char data[] = "Chris,Bourke,35140602,Omaha,NE,103 Schorr";

    char *currentToken = NULL;

    int numExpectedTokens = 6;
    int count = 1;

    currentToken = strtok(data, ",");
    while(currentToken != NULL) {
        printf("token %d = %s\n", count, currentToken);
        count++;
        currentToken = strtok(NULL, ",");
    }
    if(count - 1 != numExpectedTokens) {
        printf("Error\n");
    }

    printf("the original data is...\n");
    for(int i=0; i<50; i++) {
        printf("data[%d] = %c (%d)\n", i, data[i], (int) data[i]);
    }

```

## String Comparisons

* In C, `strcmp` is used to compare the *contents* of two strings
* Remember: you CANNOT use the `==` operator
* The `==` operator only compares memory addresses (and besides it cannot tell you that one string is less than or greater than another)
* To properly compare strings use a *comparator* function: `strcmp`
  * It takes two strings, `a, b`
  * if the contents are equal it returns zero
  * If `a` comes before `b` lexicographically (alphanumerically) it returns *SOMETHING* negative
  * IF `a` comes after `b` lexicographically, it returns *SOMETHING* positive
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
