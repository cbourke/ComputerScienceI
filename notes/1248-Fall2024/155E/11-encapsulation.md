
# CSCE 155E - Computer Science I
## Encapsulation - Structures
### Fall 2024

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
* Usage:
  * Once defined you can declare them: `Book b1;` or a pointer: `Book *b2;`
  * To access member variables of a regular-old-struture: dot operator: `b1.isbn`
  * to access member variables of a pointer-to-structure: arrow operator: `b2->isbn`
* You can define factory functions to create new instances of your structure, returning a pointer to a *dynamically allocated* instance of the structure
  * remember: to use `sizeof(Book)` with `malloc()`
* Other common functions:
  * a "to string" function that formats the structure as a string `char *`
  * A "destructor" function: `freeBook()` that frees *all* memory assoicated with the structure
  * An "initializer" function: if you already have an instance of a book, you can pass it as a pointer and *initialize* instead of create
  * Bulk functions: print all books, destroy all books, etc. that operate on *arrays* of structures

```text









```
