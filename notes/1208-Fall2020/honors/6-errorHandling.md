
# CSCE 155H - Computer Science I - Honors
## Error Handling
### Fall 2020

* Errors can either be completely unexpected or anticipated but not normal
* Some errors, are, by nature *fatal*; the program, in general, *should* die in some cases
* Some errors you *can* recover from (you can anticipate them and not perform the dangerous operation and instead move on in some way)
* This is known as *error handling*: how you "handle" the errors when encountered

1. Defensive Programming: "look before you leap"
  * You write code to detect potentially bad/dangerous operations before they occur
  * If they would occur, you don't do them
  * Instead, you return an *error code* from the function and let the calling function *handle* the error (it decides what to do)
  * It is the calling function's responsibility to decide what happens
  * By convention 0 is associated with "no error"
  * Non-zero values indicate a particular type of error
2. Exceptions
  * "Modern" programming language support exceptions
  * Go ahead and leap before you look; if you fall, we'll `catch` you and let you recover
  * You can write exceptions using a `try` keyword (you "try" the dangerous operation), and the code may `catch` an exception
  
## Defensive Programming in C


* In C, you design functions such that the actual return values are communicated using pass-by-reference variables
* This frees up the return value to be an error code: an integer that indicates the *type* of error encountered
* In general: zero indicates no error
* In general: don't use magic numbers (mysterious numbers that have no apparent meaning): it makes your code unreadable and unmaintainable 

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
  SATURDAY
} DayOfWeek;
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
DayOfWeek foo = MONDAY + 500;//has the value 501
```

* In C, all enumerated types are actually integers
* The first item in the list gets the value 0 by default, each one after is incremented by 1 (`SUNDAY = 0, MONDAY = 1, SATURDAY = 6`)
* BE CAREFUL, do not use enumerated types in numerical expressions, only for setting/conditionals

## How C does system-level error handling

* The POSIX = Portable Operating System Interface standard defines only 3 error codes:
  * `EDOM`: indicates an error in the *domain* of a function: ie an error in the input; example: `sqrt(-1)`
  * `ERANGE`: indicates an error in the *range* of a function: ie an error in the output; example: `log(0)`
  * `EILSEQ`: indicates an illegal byte sequence
* All of these (and more) are defined in a header file, `errno.h` (error number)
* Instead of returning an error code, a global variable named `errno` (an int) is set, convention: 0 is no error, 

## Error handling in Java: Exceptions

* Java uses exceptions instead of defensive programming
* An *exception* is an interruption of the normal linear flow of control
* Philosophy: go ahead and leap before you look: `try` a potentially dangerous operation, we'll `catch` you if you fall and then you can handle the error
* Advantages:
  * With error codes, there is no *semantic* meaning to the code, it is just a number; even if you don't use magic numbers, they are all still just integers
  * But with exceptions, you *do* have semantic meaning: a `NullPointerException` is not the same thing as a `ArithmeticException` which is not the same thing as `InputMismatchException`
  * Often defensive programming leads to large, nested and separate error handling code and "GOTO FAIL" style errors
  
### Exceptions in Java

```java
int a = 10;
int b = 0;
try {
  int c = a / b;
  System.out.println("c = " + c);
} catch(NullPointerException npe) {
  System.out.println("uh, the denominator is null");
  //TODO: decide what to do here!
  //do something else??
} catch(ArithmeticException ae) {
  System.out.println("INFINIITY, look into the void!");
  throw new RuntimeException(ae);			
  //TODO: decide what to do here!
} catch(Exception e) {
  //this will catch any other type of exception
  //TODO: decide what to do here!
  throw new RuntimeException(e);
}
```

* In Java all exceptions are a "subclass" of `Throwable` objects
  * `Error`: mainly used by the JVM and is always fatal
  * `Exception`: this is what you *do* use in your code; there are two types of exceptions:
    * `Exception`: a "checked" exception: you are forced to surround it with `try-catch` statement and decide what to do with it
    * `RuntimeException`: an "unchecked" exception: you may surround it with a `try-catch` if you choose, or not (in which case its fatal)  
* Checked exceptions were a mistake, but we still have to live with them
* In general, if you *have* to surround a piece of code because of a checked exception: catch and release: `catch` the exception and (re)`throw` it as a `RuntimeException`

```java
try {
  Scanner s = new Scanner(new File("input.txt"));
} catch (FileNotFoundException e1) {
  throw new RuntimeException(e1);			
}
```

* You can also define your own types of exceptions by defining a class:

```java

public class TimeException extends RuntimeException {

	public TimeException(String message) {
		super(message);
	}
	
}
```

* With `try-catch` blocks you can also have a `finally` block
* The `finally` block will execute regardless of whether or not an exception occurred
* Use case: if you have open resources that still need to be cleaned up
  * Example: you successfully connect to the database, but the table you are querying is missing: EXCEPTION
  * The database connection is still open
  * To close it, put the "close the database" code into a `finally` block
* Java 7 or 8 introduced a "try with resources" syntax that automatically closes resources for you without a `finally` block

```text






```