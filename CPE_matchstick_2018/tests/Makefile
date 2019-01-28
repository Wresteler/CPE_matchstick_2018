##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME_T	=	unit_tests

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-I../include/

CFLAGS	+=	-W -Wall -Wextra

DIR	=	../srcs/

SRCS_T	=	$(DIR)basics.c		\
		$(DIR)ai.c		\
		$(DIR)errors.c		\
		$(DIR)free.c		\
		$(DIR)game.c		\
		$(DIR)get_next_line.c	\
		$(DIR)help.c		\
		$(DIR)map.c		\
		$(DIR)matches.c		\
		$(DIR)matchstick.c	\
		$(DIR)utils.c		\
		tests_matchstick_basics.c

OBJS_T	=	$(SRCS_T:.c=.o)

T_FLAGS =	-lcriterion -lgcov --coverage

all:		$(NAME_T)

$(NAME_T):	$(OBJS_T)

clean:
		$(RM) $(OBJS_T)

tests_run:
		$(CC) -o $(NAME_T) $(OBJ_T) -lcriterion -lgcov --coverage

fclean:		clean
		$(RM) $(NAME_T)

re:		fclean all

.PHONY:		all clean fclean re
