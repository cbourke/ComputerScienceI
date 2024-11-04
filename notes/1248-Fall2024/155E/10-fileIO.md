
# CSCE 155E - Computer Science I
## File I/O
### Fall 2024

* A *file* is a unit of stored memory
* Typically we think of files on a *disk*
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

* A file in C is represented using a pointer: `FILE *`
* To open a file use `fopen()`
* Two arguments:
  * First: a string that gives the file path + file name
  * Second: mode to open it in: `"r"` (reading, file input), `"w"` (writing, file outout)
  * Upon success, `fopen()` will return a file pointer or "handle"
* OBservations:
  * Opening a file for reading that does not exist: error
  * Opening a file for reading that you don't have permission for: error
  * OPening a file for writing that already exists: overwrite the data!
  * Opening a file for writing that does not exist: it generally creates the file for you!

## Closing a file

* Failure to properly close a file can lead to corrupted data, undefined behavior, etc.
* ALWAYs close your file when you are done
* Use: `fclose()`
* After it is closed, that's it you cannot read/write the file anymore, you can always *re*open it if you need to!

## File Output

* to keep it simple, just use `fprintf()`
* The only difference is that you provide the file pointer that you want to output to as the first argument
* EVERYTHING you know and love about `printf()` can be used with `fprintf()`

```c

    FILE *h = fopen("output.txt", "w");

    if(h == NULL) {
        printf("unable to open file!\n");
        exit(1);
    } else {
        printf("successfully opened file...\n");
    }

    //file output:
    fprintf(h, "Hello World!\n");
    fprintf(h, "Hello World!\n");
    int x = 42;
    fprintf(h, "x = %d\n", x);
    double y = 3.5;
    char message[] = "Goodbye World!!!!";
    fprintf(h, "y = %.2f, %s\n", y, message);

    fclose(h);
```

## Other Items

* You can use relative and absolute file paths
* `fopen("foo.txt", "r")` opens the file `foo.txt` in the current directory
* `fopen("../hack01/foo.txt", "r")` opens the file one level up, in the subdirectory `hack01` for reading (relative path)
* Absolute path: `fopen("/home/ubuntu/profile.txt", "r")`


## File Input

* There are *many* ways to do file input, most of them are dangerous
* Two ways:
  * `fgetc()` - reads one character at a time from the file
  * `fgets()` - reads a "string" from the file: upto an entire line at a time
* `fgetc()` reads one character at a time
  * It starts at the first character
  * After each character read, it advances the file pointer `FILE *` to the next one
  * Until it reaches the end of the file...

```c

    FILE *h = fopen("data.txt", "r");

    char c = fgetc(h);
    int numChars = 0;
    while(c != EOF) {
        printf("%c", c);
        numChars++;
        c = fgetc(h);
    }

    fclose(h);

    printf("there were %d characters\n", numChars);
```

* You can use `fgets()` to get upto an entire line of input at once
  * `char *fgets(char *s, int size, FILE *stream);`
  * 3 arguments
  * first: buffer (string) that you want the line read *into* (its gotta be big enough!)
  * second: the maximum number of bytes to read into the buffer minus 1!  Minus One: because `fgets()` inserts the null terminator `\0` for you!
  * It will actually stop when it sees the first endline character: `\n`
  * It will return a pointer to the buffer if the read was valid
  * Upon failure or the end of the file it returns `NULL`
* `fgets` will *retain* the endline character: `\n` in the buffer
  * to get rid of it: chomp it out

```c

    FILE *h = fopen("data.txt", "r");

    char buffer[1000];
    char *s = fgets(buffer, 1000, h);
    int numLines = 0;
    while(s != NULL) {
        //remove the endline character:
        if( buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }

        printf("buffer = %s\n", buffer);
        numLines++;
        s = fgets(buffer, 1000, h);
    }

    printf("number of lines = %d\n", numLines);

    fclose(h);
```

```text







```
