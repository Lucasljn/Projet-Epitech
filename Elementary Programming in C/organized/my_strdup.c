/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *src)
{
    char *dest;
    int len = 0;

    for (int i = 0; src[i] != '\0'; i++)
        len = len + 1;
    dest = malloc(sizeof(char) * (len + 1));
    for (int j = 0; src[j] != '\0'; j++)
        dest[j] = src[j];
    dest[len] = '\0';
    return dest;
}
