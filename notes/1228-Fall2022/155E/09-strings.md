
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

```c







```
