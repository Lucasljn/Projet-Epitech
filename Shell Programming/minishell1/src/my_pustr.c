/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** put str
*/

#include <unistd.h>
#include "../my.h"

void my_putchar(char c)
{
    write(2, &c, 1);
}

int my_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i ++;
    }
    return 0;
}
