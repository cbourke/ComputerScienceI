
# CSCE 155E - Computer Science I
## File I/O
### Fall 2020

* A *file* is a unit of stored memory, usually on disk
* Files are also directories, buffers (standard input/output), a socket could be file, a program is a file
* Files may be read from (input) or written to (output)
* Files may be plaintext or binary (or plaintext but structured and not intended for human consumption): JSON, XML, etc. Base-64 encoding
* Basic steps of working with files:
  1. Open the file
  2. Process the file
  3. Close the file

### Opening a file in C

* A file is represented by the `FILE *` built into the standard library
* To open a file use `fopen()` function
* The `fopen()` function takes two arguments:
  * a string representing the path/name of the file you want to open
  * a second string that represents the *mode*: `"r"` (input, reading), `"w"` (writing, output)
  * It returns a pointer to the file (upon success)
* Examples

```c
//open a file in the current directory for reading:
FILE *in = fopen("data.txt", "w");

//if it fails to open, NULL is returned:
if(in == NULL) {
    printf("failed to open data.txt file\n");
}

//open a file using a relative path:
FILE *in = fopen("../archive/setup.sh", "r");

//open a file using an absolute path:
FILE *in = fopen("/etc/passwd", "r");
```

* Opening a file for reading that does not exist or that you do not have permissions to will result in `NULL`
* Opening a file that does not exist for *writing* ends up creating the file
* Opening a file that exists for writing will start *overwritting* the file

## Closing a File

* Once you are done with a file, be sure to close it
* Failure to close could result in file corruption or it not saving
* To close a file, use `fclose()`: simply pass it the file pointer you want to close

```c
FILE *f = fopen("/etc/passwd", "r");
//... process the file
fclose(f);
```

## File Output

* To keep it simple, just use `fprintf()`

```c
FILE *out = fopen("data.txt", "w");

int x = 42;
double pi = 3.14159;
char name[] = "Chris Bourke";

fprintf(out, "This is a simple sentence\n");
fprintf(out, "\n\n\n");
fprintf(out, "This is another simple sentence\n");
fprintf(out, "Hello, %s, your number is %d\n", name, x);
fprintf(out, "also, pi is about %.3f\n", pi);

fclose(out);
```

## File Input

* There are many ways to do file input
* I'll keep it simple and show you the two easiest/useful/safe ways
* Focus on 2 functions: `fgetc`, `fgets`
* `fgetc` gets a single character from the file and advances the file poitner to the next character
  * Ie it reads one byte at a type
  * It returns the character it read
  * When it reaches the end of the file it returns a special character, `EOF` (this is NOT a valid ASCII character) EOF=end of file

```c
FILE *in = fopen("data.txt", "r");

char c = fgetc(in);
while(c != EOF) {
  printf("read: %c\n", c);
  c = fgetc(in);
}

fclose(in);
```

* `fgets` gets an entire line of the file up to a maximum number of bytes/characters
  * `char *fgets(char *s, int size, FILE *stream);`
  * The first input is the buffer or string that you want the result stored in (it reads up to a full line and stores it in `s`)
  * The second is the *limit*: it reads at most `size-1` bytes from the file: minus one because it needs space for the null-terminator character *which it takes care of for you*!
  * The third is the file pointer you are reading in from
  * The return value is a pointer to the resulting string (ie `s`) upon success.  
  * up on failure or the end of the file: returns `NULL`
  * Also: the endline characters *ARE* included in the read input
  * If you don't want them, then "chomp" them out

```c

  FILE *in = fopen("data.txt", "r");

  //buffer that is "large enough"
  char buffer[1000];

  char *s = fgets(buffer, 1000, in);
  while(s != NULL) {
    if(s[strlen(s)-1] == '\n') {
      s[strlen(s)-1] = '\0'; //chomp it out...
    }
    printf("line = %s\n", s);
    s = fgets(buffer, 1000, in);
  }

  fclose(in);
```

### Binary Data in C

* Binary data should be handled by libraries
* C provides two functions to do binary I/O: `fread`, `fwrite`
* `size_t fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);`

```c

FILE *out = fopen("output.bin", "w");
FILE *out_text = fopen("output.txt", "w");

int primes[] = {2147000000, 2147000001, 2147000002, 2147000003, 2147000000, 2147000000, 2147000000, 2147000000};
int n = 8;

//write all 8 integers to the output file at once:
fwrite(primes, sizeof(int), n, out);
for(int i=0; i<n; i++) {
    fprintf(out_text, "%d\n", primes[i]);
}

fclose(out);
fclose(out_text);
```

```text





```
