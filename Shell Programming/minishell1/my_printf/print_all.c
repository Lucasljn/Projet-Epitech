/*
** EPITECH PROJECT, 2023
** print_all
** File description:
** d
*/

#include "../my.h"
#include "printf.h"

int my_is_prime(int nbr)
{
    if (nbr == 2)
        return 1;
    if (nbr < 2 || nbr % 2 == 0)
        return 0;
    for (int i = 3; i * i <= nbr; i += 2) {
        if (nbr % i == 0)
            return 0;
    }
    return 1;
}
