/*
** EPITECH PROJECT, 2023
** projects
** File description:
** inttostr.c
*/

#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include <time.h>

char *int_to_str(int nbr)
{
    char *score = malloc(sizeof(char) * 10);
    int len = 1;
    char temp;

    while (nbr != 0) {
        score[len] = '0' + (nbr % 10);
        nbr /= 10;
        len++;
    }
    for (int i = 0; i < len / 2; i++) {
        temp = score[i];
        score[i] = score[len - i - 1];
        score[len - i - 1] = temp;
    }
    score[len - 1] = '\0';
    return score;
}

void drawscore(meteorsprite_t meteor, sfRenderWindow *window)
{
    char *strscore = int_to_str(meteor.score);
    sfFont *font = sfFont_createFromFile("scorefont.TTF");

    sfText_setFont(meteor.scorestr, font);
    sfText_setFillColor(meteor.scorestr, sfWhite);
    sfText_setString(meteor.scorestr, strscore);
    sfText_setPosition(meteor.scorestr, (sfVector2f){10, 10});
    sfRenderWindow_drawText(window, meteor.scorestr, NULL);
    free(strscore);
    sfFont_destroy(font);
}

int help(int argc, char **argv)
{
    if (argc > 2)
        return 84;
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putstr("USAGE\n    ./my_hunter\n\nDESCRIPTION\n");
        my_putstr("    In order to play huntermeteor, you must destroing\n");
        my_putstr("    meteorites which could explode the planet if you\n");
        my_putstr("    don't do something.\n    To save the world, you can\n");
        my_putstr("    destroy the meteorites by cliquing on it with\n");
        my_putstr("    cursor.\n\nNow i let you play. Good luck.\n");
        return 0;
    }
    if (argc == 1) {
        return 0;
    } else {
        return 84;
    }
    return 0;
}
