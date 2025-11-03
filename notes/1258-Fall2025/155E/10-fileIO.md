
# CSCE 155E - Computer Science I
## File I/O
### Fall 2025

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

* In C, files are represented using a pointer: `FILE *`
* To open a file: `fopen()`
* It takes two arguments:
  * First: a string that gives the file path + file name
  * Second: mode to open it up for: `"r"` (reading, file input), `"w"` (writing, file output)
  * Upon success, `fopen()` will return a file pointer or "handle"
* The pointer will point to the beginning of the file
* As you read/write characters or bytes, the file pointer will *automatically* advance
* OBservations:
  * Opening a file that does not exist, *may* create it for you!
  * Opening a file that does not exist for reading however...
  * Opening a file for reading that does not exist: error, `fopen` will return `NULL`
  * Opening a file that you do not have permission to read/write will result in `NULL`
  * OPening a file for writing that already exists: overwrite the data!
  * Opening a file for writing that does not exist: it generally creates the file for you!

## Closing a file

* Failure to properly close a file can lead to corrupted data, undefined behavior, etc.
* ALWAYs close your file when you are done
* Use: `fclose()`
* After it is closed, that's it you cannot read/write the file anymore, you can always *re*open it if you need to!

## File Output

* To keep it simple, use `fprintf()`
* The only difference is that you provide the file pointer that you want to output to as the first argument
* EVERYTHING you know and love/hate about `printf()` can be used with `fprintf()`

```c

    FILE *f = fopen("file.txt", "w");

    fprintf(f, "Goodbye World\n");
    int x = 42;
    double y = 1.567;
    char initial = 'Q';
    fprintf(f, "x = %d, y = %f, initial = %c\n", x, y, initial);

    fclose(f);

```

## Other Items

* You can use relative and absolute file paths
  * `fopen("foo.txt", "r")` - opens `foo.txt` in the current working directory
  * relative: `fopen("../../data/bar.txt")` relative to the current working directory, two directories up and then down into `data` and opening `bar.txt`
  * absolute paths: `fopen("/etc/passwd", "r")`

## File Input

* There are *many* ways to do file input, most are dangerous
* Two ways:
  * `fgetc()` - reads one character at a time from the file
  * `fgets()` - reads a "string" from the file: upto an entire line at a time
* `fgetc()` reads one character at a time
  * It starts at the first character
  * After each one is read, it advances to the next character automatically `FILE *` is updated!
  * Until it reaches the end of the file...
  * To determine if you are at the end of the file a special character is defined: `EOF`

```c
FILE *f = fopen("file.txt", "r");

int count = 0;
char c = fgetc(f);
while(c != EOF) {
    printf("c = %c\n", c);
    count++;
    c = fgetc(f);
}

printf("Found %d characters\n", count);

fclose(f);
```

### Honorable mentions

* There are other nice utility functions in the stdio library:
  * `fseek()` - this can fast forward or rewind the file pointer!
  * `rewind()` - this rewinds all the way back to the start of the file

### `fgets()`

* You can use `fgets()` to get upto an entire line of input at once
  * `char *fgets(char *s, int size, FILE *stream);`
  * first: buffer (string) that you want the line read *into* (its gotta be big enough!)
  * second: the maximum number of bytes to read into the buffer minus 1!  Minus One: because `fgets()` inserts the null terminator `\0` for you!
  * It will actually stop when it sees the first endline character: `\n`
  * OR it will stop after `size` bytes (still adds in the null terminator for you)
  * Upon success, it will return a valid pointer to the same buffer you just read into
  * Upon failure or the END of the file it returns `NULL`
* `fgets` will *retain* the endline character: `\n` in the buffer
  * IF you want to get rid of it, you can "chomp" out the endline character: reset it to `\0`

```text












```
