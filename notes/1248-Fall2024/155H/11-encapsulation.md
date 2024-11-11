
# CSCE 155H - Computer Science I
## Encapsulation - Structures/Classes
### Fall 2024

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
  * Generally: use `UpperCamelCasing` for structure name
  * Use `lowerCamelCasing` for structure variables
  * Declaration order matters
* Other:
  * IF you have a regular structure, `Book b`, then use the dot operator: `b.title`
  * If you have a pointer: `Book *b` then use the arrow operator
  `b->title`

## Java

* Java is an OOP language that uses classes for encapsulation
  * Class names are `UpperCamelCased`
  * *Member variables* are `lowerCamelCased`
* Recall that Java offers **strong** encapsulation
* Java supports "strong encapsulation": you can "protect" your variables from the outside world
  * `public` allows *any* piece of code to change or view your variables!  Chaos!
  * `protected` (inheritance: next semester)
  * `private`: only the class and instances of the class can see the variable
  * Best practice: make everything `private` unless you have a Very Good Reason
* YOu can control access through getters/setters (but generally you prefer *immutable objects*)
* Java allows you to define *nontrivial* methods; ex: `getAge()`


```text




```
