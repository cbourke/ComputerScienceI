
# CSCE 155H - Computer Science I
## Conditionals
### Fall 2022


* Normally programs have a linear flow of control
* Like English: top to bottom, left to right
* But more complex programs require *decisions*
* Both C and Java support basic `if`, `else-if` and `if-else-if` conditional statements
* Each one relies on some logical conditional statement
* Or "boolean statements": statements or values that are either *true* or *false*

## Basic If/else-if/if-else-if statements

```c
if(<condition>) {
  //the code inside this block will execute if and only
  //if the <condition> evaluates to true
}

if(<condition>) {
  //block A
} else {
  //block B
}

```

### Examples

```c

    int a = 0;
    int b = 10;
    int c = 15;

    if(a == 0) {
        printf("do not divide by a!\n");
    }

    if(a == b) {
      printf("both variables are equal\n");
    }

    //you can use full mathematical expressions:
    if( b * b - 4 * a * c < 0 ) {
        printf("no real roots!\n");
    }

```

* Stylistically, we do not do:

```c
if(0 == a) {
  printf("do not divide by a!\n");
}
```
