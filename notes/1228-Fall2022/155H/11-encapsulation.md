
# CSCE 155H - Computer Science I
## Encapsulation - Structures & Classes
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
  * Java: Classes
* Encapsulation is a mechanism that allows you to:
  1. Group pieces of data together into one logical "unit"
  2. Protect that data from the outside world
  3. Group functionality that acts on that data with the data
* C: structures support just #1 (weak encapsulation)
* Java: all three, strong encapsulation

## C: Structures

* A structure is a user-defined type that allows you to create a new type of variable that consists of a grouping of other variables
* Demo

## Java: Classes

* Demo: create `Book`, `Author`, (`Date`?) classes
* Visibility:
  * making a member variable `private` means only the class can "see" it (no outside code can access or change it!)
  * making a member variable (or method) `public` means any piece of code can access or change it: this leads to a lot of chaos!
* Design principle:
  * make all member variables `private` unless you have a Very Good Reason to do otherwise
  * Instead: control access through *getters* and *setters*: functions that allow the outside world to access or change the variable values
  * getters/setters allow you to control access and do *data validation*
  * Lack of any setters and all `private` variables make your class *immutable*: this is a Very Good Thing: it gives you thread safety for free!
* Constructors
  * Constructors are special methods in a class that allow you to specify how an object gets built/constructed
  * You can define multiple constructors to allow a user to create an object in multiple different ways
* Other observations
  * Class names should be `UpperCamelCased`, member variables should be `lowerCamelCased`

```text









```
