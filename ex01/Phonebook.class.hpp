#include <iostream>
#include <string>
#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

// Class Contact
class Contact 
{
  private:
  std::string firstName;
  std::string lastName;
  std::string phoneNumber;
  public:
  // Constructeur
  Contact();
  // Destructeur
  ~Contact();
  // Parsing
  bool isValidPhone(const std::string& phoneNumber);
  bool isValidString(const std::string& name);
  //Contact 
  void contactSet();
  // Print le PhoneBook
  void contactDisplay()const;
};
#endif
