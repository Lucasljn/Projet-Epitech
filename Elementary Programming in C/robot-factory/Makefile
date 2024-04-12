##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC	=	main.c		\
		main2.c		\
		my_printf.c \
		put_all.c	\
		print_all.c	\
		open_file.c \
		op.c 		\
		my_array_strtok.c	\
		label.c 	\
		header.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	asm

CFLAGS	=	-g3

all:		$(NAME)

$(NAME): 	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
