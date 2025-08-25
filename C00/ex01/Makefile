NAME = phoneBook
CC = c++ -Wall -Wextra -Werror --std=c++98 -Iincludes
CCDEBUG = $(CC) -g3

SRC_DIR = src
SRC_FILES = main.cpp

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = obj
OBJ_FILES = $(SRC_FILES:.cpp=.o)

OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p obj
	$(CC) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -o $@ $^

all: $(NAME)

debug: fclean
	$(MAKE) CC="$(CCDEBUG)" all

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
