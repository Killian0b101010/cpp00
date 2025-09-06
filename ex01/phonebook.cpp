#include "Phonebook.class.hpp"

Contact::Contact(void)
{
  this->firstName = "";
  this->lastName = "";
  this->phoneNumber = "";
  std::cout << "Constructor called" << std::endl;
  return;
}

Contact::~Contact(void){
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

int main(void)
{
  Contact instance;
  instance.contactSet();
  instance.contactDisplay();
  return(0);
}
