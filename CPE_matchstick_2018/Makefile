##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC		=	gcc

RM		=	rm -f

NAME		=	matchstick

COMPILEFLAG	=	-ggdb3 -Wall -Wextra -pedantic -std=c99 -g -g3

INCLUDE		=	-Iinclude/

USELESS_F	=	*~

U_F_SRC		=	srcs/*~

U_F_INC		=	include/*~

U_F_UTEST	=	tests/*~ tests/*.o tests/unit_tests

U_F_VG		=	vgcore.*

DEBUG		=	with debug

UTEST_BIN	=	srcs/*.gcda

UTEST_BIN_U	=	tests/*.gcda

UTEST_OBJ	=	srcs/*.gcno

UTEST_OBJ_U	=	tests/*.gcno

CFLAGS		=	$(COMPILEFLAG) $(INCLUDE)

SRC		=	main.c			\
			srcs/launch.c		\
			srcs/basics.c		\
			srcs/utils.c		\
			srcs/errors_game.c	\
			srcs/matchstick.c	\
			srcs/help.c		\
			srcs/map.c		\
			srcs/free.c		\
			srcs/errors.c		\
			srcs/game.c		\
			srcs/get_next_line.c	\
			srcs/matches.c		\
			srcs/ai.c

OBJ		=	$(SRC:.c=.o)

$(OBJDIR)%.o:		%.c
			@$(CC) $(CFLAGS) -o $@ -c $<
			@if test -s $*.c; then \
			echo -e "\033[01m\033[35m Compiling $(DEBUG)\033[00m\
			\033[36m$(SRCPATH)$*.c\033[032m  [OK]\033[00m";\
			else \
			echo -e "\033[01m\033[33m Compiling $(DEBUG)\033[00m\
			\033[36m$(SRCPATH)$*.c\033[00m\  [Error]"; fi

$(NAME):		$(OBJ)
			@echo -e "\033[01m\033[31mLinking ...\033[00m"
			@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
			@echo -e "\033[01m\033[32mCompilation done => ${NAME}\033[00m"

all:			$(NAME)

clean:
			@$(RM) $(OBJ)
			@$(RM) $(UTEST_BIN)
			@$(RM) $(UTEST_OBJ)
			@$(RM) $(UTEST_BIN_U)
			@$(RM) $(UTEST_OBJ_U)
			@$(RM) $(USELESS_F)
			@$(RM) $(U_F_SRC)
			@$(RM) $(U_F_INC)
			@$(RM) $(U_F_UTEST)
			@$(RM) $(U_F_VG)
			@echo -e "\033[01m\033[31mRemoving objects ...\033[00m"

fclean:			clean
			@$(RM) $(NAME)
			@echo -e "\033[01m\033[31mRemoving binary : {${NAME}} ...\033[00m"

re:			fclean all

.PHONY:			all clean fclean re
