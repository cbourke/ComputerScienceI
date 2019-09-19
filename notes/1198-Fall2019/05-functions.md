
# CSCE 155E - Computer Science I
## Functions
### Fall 2019

An introduction to functions in C.

* A *function* is a reusable unit of code that may take *input(s)* and *may* produce an *output*
* Similar to math functions:
  $$f(x), f(x, y), f()$$
* Already familiar with several functions: `sin(), round(), printf(), scanf(), main()`, etc.
* Functions facilitate *code reuse*: you don't copy-paste (cut and paste), you don't want to reinvent the wheel
* Procedural Abstraction: functions allow you to ignore implementation details of how a certain block of code works, you can *just use it*
* Functions *encapsulate* functionality into reusable *abstract* units of code
* Standard libraries and external libraries provide useful functions that have a lot of testing, debugging and optimization behind them, don't throw those resources away!
* Feeds into an overall problem solving strategy: is there a function that does this task for me already?  Or, failing that, is there a function that can help me partially solve this task?

## Functions in C

* As with variables, functions have to be "declared" before you can use them
* In C you "declare" a function by creating a *prototype*
* A prototype is a declaration that defines a functions *signature*
  * The name of the function (identifier)
  * The list of its inputs called "parameters" or "arguments"
  * The type of variable that the function outputs or `return`s
* Example:

```c
/**
 * This function rounds the given amount to the 
 * nearest hundredth (ie the nearest cent) and
 * returns the value.
 *
 */
double roundToCents(double amount);
```

* Prototypes end with a semicolon
* Documentation is usually written *above* a prototype




