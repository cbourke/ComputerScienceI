
# CSCE 155H - Computer Science I
## File I/O
### Fall 2023

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

* In C files are represented with a pointer: `FILE *`
* To open a file you use `fopen()`
  * First parameter: a string representing hte *path* and name of the file
  * Second: mode you want to open it for: `"r"` (read, input), `"w"` (write, output)
  * It returns (if successful) a pointer to the file starting at the first byte/character
  * As you read the file, the pointer is automatically advanced to the next character/line/etc.
* To close a file: `fclose()`
  * ONce closed, that's it, the file is saved, you are done with it

```c

  //open a file in the same directory:
  FILE *f = fopen("books.csv", "r");

  //open a file in a *relative* path
  FILE *f2 = fopen("../review/review.c", "r");

  //open a file in an absolute path:
  FILE *f3 = fopen("/etc/blasdjkflaksjd", "r");

  if(f3 == NULL) {
    printf("could not open file!\n");
    exit(1);
  }

  //TODO: process the file here

  fclose(f);
```

* To do file output, just use `fprintf`

```c

  //open a file in the same directory:
  FILE *f = fopen("output.txt", "w");

  int a = 10;
  double b = 3.4;
  fprintf(f, "Hello How are you?\n");
  fprintf(f, "a = %d, b = %f\n", a, b);

  fclose(f);
```

## Java File I/O

* Java defines a class called `File`

```java
File f = new File("file.txt");
File f = new File("/absolute/path/to/file.txt");
File f = new File("../../archive/file.txt");
```

## File Input

* Lots of ways but the easiest: `Scanner`

```java

		File f = new File("data/input.txt");
		try(Scanner s = new Scanner(f)) {
			while(s.hasNextLine()) {
				String line = s.nextLine();
				System.out.println(line);
			}
		} catch (FileNotFoundException e) {
			throw new RuntimeException(e);
		}

		File outFile = new File("data/output.txt");
		try {
			PrintWriter pw = new PrintWriter(outFile);
			pw.print("Hello");
			pw.println(" World");
			pw.printf("%d, %.3f\n", 123, 3.5);
			pw.close();
		} catch (FileNotFoundException e) {
			throw new RuntimeException(e);
		}
```



```text











```
