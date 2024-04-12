/*
** EPITECH PROJECT, 2023
** projects
** File description:
** add_and_del.c
*/

#include "stdlib.h"
#include "libshell/shell.h"
#include "my.h"

int maxplace(organized_t *list)
{
    int max = 0;
    organized_t *current = list;

    if (current == NULL)
        return 0;
    while (current != NULL) {
        if (current->id > max)
            max = current->id;
        current = current->next;
    }
    return max + 1;
}

void deleted(organized_t **workshop, organized_t *current, organized_t *prev)
{
    if (prev == NULL) {
        *workshop = current->next;
    } else {
        prev->next = current->next;
    }
    free(current->name);
    free(current->type);
    free(current);
}

void conddel(organized_t *current, organized_t **workshop, char **args, int i)
{
    organized_t *prev = NULL;

    while (current != NULL) {
        if (current->id == my_getnbr(args[i])) {
            mini_printf("%s n°%d - \"%s\" deleted.\n", current->type,
                current->id, current->name);
            deleted(&*workshop, current, prev);
        }
        prev = current;
        current = current->next;
    }
}

int errorsort(char **args)
{
    if (lenargs(args) != 1 && lenargs(args) != 2 || lenargs(args) == 0)
        return 84;
    if (lenargs(args) == 2 && my_strcmp(args[1], "-r") != 0)
        return 84;
    if (my_strcmp(args[0], "NAME") != 0 && my_strcmp(args[0], "TYPE") != 0
        && my_strcmp(args[0], "ID") != 0)
        return 84;
    return 0;
}

organized_t *reverse_list(organized_t *list)
{
    organized_t *prev = NULL;
    organized_t *current = list;
    organized_t *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}
