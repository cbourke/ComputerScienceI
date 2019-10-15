
# CSCE 155E - Computer Science I
## Strings
### Fall 2019

* Strings are ordered sequences of characters (may be ASCII or Unicode)
* In C, strings are simply just (null-terminated) arrays of characters (`char` values)
* In C all characters are simple ASCII text characters
* Most languages provide a robust library to process strings, C included: `#include <string.h>`
* In C, *all strings must be null-terminated*
* The null terminating character is `\0` (ASCII text value: 0), NOT the same thing as `NULL`, it is not the "`void`" character, it is NOT the "character" zero, `'0'`
* If a string is NOT null terminated, operations on it may be *undefined behavior*

## Strings in C

* In C, strings are arrays of `char` elements
* You can declare a string using familiar syntax

```c
//this can only store 9 characters as you need
// the null terminating character at the end
char message[10];
message[0] = 'H';
message[1] = 'e';
message[2] = 'l';
message[3] = 'l';
message[4] = 'o';
message[5] = '\0';

char message[10] = "Hello";

char message[] = "Hello";
```

* In C, strings are *mutable*: the contents of a string (just like any array) can be changed

```c
char name[] = "chris";
//you CAN change a single character:
name[0] = 'C';

//careful: is this valid?
name[5] = 't';
name[6] = 'o';
name[7] = 'p';
```

* In general, overwriting a string past the null terminator can lead to undefined behavior
* You can always make a string shorter

```c
char name[] = "Christopher";
printf("%s", name);
name[5] = '\0';
printf("%s", name);
```

* making a string shorter by placing a null terminator is usually valid; it doesn't shorten the size of the array, it only shortens the string

## Dynamic Strings

* you can always use malloc to create a `char` array dynamically

```c
//goal: create an array that is able to hold 100 characters
int n = 100;
char *name = (char *) malloc( (n+1) * sizeof(char));

name = "Christopher Michael James Bourke";
```

* THe above "works" but it is a memory leak: the original array is lost
* THe assignment operator *can* be used on string at declaration
* The assignment operator cannot be used on strings *after* initialization
* Instead, you need a function to copy one string to another string

```c
//copy fullName into name
  int i = 0;
  while(fullName[i] != '\0') {
    name[i] = fullName[i];
    i++;
  }
  printf("i = %d\n", i);
  name[i] = '\0';
```

* THe string library provides a convenient method: `strcpy`
* `char * strcpy ( char * destination, const char * source );`
* `strcpy` copies the string in the second argument into the first (just like how the assignment operator works)
* The second argument has a `const` in front so it will NOT make changes to it (the first one will of course be changed)
* It takes care of the null terminating character for you
* BEWARE: `strcpy` assumes that the source string is *valid* (already has a null terminating character)
* BEWARE: `strcpy` assumes that the destination string is big enough to hold what you are copying!

```c
char name[] = "Christopher";
char copy[5];
strcpy(copy, name);
```

* Proper way:

```c
int n = 100;
char *name = (char *) malloc( (n+1) * sizeof(char));
strcpy(name, "Christopher Michael James Bourke");
```

### Determining the length of a string

* Often you want to determine how big a string is
* If you want to copy string a to string b, you need to make sure string b is big enough
* Thus, you need to know how big the string a is
* Manual solution:

```c
char name[] = "Chris";
int length = 0;
while(name[length] != '\0') {
  length++;
}

printf("length = %d\n", length);
```

* The string library provides a function to determine the length of a string: `strlen`
* It returns an integer representing the number of characters (NOT including the null terminating character)
* It reacts dynamically to changes in a string: it only counts up to the first null terminating character

### Exercise

* `strcpy` only copies one string into another
* It assumes the destination is big enough
* Let's write our own deep-copy string copy function
* A function that copies one string into another but ALSO dynamically allocates enough memory for it


```c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * This function creates a new string and copies the
 * given string into it, returning the new string
 */
char * deepStringCopy(const char *str) {

  char *copy = (char *) malloc( sizeof(char) * (strlen(str) + 1) );
  strcpy(copy, str);
  return copy;
}

int main(void) {

  char name[] = "Christopher";
  char *copy = deepStringCopy(name);
  printf("%s\n", name);
  printf("%s\n", copy);

  name[5] = '\0';
  printf("%s\n", name);
  printf("%s\n", copy);

  return 0;
}
```

