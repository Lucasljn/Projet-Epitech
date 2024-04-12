/*
** EPITECH PROJECT, 2023
** B2
** File description:
** my_strtok.c
*/

#include "../include/maze.h"

int my_char_isalpha(char stri)
{
    if (stri == ' ' || stri == '\t' || stri == '.' ||
        stri == '\"' || stri == '\n')
            return 0;
    return 1;
}

int len_tab(char *str)
{
    int lentab = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isalpha(str[i]) == 0
            && my_char_isalpha(str[i + 1]) == 1)
            lentab = lentab + 1;
    }
    if (my_char_isalpha(str[0]))
        lentab++;
    return lentab;
}

int my_strtok2(char *save, char *delim, int i)
{
    for (int j = 0; delim[j] != '\0'; j++) {
        if (save[i] == delim[j])
            return 1;
    }
    return 0;
}

char *my_strtok(char *str, char *delim)
{
    static char *save = NULL;
    char *res = NULL;

    if (str != NULL)
        save = str;
    if (save == NULL)
        return NULL;
    for (int i = 0; save[i] != '\0'; i++) {
        if (my_strtok2(save, delim, i) == 1) {
            save[i] = '\0';
            res = save;
            save = &save[i + 1];
            return res;
        }
    }
    res = save;
    save = NULL;
    return res;
}

char **my_str_to_array(char *str, char *delim)
{
    char **tab;
    int lentab = len_tab(str);
    int b = 0;
    char *token;

    tab = malloc(sizeof(char *) * (lentab + 2));
    token = my_strtok(my_strdup(str), delim);
    while (token != NULL) {
        if (my_strcmp(token, "\0") != 0) {
            tab[b] = my_strdup(token);
            b++;
        }
        token = my_strtok(NULL, delim);
    }
    tab[b] = NULL;
    return tab;
}
