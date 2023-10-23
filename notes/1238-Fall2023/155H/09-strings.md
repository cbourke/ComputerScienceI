
# CSCE 155H - Computer Science I
## Strings
### Fall 2023

* A *string* is a sequence of characters
  * In C, *strings* are ordered sequences of ASCII characters
  * In Java, strings are Unicode characters; 🎃 (U+1F383), 👻 (U+1F47B)
  * In C, strings are *null-terminated* arrays of `char` elements
  * IN Java, strings are unicode `byte` arrays

## Strings in C

* In C, a *string* is a null-terminated array of `char` elements
* In C, you have characters in the array but at the end of the array, you need a *null-terminating* character: `\0`
  * It is NOT zero
  * It is NOT the endline character: `\n`
  * It is NOT `NULL`

```c

  //strings can be declared this way:
  char message[] = "hello World!";
  //strings are mutable: their contents can be changed:
  message[0] = 'H';

  char b[100] = "hello World!";
  b[0] = 'H';
  b[12] = '!';
  b[13] = '!';
  //always, ALWAYS, null-terminate your strings:
  b[14] = '\0';

  //this syntax creates a read-only string:
  char *c = "hello World!";
  //c[0] = 'H';
```

```c
char message[1000];

//print a string using the __ placeholder:
printf("message = %s\n", message);

//generally they are filled with garbage (no default value):
// for(int i=0; i<1000; i++) {
//   printf("message[%d] = %c (%d)\n", i, message[i], message[i]);
// }

message[0] = '\0';
printf("message = %s\n", message);
```

```text









```
