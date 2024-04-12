/*
** EPITECH PROJECT, 2023
** put_all
** File description:
** d
*/

#include "../my.h"
#include "printf.h"


int show_nbr(int nb, int n)
{
    if (nb > 0) {
        n = nb % 10 + '0';
        show_nbr(nb / 10, n);
        write(1, &n, 1);
    }
    if (nb < 0) {
        write(1, "-", 1);
        n = nb % 10 * (- 1) + '0';
        show_nbr(nb / (- 10), n);
        write(1, &n, 1);
    }
}

int my_put_nbr(int nb)
{
    int n = 0;

    if (nb == 0) {
        write(1, "0", 1);
        return 0;
    }
    show_nbr(nb, n);
    return 0;
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0' || dest[i] != '\0') {
        if (src[i] == '\0') {
            dest[i] = '\0';
            return dest;
        } else {
            dest[i] = src[i];
            i++;
        }
    }
    return (dest);
}
