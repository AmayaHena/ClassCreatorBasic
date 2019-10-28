##
## EPITECH PROJECT, 2019
## PROG-ClassCreator
## File description:
## Makefile
##

# ---------------------------------------- #
#               Variables				   #
# ---------------------------------------- #

NAME			=	classCreator

CXX				=	g++

CXXFLAGS		=	-Wall -Wextra

SRC_DIR			=	$(realpath src)

SRC				=	$(SRC_DIR)/main.cpp				\
					$(SRC_DIR)/Core/Core.cpp		\
					$(SRC_DIR)/Parser/Parser.cpp	\
					$(SRC_DIR)/Dir/Dir.cpp			\
					$(SRC_DIR)/File/File.cpp		\
					$(SRC_DIR)/Writer/Writer.cpp

CPPFLAGS	    =

LD_DIRS			=	-I

LDFLAGS	        =

SRCOBJ	        =	$(SRC:.cpp=.o)

# ---------------------------------------- #
#                 RULES					   #
# ---------------------------------------- #

all: $(NAME)

$(NAME): $(SRCOBJ)
	$(CXX) -o $(NAME) $(SRCOBJ) $(CPPFLAGS) $(LDFLAGS)

debug: CFLAGS += -g3
debug: fclean $(NAME)

clean:
	$(RM) $(SRCOBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re debug
