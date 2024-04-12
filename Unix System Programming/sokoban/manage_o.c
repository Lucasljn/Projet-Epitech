/*
** EPITECH PROJECT, 2023
** projects
** File description:
** manage_o.c
*/

#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ncurses.h>

pos_t p_on_o(pos_t pos, pos_o_t pos_o)
{
    if ((pos.x == pos_o.x && pos.y == pos_o.y)) {
        if (pos.p_x == pos.x && pos.y == pos.p_y)
            return pos;
        pos.square[pos_o.y][pos_o.x] = 'P';
        pos.square[pos.p_y][pos.p_x] = ' ';
        pos.p_x = pos_o.x;
        pos.p_y = pos_o.y;
    } else {
        return pos;
    }
    return pos;
}

pos_t x_on_o(pos_t pos, pos_o_t pos_o)
{
    if ((pos.x_x == pos_o.x && pos.x_y == pos_o.y)) {
        if (pos.x_x == pos.x && pos.y == pos.x_y)
            return pos;
        pos.square[pos_o.y][pos_o.x] = 'X';
        pos.square[pos.y][pos.x] = 'P';
        pos.square[pos.p_y][pos.p_x] = ' ';
        pos.p_x = pos.x;
        pos.p_y = pos.y;
        pos.x_x = pos.x;
        pos.x_y = pos.y;
        }
    return pos;
}

pos_t itsnot_o(pos_t pos, pos_o_t pos_o)
{
    for (int i = 0; pos_o.squaredup[i] != 0; i++) {
        for (int j = 0; pos_o.squaredup[i][j] != '\0'; j++) {
            pos = replace_o(pos_o, pos, i, j);
        }
    }
    return pos;
}

pos_t replace_o(pos_o_t pos_o, pos_t pos, int i, int j)
{
    if (pos_o.squaredup[i][j] == 'O' && pos.square[i][j] == ' ')
        pos.square[i][j] = 'O';
}

pos_t movewitho(pos_t pos, pos_o_t pos_o, int i, int j)
{
    if (pos_o.squaredup[i][j] == 'O') {
        pos_o.x = j;
        pos_o.y = i;
        if (pos.square[pos.y][pos.x] != 'X')
            pos = p_on_o(pos, pos_o);
        if (pos.square[pos.y][pos.x] == 'X')
            pos = x_on_o(pos, pos_o);
        if (pos.square[pos_o.y][pos_o.x] == ' ')
            pos.square[pos_o.y][pos_o.x] == 'O';
    }
    return pos;
}
