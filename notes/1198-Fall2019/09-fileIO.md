
# CSCE 155E - Computer Science I
## File I/O
### Fall 2019

* A *file* is a unit of stored memory, usually on disk
* A file can also be: directories, buffers (standard input/output are files), a socket could be a file, a program is a file
* You can write to and read from a file
* Files may be plaintext or binary (or plaintext but not intended for human consumption: EDI, XML, JSON, base-64 encoding)
* The basic steps to follow are:
	1. Open the file
	2. Process the file
	3. Close the file
	
### Opening a file in C

* A file is represented by `FILE *` built into the standard library
* To open a file you use the `fopen()` function
* `fopen()` takes two arguments:
  * A string representing the path to the file you want to open
	* The second is a string representing the *mode*: `"r"` (reading, file input), `"w"` (writing, file output)
	
```c
//open a file in the current directory for reading:
FILE *inputFile = fopen("data.txt", "r");

//open a file in the current directory for writing:
FILE *outputFile = fopen("output.txt", "w");

//you can also use relative and absolute paths
//relative path: two levels up from the current directory
FILE *f = fopen("../../data.txt", "r");

//absolute path:
FILE *f = fopen("/etc/passwd", "r");

```

* Opening a file may fail:
  * Permission may not be available to read or write to a directory
	* The file may not exist (usually it will be created for you)
* If a file opening fails, then `fopen()` returns `NULL`
* You can thus check to see if a file opening failed or succeeded

```c
FILE *f = fopen("/etc/shadow", "r");

if(f == NULL) {
	printf("failed to open file\n");
} else {
  printf("you may start reading/writing\n");
}
```

* In general if you open a file for writing, it will be created for you
* In fact, if a file exists and you open it for writing, its contents will be *overwritten*

### Closing a file

* Once you are done processing a file you should close it
* Failure to close a file may lead to file corruption
* To close a file use the `fclose()`, you pass it the file
pointer that you want to close
* Attempts to read or write after a file is closed are *undefined behavior*

```c
FILE *f = fopen("/etc/passwd", "r");
//TODO: process the file
//close the file:
fclose(f);
```

## File Output (plaintext output)

* There are many ways to do file output (writing)
* We're going to focus one one: `fprintf`
* `fprintf` takes the file pointer as the first argument, then the usual arguments follow

```c
FILE *outputFile = fopen("output.txt", "w");
int x = 42;
int pi = 3.14159;
char name[] = "Chris";
char midInit = 'M'
fprintf(outputFile, "x = %d, pi is %10.2f\n\tYou are %s %c.\n", x, pi, name, midInit);
fprintf(outputFile, "Hello world how are you?\n");
fclose(outputFile);
```

## File Input (plaintext files)

* There are many ways to do file input
* Most of them are extremely dangerous 
* We'll focus on two "safe" version instead: `fgetc` and `fgets`
* `fgetc` gets a single character from the file and advances the file pointer to the next character (ie this function limits input to one byte at a time)
* `fgetc` returns a special "character", `EOF` when it gets to the end of a file
* Example:

```c
FILE *inputFile = fopen("data.txt", "r");
char c = fgetc(inputFile);
while(c != EOF) {
	printf("read: %c\n", c);
	c = fgetc(inputFile);    
}
```

* Alternatively you can read an entire line at once using `fgets`
* `fgets` gets up to the entire string (line) at once
* You provide it several arguments: `*fgets(char *s, int size, FILE *stream);`
  * `s`: the destination string that the line in the file will be stored in
	* your destination string needs to be big enough to hold whatever you're reading
	* The second argument limits the number of character to be read to `size - 1` (minus one: because it includes the null terminating character for you!)
	* The third argument is the file to be read from
* `fgets` will read up to `size - 1` bytes (characters) or STOP early if it encounters the endline character
* `fgets` *retains* the endline character, you need to manually remove it if you don't want it
* `fgets` returns a pointer to the string (`char *`) that it read, so when it reaches the end of the file it returns `NULL`

```c
FILE *inputFile = fopen("data.txt", "r");
char buff[100];
char *s = fgets(buff, 100, inputFile);
//read the entire file line by line until the end
while(s != NULL) {
	printf("line = %s\n", buff);
	s = fgets(buff, 100, inputFile);
	//buff[strlen(buff)-1] = '\0';
}
```

* `fgets` always retains the endline character (if it encountered it)
* You can "chomp" it out by setting the endline character `\n` to the null terminating character, `\0`

### Binary Data in C

* C Provides two functions to do binary I/O: `fread` (binary input) `fwrite` for binary output
* `size_t fwrite(const void *restrict ptr, size_t size, size_t nitems, FILE *restrict stream);
* In general binary data is more compact and efficient
* Demonstration:

```c
int arr[] = {2147000000, 2147000001, 2147000002, 2147000003};
int n = 4;
//write an entire array to a binary file:
FILE *f = fopen("output.bin", "w");
fwrite(arr, sizeof(int), n, f);
fclose(f);

f = fopen("numbers.txt", "w");
fprintf(f, "%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
fclose(f);
```

	
	
	
	
	
	
	