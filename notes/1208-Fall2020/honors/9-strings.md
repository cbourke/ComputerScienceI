
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


```text





```