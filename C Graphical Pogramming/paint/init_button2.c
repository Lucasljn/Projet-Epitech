/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** init button 2
*/

#include "include/my.h"

void init_button_edit(win_t *win, find_button_t *button)
{
    button->edit = malloc(sizeof(button_t));
    button->edit->color = sfWhite;
    button->edit->position.x = 65 * (860 / win->size.x);
    button->edit->position.y = 0 * (540 / win->size.y);
    button->edit->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->edit->rect,
        button->edit->position);
    sfRectangleShape_setSize(button->edit->rect,
        (sfVector2f){60, 30});
    sfRectangleShape_setFillColor(button->edit->rect,
        button->edit->color);
    button->edit->is_edit = 0;
}

void init_button_help(win_t *win, find_button_t *button)
{
    button->help = malloc(sizeof(button_t));
    button->help->color = sfWhite;
    button->help->position.x = 130 * (860 / win->size.x);
    button->help->position.y = 0 * (540 / win->size.y);
    button->help->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->help->rect,
        button->help->position);
    sfRectangleShape_setSize(button->help->rect,
        (sfVector2f){60, 30});
    sfRectangleShape_setFillColor(button->help->rect,
        button->help->color);
}

void init_button_savefile(win_t *win, find_button_t *button)
{
    button->savefile = malloc(sizeof(button_t));
    button->savefile->color = sfWhite;
    button->savefile->position.x = 20 * (860 / win->size.x);
    button->savefile->position.y = 40 * (540 / win->size.y);
    button->savefile->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->savefile->rect,
        button->savefile->position);
    sfRectangleShape_setSize(button->savefile->rect,
        (sfVector2f){80, 45});
    sfRectangleShape_setFillColor(button->savefile->rect,
        button->savefile->color);
}

void init_button_newfile(win_t *win, find_button_t *button)
{
    button->newfile = malloc(sizeof(button_t));
    button->newfile->color = sfWhite;
    button->newfile->position.x = 113 * (860 / win->size.x);
    button->newfile->position.y = 40 * (540 / win->size.y);
    button->newfile->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->newfile->rect,
        button->newfile->position);
    sfRectangleShape_setSize(button->newfile->rect,
        (sfVector2f){80, 45});
    sfRectangleShape_setFillColor(button->newfile->rect,
        button->newfile->color);
}

void init_button_openfile(win_t *win, find_button_t *button)
{
    button->openfile = malloc(sizeof(button_t));
    button->openfile->color = sfWhite;
    button->openfile->position.x = 208 * (860 / win->size.x);
    button->openfile->position.y = 40 * (540 / win->size.y);
    button->openfile->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->openfile->rect,
        button->openfile->position);
    sfRectangleShape_setSize(button->openfile->rect,
        (sfVector2f){80, 45});
    sfRectangleShape_setFillColor(button->openfile->rect,
        button->openfile->color);
}
