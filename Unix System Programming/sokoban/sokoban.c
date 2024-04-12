/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** sokoban.c
*/

#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ncurses.h>

int getcols(char **square)
{
    int lenlines = 0;
    int lencols = 0;
    int tmp = 0;

    while (square[lenlines] != 0) {
        while (square[lenlines][tmp] != '\n') {
            tmp++;
        }
        if (lencols < tmp)
            lencols = tmp;
        lenlines++;
        tmp = 0;
    }
    return lencols;
}

int getrows(char **square)
{
    int lenlines = 0;

    while (square[lenlines] != 0) {
        lenlines++;
    }
    return lenlines;
}

pos_t display_sokoban(char **square, pos_t posp, int touch, pos_o_t pos_o)
{
    int lenlines = getrows(square);
    int lencols = getcols(square);
    int maxx = 0;
    int maxy = 0;

    getmaxyx(stdscr, maxy, maxx);
    if (maxy < lenlines || maxx < lencols) {
        clear();
        mvprintw(maxy / 2, maxx / 2, "The window is too small" );
    } else {
        clear();
        posp = move_p(touch, posp);
        posp = my_swap_p(posp, pos_o);
        for (int i = 0; posp.square[i] != 0; i++)
            mvprintw(maxy / 2 + i, maxx / 2, posp.square[i]);
    }
    touch = win(posp, pos_o, touch);
    refresh();
    return posp;
}

int win(pos_t pos, pos_o_t pos_o, int touch)
{
    int nbr_o = 0;
    int nbr_x = 0;
    int total_x = 0;
    int x = 0;

    for (int i = 0; pos_o.squaredup[i] != 0; i++) {
        for (int j = 0; pos_o.squaredup[i][j] != '\0'; j++) {
            nbr_o = nbr_o_onsquare(pos, i, j, nbr_o);
            nbr_x = nbr_o_onx(pos, i, j, nbr_x);
            total_x = count_x(pos, i, j, total_x);
            x = lose(pos, i, j, x);
        }
    }
    if (nbr_o == nbr_x || total_x == x) {
        endwin();
        exit(0);
    }
    return touch;
}

int main(int argc, char **argv)
{
    int help = help_map_sokoban(argv, argc);
    char *buff = fs_open_file(argv[1]);
    int touch;
    pos_t pos;
    pos_o_t pos_o;

    pos = tocreatesquare(pos, buff);
    pos_o.squaredup = display_square(buff, str_to_square(buff));
    initscr();
    noecho();
    keypad(stdscr, true);
    display_sokoban(pos.square, pos, touch, pos_o);
    touch = getch();
    while (touch != 'q') {
        if (touch == ' ')
            pos.square = display_square(buff, str_to_square(buff));
        pos = display_sokoban(pos.square, pos, touch, pos_o);
        touch = getch();
    }
    endwin();
}
