/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** main
*/

#include "include/my.h"

sfRenderWindow *init_window(void)
{
    sfRenderWindow *window;
    sfVideoMode mode = {860, 540, 32};

    window = sfRenderWindow_create(mode, "My_Paint", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

static void free_all(win_t *win, draw_t *draw)
{
    free(draw->pixels);
    sfSprite_destroy(draw->draw_s);
    sfTexture_destroy(draw->canvas_t);
    sfRenderWindow_destroy(win->window);
    free(win->event);
    free(win);
}

void init_all(win_t *win, find_tools_t *tools, find_button_t *button,
    draw_t *draw)
{
    win->window = init_window();
    win->size = sfRenderWindow_getSize(win->window);
    win->event = malloc(sizeof(sfEvent));
    init_eraser(win, tools);
    init_pencil(win, tools);
    init_button_clear(win, button);
    init_button_eraser(win, button);
    init_button_pencil(win, button);
    init_background(win, tools, "assets/menu.png");
    init_button_file(win, button);
    init_button_edit(win, button);
    init_button_help(win, button);
    init_button_savefile(win, button);
    init_button_openfile(win, button);
    init_button_newfile(win, button);
    init_button_size(button, win);
    init_button_color(win, button);
}

void pull_event(win_t *win, find_tools_t *tools)
{
    sfRenderWindow_setMouseCursorVisible(win->window, sfFalse);
    while (sfRenderWindow_pollEvent(win->window, win->event)) {
        if (win->event->type == sfEvtMouseMoved) {
            tools->pencil->pos.x = win->event->mouseMove.x - 7;
            tools->pencil->pos.y = win->event->mouseMove.y - 70;
        }
        if (win->event->type == sfEvtClosed)
            sfRenderWindow_close(win->window);
    }
}

int main(int argc, char **argv)
{
    win_t *win = malloc(sizeof(win_t));
    find_tools_t *tools = malloc(sizeof(find_tools_t));
    find_button_t *button = malloc(sizeof(find_button_t));
    draw_t *draw = malloc(sizeof(draw_t));

    init_paint(win, draw, argv[1]);
    init_all(win, tools, button, draw);
    while (sfRenderWindow_isOpen(win->window)) {
        sfRenderWindow_clear(win->window, sfWhite);
        pull_event(win, tools);
        sfSprite_setPosition(tools->pencil->sprite, tools->pencil->pos);
        sfRenderWindow_drawSprite(win->window, tools->menu->sprite, NULL);
        draw_palette(win, button);
        button_action(win, button, tools, draw);
        paint_canvas(win, tools, draw, button);
        sfRenderWindow_drawSprite(win->window, tools->pencil->sprite, NULL);
        sfRenderWindow_display(win->window);
    }
    free_all(win, draw);
    return 0;
}
