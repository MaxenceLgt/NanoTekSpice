##
## EPITECH PROJECT, 2024
## B-PDG-300-REN-3-1-PDGD04am-maxence.largeot
## File description:
## Makefile
##

SRC	=	src/main.cpp				\
		src/app/Circuit.cpp			\
		src/component/BluePrint.cpp	\
		src/component/Clock.cpp		\
		src/component/False.cpp		\
		src/component/True.cpp		\
		src/component/IO.cpp		\
		src/component/Nand.cpp		\
		src/factory/ComponentFactory.cpp	\
		src/inheritence/AComponent.cpp

INCLUDE =	src/app/			\
			src/component/		\
			src/factory/		\
			src/inheritence		\
			src/parsing			\


NAME	=	nano

CPPFLAGS = $(INCLUDE:%=-I%) -std=c++20 -Wall -Wextra -Werror

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re