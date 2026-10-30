
# CSCE 155H - Computer Science I
## File I/O
### Fall 2026

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
* To open a file you use `fopen()`
  * First parameter: a string representing the *path* and name of the file
  * Second parameter: a mode to open it up in: `"r"` (reading input) or `"w"` (writing, output)
  * It returns (if successful) a pointer to the file starting at the first byte/character
  * As you read the file either character-by-character or line-by-line, it updates the pointer
* Step 3: closing the file: `fclose()`
  * Once closed, that's it, the file is saved/flushed, etc. You are done with it.

### File Output

* Just use `fprintf` the same behavior, placeholders, etc. as `printf`

```c

    FILE *output_file = fopen("./foo.txt", "w");

    //TODO: process the file
    fprintf(output_file, "Hello Nebraska!\n");
    int x = 42;
    double y = 3.5;
    char s[] = "Goodbye World!";
    fprintf(output_file, "x = %d, y = %f, s = %s\n", x, y, s);



    //3. close the file
    fclose(output_file);
```

## More Observations

* OPening a file for writing that doesn't exist: it creates the file for you!
* However, if you do not have permission to the file, it will fail....
* To indicate failure, `fopen` will return `NULL`
* You can specify files either:
  * Locally: `"./foo.txt"` current working directory
  * Relative: `"../../foo/bar.txt"`
  * Absolute: `"/etc/passwd"`

## File Input

* You want to read *from* a file
* Keep it simple: two methods: char-by-char, line-by-line
* To read character by character use `fgetc()`
* To read line by line use `fgets()`

### Using `fgetc()`

* You can use `fgetc()` and it returns a single character (the next character) from the file
* It automatically advances the pointer to the next character
* Once it reaches the end of a file, it returns a special `EOF` character value

```c

    FILE *input = fopen("foo.txt", "r");

    char c = fgetc(input);
    int numChars = 0;
    while(c != EOF) {
        printf("c = %c\n", c);
        numChars++;
        c = fgetc(input);
    }

    printf("numChars = %d\n", numChars);

    fclose(input);
```    

### Reading Line By Line using `fgets()`

* `fgets()` gets *upto* an entire line in the file, but limits the number of characters it reads to a certain amount to avoid *buffer overflows*
  * `char *fgets(char *s, int size, FILE *stream);`
  * `s` is the buffer (string) that the data will be read *into*
  * `size` is the limit: maximum number of bytes, MINUS ONE that will be read from the file: it automatically places the null-terminator `\0` in the buffer for you!
  * `stream` is the file you are reading *from*
  * It returns a pointer to a string: if it read a line successfully, it returns a pointer to the buffer; if it encountered an error or the *end of the file*: it returns `NULL`

```c

    FILE *input = fopen("foo.txt", "r");

    int numLines = 0;
    char buffer[1000];
    char *s;
    s = fgets(buffer, 1000, input);
    while(s != NULL) {
        //chomp out the endline character:
        // ie remove the endline character:
        if(buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }
        printf("buffer = %s\n", buffer);
        numLines++;
        s = fgets(buffer, 1000, input);
    }
    printf("numLines = %d\n", numLines);
    fclose(input);
```

### More Observations

* `fgets` will *retain* the endline character, if you don't want it; it needs to be manually "chomped" out
* Opening a file for reading that does not exist or you don't have permissions for: error and `NULL`

### Misc

* Honorable mentions:
  * `rewind()`
  * `fseek()` will fast forward by a certain number of bytes

# Java

* Lots of ways; easiest: `Scanner`
* The `Scanner` will remove the endline characters for you

```java
File f = new File("data/foo.txt");
Scanner s = null;

try {
  //step 1: open the file for reading...
  s = new Scanner(f);

  //reads it line by line until it gets to the end of the file
  while(s.hasNextLine()) {
    String line = s.nextLine();
    System.out.println(line);
  }

  //step 3: close the scanner
  s.close();
} catch (FileNotFoundException e) {
  throw new RuntimeException(e);
}
```

* Even easier:


```text













```
