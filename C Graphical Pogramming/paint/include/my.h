/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** day9 task2
*/

#ifndef MY_
    #define MY_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <time.h>
    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <stdbool.h>
    #include "paint.h"

int my_printf(const char *format, ...);
int my_str_isnum(char const *str);
char *my_strdup(char const *src);
int my_getnbr(char const *str);
char *my_strcpy(char *dest, char const *src);
int count_char_int(int count, long nb);
int pstr(va_list list, int i, const char *s, int count);
int pnb(va_list list, int i, const char *s, int count);
int type(va_list list, int i, const char *s, int count);
int show_nbr(int nb, int n);
int random_nbr(int min, int max);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int my_strlen(char const *str);

void init_pencil(win_t *win, find_tools_t *tools);
void init_eraser(win_t *win, find_tools_t *tools);
void init_background(win_t *win, find_tools_t *tools, char *filename);
void init_paint(win_t *win, draw_t *draw, char *filename);

void init_button_color_yellow(find_button_t *button, win_t *win);
void init_button_color_orange(find_button_t *button, win_t *win);
void init_button_color_red(find_button_t *button, win_t *win);
void init_button_color_grey(find_button_t *button, win_t *win);
void init_button_color_white(find_button_t *button, win_t *win);

void draw_buttons(win_t *win, find_tools_t *tools, find_button_t *button);
void color_selected(win_t *win, find_button_t *button, draw_t *draw);
void draw_palette(win_t *win, find_button_t *button);

void init_button_clear(win_t *win, find_button_t *button);
void button_action(win_t *win, find_button_t *button, find_tools_t *tools,
    draw_t *draw);
void init_button_eraser(win_t *win, find_button_t *button);
void button_eraser(win_t *win, find_button_t *button, find_tools_t *tools);
void init_button_pencil(win_t *win, find_button_t *button);
void init_button_file(win_t *win, find_button_t *button);
void button_file(win_t *win, find_button_t *button, find_tools_t *tools, draw_t
    *draw);
void init_button_size(find_button_t *button, win_t *win);
void init_button_color(win_t *win, find_button_t *button);

sfBool is_hover(button_t *button, win_t *win, sfCircleShape *rect);
sfBool is_clicked(button_t *button, win_t *win, sfCircleShape *rect);

void edit_thickness(find_tools_t *tools, draw_t *draw, win_t *win,
    find_button_t *button);
void paint_canvas(win_t *win, find_tools_t *tools, draw_t *draw, find_button_t
    *button);
void print_thickness(draw_t *draw, win_t *win);
void save_paint(sfRenderWindow *window, char *filename, draw_t *draw);

void init_button_edit(win_t *win, find_button_t *button);
void init_button_help(win_t *win, find_button_t *button);
void init_button_savefile(win_t *win, find_button_t *button);
void init_button_openfile(win_t *win, find_button_t *button);
void init_button_newfile(win_t *win, find_button_t *button);

#endif //MY_
