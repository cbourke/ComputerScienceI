
# CSCE 155H - Computer Science I
## Strings
### Fall 2021

* Strings are ordered sequences of characters (may be ASCII or Unicode)
* Different languages represent strings differently
* Most languages provide a standard library of functions to manipulate and process strings

## Strings in C

* In C, strings are simply arrays of characters, ie `char` array
* In C you can have static strings, `char s[]` or better, dynamic strings: `char *s;`
* ***But***: for a string to be valid in C, it *must* be ended (terminated) with a null-terminating character, `'\0'`
  * It is not the same thing as zero
  * It is not the same thing as the zero character: `'0'`
  * It is not `void`, it is not `NULL`
  * It is not the space, it is not the endline character, `\n`
* If an array of characters is *not* null-terminated, it is *not* a valid string and any operation on it is undefined behavior

```c
//create a static array of characters, ie a string:
char message[] = "hello World!";
```

* In the example above, the compiler will take care of the null terminator for you
* So the actual size of the array is 13 (1 additional to account for the null terminator)

```c
char name[100] = "chris";
```

* You *can* create arrays that are larger and "waste space"
* In C, all strings are *mutable*: you can change their contents

```c
char name[100] = "chris";
name[0] = 'C';

//print the string:
printf("Hello, %s\n", name);

```

## String assignments

* after the initial declaration, you can manipulate individual characters in a string, BUT
* you cannot reassign the entire contents of a string using the usual assignment operator, `=`
* Instead, you can use the string library's `strcpy`
* The string library is in `string.h`
* `char *strcpy(char *dest, const char *src);`
  * First argument: the *destination*, the string you are copying *to*
  * Second argument: the source, what you are copying from
  * The second argument is read-only!
  * The order is similar to the assignment operator: you take the right one and put it into the left one
  * This function *assumes* that `dest` is big enough to hold the source string
  * This function *assumes* that the source string is a valid, null-terminated string
  * `strcpy` *will* copy the null terminator for you

```c
char fullName[100];
strcpy(fullName, "Christopher");
```

* Another useful function: `strlen`: it returns an integer indicating the number of characters, *not including the null-terminator*

### Another operation: String Concatenation

* you can concatenate (combine) two strings using `strcat`
* `char *strcat(char *dest, const char *src);`
  * It appends the contents of `src` to the end of the `dest` string
  * It assumes that `dest` is large enough, it assumes that `src` is properly null terminated
  * If so, it takes care of the null terminator for you

### Byte Limited Versions  

  * There is also `strncpy` and `strncat` that take a third argument: the maximum number of characters to copy/concatenate
  * IF either function sees the null terminating character within the first `n` bytes, it will be copied over
  * Otherwise, the null terminator will NOT be copied over: ***It becomes your responsibility to do so***
  * This is very useful to copy *substrings*

```c

    char fullName[100];
    strcpy(fullName, "Christopher M. Bourke");
    char shortName[6];
    //copy only the first 5 bytes of fullName:
    strncpy(shortName, fullName, 5);
    //take care of the null terminator:
    shortName[5] = '\0';

    //you can also use strcat/strcopy to get a substring:
    char team[] = "Nebraksa Cornhuskers";
    char shortTeam[100];
    //team[9] is where "Cornhuskers" begins...
    strncpy(shortTeam, &team[9], 4);
    shortTeam[5] = '\0';
    printf("shortTeam = %s\n", shortTeam);

```

## Other useful things

* The `string.h` library has several dozen other functions: RTM
* The `ctype.h` library has a lot of useful functions for individual characters:
  * `isspace(c)` is true if `c` is a space character (` , \n, \t`, etc.)
  * `isupper(c)` or `islower(c)`
  * Convert: `toupper(c)` `tolower(c)`
  * etc. RTM!

## Strings in Java

* Strings in Java are "built-in": you have a class `String`

## Strings in Java

* Strings in Java are "built-in": you have a class `String`
* You also have a "string library" (a collection of methods that can manipluate strings)
* Java strings are *NOT* null terminated: don't use the null terminator in Java!
* In Java, strings are *immutable*: once created, their contents *cannot be changed*
* You *can* use the assignment operator to make a `String` reference refer to a new string
* You can also use the `+` operator to automatically concatenate strings
* The `.length()` method gives you the length of a string
* You can iterate over each character in a string:

