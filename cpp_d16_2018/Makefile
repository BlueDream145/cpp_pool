##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## @epitech.eu
##

SRC		=	main.cpp

CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRC:.cpp=.o)

NAME	=	my_cat

all:	$(NAME)

$(NAME): $(OBJS)
	g++ -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re