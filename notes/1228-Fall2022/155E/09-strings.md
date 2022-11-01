
# CSCE 155E - Computer Science I
## Strings
### Fall 2022

* In C, *strings* are ordered sequences of ASCII characters (not Unicode)
* In C, strings are simply null-terminated arrays of character elements (`char`)
* The null terminating character is ASCII value 0 and we write `\0`
  * It is NOT the value `0`
  * It is NOT the pointer `NULL`
  * It is not `void`
  * It is not the endline character `\n`
* If a string does not have a null-terminating character at the end, it is *not a valid string*
* If you try to do anything with an invalid string, it is *undefined behavior*: anything could happen: seg fault, bad results, etc.

```c

    //this is not yet a valid string!
    char *name = (char *) malloc( 12 * sizeof(char) );
    //make it a valid string:
    name[0] = '\0';
    //char name[100] = "chris";

    printf("My name is %s\n", name);

    //you can change individual characters:
    name[0] = 'C';
    name[1] = '\0';

    printf("My name is %s\n", name);

    //we cannot do this in C:
    //name = "Christopher";

    //instead we need to use a function...
    //it copies the contents of the second string into the first string
    // it takes care of the null terminating character for you
    // BUT it is *your responsibility* to ensure that the destination string
    // is big enough!
    strcpy(name, "Christopher");

    printf("My name is %s\n", name);

```

## Strings in C

* In C, strings are arrays of `char` elements
* Ex: `char str[10]` or `char *` (NOT `int *`)
* Declaring strings

### String Assignments

* Once you have created a string, you *cannot* reassign its value with the assignment operator: `=`
* You *must* use the `strcpy()` function to copy the contents of one string into another
* It is located in the string library: `string.h`
* The function has the signature:

`char * strcpy(char * destination, const char * source);`

* It *assumes* that the `destination` string is big enough to hold the `source` AND its null-terminating character!
* It assumes that the `source` string is a valid, null-terminated string!
* It does take care of the null-terminating character for you
* Observe the usage (and lack of) usage of the `const` keyword:

### String Concatenation

* Concatenation means appending one string to the end of the other string
* You can use the function `strcat`:

`char *strcat(char *dest, const char *src);`

* It appends the contents of `src` to the end of `dest`
* It assumes `src` is a valid null terminated string and `dest` is big enough to hold both `dest`, `src` AND the null terminating string!

```c
char name[100];

strcpy(name, "Christopher");
strcat(name, " ");
strcat(name, "Michael ");
strcat(name, "Bourke");

printf("My name is %s\n", name);

for(int i=0; i<100; i++) {
  printf("name[%d] = %c (%d)\n", i, name[i], (int) name[i]);
}
```

## String Length

* You use the `strlen()`: it returns the number of characters in the string *not* including the null-terminating character
* You can write a deep string copy function:

```c

char *deepStringCopy(const char *s) {
    char *copy = (char *) malloc( ( strlen(s) + 1 )  * sizeof(char) );
    strcpy(copy, s);
    return copy;
}
```

### Other Convenience Functions

* The `ctype.h` library has many functions that operate on single characters
  * `isalnum(c)` returns true if `c` is an alpha-numeric character: `0-9, a-z, A-Z`
  * `ispunct(c)` returns true if `c` is a punctuation character
  * `isspace(char c)` - returns true for all whitespace characters, `\t, \n, ` (space character)
  * `isupper(c), islower(c)` true or false if `c` is an upper case letter or lower case letter
  * `toupper(c), tolower(c)` return the upper/lower case version of `c`, returns `c` itself if it is not a letter
  * `isdigit(c)` true for 0-9
  * Exercise: write a function to convert a string to all uppper case characters

```c

/**
 *  "Computer!" => "COMPUTER!"
 */
void toUpperCaseString(char *s) {

  int n = strlen(s);
  for(int i=0; i<n; i++) {
    s[i] = toupper(s[i]);
  }
  return;
}

char *getUpperCaseCopy(const char *s) {
    char *copy = deepStringCopy(s);
    toUpperCaseString(copy);
    return copy;
}
```

## String Comparisons

* You will often need to compare the contents of one string to another...
* Can you use the `==` operator?

```c

    char a[] = "!pple";
    char b[] = "apple";

    //== compares memory address, NOT the contents of the string
    if(a == b) {
        printf("%s is equal to %s\n", a, b);
    } else {
        printf("%s is NOT equal to %s\n", a, b);
    }

    //strcmp compares two strings in lexicographic order (ASCII table)
    int result = strcmp(a, b);
    if(result < 0) {
        //a < b
        printf("%s comes before %s\n", a, b);
    } else if(result == 0) {
        printf("%s is equal to %s\n", a, b);
    } else if(result > 0) {
        printf("%s comes after %s\n", a, b);
    }

    //If you want to compare based on case-insensitive comparisons...
    result = strcasecmp(a, b);
    if(result < 0) {
        //a < b
        printf("%s comes before %s (ignoring case) \n", a, b);
    } else if(result == 0) {
        printf("%s is equal to %s (ignoring case) \n", a, b);
    } else if(result > 0) {
        printf("%s comes after %s (ignoring case) \n", a, b);
    }

    //You can also do comparisons with a byte limited version:
    // strncmp: you provide a third argument, the number of characters to compare
    char c[] = "apple pie";
    char d[] = "apple";
    result = strncmp(c, d, 6);
    if(result < 0) {
        //a < b
        printf("%s comes before %s (limited to 5 characters) \n", c, d);
    } else if(result == 0) {
        printf("%s is equal to %s (limited to 5 characters) \n", c, d);
    } else if(result > 0) {
        printf("%s comes after %s (limited to 5 characters) \n", c, d);
    }
```

