/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** strcat
*/

#include "my.h"

char *my_strcat(char *dest, char *src)
{
    int j = 0;
    int i = 0;
    char *str = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src));

    for (; dest[i] != '\0'; i++)
        str[i] = dest[i];
    for (; src[j] != '\0'; j++) {
        str[i] = src[j];
        i++;
    }
    str[i] = '\0';
    return str;
}
