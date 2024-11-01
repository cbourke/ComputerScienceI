# CSCE 155H - Computer Science I
## Strings
### Fall 2024

* A *string* is a sequence of characters
  * In C, *strings* are ordered sequences of ASCII characters
  * In Java, strings are Unicode characters; 🎃 (U+1F383), 👻 (U+1F47B)
  * In C, strings are *null-terminated* arrays of `char` elements
  * IN Java, strings are unicode `byte` arrays (inside of full classes: `String`)

## Strings in C

* In C, a *string* is a null-terminated array of `char` elements
* In C, you ahve characters in the array but at the end of the arry you have a null-terminator: `\0`
  * It is NOT zero `0`
  * It is NOT the endline character: `\n`
  * It is NOT `NULL`


```c

  char message[] = "hello World!!";
  printf("message = %s\n", message);
  //strings are mutable or "changeable"
  message[0] = 'H';

  printf("message = %s\n", message);

  //valid?
  message[13] = '!';

  printf("message = %s\n", message);

  char name[100] = "Chris Bourke";
  name[12] = '!';
  name[13] = '\0';

  printf("Hello, %s\n", name);

  // for(int i=0; i<100; i++) {
  //   printf("%c\n", name[i]);
  // }

  //reset my name to my full name:
  //name = "Christopher Michael Bourke";
  strcpy(name, "Christopher Michael Bourke");
  printf("Hello, %s\n", name);

```

## String assignments

* after the initial declaration, you can manipulate individual characters in a string, BUT
* You cannot reassign the entire contents of a string using the usual assignment operator: `=`
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

### Another operation: String Concatenation

* you can concatenate (combine) two strings using `strcat`
* `char *strcat(char *dest, const char *src);`
  * It appends the contents of `src` to the end of the `dest` string
  * It assumes that `dest` is large enough, it assumes that `src` is properly null terminated
  * If so, it takes care of the null terminator for you

```c
char name[100];
strcpy(name, "Christopher Michael");
printf("Hello, %s\n", name);

strcat(name, " ");
strcat(name, "Bourke");
printf("Hello, %s\n", name);
```

## Strings in Java

* Strings in Java are "built-in": you have a class `String`
* You also have a "string library" (a collection of methods that can manipluate strings)
* Java strings are *NOT* null-terminated; do not try to muck with the null terminator in Java
* In Java, strings are *immutable*: once created, their contents *cannot be changed*
* Instead, all of the methods return *new strings*
* You can determine the length of a string using `.length()`
* You can "copy" a string using the (re)assignment operator
* You can concatenate using the concatenation operator: `+`

```c

		String name = "Christopher Bourke";
		System.out.println(name);
		String foo = name.toUpperCase();
		System.out.println(name);
		System.out.println(foo);

		String oldName = name;
		//creates a brand new string in memory and resets name to reference to it
		name = "Jill Tracy";
		System.out.println(oldName);
		System.out.println(name);

		int n = name.length();
		System.out.println(n);

		name = "Chris";
		name = name + "topher";
		name = name + " ";
		name = name + "Michael Bourke";
		System.out.println(name);

		String newName = new String("Chris").concat("topher")
				                            .concat(" ")
				                            .concat("Michael Bourke");
		System.out.println(newName);

		String bar = "Hello";
		int baz = 42;
		String biz = bar + Integer.toString(baz);
		System.out.println(biz);

		//In Java you do have a mutable version of a string:
		StringBuilder sb = new StringBuilder();
		sb.append("chris");
		sb.append("topher");
		sb.append(" ").append("Michael")
		              .append(" ")
		              .append("Bourke");
		//dump it to a string:
		String buz = sb.toString();
		sb.replace(0, 11, "Jeremy");
		String bzz = sb.toString();
		System.out.println(buz);
		System.out.println(bzz);
```

## String Processing - C

* You can treat  strings as a regular array and manipulate the contents
* Example: write a function to convert to uppercase
* You can use the `ctype.h` library to compute values on individual `char` values
  * `toupper, tolower`, `isupper, islower`
  * `isspace` is true if it is a space character: ` , \n, \t`, etc.

### Byte Limited Versions  

* THere are also `strncpy` and `strncat` that take a third argument: `n` and only copy over or concatenate over **at most** `n` bytes
  * It will copy `n` bytes unless it sees the `\0` first, at which point it stops
  * If it *doesnt'* see the null terminator, *it will not copy it*!
* `sprintf` is a printf-like function that "prints" to a string
  * `s` refers to string: it prints not to the standard output, but to a string: the usual assumptions must hold  


