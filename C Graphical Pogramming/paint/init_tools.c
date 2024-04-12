/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** init tools
*/

#include "include/my.h"

#include <SFML/Graphics.h>

void init_pencil(win_t *win, find_tools_t *tools)
{
    tools->pencil = malloc(sizeof(set_tools_t));
    tools->pencil->size = 2.5;
    tools->pencil->color = sfBlack;
    tools->pencil->shape = 0;
    tools->pencil->pos.x = 500;
    tools->pencil->pos.y = 50;
    tools->pencil->scale_fix.x = 0.1;
    tools->pencil->scale_fix.y = 0.1;
    tools->pencil->scale.x = 0.2;
    tools->pencil->scale.y = 0.2;
    tools->pencil->texture = sfTexture_createFromFile("assets/pencil.png",
    NULL);
    tools->pencil->sprite = sfSprite_create();
    sfSprite_setTexture(tools->pencil->sprite, tools->pencil->texture, sfTrue);
    sfSprite_setScale(tools->pencil->sprite, tools->pencil->scale);
    sfSprite_setPosition(tools->pencil->sprite, tools->pencil->pos);
}

void init_eraser(win_t *win, find_tools_t *tools)
{
    tools->eraser = malloc(sizeof(set_tools_t));
    tools->eraser->size = 2.5;
    tools->eraser->color = sfWhite;
    tools->eraser->shape = 1;
    tools->eraser->pos.x = 550;
    tools->eraser->pos.y = 50;
    tools->eraser->scale.x = 0.1;
    tools->eraser->scale.y = 0.1;
    tools->eraser->texture = sfTexture_createFromFile("assets/eraser.png",
    NULL);
    tools->eraser->sprite = sfSprite_create();
    sfSprite_setTexture(tools->eraser->sprite, tools->eraser->texture, sfTrue);
    sfSprite_setScale(tools->eraser->sprite, tools->eraser->scale);
    sfSprite_setPosition(tools->eraser->sprite, tools->eraser->pos);
}

void init_background(win_t *win, find_tools_t *tools, char *filename)
{
    sfVector2u texture_size;
    sfVector2f scale;

    tools->menu = malloc(sizeof(set_tools_t));
    tools->menu->texture = sfTexture_createFromFile(filename, NULL);
    texture_size = sfTexture_getSize(tools->menu->texture);
    scale.x = 860.0 / texture_size.x;
    scale.y = 540.0 / texture_size.y;
    tools->menu->sprite = sfSprite_create();
    sfSprite_setTexture(tools->menu->sprite, tools->menu->texture, sfFalse);
    sfSprite_setScale(tools->menu->sprite, scale);
}

void draw_palette(win_t *win, find_button_t *button)
{
    sfRenderWindow_drawCircleShape(win->window, button->black->circle, NULL);
    sfRenderWindow_drawCircleShape(win->window, button->white->circle, NULL);
    sfRenderWindow_drawCircleShape(win->window, button->red->circle, NULL);
    sfRenderWindow_drawCircleShape(win->window, button->green->circle, NULL);
    sfRenderWindow_drawCircleShape(win->window, button->blue->circle, NULL);
    sfRenderWindow_drawCircleShape(win->window, button->yellow->circle, NULL);
    sfRenderWindow_drawCircleShape(win->window, button->purple->circle, NULL);
    sfRenderWindow_drawCircleShape(win->window, button->orange->circle, NULL);
    sfRenderWindow_drawCircleShape(win->window, button->grey->circle, NULL);
    sfRenderWindow_drawCircleShape(win->window, button->pink->circle, NULL);
}
