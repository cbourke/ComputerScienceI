
# CSCE 155E - Computer Science I
## Encapsulation - Structures
### Fall 2025

* Built-in primitive types (`int, double, char`) are limiting: not everything is a simple number of character
* Real world entities are made up of multiple pieces of data
* In programming languages you can *collect* and **encapsulate** multiple pieces of data together into one logical unit
* In C this is achieved using *structures*
* Structures are "weak" encapsulation
* Encapsulation in general:
  1. The grouping of data
  2. The protection of data
  3. The grouping of functionality that acts on that data
* C is NOT an OOP language and only supports #1 ("weak" encapsulation)

## Defining Structures

* Create a structure that models a *book*
  * You use the syntax: `typedef struct`
  * You place a collection of variables inside `{}` (delimited by `;`)
  * You provide a name at the end + `;`
  * Generally: modern convention is to use `UpperCamelCasing`
  * Generally, structure declarations are placed into header files, often of similar name, `book.h`
  * Generally you should document them
  * Order matters: if you use *composition* (one structure is composed of other structures) then you need to declare the used structures first

```text













```
