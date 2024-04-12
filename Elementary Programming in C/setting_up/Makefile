##
## EPITECH PROJECT, 2023
## projects
## File description:
## Makefile
##

SRC	=	mini_printf.c	\
		findmaxsquare.c \
		findmaxsquare2.c	\
		settingup.c	\
		my_strcmp.c		\
		put_miniprintf.c \
		my_strcat.c	\
		error.c	\
		generatormap.c	\
		my_getnbr.c	\
		my_str_isnum.c

NAME = setting_up

all: $(NAME)

$(NAME):	$(OBJ)
			gcc -g3 -o $(NAME) $(SRC)

clean:
			rm -f $(OBJ)

fclean:
			rm -f $(NAME)

re:			fclean all
