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
		src/component/Nand.cpp		\
		src/component/Output.cpp	\
		src/component/Input.cpp		\
		src/factory/ComponentFactory.cpp	\
		src/inheritence/AComponent.cpp

INCLUDE =	src/app/			\
			src/component/		\
			src/factory/		\
			src/inheritence		\
			src/parsing


NAME	=	nanotekspice

CPPFLAGS = $(INCLUDE:%=-I%) -std=c++20 -Wall -Wextra -Werror

CPPFLAGSTEST = -lcriterion --coverage

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.gcno
	rm -f *.gcda

re: fclean all

tests_run:
	g++ -o nanotekspice \
	tests/unit_tests.cpp $(CPPFLAGSTEST)
	-./nanotekspice

.PHONY: all clean fclean re