
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

* Even easier: Java's NIO (non-blocking I/O) library:

```java
Path path = Paths.get("data/foo.txt");
List<String> lines;
try {
  lines = Files.readAllLines(path);
  System.out.println(lines);
} catch (IOException e) {
  throw new RuntimeException(e);
}
```

## File Output

* Simplest way: `PrintWriter`
* It allows you to use `print, println, printf` methods

```java

		File f = new File("data/output.txt");
		try {
			PrintWriter pw = new PrintWriter(f);
			pw.print("Hello World");
			pw.println("Goodbye World");
			int x = 42;
			double y = 123.4;
			String name = "Chris";
			pw.printf("x = %d, y = %f, name = %s\n", x, y, name);
			pw.close();
		} catch (FileNotFoundException e) {
			throw new RuntimeException(e);
		}
```

# Book Demo

```c

    //what is the highest rated book?
    //load up the data line by line: File Input
    //.  process each token (piece of data): strtok
    //.  find the highest rating...
    //.  does that give us the actual book?

    double highestRating = 0.0;
    char *highestRatedTitle = NULL;
    char *authorFirstName = NULL;
    char *authorLastName = NULL;

    //1. open the file
    FILE *f = fopen("./books.csv", "r");
    //1a buffer to hold each line value...
    char buffer[1000];
    //ignore the first line (header data)
    char *line = fgets(buffer, 1000, f);
    line = fgets(buffer, 1000, f);
    while(line != NULL) {
        if(buffer[strlen(buffer)-1] == '\n') {
            buffer[strlen(buffer)-1] = '\0';
        }
        //printf("line = %s\n", line);
        //process the line: tokenize it and find the rating
        if(strlen(buffer) > 0) {
           char *token;
           token = strtok(buffer, ",");
           int bookId = atoi(token);
           token = strtok(NULL, ",");
           char *title = deepStrCpy(token);
           token = strtok(NULL, ",");
           char *firstName = deepStrCpy(token);
           token = strtok(NULL, ",");
           char *lastName = deepStrCpy(token);
           token = strtok(NULL, ",");
           char *isbn = deepStrCpy(token);
           token = strtok(NULL, ",");
           double rating = atof(token);
           //TODO: the others: Publisher,Original Publication Year,Date Read
           //printf("rating = %f\n", rating);
           if(rating > highestRating) {
             highestRating = rating;
             highestRatedTitle = title;
           }
        }
        line = fgets(buffer, 1000, f);
    }

    fclose(f);

    printf("Highest rating: %.2f\n", highestRating);
    printf("Title of best book: %s\n", highestRatedTitle);

```

```java

		double highestRating = 0.0;
		String bookTitle = null;
		String authorFirstName = null;
		String authorLastName = null;

		File f = new File("data/books.csv");
		try {
			Scanner s = new Scanner(f);

			String line = s.nextLine();
			while (s.hasNextLine()) {
				line = s.nextLine();
				if (!line.isEmpty()) {
					String tokens[] = line.split(",");
					int bookId = Integer.parseInt(tokens[0]);
					String title = tokens[1];
					String lastName = tokens[3];
					String firstname = tokens[2];
					String isbn = tokens[4];
					double rating = Double.parseDouble(tokens[5]);
					// TODO: handle the rest of the data..
					if (rating > highestRating) {
						highestRating = rating;
						bookTitle = title;
						authorFirstName = firstname;
						authorLastName = lastName;
					}
				}
			}

			s.close();
		} catch (FileNotFoundException e) {
			throw new RuntimeException(e);
		}

		System.out.println("Highest rating: " + highestRating);
		System.out.printf("%s by %s, %s\n", bookTitle, authorLastName, authorFirstName);

```


```text













```
