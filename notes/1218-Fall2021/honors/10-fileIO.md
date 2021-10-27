
# CSCE 155H - Computer Science I
## File I/O
### Fall 2021

* A *file* is a unit of stored memory, usually on disk
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

* In C files are represented with a pointer type: `FILE *`
* To open a file you use `fopen()`: it takes two parameters
  * First: a string representing the path + file name to open
  * Second: is the mode that you open it in: `"r"` (reading, file input) or `"w"` (writing, file output)
* If successful, it returns a valid pointer
* If unsuccessful: it returns `NULL`
  * Doesn't exist
  * Don't have permissions

  ```c
  //open a data file in the current directory:
  FILE *f = fopen("input.txt", "r");

  //relative paths:
  FILE *f = fopen("../../mydata/input.txt", "r");

  //absolute paths:
  FILE *f = fopen("/etc/passwd", "r");

  //it can fail:
  FILE *f = fopen("/etc/shadow", "r");
  if(f == NULL) {
  	printf("cannot read passwords, good");
  }
  ```

### Closing a file

* to close a file, simply use `fclose()`: you pass in the file pointer of the file you want to close
* Failure to close a file *may* result in corrupted data or incomplete data  
```c
fclose(f);
```

### File Output

* There are many ways of doing file output
* KISS = Keep It Simple Stupid
* Use `fprintf()`
* It has the same behavior as `printf` but with one additional argument: the file you want to print to

```c
FILE *out = fopen("data.txt", "w");

fprintf(out, "Hello how are you?\n");
int x = 42;
double pi = 3.14159;
char name[] = "Chris";
fprintf(out, "\n\n\n");
fprintf(out, "Hello, %s, pi is %.2f and x is %d\n", name, pi, x);

fclose(out);
```

* If you open an existing file and start writing to it: it overwrite the data; it "clobbers" the file
* There is no undo, there is no undelete!

## File Input

* There are several ways of doing file input
* MOST are *dangerous*
* Look at two safe/easy ways: `fgetc()` and `fgets()`
* Each one reads either a character or a string (line) of the file one at a time, advancing the pointer through the file
* Until: `EOF` (end of file)

```c

char c = fgetc(f);
while(c != EOF) {
  printf("c = %c\n", c);
  c = fgetc(f);
}
```

* You can use `fgets()` to read up to an entire line from a file at once
* `char *fgets(char *s, int size, FILE *stream);`
  * `s` is the string you want the result from the file to be stored into (it is a *buffer*)
  * `size`: `fgets` will read *at most* `size-1` bytes from the file and place the results into `s` (minus 1 to accommodate the null terminator, which it takes care of for you!)
  * It stops when it sees the first endline character, `\n`
  * THe last argument is the file pointer you are reading from
  * Upon success it returns a valid pointer to the resulting string
  * At the end of the file, it returns `NULL`
  * fgets preserves the end line character, `\n`
  * If you don't want the endline character: you can trim or "chomp" it out (chomp = remove leading and/or trailing whitespace)

```c

  char buffer[10000];
  char *s = fgets(buffer, 10000, f);
  while(s != NULL) {
    //chomp:
    buffer[strlen(buffer)-1] = '\0';
    printf("buffer = %s\n", buffer);
    s = fgets(buffer, 10000, f);
  }
```

## Java

* Java defines a class called `File`

```java
File f = new File("file.txt");
File f = new File("/absolute/path/to/file.txt");
File f = new File("../../archive/file.txt");
```

## File Input

* Lots of ways but the easiest: `Scanner`

```java
File f = new File("file.txt");
try {
  Scanner s = new Scanner(f);
  while(s.hasNextLine()) {
    String line = s.nextLine();
    System.out.println(line);
  }
  s.close();
} catch (FileNotFoundException fnfe) {
  throw new RuntimeException(fnfe);
}
```

* Try with resources:
```java
File f = new File("file.txt");
try (Scanner s = new Scanner(f)) {
  while(s.hasNextLine()) {
    String line = s.nextLine();
    System.out.println(line);
  }
} catch (FileNotFoundException fnfe) {
  throw new RuntimeException(fnfe);
}
```

* You can use any number of `next()` methods to get tokens out of the file
* By default, whitespace is used as a delimiter and the delimiters are NOT preserved in the result
* You can use `s.hasNextLine()` or `s.hasNext()` to test if you are at the end of a file
* a try-with-resources construct will automatically close the file for you!

## File Output

* Simplest way: `PrintWriter`
* It allows you to use `print, println, printf` methods

```java
File f = new File("output.txt");
try (PrintWriter pw = new PrintWriter(f)) {
  pw.print("Hello World!\n");
  pw.println("How are you?");
  int x = 42;
  pw.printf("Here is a number = %d\n", x);
  //pw.close();
} catch (FileNotFoundException e) {
  throw new RuntimeException(e);
}
```


## Binary File I/O

* Bring in a library!


```c
int x = 2147000000;










```
