/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** action button
*/

#include "include/my.h"

void button_help(sfVector2i mouse, find_button_t *button, find_tools_t *tools)
{
    sfFloatRect edit = sfRectangleShape_getGlobalBounds(button->edit->rect);
    sfFloatRect help = sfRectangleShape_getGlobalBounds(button->help->rect);

    if (sfFloatRect_contains(&edit, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        button->edit->is_edit = 0;
        tools->menu->texture = sfTexture_createFromFile("assets/menu.png",
            NULL);
        sfSprite_setTexture(tools->menu->sprite, tools->menu->texture,
            sfFalse);
    }
    if (sfFloatRect_contains(&help, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        button->edit->is_edit = 1;
        tools->menu->texture =
            sfTexture_createFromFile("assets/optionhelp.png", NULL);
        sfSprite_setTexture(tools->menu->sprite, tools->menu->texture,
            sfFalse);
    }
}

void button_file(win_t *win, find_button_t *button, find_tools_t *tools,
    draw_t *draw)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);
    sfFloatRect file = sfRectangleShape_getGlobalBounds(button->file->rect);

    if (sfFloatRect_contains(&file, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            button->edit->is_edit = 1;
            tools->menu->texture =
                sfTexture_createFromFile("assets/optionfile.png", NULL);
            sfSprite_setTexture(tools->menu->sprite, tools->menu->texture,
                sfFalse);
    }
    button_help(mouse, button, tools);
}

void button_clear(draw_t *draw, find_button_t *button, win_t *win)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);
    sfFloatRect clear = sfRectangleShape_getGlobalBounds(button->clear->rect);
    sfFloatRect n = sfRectangleShape_getGlobalBounds(button->openfile->rect);

    if ((sfFloatRect_contains(&clear, mouse.x, mouse.y) ||
        sfFloatRect_contains(&n, mouse.x, mouse.y))
            && sfMouse_isButtonPressed(sfMouseLeft)) {
            for (int i = 0; i < 800 * 450 * 4; i += 4) {
                draw->pixels[i] = 255;
                draw->pixels[i + 1] = 255;
                draw->pixels[i + 2] = 255;
                draw->pixels[i + 3] = 255;
            }
    }
}

static char *name_your_file(void)
{
    char *commande = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        write(1, "save as name: ", 14);
        read = getline(&commande, &len, stdin);
        if (commande[read - 1] == '\n')
            commande[read - 1] = '\0';
        break;
    }
    return commande;
}

static void button_on_file(win_t *win, find_button_t *button, draw_t *draw)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);
    sfFloatRect s = sfRectangleShape_getGlobalBounds(button->savefile->rect);
    sfFloatRect o = sfRectangleShape_getGlobalBounds(button->newfile->rect);
    char *name;

    if (sfFloatRect_contains(&s, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft))
        save_paint(win->window, name_your_file(), draw);
    if (sfFloatRect_contains(&o, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        name = name_your_file();
        draw->pixels = (sfUint8*)malloc(1920 * 1080 * 4);
        draw->draw_s = sfSprite_create();
        if (open(name, O_RDONLY) != -1) {
            draw->canvas_t = sfTexture_createFromFile(name, NULL);
            sfSprite_setTexture(draw->draw_s, draw->canvas_t, sfTrue);
            sfSprite_setPosition(draw->draw_s, (sfVector2f){136, 95});
        } else
            write(2, "No image.jpg found.\n", 20);
    }
}

static void button_pen_eraser(win_t *win, find_button_t *button,
    find_tools_t *tools, draw_t *draw)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);
    sfFloatRect gom = sfRectangleShape_getGlobalBounds(button->eraser->rect);
    sfFloatRect pen = sfRectangleShape_getGlobalBounds(button->pencil->rect);

    if (sfFloatRect_contains(&gom, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            draw->pen_color = sfWhite;
            sfSprite_setTexture(tools->pencil->sprite,
                tools->eraser->texture, sfFalse);
            draw->is_pen = 0;
    }
    if (sfFloatRect_contains(&pen, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft)) {
            draw->pen_color = sfBlack;
            sfSprite_setTexture(tools->pencil->sprite,
                tools->pencil->texture, sfFalse);
            draw->is_pen = 1;
    }
}

void button_action(win_t *win, find_button_t *button, find_tools_t *tools,
    draw_t *draw)
{
    button_pen_eraser(win, button, tools, draw);
    button_clear(draw, button, win);
    button_file(win, button, tools, draw);
    button_on_file(win, button, draw);
    color_selected(win, button, draw);
}

void edit_thickness(find_tools_t *tools, draw_t *draw, win_t *win,
    find_button_t *button)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(win->window);
    sfFloatRect size_plus = sfRectangleShape_getGlobalBounds(button->
        size_plus->rect);
    sfFloatRect size_min = sfRectangleShape_getGlobalBounds(button->
        size_min->rect);

    if (sfFloatRect_contains(&size_plus, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft) && draw->thickness < 50)
            draw->thickness += 1;
    if (sfFloatRect_contains(&size_min, mouse.x, mouse.y)
        && sfMouse_isButtonPressed(sfMouseLeft) && draw->thickness > 1)
            draw->thickness -= 1;
    if (button->edit->is_edit == 0)
        print_thickness(draw, win);
}
