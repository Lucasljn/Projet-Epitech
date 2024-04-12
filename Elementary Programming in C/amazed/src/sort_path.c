/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** sort_path.c
*/

#include "../include/maze.h"

int len_tab_int(int *path)
{
    int i;

    for (i = 0; path[i] != -1; i++);
    return i;
}

int sort_path2(path_t *path, int *tmp, int i)
{
    if (len_tab_int(path->all_path[i]) >
        len_tab_int(path->all_path[i + 1])) {
        tmp = path->all_path[i];
        path->all_path[i] = path->all_path[i + 1];
        path->all_path[i + 1] = tmp;
        return 0;
    }
    return i;
}

void sort_path(path_t *path)
{
    int *tmp;

    for (int i = 0; i < path->num_path; i++) {
        if (i + 1 != path->num_path) {
            i = sort_path2(path, tmp, i);
        }
    }
}
