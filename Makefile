##
## EPITECH PROJECT, 2018
## makefile
## File description:
## to make
##

SRC	=	src/main.c \
		src/functions.c \
		src/minishell.c \
		src/minishell2.c \
		src/minishell3.c

OBJ     =       $(SRC:.c=.o)

CC	=	gcc

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
	 $(CC) $(OBJ) -o $(NAME)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

