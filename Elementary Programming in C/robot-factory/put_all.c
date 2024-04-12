/*
** EPITECH PROJECT, 2023
** put_all
** File description:
** d
*/

#include "my.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
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

int my_strncmp(char *s1, char *s2, int n)
{
    for (int i = 0; i < n && (s1[i] && s2[i]); i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    return 0;
}

char *my_revstr(char *str)
{
    int len = 0;
    char tmp;

    for (int i = 0; str[i] != '\0'; i += 1) {
        len = len + 1;
    }
    for (int j = 0; j < len - j - 1; j++) {
        tmp = str[j];
        str[j] = str[len - j - 1];
        str[len - j - 1] = tmp;
    }
    return str;
}
