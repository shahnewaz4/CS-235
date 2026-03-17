
/*
    Author: Shahnewaz Azad
    Date: 2/24/2023
    This is the implementation of the class Novel. Defines functions getGenre, setGenre, getCharacterList,
    getCharacterListString, addCharacter, hasFilmAdaptation, setFilmAdaptation, getAverageRating, createReview, 
    calculateAverageRating, createReview, addReview

*/

#include "Book.hpp"
#include <vector>

struct review {
    double score_;
    std::string rating_;
};

class Novel : public Book{
    private:
    std::string genre_;
    std::vector<std::string> characters_;
    std::vector<review> reviews_;
    double avg_rate_;
    bool film_adapt_;

    public:
/**
  Default constructor.
  Default-initializes all private members.
*/
    Novel();

/**
  Parameterized constructor.
  @param     : The title of the book (a string)
  @param     : The author of the book (a string)
  @param     : The number of pages in the book (a positive integer)
  @param     : The genre of the novel (a string)
  @param     : A flag indicating whether the book is in digital form
                with DEFAULT VALUE False (a Boolean)
  @param     : A flag indicating whether there is a film adaptation
                for this novel with DEFAULT VALUE False (a Boolean)
*/
    Novel(std::string title, std::string author, int page_count, std::string genre, bool is_digital = false, bool film_adapt = false);

/**
  @return   : the value of the genre private member
**/
    std::string getGenre() const;

/**
  @param  : a reference to string indicating the genre of the book
  @post   : sets genre_ private member to the
              value of the parameter
**/
    void setGenre(const std::string genre);

/**
  @return   : the vector containing the list of characters for this novel
**/
    std::vector<std::string> getCharacterList() const;

/**
  @return    : a string of all the characters in the
              character_list_ private member, concatenated
              and separated by a space " " .
              For example: "character1 character2 character3"
**/
    std::string getCharacterListString() const;

/**
  @param  : a reference to string indicating a character
  @post   : inserts the character into the character_list_ vector
**/
    void addCharacter(const std::string character);

/**
  @return   : the value of the film_adaptation_ private member
**/
    bool hasFilmAdaptation() const;

/**
  @post   : sets has_film_adaptation_ private member to true
**/
    void setFilmAdaptation();

/**
  @param    : a reference to floating point number (double) indicating
              the score of the  review
  @param    : a reference to string indicating the rating of the review
  @return   : creates and returns a review data type with
              score and rating as indicated by the parameters
*/
    review createReview(const double score, const std::string rating);

/**
  @param  : a reference to review object
  @post   : inserts the review argument into the reviews_ vector
**/
    void addReview(const review object);

/**
  @return   : the value of the average rating private member
**/
    double getAverageRating() const;

/**
  @post   : retrieves all scores from the reviews_ vector and
            computes the average to set value of the average_rating_
            private member
**/
    void calculateAverageRating();


};