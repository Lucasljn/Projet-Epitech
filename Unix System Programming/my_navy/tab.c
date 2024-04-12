/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** print map
*/

#include "my.h"

char **create_map(void)
{
    char **map = malloc(sizeof(char *) * 8);

    for (int i = 0; i < 8; i++)
        map[i] = malloc(sizeof(char) * 8);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            map[i][j] = '.';
        }
    }
    return map;
}

void color_map(char map_cell, int j)
{
    char sym[4] = {'2', '3', '4', '5'};

    my_printf("%c", map_cell);
    if (j == 7)
        my_printf("\n");
    else
        my_printf(" ");
}

void show_map(char **map)
{
    my_printf(" |A B C D E F G H\n-+---------------\n");
    for (int i = 0; i < 8; i++) {
        my_printf("%d|", i + 1);
        for (int j = 0; j < 8; j++)
            color_map(map[i][j], j);
    }
}

void show_all(void)
{
    my_printf("my navy:\n");
    show_map(navy->map);
    my_printf("enemy navy:\n");
    show_map(navy->map_ad);
}

void edit_map(void)
{
    char arr_nbr[4] = {'2', '3', '4', '5'};
    int letter = navy->coord[0] - 'A';
    int number = navy->coord[1] - '0' - 1;

    if (number == -1)
        number = 1;
    if (my_in(navy->map[number][letter], arr_nbr)) {
        usleep(100);
        kill(navy->pid_ad, SIGUSR1);
        my_printf("hit\n");
        navy->map[number][letter] = 'x';
    } else {
        usleep(100);
        kill(navy->pid_ad, SIGUSR2);
        my_printf("missed\n");
        if (navy->map[number][letter] == '.')
            navy->map[number][letter] = 'o';
    }
}
