# CSCE 155H - Computer Science I
## Strings
### Fall 2026

* A *string* is a sequence of characters
  * In C, *strings* are ordered sequences of ASCII characters
  * In Java, strings are Unicode characters; 🎃 (U+1F383), 👻 (U+1F47B)
  * In C, strings are *null-terminated* arrays of `char` elements
  * IN Java, strings are unicode `byte` arrays (inside of full classes: `String`)

## Strings in C

* In C, a *string* is a null-terminated array of `char` elements
* In C, you have characters, but the *end of the string* is terminated with a null-terminator: `\0`
  * It is NOT zero `0`
  * It is NOT the character `'0'`
  * It is NOT the endline: `\n`
  * It is NOT `NULL`

## String Assignments

* after the initial declaration, you can manipulate individual characters in a string, BUT
* You cannot reassign the entire contents of a string using the assignment operator: `=`
  * It is either a compiler error or
  * You are simply changing pointers
* Instead use `strcpy`:
  * The string library is in `string.h`
  * `char *strcpy(char *dest, const char *src);`
  * The first is the `destination`
  * The second is the `source`
  * Copies from the source to the destination
  * It assumes the source is a valid, null-terminated string
  * It also assumes the destination is big enough to hold the entire string + terminating character
  * `src` is read only because of `const`
  * It will copy the entire string and add the null terminator for you
* Another useful function: `strlen`: it returns an integer indicating the number of characters, *not including the null-terminator*

```c

    //static strings:
    char str[] = "hello World!";
    //strings in C are mutable:
    str[0] = 'H';
    //compiler error:
    //str = "Goodbye";

    printf("str = %s\n", str);

    //a string ends at the null terminating character: Hello
    str[5] = '\0';

    printf("str = %s\n", str);

    //don't do bad things:
    str[5] = ' ';
    //illegal: undefined behavior, you may get away with it
    // but it is really bad
    str[12] = '!';

    printf("str = %s\n", str);

    //dynamic strings:
    //"Christopher Bourke" + 1 for the null terminator
    char *name = (char *) malloc( sizeof(char) * (18 + 1) );
    //printf("name = \"%s\"\n", name);
    //no warnings; bu wrong: you are repointing the pointer
    // name = "Christopher Bourke";
    // printf("name = \"%s\"\n", name);

    //to "assign" a value to a string, you need to use a function
    // strcpy: str = string, cpy = copy
    strcpy(name, "Christopher Bourke");
    printf("name = \"%s\"\n", name);

    //name is too small to hold the full name:
    // strcpy(name, "Christopher Michael Bourke");
    // printf("name = \"%s\"\n", name);

    int length = strlen(name);
    printf("%s has %d characters\n", name, length);

    for(int i=0; i<length; i++) {
        //convert to upper case...
        name[i] = toupper(name[i]);
    }
    printf("%s has %d characters\n", name, length);

    free(name);

    //create a temporary "buffer" string that is "big"
    char buffer[1000];
    strcpy(buffer, "Goodbye World");
    printf("buffer = %s\n", buffer);
    //900 something unused characters
    strcpy(buffer, "I've got a bad feeling about this, Han said, and the walls of the trash compactor began to close. I am a Jedi, like my father before me, Luke declared, tossing his lightsaber aside. You don't know the power of the dark side, Vader warned, clenching his mechanical fist. Judge me by my size, do you? And well you should not, for my ally is the Force. Hokey religions and ancient weapons are no match for a good blaster at your side, kid.");
    printf("buffer = %s\n", buffer);

    strcpy(buffer, "Hello");
    strcat(buffer, " ");
    strcat(buffer, "World");
    strcat(buffer, "!!!");
    printf("buffer = %s\n", buffer);
    //bad:
    for(int i=0; i<10000; i++) {
        strcat(buffer, "!!!!!!!!!!");
    }
```

### Another operation: String Concatenation

