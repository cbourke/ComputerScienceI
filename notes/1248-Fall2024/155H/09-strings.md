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


```text














```
