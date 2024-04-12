/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** init button
*/

#include "include/my.h"

void init_button_clear(win_t *win, find_button_t *button)
{
    button->clear = malloc(sizeof(button_t));
    button->clear->color = sfBlack;
    button->clear->position.x = 742 * (860 / win->size.x);
    button->clear->position.y = 37.5 * (540 / win->size.y);
    button->clear->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->clear->rect,
        button->clear->position);
    sfRectangleShape_setSize(button->clear->rect,
        (sfVector2f){95, 50});
    sfRectangleShape_setFillColor(button->clear->rect, button->clear->color);
}

void init_button_eraser(win_t *win, find_button_t *button)
{
    button->eraser = malloc(sizeof(button_t));
    button->eraser->color = sfBlack;
    button->eraser->position.x = 368 * (860 / win->size.x);
    button->eraser->position.y = 62.5 * (540 / win->size.y);
    button->eraser->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->eraser->rect,
        button->eraser->position);
    sfRectangleShape_setSize(button->eraser->rect,
        (sfVector2f){30, 30});
    sfRectangleShape_setFillColor(button->eraser->rect,
        button->eraser->color);
}

void init_button_pencil(win_t *win, find_button_t *button)
{
    button->pencil = malloc(sizeof(button_t));
    button->pencil->color = sfBlack;
    button->pencil->position.x = 322 * (860 / win->size.x);
    button->pencil->position.y = 62.5 * (540 / win->size.y);
    button->pencil->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->pencil->rect,
        button->pencil->position);
    sfRectangleShape_setSize(button->pencil->rect,
        (sfVector2f){30, 30});
    sfRectangleShape_setFillColor(button->pencil->rect,
        button->pencil->color);
}

void init_button_file(win_t *win, find_button_t *button)
{
    button->file = malloc(sizeof(button_t));
    button->file->color = sfWhite;
    button->file->position.x = 0 * (860 / win->size.x);
    button->file->position.y = 0 * (540 / win->size.y);
    button->file->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->file->rect,
        button->file->position);
    sfRectangleShape_setSize(button->file->rect,
        (sfVector2f){60, 30});
    sfRectangleShape_setFillColor(button->file->rect,
        button->file->color);
}

void init_button_size(find_button_t *button, win_t *win)
{
    button->size_min = malloc(sizeof(button_t));
    button->size_plus = malloc(sizeof(button_t));
    button->size_min->position.x = 550 * (860 / win->size.x);
    button->size_min->position.y = 60 * (540 / win->size.y);
    button->size_min->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->size_min->rect,
        button->size_min->position);
    sfRectangleShape_setSize(button->size_min->rect,
        (sfVector2f){25, 25});
    sfRectangleShape_setFillColor(button->size_min->rect,
        button->size_min->color);
    button->size_plus->position.x = 617 * (860 / win->size.x);
    button->size_plus->position.y = 60 * (540 / win->size.y);
    button->size_plus->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->size_plus->rect,
        button->size_plus->position);
    sfRectangleShape_setSize(button->size_plus->rect,
        (sfVector2f){25, 25});
    sfRectangleShape_setFillColor(button->size_plus->rect,
        button->size_plus->color);
}
