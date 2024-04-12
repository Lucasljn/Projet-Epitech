/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** select color
*/

#include "include/my.h"

void color_selected4(sfVector2i mouse, find_button_t *button, draw_t *draw,
    win_t *win)
{
    sfFloatRect green = sfCircleShape_getGlobalBounds(button->green->circle);
    sfFloatRect blue = sfCircleShape_getGlobalBounds(button->blue->circle);
    sfFloatRect yellow = sfCircleShape_getGlobalBounds(button->yellow->circle);

    if (sfFloatRect_contains(&green, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft))
            draw->pen_color = sfGreen;
    if (sfFloatRect_contains(&blue, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft))
            draw->pen_color = sfBlue;
    if (sfFloatRect_contains(&yellow, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft))
            draw->pen_color = sfYellow;
}

void color_selected3(sfVector2i mouse, find_button_t *button, draw_t *draw,
    win_t *win)
{
    sfFloatRect orange = sfCircleShape_getGlobalBounds(button->orange->circle);
    sfFloatRect purple = sfCircleShape_getGlobalBounds(button->purple->circle);
    sfFloatRect pink = sfCircleShape_getGlobalBounds(button->pink->circle);

    if (sfFloatRect_contains(&orange, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft))
            draw->pen_color = sfColor_fromRGB(255, 165, 0);
    if (sfFloatRect_contains(&purple, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft))
            draw->pen_color = sfMagenta;
    if (sfFloatRect_contains(&pink, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft))
            draw->pen_color = sfColor_fromRGB(255, 192, 203);
}

void color_selected2(sfVector2i mouse, find_button_t *button, draw_t *draw,
    win_t *win)
{
    sfFloatRect white = sfCircleShape_getGlobalBounds(button->white->circle);
    sfFloatRect grey = sfCircleShape_getGlobalBounds(button->grey->circle);
    sfFloatRect red = sfCircleShape_getGlobalBounds(button->red->circle);

    if (sfFloatRect_contains(&white, mouse.x, mouse.y)) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            draw->pen_color = sfWhite;
        }
    }
    if (sfFloatRect_contains(&grey, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft))
            draw->pen_color = sfColor_fromRGB(128, 128, 128);
    if (sfFloatRect_contains(&red, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft))
            draw->pen_color = sfRed;
}

void color_selected(win_t *win, find_button_t *button, draw_t *draw)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);
    sfFloatRect black = sfCircleShape_getGlobalBounds(button->black->circle);

    if (draw->is_pen == 1) {
        if (sfFloatRect_contains(&black, mouse.x, mouse.y)
            && sfMouse_isButtonPressed(sfMouseLeft))
                draw->pen_color = sfBlack;
    }
    color_selected2(mouse, button, draw, win);
    color_selected3(mouse, button, draw, win);
    color_selected4(mouse, button, draw, win);
}
