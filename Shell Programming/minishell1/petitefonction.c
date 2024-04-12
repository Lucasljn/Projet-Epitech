/*
** EPITECH PROJECT, 2023
** B2
** File description:
** all.c
*/

#include "my.h"

environnement_t *oldpath(environnement_t *elm, char *buff)
{
    while (my_strcmp(elm->variable, "OLDPWD") != 0)
        elm = elm->next;
    elm->variable = my_strdup("OLDPWD");
    elm->valeur = my_strdup(buff);
    return elm;
}

environnement_t *add_env2(char *variable, char *valeur,
    environnement_t *current)
{
    environnement_t *new_node = malloc(sizeof(environnement_t));

    if (new_node == NULL) {
        return NULL;
    }
    new_node->variable = my_strdup(variable);
    new_node->valeur = my_strdup(valeur);
    new_node->next = NULL;
    current->next = new_node;
    current = new_node;
    return new_node;
}

environnement_t *add_to_env(environnement_t *elm, int path, int home, int old)
{
    environnement_t *head = elm;
    environnement_t *tail = elm;
    char buff[1024];

    if (elm == NULL) {
        elm = malloc(sizeof(environnement_t));
        head = elm;
        tail = elm;
    }
    getcwd(buff, sizeof(buff));
    while (tail->next != NULL)
        tail = tail->next;
    if (home != 1)
        tail = add_env2("HOME", "/home", tail);
    if (old != 1)
        tail = add_env2("OLDPWD", buff, tail);
    return head;
}

environnement_t *init_envp(environnement_t *elm)
{
    environnement_t *current = elm;
    int path = 0;
    int home = 0;
    int old = 0;

    while (current != NULL) {
        if (my_strcmp(current->variable, "PATH") == 0)
            path = 1;
        if (my_strcmp(current->variable, "HOME") == 0)
            home = 1;
        if (my_strcmp(current->variable, "OLDPWD") == 0)
            old = 1;
        current = current->next;
    }
    if (elm == NULL)
        elm = malloc(sizeof(environnement_t));
    return add_to_env(elm, path, home, old);
}

void free_function(char **tab, environnement_t *elm, char *command)
{
    environnement_t *current;
    environnement_t *next;

    for (int i = 0; tab[i] != 0; i++)
        free(tab[i]);
    free(tab);
    while (current != NULL) {
        next = current->next;
        free(current->variable);
        free(current->valeur);
        free(current);
        current = next;
    }
    free(command);
    free(elm);
}
