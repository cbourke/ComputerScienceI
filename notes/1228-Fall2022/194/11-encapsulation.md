
# ECEN 194 - Computer Science I
## Encapsulation - Structures
### Fall 2022

## Motivating Exercise

* Given (CSV) data on books, compute various statistics/reports:
  * What is the best book?
  * What is the worst book?
  * What are all books written by Frank Herbert?

## Introduction

* Built-in primitive types `int, double, char` are very limiting: not everything is a number or character
* Real world entities are *composed* of multiple pieces of data
* Encapsulation is when you group multiple pieces of data together into one "object" or "thing"
* Solution in C: structures
* You can define a structure using the `typedef struct` keyword
* Encapsulation is a mechanism by which you can:
  1. Group pieces of data together into one logical "unit"
  2. Protect that data from the outside world
  3. Group functionality that acts on that data with the data
* C only supports #1: weak encapsulation

### Defining Structures

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
} Author;

typedef struct {
  char *title;
  Author author;
  double rating;
  Date releaseDate;
} Book;


```

Observations:
* YOu use the keywords `typedef struct` and within curly brackets provide a "list" of the structure's *member variables*
* Each one is ended with a semicolon: `;`
* The name of the structure is provided at the end with a semicolon
* The name should follow an `UpperCamelCasing` convention
* Member variables should use a `lowerCamelCasing` convention
* When a structure contains another structure, it is known as *composition*
* When you declare an "instance" of your structure, you can access its member variable variables using the "dot" operator: `.`

## Constructors or "Factory" functions

* Creating instances of structures can be a lot of boilerplate code
* Instead: create a function to do the grunt work for you!
* OOP: this would be a "constructor"
* C: factory functions


```text









```
