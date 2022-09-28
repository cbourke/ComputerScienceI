
# CSCE 155E - Computer Science I
## Error Handling
### Fall 2022

* Errors can either be completely unexpected or anticipated but not normal
* Some errors, are, by nature *fatal*; the program, in general, *should* die in some cases
* Some errors you *can* recover from (you can anticipate them and not perform the dangerous operation and instead move on in some way)
* This is known as *error handling*: how you "handle" the errors when encountered

## In C:

* C uses *defensive programming*: "look before you leap"
* You write code to detect potentially bad/dangerous operations before they occur
* Example

```c
double a, b;
//TODO; read values in...

double x = a / b;

//instead:

if(b == 0) {
  //DONT DIVIDE, DO SOMETHING ELSE
} else {
  x = a / b;
}

```
* If an error condition is detected, you don't do the potentially dangerous code
* Instead, from a function, you:
  * Immediately return without doing the dangerous code
  * You return an error code to the calling function to communicate the type of error that occurred
  * You *DON'T* exit the program
  * YOu *DON'T* print anything
  * the calling function then has the responsibility (or option) to deal with the problem or error

* To do this, make all of your result values as pass-by-reference variables
* Use the return type to return an integer: `int` that indicates the *type* of error that occurred
  * convention: `0` indicates no error (false, no error)
  * non-zero indicates *yes* there was an error

## Solution: use enumerated types

* You *could* define macros using the `#define ERROR_TYPE 1`
* OR you can use an *enumerated type*
* An enumeration is a *list* of things: days of the week, months, etc; *error codes*
* In C, you can define an enumeration:

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

//later in the program, you can use your own type!

DayOfWeek today = WEDNESDAY;

```

* Style/Syntax observations:
  * You use `typedef enum` to define a enumeration
  * Within the opening/closing curly brackets you have the list
  * one item to a line, separated by commas
  * Values use an `UPPER_UNDERSCORE_NAMING_CONVENTION`
  * At the end you give your type a name followed by a semicolon
  * The name should be `UpperCamelCased`


```c
typedef enum {
  JANUARY,
  FEBRUARY,
  MARCH,
  APRIL,
  ...

} Month;


```

```text





```
