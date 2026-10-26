
# CSCE 155E - Computer Science I
## Strings
### Fall 2026

* In C, *strings* are ordered sequences of ASCII characters
* In C, strings are simply null-terminated arrays of character elements (`char`)
* In C, a string *MUST* be null-terminated: it must end with the special character, `\0`
  * It is NOT the character zero: `'0'`
  * This is *NOT* the endline character: `\n`
  * This is *NOT* the same thing as `NULL` (pointer)
  * It is NOT teh same thing as the number zero: `0`
* A string is NOT valid in C unless it is null-terminated
* Any operations or other things you do with a string that is invalid are *undefined behavior*
* In C, *all strings must be terminated with the null terminating character!*

## Strings in C

* You can declare strings statically or dynamically just as you did with arrays

## String library: `string.h`

* The string library, `string.h` provides many different functions that operate on strings!

### String Copy Function

* You cannot reassign an entire string after its declaration
* Instead, you have to use a function: `strcpy`
* `char * strcpy ( char * destination, const char * source );`
  * It copies the contents of `source` into `destination`
  * It is *assumed* that `destination` is big enough to hold the source
  * It is *assumed* that the `source` is a valid, null-terminated character
  * If not: bad things happen (seg fault, stack smashing, etc. - undefined behavior)
  * Ultimately, however, it does copy the null-terminator character for you
  * `const` ensures the function does not change the `source`
  * The lack of `const` in the `destination` implies it will change the contents!
* Do NOT try to copy more than the size of an array: seg faults, corrupted memory, etc.
  * Use valgrind to check if you are doing so!

### String Concatenation

* Concatenation: appending one string to the end of another
* Another useful function: `strcat`
* `char * strcat ( char * destination, const char * source );`
  * It has the same assumptions as `strcpy`
  * It will take the contents of `source` and *append* (add to the end) to `destination`, including the null terminating character

```c

    //static declaration:
    char message[] = "hello World!";
    //strings are mutable in C: you can change their values
    message[0] = 'H';

    printf("message = \"%s\"\n", message);

    //dynamic declaration:
    //"Christopher"
    //+1 for the null terminating character
    char *name = (char *) malloc( sizeof(char) * (11 + 1) );

    strcpy(name, "Christopher");

    printf("name = %s\n", name);

    //truncates the string, but it does not do anything to the other character
    name[5] = '\0';

    printf("name = %s\n", name);

    name[5] = 't';

    printf("name = %s\n", name);

    //try to fit my full name:
    //illegal, bad:
    //strcpy(name, "Christopher Michael Bourke");

    char buffer[1000];

    strcpy(buffer, "Hello");
    strcat(buffer, " ");
    strcat(buffer, "World");
    strcat(buffer, "!!!");

    printf("buffer = %s\n", buffer);

    free(name);
```

### Dynamic Strings

* Static strings are fine, but have the same problems as static arrays: small, declared on the stack, etc.
* Dynamic strings can be allocated on the heap using `malloc`
* Just make sure that the size *includes* one more for the null-terminator!

### String Length

* The string library has a function: `strlen` that gives you the **len**gth of a string
  * It does NOT include the null-terminating character!

```c

    char buffer[1000];
    strcpy(buffer, "Hello");
    int n = strlen(buffer);
    printf("length of '%s' is %d\n", buffer, n);

    //make a deep copy of the buffer...
    char *copy = (char *) malloc( sizeof(char) * (strlen(buffer) + 1) );
    strcpy(copy, buffer);

```

## String Processing

* String contain data
* Character by character
* The `ctype.h` library provides many other useful functions for single characters:
  * `isalpha(char c)` - true if `c` is an alpha-numeric character `A-Z, a-Z, 0-9`
  * `isspace(char c)` - true if `c` is a space character (` , \t, \n, \r`)
  * `isupper(c), islower(c)` - true if `c` is an uppercase or lowercase character
  * `toupper(c), tolower(c)` - convert to the lower/upper equivalent
  * `isdigit(c)` - true for 0 - 9

### Formatting

* `printf` will format a result to the standard output
* `sprintf` will format a result to a *string*

### Byte Limited Versions

* `strcpy` and `strcat` both copy/concatenate the entire string (beginning to end)
* `strncpy` and `strncat` are *byte-limited* versions of copy/concatenate
  * Each takes a third argument: `n` and copies/concats *at most* `n` characters/bytes
  * If it sees the null-terminating character before `n` bytes, it stops and copies `\0` for you!
  * However, if it does *not* see the null-terminator in the first `n` bytes, it **does not insert it for you!**

