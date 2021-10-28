
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

* You can declare a structure once defined 



```text







```
