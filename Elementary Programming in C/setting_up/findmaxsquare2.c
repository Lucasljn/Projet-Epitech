/*
** EPITECH PROJECT, 2023
** projects
** File description:
** findmaxsquare2.c
*/

#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int lenrow(char **square)
{
    int len = 0;

    for (int i = 0; square[i] != 0; i++) {
        len++;
    }
    return len;
}

int lencol(char **square)
{
    int len = 0;

    if (square[0] != 0) {
        for (int j = 0; square[0][j] != '\0'; j++) {
            len++;
        }
    }
    return len;
}

int **createsquare(char **square, int lenofcol, int lenofrow)
{
    int **newsquare = (int **)malloc(sizeof(int *) * (lenofrow + 1));

    newsquare[lenofrow] = NULL;
    for (int i = 0; square[i] != 0; i++) {
        newsquare[i] = (int *)malloc(sizeof(int) * lenofcol + 1);
    }
    return newsquare;
}

int min(int left, int above, int next)
{
    int min = left;

    if (min > above)
        min = above;
    if (min > next)
        min = next;
    return min;
}
