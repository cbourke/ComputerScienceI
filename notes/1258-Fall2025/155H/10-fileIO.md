
# CSCE 155H - Computer Science I
## File I/O
### Fall 2025

* A *file* is a unit of stored memory
* *Typically* think of files as being stored on *disk*
* Directories are files, programs are files, sockets are files, or buffers
* usually files are stored on disk for long term *persistence* of data
* You can read (input) or write (output) a file
* Files may be plaintext or binary files
* They maybe intended for human consumption or not
* EDI = Electronic Data Interchange (XML, JSON, base-64, etc.)
* The basic steps:
  1. Open the file
  2. Process the file
  3. Close the file

## File I/O in C

* In C files are represented by a pointer: `FILE *`
* It points to somewhere inside the file (initially it points to the first character)
* To open a file: use `fopen()`
  * First parameter: a string representing the *path* and name of the file
  * Second parameter: a mode to open it up in: `"r"` (reading input) or `"w"` (writing, output)
  * It returns (if successful) a pointer to the file starting at the first byte/character
  * As you read the file either character-by-character or line-by-line, it updates the pointer
* Step 3: closing the file: `fclose()`
  * Once closed, that's it, the file is saved/flushed, etc. You are done with it.
* Opening a file for reading that does not exist: error
* OPening a file for reading that you don't have permission for: error
* Opening a file for writing that does not exist: it will be created for you
* Opening a file for writing that *does* exist: it starts *overwriting* the contents!
* for errors, `fopen()` returns `NULL`
* You can use relative paths: `"../../data/myData.txt"`
* You can use absolute paths: `"/etc/passwd"`
* You can use the current directory: `"./myData.txt"` or `"myData.txt"`

### File Output

* Just use `fprintf`: the same behavior, placeholders, etc. as `printf`

```c

    FILE *out = fopen("./foo.txt", "w");

    fprintf(out, "hello wolrd!\n");
    int x = 42;
    double y = 3.1514;
    char message[] = "Goodbye WOrld\n";
    fprintf(out, "x = %d, y = %f, \n%s", x, y, message);

    fclose(out);
```

## File Input

* You want to read *from* a file
* Keep it simple: two methods: char-by-char, line-by-line
* To read character by character use `fgetc()`
* To read line by line use `fgets()`

### Using `fgetc()`

* You can use `fgetc()` and it returns a single character (the next character) from the file
* It automatically advances the pointer to the next character
* Once it reaches the end of a file, it returns a special `EOF` character value


```text













```
