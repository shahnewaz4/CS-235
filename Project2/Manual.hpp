/*
    Author: Shahnewaz Azad
    Date: 2/24/2023
    This is the implementation of the class Manual. Defines functions setDevice, getDevice, setWebsite, getWebsite,
	setVisualAid, hasVisualAid, hasWebsite

*/


#include "Book.hpp"
#include <regex>


class Manual : public Book{
	private:
	std::string website_;
	std::string device_name_;
	bool has_visual_;
	bool has_website_;

	public:
/**
  Default constructor.
  Default-initializes all private members.
*/
	Manual();

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
	Manual(std::string title, std::string author, int page_count, std::string device_name, bool is_digital = false,  std::string website = "",  bool has_visual = false);

/**
  @param  : a reference to a string representing the device
  @post   : sets the private member variable to the value of the parameter
**/
	void setDevice(const std::string device_name);

/**
  @return  : the variable indicating the device the manual is for
**/
	std::string getDevice() const;

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
	bool setWebsite(const std::string website);

/**
  @return  : the url for the website
**/
	std::string getWebsite() const;

/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating the presence
            of a visual aid to the value of the parameter
**/
	void setVisualAid(const bool vis);

/**
  @return  : the visual aid flag
**/
	bool hasVisualAid() const;

/**
  @return  : the has website flag
**/
	bool hasWebsite() const;

};