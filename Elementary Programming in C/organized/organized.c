/*
** EPITECH PROJECT, 2023
** projects
** File description:
** organized.c
*/

#include "stdlib.h"
#include "libshell/shell.h"
#include "my.h"

int add(void *data, char **args)
{
    organized_t **workshop = (organized_t **)data;
    organized_t *nw;
    int a = 0;
    int b = 1;

    if (erroradd(args) == 84)
        return 84;
    while (args[b] != NULL) {
        nw = malloc(sizeof(organized_t));
        nw->type = my_strdup(args[a]);
        nw->name = my_strdup(args[b]);
        nw->id = maxplace(*workshop);
        mini_printf("%s n°%d - \"%s\" added.\n", nw->type, nw->id, nw->name);
        nw->next = *workshop;
        *workshop = nw;
        nw = nw->next;
        a += 2;
        b += 2;
    }
}

int del(void *data, char **args)
{
    organized_t **workshop = (organized_t **)data;
    organized_t *current = *workshop;
    organized_t *prev = NULL;

    if (errordel(current, args) == 84)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        current = *workshop;
        conddel(current, &*workshop, args, i);
    }
    return 0;
}

int sort(void *data, char **args)
{
    organized_t **workshop = (organized_t **)data;
    organized_t *list = *workshop;

    if (list == NULL || errorsort(args) == 84)
        return 84;
    if (my_strcmp(args[0], "NAME") == 0)
        *workshop = tri_fusion(list, 0);
    if (my_strcmp(args[0], "TYPE") == 0)
        *workshop = tri_fusion(list, 1);
    if (my_strcmp(args[0], "ID") == 0)
        *workshop = tri_fusion(list, 2);
    if (lenargs(args) == 2 && my_strcmp(args[1], "-r") == 0)
        *workshop = reverse_list(*workshop);
    return 0;
}

int disp(void *data, char **args)
{
    organized_t **workshop = (organized_t **)data;
    organized_t *current = *workshop;

    if (current == NULL)
        return 84;
    while (current != NULL) {
        mini_printf("%s n°%d - \"%s\"\n", current->type,
            current->id, current->name);
        current = current->next;
    }
    return 0;
}

int main(int argc, char **argv)
{
    organized_t *list = NULL;
    int output = workshop_shell(&list);

    if (output == 84)
        return 84;
    return 0;
}
