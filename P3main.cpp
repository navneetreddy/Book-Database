/*******************************************************************************
Author:         Navneet Reddy
CS Login:       navneet
Course:         CS 368, Fall 2014
Assignment:     Programming Assignment 3
*******************************************************************************/

#include <iostream>
#include "Book.h"
#include "SortedList.h"

using namespace std;

int main() {
	
	//Test Book destructor, copy constructor, copy assignment operator
	Book bk1 = Book(12345, "cs.", 2010, 2.13);
	cout << "Book1" << endl;
    	bk1.print();
	
	//Copy constructor
	Book bk2(bk1);

	//Test
	if (bk1.getID() != bk2.getID() || bk1.getYear() != bk2.getYear()
	    || bk1.getRating() != bk2.getRating())
		cout << "error with Book copy constructor" << endl;
	cout << "Book2 after copy constructor" << endl;
    	bk2.print() ;   

	Book bk3 = Book(34563);
	bk3.print() ;
    	
	//Copy assignment
	bk3 = bk2;

	//test
	if (bk3.getID() != bk2.getID() || bk3.getYear() != bk2.getYear()
	    || bk3.getRating() != bk2.getRating())
		cout << "error with Book copy assignment operator " << endl;
	cout << "Book3 operator=" << endl;
	bk3.print();
	
    return 0;
}
