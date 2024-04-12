##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile_lib
##

SRC = 	main.c				\
		my_printf.c 		\
		print_all.c			\
		put_all.c			\
		openandmap.c		\
		signal.c 			\
		send_get.c 			\
		player.c			\
		left.c				\
		tab.c				\
		load_file.c			\
		error_map.c			\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_navy

all:		$(NAME)

$(NAME): 	$(OBJ)
			gcc -g3 $(SRC) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
