# Computer Science I
## ECEN 1940 - Spring 2022
### Introduction/Getting Started

- Course Overview
- Syllabus
- Getting Started

## Programming, Compiling, Running

* Source files are *plain text* files containing computer code in a highlevel programming language
* Source files have to be compiled into an *executable program* (binary code)
  * *source → assembly → machine code*

### Demonstration

  1. Edit a source file `hello.c`
  2. Assemble: `gcc -S hello.c`
  3. Compile: `gcc -c hello.c`
    * Produces an object file, `hello.o`
    * View: `hexdump -C hello.o`
  4. You need to also *link* in any external libraries

  * All at once: `gcc hello.c`
