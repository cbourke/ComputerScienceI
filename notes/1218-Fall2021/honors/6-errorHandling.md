
# CSCE 155H - Computer Science I - Honors
## Error Handling
### Fall 2021

* Errors can either be completely unexpected or anticipated but not normal
* Some errors, are, by nature *fatal*; the program, in general, *should* die in some cases
* Some errors you *can* recover from (you can anticipate them and not perform the dangerous operation and instead move on in some way)
* This is known as *error handling*: how you "handle" the errors when encountered

1. C: Defensive Programming: "looking before you leap"
  * You write code to detect potentially bad/dangerous operations before they occur
  * If they would occur, you don't do the operation
  * Instead, within a function you return an *error code*
    * An integer value that represents the type of error that would of occurred
    * 0 = no error
    * 1, 2, 3, etc. (non-zero value) indicates some type of error
2. Exceptions
  * "Modern" programming languages support exceptions
  * You can go ahead and `try` to perform dangerous operations without looking before you leap
  * Its okay because if an error (exception) occurs, it will `catch`

## Defensive Programming in C

* In C, you design functions such that the actual return values are communicated using pass-by-reference variables
* This frees up the return value to be an error code: an integer that indicates the *type* of error encountered


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
} dayOfWeek;
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
* Later in the program...

```c
DayOfWeek today = THURSDAY;
DayOfWeek tomorrow = THURSDAY + 1;
//you can but shouldn't:
DayOfWeek when = MONDAY + THURSDAY;
when = today + 500;
```

* In C, all enumerated types are actually integers
* The first item in the list gets the value 0 by default, each one after is incremented by 1 (`SUNDAY = 0, MONDAY = 1, SATURDAY = 6`)
* BE CAREFUL, do not use enumerated types in numerical expressions, only for setting/conditionals

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

```java

		int a = 10;
		Integer b = 10;
		try {
			int c = (a / b);
		} catch (ArithmeticException ae) {
			System.out.println("INFINIITY, look into the void!");
			ae.printStackTrace();
			// TODO: decide what to do here!
		} catch (NullPointerException npe) {
			npe.printStackTrace();
			// TODO: potentially handle this differently
		} catch (Exception e) {
			// this block will handle ANY OTHER TYPE of Exception
		}

		Scanner s = null;
		try {
			s = new Scanner(new File("data/input.txt"));
			int x = s.nextInt();
			System.out.println(x);
		} catch (FileNotFoundException e1) {
			// e1.printStackTrace();
			throw new RuntimeException(e1);
 		} finally {

			// this block of code is executed *regardless* of any
			// exception
			if (s != null) {
				s.close();
			}
		}

		System.out.println("done");

```

## Unit Testing

* Design and **rigorously test** a function to compute the amount of change: given a dollar amount in the range 0 thru .99 and "outputs" the number of quarters, dimes, nickels and pennies to make change.
* Rigorous testing = automated unit testing
  * A unit in code is simply some indivisible piece of code: a snippet, it could be an entire library
  * For us, our "unit" will be a function
  * A unit test is a triple: input, expected output, the actual output
  * Your test *passes* the unit test if the expected output "matches" the actual output
  * Generally, the expected output is computed using *some other means*: a calculator, some online resource, etc.
  * You can have *false positives*: your test passes but your code is actually wrong
  * You can have *false negatives*: your test fails, but your code is actually right
  * Unit testing never provides a 100% guarantee that your code is correct
  * Many tests and good *test coverage* provide a *high* assurance that your code is correct
  * Testing can be tedious but it can be made better by using a *formal testing framework*
    * C: cmocka
    * Java: junit




```text






```
