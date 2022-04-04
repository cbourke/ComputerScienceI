
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
