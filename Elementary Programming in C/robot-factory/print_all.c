/*
** EPITECH PROJECT, 2023
** print_all
** File description:
** d
*/

#include "my.h"

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

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    char *new = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

    if (new == NULL)
        exit(1);
    for (i = 0; dest[i] != '\0'; i++)
        new[i] = dest[i];
    for (j = 0; src[j] != '\0'; j++)
        new[i + j] = src[j];
    new[i + j] = '\0';
    return new;
}

char **my_str_to_word_array(char *str, char sep)
{
    int j = 0;
    int k = 0;
    char **array = malloc(sizeof(char *) * (my_strlen(str) + 1));

    array[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep) {
            array[j][k] = '\0';
            j++;
            k = 0;
            array[j] = malloc(sizeof(char) * (my_strlen(str) + 1));
        } else {
            array[j][k] = str[i];
            k++;
        }
    }
    array[j][k] = '\0';
    array[j + 1] = NULL;
    return array;
}

int my_getnbr(char *str)
{
    int i = 0;
    int neg = 1;
    int nb = 0;

    if (str[0] == '-') {
        neg = -1;
        i++;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        nb = nb * 10 + str[i] - 48;
    }
    return nb * neg;
}

int str_is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 84;
    }
    return 0;
}
