
# CSCE 155H - Computer Science I
## File I/O
### Fall 2024

* A *file* is a unit of stored memory
* *Typically* think of files as being stored on *disk*
* Directories are files, programs are files, sockets are files, or buffers
* usually files are stored on disk for long term *persistence* of data
* You can read (input) or write (output) a file
* Files may be plaintext or binary files
* They maybe intended for human consumption or not
* EDI (Electronic Data Interchange): XML, JSON, base-64 encoding
* The basic steps:
  1. Open the file
  2. Process the file
  3. Close the file

## File I/O in C

* In C files are represented with a pointer: `FILE *`
* It points to somewhere inside the file (initially at the first character)
* To open a file: use `fopen()`
  * First parameter: a string representing the *path* and name of the file
  * Second: mode you want to open it in: `"r"` (reading, file input), `"w"` (write, file output)
  * It returns (if successful) a pointer to the file starting at the first byte/character
  * As you read the file either character-by-character or line-by-line, it updates the pointer
* Step 3: closing the file: `fclose()`
  * Once closed, that's it, the file is saved/flushed, etc. You are done with it.
* Opening a file for reading that does not exist: error
* OPening a file for reading that you don't have permission for: error
* Opening a file for writing that does not exist: it will be created for you
* Opening a file for writing that *does* exist: it starts *overwriting* the contents
* You can use relative paths: `"../../data/myData.txt"`
* You can use absolute paths? `"/etc/passwd"`
* You can use the current directory: `"./myData.txt"`
* Failure to close a file may lead to corrupted output data


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

* You can use `fgetc()` and it returns a single character (the next character) in the file
* Once it reaches the end of the file, `EOF` is returned


```c

    FILE *in = fopen("./data.txt", "r");

    char c = fgetc(in);
    int numChars = 0;
    while(c != EOF) {
      printf("c = %c\n", c);
      numChars++;
      c = fgetc(in);
    }

    fclose(in);

    printf("numChars = %d\n", numChars);
```

### Reading Line By Line using `fgets()`

* `fgets()` gets *upto* an entire line in the file, but limits the number of characters it reads to a certain amount to avoid *buffer overflows*
  * `char *fgets(char *s, int size, FILE *stream);`
  * `s` is the buffer (string) that the data will be read *into*
  * `size` is the limit: maximum number of bytes, MINUS ONE that will be read from the file: it automatically places the null-terminator `\0` in the buffer for you!
  * `stream` is the file you are reading *from*
  * It returns a pointer to a string: if it read a line successfully, it returns a pointer to the buffer; if it encountered an error or the *end of the file*: it returns `NULL`
  * Note: the endline characater `\n` is read into the buffer (if it exists)!
  * If you *don't* want the end line character: "chomp" it out: remove trailing whitespace

```c

    FILE *in = fopen("./data.txt", "r");

    char buffer[1000];

    char *s = fgets(buffer, 1000, in);
    while(s != NULL) {
      if( buffer[strlen(buffer)-1] == '\n') {
        buffer[strlen(buffer)-1] = '\0';
      }
      printf("buffer = %s\n", buffer);
      s = fgets(buffer, 1000, in);
    }

    fclose(in);
```

```text













```
