
# CSCE 155H - Computer Science I - Honors
## Error Handling
### Fall 2025

* Errors can either be completely unexpected or anticipated but not normal
* Some errors, are, by nature *fatal*; the program, in general, *should* die in some cases
* Some errors you *can* recover from (you can anticipate them and not perform the dangerous operation and instead move on in some way)
* This is known as *error handling*: how you "handle" the errors when encountered

1. C: Defensive Programming: "looking before you leap"
  * You write code to detect potentially dangerous or bad operations before they occur
  * Instead of executing that code (dangerous operation) you stop and if in a function:
    * YOU return an *error code*: an integer indicating a *type* of error
    * YOU do NOT:
      * print any error message
      * You do NOT exit
    * Convention: 0 = no error, non-zero: some kind of error (1, 2, 3, etc.)
2. Java: exceptions, it is okay to leap before you look because if something bad happens, we will `catch` you and `throw` you back up

## Defensive Programming in C

* In C, you design functions such that the actual return values are communicated using pass-by-reference variables
* This frees up the return value to be an error code: an integer that indicates the *type* of error encountered

### Standard Libraries: `errno.h` library

* errno = error number

### Solution to Magic Numbers: Enumerated Types

* One option to avoid magic numbers: use `#define` macros

```c
#define NO_ERROR 0
#define COMPLEX_ROOT_ERROR 1
#define DIVIDE_BY_ZERO_ERROR 2
#define NULL_POINTER_ERROR 3
```

* An alternate, "better" solution: use enumerated types
* An enumeration is a list
* Example: days of the week, months, error codes
* In C you can use an *enumerated type* and give a predefined list of valid, human-readable values to them

```c
typedef enum {
  SUNDAY,
  MONDAY,
  TUESDAY,
  WEDNESDAY,
  THURSDAY,
  FRIDAY,
  SATURDAY,
} DayOfWeek;

//later in the program...

DayOfWeek today = FRIDAY;
if(today == FRIDAY) {
  printf("get ready for the weekend!\n");
}
```

* Careful: this is NOT a true type in C
* Instead: C assigns an `int` value to each (starting at zero)
* `SUNDAY = 0`, `MONDAY = 1`, etc., `SATURDAY = 6`
* Consequences:

```c
DayOfWeek today = Friday;
today += 1; //SATURDAY!
today += 1; //7, an invalid value
today = (today + 5) % 7;
```

* Style:
  * `UPPER_UNDERSCORE_CASING` for elements
  * `UpperCamelCasing` for the name
  * Generally whitespace doesn't matter, but it is good to put one to a line
* Syntax:
  * Use `typedef enum`
  * Comma delimited list inside curly brackets
  * The name of the type was at the end + semicolon
  * Generally you declare these things in a header file
  * Note: the coding oxford comma!

* Java also has enumerated types
  * Key difference: they are *NOT* integers

## Error Handling in Java: `Exception`s

* Java uses exceptions instead of defensive programming
* An *exception* is an interruption of the normal linear flow of control
* Philosophy: go ahead and leap before you look: `try` a potentially dangerous operation, we'll `catch` you if you fall and then you can handle the error
* Advantages:
  * With error codes, there is no *semantic* meaning to the code, it is just a number; even if you don't use magic numbers, they are all still just integers
  * But with exceptions, you *do* have semantic meaning: a `NullPointerException` is not the same thing as a `ArithmeticException` which is not the same thing as `InputMismatchException`
  * Often defensive programming leads to large, nested and separate error handling code and "GOTO FAIL" style errors
  * In Java all exceptions are a "subclass" of `Throwable` objects
    * `Error`: mainly used by the JVM and is always fatal
    * `Exception`: this is what you *do* use in your code; there are two types of exceptions:
      * `RuntimeException`: an "unchecked" exception: you may surround it with a `try-catch` if you choose, or not (in which case its fatal)  
      * Other exceptions are "checked" exceptions: you are *forced* to surround them with a try-catch block
      * Uusal way of handling them: catch and release

```java

		String input = "1234";
		int n = 0;
		Integer m = 10;


		try {
			n = Integer.parseInt(input);
			n = n + m;
			System.out.println("Hello");
			Scanner s = new Scanner(new File("Nonexistantfile.txt"));
		} catch(NumberFormatException nfe) {
			System.err.println("error occurred! (number format bad)");
		} catch(NullPointerException npe) {
			//System.err.println("error occurred! (null pointer)");
			n = n + 1;
		} catch(Exception e) {
			throw new RuntimeException(e);
		} finally {
			//anything that should happen regardless of an exception or not
			// this block gets executed in either case
			System.out.println("foo!");
		}


		System.out.println("okay");
		System.out.println(n);

		try {
			Scanner s2 = new Scanner(new File("Nonexistantfile.txt"));
		} catch (FileNotFoundException e) {
			throw new RuntimeException(e);
		}
```

```text









```
