
/*
    Author: Shahnewaz Azad
    Date: 2/24/2023
    This is the implementation of the class Novel. Defines functions getGenre, setGenre, getCharacterList,
    getCharacterListString, addCharacter, hasFilmAdaptation, setFilmAdaptation, getAverageRating, createReview, 
    calculateAverageRating, createReview, addReview

*/


#include "Novel.hpp"

/**
  Default constructor.
  Default-initializes all private members.
*/
Novel::Novel():Book(){
    bool film_adapt_ = false;
    std::string genre = "";

}

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
Novel::Novel(std::string title, std::string author, int page_count, std::string genre, bool is_digital, bool film_adapt): Book(title, author, page_count, is_digital){
    genre_ = genre;
    film_adapt_ = film_adapt;
}

/**
  @return   : the value of the genre private member
**/
std::string Novel::getGenre() const{
    return genre_;
}

/**
  @param  : a reference to string indicating the genre of the book
  @post   : sets genre_ private member to the
              value of the parameter
**/
void Novel::setGenre(const std::string genre){
    genre_ = genre;
}

/**
  @return   : the vector containing the list of characters for this novel
**/
std::vector<std::string> Novel::getCharacterList() const{
    return characters_;
}

/**
  @return    : a string of all the characters in the
              character_list_ private member, concatenated
              and separated by a space " " .
              For example: "character1 character2 character3"
**/
std::string Novel::getCharacterListString() const{
    std::string strcharacter = "";
    for(int i = 0; i < characters_.size(); i++){
        strcharacter = strcharacter + characters_[i] + " ";
    }
    std::string strcharacters;
    strcharacters = strcharacter.substr(0, strcharacter.length()-1);
    return strcharacters;
}

/**
  @param  : a reference to string indicating a character
  @post   : inserts the character into the character_list_ vector
**/
void Novel::addCharacter(const std::string character){
    characters_.push_back(character);
}

/**
  @return   : the value of the film_adaptation_ private member
**/
bool Novel::hasFilmAdaptation() const{
    return film_adapt_;
}

/**
  @post   : sets has_film_adaptation_ private member to true
**/
void Novel::setFilmAdaptation(){
    film_adapt_ = true;
}

/**
  @return   : the value of the average rating private member
**/
double Novel::getAverageRating() const{
    return avg_rate_;
}

/**
  @param    : a reference to floating point number (double) indicating
              the score of the  review
  @param    : a reference to string indicating the rating of the review
  @return   : creates and returns a review data type with
              score and rating as indicated by the parameters
*/
review Novel::createReview(const double score, const std::string rating){
    review revewstru;
    revewstru.score_ = score;
    revewstru.rating_ = rating;
    calculateAverageRating();
    return revewstru;
}

/**
  @post   : retrieves all scores from the reviews_ vector and
            computes the average to set value of the average_rating_
            private member
**/
void Novel::calculateAverageRating(){
    double sum = 0;
    for(int i = 0; i < reviews_.size(); i++){
        sum = sum + reviews_[i].score_;
    }
    sum = sum/(reviews_.size());
    avg_rate_ = sum;
}

/**
  @param  : a reference to review object
  @post   : inserts the review argument into the reviews_ vector
**/
void Novel::addReview(review object){
     reviews_.push_back(object);
}