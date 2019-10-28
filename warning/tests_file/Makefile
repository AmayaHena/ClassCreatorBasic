##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	=	classCreator

CPPFLAGS=	-I inc

SRC_DIR	=	$(realpath src)

SRC	=	$(SRC_DIR)/main.c		\
		$(SRC_DIR)/Core/Core.cpp	\
		$(SRC_DIR)/Parser/Parser.cpp	\
		$(SRC_DIR)/Dir/Dir.cpp		\
		$(SRC_DIR)/File/File.cpp	\
		$(SRC_DIR)/Writer/Writer.cpp

OBJ	=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
	g++ -o $@ $(OBJ)

clean:
	$(RM) $(SRC_DIR)/main.o

fclean:

re:		fclean all

.PHONY:		all fclean clean re
