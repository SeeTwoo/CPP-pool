CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_FILES = megaphone.cpp

NAME = megaphone

all:  $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -o $@ $(SRC_FILES)

clean:

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
