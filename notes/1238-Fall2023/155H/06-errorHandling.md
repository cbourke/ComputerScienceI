
# CSCE 155H - Computer Science I - Honors
## Error Handling
### Fall 2023

* Errors can either be completely unexpected or anticipated but not normal
* Some errors, are, by nature *fatal*; the program, in general, *should* die in some cases
* Some errors you *can* recover from (you can anticipate them and not perform the dangerous operation and instead move on in some way)
* This is known as *error handling*: how you "handle" the errors when encountered

1. C: Defensive Programming: "looking before you leap"
  * YOU write code to detect potentially dangerous or bad operations before they occur
  * Instead of executing those operations, you stop and if in a function, return with an error code
  * YOU do NOT:
    * Exit
    * Nor print anything
  * Convention: 0 = no error, non-zero = some kind of error
  * Best practice: you use human-readable terms (`#define` or an `enum`)
2. Java: exceptions, it is okay to leap before you look because if something bad happens, we will `catch` you and `throw` you back up

## Defensive Programming in C

* In C, you design functions such that the actual return values are communicated using pass-by-reference variables
* This frees up the return value to be an error code: an integer that indicates the *type* of error encountered

### Standard Libraries: `errno.h` library

* errno = error number

### Solution to Magic Numbers: Enumerated Types

* Many pieces of data have small or limited number of possible values
* Example: days of the week, months, error codes
* In C, you can define an *enumerated type* and give predefined, human-readable names to them

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
```

* Careful: in C these are just integers and can be treated as such (*but should not be*!)

```c
DayOfWeek today = FRIDAY;
today++; //now its SATURDAY
today++; //now its !?!?!
//alternatively:
today = (today + 2) % 7;

```

* Style:
  * `CAPITAL_UNDERSCORE_CASING` for elements
  * `UpperCamelCasing` for the name
  * Generally whitespace doesn't matter, but it is good to put one to a line
* Syntax:
  * Use `typedef enum`
  * Comma delimited list inside curly brackets
  * Name of the type at the end with a semicolon
  * Generally they are declared in header files

* Java also has enumerated types
  * Key difference: they are *NOT* integers

## Error handling in Java: Exceptions

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
      * `Exception`: a "checked" exception: you are forced to surround it with `try-catch` statement and decide what to do with it
      * `RuntimeException`: an "unchecked" exception: you may surround it with a `try-catch` if you choose, or not (in which case its fatal)  
      * Usually you have to deal with checked exceptions by rethrowing them as `RuntimeException`

```java

		int a = 10;
		Integer b = 0;


		try {
			double c = a / b;
			System.out.println(c);
		} catch(ArithmeticException ae) {
			System.err.println("Cannot divide by zero!");
			//System.exit(1);
		} catch(NullPointerException npe) {
			System.err.println("Cannot divide by null!");
			npe.printStackTrace();
		} catch(Exception e) {
			System.err.println("Something really bad happened!");
			System.exit(1);
		} finally {
			//regardless of an error or no error, this block is executed at
			// the end
			System.out.println("Moving on...");
		}

		System.out.println("Oh, well, let's do the rest of hte program...");

```

```text






```
