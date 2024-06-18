##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## @epitech.eu
##

SRC		=	main.c \
			menger.c

CFLAGS	=	-std=gnu11 -Wall -Wextra

INCLUDE =	-o

LIB		=	-g -lm

NAME	=	menger

all:	$(NAME)

$(NAME):
	gcc $(SRC) $(CFLAGS) $(INCLUDE) $(NAME) $(LIB)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re