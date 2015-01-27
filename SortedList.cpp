/*******************************************************************************
Author:         Navneet Reddy
CS Login:       navneet
Course:         CS 368, Fall 2014
Assignment:     Programming Assignment 3
*******************************************************************************/

#include <iostream>
#include <iomanip>
#include "SortedList.h"

using namespace std;


/*
 * Constructor for the class to initialize the list.
 */
SortedList::SortedList() {
    Book* book = NULL;
    Listnode* next = NULL;
    Listnode* head = NULL;
    Listnode* tail = NULL;
}

/*
 * Adds a book to the list.
 * 
 * @param *b pointer to the book to be added
 * @return true if the book was added successfully. False otherwise.
 */
bool SortedList::addBook(Book *b) {
    //Check if the book is in the list
    if (search(b->getID()) != NULL) {
        return false;
    }
    
    //Create a new node for the book
    Listnode* temp = new Listnode;
    temp->book = b;
    temp->next = NULL;
    
    //Check if the list is empty
    if (head == NULL) {
        head = temp;
    }
    else {
        tail->next = temp;
    }
    
    tail = temp;
    return true;
}

/*
 * Searches the list for a book
 * 
 * @param bookID ID of the book to search
 * @return pointer to the book being searched for.
 */
Book* SortedList::search(int bookID) {
    //Check if the list is empty
    if (head == NULL) {
        return NULL;
    }
    
    Listnode* temp = head;
    Book* b;
    
    //Run through the list to see if book ID matches any IDs in the list
    while (temp != NULL) {
        b = temp->book;
    
        if (b->getID() == bookID) {
            return b;
        }
        
        temp = temp->next;
    }
    
    return NULL;
    
}

/*
 * Prints the books published in the given year.
 * 
 * @param year publication year of the books to be printed
 * @return true if books were found that were published in the year.
 * False otherwise.
 */
bool SortedList::printBooksByYear(int year) {
    Listnode* temp = head;
    Book* b;
    int booksFound = 0;
    
    //Run through the list to see if there were books published in the given year
    while (temp != NULL) {
        b = temp->book;
    
        if (b->getYear() == year) {
            b->print();
            booksFound++;
        }
        
        temp = temp->next;
    }
    
    //Check if any books were published in the given year
    if (booksFound > 0) {
        return true;
    }
    
    return false;
}

/*
 * Update the book with the given ID.
 * 
 * @param bookID ID of the book to be updated
 * @param year Updated publication year
 * @param rating Updated book rating
 * @return true if book was successfully updated. False otherwise.
 */
bool SortedList::updateBook(int ID, int year, double rating) {
    Book* b = search(ID);
    
    //Update the book
    if (b != NULL) {
        b->updateBook(ID, year, rating);
        
        return true;
    }
    
    return false;
}

/*
 * Calulate the average rating of all the books in the list.
 *
 * @return average rating of all the books in the list
 */
double SortedList::calculateAverageRating() {
    //Check if the list is empty
    if (head == NULL) {
        return 0;
    }
    
    Listnode* temp = head;
    Book* b;
    double totalRating = 0;
    int numBooks = 0;
    double avgRating;
    
    //Add the ratings of all the books
    while (temp != NULL) {
        b = temp->book;
    
        totalRating = totalRating + (b->getRating());
        numBooks++;
        
        temp = temp->next;
    }
    
    //Calculate average rating
    avgRating = totalRating/numBooks;
    
    return avgRating;
}

/*
 * Remove a book from the list.
 * 
 * @param bookID ID of the book to remove
 * @return pointer to the book that was removed from the list
 */
Book* SortedList::removeBook(int bookID) {
    //Check if the list is empty
    if (head == NULL) {
        return NULL;
    }
    
    Listnode* temp = head;
    Listnode* temp1 = head;
    Book* b = search(bookID);
    
    //Check if the book exists
    if (b == NULL) {
        return NULL;
    }
    
    //Check if the book is the head of the list
    if(head->book == b) {
        if(head->next == NULL) {
           head = NULL;
           return b;
        }
            
        //Set head to the next node
        head->book = head->next->book;
        head = head->next;
        head->next = head->next->next;
 
        return b;
    }
    
    //Book is not the head of the list
    while (temp != NULL) {
        b = temp->book;
        
        //Remove node from list
        if (b->getID() == bookID) {
            temp1->next = temp->next;
            return b;
        }
        
        temp1 = temp;
        temp = temp->next;
    }
    
    return NULL;
}

/*
 * Print the books in the list.
 */
void SortedList::print() const {
    Listnode* temp = head;
    Book* b;
    
    //Run through the list and print the contents of each book
    while (temp != NULL) {
        b = temp->book;
        
        b->print();
        
        temp = temp->next;
    }
}

/*
 * Traverses the linked list, returning each node to free storage.
 * 
 * @param L a pointer to a listnode
 */
void SortedList::freeList (Listnode* L) {
    Listnode* temp;
    
    //Run through all the nodes and delete each node
    while (L != NULL) {
        temp = L;
        L = L->next;
        
        delete temp;
    }
    
    head = NULL;
    tail = NULL;
}

/*
 * Returns a pointer to the first node of a copy of the original linked list.
 * 
 * @param L a pointer to a listnode
 */
void SortedList::copyList (Listnode* L) {
    //Run through all the books and and copy each one into the new list
    while (L != NULL) {
        addBook(L->book);
        L = L->next;
    }
}

/*
 * Destructor for a sorted list.
 */
SortedList::~SortedList() {
    cout << "Destructor for sorted list." << endl;
    
    freeList(head);
}

/*
 * Copy constructor for a sorted list.
 */
SortedList::SortedList(const SortedList& original) : head(NULL), tail (NULL) {
    cout << "Copy constructor for sorted list." << endl;
    
    copyList(original.head);
}

/*
 * Copy assignment operator for a sorted list.
 *
 * @param original original list to copy.
 */
SortedList& SortedList::operator= (const SortedList& original) {
    cout << "Copy assignment operator for sorted list." << endl;
    
    //Check if the current list is the same list passed through the function parameter
    if (this != &original) {
        freeList(original.head);
    
        Listnode* current = original.head;
    
        //Run through all the books and and copy each one into the new list
        while (current != NULL) {
            addBook(current->book);
            current = current->next;
        }
    }
    
    return *this;
}

