/*
** EPITECH PROJECT, 2023
** my-ls
** File description:
** put_miniprintf.c
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0'){
        my_putchar(str[i]);
        i ++;
    }
    return 0;
}

int my_put_nbr(int nbr)
{
    int nbr2 = nbr;

    if (nbr == -2147483648) {
        my_putchar('-');
        nbr = 214748364;
    }
    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr / 10 != 0) {
        my_put_nbr(nbr / 10);
    }
    my_putchar(48 + (nbr % 10));
    if (nbr2 == -2147483648) {
        my_putchar(56);
    }
    return 0;
}

int my_numlen(int n)
{
    int numlen = 0;

    if (n < 0) {
        n = n * -1;
        numlen = numlen + 1;
    }
    while (n != 0) {
        n = n / 10;
        numlen = numlen + 1;
    }
    return numlen;
}

int my_strlen(char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        len = len + 1;
    }
    return len;
}