### Mutable Strings in Java: `StringBuilder`

* A `StringBuilder` is a mutable (changeable) version of a string: you change its contents

```java
StringBuilder sb = new StringBuilder();
sb.append("hello").append(" ").append("world");
System.out.println(sb);
sb.setCharAt(0, 'H');
System.out.println(sb);
//dump a string builder to a string:
String mesage = sb.toString();

```

## More String Processing

### Formatting

* In C you can use `printf` to format the output (to the standard output).
* You can use `sprintf` to "print" to a string in a formatted manner

```c
int a = 42;
double b = 3.14;
char name[] = "Chris";
char message[100];

printf("Hello, %s, your number is %d, pi is %f\n", name, a, b);
sprintf(message, "Hello, %s, your number is %d, pi is %f\n", name, a, b);
printf("message = %s\n", message);
```

* Common pattern: you can use a temporary buffer that is "big enough" to work with then create a dynamic string of the *exact* size you need:

```c

  char firstName[] = "Chris";
  char lastName[] = "Bourke";
  char buffer[100];
  sprintf(buffer, "%s, %s", lastName, firstName);
  char *fullName = (char *) malloc(sizeof(char) * (strlen(buffer)+1));
  strcpy(fullName, buffer);
  printf("Hello, %s\n", fullName);
```

#### Java

```java
int a = 42;
double b = 3.14;
String name = "Chris";

System.out.printf("Hello, %s, your number is %d, pi is %f\n", name, a, b);
String message = String.format("Hello, %s, your number is %d, pi is %f\n", name, a, b);
System.out.println(message);
```

### Tokenizing Data

* Often, data is formatted: CSV, TSV (flat file formats)
* CSV = Comma Separated Values
* Example: `"Chris,Bourke,35140602,Omaha,NE,105 Schorr"`
* You want to process the record token by token: each *token* of data is separated by a *delimiter*
* In C you can use a function called `strtok` that "splits" a string into its separate tokens
* `char *strtok(char *str, const char *delim);`
  * First argument: string of data you want to tokenize
  * Second argument: delimiter (or list of delimiters) you want to use
  * The first argument is not `const`: `strtok` *will* make changes to your data!
  * The return value is a pointer to a string that represents the next token
  * on the first call you pass it the data you want to tokenize, it returns a pointer to the token
  * On each subsequent call, you pass in `NULL` to continue tokenizing the same data
  * It will return `NULL` when there are no more tokens available

```c
char data[] = "Chris,Bourke,35140602,Omaha,NE,105 Schorr";

int numTokens = 0;
char *token = strtok(data, ",");
while(token != NULL) {
  printf("token = %s\n", token);
  numTokens++;
  token = strtok(NULL, ",");
}
//TODO: check that numTokens is correct
printf("numTokens = %d\n", numTokens);

```

Java

* Use the `String.split()` method
* You can use regular expressions to do some really powerful stuff

## String Comparisons

* In *neither* language can you use the `==` operator to compare strings!
* In Both languages, `==` operator compares memory addresses!
* In C you can use `strcmp` to compare the contents of two strings
* This is a *comparator pattern*
  * It takes two arguments; $a, b$
  * It returns *something* negative if $a < b$
  * It returns *something* positive if $a > b$
  * It returns 0 if they are "equal"
* `strcmp` uses *lexicographic* ordering NOT dictionary or alphabetic ordering: it uses the ASCII text table values
* `strcasecmp` compares lexicographically but ignores the upper/lower case (case insensitive)
* `strncmp` is a byte-limited version
* `strncasecmp` is a variation that includes both!

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

* In Java you use `a.compareTo(b)`


### String Comparisons


```java
String a = "Apple";
String b = "apple";

int r = a.compareTo(b);

if (r < 0) {
  System.out.printf("%s comes before %s\n", a, b);
} else if (r > 0) {
  System.out.printf("%s comes before %s\n", b, a);
} else {
  System.out.printf("%s and %s are equal!\n", a, b);
}
```

* Case insensitive version: `a.compareToIgnoreCase(b)`
* Byte limited versions: create a substring!

```text





```
