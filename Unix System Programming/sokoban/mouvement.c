/*
** EPITECH PROJECT, 2023
** projects
** File description:
** mouvement.c
*/

#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ncurses.h>

pos_t key_up(pos_t pos)
{
    if (pos.y != 0 && pos.square[pos.y - 1][pos.x] != '#') {
        pos = position_p(pos);
        pos.y--;
        pos.x_y--;
        if (pos.square[pos.y][pos.x] == 'X' && pos.y != 0)
            pos.x_y--;
    }
    return pos;
}

pos_t key_down(pos_t pos)
{
    if (pos.square[pos.y + 1] != 0 && pos.square[pos.y + 1][pos.x] != '#') {
        pos = position_p(pos);
        pos.y++;
        pos.x_y++;
        if (pos.square[pos.y + 1] != 0 && pos.square[pos.y][pos.x] == 'X')
            pos.x_y++;
    }
    return pos;
}

pos_t key_left(pos_t pos)
{
    if (pos.square[pos.y][pos.x - 1] != '#' && pos.x != 0) {
        pos = position_p(pos);
        pos.x--;
        pos.x_x--;
        if (pos.square[pos.y][pos.x] == 'X' && pos.x != 0)
            pos.x_x--;
    }
    return pos;
}

pos_t key_right(pos_t pos)
{
    if (pos.square[pos.y][pos.x + 1] != '#' &&
        pos.square[pos.y][pos.x + 1] != '\n') {
        pos = position_p(pos);
        pos.x++;
        pos.x_x++;
        if (pos.square[pos.y][pos.x] == 'X' &&
            pos.square[pos.y][pos.x + 1] != '\n')
            pos.x_x++;
    }
    return pos;
}

pos_t move_p(int touch, pos_t pos)
{
    int tab[5] = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, 0};
    pos_t(*mouv[5])(pos_t) = {key_left, key_right, key_up, key_down, 0};

    for (int i = 0; i != 5; i++) {
        if (touch == tab[i]) {
            pos = (*mouv[i])(pos);
        }
    }
    return pos;
}
