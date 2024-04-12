/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** init color 2
*/

#include "include/my.h"

void init_button_color_white(find_button_t *button, win_t *win)
{
    button->white = malloc(sizeof(button_t));
    button->white->color = sfWhite;
    button->white->position.x = 15 * (860 / win->size.x);
    button->white->position.y = 360 * (540 / win->size.y);
    button->white->circle = sfCircleShape_create();
    sfCircleShape_setPosition(button->white->circle,
        button->white->position);
    sfCircleShape_setRadius(button->white->circle, 15);
    sfCircleShape_setFillColor(button->white->circle,
        button->white->color);
    sfCircleShape_setOutlineThickness(button->white->circle, 2);
    sfCircleShape_setOutlineColor(button->white->circle, sfBlack);
}

void init_button_color_grey(find_button_t *button, win_t *win)
{
    button->grey = malloc(sizeof(button_t));
    button->grey->color = sfColor_fromRGB(128, 128, 128);
    button->grey->position.x = 51 * (860 / win->size.x);
    button->grey->position.y = 360 * (540 / win->size.y);
    button->grey->circle = sfCircleShape_create();
    sfCircleShape_setPosition(button->grey->circle,
        button->grey->position);
    sfCircleShape_setRadius(button->grey->circle, 15);
    sfCircleShape_setFillColor(button->grey->circle,
        button->grey->color);
    sfCircleShape_setOutlineThickness(button->grey->circle, 2);
    sfCircleShape_setOutlineColor(button->grey->circle, sfBlack);
}

void init_button_color_red(find_button_t *button, win_t *win)
{
    button->red = malloc(sizeof(button_t));
    button->red->color = sfRed;
    button->red->position.x = 90 * (860 / win->size.x);
    button->red->position.y = 360 * (540 / win->size.y);
    button->red->circle = sfCircleShape_create();
    sfCircleShape_setPosition(button->red->circle,
        button->red->position);
    sfCircleShape_setRadius(button->red->circle, 15);
    sfCircleShape_setFillColor(button->red->circle,
        button->red->color);
    sfCircleShape_setOutlineThickness(button->red->circle, 2);
    sfCircleShape_setOutlineColor(button->red->circle, sfBlack);
}

void init_button_color_orange(find_button_t *button, win_t *win)
{
    button->orange = malloc(sizeof(button_t));
    button->orange->color = sfColor_fromRGB(255, 165, 0);
    button->orange->position.x = 15 * (860 / win->size.x);
    button->orange->position.y = 415 * (540 / win->size.y);
    button->orange->circle = sfCircleShape_create();
    sfCircleShape_setPosition(button->orange->circle,
        button->orange->position);
    sfCircleShape_setRadius(button->orange->circle, 15);
    sfCircleShape_setFillColor(button->orange->circle,
        button->orange->color);
    sfCircleShape_setOutlineThickness(button->orange->circle, 2);
    sfCircleShape_setOutlineColor(button->orange->circle, sfBlack);
}

void init_button_color_yellow(find_button_t *button, win_t *win)
{
    button->yellow = malloc(sizeof(button_t));
    button->yellow->color = sfYellow;
    button->yellow->position.x = 51 * (860 / win->size.x);
    button->yellow->position.y = 415 * (540 / win->size.y);
    button->yellow->circle = sfCircleShape_create();
    sfCircleShape_setPosition(button->yellow->circle,
        button->yellow->position);
    sfCircleShape_setRadius(button->yellow->circle, 15);
    sfCircleShape_setFillColor(button->yellow->circle,
        button->yellow->color);
    sfCircleShape_setOutlineThickness(button->yellow->circle, 2);
    sfCircleShape_setOutlineColor(button->yellow->circle, sfBlack);
}
