##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## @epitech.eu
##

SRC		=	string.c

NAME	=	libstring.a

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-std=gnu11 -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJ)
	ar rc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re