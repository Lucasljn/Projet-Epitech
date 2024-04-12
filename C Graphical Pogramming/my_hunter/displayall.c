/*
** EPITECH PROJECT, 2023
** projects
** File description:
** displayall.c
*/

#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include <time.h>

int display_menu(window_t window, create_t create, int intlevel)
{
    if (intlevel == 0) {
        intlevel = analyse_events_menu(window);
        sfRenderWindow_drawSprite(window.window, create.menufond, NULL);
    }
    return intlevel;
}

meteorsprite_t game(meteorsprite_t meteor, window_t window, create_t create,
    sfSprite *life)
{
    if (meteor.level == 1) {
        sfRenderWindow_setMouseCursorVisible(window.window, sfFalse);
        meteor.pos = analyseevent(window, meteor.pos);
        sfRenderWindow_drawSprite(window.window, create.fond, NULL);
        sfSprite_setPosition(create.viseur, meteor.pos);
        meteor = drawmeteorsprite(meteor, window.window);
        meteor = click_meteor(window, meteor);
        meteor = respawnmeteor(meteor, window.window);
        sfSprite_setTextureRect(life,
            (sfIntRect){28, 22 + (36* meteor.meteorpass), 197, 36});
        sfRenderWindow_drawSprite(window.window, life, NULL);
        drawscore(meteor, window.window);
        sfRenderWindow_drawSprite(window.window, create.viseur, NULL);
        meteor = clockmeteor(meteor, meteor.level);
    }
    return meteor;
}

int analyse_events_over(window_t window)
{
    sfMouseButtonEvent position;

    while (sfRenderWindow_pollEvent(window.window, &window.event)) {
        close_window(window);
        return clickover(window);
    }
    return 2;
}

int clickover(window_t window)
{
    sfVector2i mouse;
    sfVector2u sizewindow = sfRenderWindow_getSize(window.window);
    double zoom_x = 960.0 / sizewindow.x;
    double zoom_y = 540.0 / sizewindow.y;

    if (window.event.type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(window.window);
        if (mouse.x >= (162 / zoom_x) && mouse.x <= (444 / zoom_x) &&
            mouse.y >= (268 / zoom_y) && mouse.y <= (365 / zoom_y)) {
            return 1;
        }
        if (mouse.x >= (517 / zoom_x) && mouse.x <= (798 / zoom_x) &&
            mouse.y >= (268 / zoom_y) && mouse.y <= (365 / zoom_y)) {
            return 0;
        }
    }
    return 2;
}

meteorsprite_t displaygameover(meteorsprite_t meteor, window_t window,
    create_t create)
{
    if (meteor.level == 2) {
        meteor.meteorpass = 0;
        meteor.posmeteor1 = (sfVector2f){(rand() % 960 + 1), -300};
        meteor.posmeteor2 = (sfVector2f){(rand() % 960 + 1), -495};
        meteor.posmeteor3 = (sfVector2f){(rand() % 960 + 1), -182};
        meteor.posmeteor4 = (sfVector2f){(rand() % 960 + 1), -420};
        sfRenderWindow_setMouseCursorVisible(window.window, sfTrue);
        meteor.level = analyse_events_over(window);
        sfRenderWindow_drawSprite(window.window, create.gameover, NULL);
    }
    return meteor;
}
