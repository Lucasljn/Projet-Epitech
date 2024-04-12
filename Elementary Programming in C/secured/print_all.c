/*
** EPITECH PROJECT, 2023
** print_all
** File description:
** d
*/

#include "my.h"

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

char *my_strdup(char *src)
{
    char *dest;
    int len = my_strlen(src);

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
