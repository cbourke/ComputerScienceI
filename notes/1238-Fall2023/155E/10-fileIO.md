
# CSCE 155E - Computer Science I
## File I/O
### Fall 2023

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

* A file in C is represented by a pointer, `FILE *`
* To open a file you use `fopen()`
  * Two arguments...
  * First: path and file name of the file you want to open
  * Second: mode `"r"` (reading, input) or `"w"` (writing, file output)
  * If the opening fails for whatever reason, `fopen()` returns `NULL`

## Closing a file

* Failure to close a file can result in undefined behavior, data corruption, etc.
* ALWAYS close a file when you are done: `fclose()`
* After it is closed, you can no longer interact with it!

## Failures

* If the file does not exist, you cannot open it for reading!
* If you do not have permissions to open the file for *either* reading or writing then it will not open
* Opening an existing file for writing, **Overwrites** any content in the file
* There is NO undo, no recycle bin, NO undelete

## Other Items

* You can use relative and absolute file paths
* `fopen("foo.txt", "r")` opens the file `foo.txt` in the current directory
* `fopen("../hack01/foo.txt", "r")` opens the file one level up, in the subdirectory `hack01` for reading (relative path)
* Absolute path: `fopen("/home/ubuntu/profile.txt", "r")`

## File Output

* to keep it simple, just use `fprintf()`
* The only difference is that you provide the file pointer that you want to output to as the first argument
* EVERYTHING you know and love about `printf()` can be used with `fprintf()`

```c
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  FILE *f = fopen("output.txt", "w");
  if(f == NULL) {
    printf("error: cannot open file!\n");
  } else {
    printf("success: opened file!\n");
  }

  int a = 10;
  double b = 3.5;
  fprintf(f, "Hello world how are you?\n");
  fprintf(f, "a = %d, b = %.2f\n", a, b);

  fclose(f);



  return 0;
}
```

## File Input

* There are *many* ways to do file input, most of them are dangerous
* Two simple/safe ways:
  * `fgetc()` - reads one character at a time from the file
  * `fgets()` - reads a "string" from the file: upto an entire line at a time
* `fgetc()` reads one character at a time
  * After each read, it advances the file pointer to the next character automatically!
  * when it reaches the end of the file, it returns `EOF`

```c
int counter = 0;
char c = fgetc(f);
while(c != EOF) {
  printf("I read a '%c'\n", c);
  counter++;
  c = fgetc(f);
}
fclose(f);
printf("I read %d characters!\n", counter);
```

* You can use `fgets()` to get upto an entire line of input at once
  * 3 arguments
  * first: buffer (string) that you want the line read *into* (its gotta be big enough!)
  * second: the maximum number of bytes to read into the buffer minus 1!  Minus One: because `fgets()` inserts the null terminator for you!
  * It will actually stop when it sees the first endline character
  * It will return a pointer to the current line until...
  * when it reaches the end of the file, it returns `NULL`

```c

  char buffer[1000];

  int numLines = 0;
  //read the first line:
  char *line = fgets(buffer, 1000, f);
  while(line != NULL) {
    //Get rid of the endline character:
    if(buffer[strlen(buffer)-1] == '\n') {
      buffer[strlen(buffer)-1] = '\0';
    }
    printf("line = \"%s\"\n", buffer);
    numLines++;
    //read the next line:
    line = fgets(buffer, 1000, f);
  }
  printf("I read %d lines from the file!\n", numLines);
```

```text








```
