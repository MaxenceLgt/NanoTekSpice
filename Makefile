##
## EPITECH PROJECT, 2024
## Nano
## File description:
## Makefile
##

CC 			= 	g++

NAME		=	nanotekspice

SRC			+= main.cpp
SRC			+= Circuit.cpp
SRC			+= ComponentFactory.cpp
SRC			+= AComponent.cpp
SRC			+= BluePrint.cpp
SRC			+= Clock.cpp
SRC 		+= False.cpp
SRC			+= IO.cpp
SRC			+= Nand.cpp
SRC			+= True.cpp

# for add a new path : VPATH += src/new_path/
VPATH		+=	src/
VPATH		+=	src/app/
VPATH		+=	src/component/
VPATH		+=	src/config/
VPATH		+=	src/factory/
VPATH		+=	src/inheritence/
VPATH		+=	src/parsing/

vpath %.cpp $(VPATH)

BUILD_DIR	=	build

OBJ			=	$(SRC:%.cpp=$(BUILD_DIR)/%.o)

IFLAGS		=	-I ./src -I src/app/ -I src/component/ -I src/config/ -I src/factory/ -I src/inheritence/ -I src/parsing/
CFLAGS		=	-Wall -Wextra -Werror $(IFLAGS) -g
LDFLAGS		=
CFLAGSTEST += -lcriterion --coverage

TMP_FILES	=	*.gcno					\
    			*.gcda					\
    			vgcore.*				\
    			*.log					\
    			temp.txt				\
    			-r $(BUILD_DIR)			\
    			$(OBJ)

# ------ DISPLAY -------- #

ECHO 		= echo
C_RESET 	= \033[00m
C_RED		= \e[31m
C_GREEN 	= \e[32m
C_YELLOW 	= \e[33m
C_BLUE		= \e[34m
C_PINK		= \e[35m
C_FULL_RED	= \e[41m
# ----------------------- #

all:		$(NAME)

%:
	@ $(ECHO) "$(C_RED)|==========> RULE NOT FOUND. <==========|$(C_RESET)"

%.cpp:
	@ $(ECHO) "$(C_RED)[KO] -> $@$(C_RESET)"

$(BUILD_DIR)/%.o: %.cpp
	@ mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@
	@ $(ECHO) "$(C_GREEN)[OK] -> $<$(C_RESET)"

$(NAME):	$(OBJ)
	@ $(CC) -o $@ $? $(LDFLAGS)
	@ $(ECHO) "$(C_PINK)|==========> $(NAME) compiled. <==========|$(C_RESET)"

clean:
	@ $(RM) $(TMP_FILES)

fclean:		clean
	@ $(RM) $(NAME)

re:		fclean all

tests_run:
	$(CC) -o nanotekspice \
	tests/unit_tests.cpp -I include/ $(LDFLAGS) $(CFLAGS) $(CFLAGSTEST)
	-./nanotekspice

debug: CFLAGS += -g
debug: CFLAGS += -Werror
debug: all

.PHONY: all re clean fclean  debug