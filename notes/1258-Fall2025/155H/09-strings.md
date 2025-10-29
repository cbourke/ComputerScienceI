# CSCE 155H - Computer Science I
## Strings
### Fall 2025

* A *string* is a sequence of characters
  * In C, *strings* are ordered sequences of ASCII characters
  * In Java, strings are Unicode characters; 🎃 (U+1F383), 👻 (U+1F47B)
  * In C, strings are *null-terminated* arrays of `char` elements
  * IN Java, strings are unicode `byte` arrays (inside of full classes: `String`)

## Strings in C

* In C, a *string* is a null-terminated array of `char` elements
* In C, you have characters, but the *end of the string* is terminated with a null terminator: `\0`
  * It is NOT zero `0`
  * It is NOT the character zero: `'0'`
  * It is NOT the endline character: `\n`
  * It is NOT `NULL`

```c

    //static string:
    //char str[] = "hello World!";
    //dynamic string:
    char *str = (char *) malloc( sizeof(char) * (13 + 1) );
    strcpy(str, "hello World!");

    //you can print string using the %s placeholder
    printf("str = %s\n", str);

    //in C, strings are *mutable*: they can be changed
    str[0] = 'H';
    printf("str = %s\n", str);

    str[12] = '!';
    //question: what is in str[13] at this point?
    str[13] = '\0';
    printf("str = %s\n", str);


    free(str);

```

## String Assignments

* after the initial declaration, you can manipulate individual characters in a string, BUT
* You cannto reassign the entire contents of a string using the assignment operator: `=`
* Instead: use `strcpy`
* The string library is in `string.h`
* `char *strcpy(char *dest, const char *src);`
  * The first is the `destination`
  * The second is the `source`
  * Copies from the source to the destination
  * It assumes the source is a valid, null-terminated string
  * It also assumes the destination is big enough to hold the entire string + terminating character
  * `src` is read only because of `const`
  * It will copy the enitre string and add the null terminator for you

* Another useful function: `strlen`: it returns an integer indicating the number of characters, *not including the null-terminator*

```c

    //create a large enough static string:
    //char str[100] = "Hello World";
    char str[100];

    //no reassignments:
    //str = "Goodbye World";

    //must use strcpy:
    //strcpy will assume that the target/destination is *big enough* to hold the string + null-terminator
    strcpy(str, "Goodbye World");

    printf("str = %s\n", str);

    int n = strlen(str);

    printf("n = %d\n", n);

    //copy str but ONLY the necessary characters:
    char *copyStr = (char *) malloc( sizeof(char) * (strlen(str) + 1) );
    strcpy(copyStr, str);
    printf("copyStr = %s\n", copyStr);
```

### Another operation: String Concatenation

* You can concatenate (combine) two strings using `strcat`
* `char *strcat(char *dest, const char *src);`
  * It appends the contents of `src` to the end of the `dest` string
  * It assumes that `dest` is large enough, it assumes that `src` is properly null terminated
  * If so, it takes care of the null terminator for you

## Strings in Java

* Strings in Java are "built-in": you have a class `String`
* You also have a "string library" (a collection of methods that can manipulate strings)

```java

		String s = "Hello";
		String t = s;
		//reset a string:
		s = "Goodbye";

		System.out.println(s);		
		System.out.println(t);
```

* In Java, strings are *immutable*: once created, they cannot be changed!
* Java strings are *NOT* null-terminated; do not try to muck with the null terminator in Java
* When you call a string method to process or "change" a string, it actually *returns a new string*!
* You can determine the length of a string using `.length()`
* You can "copy" a string using the (re)assignment operator
* You can concatenate using the concatenation operator: `+`

```java

		String s = "Hello";
		String t = "World";
		String message = s + " " + t + "!!!";
		StringBuilder sb1 = new StringBuilder(s)
				.append(" ")
				.append(t)
				.append("!!!");
		System.out.println(message);

		StringBuilder sb = new StringBuilder();
		sb.append("hello");
		sb.append(" ");
		sb.append("World");
		System.out.println(sb);
		sb.replace(0, 1, "H");
		System.out.println(sb);
		sb.reverse();
		System.out.println(sb);
		String result = sb.toString();


```

## String Processing - C

* Strings are important because they are often used to hold *data*
* That data needs to be processed
* Data formats: XML, JSON, TSV (tab-separated data), CSV = Comma Separated Values
* CSV: Each piece of data (token) is separated by a *delimiter* (comma)
* we need a way to separate each token and process each one separately
* We use "tokenization" to "split" the data up into each individual token
* In C: `strtok`
  * `char *strtok(char *str, const char *delim);`
  * `str` is the string you want to tokenize
  * **observe**: it lacks the `const` keyword! `strtok` will *change* your data!
  * `delim` is the delimiter: it can be any number of individual characters: you can "split" on commas, `","` or tabs `"\t"` or *muliple* delimiters: `":,"`
  * It returns a pointer to the next available token
  * It returns `NULL` when no more tokens are available
  * You have to be careful how you call it:
    * The first time you call it you pass in the `str` you want to tokenize
    * Each subsequent call you pass in `NULL` as the first argument to *continue* tokenizing the same string

```c

    char data[] = "Chris,Bourke,School of Computing,2-5008,Schorr 105";
    char *token = strtok(data, ",");

    while(token != NULL) {
        printf("token = %s\n", token);
        token = strtok(NULL, ",");
    }

```

* Careful: do not do anything directly with the tokens
  * If you need to process it as a number: use `atoi`, `atof`
  * If you need to leave a string: **make a deep copy**!!!

```java
String data = "Chris,Bourke,School of Computing,2-5008,Schorr 105";

String tokens[] = data.split(",");
System.out.println(Arrays.toString(tokens));
```

## More String Processing - C

* You can treat  strings as a regular array and manipulate the contents
* Example: write a function to convert to uppercase
* You can use the `ctype.h` library to compute values on individual `char` values
  * `toupper, tolower`, `isupper, islower`
  * `isspace` is true if it is a space character: ` , \n, \t`, etc.

### Byte Limited Versions  

* THere are also `strncpy` and `strncat` that take a third argument: `n` and only copy over or concatenate over **at most** `n` bytes
  * It will copy `n` bytes unless it sees the `\0` first, at which point it stops
  * If it *doesnt'* see the null terminator, *it will **not** copy it*!

```text














```
