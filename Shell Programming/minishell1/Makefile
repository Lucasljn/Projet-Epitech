##
## EPITECH PROJECT, 2023
## B2
## File description:
## Makefile
##

SRC	=	minishell1.c	\
		src/my_pustr.c	\
		src/my_str_to_word_array.c	\
		src/my_strcmp.c	\
		src/my_strcat.c	\
		setenv.c	\
		errorandother.c	\
		petitefonction.c	\
		error.c	\
		my_printf/my_printf.c	\
		my_printf/print_all.c	\
		my_printf/put_all.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3

NAME	=	mysh

all:	$(NAME)

$(NAME):	$(OBJ)
			gcc -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean:	clean
		rm -f $(NAME)

re:		fclean all
