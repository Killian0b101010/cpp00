NAME = PhoneBook
SRC = phonebook.cpp
OBJ = $(SRC:.cpp=.o)
CC = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
RM	= rm -rf

all : $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAG) -o $@ $^
%.o: %.cpp 
		$(CC) $(CFLAG) -c $< -o $@
clean : 
		$(RM) $(OBJ)
fclean : clean 
		$(RM) $(NAME)
re: fclean all;
