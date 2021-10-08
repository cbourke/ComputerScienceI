
# CSCE 155H - Computer Science I
## Strings
### Fall 2020

* Strings are ordered sequences of characters (may be ASCII or Unicode)
* Different languages represent strings differently
* Most languages provide a standard library of functions to manipulate and process strings

## Strings in C

* Strings in C are simply arrays of characters, `char` elements
* BUT for a string to be valid in C, it *must* be end (terminated) with a null-terminating character
* The null terminating character is the `\0`
  * It is not the same thing as zero
  * It is not the same thing as the character, `0`
  * It is not the same thing as `NULL`
  * It is not space, it is not an *end line* character
* If an array of characters is not null-terminated, then it may result in undefined behavior

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
//fix the first character:
name[0] = 'C';
```

## String assignments

* after the initial declaration, you can manipulate individual characters in a string, BUT
* you cannot reassign the entire contents of a string using the usual assignment operator, `=`
* You can copy a string using the `strcpy` function in the string library, `string.h`
* `char *strcpy(char *dest, const char *src);`
  * It copies the contents of the `src` string into the `dest`
  * The source is declared as constant: it will not make changes to `src`
  * It *will* make changes to `dest`
  * It also assumes that `src` is a properly null-terminated string
  * It also assumes that `dest` is big enough to hold the contents of the `src` AND the null terminator
* You can also write your own *deep copy* string function
* Another convenient function in the string library: `strlen`: it returns the number of characters in the string NOT INCLUDING the null terminator

```c

char * deepCopyString(const char *source) {

  int length = strlen(source)
  char *result = (char *) malloc(sizeof(char) * (length + 1));
  strcpy(result, source);
  return result;
}
```

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
strncpy(shortName, fullName, 5);
shortName[5] = '\0';
printf("hello, %s\n", fullName);
printf("hello, %s\n", shortName);
```

* Or you can copy a substring starting at an arbitrary character:

```c
char middleName[8];
strncpy(middleName, &fullName[12], 7); //copies "Michael"
middleName[7] = '\0';
printf("your middle name is, %s\n", middleName);
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
* You also have a "string library" (a collection of methods that can manipluate strings)
* Java strings are *NOT* null terminated: don't use the null terminator in Java!
* In Java, strings are *immutable*: once created, their contents *cannot be changed*

```java
String s = "Hello";
s = "Goodbye!";
```

* You *can* use the assignment operator to make a `String` reference refer to a new string
* You can also use the `+` operator to automatically concatenate strings

```java
String a = "Christopher";
String b = "Bourke";
//concatenation with the + operator
String name = b + ", " + a;
```

* You can use `name.length()` to get the length of the string (number of characters in it)
* You *can* iterate over each character using a traditional for-loop

```java
String name = "Christopher";
for(int i=0; i<name.length(); i++) {
  System.out.println(name.charAt(i));
}

for(Character c : name.toCharArray()) {
  System.out.println(c);
}
```

### Mutable Strings in Java: `StringBuilder`

* A `StringBuilder` is a mutable (changeable) version of a string: you change its contents

```java

		StringBuilder sb = new StringBuilder();
		System.out.println(sb);
		sb.append("hello");
		sb.append(" ");
		sb.append("Worll!");
		System.out.println(sb);

		sb.setCharAt(0, 'H');
		sb.setCharAt(10, 'd');
		System.out.println(sb);

		sb.insert(0, "message: ");
		System.out.println(sb);

		sb.replace(15, 21, "Universe");
		System.out.println(sb);
```

## More String Processing in C

### Formatting

* Recall that you can use `printf` to format output that gets printed to the standard output
* You can also use `sprintf` to format to a string "output"
* Signature: `int sprintf(char *str, const char *format, ...);`

```c
char firstName[] = "Chris";
char lastName[] = "Bourke";
char fullName[100];
sprintf(fullName, "%s, %s", lastName, firstName);
printf("Hello, %s\n", fullName);
```

* `sprintf` assumes that the destination string is big enough to hold whatever you are printing
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

### String Tokenization

* Often, data is formatted: CSV, TSV (flat file formats)
* CSV = Comma Separated Value data
* Example: `"Chris,Bourke,35140602,Omaha,NE,103 Schorr"`
* You want to process the record token by token: each *token* of data is separated by a *delimiter*
* In C you can use a function called `strtok` that "splits" a string into their separte tokens
* `char *strtok(char *str, const char *delim);`
  * The first argument is the string you want to process (tokenize)
  * NOTE: the first argument is not `const`: `strtok` *will* change your string
  * The second is a string containing delimiter(s)
  * It returns a pointer to the next token
  * Beware: the first time you call `strtok` you pass in the string you want to tokenize; each *subsequent* call you pass in `NULL` to *continue* processing the same string
  * `strtok` returns `NULL` when there are no more tokens to process

```c

  char data[] = "Chris,foo,Bourke,35140602,Omaha,NE,103 Schorr";
  char *token = strtok(data, ",");
  int numTokens = 0;
  while(token != NULL) {
    printf("token = %s\n", token);
    numTokens++;
    token = strtok(NULL, ",");
  }
  if(numTokens != 6) {
    printf("bad data!\n");
  }
  ```

### string Comparisons

* In C, `strcmp` can be used to compare the *contents* of two strings
* You *cannot* use the `==` operator to compare strings!  
* `strcmp` follows a *comparator pattern*:
  * It takes two arguments, `a, b`
  * IT returns an integer:
  * It returns *something* negative if `a` comes before `b`
  * It returns 0 if `a` and `b` have the same contents
  * It returns *something* positive if `a` comes after `b`
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


## More String Processing in Java

### Formatting

* To format using `printf`-style formatting, you can use `String.format()`

```java
String firstName = "Chris";
String lastName = "Bourke";
String fullName = String.format("%s, %s", lastName, firstName);
System.out.println(fullName);
```

### Tokenization

```
String data = "Chris,foo,Bourke,35140602,Omaha,NE,103 Schorr";
String tokens[] = data.split(",");
System.out.println(Arrays.toString(tokens));
for(String token : tokens) {
  System.out.println(token);
}
```

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
