package unl.cse;

import java.time.LocalDate;

public class Book {
	
	private String title;
	private Author author;
	private LocalDate releaseDate;
	private double rating;
	
	/**
	 * @param title
	 * @param author
	 * @param releaseDate
	 * @param rating
	 */
	public Book(String title, Author author, LocalDate releaseDate, double rating) {
		this.title = title;
		this.author = author;
		this.releaseDate = releaseDate;
		this.rating = rating;
	}
	
	/**
	 * This is a copy constructor: it allows you to create a new copy of a Book instance
	 * possibly with different values; example: a different value for a rating
	 */
	public Book(Book that, double rating) {
		this.title = that.title;
		this.author = that.author;
		this.releaseDate = that.releaseDate;
		this.rating = rating;
		
	}
	

	@Override
	public String toString() {
		return String.format("%s by %s was released in %d with a rating of %f", title, author, releaseDate.getYear(), rating);
	}
	
	public double getRating() {
		return this.rating;
	}

	public String getTitle() {
		return title;
	}

	public Author getAuthor() {
		return author;
	}

	public LocalDate getReleaseDate() {
		return releaseDate;
	}

//	public void setRating(double rating) {
//		if(rating < 0 || rating > 5.0) {
//			throw new RuntimeException("Attempted to set an invalid rating: " + rating);
//		}
//		this.rating = rating;
//	}
	
	

}
