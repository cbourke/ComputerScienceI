# Hack 10.0 - File I/O
## Java Edition
**[School of Computing](https://computing.unl.edu/)**  
**[College of Engineering](https://engineering.unl.edu/)**  
**[University of Nebraska-Lincoln](https://unl.edu)**  
**[University of Nebraska-Omaha](https://http://unomaha.edu/)**  

# Introduction

Hack session activities are small weekly programming assignments
intended to get you started on full programming assignments. You may
complete the hack on your own, but you are *highly encouraged* to work
with another student and form a hack pair. Groups larger than 2 are not
allowed. However, you may discuss the problems *at a high level* with
other students or groups. You may not share code directly outside your
pair.

If you choose to form a Hack Pair, you *must*:

1.  Both join a hack pair on Canvas (go to People then Groups)

2.  You must both work on the hack equally; it must be an equal effort
    by both partners. Do not undermine your partner's learning
    opportunity and do not undermine your own by allowing one parter to
    do all the work.

3.  You may both turn in a copy, but only one will be graded (generally
    the one whose last name comes first alphabetically).

## Rubric

You are graded based on style, documentation, design and correctness.
For detail, see the general course rubric.

| Category      | Points |
|---------------|--------|
| Style         | 2      |
| Documentation | 2      |
| Design        | 5      |
| Correctness   | 16     |
| Total         | 25     |

For correctness:
 - Your program(s) *must* compile and run on the grader
 - 5 points for each function
 - 1 point for error handling
 - 5 points for protein program

# Exercises

To get more practice working with files, you will write several methods
that involve operations on files. In particular, implement the following
functions.

1.  Write a method that, given a file path/name as a string opens the
    file and returns its entire contents as a single string. Any endline
    characters should *be preserved*.

    `public static String getFileContents(String filePath)`

2.  Write a method that, given a file path/name as a string opens the
    file and returns the contents of the file as a list of strings. Each
    element in the list should correspond to a line in the file. Any end
    line character should be *chomped out* and not included.

    `public static List<String> getFileLines(String filePath)`

## Protein Translation

DNA is a molecule that encodes genetic information. A DNA sequence is a
string of nucleotides represented as letters A, T, C, and G
(representing the nucleobases adenine, thymine, cytosine, and guanine
respectively). Protein sequencing in an organism consists of a two step
process. First the DNA is translated into RNA by replacing each thymine
nucleotide with uracil (U). Then, the RNA sequence is translated into a
protein (a sequence of amino acids) according to the following rules.

The RNA sequence is processed 3 bases at a time called a *codon*. Each
codon is translated into a single amino acid according to known encoding
rules. There are 20 such amino acids, each represented by a single
letter in $$(A,C,D,E,F,G,H,I,K,L,M,N,P,Q,R,S,T,V,W,Y)$$ Because there
are $4^3 = 64$ possible codons but only 20 amino acids, some codons
translate to the same amino acid.

The rules for translating trigrams are complex, but we've simplified the
process by providing starter code that includes a `Map` which is
an extremely useful data structure that allows you to map keys to
values. In this case, the `Map` maps RNA codons (as strings) to
proteins (as a single character string). If you provide it an invalid
sequence, it will return `null`.

In addition, the trigrams UAA, UAG, and UGA are special markers that
indicate a (premature) end to the protein sequencing (there may be
additional nucleotides left in the RNA sequence, but they are ignored
and the translation ends). The `Map` we've provided will return a
lower-case `x` character for any of these three trigrams.

As an example, suppose we start with the DNA sequence $AAATTCCGCGTACCC$;
it would be encoded into RNA as $AAAUUCCGCGUACCC$; and into an amino
acid sequence $KFRVP$.

You will write a program that takes two command line arguments. The
first is an input file containing a DNA sequence and the second is the
name of the output file in which you'll place the translated protein
sequence.

The input file *may* contain irrelevant whitespace characters to avoid
very long lines. You will need to *ignore* any whitespace characters
when you process the data.

# Instructions

-   For the exercises, place all your methods into a source file named
    `FileUtils.java` with proper documentation. In addition,
    you'll want to create a main test driver program that demonstrates
    at least 3 cases per method to verify their output. You need not
    hand it in, however.

-   Code for the RNA-to-protein `Map` as well as a demonstration
    on how to use it has been provided in the
    `ProteinTranslator.java` source file. You should add your
    translation code using this class.  All classes should be in the
    `unl.soc` package.

-   **Hint**: Code reuse is a Very Good Thing. Your protein program can
    use your file utility methods, but also: feel free to include any
    additional functions you may have written before in the
    `FileUtils.java` file and use them in your protein translator
    program.

-   You may (in fact are encouraged) to define any additional "helper"
    methods that may help you.
