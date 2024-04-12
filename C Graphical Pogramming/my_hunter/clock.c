/*
** EPITECH PROJECT, 2023
** projects
** File description:
** clock.c
*/

#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include <time.h>

meteorsprite_t createclock(meteorsprite_t meteor)
{
    meteor.clock = sfClock_create();
    meteor.elasped = 0.0;
    meteor.frameinit = 0;
    meteor.frametime = 2;
    return meteor;
}

meteorsprite_t clockmeteor(meteorsprite_t meteor, int intlevel)
{
    meteor.elasped += sfClock_getElapsedTime(meteor.clock).microseconds /
        10000000.0;
    if (meteor.elasped >= meteor.frametime && intlevel == 1) {
        sfClock_restart(meteor.clock);
        meteor.elasped = 0.0;
        clockspritemeteor(meteor);
        if (meteor.frameinit < 4)
            meteor.rectmeteor.left = meteor.rectmeteor.left + 78;
        if (meteor.frameinit > 4)
            meteor.rectmeteor.left = meteor.rectmeteor.left + 73;
        meteor.frameinit++;
        if (meteor.frameinit == 9) {
            meteor.frameinit = 0;
            meteor.rectmeteor.left = 5;
        }
    }
    return meteor;
}

void createover(sfSprite *sprite)
{
    sfTexture *texture_menue = sfTexture_createFromFile("gameover.png", NULL);
    sfVector2u texture_size = sfTexture_getSize(texture_menue);
    sfVector2f scale = {960.0 / texture_size.x, 540.0 / texture_size.y};

    sfSprite_setTexture(sprite, texture_menue, sfFalse);
    sfSprite_setScale(sprite, scale);
}

void spritelife(sfSprite *life, sfIntRect rectmeteor,
    sfVector2f posmeteor)
{
    sfTexture *texturemeteor = sfTexture_createFromFile("vie.png", NULL);

    sfSprite_setTexture(life, texturemeteor, sfFalse);
    sfSprite_setTextureRect(life, rectmeteor);
    sfSprite_setPosition(life, posmeteor);
}

meteorsprite_t score(meteorsprite_t meteor, sfVector2i mousepos)
{
    sfFloatRect touchsprite1 = sfSprite_getGlobalBounds(meteor.meteor1);
    sfFloatRect touchsprite2 = sfSprite_getGlobalBounds(meteor.meteor2);
    sfFloatRect touchsprite3 = sfSprite_getGlobalBounds(meteor.meteor3);
    sfFloatRect touchsprite4 = sfSprite_getGlobalBounds(meteor.meteor4);

    if (sfFloatRect_contains(&touchsprite1, mousepos.x, mousepos.y))
        meteor.score++;
    if (sfFloatRect_contains(&touchsprite2, mousepos.x, mousepos.y))
        meteor.score++;
    if (sfFloatRect_contains(&touchsprite3, mousepos.x, mousepos.y))
        meteor.score++;
    if (sfFloatRect_contains(&touchsprite4, mousepos.x, mousepos.y))
        meteor.score++;
    return meteor;
}
