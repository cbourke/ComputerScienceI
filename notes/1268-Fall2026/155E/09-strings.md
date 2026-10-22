
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


```text
















```
