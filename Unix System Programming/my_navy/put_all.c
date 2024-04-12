/*
** EPITECH PROJECT, 2023
** put_all
** File description:
** d
*/

#include "my.h"

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

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
    return 0;
}

int my_strlen(char const *str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        res += 1;
    }
    return res;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
