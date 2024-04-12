/*
** EPITECH PROJECT, 2023
** projects
** File description:
** error.c
*/

#include "stdlib.h"
#include "libshell/shell.h"
#include "my.h"

int lenargs(char **args)
{
    int len = 0;

    while (args[len] != NULL)
        len++;
    return len;
}

int lenlistchaine(organized_t *list)
{
    int len = 0;

    while (list != NULL) {
        len++;
        list = list->next;
    }
    return len;
}

int comparecate(int i, char **args, int error)
{
    char *cat[6] = {"ACTUATOR", "DEVICE", "PROCESSOR", "SENSOR", "WIRE", 0};

    for (int j = 0; cat[j] != 0; j++) {
        if (my_strcmp(args[i], cat[j]) == 0) {
            return 0;
        } else {
            error = 84;
        }
    }
    return error;
}

int erroradd(char **args)
{
    int lencommande = lenargs(args);
    int error = 0;

    if (lencommande % 2 != 0 || lenargs(args) == 0)
        return 84;
    for (int i = 0; args[i] != 0; i += 2) {
        if (comparecate(i, args, error) == 0) {
            error = 0;
        } else {
            error = 84;
        }
    }
    return error;
}

int errordel(organized_t *list, char **args)
{
    char tmp;

    if (lenargs(args) > lenlistchaine(list) || lenargs(args) == 0)
        return 84;
    for (int i = 0; args[i] != NULL; i++) {
        for (int j = 0; args[i][j] != '\0'; j++) {
            return conddelerror(i, j, args);
        }
    }
}