* String comparison function `strcmp, strncmp, strcasecmp, strncasecmp` all follow a *comparator* pattern
* A comparator pattern is a general, abstract comparison: it is a function that takes two arguments, $a, b$
* It returns an integer:
  * *something* negative if $a < b$
  * zero if they are equal (conceptually), $a = b$
  * *something* positive if $a > b$ (equivalently, $b < a$)

## Byte Limited Versions

* Both `strcpy` and `strcat` have byte limited versions: `strncpy, strncat` that take a third argument: $n$, the maximum number of characters to copy or concatenate
* Same rules apply: source/destination are valid and the destination is big enough to hold both
* New rule: if the null-terminator character is seen by either function in the first $n$ characters, it is automatically copied for you
* If NOT: it becomes YOUR responsibility!

```c

    char fullName[100] = "Christopher Michael Bourke";
    char firstName[50];
    char foo[] = "Hello World";

    strncpy(firstName, fullName, 5);
    firstName[5] = '\0';
    printf("firstName = %s\n", firstName);

    strncat(firstName, foo, 5);
    firstName[10] = '\0';
    printf("firstName = %s\n", firstName);
```

* Challenge for Wednesday: get a substring of a string ()

```c

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>



char *deepStringCopy(const char *s) {
    char *copy = (char *) malloc( ( strlen(s) + 1 )  * sizeof(char) );
    strcpy(copy, s);
    return copy;
}

/**
 * This function takes a string s and a character c and counts up the
 * number of instances of the character c in s
 *
 */
int countChar(const char *s, char c) {

  if(s == NULL) {
    return 0;
  }

  int count = 0;
  for(int i=0; i<strlen(s); i++) {
    if(s[i] == c) {
        count++;
    }
  }
  return count;

}



/**
 * This function takes a string s and modifies it by removing all
 * whitespace characters
*/
int removeAllWhitespace(char *s) {

  //MAYBE: count up the number of whitespace characters
  //go through the characters (again) and if it is a non-whitespace character, copy it over to a
  // temporary work string
  //need some temporary space to work in:
  int n = strlen(s);
  char *temp = (char *) malloc( sizeof(char) * (n + 1) );
  //go through the characters...
  int j=0;
  for(int i=0; i<n; i++) {
    //if it is a whitespace character, ignore it.
    //else copy it from s to temp...
    if(!isspace(s[i])) {
        temp[j] = s[i];
        j++;
    }
  }
  temp[j] = '\0';

  //copy the temp string back into the original...
  strcpy(s, temp);
  free(temp);

  return 0;

}

/**
 * This function takes a string s and returns a new string (copy of it)
 * with all the whitespace characters removed
 */
char *removeAllWhitespaceCopy(const char *s) {

    //TODO: error check; return NULL
    char *copy = deepStringCopy(s);
    removeAllWhitespace(copy);
    return copy;

}

/**
 * This function takes a string s and two indices: start and end
 * and creates and returns a new string which is a substring of s
 * containing characters from [start, end]
 */
char *substring(const char *s, int start, int end) {

  if(s == NULL || start < 0 || end > strlen(s)-1 || start > end ) {
    return NULL;
  }

  int n = end-start+1;
  char *result = (char *) malloc( sizeof(char) * (n+1) );
  strncpy(result, &s[start], n);
  result[n] = '\0';

  return result;
}

int main(int argc, char **argv) {

    char school[100] = "\nUniv  er\tsity of Nebraska L\tinc    \t\t\toln";
    int n = strlen(school);
    printf("n = %d\n", n);

    //school is a char * (a pointer, a string)
    //school[15] is a char
    // but I want a char * to copy
    // char -> char *

    char *state = substring(school, 0, strlen(school)-1);

    // strncpy(state, &school[14], 8);
    // state[8] = '\0';
    printf("state = |%s|\n", state);

    free(state);

    int count = countChar(school, ' ');
    printf("count = %d\n", count);

    char *copy = removeAllWhitespaceCopy(school);
    printf("copy = |%s|\n", copy);
    free(copy);

    removeAllWhitespace(school);
    printf("school = |%s|\n", school);




    return 0;
}

```

## Data Processing: String Tokenization

* Formatting: Comma Separated Values = CSV

```text
first,last,nuid,city,state,office
Chris,Bourke,35140602,Omaha,NE,103 Schorr
Margaret,Hamilton,1234,Lincoln,NE,105 Schorr
Joe,Smith,5678,Atlanta,GA,120 Foo

```

* Each item is a *token*
* Each line is a record
* Splitting up the tokens on each line is called "tokenization"

```c

  char data[] = "Margaret,Hamilton,1234,Lincoln,NE,105 Schorr,USA";

  // The first time you call strtok: you pass
  //   1. The string you want to tokenize
  //   2. The delimiter you want to split it along (ex: ,) *as a string*
  //   3. It returns a pointer to the first token
  char *token = strtok(data, ",");
  //  4. every call after the first: you don't pass in the string
  ///    instead: pass in NULL to *continue* tokenizing the same string
  //     Otherwise: if you pass in a string, it start over
  while(token != NULL) {
    printf("token = %s\n", token);
    token = strtok(NULL, ",");
  }

  printf("my data is now: |%s|\n", data);

```

* You can tokenize a string based on any *delimiter* using `strtok`
  * `char * strtok(char *str, const char *delim)`
  * You provide with two arguments: the string you want to tokenize and the delimiter you want to tokenize on
  * The first call you provide the string, each subsequent call you provide `NULL` so that it continues to work on the same string
  * The return value can be used to determine if you are at the end of the string: when you are at the end it returns `NULL`
```text








```