* You can combine or "concatenate" two strings together: you append one string to the end of the other
* `char *strcat(char *dest, const char *src);`
  * It appends the contents of `src` to the end of the `dest` string
  * It assumes that `dest` is large enough, it assumes that `src` is properly null terminated
  * If so, it takes care of the null terminator for you

## Strings in Java

* Strings in Java are "built-in": you have a class `String`
* You also have a "string library" (a collection of methods that can manipulate strings)
* Strings in Java are *immutable*
* Java strings are *NOT* null-terminated; do not try to muck with the null terminator in Java
* When you call a string method to process or "change" a string, it actually *returns a new string*!
* You can determine the length of a string using `.length()`
* You can "copy" a string using the (re)assignment operator
* You can concatenate using the concatenation operator: `+`


```java

		String s;
		s = "Hello";
		s = "Hello World";
		s = s + "!!!";
		System.out.println(s);
		System.out.printf("s = %s\n", s);

		//strings are IMMUTABLE in Java
		s = "hello";
		//cannot: s[0] = 'H';
		String t = s;
		s = "Hello";
		System.out.println("s = " + s);
		System.out.println("t = " + t);

		s = "Hello";
		int n = s.length();
		System.out.println(n);

		s = s.toUpperCase();
		System.out.println(s);

		char c = s.charAt(0);
		System.out.println(c);

		//there IS a "mutable" version of strings in Java:
		StringBuilder sb = new StringBuilder();
		sb.append("hello");
		sb.append(" ");
		sb.append("World");
		System.out.println(sb);
		sb.setCharAt(0, 'H');
		System.out.println(sb);
		//dump to a regular old string:
		String message = sb.toString();
		System.out.println(message);
```

## String Processing - C

* Strings are important because they are often used to hold *data*
* That data needs to be processed
* Basic processing:
  * C: use a loop...

### `ctype.h` library

* String contain data
* Character by character
* The `ctype.h` library provides many other useful functions for single characters:
  * `isalpha(char c)` - true if `c` is an alpha-numeric character `A-Z, a-Z, 0-9`
  * `isspace(char c)` - true if `c` is a space character (` , \t, \n, \r`)
  * `isupper(c), islower(c)` - true if `c` is an uppercase or lowercase character
  * `toupper(c), tolower(c)` - convert to the lower/upper equivalent
  * `isdigit(c)` - true for 0 - 9

```c

int toUpperCase(char *s) {

    if(s == NULL) {
        return 1;
    }

    int i = 0;
    while(s[i] != '\0') {
        s[i] = toupper(s[i]);
        i++;
    }
    return 0;
}

char * toUpperCaseCopy(const char *s) {

    //0. error checking:
    if(s == NULL) {
        return NULL;
    }

    //1. copy the string...
    char *copy = (char *) malloc( sizeof(char) * (strlen(s)+1) );
    strcpy(copy, s);

    // int i = 0;
    // while(s[i] != '\0') {
    //     copy[i] = toupper(s[i]);
    //     i++;
    // }
    // //must terminate this manually:
    // copy[i] = '\0';
    //instead: reuse our functionality
    toUpperCase(copy);

    return copy;

}

int removeWhitespace(char *s) {

    if(s == NULL) {
        return 1;
    }

    int j = 0;
    //TODO: change this to a while loop to avoid potential multiple calls to strlen
    for(int i=0; i<strlen(s)+1; i++) {
        //copy only if it is NOT a whitespace character...
        if(!isspace(s[i])) {
            s[j] = s[i];
            j++;
        }
    }
    //s[j] = '\0';
    return 0;
}
```

```java

		String s = "Hello World!!!";

		String t = s.toUpperCase();

		System.out.println(t);

		//if you DO need to process a string character by character...
		for(int i=0; i<s.length(); i++) {
			char c = s.charAt(i);
			System.out.println(c);
		}

		for(char c : s.toCharArray()) {
			System.out.println(c);
		}

		String message = "Hel\tlo ho\nw ar\re youA hello U EFJDKSL:FKJDS:?";
		t = message.replaceAll("Hello", "");		
		System.out.println(t);

		System.out.println("=========");
		t = message.replaceAll(".*", "");		
		System.out.println(t);

```

