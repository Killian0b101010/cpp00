/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiteixei <kiteixei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 15:02:14 by kiteixei          #+#    #+#             */
/*   Updated: 2025/10/11 15:02:16 by kiteixei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

bool is_lowercase(char c)
{
  return(c >= 'a' && c <= 'z');
}

int main(int argc, char **argv)
{
  if(argc == 1)
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
  if (argc > 1)
  {
    for(int i = 1; i < argc; i++)
    {
      std::string s(argv[i]);
      for(unsigned long j = 0; j < s.length();j++)
      {
        if(is_lowercase(s[j]))
          s[j] = std::toupper(s[j]);
      }
      std::cout << s;
    }
    std::cout << std::endl;
  }
 return(0);
}
