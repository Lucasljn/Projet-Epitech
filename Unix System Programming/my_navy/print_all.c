/*
** EPITECH PROJECT, 2023
** print_all
** File description:
** d
*/

#include "my.h"

int my_getnbr(const char *str)
{
    int signe = 1;
    long nbr = 0;
    int j = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            signe = signe * (-1);
        if (str[i] > 47 && str[i] < 58) {
            nbr = nbr * 10 + str[i] - 48;
            j = 1;
        }
        if ((str[i] < 48 || str[i] > 57 || str[i + 1] == '\0') && j == 1)
            return (nbr * signe);
    }
}

char *my_strdup(const char *src)
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

char **my_str_to_word_array(char *str)
{
    int j = 0;
    int k = 0;
    char **array = malloc(sizeof(char *) * (my_strlen(str) + 1));

    array[0] = malloc(sizeof(char) * (my_strlen(str) + 1));
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
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
