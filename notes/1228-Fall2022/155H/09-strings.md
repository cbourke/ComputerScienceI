
# CSCE 155H - Computer Science I
## Strings
### Fall 2022

* Strings are ordered sequences of characters (may be ASCII or Unicode)
* Different languages represent strings differently
* Most languages provide a standard library of functions to manipulate and process strings


## Strings in C

* In C, strings are simply arrays of characters: `char` (ASCII *only*)
* In C you can have static strings, `char s[]` or better, dynamic strings: `char *s;`
* ***BUT***: for a string to be *valid* in C, it ***MUST*** end (be terminated) with a null terminating character: `\0`
  * It is NOT zero, `0`
  * It is NOT the character `'0'`
  * It is NOT `NULL` (it is not a pointer!)
  * It is not `void`, etc. etc. etc.
  * It is not the endline character! `\n`
* If an array of `char`s is not null-terminated, it is NOT a valid string and any operation on it is *undefined behavior*

```c
//create a static array of characters; ie a string:
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
  printf("name = %s\n", name);
  name[0] = 'C';
  name[5] = 'o';
  name[6] = 'p';
  name[7] = 'h';

  //this will not work:
  //name = "Christopher";

  //this will:
  strcpy(name, "Christopher");

  printf("name = %s\n", name);

```

## String assignments

* after the initial declaration, you can manipulate individual characters in a string, BUT
* you cannot reassign the entire contents of a string using the usual assignment operator, `=`
* Instead, you must use the string library's `strcpy` function
* The string library is in `string.h`
* `char *strcpy(char *dest, const char *src);`
  * copies the contents of `src` into the string `dest` (right-to-left, just like the assignment operator!)
  * The `const` in front of the `src` string indicates *no changes* will be made to `src`
  * The lack of a `const` in the `dest` means it *will* be changed
  * It is *your responsibility* to ensure that the `src` string is a valid string
  * It is *your responsibility* to ensure that the `dest` string is big enough to hold the source PLUS the null terminating character!

## Other Basic Operations

* You can determine how long a string is (the number of characters in it) using: `strlen()`
  * It only works on valid strings
  * It does *not* include the null terminating character

### Concatenation

* String concatenation simply means appending one string to the end of another string
* To do this in C, you use a function: `strcat()`
* `char *strcat(char *dest, const char *src);`
  * It appends the `src` string to the *end* of the `dest` string
  * It assumes that *both* are valid strings
  * It will take care of the null terminating character for you
  * It assumes that the `dest` is big enough to hold both strings!

### Byte Limited Versions  

* There is also `strncpy` and `strncat` that take a third argument: the maximum number of characters to copy/concatenate
* IF either function sees the null terminating character within the first `n` bytes, it will be copied over and it will end its copying (it only copies "at most" $n$ bytes, it stops either at $n$ bytes or the null terminating character!)
* Otherwise, the null terminating character becomes *your* responsibility
* It can be used to create *substrings*!
* You can manipulate strings to get a substring that starts anywhere in the string!

```c
char fullName[] = "Christopher Michael Bourke";
char middle[100];

//want to copy "Michael" into middle
strncpy(middle, &fullName[12], 7);
middle[7] = '\0';


printf("name = %s\n", fullName);
printf("name = %s\n", middle);
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
* You also have a "string library" (a collection of methods that can manipulate strings)
* Java strings are *NOT* null terminated: don't use the null terminator in Java!

```java
String name = "chris";


name = "Chris";
System.out.println(name.length());
System.out.println(name);
String foo = name.toUpperCase();
System.out.println(name);
System.out.println(foo);

