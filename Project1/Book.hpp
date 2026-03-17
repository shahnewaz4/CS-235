
#ifndef BOOK_HPP_
#define BOOK_HPP_

#include <iostream>


class Book {

private:

    std::string title_; // private variable title
    std::string author_; // private variable author
    int page_count_; // private variable page count
    bool is_digital_ = false; // private variable for if book is available in digital default initialized to false
    
public:
/*
    Default constructor.
    Default-initializes all private members. Booleans are default-initialized to False.
*/
    Book() = default; //default constructer
/*
    Parameterized constructor.
    @param      : The title of the book (a string)
    @param      : The author of the book (a string)
    @param      : The number of pages in the book (a positive int)
    @param      : A flag indicating whether the book is in digital form (a Boolean),
                with default value False
    @post       : The private members are set to the values of the corresponding parameters.
*/
    Book(const std::string title, const std::string author, const int page_count, const bool is_digital = false); // initializes all private member functions
    
    // accessors and mutators
/*
   @param  : the title of the Book
   @post   : sets the Book's title to the value of the parameter
*/
    void setTitle(const std::string title);
/*
    @param  : the name of the author of the Book
    @post   : sets the Book's author to the value of the parameter
*/
    void setAuthor(const std::string author); 
/*
    @param  : a positive integer page count
    @pre    : page count > 0 - books cannot have a negative number of pages
    @post   : sets the page count to the value of the parameter
*/
    void setPageCount(const int page_count); 
/*
   @post   : sets the digital flag to true
*/
    void setDigital(); 
/*
    @return : the title of the Book
*/
    std::string getTitle() const; 
/*
    @return : the author of the Book
*/
    std::string getAuthor() const; 
/*
    @return : the page count
*/
    int getPageCount() const; 
/*
    @return true if the book is available in digital form, false otherwise
*/
    bool isDigital() const; 

};
#endif