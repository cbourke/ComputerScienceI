
# CSCE 155E - Computer Science I
## File I/O
### Fall 2026

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

## Closing the file

* Failure to properly close a file can lead to corrupted data, undefined behavior, etc.
* ALWAYs close your file when you are done
* Use: `fclose()`
* After it is closed, that's it you cannot read/write the file anymore, you can always *re*open it if you need to!

## File Output

* To keep it simple, use `fprintf()`
* The only difference is that you provide the file pointer that you want to output to as the first argument
* EVERYTHING you know and love/hate about `printf()` can be used with `fprintf()`

# Observations

* If you open a file for writing that doesn't exist, it will be created for you
* If you write to a file, all the data already in the file will be **overwritten** there is NO recovery
* If you open a file that you do not have permission to, `fopen()` will fail and return `NULL`
* File INput: if you open a file for reading that doesn't exist, it will also fail

```c

    FILE *f = fopen("/etc/passwd", "w");

    if(f == NULL) {
        printf("opening file failed!\n");
        exit(1);
    }

    //TODO: process the file...
    fprintf(f, "Hello World!\n");
    int x = 42;
    double y = 123.4;
    char s[] = "Goodbye World!\n";
    fprintf(f, "x = %d, y = %f, s = %s\n", x, y, s);

    fclose(f);
```

## File Input

* There are *many* ways to do file input, most are dangerous
* Two ways:
  * read a file character-by-character: `fgetc()`
  * read a file line-by-line: `fgets()`
* `fgetc()` reads one character at a time
  * It starts at the first character
  * After each one is read, it advances to the next character automatically `FILE *` is updated!
  * Until it reaches the end of the file
  * At the end of the file, `fgetc` returns `EOF` End=of-file to indicate that the file has been read

```c

    FILE *f = fopen("./foo.txt", "r");

    char c = fgetc(f);
    int numCharacters = 0;

    while(c != EOF) {
        numCharacters++;
        printf("c = %c\n", c);
        c = fgetc(f);
    }

    printf("read %d characters from the file\n", numCharacters);

    //printf("c = %c\n", c);

    fclose(f);
```

* You can also read line-by-line using `fgets()`
* `char *fgets(char *s, int size, FILE *stream);`
  * `s` is the string that you read the line into
  * `size` is a limitation on the number of characters `fgets()` will read: it will read **at most** `size` characters MINUS 1, it will put the null-terminator there for you automatically!
  * `stream` is the file you are reading from
  * The return value is a pointer to the string that you just read in, UNLESS it is at the end of the file...
  * If there is no more data to read from the file, the function will return `NULL`
  * `fgets()` retains the endline character: `\n`, you will need to manually remove it if you don't want it

```c

    FILE *f = fopen("./foo.txt", "r");

    char buffer[1000];
    char *s = fgets(buffer, 1000, f);
    int numLines = 0;

    while(s != NULL) {
        //print it
        numLines++;
        //chomp out/remove the endline character
        if(buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }
        printf("line = %s\n", buffer);
        //read the next line
        s = fgets(buffer, 1000, f);
    }

    printf("I read %d lines\n", numLines);

    fclose(f);

```

### Honorable mentions

* There are other nice utility functions in the stdio library:
  * `fseek()` - this can fast forward or rewind the file pointer!
  * `rewind()` - this rewinds all the way back to the start of the file

```text












```
