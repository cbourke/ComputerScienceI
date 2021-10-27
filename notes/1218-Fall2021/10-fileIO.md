
# CSCE 155E - Computer Science I
## File I/O
### Fall 2021

* A *file* is a unit of stored memory, usually on disk
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

* A file in C is represented by a pointer, `FILE *`
* To open a file you use `fopen()`
* The `fopen()` function takes two arguments:
  * A string representing the path/file name of the file you want to open
  * A string representing the *mode*
  * Mode: `"r"` (reading, input), `"w"` (writing, output)
  * Upon success it returns a `FILE *` to the file (sometimes this is referred to as a "handle")

```c

  //opens the books.csv file assumed to be in
  //the current working directory (cwd)
  //FILE *f = fopen("books.csv", "r");

  //you can also use "absolute paths"
  //FILE *f = fopen("/etc/shadow", "r");

  //you can use relative directories:
  FILE *f = fopen("../honors/foo.txt", "r");

  if(f == NULL) {
      printf("unable to open file for some reason\n");
  } else {
      printf("success!\n");
  }
```

* OPening a file for reading may fail: it may not exist, you may not have permissions, etc.
* Opening a file that doesn't exist for *writing* will actually end up creating that file for you!
* opening a file for writing that already exists will *overwrite* or "clobber" the contents of that file

## Closing a File

* Once you are done processing a file, be sure to close it
* Failure to do so could result in file corruption
* Use `fclose()` to close a file, pass it the file handle/pointer

```c
//3. close the file:
fclose(f);
```

## File Output

* To keep it simple use `fprintf()`
* Instead of printing to the standard output, you print to a file
* EVERYTHING you know and love about `printf()` can be used with `fprintf()`

```c

  //TODO: process the file
  int x = 42;
  double pi = 3.14159;
  char name[] = "Chris Bourke";

  fprintf(f, "x = %d, pi to 3 decimals is %.3f, hello %s\n", x, pi, name);
```

## File Input

* There are *many* ways to do file input
* most of them are *extremely dangerous*
* Two simple/safe methods are:
  * `fgetc()`
  * `fgets()`
* `fgetc` gets a single character from the file and advances the file pointer to the next character
  * It reads 1 character or byte at a time
  * It returns the character that it read: `char`
  * When it reaches the end of a file, it returns a special character `EOF`

```c

  //read it in character by character
  char c = fgetc(f);
  int count = 0;
  while(c != EOF) {
      count++;
      printf("c = %c\n", c);
      c = fgetc(f);
  }
  printf("read %d characters\n", count);
```

### `fgets()`

* `fgets` gets up to an entire line of the file at once, but limits itself to a certain size
  * `char *fgets(char *s, int size, FILE *stream);`
  * The first parameter is the *buffer* or string where the result will be stored.  
  * The second is the limiting size: generally the size of the buffer
  * It will read at most `size-1` characters from the file and place the result into `s`
  * If it encounters the endline character first, then it stops
  * `fgets` will insert the null terminator `\0` for you!
  * `fgets` will retain the endline character in the result!
  * If you don't want it, "chomp" it out

```c

  char buffer[1000];
  char *line = fgets(buffer, 1000, f);
  while(line != NULL) {
    if(buffer[strlen(buffer)-1] == '\n') {
      buffer[strlen(buffer)-1] = '\0';
    }
    printf("line = %s\n", buffer);
    line = fgets(buffer, 1000, f);
  }
```

  * When `fgets` reaches the end of a file, it returns `NULL`


### Binary Data in C

  * Binary data should be handled by libraries
  * C provides two functions to do binary I/O: `fread`, `fwrite`
  * `size_t fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);`

```text



```
