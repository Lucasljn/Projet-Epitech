/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** check nbr boat
*/

#include "my.h"

int check_x(int i, int j, int player)
{
    if (player == 1) {
        if (navy->map[i][j] == 'x')
            return 1;
    } else {
        if (navy->map_ad[i][j] == 'x')
            return 1;
    }
    return 0;
}

int left(int player)
{
    int boat = 14;

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            boat -= check_x(i, j, player);
    return boat;
}

void win(void)
{
    if (left(1) == 0)
        my_printf("\nEnemy won\n");
    if (left(2) == 0)
        my_printf("\nI won\n");
}
