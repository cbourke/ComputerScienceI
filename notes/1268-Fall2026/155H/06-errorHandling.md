
# CSCE 155H - Computer Science I - Honors
## Error Handling
### Fall 2026

* Errors can either be completely unexpected or anticipated but not normal
* Some errors, are, by nature *fatal*; the program, in general, *should* die in some cases
* Some errors you *can* recover from (you can anticipate them and not perform the dangerous operation and instead move on in some way)
* This is known as *error handling*: how you "handle" the errors when encountered

1. C: Defensive Programming: "looking before you leap"

  * You write code to detect potentially dangerous or bad operations before they occur
  * Instead of executing that code, in a function you STOP and:
    * You return an *error code*: an integer indicating the *type* of error that occurred
    * You do **NOT**:
      - print an error message
      - exit
    * Convention: 0 = no error; non-zero is some kind of error (1, 2, 3, etc.)

2. Java: use exceptions, it is okay to leap before you look because if something bad happens, you can `catch` the falling program and `throw` them back up to safety


## Defensive Programming in C

* In C, you design functions such that the actual return values are communicated using pass-by-reference variables
* This frees up the return value to be an error code: an integer that indicates the *type* of error encountered

### Standard Libraries: `errno.h` library

* errno = error number

### Solution to Magic Numbers: Enumerated Types

* One option to avoid magic numbers: use `#define` macros
* An alternate, "better" solution: use enumerated types
* An enumeration is a list
* In C you can define an enumerated type and give it a predeinfed list of valid, human-readable values
* Example: days of the week

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

* Later on in the program...

```c
DayOfWeek today = FRIDAY;
if(today == FRIDAY) {
  printf("get ready for the weekend!\n");
}

```

* Careful: this is NOT a true type in C
* Instead: internally C assigns `int` values to each item starting at zero
* Example: `SUNDAY = 0`, `MONDAY = 1`, ... `SATURDAY = 6`
* Consequences: you can, but should NOT do basic math on `enum`s

```c
DayOfWeek today = SATURDAY;
today += 1;
//today is now 8, invalid!
```

* Style:
  * `UPPER_UNDERSCORE_CASING` for elements
  * `UpperCamelCasing` for the name
  * Generally whitespace doesn't matter, but it is good to put one to a line
* Syntax:
  * Use `typedef enum`
  * Comma delimited list inside the curly brackets
  * THe name goes at the end + semicolon
  * Generally you place the declaration in a header file
  * Note: the coding oxford comma (optional)

## Error Handling in Java: `Exception`s

* Java uses exceptions instead of defensive programming
* An *exception* is an interruption of the normal linear flow of control
* Philosophy: go ahead and leap before you look: `try` a potentially dangerous operation, we'll `catch` you if you fall and then you can handle the error
* Advantages:
  * With error codes, there is no *semantic* meaning to the code, it is just a number; even if you don't use magic numbers, they are all still just integers
  * But with exceptions, you *do* have semantic meaning: a `NullPointerException` is not the same thing as a `ArithmeticException` which is not the same thing as `InputMismatchException`
  * Often defensive programming leads to large, nested and separate error handling code and "GOTO FAIL" style errors
  * Often defensive programming leads to large, nested and separate error handling code and "GOTO FAIL" style errors
  * In Java all exceptions are a "subclass" of `Throwable` objects
    * `Error`: mainly used by the JVM and is *always* fatal
    * `Exception`: this is what you do use in your code
      * `RuntimeException`: you *may* or *may not* surround with a `try-catch`
      * Checked exceptions: you are forced by Java to surround them with a `try-catch` block: the usual solution is to *rethrow* as a `RuntimeException`

```java

		int a = 0;

		//throw new ComplexRootException("Cannot handle complex roots");

		int b;
		if(a == 0) {
			throw new RuntimeException("a is zero, cannot divide by it");
		} else {
			b = 10 / a;
		}

		String input = "1234";
		int n = 0;
		Integer m = 0;

		try {
			n = Integer.parseInt(input);
			n = n + m;
			System.out.println("Hello");
			Scanner s = new Scanner(new File("foo.txt"));
		} catch(NumberFormatException nfe) {
			//handle a bad input, somehow...
			//alternative: don't handle it...
			throw new RuntimeException(nfe);
		} catch(NullPointerException npe) {
			n = n + 0;
		} catch(FileNotFoundException fnfe) {
			//TODO: create the file
			//generally checked exceptions should be rethrown as
			throw new RuntimeException(fnfe);
		} catch(Exception e) {
			throw new RuntimeException(e);
		}

		System.out.println("Done with the program");
```
```text












```
