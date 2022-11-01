
# ECEN 194 - Computer Science I
## File I/O
### Fall 2022

* A *file* is a unit of stored memory, usually on disk
* Files are also directories, programs are files, buffers, sockets
* Files may be read (input), or written (output)
* Files may be binary (pure data) or plaintext files (ASCII)
* Even plaintext files may be *structured* and not intended for human consumption: CSV, XML, JSON, etc. Base-64 encoding:
* EDI = Electronic Data Interchange
* Basic steps to working with files:
 1. Open the file
 2. Process the file
 3. Close the file

## Opening a file

* In C a file is represented by a pointer: `FILE *`: sometimes this is called a "handle": it automatically advances through the file as you read it
* To open a file use `fopen()`: it takes two arguments:
  * A string representing the path/file name to be opened
  * A string representing the *mode*: `"r"` (reading, file input), `"w"` (writing, file output)
  * IT returns a `FILE *` pointer upon success
  * If it does not succeed it returns `NULL`
    * It may not exist, we may not have permissions, etc.

## Closing a File

* You simply use `fclose()` and pass the file pointer into it
* failure to correctly close a file may result in lost data, corrupted data or undefined behavior

```c  
//opens test.txt which is assumed to be in the current workin directory
FILE *h = fopen("foo.txt", "r");
//absolute paths:
FILE *h = fopen("/etc/passwd", "r");
//relative paths:
FILE *h = fopen("../data/test.txt", "r");

```

## File Output

* You can use `fprintf()` just like you would `printf` to "print" to a file (do file output)

```c

  FILE *f = fopen("myFile.txt", "w");

  int x = 42;
  double y = 4234.52432;
  char name[] = "University of Nebraska-Omaha";

  fprintf(f, "Hello World\n");
  fprintf(f, "x = %d, y = %f\n", x, y);
  fprintf(f, "welcome to %s", name);

  fclose(f);
```

## File Input

* Keep it simple:
  * Use `fgetc()` to read character by character
  * Use `fgets()` to read line by line

## Reading Character by Character

* `fgetc()` reads and returns a single character from the file
* It returns a special `EOF` character (this is NOT a valid ASCII text character) that indicates the *end of file*!

```c

int countCharsInFile(const char *fileName) {

  FILE *f = fopen(fileName, "r");

  if(f == NULL) {
    return 0;
  }

  char c = fgetc(f);
  int count = 0;
  while( c != EOF ) {
    count++;
    c = fgetc(f);
  }

  fclose(f);

  return count;
}

```

### Reading Line By Line

* YOu can use `fgets()` to get *upto* an entire line of the input file; BUT the number of characters is limited to prevent buffer overflows
* Signature of the function:
`char *fgets(char *s, int size, FILE *stream);`
 * First argument: string you want to read the line into
 * second argument: a limit, it will read *at most* `size-1` bytes from the file and place it into `s`, stopping when the limit is reached OR it sees an endline character `\n`
 * It is minus one because it needs room for the null terminating character, `\0` and automatically takes care of it for you!
 * The last argument is the file you are reading from
 * Observation: the endline character (`\n`) is *retained* in the buffer if one is read!
 * The function returns a pointer:
   * Usually this points to the buffer to indicate that you successfully read a line from the file
   * Otherwise, when it gets to the end of a file, it returns `NULL` and the buffer is unchanged!

```c

  FILE *f = fopen("myFile.txt", "r");

  char buffer[1000];

  char *line = fgets(buffer, 1000, f);
  while(line != NULL) {
    //chomp out the last character IF it is an endline character:
    if( buffer[strlen(buffer)-1] == '\n' ) {
      buffer[strlen(buffer)-1] = '\0';
    }
    printf("line = %s\n", buffer);
    line = fgets(buffer, 1000, f);
  }

  fclose(f);
```

## Binary Files

* Consider a "large" integer value: 2147000000
  * If it is stored in plaintext: how many bytes does it take to represent? A: 10
  * If stored in binary, how many bytes? `sizeof(int)`: 4

```text











```
