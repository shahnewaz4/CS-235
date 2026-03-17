
/*
    Author: Shahnewaz Azad
    Date: 2/24/2023
    This is the implementation of the class Manual. Defines functions setDevice, getDevice, setWebsite, getWebsite,
    setVisualAid, hasVisualAid, hasWebsite

*/

#include "Manual.hpp"

/**
  Default constructor.
  Default-initializes all private members.
*/
Manual::Manual(){
    std::string website_ = "";
	std::string device_name_ = "";
	bool has_visual_ = false;
	bool has_website_ = false;
}

/**
  Parameterized constructor.
  @param     : The title of the book (a string)
  @param     : The author of the book (a string)
  @param     : The number of pages in the book (a positive integer)
  @param     : The name of the device (a string)
  @param     : A flag indicating whether the book is in digital form
                with DEFAULT VALUE False (a Boolean)
  @param     : The URL that is in the format
                'https://www.something.something'
                or 'http://www.something.something'
                with the last 'something' being at least 2 characters
                with DEFAULT VALUE empty string (a string)
  @param     : A Boolean indicating the presence of a visual aid
                with DEFAULT VALUE False
  @post      : The private members are set to the values of the
                corresponding parameters.
                If a URL is provided, the website flag is set to True.
                If the URL is ill-formatted, the website is set to
                empty string and the website flag is set to False.
*/
Manual::Manual(std::string title, std::string author, int page_count, std::string device_name, bool is_digital, std::string website, bool has_visual):Book(title, author, page_count, is_digital){
    device_name_ = device_name;
    std::regex format("https?://www\\..+\\..{2,}");
    if (std::regex_match(website, format)){
        website_ = website;
        has_website_ = true;
    }
    else{
        website_ = "";
        has_website_ = false;
    }

    has_visual_ = has_visual;
}

/**
  @param  : a reference to a string representing the device
  @post   : sets the private member variable to the value of the parameter
**/
void Manual::setDevice(const std::string devicename){
    device_name_ = devicename;
}

/**
  @return  : the variable indicating the device the manual is for
**/
std::string Manual::getDevice() const{
    return device_name_;
}

/**
  @param   : a reference to a website link (string) that is in the format
             'https://www.something.something'
             or 'http://www.something.something'
             with the last 'something' being at least 2 characters
  @return  : has_website_ flag (a boolean)
  @post    : If the link is not correctly formatted,
             store "Broken Link" in the link member variable (see <regex>)
             and either way set the has website flag to True
**/
bool Manual::setWebsite(const std::string website){
    std::regex format("https?://www\\..+\\..{2,}");
    if (std::regex_match(website, format))
    {
        website_ = website;
        has_website_ = true;
    }
    else{
        website_ = "Broken Link";
        has_website_ = true;
    }
    
    return has_website_;
}

/**
  @return  : the url for the website
**/
std::string Manual::getWebsite() const{
    return website_;
}

/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating the presence
            of a visual aid to the value of the parameter
**/
void Manual::setVisualAid(const bool vis){
    has_visual_ = vis;
}

/**
  @return  : the visual aid flag
**/
bool Manual::hasVisualAid() const{
    return has_visual_;
}

/**
  @return  : the has website flag
**/
bool Manual::hasWebsite() const{
    return has_website_;
}