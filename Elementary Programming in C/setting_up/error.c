/*
** EPITECH PROJECT, 2023
** projects
** File description:
** error.c
*/

#include "my.h"
#include <stdlib.h>

int destroyfirstrow(char *str)
{
    int destroy = 0;

    for (int i = 0; str[i] != '\n'; i++) {
        destroy++;
    }
    return destroy + 1;
}

int diff_nbr_char(int ac, char **av, int j)
{
    if (ac == 3) {
        if (av[2][j] != '.' && av[2][j] != 'o')
            exit(84);
    }
}

int error(int ac, char **av)
{
    if (ac != 2 && ac != 3)
        exit(84);
    if (ac == 3) {
        if (my_str_isnum(av[1]) == 0)
            exit(84);
        if (my_getnbr(av[1]) > 2000)
            exit(84);
    }
    for (int i = 1; av[i] != 0; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            diff_nbr_char(ac, av, j);
        }
    }
}

int errorrow(char *str, char **square)
{
    int i = 0;
    char *nombre;
    int j = 0;

    while (str[i] != '\n') {
        i++;
    }
    nombre = malloc(sizeof(char) * i);
    while (str[j] != '\n') {
        nombre[j] = str[j];
        j++;
    }
    if (my_getnbr(nombre) != lenrow(square) || my_getnbr(nombre) > 2000)
        exit(84);
}
