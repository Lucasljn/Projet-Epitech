/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** winlose.c
*/

#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ncurses.h>

int nbr_o_onsquare(pos_t pos, int i, int j, int nbr_o)
{
    if (pos.square[i][j] == 'O')
        nbr_o++;
    return nbr_o;
}

int nbr_o_onx(pos_t pos, int i, int j, int nbr_x)
{
    if (pos.square[i][j] == 'X' && pos.square[i][j] == 'O')
        nbr_x++;
    return nbr_x;
}

int error_map(char *str)
{
    int o_onmap = 0;
    int x_onmap = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != 'P' && str[i] != '\n' && str[i] != '#' &&
            str[i] != 'X' && str[i] != 'O' && str[i] != ' ')
            exit(84);
        if (str[i] == 'X')
            x_onmap++;
        if (str[i] == 'O')
            o_onmap++;
    }
    if (x_onmap != o_onmap)
        exit(84);
    return 0;
}

int lose(pos_t pos, int i, int j, int x)
{
    if (pos.square[i][j] == 'X' && pos.square[i][j] != 'O') {
        if ((pos.square[i + 1][j] == '#' && pos.square[i][j + 1] == '#') ||
            (pos.square[i + 1][j] == '#' && pos.square[i][j - 1] == '#') ||
            (pos.square[i - 1][j] == '#' && pos.square[i][j - 1] == '#') ||
            (pos.square[i - 1][j] == '#' && pos.square[i][j + 1] == '#')) {
                x++;
        }
    }
    return x;
}

int count_x(pos_t pos, int i, int j, int total_x)
{
    if (pos.square[i][j] == 'X')
        total_x++;
    return total_x;
}
