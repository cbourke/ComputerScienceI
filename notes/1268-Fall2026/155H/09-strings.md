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


```text














```
