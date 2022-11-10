package unl.cse;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Demo {
	
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
		
		
		List<Book> library = Demo.loadFromFile("data/books.csv");
		
		Book highestRated = Demo.getHighestRatedBook(library);
		System.out.printf("The highest rated book was %s\n", highestRated);

		Book lowestRated = Demo.getLowestRatedBook(library);
		System.out.printf("The lowest rated book was %s\n", lowestRated);
		
		Author a = new Author("Frank", "Herbert");
		List<Book> franksBooks = getBooksByAuthor(library, a);
		for(Book b : franksBooks) {
			System.out.println(b);
		}

	}
}
