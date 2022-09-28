
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



```text






```