### Formatting

* `printf` will format a result to the standard output
* `sprintf` will format to a string

```c

    int x = 42;
    double y = 3.5;
    char name[] = "John";

    char result[100];

    sprintf(result, "x = %d, y = %f, name = %s\n", x, y, name);

    printf("result is now %s\n", result);
```

### Byte Limited Versions

* `strcpy` and `strcat` both copy/concatenate the entire string (beginning to end)
* `strncpy` and `strncat` are *byte-limited* versions of copy/concatenate
  * Each takes a third argument: `n` and copies/concats *at most* `n` characters/bytes
  * If it sees the null-terminating character before `n` bytes, it stops and copies `\0` for you!
  * However, if it does *not* see the null-terminator in the first `n` bytes, it **does not insert it for you!**

```c

    char fullName[] = "Christopher Michael Bourke";

    char firstName[6];

    strncpy(firstName, fullName, 5);
    //we need to take care of the null terminator manually:
    firstName[5] = '\0';

    printf("firstName = %s\n", firstName);
```

### Substrings

* A substring of a string is a part of it (may begin inside the string)
* For example: `"Husker"` is a substring of `"Go Husker Football!!"`
* Goal: write a function that returns a substring of a given string

```c

/**
 * Returns a new substring of s starting at beginIndex
 * all the way to the end of s
 */
//char *substring(const char *s, int beginIndex);

/**
 * Returns a new substring of s starting at beginIndex
 * and ending at endIndex - 1
 */
char *substring(const char *s, int beginIndex, int endIndex);

/**
 * Returns a new substring of s starting at beginIndex
 * and of the given length
 */
//char *substring(const char *s, int beginIndex, int length);


int main(int argc, char **argv) {

    char str[] = "Go Husker Football!!";

    char *substr = substring(str, 3, 9);

    printf("substr = %s\n", substr);

    free(substr);

    return 0;
}

char *substring(const char *s, int beginIndex, int endIndex) {

    if(s == NULL || beginIndex < 0 || endIndex < beginIndex) {
        return NULL;
    }

    //1. create memory to hold the new string...
    int n = endIndex - beginIndex;
    char *result = (char *) malloc( sizeof(char) * (n + 1) );

    //s is char *
    //s[i] is char
    //char => char *
    //&s[i]
    //use strncpy to copy over n bytes into result...
    strncpy(result, &s[beginIndex], n);
    result[n] = '\0';

    // //2 copy over the characters
    // for(int i=beginIndex; i<endIndex; i++) {
    //     result[i-beginIndex] = s[i];
    // }
    // //2.5 add the null terminator
    // result[n] = '\0';



    return result;
}
```

```java

		//sprintf:
		int x = 42;
		double y = 3.5;
		String name = "Chris";
		String result = String.format("x = %d, y = %f, name = %s", x, y, name);

		String message = "Go Husker Football!!!";
		String a = message.substring(3);
		System.out.println(a);
		String b = message.substring(3, 9);
		System.out.println(b);

```

## Data Processing

* Data is fundamental to CS
* Often data is given in textual manner: not  necessary for humans, but in a readable format
* MOre often data is stored in a *structured format*
  * XML = eXtensible Markup Language
  * JSON = JavaScript Object Notation
  * TSV, CSV = Tab Separated Values, Comma Separated Value
  * These are "flat file" representations
  * Ex: `"Chris,Bourke,2-2400,Avery 104B,Professor of Practice"`
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
  * on each subsequent call, you pass `NULL` to continue with the same string
  * When there are no more tokens, it returns `NULL` to indicate that it is done processing the data

```text














```
