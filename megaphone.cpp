#include <iostream>
#include <cctype>

bool is_lowercase(char c)
{
  return(c >= 'a' && c <= 'z');
}

int main(int argc, char **argv)
{
  if (argc > 1)
  {
    for(int i = 1; i < argc; i++)
    {
      std::string s(argv[i]);
      for(int j = 0; j < s.length();j++)
      {
        if(is_lowercase(s[j]))
          s[j] = std::toupper(s[j]);
      }
      std::cout << s << std::endl;
    }
  }
  return(0);
}
