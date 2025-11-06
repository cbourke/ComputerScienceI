
# CSCE 155H - Computer Science I
## Encapsulation - Structures/Classes
### Fall 2025

* Built-in primitive types `int, double, char` are very limiting: not everything is a number or character
* Real world entities are *composed* of multiple pieces of data
* Encapsulating multiple pieces of data into one "object" or "thing" allows you to deal with that one "thing"
* Solution: encapsulation
  * C: structures
  * Java: Classes
* Encapsulation is a mechanism that allows you to:
  1. Group pieces of data together to form one logical "unit"
  2. Protect that data from the outside world/code
  3. Group functionality that acts on that data with the data
* C: weak encapsulation, it only supports #1
* Java: supports all three, it has *strong* encapsulation (because it is an OOP = Object-Oriented Programming language)

## C

* C only supports *weak* encapsulation: #1 the grouping of data through *structures*
* Defining a structure:
  * Define using `typedef struct`
  * Generally: use `UpperCamelCasing` for structure names
  * Use `lowerCamelCasing` for structure variables
  * Declaration order matters!
  * If a structure is composed of other structures, those "other" structures need to be declared *first*
* Other:
  * IF you have a regular structure, `Book b`, then use the dot operator: `b.title`
  * If you have a pointer: `Book *b` then use the arrow operator
  `b->title`

## Java

* Java is an OOP language that uses classes for encapsulation


```text










```
