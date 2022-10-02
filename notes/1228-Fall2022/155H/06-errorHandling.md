
# CSCE 155H - Computer Science I - Honors
## Error Handling
### Fall 2022

* Errors can either be completely unexpected or anticipated but not normal
* Some errors, are, by nature *fatal*; the program, in general, *should* die in some cases
* Some errors you *can* recover from (you can anticipate them and not perform the dangerous operation and instead move on in some way)
* This is known as *error handling*: how you "handle" the errors when encountered

## In C

* C uses *defensive programming*: you "look before you leap"
* You write code to detect potentially bad/dangerous operations before they occur
  * If so, you don't do them
  * Instead, if you are in a function you:
  * return an error code that can be interpreted and handled by the calling function
  * Typically you use an integer
  * Convention 0 = no error
  * Non-zero is *some type of error*

## In Java

* Java uses *exceptions*
* Most modern programming languages use exceptions: you `try` a dangerous operation (go ahead and leap)
* If an error occurs, an exception is `throw`n
* Which can then be `catch`ed and dealt with/handled
* Go ahead and do your dangerous operation, if you fall, we will `catch` you

## Defensive Programming in C

* In C, you design functions such that the actual return values are communicated using pass-by-reference variables
* This frees up the return value to be an error code: an integer that indicates the *type* of error encountered

### Solutions

* you can define error codes using the macro `#define ERROR_TYPE 1`
* OR you can use *enumerated types*
* An enumeration is a *list* of things: days of the week, months, etc; *error codes*
* IN C  you can define an enumeration using:

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

* Style:
  * `CAPITAL_UNDERSCORE_CASING` for elements
  * `UpperCamelCasing` for the name
  * Generally whitespace doesn't matter, but it is good to put one to a line
  * Generally place an `enum` in a relevant header file
* Syntax:
  * Use `typedef enum`
  * Comma delimited list inside curly brackets
  * Name of the type at the end with a semicolon
  * Generally they are declared in header files

* Be careful: C actually uses integers to represent enumerated types
* The list items receive an integer value: starting at 0

```c
DayOfWeek today = FRIDAY;
DayOfWeek tomorrow = SATURDAY;

//you can, but be careful with...
tomorrow = today + 10;
DayOfWeek when = FRIDAY + WEDNESDAY;

```

## Tool Demo: valgrind

* Recall that the `-Wall` flag can be used as a *linter*: a *static* analysis tool that examines code *before* you compile
* You can also use *dynamic* analysis tools: tools that examine a *running program* after compilation
* Ex: `valgrind`
* Usage: be sure to compile with the `-g` flag to preserve line numbers and variables, etc.
* Run: `valgrind ./a.out`
* Which produces a report telling you what line(s) it failed on

## Java

* Java uses exceptions instead of defensive programming
* An *exception* is an interruption of the normal linear control flow of a program
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
try {
  double result = MyMath.agm(-10, -20);
} catch(Exception e) {
  //do something about it...
}

int a = 10, b = 0;
if(b == 0) {
  throw new RuntimeException("You cannot do that...");
} else {
  int x = a / b;
}

try {
  Scanner sc2 = new Scanner(new File("bar"));
} catch (FileNotFoundException e1) {
  throw new RuntimeException(e1);
}


String s = "123";
Integer x = null;
int y = 0;

try {

  x = Integer.parseInt(s);
  y = 1 / x;
  System.out.println("x = " + x);
  System.out.println("y = " + y);
  Scanner sc = new Scanner(new File("foo"));
  sc.nextInt();
} catch(NumberFormatException nfe) {

  //choose to handle this situation somehow...
} catch(ArithmeticException ae) {
  //choose to handle in a different way, somehow...
  System.out.println("you cannot divide by zero, setting a default value...");
  x = 1;
  y = 2;
} catch(NullPointerException npe) {
  //a third way...
} catch(Exception e) {
  e.printStackTrace();
  throw new RuntimeException(e);
}

System.out.println("x = " + x);
System.out.println("y = " + y);
System.out.println("Done");
```


```text






```
