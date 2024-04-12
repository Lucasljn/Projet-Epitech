/*
** EPITECH PROJECT, 2023
** projects
** File description:
** poseandswitch.c
*/

#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ncurses.h>

pos_t allpos(pos_t pos, int i, int j)
{
    if (pos.square[i][j] == 'P') {
        pos.p_x = j;
        pos.p_y = i;
        pos.x = j;
        pos.y = i;
        pos.x_x = j;
        pos.x_y = i;
    }
    return pos;
}

pos_t position_p(pos_t pos)
{
    for (int i = 0; pos.square[i] != 0; i++) {
        for (int j = 0; pos.square[i][j] != '\0'; j++)
            pos = allpos(pos, i, j);
    }
    return pos;
}

pos_t move_x(pos_t pos, char tmp)
{
    if (pos.square[pos.y][pos.x] == 'X') {
        tmp = pos.square[pos.y][pos.x];
        pos.square[pos.y][pos.x] = pos.square[pos.x_y][pos.x_x];
        pos.square[pos.x_y][pos.x_x] = tmp;
        pos.x_x = pos.x;
        pos.x_y = pos.y;
    }
    return pos;
}

pos_t my_swap_p(pos_t pos, pos_o_t pos_o)
{
    char tmp;

    if (pos.square[pos.y][pos.x] == 'O' ||
        pos.square[pos.x_y][pos.x_x] == 'O') {
        pos = its_o(pos, pos_o);
        return pos;
    }
    if (pos.square[pos.x_y][pos.x_x] == '#' ||
            pos.square[pos.x_y][pos.x_x] == 'X')
            return pos;
    pos = move_x(pos, tmp);
    tmp = pos.square[pos.y][pos.x];
    pos.square[pos.y][pos.x] = pos.square[pos.p_y][pos.p_x];
    pos.square[pos.p_y][pos.p_x] = tmp;
    pos.p_x = pos.x;
    pos.p_y = pos.y;
    pos = itsnot_o(pos, pos_o);
    return pos;
}

pos_t its_o(pos_t pos, pos_o_t pos_o)
{
    for (int i = 0; pos_o.squaredup[i] != 0; i++) {
        for (int j = 0; pos_o.squaredup[i][j] != '\0'; j++) {
            pos = movewitho(pos, pos_o, i, j);
        }
    }
    return pos;
}
