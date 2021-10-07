
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

```text








```
