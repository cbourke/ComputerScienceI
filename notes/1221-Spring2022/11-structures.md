
# ECEN 1940 - Computer Science I
## Encapsulation - Structures
### Spring 2022

* Built-in types such as `int, double, char` are not enough to model real-world data
* Real world entities have multiple pieces of data that should be *grouped* together
* Examples: Person/office data, baseball teams, states, etc. all have multiple variables associated with them
* In C you can define a *structure*: allows you to group multiple variables together into one logical unit
* This is generally referred to as *encapsulation*
  1. Grouping of data
  2. Protection of data
  3. Grouping of functionality that acts on that data
* C only supports #1: grouping of data (weak encapsulation)

## Defining Structures

```c
typedef struct {
  int month;
  int day;
  int year;
} Date;

typedef struct {
  char *firstName;
  char *lastName;
  int nuid;
  char *city;
  char *state;
  char *office;
  double heightMeters;
  Date hireDate;
} Faculty;
```

Observations

* A structure is *composed* of multiple pieces of data or even *other structures* this is called "composition"
* The order of declaration matters: if you use a structure in another structure, it must be declared above
* Each variable inside a structure is called a *member variable*
* You can/may want to designate some unique identifier for each possible *instance* of a structure
* To get a single *component* (variable) in a structure you use the *component selection operator* `.` (dot operator)
* Styling:
  * Names of structures can/should use `UpperCamelCasing`
  * Note: internal structures in C use a `foo_t` naming convention; ex: `date_t, time_t`
  * Member variables use a `lowerCamelCasing` convention
  * You use `typedef struct` with the name at the end terminated by a semicolon
* Usually, structures are declared in a header file with an appropriate name

## Using Structures

* Once defined, a structure can be declared like any other variable: `Faculty f` or a pointer to a structure: `Faculty *f`
* You can (and should) design and implement a "factory" function to make creating *instances* of a structure easy
* When you have a regular old structure, you use the dot operator
* When you have a pointer to a structure, you use the arrow operator: `->`
* You can dynamically allocate a new structure using `malloc()` and `sizeof()` with your structure; example: `sizeof(Faculty)`
* You can use the curly brackets to initialize a quick and dirty structure for testing:
  `  Faculty f = {"Joe", "Smith", 1234, 1.25, {4, 6, 2022}};
`
* Often you can write and implement other conveniencence functions:
  * Destructor: a way to "clean" up (free) a structure
  * A function to print a structure in a human-readable format
  * Serialize to a JSON format
  * More generally: a `toString()`-style function 

```text











```
