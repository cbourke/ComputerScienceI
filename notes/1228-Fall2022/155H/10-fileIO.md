
# CSCE 155H - Computer Science I
## File I/O
### Fall 2022

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

* In C files are represented by pointers ("handles"): `FILE *`
* To open a file you use `fopen()` and provide two parameters:
  * A string representing the path/name of the file you want to open
  * A string representing the "mode": `"r"` (reading, input) or `"w"` (writing, output)
* If successful, it returns a pointer that points to the beginning of the file
* If unsuccessful: it returns `NULL`
  * Doesn't exist
  * Don't have permissions

* Demo

```c

  FILE *input = fopen("myFile.txt", "w");

  if(input == NULL) {
    printf("cannot open file!\n");
  } else {
    printf("opened successfully!\n");
  }

  //process the *output* file by giving it some output...
  int x = 42;
  double pi = 3.1415;
  char school[] = "School of Computing!";
  fprintf(input, "x = %d\n pi = %f\n name = %s\n", x, pi, school);

  //close the file:
  fclose(input);

```

### File Input in C

* Two ways: read line-by-line or character-by-character
  * Line by line: `fgets()`
  * character by character: `fgetc()`

```c
//character by character:
char c = fgetc(input);
while(c != EOF) {
  printf("c = %c\n", c);
  c = fgetc(input);
}
```

* `fgets` demo:

```c

  //line by line
  char buffer[1000];
  char *line = fgets(buffer, 1000, input);
  while(line != NULL) {
    //chomp (remove) the endline character from input:
    if(buffer[strlen(buffer)-1] == '\n') {
      buffer[strlen(buffer)-1] = '\0';
    }
    printf("line = %s\n", line);
    line = fgets(buffer, 1000, input);
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
* Use a `File` and use the `Scanner` to read it line by line

```java
File f = new File("data/foo.txt");
try {
  Scanner s = new Scanner(f);

  //read in a line:
  while(s.hasNextLine()) {
    String line = s.nextLine();
    System.out.println(line);
  }		
  s.close();

} catch (FileNotFoundException e) {
  throw new RuntimeException(e);
}
```

## File Output

* Simplest way: `PrintWriter`
* It allows you to use `print, println, printf` methods

```java
File f = new File("data/bar.txt");
try {
  int x = 42;
  double pi = 3.1415;
  String school = "School of Computing!";

  PrintWriter pw = new PrintWriter(f);

  pw.print("Goodbye, no endline!");
  pw.println("... Now we have an endline. :)");
  pw.printf("x = %d\n pi = %f\n name = %s\n", x, pi, school);

  pw.close();

} catch (FileNotFoundException e) {
  throw new RuntimeException(e);
}
```

```text





````