```c
/**
 * Demonstration code template.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//TODO: documentation
char *deepCopyStr(const char *str);

/**
 * Converts the given string so that all characters are uppercase
 */
void toUpperCase(char *str);

/**
 * Returns a new string that is the given string so that all characters are uppercase
 */
char * toUpperCaseCopy(const char *str);

/**
 * returns a new (sub)string of the given string s starting at
 * the given start index and of length at most <code>length</code>
 */
char * substring(const char *s, int start, int length);

int main(int argc, char **argv) {

    char str[] = "Go Husker Football!!";
    char *strCaps = toUpperCaseCopy(str);
    printf("s = %s\n", str);
    printf("s = %s\n", strCaps);

    char foo[100];
    strncpy(foo, str, 9);
    //null terminator was not copied!
    foo[9] = '\0';
    printf("foo = %s\n", foo);

    //we want "Husker" instead: this a *substring*
    strncpy(foo, &str[3], 6);
    foo[6] = '\0';
    printf("foo = %s\n", foo);

    char *bar = substring(str, 6, 5);
    printf("bar = %s\n", bar);

    char buffer[1000];
    int x = 42;
    double y = 3.14159;
    char c = 'C';
    sprintf(buffer, "x = %d, y = %f, c = %c\n", x, y, c);
    printf("buffer = %s", buffer);
    char * finalStr = deepCopyStr(buffer);
    printf("finalStr = %s", finalStr);
}

void toUpperCase(char *str) {
    for(int i=0; i<strlen(str); i++) {
        str[i] = toupper(str[i]);
    }
    return;
}

char * toUpperCaseCopy(const char *str) {
    //TODO: error handling
    char *newStr = deepCopyStr(str);
    toUpperCase(newStr);
    return newStr;

}

char *deepCopyStr(const char *str) {

    char *newStr = (char *) malloc( sizeof(char) * (strlen(str) + 1) );
    strcpy(newStr, str);
    return newStr;
}

char * substring(const char *s, int start, int length) {

    //TODO: think of some more, what happens when length is to big?
    if(s == NULL || start < 0 || start > strlen(s) - 1 || length < 0) {
        return NULL;
    }

    char *subStr = (char *) malloc( sizeof(char) * (length + 1) );
    strncpy(subStr, &s[start], length);
    subStr[length] = '\0';
    return subStr;

}
```

```java


		String s = "Go Husker Football!!";
		String t = s.toUpperCase();
		//Deep, but useless copy:
		String x = new String(s);
		//mutable version:
		StringBuilder sb = new StringBuilder(s);
		//now you can manipulate it...
		sb.append("!!!!");


		int beginIndex = 3;
		int length = 6;
		String foo = s.substring(beginIndex, beginIndex + length);
		System.out.println(foo + ".");
		String bar = s.substring(beginIndex);
		System.out.println(bar);

		//sprintf-like behavior
	    int xx = 42;
	    double y = 3.14159;
	    char c = 'C';
	    String formatted = String.format("xx = %d, y = %f, c = %c\n", xx, y, c);
		System.out.println(formatted);

```

## Data Processing

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
  * You basically call this function multiple times until the last token is given...
  * It returns `NULL` when no more tokens are available
  * The first time you call it on a string: you pass in `str` the string you want to tokenize, each subsequent call: pass in `NULL` for `str` to *continue* processing the same string

```c

    char csvData[] = "Colour of Magic,Terry,Pratchett,1983,3.98";
    char *token = strtok(csvData, ",");
    while(token != NULL) {
      printf("token = %s\n", token);
      token = strtok(NULL, ",");
    }
```

* Careful: do not do anything directly with the tokens
  * If you need to process it as a number: use `atoi`, `atof`
  * If you need to leave a string: **make a deep copy**!!!

```c

    char csvData[] = "Colour of Magic,Terry,Pratchett,1983,3.98";
    int count = 0;
    for(int i=0; i<strlen(csvData); i++) {
      if(csvData[i] == ',') {
        count++;
      }
    }
    count++;

    char **tokenData = (char **) malloc( sizeof(char *) * count );
    char *tempToken = strtok(csvData, ",");
    for(int i=0; i<count; i++) {
      //copy the current token into tokenData[i[]]
      tokenData[i] = (char *) malloc( sizeof(char) * (strlen(tempToken) + 1) );
      strcpy(tokenData[i], tempToken);
      tempToken = strtok(NULL, ",");
    }
    for(int i=0; i<count; i++) {
      printf("tokenData[%d] = %s\n", i, tokenData[i]);
    }
    strcpy(csvData, "Hello WOrld!\n");
```

```text














```
