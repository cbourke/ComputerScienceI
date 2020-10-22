
# CSCE 155E - Computer Science I
## Encapsulation - Structures
### Fall 2020

* Built-in primitive types (`int, double, char`) are limiting: not everything is a simple number of character
* Real world entities are made up of multiple pieces of data
* Example: Lab 10 had baseball teams
  * It is a bad idea to represent real world entities with separate pieces of data
  * Lots of bookkeeping
  * Ideally, those pieces of *related* data should be collected into one "unit" or "thing" or "entity"
  * In C that entity is a *structure*
* This is generally referred to as *encapsulation*
  1. The grouping of data
  2. The protection of data
  3. THe grouping of functionality that acts on that data
* More of an OOP = Object Oriented Programming concept
* C only really supports #1: the grouping of data

## Defining Structures

* Goal: define a structure that models a book

```c

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  char *firstName;
  char *lastName;
  Date dateOfBirth;
} Person;

typedef struct {
  char *isbn;
  char *title;
  Person author;
  int numberOfPages;
  Date publishDate;
} Book;
```

Observations
* a structure is *composed* of multiple pieces of data
* a structure can be composed of primitive types and/or other strctures
* When a structure "owns" another structure it is called *composition*
* Each variable in a structure is a member variable or "field"
* You can/may want to design a unique identifier field
* Styling/conventions/syntax:
  * Names of structures use `UpperCamelCasing`
  * Names of member variables use `lowerCamelCasing`
  * You use `typedef struct` and opening/closing curly brackets to define what the structure is composed of
  * Semicolons end each variable
  * You provide the name of the structure at the end followed by a semicolon
* Order matters: you must declare a structure before you can use it or use it in other structures
* Usually structures are declared in a header file

## Using structures








