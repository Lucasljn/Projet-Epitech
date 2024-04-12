##
## EPITECH PROJECT, 2023
## projects
## File description:
## Makefile
##

SRC	=	my_strcmp.c		\
		my_strcat.c	\
		sokoban.c	\
		mouvement.c	\
		openfile.c \
		poseandswitch.c	\
		manage_o.c	\
		winlose.c	\
		error.c	\
		my_putstr.c

NAME = my_sokoban

all: $(NAME)

$(NAME):	$(OBJ)
			gcc -g3 -o $(NAME) $(SRC) -lncurses

clean:
			rm -f $(OBJ)

fclean:
			rm -f $(NAME)

re:			fclean all
