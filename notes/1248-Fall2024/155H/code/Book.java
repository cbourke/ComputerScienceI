package unl.soc;

import java.time.LocalDate;
import java.time.Period;

public class Book {

	private String isbn;
	private String title;
	private LocalDate publishDate;
	private Double rating;
	private Person author;
	
	public Book(String isbn, String title, LocalDate publishDate, Person author) {
		this(isbn, title, publishDate, author, null);
	}

	public Book(String isbn, String title, LocalDate publishDate, Person author, Double rating) {
		this.isbn = isbn;
		this.title = title;
		this.publishDate = publishDate;
		this.author = author;
		this.rating = rating;
	}

	public Book(String title, LocalDate publishDate, Person author) {
		this(null, title, publishDate, author);
	}
	
	

	@Override
	public String toString() {
		if(this.publishDate == null) {
			return String.format("%s by %s (None) %.2f", this.title, this.author, this.rating);			
		} else {
			return String.format("%s by %s (%d) %.2f", this.title, this.author, this.publishDate.getYear(), this.rating);
		}
	}

	public String getIsbn() {
		return isbn;
	}

//	public void setIsbn(String isbn) {
//		//TODO: validate the isbn as a valid ISBN
//		if(isbn == null) {
//			throw new IllegalArgumentException("You cannot set an ISBN to null");
//		}
//		this.isbn = isbn;
//	}

	public String getTitle() {
		return title;
	}


	public LocalDate getPublishDate() {
		return publishDate;
	}


	public Person getAuthor() {
		return author;
	}
	
	public double getAgeInYears() {
		  Period p = Period.between(this.publishDate, LocalDate.now());
		  double years = p.getYears();
		  years += p.getDays() / 365.0;
		  return years;

	}
	
	public double getRating() {
		if(this.rating == null) {
			return -1;
		} else {
			return this.rating;
		}
	}

	
	

}