### String Processing

* The `string.h` library provides many other useful functions
* Example: `strcat` (String concatenation)
* Concatenation: appending one string to the end of another string

```c
char fullName[100];
//strcpy(fullName, "Bourke, Christopher");
strcpy(fullName, "Bourke");
printf("%s\n", fullName);
//append or concatenate ", ":
strcat(fullName, ", ");
strcat(fullName, "Christopher");
printf("%s\n", fullName);
```

* `strcat` concatenates the second argument to the end of the first
* It is *your* responsibility to ensure that the first argument is "big enough" to handle whatever you concatenate
* `strcat` handles the null terminating character for you!

### Length limited versions

* `strcpy` and `strcat` both have byte-limited versions: `strncpy` and `strncat`
* You can give them another, third argument that limits how many bytes (how many characters) are copied or concatenated
```c

char fullName[100];
//strcpy(fullName, "Bourke, Christopher");
strncpy(fullName, "Bourke", 3);
printf("%s\n", fullName);
//append or concatenate ", ":
strcat(fullName, ", ");
strncat(fullName, "Christopher", 5);

printf("%s\n", fullName);
```

### Substrings

* Often you'll want only *part* of a string called a "substring"

```c

  //char -> char *
  char message[] = "Hello World how are you?";
  char word[100];
  //goal: copy the "World" part of message into word
  // start at message[6], copy 5 characters
  strncpy(word, &message[6], 5);
  printf("word = %s\n", word);
```

### More convenient functions

* The `ctype.h` library provides some more functions that operate on individual characters: `isalpha(char c)` `isupper(c)`, `islower(c)`, convert: `toupper(c), tolower(c)`, `isspace(c)`, `isdigit(c)` 

### String Formatting

* Recall: `printf` prints a formatted string to the standard output
* You can use another function, `sprintf` to "print" to another string
* `sprintf` takes one new argument: the first argument is the string you want to print to (instead of the standard output)
* It is YOUR responsibility to ensure that the destination string is big enough to hold the results

```c

  char message[1000];
  int x = 42;
  double pi = 3.14159;
  char name[] = "Chris";
  sprintf(message, "\tx = %d, pi =%10.2f, my name is %s\n", x, pi, name);
  printf("%s", message);
```

### String Tokenization

* Often, data is formatted: CSV, TSV (Comma or Tab Separated Value)
* Example: `"Chris,Bourke,35140602,Omaha,NE,363 Avery Hall"`
* Each piece of data is separated by a *token*
* We'll stick to *simple* data tokenization: we will want to "split" a string along some delimiter and process each token separately

* Function that we'll use is: `strtok`
* It takes two arguments: the string you want to tokenize and a delimiter that you want to use
* Generally we'll only use one delimiter, but you can use multiple ones 
* Generally, the delimiter is ignored
* The first time you call `strtok` you pass the string you want to tokenize
* Each subsequent call, in order to continue tokenizing the same string, you need to pass in `NULL`
* Keep in mind: `strtok` will *change the contents of your string*

```c
char data[] = "Chris,Bourke,35140602,Omaha,NE,363 Avery Hall";
char *token;
//process the first token:
token = strtok(data, ",");

while(token != NULL) {
  printf("%s\n", token);
  token = strtok(NULL, ",");
}
```

## String Comparisons (Revisited)

* In C, you *cannot* use the `==` operator to compare strings
* `==` is a numerical operator, using it with strings `char *` is only comparing the memory addresses of strings, not their content
* To properly compare strings according to their *content* you need to use a function: `strcmp`:
  * It takes two strings, `a, b`
  * It returns something negative, zero, or positive based on the relative ordering of the string (contents):
  * If `a < b` (conceptually) it returns *something* negative
  * If `a = b` (conceptually) it returns 0
  * If `a > b` (out of order conceptually) it returns *something* positive
  

```c
int result;

result = strcmp("apple", "apple"); //0
result = strcmp("apple", "apples"); //negative
result = strcmp("apples", "apple"); //positive

result = strcmp("Apple", "apple"); //negative

result = strcmp("apples", "oranges"); //negative

result = strcasecmp("ApPlE", "apple"); //zero
```

* all comparisons are according to the ASCII text table: "lexicographic ordering"  




