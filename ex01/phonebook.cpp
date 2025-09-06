#include "Phonebook.class.hpp"

Contact::Contact(void)
{
  this -> firstName = "";
  this -> lastName = "";
  this -> phoneNumber = "";
  std::cout << "Constructor called" << std::endl;
  return;
}

Contact::~Contact(void)
{
  std::cout << "Destructor called" << std::endl;
  return;
}

static bool isChar(char c)
{
  return std::isalpha(c);
}

bool Contact::isValidString(const std:: string &name)
{
  return std::all_of(name.begin(),name.end(),isChar);
}

static bool isDigitChar(char c)
{   
  return std::isdigit(c);
}

bool Contact::isValidPhone(const std:: string &phoneNumber)
{
  return std::all_of(phoneNumber.begin(), phoneNumber.end(), isDigitChar);
}

void Contact::contactSet()
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

void Contact::contactDisplay()const
{
    std::cout << firstName << " " << lastName << " : " << phoneNumber << std::endl;
    return;
}

int main(void)
{
  Contact instance;
  instance.contactSet();
  instance.contactDisplay();
  return(0);
}
