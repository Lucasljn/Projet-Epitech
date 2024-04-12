/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** dijejio
*/

#include <stdlib.h>
#include <unistd.h>
#include "../my.h"

char *my_strdnup(int i, char *src, int n)
{
    char *dest;
    int j = 0;
    int n2 = n;

    if (src[i + 1] == '\0')
        i = i + 1;
    dest = malloc(sizeof(char) * (n + 1));
    while (j < n2) {
        dest[j] = src[i - n];
        j = j + 1;
        n = n - 1;
    }
    dest[j] = '\0';
    return dest;
}

int my_char_isalpha(char stri)
{
    if (stri != ' ')
        return 1;
    return 0;
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

char **my_str_to_array(char *str, char delim[])
{
    char **tab;
    int lentab = len_tab(str);
    int b = 0;
    char *token;

    tab = malloc(sizeof(char *) * (lentab + 1));
    token = strtok(my_strdup(str), delim);
    while (token != NULL) {
        tab[b] = my_strdup(token);
        token = strtok(NULL, delim);
        b++;
    }
    tab[b] = 0;
    return tab;
}

environnement_t *my_str_to_list(char *str)
{
    environnement_t *elm = NULL;
    int n = 0;
    int valeur = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '=')
            n = n + 1;
        if (str[i] == '=' && valeur == 0) {
            elm = malloc(sizeof(environnement_t));
            elm->variable = my_strdnup(i, str, n);
            n = 0;
            valeur = 1;
        }
        if (str[i + 1] == '\0' && valeur == 1) {
            elm->valeur = my_strdnup(i, str, n);
            elm->next = NULL;
            n = 0;
        }
    }
    return elm;
}
