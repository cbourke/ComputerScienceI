package unl.soc;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;
import java.util.Set;
import java.util.UUID;

/**
 * Chris Bourke 
 * 2024-09-13
 *
 * Demo Code
 *
 */
public class BookDemo {
	
	public static List<Book> loadBookData(String fileName) {
		List<Book> books = new ArrayList<>();
		
		//1. open the file
		//2. read line by line (ignore the first one
		Path path = Paths.get(fileName);
		List<String> contents;
		try {
			contents = Files.readAllLines(path);
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		//3. for each line: parse the string (tokenize it)
		//3a. remove the first line:
		contents.remove(0);
		for(String line : contents) {
			//Book Id,Title,Last,First,ISBN13,Average Rating,Publisher,Original Publication Year,Date Read
			String tokens[] = line.split(",");
			if(tokens.length == 9) {
				String bookId = tokens[0];
				String title = tokens[1];
				Person p = new Person(tokens[3], tokens[2]);
				String isbn = tokens[4];
				double rating = Double.parseDouble(tokens[5]);
				String publisher = tokens[6];
				LocalDate publishDate;
				try {
					publishDate = LocalDate.of(Integer.parseInt(tokens[7]), 1, 1);
				} catch(NumberFormatException nfe) {
					publishDate = null;
				}
				//4. create a book with the given data
				Book b = new Book(isbn, title, publishDate, p, rating);
				books.add(b);
			}
		}
		
		
		return books;
	}
	

	public static void main(String[] args) {

		Person p1 = new Person("Ursula", "le Guin");
		Person p2 = new Person("Ray", "Bradbury", LocalDate.of(1920, 8, 22));
 
	    Book b1 = new Book("The Dispossessed", LocalDate.of(1974, 1, 1), p1);
	    Book b2 = new Book("Fahrenheit 451", LocalDate.of(1952, 1, 1), p2);
	    
	    System.out.println(b1);
	    System.out.println(b2);
		
	    Set<Book> library = new HashSet<>();
	    library.add(b1);
	    library.add(b2);
	    System.out.println(library);
	    
	    System.out.println(b1.getAgeInYears());
	    System.out.println(b2.getAgeInYears());
	    
	    List<Book> books = BookDemo.loadBookData("data/goodreads.csv");	    
	    for(Book b : books) {
	    	System.out.println(b);
	    }
	    
	    //Goal 1: find the best book
	    Book bestBook = books.get(0);
	    for(Book b : books) {
	    	if(b.getRating() > bestBook.getRating()) {
	    		bestBook = b;
	    	}
	    }
	    //print best rating
	    System.out.println("Best book: " + bestBook);
	    
	    //Goal 2: find the newest book
	    Book newestBook = books.get(0);
	    for(Book b : books) {
//	    	if(b.getPublishDate().compareTo(newestBook.getPublishDate()) > 0) {
//	    		newestBook = b;
//	    	}
	    	if( b.getPublishDate() != null && newestBook.getPublishDate() != null && 
	    			b.getPublishDate().compareTo(newestBook.getPublishDate()) > 0) {
	    		newestBook = b;
	    	}

	    }
	    //print best rating
	    System.out.println("Newest book: " + newestBook);
	    

	}
	

}