```c

/**
 * Converts the given string to upper case characters
 *
 * Returns a non-zero error code if s is NULL
 */
int toUpperCase(char *s);

/**
 * Creates a new string that is a copy of the given string but with
 * all letters converted to upper case.
 */
char * toUpperCaseCopy(const char *s);

/**
 * Removes all whitespace characters from the given string
 * TODO: add error handling
 */
void removeWhitespace(char *s);

/**
 * Returns a deep copy of the given string
 */
char *deepStringCopy(const char *s);

int main(int argc, char **argv) {

    //1. design a function that will convert a string to all uppercase letters
    char s[] = "Hello World!!!";

    // printf("BEFORE: %s\n", s);
    // toUpperCase(s);
    // printf("AFTER:  %s\n", s);

    //2. design a fucntion that converts to upper case but with a deep copy.
    char *t = toUpperCaseCopy(s);
    printf("s = %s\n", s);
    printf("t = %s\n", t);
    free(t);

    //3. Write a function to remove all whitespace characters from the string
    //ex: "Hello how are you?" = "Hellohowareyou?"
    char message[] = "Hello how are you?";
    removeWhitespace(message);
    printf("AFTER: message = %s\n", message);

    int x = 42;
    double y = 3.5;
    char name[] = "Chris";

    char buffer[1000];

    sprintf(buffer, "x = %d, y is %.3f, hello %s", x, y, name);
    printf("buffer = %s\n", buffer);
    //want to "print" to a string but ONLY of the size necessary
    char *result = deepStringCopy(buffer);
    free(result);

    char fullName[] = "Christopher";
    char shortName[6];
    strncpy(shortName, fullName, 5);
    shortName[5] = '\0';
    printf("short name = %s\n", shortName);

    return 0;
}

int toUpperCase(char *s) {

    if(s == NULL) {
        return 1;
    }

    int i = 0;
    while(s[i] != '\0') {
       //convert s[i] to uppercase
       s[i] = toupper(s[i]);
       i++;
    }

    return 0;
}

char * toUpperCaseCopy(const char *s) {

    //0. error handling
    if(s == NULL) {
        return NULL;
    }

    //1. create a new string...
    char *copy = deepStringCopy(s);
    toUpperCase(copy);

    return copy;
}

void removeWhitespace(char *s) {

    //0. create an empty that can be used as a buffer
    char *buffer = deepStringCopy(s);

    int i = 0;
    int j = 0;
    while(buffer[i] != '\0') {
        if( !isspace(buffer[i]) ) {
            s[j] = buffer[i];
            j++;
        }
        i++;
    }
    s[j] = '\0';

    free(buffer);
    return;
}

char *deepStringCopy(const char *s) {
    char *copy = (char *) malloc( sizeof(char) * (strlen(s) + 1));
    strcpy(copy, s);
    return copy;
}

```

### Substrings

* A substring of a string is a part of it (may begin inside the string)
* For example: `"Husker"` is a substring of `"Go Husker Football!!"`
* Goal: write a function that returns a substring of a given string

## Data Processing

* Data is fundamental to CS
* Strings are important because they are used to store data
* Often data is given in textual manner: not  necessary for humans, but in a readable format
  * XML = eXtensible Markup Language
  * JSON = JavaScript Object Notation
  * TSV, CSV = Tab Separated Values, Comma Separated Value
  * Ex: `"Chris,Bourke,2-2400,Avery 104B,Professor of Practice"`
  * These are "flat file" representations
* Goal: process a data string to pull out each individual piece of data called "tokens"
* Basic *tokenization*: split up a string of data into separate *tokens* so we can process each
  * Each piece of data is a token
  * Each is separated by a *delimiter* (comma)
* C provides a function, `strtok`
* `char *strtok(char *str, const char *delim);`
  * `str` is the string to tokenize (data string)
  * `delim` is a (optionally a list) of delimiters to use, typically we'll use `","`
  * `str` is not `const`: it can change and in fact it will be changed
  * Returns a pointer to the next token (ie you need to call this function several times to get each of the tokens)
  * On the first call you pass in the string you want to tokenize, however...
  * on each subsequent call, you pass `NULL` to continue with the same string (otherwise it will start over on the same string, giving the same token)
  * When there are no more tokens to provide, it returns `NULL`
  * Note: if you need the original data to be preserved, you need to operate on a *deep copy*

```c

    char data[] = "Chris,Bourke,2-2400,Avery 104B,Professor of Practice";

    char *token;
    token = strtok(data, ",");
    int numTokens = 0;

    while(token != NULL) {
      //print the current token
      printf("token = %s\n", token);
      //set up the next iteration, by going to the next token:
      token = strtok(NULL, ",");
      numTokens++;
    }

    printf("read %d tokens\n", numTokens);
```


```text
















```
