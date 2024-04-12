##
## EPITECH PROJECT, 2024
## amazed
## File description:
## amazed
##

SRC = 	src/algo_find.c 		\
		src/basic_function.c 	\
		src/parsing_edge.c 		\
		src/main.c 				\
		src/robustness.c 		\
		src/my_printf.c 		\
		src/my_array_strtok.c 	\
		src/sort_path.c 		\
		src/mouvement.c 		\

NAME = amazed

OBJ = $(SRC:.c=.o)

CFLAGS = -g3

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
