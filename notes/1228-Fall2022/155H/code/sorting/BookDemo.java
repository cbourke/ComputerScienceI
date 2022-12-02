package unl.cse;

import java.io.File;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class BookDemo {
	
	public static final Map<String, Integer> m = new HashMap<String, Integer>();
	static {
		m.put("Freshman", 1);
		m.put("Sophomore", 2);
		m.put("Junior", 3);
		m.put("Senior", 4);
	}	
	
//	public static final Comparator<Book> cmpByAuthorThenByTitle = new Comparator<>() {
//
//		@Override
//		public int compare(Book a, Book b) {
//			int result = a.getAuthor().compareTo(b.getAuthor());
//			if(result == 0) {
//				result = a.getTitle().compareTo(b.getTitle());
//			}
//			return result;
//		}
//	};
	
	public static final Comparator<Book> cmpByAuthorThenByTitle = 
			Comparator.comparing(Book::getAuthor)
			          .thenComparing(Book::getTitle)
			          .thenComparing(Book::getIsbn)
			          .reversed();

	public static final Comparator<Book> cmpByAuthor = new Comparator<>() {

		@Override
		public int compare(Book a, Book b) {
			
//			int result = a.getAuthor().getLastName().compareTo(b.getAuthor().getLastName());
//			if(result == 0) {
//				result = a.getAuthor().getFirstName().compareTo(b.getAuthor().getFirstName());	
//			}
//			
//			return result;
			return a.getAuthor().compareTo(b.getAuthor());

		}
		
	};
	
	public static final Comparator<Book> cmpByRatingDesc = new Comparator<>() {

		@Override
		public int compare(Book a, Book b) {
			
//			if(a.getRating() < b.getRating()) {
//				return 1;
//			} else if(a.getRating() > b.getRating()) {
//				return -1;
//			} else {
//				return 0;
//			}
			
			return -Double.compare(a.getRating(), b.getRating());
			
		}
		
	};
	
	public static final Comparator<Book> cmpByRatingAsc = new Comparator<>() {

		@Override
		public int compare(Book a, Book b) {
			
			return Double.compare(a.getRating(), b.getRating());
			
		}
		
	};
	
	public static List<Book> loadFromFile(String fileName) {
		List<Book> library = new ArrayList<>();
		
		try {
			
		
			Scanner s = new Scanner(new File(fileName));
			String firstLine = s.nextLine();
			int numRecords = Integer.parseInt(firstLine);
		
			for (int i = 0; i < numRecords; i++) {
	
				// read the next line...
				String line = s.nextLine();
				// tokenize each line to get each token of data
				String tokens[] = line.split(",");
	
				String title = tokens[0];
				String authorFirstName = tokens[1];
				String authorLastName = tokens[2];
				String yearString = tokens[3];
				int yearReleased = Integer.parseInt(yearString);
				String ratingString = tokens[4];
				double rating = Double.parseDouble(ratingString);

				Author a = new Author(authorFirstName, authorLastName);
				LocalDate releaseDate = LocalDate.of(yearReleased, 1, 1);
				Book b = new Book(title, a, releaseDate, rating);
				//TODO: add the book to my "library"
				library.add(b);
				
			}
	
			s.close();
	
		} catch(Exception e) {
			throw new RuntimeException(e);
		}
		
		return library;
		
	}
	
	public static Book getHighestRatedBook(List<Book> library) {
		
		double rating = -1;
		Book bestBook = null;
		for(Book b : library) {
			if(b.getRating() > rating) {
				bestBook = b;
				rating = b.getRating();
			}
		}
		return bestBook;
	}
	
	public static Book getLowestRatedBook(List<Book> library) {
		
		double rating = 10;
		Book worstBook = null;
		for(Book b : library) {
			if(b.getRating() < rating) {
				worstBook = b;
				rating = b.getRating();
			}
		}
		return worstBook;
	}
	
	public static List<Book> getBooksByAuthor(List<Book> library, Author a) {
		List<Book> authorBooks = new ArrayList<>();
		
		for(Book b : library) {
			if( b.getAuthor().equals(a)	) {
				authorBooks.add(b);
			}
		}

		
		return authorBooks;
	}

	public static void main(String[] args) {
		
		
		List<Book> library = BookDemo.loadFromFile("data/books.csv");

		//sort books by rating...
		Collections.sort(library, cmpByRatingDesc);
		

		Book highestRated = library.get(0);
		System.out.printf("The highest rated book was %s\n", highestRated);

		Book lowestRated = library.get(library.size()-1);
		System.out.printf("The lowest rated book was %s\n", lowestRated);

		//reverse:
		Collections.reverse(library);
		//or resort:
		Collections.sort(library, cmpByRatingAsc);

		Author frank = new Author("Frank", "Herbert");
		List<Book> franksBooks = getBooksByAuthor(library, frank);
		for(Book b : franksBooks) {
			System.out.println(b);
		}
		
		System.out.println("Sorted by Author: ");
		Collections.sort(library, cmpByAuthor);
		for(Book b : library) {
			System.out.println(b);
		}
		
		//find a single book by Frank Herbert...
		//create a dummy book key with the author Frank Herbert:
		Book bKey = new Book(null, frank, null, 0.0);
		int index = Collections.binarySearch(library, bKey, cmpByAuthor);
		Book franksBook = library.get(index);
		System.out.println(franksBook);
		
		System.out.println("Sorted by Author/Title: ");
		Collections.sort(library, cmpByAuthorThenByTitle);
		for(Book b : library) {
			System.out.println(b);
		}
		

	}
}
