
# CSCE 155E - Computer Science I
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
* Encapsulating multiple pieces of data into one "object" or "thing" allows you to deal with that one "thing"
* Solution: encapsulation
  * C: structures
* YOu can define a user-defined type called a `struct` that allows you to collect multiple pieces of data into one logical unit
* Encapsulation is a mechanism that allows you to:
  1. Group pieces of data together into one logical "unit"
  2. Protect that data from the outside world
  3. Group functionality that acts on that data with the data

## Demo

* Observations:
  * A structure is *composed* of multiple pieces of data or even *other structures* this is called "composition"
  * Order of declaration matters: if one structure uses another, it must be declared first
  * The variables inside of a structure are called *member variables*
  * WHen you create an actual variable of that type, it is known as an "instance"
  * `Book b; //b is an "instance" of the Book structure`
  * To access member variables of a regular old structure you use the dot operator: `.`; example: `b.title = ...`
  * Style notes:
    * Names of structures should be `UpperCamelCased`
    * Member variables should be `lowerCamelCased`
    * You end the definition with a semicolon
    * Member variables are ended with a semicolon

## Using Structures

* Once defined, you can create instances of a structure or pointer to instances of structures: `Book b`, `Book *b`
* To access member variables of a pointer to a structure, use the arrow operator: `b->rating`
* You can/should define utility functions:
  * You can define a factory function to create new instances
  * You can define "to string" functions to print or convert data to a human-readable format
  * You can define "destructor" functions to free up memory properly
  * You can also define "initialization" versions of a function: suppose that an instance already exists, you simply need to assign/allocate its values


```text









```
