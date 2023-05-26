##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compileur
##

CC = g++
CFLAGS = -I include
CPPFLAGS = -Wall -Wextra
SFMLFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

SRC = main.cpp \
    $(wildcard src/*.cpp)

OBJ = $(SRC:.cpp=.o)
NAME = JAM_3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CPPFLAGS) $(CFLAGS) $(SFMLFLAGS) -g3

clean:
	rm -f $(NAME) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
