
# CSCE 155H - Computer Science I
## Encapsulation - Structures & Classes
### Fall 2021

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
* C: structures support just #1 (weak encapsulation)
* Java: all three, strong encapsulation

## Example: C

* Write a structure to model a student

```c

typedef enum {
  FRESHMAN,
  SOPHOMORE,
  JUNIOR,
  SENIOR
} Year;

typedef struct {
  int year;
  int month;
  int day;
} Date;

typedef struct {
  char *firstName;
  char *lastName;
  Year year;
  double gpa;
  Date dateOfBirth;
} Student;
```

Observations
* You use `typedef struct` to declare a structure
* Opening/closing curly brackets to encapsulate multiple variables
* You generally use a `UpperCamelCasing` convention for structure's name and `lowerCamelCasing` for its *member variables*
* You use semicolons at the end of each variable AND the structure's name
* Order matters: if you use a structure inside another structure, it must be declared first
* Usually structures are placed into a header file: `student.h`
* When a structure contains another structure we say it is *composed* of that structure (and other variables)

## Example: Java

* Design a class that models a student

Observations
  * Similar naming conventions: `UpperCamelCasing` for class names, `lowerCamelCasing` for member variable names
  * With Java there is "strong encapsulation": you can "protect" your variables from the outside world
    * `public` - ANY code can see and change your variables!
    * The lack of a keyword makes a variable "package protected"
    * `protected` - the class and any subclass can see your variables (involves inheritance)
    * `private` - only your class can "see" the variables, in general make all of your variables `private` unless there is Very Good Reason to do so

## Using Structures

* Once declared, you can create an instance of a structure like other variable types
* when you have a regular old structure, you use the dot operator `.` to access member variables
* When you have a pointer to a structure, you use the arrow operator `->`
* Alternatively: you can create an "initialization" function: if you already have a structure allocated, you simpley need to set is values
* Other convenience functions
  * A way to print a structure to the standard output
  * A way to generally provide a string representation of a structure
     * Human readable
     * XML or JSON for EDI = Electronic Data Interchange
  * A function to free up a structure (destructor)

### Structures, Arrays, Functions

* See the code demo


## Summary

* Principles of Design: when defining/designing a structure: think about the essential pieces of data that make it up
  * Identify each "field" or "member" variable and its type
  * Decompose a structure into smaller and smaller parts or "substructures" UNTIL it is either trivially representable OR a structure is already defined for you `date_t`
  * Beware of YAGNI: You Ain't Gonna Need It (don't unnecessarily over-engineer your structures)
  * Don't reinvent the wheel: if there is a nice (convenient) structure already defined, use it
  * The *semantics* of a real-world entity will dictate design

```text





```
