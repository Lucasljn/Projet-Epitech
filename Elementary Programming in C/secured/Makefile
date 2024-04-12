##
## EPITECH PROJECT, 2023
## projects
## File description:
## Makefile
##

SRC	=	my_printf.c	\
		put_all.c 	\
		print_all.c	\
		secured.c	\
		secured2.c

OBJ =	$(SRC:.c=.o)

NAME	=	libhashtable.a

all:	$(NAME)

$(NAME): 	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
