/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** init color
*/

#include "include/my.h"

void init_button_color_black(find_button_t *button, win_t *win)
{
    button->black = malloc(sizeof(button_t));
    button->black->color = sfBlack;
    button->black->position.x = 51 * (860 / win->size.x);
    button->black->position.y = 305 * (540 / win->size.y);
    button->black->circle = sfCircleShape_create();
    sfCircleShape_setPosition(button->black->circle,
        button->black->position);
    sfCircleShape_setRadius(button->black->circle, 15);
    sfCircleShape_setFillColor(button->black->circle,
        button->black->color);
    sfCircleShape_setOutlineThickness(button->black->circle, 2);
    sfCircleShape_setOutlineColor(button->black->circle, sfWhite);
}

void init_button_color_green(find_button_t *button, win_t *win)
{
    button->green = malloc(sizeof(button_t));
    button->green->color = sfGreen;
    button->green->position.x = 90 * (860 / win->size.x);
    button->green->position.y = 415 * (540 / win->size.y);
    button->green->circle = sfCircleShape_create();
    sfCircleShape_setPosition(button->green->circle,
        button->green->position);
    sfCircleShape_setRadius(button->green->circle, 15);
    sfCircleShape_setFillColor(button->green->circle,
        button->green->color);
    sfCircleShape_setOutlineThickness(button->green->circle, 2);
    sfCircleShape_setOutlineColor(button->green->circle, sfBlack);
}

void init_button_color_blue(find_button_t *button, win_t *win)
{
    button->blue = malloc(sizeof(button_t));
    button->blue->color = sfBlue;
    button->blue->position.x = 15 * (860 / win->size.x);
    button->blue->position.y = 470 * (540 / win->size.y);
    button->blue->circle = sfCircleShape_create();
    sfCircleShape_setPosition(button->blue->circle,
        button->blue->position);
    sfCircleShape_setRadius(button->blue->circle, 15);
    sfCircleShape_setFillColor(button->blue->circle,
        button->blue->color);
    sfCircleShape_setOutlineThickness(button->blue->circle, 2);
    sfCircleShape_setOutlineColor(button->blue->circle, sfBlack);
}

void init_button_color_pink(find_button_t *button, win_t *win)
{
    button->pink = malloc(sizeof(button_t));
    button->pink->color = sfColor_fromRGB(255, 192, 203);
    button->pink->position.x = 51 * (860 / win->size.x);
    button->pink->position.y = 470 * (540 / win->size.y);
    button->pink->circle = sfCircleShape_create();
    sfCircleShape_setPosition(button->pink->circle,
        button->pink->position);
    sfCircleShape_setRadius(button->pink->circle, 15);
    sfCircleShape_setFillColor(button->pink->circle,
        button->pink->color);
    sfCircleShape_setOutlineThickness(button->pink->circle, 2);
    sfCircleShape_setOutlineColor(button->pink->circle, sfBlack);
}

static void init_button_color_purple(find_button_t *button, win_t *win)
{
    button->purple = malloc(sizeof(button_t));
    button->purple->color = sfMagenta;
    button->purple->position.x = 90 * (860 / win->size.x);
    button->purple->position.y = 470 * (540 / win->size.y);
    button->purple->circle = sfCircleShape_create();
    sfCircleShape_setPosition(button->purple->circle,
        button->purple->position);
    sfCircleShape_setRadius(button->purple->circle, 15);
    sfCircleShape_setFillColor(button->purple->circle,
        button->purple->color);
    sfCircleShape_setOutlineThickness(button->purple->circle, 2);
    sfCircleShape_setOutlineColor(button->purple->circle, sfBlack);
}

void init_button_color(win_t *win, find_button_t *button)
{
    init_button_color_black(button, win);
    init_button_color_white(button, win);
    init_button_color_red(button, win);
    init_button_color_green(button, win);
    init_button_color_blue(button, win);
    init_button_color_yellow(button, win);
    init_button_color_purple(button, win);
    init_button_color_orange(button, win);
    init_button_color_grey(button, win);
    init_button_color_pink(button, win);
}
