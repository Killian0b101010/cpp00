#include <iostream>
#include <string>
#include <iomanip>
#ifndef PHONEBOOK_CLASS_HPP
#define PHONEBOOK_CLASS_HPP

class Contact 
{
  private:
  std::string firstName;
  std::string lastName;
  std::string phoneNumber;
  std::string darkSecret;
  std::string nickName;
  public:
  Contact();
  ~Contact();
  bool isValidPhone(const std::string& phoneNumber);
  bool isValidString(const std::string& name);
  void contactSet();
  void initDisplay()const;
  void contactDisplayTrunked(int index)const;
  void contactDisplayNotTrunked()const;
};

class PhoneBook {
private:
    Contact contacts[8]; 
    int count;           
    int index;
public:
    PhoneBook() : count(0), index(0) {}
    void addContact();
    void searchContact() const; 
}; 
#endif
