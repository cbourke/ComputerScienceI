
# CSCE 155H - Computer Science I - Honors
## Error Handling
### Fall 2024

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

* Many pieces of data have small or limited number of possible values
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

...

DayOfWeek today = WEDNESDAY;
if(today == FRIDAY) {
  printf("get ready for the weekend!\n");
}
```

* Careful: the way C does this is by associating the values with integer types (starting at zero)
* `SUNDAY = 0`, `MONDAY = 1`, ... `SATURDAY = 6`
* Consequences:

```c
DayOfWeek today = WEDNESDAY;
today += 1; //okay, now it is Thursday
today = SATURDAY;
today += 1;

```

* Style:
  * `CAPITAL_UNDERSCORE_CASING` for elements
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

		Integer x = null;
		int z;

		try {
			//z = x + 10;
			String s = "Hello world";
			int a = Integer.parseInt(s);
			x = 0;
			int y = 1 / x;
			System.out.println("Line 23");
		} catch (ArithmeticException ae) {
			System.err.println("You tried to divide by zero, x was zero..");
		} catch (NullPointerException npe) {
			x = 0;
			z = x + 10;
		} catch (NumberFormatException nfe) {
			//TODO: do something else
		} catch (Exception e) {
//			System.err.println("Exception occurred");
//			e.printStackTrace();
//			System.exit(1);
			throw new RuntimeException(e);
		}

		File f = new File("/data/foo.txt");
		try {
			Scanner s = new Scanner(f);
		} catch (FileNotFoundException e) {
			throw new RuntimeException(e);
		}

		System.out.println("the rest of the program");

  ```

```text









```
