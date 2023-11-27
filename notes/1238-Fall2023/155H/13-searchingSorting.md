
# CSCE 155H - Computer Science I
## Algorithms, Searching & Sorting
### Fall 2023

# Introduction & Demonstration

* Huge part of Computer Science: data processing
* Fundamental operations: *searching*, *sorting*
* Form the basis or preprocessing step of many algorithms
* Large variety of algorithms have been developed  

## Demo

* Demo: write a function to search a collection for a particular element

## Searching and Sorting in Practice

* In general you do *not* write your own implementations of searching/sorting
* You use built-in functions for doing so
* Those built-in functions are *generic*: they can take an array/list of any type of thing
* Problem: it doesn't know what those "things" are or *how* to compare them
* To compare, you provide the search/sort function with a *comparator*

### Comparator in C

* In C, a *comparator function* is a function that compares two  generic elements $a, b$ and returns:
  * it returns *something* negative if a < b
  * it returns zero if a is equal to b
  * it returns *something* positive if a > b (b < a)
* In C the signature of a comparator function *MUST* Be:

`int cmp(const void *a, const void *b)`

* returns an integer
* takes two arguments
* *both* must be `const` and are unchangeable
* Both are *generic void pointers*: pointers that can point to any data type (`int`, `double`, `Book`, etc)
* Inside a comparator function, you follow the general pattern:
  1. You *cast* the two generic pointers as the types of data you expect
  2. Now that they are of a type you can deal with, you compare them: you return something positive/negative/zero depending on the order you want

### Comparators in Java

* Java is an OOP language: everything in Java is a class or belongs to a class
* Ie: no "comparator functions"
* Instead: `Comparator<T>` classes that implement one method: `public int compare(T a, T b);`
* Demo code:

```java

		List<Integer> numbers = Arrays.asList(7, 1, 8, 6, 2, 5, 8, 3);
		int key = 8;

		Comparator<Integer> compareInt = new Comparator<>() {

			@Override
			public int compare(Integer a, Integer b) {
				if(a < b) {
					return -1;
				} else if(a > b) {
					return 1;
				} else {
					return 0;
				}
			}

		};

		Comparator<Book> compareBookByTitle = new Comparator<>() {

			@Override
			public int compare(Book a, Book b) {
				return a.getTitle().compareTo(b.getTitle());
			}

		};

		Comparator<Book> byAuthorThenDate = Comparator.comparing(Book::getAuthor).thenComparing(Book::getPublishDate);
		Comparator<Book> byTitleThenDate = Comparator.comparing(Book::getTitle)
				.thenComparing(Book::getPublishDate);


		Collections.sort(numbers, compareInt);
		int indexOf = Collections.binarySearch(numbers, key, compareInt);
		System.out.printf("Found %d at index %d\n", key, indexOf);
		System.out.println(numbers);

		List<Book> books = Book.loadBooks("data/books.csv");
		Book bookKey = new Book("Dune", null, null, 0.0);
		Collections.sort(books, compareBookByTitle);
		indexOf = Collections.binarySearch(books, bookKey, compareBookByTitle);
		System.out.printf("Found %s at index %d\n", books.get(indexOf), indexOf);

		Collections.sort(books, byAuthorThenDate);
		for(Book b : books) {
			System.out.println(b);
		}
```

* In addition, a class (`Author`) can be made "naturally ordered" by making it `Comparable`:

```java
public class Author implements Comparable<Author> {
   ...

 @Override
 public int compareTo(Author that) {
   //we need to compare *this* author to *that* author
   int result = this.authorLastName.compareTo(that.authorLastName);
   if(result == 0) {
     //same last names, so look at the first name:
     result = this.firstName.compareTo(that.firstName);
   }
   return result;
 }
}
```

# Binary Search

* Basic idea: assume an *array* is sorted
* To search for a key $k$: check the middle element $a_m$
  * If $a_m = k$: done found it
  * If $k < a_m$: search the left half
  * If $k > a_m$: search the right half
* In either case: you've cut the array in half
* Repeat until found or until the "section" is empty



```text







```
