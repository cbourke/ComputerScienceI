
# CSCE 155H - Computer Science I
## File I/O
### Fall 2020

* A *file* is a unit of stored memory, usually on disk
* Directories are files, programs are files, socket is a file, or buffers
* Usually files are stored long term for *persistence* of data
* You can read from (input) or write to (output) a file
* Files may be plaintext or binary OR they may be plaintext but not intended for human consumption
* EDI (Electronic Data Interchange): XML, JSON, base-64 encoding
* The basic steps:
  1. Open the file
  2. Process the file
  3. Close the file
  
## File I/O in C

* Files in C are represented by a pointer type: `FILE *`
* To open a file, use `fopen()` it takes two arguments:
  * First: string that denotes the path + file name you want to open
  * Second: a string representing the *mode* you want to open the file in: `"w"` (writing, output), `"r"` (reading, input)
* If successful, it returns a valid pointer
* If not successful, it returns `NULL`
  * Ex: it may not exist (opening for reading)
  * Ex: your program may not have the permissions to do so
* Examples
  
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

* There are many ways to do file output
* Let's KISS = Keep It Simple Stupid!
* You can use `fprintf()`
* IT has the exact same behavior and formatting placeholders as `printf` but a new first argument: the file you want to print to

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

* There are a lot of ways to do file input
* MOST are dangerous
* KISS: you can use `fgetc()` or `fgets()`
* `fgetc()` gets and returns a single character from the file at a time, advancing the file pointer to the next character
* When the end of the file is reached, it returns a special flag value, `EOF` (end-of-file)

```c
FILE *in = fopen("data.txt", "r");

char c;
c = fgetc(in);
while(c != EOF) {
  printf("%c ", c);
  c = fgetc(in);
}

fclose(in);
```

* You can use `fgets()` to read up to an entire line from a file at once
* `char *fgets(char *s, int size, FILE *stream);`
  * `s` is the string you want the result from the file to be stored into (it is a *buffer*)
  * `size`: `fgets` will read *at most* `size-1` bytes from the file and place the results into `s` (minus 1 to accommodate the null terminator, which it takes care of for you!)
  * It stops when it sees the first endline character, `\n`
  * THe last argument is the file pointer you are reading from
  * Upon success it returns a valid pointer to the resulting string
  * Upon failure or on reaching the end of the file, it returns, `NULL`
  * `fgets` will *preserve* the endline character if it sees it
  * If you don't want the endline character: you can trim or "chomp" it out (chomp = remove leading and/or trailing whitespace)

```c
FILE *in = fopen("data.txt", "r");

char buffer[1000];
char *s = fgets(buffer, 1000, in);
while(s != NULL) {
  //chomp out the last endline if it exists:
  if(buffer[strlen(buffer)-1] == '\n') {
    buffer[strlen(buffer)-1] = '\0';
  }
  printf("%s", buffer);
  s = fgets(buffer, 1000, in);
}

fclose(in);
```

## Java

* Java defines a class called: `File`

```java
File f = new File("file.txt");
File f = new File("/absolute/path/to/file.txt");
File f = new File("../../archive/file.txt");
```

## File Input

* Lots of ways, but keeping it simple: use a `Scanner`

```java
File f = new File("data/pokemon.csv");
//try-with-resources, it closes it for you:
try (Scanner s = new Scanner(f)) {
  while (s.hasNextLine()) {
    // int x = s.nextInt();
    String line = s.nextLine();
    System.out.println(line);
  }
} catch (FileNotFoundException e) {
  // TODO Auto-generated catch block
  e.printStackTrace();
}
```

* You can use any number of `next()` methods to get tokens out of the file
* By default, whitespace is used as a delimiter and the delimiters are NOT preserved in the result
* You can use `s.hasNextLine()` or `s.hasNext()` to test if you are at the end of a file
* a try-with-resources construct will automatically close the file for you!

## File Output

* Again: many ways, but keep it simple: use `PrintWriter`
* a `PrintWriter` allows you to use `print, println, printf`

```java
File f = new File("data/pokemonOutput.txt");
try (PrintWriter pw = new PrintWriter(f)) {
  pw.print("My favorite Pokemon is... ");
  pw.println(" Ryan Reynolds\n");
  int x = 42;
  pw.printf("here is a number: %d\n", x);
} catch (FileNotFoundException e) {
  // TODO Auto-generated catch block
  e.printStackTrace();
}
```

## Binary File I/O

* Bring in a library!

  
```text






```