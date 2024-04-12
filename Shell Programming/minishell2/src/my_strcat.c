/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** strcat
*/

#include "../my.h"

int my_strlen(char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        len = len + 1;
    }
    return len;
}

char *my_strcat(char *dest, char *src)
{
    int j = 0;
    int i = 0;
    char *str = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);

    for (; dest[i] != '\0'; i++)
        str[i] = dest[i];
    for (; src[j] != '\0'; j++) {
        str[i] = src[j];
        i++;
    }
    str[i] = '\0';
    return str;
}

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
