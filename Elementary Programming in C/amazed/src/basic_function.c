/*
** EPITECH PROJECT, 2023
** B2
** File description:
** basic_function.c
*/

#include "../include/maze.h"

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
    int len = 0;
    int j = 0;

    for (int i = 0; dest[i] != '\0'; i++) {
        len += 1;
    }
    while (src[j] != '\0') {
        dest[len + j] = src[j];
        j++;
    }
    dest[len + j] = '\0';
    return dest;
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

int my_strcmp(char *s1, char *s2)
{
    for (int i = 0; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return 0;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int res = 0;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return res * neg;
}
