/*
** EPITECH PROJECT, 2023
** B2
** File description:
** error.c
*/

#include "my.h"

int case_setenv(char **tab)
{
    for (int i = 0; tab[1][i] != '\0'; i++) {
        if ((tab[1][i] < '0' || tab[1][i] > '9') && (tab[1][i] < 'a'
            || tab[1][i] > 'z') && (tab[1][i] < 'A' || tab[1][i] > 'Z')
                || tab[1][i] == '_')
            return 1;
    }
    return 0;
}

char *token_bincom(environnement_t *elm, char *bincom, char **tab)
{
    char *token;
    char delim[] = ":";

    token = strtok(my_strdup(elm->valeur), delim);
    while (token != NULL) {
        bincom = my_strcat(token, "/");
        bincom = my_strcat(bincom, tab[0]);
        if (access(bincom, X_OK) == 0)
            break;
        free(bincom);
        bincom = NULL;
        token = strtok(NULL, delim);
    }
    return bincom;
}
