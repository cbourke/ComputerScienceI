
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

```c

    FILE *in = fopen("./file.txt", "r");

    int count = 0;
    char c = fgetc(in);
    while(c != EOF) {
        printf("c = %c\n", c);
        count++;
        c = fgetc(in);
    }

    fclose(in);

    printf("read %d characters\n", count);
```

### Reading Line By Line using `fgets()`

* `fgets()` gets *upto* an entire line in the file, but limits the number of characters it reads to a certain amount to avoid *buffer overflows*
  * `char *fgets(char *s, int size, FILE *stream);`
  * `s` is the buffer (string) that the data will be read *into*
  * `size` is the limit: maximum number of bytes, MINUS ONE that will be read from the file: it automatically places the null-terminator `\0` in the buffer for you!
  * `stream` is the file you are reading *from*
  * It returns a pointer to a string: if it read a line successfully, it returns a pointer to the buffer; if it encountered an error or the *end of the file*: it returns `NULL`
  * Note: the endline characater `\n` is read into the buffer (if it exists)!
  * If you don't want this, you can "chomp" it out: remove trailing whitespace

```c

    FILE *in = fopen("./file.txt", "r");

    int lineCount = 0;
    char buffer[100];
    char *line = fgets(buffer, 100, in);
    buffer[strlen(buffer)-1] = '\0';

    while(line != NULL) {
        printf("line = %s\n", line);
        lineCount++;
        line = fgets(buffer, 100, in);
        buffer[strlen(buffer)-1] = '\0';
    }

    fclose(in);

    printf("read %d lines\n", lineCount);
```

* Honorable mentions:
  * `rewind()`
  * `fseek()`

## File I/O in Java

* Java defines a class called `File`

```java
File f = new File("file.txt");
File f = new File("/absolute/path/to/file.txt");
File f = new File("../../archive/file.txt");
```

* In Eclipse: everything is relative to the project folder!

### File Input

* Lots of ways; easiest: `Scanner`
* The `Scanner` will remove the endline characters for you

```java
File f = new File("data/file.txt");
Scanner s = null;
try {
  s = new Scanner(f);
  int lineCount = 0;
  while(s.hasNextLine()) {
    String line = s.nextLine();
    System.out.println(line);
    lineCount++;
  }
  System.out.printf("Read %d lines\n", lineCount);
} catch (FileNotFoundException e) {
  throw new RuntimeException(e);
} finally {
  s.close();
}
```

## File Output

* Simplest way: `PrintWriter`
* It allows you to use `print, println, printf` methods

```java
File f = new File("data/output.txt");
try {
  PrintWriter pw = new PrintWriter(f);
  pw.print("This is a single line... ");
  pw.println(" now this is the end.");
  int x = 42;
  double y = 3.5;
  pw.printf("x = %d, y = %f\n", x, y);
  pw.close();
} catch (FileNotFoundException e) {
  throw new RuntimeException(e);
}
```

### Even Easier: Java NIO library

* NIO = Non-blocking Input/Output
* Input line-by-line or the entire contents at once

```java
Path path = Paths.get("data/file.txt");
try {
  //line by line:
  List<String> contents = Files.readAllLines(path);
  for(String line: contents) {
    System.out.println(line);
  }

} catch (IOException e) {
  throw new RuntimeException(e);
}

try {
  String text = new String(Files.readAllBytes(path));
  System.out.print(text);
} catch (IOException e) {
  throw new RuntimeException(e);
}
```


```text













```
