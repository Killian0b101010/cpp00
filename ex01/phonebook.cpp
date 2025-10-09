#include "Phonebook.class.hpp"

Contact::Contact(void)
{
  this->firstName = "";
  this->lastName = "";
  this->phoneNumber = "";
  this ->nickName = "";
  this->darkSecret = "";
  std::cout << "Constructor called" << std::endl;
}

Contact::~Contact(void)
{
  std::cout << "Destructor called" << std::endl;
}

static bool isChar(char c) 
{ 
  return std::isalpha(c); 
}

bool Contact::isValidString(const std::string &name)
{
  for (unsigned int i = 0; i < name.length(); i++)
  {
    if (!isChar(name[i]))
      return false;
  }
  return true;
}

static bool isDigitChar(char c) 
{ 
  return std::isdigit(c); 
}

bool Contact::isValidPhone(const std::string &phoneNumber)
{
  for (unsigned int i = 0; i < phoneNumber.length(); i++)
  {
    if (!isDigitChar(phoneNumber[i]))
      return false;
  }
  return true;
}

void Contact::contactSet()
{
  do {
    std::cout << "Please, enter First Name : ";
    std::getline(std::cin, firstName);
    if(std::cin.eof())
    {
      std::cout<<"\nPas de EOF ICI VOYONS !\n";
      exit(1);
    }
    if (!isValidString(firstName) || firstName.empty())
      std::cout << "❌ First Name not valid ❌" << std::endl;
  } while (!isValidString(firstName) || firstName.empty());

  do {
    std::cout << "Please, enter Last Name : ";
    std::getline(std::cin, lastName);
    if(std::cin.eof())
    {
      std::cout<<"\nPas de EOF ICI VOYONS !\n";
      exit(1);
    }
    if (!isValidString(lastName) || lastName.empty())
      std::cout << "❌ Last Name not valid ❌" << std::endl;
  } while (!isValidString(lastName) || lastName.empty());

  do {
    std::cout << "Please, enter Phone Number : ";
    std::getline(std::cin, phoneNumber);
    if(std::cin.eof())
    {
      std::cout<<"\nPas de EOF ICI VOYONS !\n";
      exit(1);
    }
    if (!isValidPhone(phoneNumber) || phoneNumber.empty() ||phoneNumber.length() < 2 || phoneNumber.length() >= 15)
      std::cout << "❌ Phone Number not valid ❌" << std::endl;
  } while (!isValidPhone(phoneNumber) || phoneNumber.empty());
  
  do {
    std::cout << "Please, enter your Nickname : ";
    std::getline(std::cin, nickName);
    if(std::cin.eof())
    {
      std::cout<<"\nPas de EOF ICI VOYONS !\n";
      exit(1);
    }
    if (nickName.empty())
      std::cout << "❌ NickName not valid ❌" << std::endl;
  } while (nickName.empty());

  do {
    std::cout << "Please, enter your dark secret : ";
    std::getline(std::cin, darkSecret);
    if(std::cin.eof())
    {
      std::cout<<"\nPas de EOF ICI VOYONS !\n";
      exit(1);
    }
    if (darkSecret.empty())
      std::cout << "❌ Dark Secret not valid ❌" << std::endl;
  } while (darkSecret.empty());
}

static void truncated(const std::string &str)
{
  if (str.length() > 10)
    std::cout << std::setw(10) << str.substr(0, 9) + ".";
  else
    std::cout << std::setw(10) << str;
}

void Contact::initDisplay() const
{
  std::cout << std::setw(10) << "Index" << "|" << 
  std::setw(10) << "First Name" << "|" << 
  std::setw(10) << "Last Name" << "|" <<
  std::setw(10) << "Nickname" << "|" <<
  std::setw(10) << "Phone Number" << std::endl;
}

void Contact::contactDisplayNotTrunked() const
{
  std::cout << "First Name: " << firstName << std::endl;
  std::cout << "Last Name : " << lastName << std::endl;
  std::cout << "Phone Number: " << phoneNumber << std::endl;
  std::cout << "Nickname: " << nickName << std::endl;
  std::cout << "Dark Secret: " << darkSecret << std::endl;
}

void Contact::contactDisplayTrunked(int index) const
{
  std::cout << std::setw(10) << index << "|";
  truncated(firstName);
  std::cout << "|";
  truncated(lastName);
  std::cout << "|";
  truncated(phoneNumber);
  std::cout << "|";
  truncated(nickName);
  std::cout << std::endl;
}

void PhoneBook::addContact()
{
  contacts[index].contactSet();
  index = (index + 1) % 8;
  if (count < 8)
    count++;
}

void PhoneBook::searchContact() const
{
  if (count == 0) {
    std::cout << "I don't have any contacts" << std::endl;
    return;
  }

  contacts[0].initDisplay();
  for (int i = 0; i < count; i++)
    contacts[i].contactDisplayTrunked(i);

  std::cout << "Enter index please: ";
  std::string number;
  std::getline(std::cin, number);

  if (number.empty())
    return;

  int result = std::atoi(number.c_str());
  if (result >= 0 && result < count)
    contacts[result].contactDisplayNotTrunked();
  else
    std::cout << "❌ Invalid index ❌" << std::endl;
}

int main()
{
  PhoneBook book;
  std::string command;

  while (true)
  {
    std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
    std::getline(std::cin, command);
    if(std::cin.eof())
    {
      std::cout<<"\nPas de EOF ICI VOYONS !\n";
      exit(1);
    }
    if (command == "ADD")
      book.addContact();
    else if (command == "SEARCH")
      book.searchContact();
    else if (command == "EXIT")
      break;
  }
  return 0;
}
