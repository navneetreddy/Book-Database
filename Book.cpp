/*******************************************************************************
Author:         Navneet Reddy
CS Login:       navneet
Course:         CS 368, Fall 2014
Assignment:     Programming Assignment 3
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include "Book.h"

using namespace std;

/*
 * Constructs a default book with an ID of 0, year 0, and 0.0 rating.
 */
Book::Book() {
    bookID = 0;
    year = 0;
    rating = 0.0;
}

/*
 * Constructs a book with the given ID, 0 year, and 0.0 rating.
 *
 * @param ID ID of the book
 */
Book::Book(int ID) {
    bookID = ID;
    year = 0;
    rating = 0.0;
}

/*
 * Constructs a book with the given ID, year, and rating.
 *
 * @param bookID ID of the book
 * @param title title of the book
 * @param year publication year of the book
 * @param rating book rating
 */
Book::Book(int ID, string title, int yr, double rating) {
    bookID = ID;
    this->title = title;
    year = yr;
    this->rating = rating;
}

/*
 * Destructor for a book.
 */
Book::~Book() {
    cout << "Book destructor called on book " << bookID << endl;
}

/*
 * Copy constructor for a book.
 */
Book::Book(const Book& original) {
    cout << "Copy Constructor for " << original.bookID << endl;
    
    bookID = original.bookID;
    title = original.title;
    year = original.year;
    rating = original.rating;
}

/*
 * Copy assignment operator for a book.
 */
Book& Book::operator= (const Book& original) {
    cout << "Copy assignment operator for " << original.bookID << endl;
    
    bookID = original.bookID;
    title = original.title;
    year = original.year;
    rating = original.rating;
    
    return *this;
}

/*
 * Returns the book ID.
 */
int Book::getID() const {
    return bookID;
}

/*
 * Returns the title.
 */
string Book::getTitle() const {
    return title;
}

/*
 * Returns the publication year.
 */
int Book::getYear() const {
    return year;
}

/*
 * Returns the rating.
 */
double Book::getRating() const {
    return rating;   
}

/*
 * Updates the book with the given ID.
 *
 * @param bookID ID of the book to be updated
 * @param year Updated publication year
 * @param rating Updated book rating
 */
void Book::updateBook(int bookID, int yr, double rating) {
    this->bookID = bookID;
    year = yr;
    this->rating = rating;
}

/*
 * Prints the ID, title, publication year and the rating of the book.
 */
void Book::print() const {
    std::cout << std::fixed << bookID << ", " << title << ", " << year << ", " 
        << std::setprecision(2) << rating << std::endl;
}
