/*
** EPITECH PROJECT, 2023
** B2
** File description:
** sutenv.c
*/

#include "my.h"

environnement_t *list_env(char **envp)
{
    environnement_t *head = NULL;
    environnement_t *tail = NULL;
    environnement_t *elm = NULL;

    if (envp[0] == 0) {
        envp[0] = "SHELL=/tcsh";
        envp[1] = 0;
    }
    for (int i = 0; envp[i] != NULL; i++) {
        elm = my_str_to_list(envp[i]);
        if (head == NULL)
            head = elm;
        if (tail != NULL)
            tail->next = elm;
        tail = elm;
    }
    head = init_envp(head);
    return head;
}

environnement_t *use_setenv(environnement_t *elm, char **tab)
{
    environnement_t *tail = elm;
    environnement_t *new_element = NULL;

    while (tail != NULL) {
        if (my_strcmp(tail->variable, tab[1]) == 0) {
            tail->valeur = tab[2];
            return elm;
        }
        tail = tail->next;
    }
    new_element = malloc(sizeof(environnement_t));
    new_element->variable = tab[1];
    if (len_tab2(tab) == 3)
        new_element->valeur = tab[2];
    else
        new_element->valeur = NULL;
    new_element->next = NULL;
    use_setenv2(elm, new_element, tail);
    return elm;
}

void cond_head(environnement_t *previous, environnement_t *head,
    environnement_t *elm)
{
    if (previous == NULL) {
        head = elm->next;
    } else {
        previous->next = elm->next;
    }
}

environnement_t *use_unsetenv(environnement_t *elm, char *variable)
{
    environnement_t *head = elm;
    environnement_t *tmp = NULL;
    environnement_t *previous = NULL;

    while (elm != NULL) {
        tmp = elm;
        if (my_strcmp(tmp->variable, variable) == 0) {
            cond_head(previous, head, elm);
            elm = elm->next;
            free(tmp);
        } else {
            previous = elm;
            elm = elm->next;
        }
    }
    return head;
}

environnement_t *show_env(environnement_t *elm)
{
    environnement_t *head = elm;

    while (elm != NULL) {
        my_putstr(elm->variable);
        my_putstr("=");
        if (elm->valeur != NULL)
            my_putstr(elm->valeur);
        my_putstr("\n");
        elm = elm->next;
    }
    return head;
}
