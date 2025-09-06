#include <iostream>
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
  void contactSet()
  {
    do {
    std::cout << "Please, enter First Name : ";
    std::getline(std::cin,firstName);
    if(!isValidString(firstName) || firstName.empty())
    {
      std::cout << "❌First Name : " << firstName;
      std::cout << " is not valid❌" << std::endl;
    }
    }while(!isValidString(firstName) || firstName.empty());

    do {
    std::cout << "Please, enter Last Name : ";
    std::getline(std::cin,lastName);
    if(!isValidString(lastName) || lastName.empty())
    {
      std::cout << "❌Last Name : " << lastName;
      std::cout << " is not valid❌" << std::endl;
    }
    }while(!isValidString(lastName) || lastName.empty());

    do {
    std::cout << "Please, enter Phone Number : ";
    std::getline(std::cin,phoneNumber);
    if(!isValidPhone(phoneNumber) || phoneNumber.empty())
    {
      std::cout << "❌Number : " << phoneNumber;
      std::cout << " is not valid❌" << std::endl;
    }
    }while(!isValidPhone(phoneNumber) || phoneNumber.empty());

    return;
  }

  // Print le PhoneBook
  void contactDisplay()const
  {
    std::cout << firstName << " " << lastName << " : " << phoneNumber << std::endl;
    return;
  } 
};
#endif
