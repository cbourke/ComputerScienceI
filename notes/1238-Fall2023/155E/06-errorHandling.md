
# Computer Science I
## CSCE 155E - Fall 2023
### Error Handling

* Programs always have potential for errors
* Some errors can be unexpected
* You may be able to anticipate errors and *protect* your program against them
  * You write code to test for errors and then deal them or *handle" them
  * Sometimes errors can be/should be *fatal*
* In C our general strategy is *defensive programming*
  * Inside of a function, we test for invalid input or error conditions
  * "Look before we leap"
  * If you are about to do something potentially dangerous you check for any "bad" or "error" conditions
  * Generally, you return from a function with an *error code*
    * 0 = no error
    * 1, 2, 3 = some kind of error
    * THe value of the error code tells you what *type* of error occurred
* BAD error handling:
  * You don't exit in a function (other than `main()`), it takes control away from the "calling function" or code
  * You do not print anything!  Instead (in practice) you use a proper logging system.
* Misc:
  * YOu generally do not want to use mysterious "magic numbers"; instead use either preprocessor directions `#define` or an enumerated type `enum`

## C Enumerated Types

* many pieces of data have a fixed number of limited possible values
* Example: days of the week, months, error codes
* In C you can define an enumerated type with human-readable "terms" as your possible values

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

* Observations:
  * Use `UPPER_UNDERSCORE_CASING` for list items
  * Use `UpperCamelCasing` for the names of the enumerated type
  * One item per line, separated by commas
* Later in hte program you can use your type:

```c
DayOfWeek today;
today = FRIDAY;

if(today == SATURDAY) {
  printf("Let's play the game even so...\n");
}
```

## How do `enum`s actually work?

* Internally, `enum` is just *syntactic sugar* for `int` variables!
* Each value in an `enum` is just an integer
* The list begins with 0 and is incremented by 1
* Example: `SUNDAY` has a value of 0, `MONDAY` has a value of 1, etc.
* `SATURDAY` has a value of 6
* Be careful: just because they are integers, doesn't mean  you should treat them as integers

```c
DayOfWeek today = FRIDAY;
DayOfWeek tomorrow = today + 1;
DayOfWeek theDayAfterTomorrow = tomorrow + 1;

today = today + 30; //valid operation, but nonsense results
```

* Take away: understand that enumerated types are integers, but DO NOT TREAT THEM like integers

## How does C do error handling?

* Internally, the C language does define 3 error codes:
  * `EDOM` - an error in the *domain* of a function (input)
  * `ERANGE` - an error in the *range* of a function (output)
  * `EILSEQ` - an illegal byte sequence
* Defined along with some tools in the `errno.h` library
* Generally you will *not* use this library directly
* There are other standards that define *more* error codes:
  * POSIX = Portable Operating System Interface
  * Various other extensions
* In "user land" (our programs), you generally need to define your *own* error codes and enumerated, etc.

## Best Practices:

* In a function, when do you do error handling/checking?  FIRST
* Always do error checking/handling before any actual code
* Which comes first: `NULL` checks or value checks `>= 0`
* You always check pointers FIRST!  Otherwise you may be *dereferencing a null pointer!!!*
* Don't: exit in a function, don't print anything!
* If an error occurs, *return with an error code*, do not move on and do other things!
* General form: a collection of `if-else-if` statements with return values
* The rest of the function should *not* be in one giant `else` statement
* Be sure to return 0 for no error
* Omission of a valid return statement may lead to garbage results!
* Always use the `-Wall` flag!

```text











```
