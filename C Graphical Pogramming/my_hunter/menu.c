/*
** EPITECH PROJECT, 2023
** projects
** File description:
** menu.c
*/

#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include <time.h>

int clicklevel(window_t window)
{
    sfVector2i mouse;
    sfVector2u sizewindow = sfRenderWindow_getSize(window.window);
    double zoom_x = 960.0 / sizewindow.x;
    double zoom_y = 540.0 / sizewindow.y;

    if (window.event.type == sfEvtMouseButtonPressed) {
        mouse = sfMouse_getPositionRenderWindow(window.window);
        if (mouse.x >= (356 / zoom_x) && mouse.x <= (604 / zoom_x) &&
            mouse.y >= (154 / zoom_y) && mouse.y <= (285 / zoom_y)) {
            return 1;
        }
        if (mouse.x >= (27 / zoom_x) && mouse.x <= (130 / zoom_x) &&
            mouse.y >= (445 / zoom_y) && mouse.y <= (515 / zoom_y))
            sfRenderWindow_close(window.window);
    }
    return 0;
}

int analyse_events_menu(window_t window)
{
    sfMouseButtonEvent position;

    while (sfRenderWindow_pollEvent(window.window, &window.event)) {
        close_window(window);
        return clicklevel(window);
    }
}

void close_window(window_t window)
{
    if (window.event.type == sfEvtClosed)
        sfRenderWindow_close(window.window);
}

void createmenu(sfSprite *sprite)
{
    sfTexture *texture_menue = sfTexture_createFromFile("menu.png",
        NULL);
    sfVector2u texture_size = sfTexture_getSize(texture_menue);
    sfVector2f scale = {960.0 / texture_size.x, 540.0 / texture_size.y};

    sfSprite_setTexture(sprite, texture_menue, sfFalse);
    sfSprite_setScale(sprite, scale);
}