//concatenation:
String lastName = "Bourke";
String formattedName = lastName + ", " + name;
System.out.println(formattedName);
```

* In Java, strings are *immutable*: once created, you cannot change them, you can only create news trings
* You *can* use the assignment operator to make a `String` reference refer to a new string
* You can also use the `+` operator to automatically concatenate strings
* The `.length()` method gives you the length of a string
* You can iterate over each character in a string.

```java
for(int i=0; i<formattedName.length(); i++) {
  char c = formattedName.charAt(i);
  System.out.println(c);
}
```

### Mutable Strings in Java: `StringBuilder`

* A `StringBuilder` is a mutable (changeable) version of a string: you change its contents

```java
StringBuilder sb = new StringBuilder();
sb.append("chris");
System.out.println(sb);
sb.append(" ");
sb.append("Bourke");
System.out.println(sb);
sb.replace(0, 1, "C");
System.out.println(sb);

sb.replace(5, 5, "topher");
System.out.println(sb);

String name = sb.toString();
System.out.println(name);
```

## String Comparisons

### C

* In C you cannot use the `==` operator: it compares memory addresses, not contents
* You need to use `strcmp, strcasecmp, strncmp` to compare contents.

* It is a "comparator" pattern: it returns
  * *Something* negative if $a < b$
  * zero if $a = b$ (conceptually)
  * *Something* positive if $a > b$ (or $b < a$)

```c

  char fruit01[] = "apple";
  char fruit02[] = "apples";

  //using == will not compare the *contents* of a string!
  // it compares memory addresses!
  if(fruit01 == fruit02) {
    printf("%s and %s are the same!\n", fruit01, fruit02);
  } else {
    printf("%s and %s are different!\n", fruit01, fruit02);
  }

  //compares lexicographically using the ASCII table values!
  int result = strcmp(fruit01, fruit02);
  if(result < 0) {
    printf("%s comes before %s\n", fruit01, fruit02);
  } else if(result == 0) {
    printf("%s is equal to %s\n", fruit01, fruit02);
  } else if(result > 0) {
    printf("%s comes after %s\n", fruit01, fruit02);
  }

  //if you want to compare without regard for upper/lower case:
  result = strcasecmp(fruit01, fruit02);
  if(result < 0) {
    printf("%s comes before %s\n", fruit01, fruit02);
  } else if(result == 0) {
    printf("%s is equal to %s\n", fruit01, fruit02);
  } else if(result > 0) {
    printf("%s comes after %s\n", fruit01, fruit02);
  }

  //if you want to compare only a certain number of characters:
  result = strncmp(fruit01, fruit02, 5);
  if(result < 0) {
    printf("%s comes before %s\n", fruit01, fruit02);
  } else if(result == 0) {
    printf("%s is equal to %s\n", fruit01, fruit02);
  } else if(result > 0) {
    printf("%s comes after %s\n", fruit01, fruit02);
  }
```

### Java

* same exact concept, except you use the `compareTo` and `compareToIgnoreCase` methods:

```java

		String fruitA = new String("Banana");
		String fruitB = new String("apple");

		if(fruitA == fruitB) {
			System.out.println("equal!");
		} else {
			System.out.println("Not equal!");
		}

		int result = fruitA.compareTo(fruitB);
		if(result < 0) {
			System.out.printf("%s comes before %s\n", fruitA, fruitB);
		} else if(result == 0) {
			System.out.printf("%s equals %s\n", fruitA, fruitB);			
		} else if(result > 0) {
			System.out.printf("%s comes after %s\n", fruitA, fruitB);			
		}

		result = fruitA.compareToIgnoreCase(fruitB);
		if(result < 0) {
			System.out.printf("%s comes before %s\n", fruitA, fruitB);
		} else if(result == 0) {
			System.out.printf("%s equals %s\n", fruitA, fruitB);			
		} else if(result > 0) {
			System.out.printf("%s comes after %s\n", fruitA, fruitB);			
		}
```

```java

		//substings in Java
		String fullName = "Christopher Michael Bourke";
		String firstNameShort = fullName.substring(0, 5);
		System.out.println(firstNameShort);
		String middle = fullName.substring(12, 19);
		System.out.println(middle);
		String foo = fullName.substring(12);
		System.out.println(foo);
```

```text











````
