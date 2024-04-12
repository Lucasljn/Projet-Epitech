/*
** EPITECH PROJECT, 2023
** my-ls
** File description:
** my.h
*/

typedef struct pos_s {
    int p_x;
    int p_y;
    int x;
    int y;
    int x_y;
    int x_x;
    char **square;
} pos_t;

typedef struct pos_o_s {
    char **squaredup;
    int x;
    int y;
} pos_o_t;

#ifndef MY_H
    #define MY_H

int my_putstr(char *);
void my_putchar(char);
char *my_strcat(char *, char *);
int file_len(char const *);
char *fs_open_file(char const *);
char **columsquare(char **, char *);
char **str_to_square(char *);
char **display_square(char *, char **);
pos_t key_up(pos_t);
pos_t key_down(pos_t);
pos_t key_left(pos_t);
pos_t key_right(pos_t);
pos_t position_p(pos_t);
pos_t move_p(int, pos_t);
pos_t my_swap_p(pos_t, pos_o_t);
pos_t display_sokoban(char **, pos_t, int, pos_o_t);
pos_t its_o(pos_t, pos_o_t);
pos_t p_on_o(pos_t, pos_o_t);
pos_t x_on_o(pos_t, pos_o_t);
pos_t itsnot_o(pos_t, pos_o_t);
pos_t movewitho(pos_t, pos_o_t, int, int);
pos_t replace_o(pos_o_t, pos_t, int, int);
int win(pos_t, pos_o_t, int);
int nbr_o_onsquare(pos_t, int, int, int);
int nbr_o_onx(pos_t, int, int, int);
int error_map(char *);
int count_x(pos_t, int, int, int);
int lose(pos_t, int, int, int);
int help_map_sokoban(char **, int);
int my_strcmp(char *, char *);
pos_t tocreatesquare(pos_t, char *);

#endif /* MY_H*/
