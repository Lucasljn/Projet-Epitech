/*
** EPITECH PROJECT, 2023
** projects
** File description:
** findmaxsquare.c
*/

#include "my.h"
#include <stdlib.h>

int **squaretomatrix(char **square, int **newsquare, int lenofcol, int i)
{
    for (int j = 0; j < lenofcol; j++){
        if (square[i][j] == '.') {
            newsquare[i][j] = 1;
        } else {
            newsquare[i][j] = 0;
        }
    }
    return newsquare;
}

void numsquare(char **square, int **newsquare, int lenofcol, int i)
{
    for (int j = 1; j < lenofcol; j++) {
        if (square[i][j] == '.') {
            newsquare[i][j] = 1 + min(newsquare[i - 1][j],
                newsquare[i][j - 1], newsquare[i - 1][j - 1]);
        }
    }
}

void findsquare(int lenofcol, int **newsquare, struct big *maxsquare, int y)
{
    for (int x = 0; x < lenofcol; x++) {
        if (newsquare[y][x] > maxsquare->sizex) {
            maxsquare->sizex = newsquare[y][x];
            maxsquare->x = x;
            maxsquare->sizey = newsquare[y][x];
            maxsquare->y = y;
        }
    }
}

void squarewithx(char **square, struct big *maxsquare)
{
    int tmp = maxsquare->sizex;
    int tmpx = maxsquare->x;

    while (maxsquare->sizey != 0) {
        while (maxsquare->sizex != 0) {
            square[maxsquare->y][maxsquare->x] = 'x';
            maxsquare->x -= 1;
            maxsquare->sizex -= 1;
        }
        maxsquare->x = tmpx;
        maxsquare->sizex = tmp;
        maxsquare->y -= 1;
        maxsquare->sizey -= 1;
    }
}

void findmaxsquare(char **square)
{
    int lenofrow = lenrow(square) + 1;
    int lenofcol = lencol(square);
    int **newsquare = createsquare(square, lenofcol, lenofrow);
    struct big *maxsquare = (struct big *)malloc(sizeof(struct big));

    for (int i = 0; i < lenofrow - 1; i++) {
        squaretomatrix(square, newsquare, lenofcol, i);
    }
    for (int i = 1; i < lenofrow - 1; i++) {
        numsquare(square, newsquare, lenofcol, i);
    }
    maxsquare->sizex = 0;
    for (int y = 0; y < lenofrow - 1; y++) {
        findsquare(lenofcol, newsquare, maxsquare, y);
    }
    squarewithx(square, maxsquare);
}
