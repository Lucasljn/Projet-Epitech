/*
** EPITECH PROJECT, 2023
** projects
** File description:
** meteorsprite2.c
*/

#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include <time.h>

void createspriterect(sfSprite *meteorsprite, sfIntRect rectmeteor,
    sfVector2f posmeteor)
{
    sfTexture *texturemeteor = sfTexture_createFromFile("meteor.png", NULL);

    sfSprite_setTexture(meteorsprite, texturemeteor, sfFalse);
    sfSprite_setTextureRect(meteorsprite, rectmeteor);
}

meteorsprite_t clockspritemeteor(meteorsprite_t meteorsprite)
{
    sfSprite_setTextureRect(meteorsprite.meteor1, meteorsprite.rectmeteor);
    sfSprite_setTextureRect(meteorsprite.meteor2, meteorsprite.rectmeteor);
    sfSprite_setTextureRect(meteorsprite.meteor3, meteorsprite.rectmeteor);
    sfSprite_setTextureRect(meteorsprite.meteor4, meteorsprite.rectmeteor);
    return meteorsprite;
}

meteorsprite_t respawnmeteor(meteorsprite_t meteor, sfRenderWindow *window)
{
    if (meteor.posmeteor1.y > 600) {
        meteor.posmeteor1 = (sfVector2f){(rand() % 960 + 1), -300};
        meteor.meteorpass++;
    }
    if (meteor.posmeteor2.y > 600) {
        meteor.posmeteor2 = (sfVector2f){(rand() % 960 + 1), -495};
        meteor.meteorpass++;
    }
    if (meteor.posmeteor3.y > 600) {
        meteor.posmeteor3 = (sfVector2f){(rand() % 960 + 1), -182};
        meteor.meteorpass++;
    }
    if (meteor.posmeteor4.y > 600) {
        meteor.posmeteor4 = (sfVector2f){(rand() % 960 + 1), -420};
        meteor.meteorpass++;
    }
    if (meteor.meteorpass == 5)
        meteor.level = 2;
    return meteor;
}

void createfond(sfSprite *sprite)
{
    sfTexture *texture_menue = sfTexture_createFromFile("fondplay.png", NULL);
    sfVector2u texture_size = sfTexture_getSize(texture_menue);
    sfVector2f scale = {960.0 / texture_size.x, 540.0 / texture_size.y};

    sfSprite_setTexture(sprite, texture_menue, sfFalse);
    sfSprite_setScale(sprite, scale);
}

void createsprite(sfSprite *sprite, char *filepng)
{
    sfTexture *texture = sfTexture_createFromFile(filepng, NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
}
