/*
** EPITECH PROJECT, 2023
** B2
** File description:
** errorandother.c
*/

#include "my.h"

environnement_t *use_setenv2(environnement_t *elm,
    environnement_t *new_element, environnement_t *tail)
{
    if (elm == NULL) {
        elm = new_element;
    } else {
        tail = elm;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = new_element;
    }
}

void cd_function(char **tab, environnement_t *elm)
{
    char buff[1024];

    getcwd(buff, sizeof(buff));
    if (len_tab2(tab) == 2 && my_strcmp(tab[1], "-") == 0) {
        while (my_strcmp(elm->variable, "OLDPWD") != 0)
            elm = elm->next;
        my_putstr(elm->valeur);
        my_putchar('\n');
        chdir(elm->valeur);
        elm->valeur = my_strdup(buff);
        return;
    }
    if (tab[1] == NULL) {
        while (my_strcmp(elm->variable, "HOME") != 0)
            elm = elm->next;
        chdir(elm->valeur);
    } else if (chdir(tab[1]) == -1)
        my_printf("%s: %s.\n", tab[1], strerror(errno));
    elm = oldpath(elm, buff);
}

char *found_bincom(environnement_t *elm, char **tab)
{
    char *token;
    const char delim[] = ":";
    char *bincom = NULL;

    while (elm != NULL && my_strcmp(elm->variable, "PATH") != 0)
        elm = elm->next;
    if (access(tab[0], X_OK) == 0 || elm == NULL || elm->valeur == NULL)
        return tab[0];
    bincom = token_bincom(elm, bincom, tab);
    if (access(tab[0], X_OK) == 0 || bincom == NULL)
        return tab[0];
    return bincom;
}

int len_tab2(char **tab)
{
    int len = 0;

    for (int i = 0; tab[i] != 0; i++)
        len++;
    return len;
}

void bin_error(int status, char **tab)
{
    int signal = WTERMSIG(status);

    if (!WIFSIGNALED(status))
        return;
    if (signal == ENOEXEC)
        my_printf("%s: Exec format error. Wrong Architecture.\n", tab[0]);
    if (signal == SIGSEGV)
        write(2, "Segmentation fault\n", 19);
    if (SIGFPE == signal)
        write(2, "Floating point exception\n", 25);
    if (signal == SIGABRT)
        write(2, "Aborted\n", 8);
    if (signal == SIGILL)
        write(2, "Illegal instruction\n", 20);
}
