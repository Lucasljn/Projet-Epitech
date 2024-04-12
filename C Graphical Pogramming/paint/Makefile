##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC	=	paint.c				\
		init_tools.c		\
		init_button.c		\
		init_button2.c 		\
		draw.c				\
		action_button.c		\
		init_color.c		\
		init_color2.c		\
		selected_color.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_paint

CSFML =		-lcsfml-graphics -lcsfml-system -lcsfml-window -lm

all:		$(NAME)

$(NAME): 	$(OBJ)
			gcc -g3 $(SRC) -o $(NAME) -I ./include/ $(CSFML)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all
