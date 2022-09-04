---
date:  
subtitle: |
  Computer Science I - Java\
  File I/O\
  Department of Computer Science & Engineering\
  University of Nebraska--Lincoln
title: Hack 10.0
---

------------------------------------------------------------------------

# Exercises {#exercises .unnumbered}

To get more practice working with files, you will write several methods
that involve operations on files. In particular, implement the following
functions.

1.  Write a method that, given a file path/name as a string opens the
    file and returns its entire contents as a single string. Any endline
    characters should *be preserved*.

    `public static String getFileContents(String filePath)`{.java}

2.  Write a method that, given a file path/name as a string opens the
    file and returns the contents of the file as a list of strings. Each
    element in the list should correspond to a line in the file. Any end
    line character should be *chomped out* and not included.

    `public static List<String> getFileLines(String filePath)`{.java}

## Protein Translation {#protein-translation .unnumbered}

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
process by providing starter code that includes a `Map`{.java} which is
an extremely useful data structure that allows you to map keys to
values. In this case, the `Map`{.java} maps RNA codons (as strings) to
proteins (as a single character string). If you provide it an invalid
sequence, it will return `null`{.java}.

In addition, the trigrams UAA, UAG, and UGA are special markers that
indicate a (premature) end to the protein sequencing (there may be
additional nucleotides left in the RNA sequence, but they are ignored
and the translation ends). The `Map`{.java} we've provided will return a
lower-case `x`{.c} character for any of these three trigrams.

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

# Instructions {#instructions .unnumbered}

-   For the exercises, place all your methods into a source file named
    `FileUtils.java`{.text} with proper documentation. In addition,
    you'll want to create a main test driver program that demonstrates
    at least 3 cases per method to verify their output. You need not
    hand it in, however.

-   Code for the RNA-to-protein `Map`{.java} as well as a demonstration
    on how to use it has been provided in the
    `ProteinTranslator.java`{.text} source file. You should add your
    translation code using this class.

-   **Hint**: Code reuse is a Very Good Thing. Your protein program can
    use your file utility methods, but also: feel free to include any
    additional functions you may have written before in the
    `FileUtils.java`{.text} file and use them in your protein translator
    program.

-   You are encouraged to collaborate any number of students before,
    during, and after your scheduled hack session.

-   You may (in fact are encouraged) to define any additional "helper"
    methods that may help you.

-   Include the name(s) of everyone who worked together on this activity
    in your source file's header.

-   Turn in all of your files via webhandin, making sure that it runs
    and executes correctly in the webgrader. Each individual student
    will need to hand in their own copy and will receive their own
    individual grade.
