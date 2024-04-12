/*
** EPITECH PROJECT, 2023
** projects
** File description:
** meteorsprite.c
*/

#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include <time.h>

meteorsprite_t on_sprite(meteorsprite_t meteor, sfVector2i mousepos)
{
    sfFloatRect touchsprite1 = sfSprite_getGlobalBounds(meteor.meteor1);
    sfFloatRect touchsprite2 = sfSprite_getGlobalBounds(meteor.meteor2);
    sfFloatRect touchsprite3 = sfSprite_getGlobalBounds(meteor.meteor3);
    sfFloatRect touchsprite4 = sfSprite_getGlobalBounds(meteor.meteor4);

    if (sfFloatRect_contains(&touchsprite1, mousepos.x, mousepos.y))
        meteor.posmeteor1 = (sfVector2f){(rand() % 960 + 1), -300};
    if (sfFloatRect_contains(&touchsprite2, mousepos.x, mousepos.y))
        meteor.posmeteor2 = (sfVector2f){(rand() % 960 + 1), -495};
    if (sfFloatRect_contains(&touchsprite3, mousepos.x, mousepos.y))
        meteor.posmeteor3 = (sfVector2f){(rand() % 960 + 1), -182};
    if (sfFloatRect_contains(&touchsprite4, mousepos.x, mousepos.y))
        meteor.posmeteor4 = (sfVector2f){(rand() % 960 + 1), -420};
    return meteor;
}

meteorsprite_t click_meteor(window_t window, meteorsprite_t meteor)
{
    sfVector2i mousepos;

    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        mousepos = sfMouse_getPositionRenderWindow(window.window);
        meteor = score(meteor, mousepos);
        meteor = on_sprite(meteor, mousepos);
    }
    return meteor;
}

meteorsprite_t initspritemeteor(meteorsprite_t meteor)
{
    meteor.score = 0;
    meteor.level = 0;
    meteor.meteorpass = 0;
    meteor.rectmeteor = (sfIntRect){5, 0, 80, 119};
    srand(time(NULL));
    meteor.meteor1 = sfSprite_create();
    meteor.meteor2 = sfSprite_create();
    meteor.meteor3 = sfSprite_create();
    meteor.meteor4 = sfSprite_create();
    meteor.scorestr = sfText_create();
    meteor.posmeteor1 = (sfVector2f){(rand() % 960 + 1), -300};
    meteor.posmeteor2 = (sfVector2f){(rand() % 960 + 1), -495};
    meteor.posmeteor3 = (sfVector2f){(rand() % 960 + 1), -182};
    meteor.posmeteor4 = (sfVector2f){(rand() % 960 + 1), -420};
    createspriterect(meteor.meteor1, meteor.rectmeteor, meteor.posmeteor1);
    createspriterect(meteor.meteor2, meteor.rectmeteor, meteor.posmeteor2);
    createspriterect(meteor.meteor3, meteor.rectmeteor, meteor.posmeteor3);
    createspriterect(meteor.meteor4, meteor.rectmeteor, meteor.posmeteor4);
    return meteor;
}

meteorsprite_t drawmeteorsprite(meteorsprite_t meteorsprite,
    sfRenderWindow *window)
{
    sfVector2u sizewindow = sfRenderWindow_getSize(window);
    double y = 540.0 / sizewindow.y;

    meteorsprite.posmeteor1.y = meteorsprite.posmeteor1.y + 0.15 / y;
    meteorsprite.posmeteor2.y = meteorsprite.posmeteor2.y + 0.15 / y;
    meteorsprite.posmeteor3.y = meteorsprite.posmeteor3.y + 0.15 / y;
    meteorsprite.posmeteor4.y = meteorsprite.posmeteor4.y + 0.15 / y;
    sfSprite_setPosition(meteorsprite.meteor1, meteorsprite.posmeteor1);
    sfSprite_setPosition(meteorsprite.meteor2, meteorsprite.posmeteor2);
    sfSprite_setPosition(meteorsprite.meteor3, meteorsprite.posmeteor3);
    sfSprite_setPosition(meteorsprite.meteor4, meteorsprite.posmeteor4);
    sfRenderWindow_drawSprite(window, meteorsprite.meteor1, NULL);
    sfRenderWindow_drawSprite(window, meteorsprite.meteor2, NULL);
    sfRenderWindow_drawSprite(window, meteorsprite.meteor3, NULL);
    sfRenderWindow_drawSprite(window, meteorsprite.meteor4, NULL);
    return meteorsprite;
}

void destroy_all(create_t create, window_t window, meteorsprite_t meteor)
{
    sfSprite_destroy(create.viseur);
    sfMusic_destroy(create.music);
    sfRenderWindow_destroy(window.window);
    sfSprite_destroy(create.menufond);
    sfSprite_destroy(create.fond);
    sfSprite_destroy(meteor.meteor1);
    sfSprite_destroy(meteor.meteor2);
    sfSprite_destroy(meteor.meteor3);
    sfSprite_destroy(meteor.meteor4);
    sfClock_destroy(meteor.clock);
    sfSprite_destroy(create.gameover);
    sfText_destroy(meteor.scorestr);
}
