
# CSCE 155H - Computer Science I
## Encapsulation - Structures & Classes
### Fall 2023

* Built-in primitive types `int, double, char` are very limiting: not everything is a number or character
* Real world entities are *composed* of multiple pieces of data
* Encapsulating multiple pieces of data into one "object" or "thing" allows you to deal with that one "thing"
* Solution: encapsulation
  * C: structures
  * Java: Class
* Encapsulation is a mechanism that allows you to:
  1. Group pieces of data together to form one logical "unit"
  2. Protect that data from the outside world/code
  3. Group functionality that acts on that data with the data
* Java: supports all three, it has *strong* encapsulation (because it is an OOP = Object-Oriented Programming language)
* C: weak encapsulation, it only supports #1

## Java

* Java is an OOP language that uses classes for encapsulation
  * Class names are `UpperCamelCased`
  * *Member variables* are `lowerCamelCased`
* Java supports "strong encapsulation": you can "protect" your variables from the outside world
    * `public` - ANY code can see and change your variables!
    * The lack of a keyword makes a variable "package protected"
    * `protected` - the class and any subclass can see your variables (involves inheritance)
    * `private` - only your class can "see" the variables, in general make all of your variables `private` unless there is Very Good Reason to do so
* Java allows you to define *nontrivial* methods; ex: `getAge()`
  * It would be *bad design* to locate this functionality *outside* the class
