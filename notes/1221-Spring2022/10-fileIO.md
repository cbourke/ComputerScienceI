
# ECEN 1940 - Computer Science I
## File I/O
### Spring 2022


* A *file* is a unit of stored memory, usually on disk
* Files are also directories, programs are files, buffers, sockets
* Files may be read (input), or written (output)
* Files may be binary (pure data) or plaintext files (ASCII)
* Even plaintext files may be *stuctured* and not intended for human consumption: CSV, XML, JSON, etc. Base-64 encoding:
* EDI = Electronic Data Interchange
* Basic steps to working with files:
 1. Open the file
 2. Process the file
 3. Close the file

## Opening a file

* In C, a file is represented as a *pointer*: `FILE *`
* To open a file you use `fopen()`
* The `fopen()` function takes two arguments:
  * A string representing the path/file name of the file you want to open
  * A string representing the *mode*: `"w"` (writing: output) or `"r"` (reading: input)
  * Upon success it returns a `FILE *` to the file

```c  
      //opens test.txt which is assumed to be in the current workin directory
      FILE *h = fopen("foo.txt", "r");
      //absolute paths:
      FILE *h = fopen("/etc/passwd", "r");
      //relative paths:
      FILE *h = fopen("../data/test.txt", "r");

      if(h == NULL) {
        printf("cannot open file!\n");
      }  
```

## Closing a File

* Once you are done with a file, clean it up!
* You should close it: `fclose()`
* Failure to close a file may lead to corruption

## File Output

* To keep it simple, we'll use `fprintf()`
* Instead of printing to the standard output, you print to a file
* Everything you know about `printf()` is applicable to `fprintf`
* Only difference: `fprintf()` takes one new argument (first): the file handle you wish to print to

```c

    FILE *outputFile = fopen("./demo.txt", "w");
    //TODO: add error handling here

    //output some data
    int x = 42;
    double foo = 3.14159;
    char name[] = "Chris";
    fprintf(outputFile, "Hello, %s, value is %d and pi = %f\n", name, x, foo);

    fclose(outputFile);
```

## File Input

* Keep it simple: `fgetc()` and `fgets()`
* Many other *dangerous* ways to do this: forget about them
* `fgetc()` gets a sinle character from the file and advances the file pointer to the next character
  * It returns the character as an ASCII text value (`int`)
  * When it reaches the end of the file, it returns a special value (NOT a special character): `EOF` (end of file)

```c

    FILE *inputFile = fopen("./haiku.txt", "r");

    int c = fgetc(inputFile);
    int charCount = 0;
    while(c != EOF) {
        printf("read %c\n", c);
        charCount++;
        //read the next character:
        c = fgetc(inputFile);
    }

    printf("read %d characters\n", charCount);

    fclose(inputFile);
```

* `fgets()` gets *upto* an entire line of a file at once, but limits the number of characters to a certain size:
  * `char *fgets(char *s, int size, FILE *stream);`
  * `stream` is the file you are reading from
  * `s` is a *buffer* where the contents of the line are stored
  * `size` is a limit: `fgets()` only reads at most `size-1` bytes into the buffer
  * minus one because: to accommodate the null-terminating character which it takes care of for you!
  * `fgets()` stops when it sees a new line character, `\n` OR it reads the maximum number of bytes
  * To determine if you are at the end of the file or not: `fgets()` returns a string pointer (`char *`): if it successfully reads any data, it returns a pointer to `s`, if it fails (at the end of the file) it returns... `NULL`
  * Note: `fgets()` preserves the endline character in the buffer, you can always chomp it out if you want to!

```c

    FILE *inputFile = fopen("./haiku.txt", "r");

    //create a buffer "big enough" to hold any single line
    char buffer[200];
    char *s = fgets(buffer, 200, inputFile);
    while(s != NULL) { //not at the end of the file yet...
        //check for new line and "chomp" it out if you don't want it...
        //if the last character is \n, remove it...
        if(buffer[strlen(buffer)-1] == '\n') {
            //remove it
            buffer[strlen(buffer)-1] = '\0';
        }
        //process the next line...
        printf("line = %s\n", buffer);
        //read the next line...
        s = fgets(buffer, 200, inputFile);
    }


    fclose(inputFile);
```


```text









```
