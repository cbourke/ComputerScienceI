
# CSCE 155E - Computer Science I
## File I/O
### Fall 2022

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

* In C you can open a file using `fopen()`
* It takes two arguments:
  * The path/name of the file you want to open (as a string)
  * A string representing the *mode* you want to open it in: `"w"` (write to the file, file output) or `"r"` (read from a file, file input)
* It returns a file "handle" or pointer: `FILE *`
* If the opening fails for any reason, it returns `NULL`

## Closing a File

* Once you are done processing a file, you need to close it
* Failure to close it may result in *undefined behavior*
* To close a file use `fclose()`

## File Output

* To keep it simple, just use `fprintf()`
* Instead of printing to the standard output, you print to a file
* Everything you know about `printf()` is applicable to `fprintf`
* Only difference: `fprintf()` takes one new argument (first): the file handle you wish to print to


```c

  FILE *f = fopen("myFile.txt", "w");

  if(f == NULL) {
    printf("cannot open file!\n");
  } else {
    printf("file opened successfully!\n");
  }

  int x = 42;
  double foo = 10.54321;
  char name[] = "School of Computing";
  fprintf(f, "x = %d\nfoo = %f\nname = %s\n", x, foo, name);

  fclose(f);

```

## File Input

* You want to read *from* a file
* Keep it simple: you can read character-by-character or line-by-line
* To read character by character use `fgetc()`
* To read line by line use `fgets()`

### Using `fgetc()`

* You can use `fgetc()` and it returns a single character (the next character) in the file
* It automatically advances to the next character in the file

```c
FILE *f = fopen("myFile.txt", "r");

char c = fgetc(f);
while( c != EOF ) {
  printf("c = %c\n", c);
  c = fgetc(f);
}

fclose(f);
```

* Demo
```c

int numberOfCharsInFile(const char *fileName) {
  FILE *f = fopen(fileName, "r");

  if(f == NULL) {
    return 0;
  }

  int count = 0;
  char c = fgetc(f);
  while( c != EOF ) {
    count++;
    c = fgetc(f);
  }

  fclose(f);

  return count;
}

```

### Reading Line By Line using `fgets()`

* `fgets()` gets *upto* an entire line in the file, but limits the number of characters it reads to a certain amount to avoid *buffer overflows*
  * `char *fgets(char *s, int size, FILE *stream);`
  * The first argument is the string you want to read the file into!
  * The second argument limits the number of bytes that `fgets()` reads so you don't overflow the string `s`: it will read at most `size-1` bytes and automatically put in the null terminator for you!
  * The third is the file you are reading from
  * OBservation: `fgets()` retains the endline character (if it is read) in the buffer!
  * `fgets()` also returns a pointer!  Usually this is just a pointer to the string `s` (or `buffer`), unless you are at the end of a file
  * If you are at the end of a file it returns `NULL`

```c

  FILE *f = fopen("myFile.txt", "r");

  char buffer[1000];
  char *line = fgets(buffer, 1000, f);

  while( line != NULL ) {
    //chomping: removing trailing whitespace
    // but only if it is whitespace:
    if(buffer[strlen(buffer)-1] == '\n') {
      buffer[strlen(buffer)-1] = '\0';
    }
    printf("line = %s\n", buffer);
    line = fgets(buffer, 1000, f);
  }

  fclose(f);
```

### Binary Data

* How many bytes does it take to represent the largest integer value, 2147483647
  * Using plaintext: `"2147483647"`: at least 10 bytes
  * Using binary: `sizeof(int)`: usually 4 bytes


```text



```
