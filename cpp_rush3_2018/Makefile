##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## @epitech.eu
##

SRC		=	main.cpp \
			Engine.cpp \
			EngineDisplay.cpp \
			EngineInfos.cpp \
			EngineLineDisplay.cpp \
			EngineNetwork.cpp \
			EngineTextDisplay.cpp \
			EngineUser.cpp

CFLAGS	=	-Wall -Wextra -Werror -lncurses -lsfml-graphics -lsfml-window -lsfml-system

OBJS	=	$(SRC:.cpp=.o)

NAME	=	MyGKrellm

all:	$(NAME)

$(NAME): $(OBJS)
	g++ -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
