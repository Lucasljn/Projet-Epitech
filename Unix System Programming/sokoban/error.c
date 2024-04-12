/*
** EPITECH PROJECT, 2023
** my_sokoban
** File description:
** error.c
*/

#include "my.h"
#include <stdlib.h>

int help_map_sokoban(char **av, int ac)
{
    if (ac != 2)
        exit(84);
    if (my_strcmp(av[1], "-h") == 0) {
        my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n");
        my_putstr("     map file representing the warehouse map,");
        my_putstr("containing '#' for walls,\n         'P' for the player,");
        my_putstr("'X' for boxes and 'O' for storage locations.\n");
        exit(0);
    }
    return 0;
}

pos_t tocreatesquare(pos_t pos, char *buff)
{
    pos.square = display_square(buff, str_to_square(buff));
    pos = position_p(pos);
    return pos;
}
