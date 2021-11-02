
# CSCE 155E - Computer Science I
## Encapsulation - Structures
### Fall 2021

* Built-in primitive types (`int, double, char`) are limiting: not everything is a simple number of character
* Real world entities are made up of multiple pieces of data
* Example: Lab 10
  * It is a bad idea to represent real world entities with separate pieces of data
  * Lots of bookkeeping
  * Ideally, those pieces of *related* data should be collected into one "unit" or "thing" or "entity"
  * In C that entity is a *structure*
* This is generally referred to as *encapsulation*
  1. The grouping of data
  2. The protection of data
  3. The grouping of functionality that acts on that data
* C only supports the first element: grouping of data
* In C, we use *structures*

## Defining Structures

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

//model a film
typedef struct {
  char *eidr;
  char *title;
  Person director;
  double imdbRating;
} Film;

```

Observations
* A structure is *composed* of multiple pieces of data (known as "composition")
* A structure can be composed of other strutures, but then order of declaration *matters*
* Each variable inside a structure is a "field" or *member variable*
* You can/may want to designate a unique identifier (SSN, NUIDs, EIDR, ISBN)
* Styling:
  * Names can/should be `UpperCamelCased`
  * Names of member variables use `lowerCamelCasing`
  * You use `typedef struct` and opening/closing curly brackets with member variables ended with a semicolon
* Usually structures are declared in a header file with a similar name
* YAGNI = You Aint Gonna Need It

## Using Structures

* You can declare a structure once defined as you would with any built-in type: `Film f;`
* You can easily create a "factory" function to help you create instances of structures
* You can use pointers to structures as you have with pointers to other variable types
  * When you have a pointer to a structure, you use the arrow operator, `->` to access member variables
* When you have a regular old structure, you use the dot operator, `.` to access member variables
* Once you have defined a structure, you can use `sizeof(Film)` to determine how many bytes each one takes
* Other common/convenience functions include:
  * A function to create a human-readable string representation of a structure (a "to string" function)
  * A function to free up all aspects of a string a "destructor" function
  * An "initialization" function: if you already have an instance of a structure and you want to initialize its values
  * Similar functions that act on arrays of structures

## Arrays of Structures and Functions

* See code

## Summary

* Principles of Design: when defining/designing a structure: think about the essential pieces of data that make it up
  * Identify each "field" or "member" variable and its type
  * Decompose a structure into smaller and smaller parts or "substructures" UNTIL it is either trivially representable OR a structure is already defined for you `date_t`
  * Beware of YAGNI: You Ain't Gonna Need It (don't unnecessarily over-engineer your structures)
  * Don't reinvent the wheel: if there is a nice (convenient) structure already defined, use it
  * The *semantics* of a real-world entity will dictate design

```text







```
