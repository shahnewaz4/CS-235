
/*
    Author: Shahnewaz Azad
    Date: 2/24/2023
    This is the implementation of the class Textbook. Defines functions setSubject, getSubject, setGradeLevel,
    setReviewQuestions, checkReviewQuestions

*/

#include "Textbook.hpp"

/**
  Default constructor.
  Default-initializes all private members.
*/
Textbook::Textbook():Book(){
    bool review_questions_ = false;
    grade_level gradelevel_ = NONE;
}

/**
  Parameterized constructor.
  @param     : The title of the book (a string)
  @param     : The author of the book (a string)
  @param     : The number of pages in the book (a positive integer)
  @param     : The subject of the book (a string)
  @param     : A flag indicating whether the book is in digital form
                with DEFAULT VALUE False (a Boolean)
  @param     : The grade level of the book (of type grade_level)
                with DEFAULT VALUE NONE
  @param     : A boolean to indicate whether the book has review
                questions with DEFAULT VALUE False
  @post      : The private members are set to the values of the
                corresponding parameters.
*/
Textbook::Textbook(std::string title, std::string author, int page_count, std::string subject, bool is_digital, grade_level grade, bool review_questions): Book(title, author, page_count, is_digital){

    subject_ = subject;
    gradelevel_ = grade;
    review_questions_ = review_questions;
}

/**
  @return  : the subject of the textbook
**/
std::string Textbook::getSubject() const{
    return subject_;
}

/**
  @return  : a string representative of the grade_level
            (e.g. if the grade level is JUNIOR_HIGH,
            it returns "JUNIOR HIGH")
**/
std::string Textbook::getGradeLevel() const{
    std::string g;
    switch (Textbook::gradelevel_) {
        case NONE   : g = "NONE"; break;
        case ELEMENTARY   : g = "ELEMENTARY"; break;
        case JUNIOR_HIGH   : g = "JUNIOR HIGH"; break;
        case HIGH_SCHOOL    : g = "HIGH SCHOOL";  break;
        case COLLEGE  : g = "COLLEGE"; break;
    }    
    return g;

}

/**
  @param  : a reference to a string representing the the subject of the book
  @post   : sets the private member variable to the value of the parameter
**/
void Textbook::setSubject(const std::string subject){
    subject_ = subject;
}

/**
  @param  : a reference to a grade_level
  @post   : sets the private member variable to the value of the parameter
**/
void Textbook::setGradeLevel(const grade_level grade){
    gradelevel_ = grade;
}

/**
  @post   : sets the review question flag to True
**/
void Textbook::setReviewQuestions(){
    review_questions_ = true;
}

/**
  @return  : the flag indicating if the texbook has review questions
**/
bool Textbook::checkReviewQuestions() const{
    return review_questions_;
}