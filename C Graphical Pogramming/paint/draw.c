/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** draw
*/

#include "include/my.h"

char *my_tostr(int nbr)
{
    int size = 0;
    int tmp = nbr;
    char *strnbr;

    for (; tmp > 0; size++)
        tmp /= 10;
    strnbr = malloc(sizeof(char) * (size + 1));
    strnbr[size] = '\0';
    for (int i = size - 1; i >= 0; i--) {
        strnbr[i] = nbr % 10 + 48;
        nbr /= 10;
    }
    return strnbr;
}

void print_thickness(draw_t *draw, win_t *win)
{
    char *strnbr = my_tostr(draw->thickness);
    sfFont *font = sfFont_createFromFile("assets/font.otf");

    draw->text = sfText_create();
    sfText_setFont(draw->text, font);
    sfText_setString(draw->text, strnbr);
    sfText_setCharacterSize(draw->text, 30);
    sfText_setPosition(draw->text, (sfVector2f){590, 51});
    if (draw->thickness > 9)
        sfText_setPosition(draw->text, (sfVector2f){580, 51});
    sfText_setColor(draw->text, sfBlack);
    sfRenderWindow_drawText(win->window, draw->text, NULL);
}

static void change_color(draw_t *draw, int x, int y, int i)
{
    int index = 0;
    int cur_x = 0;
    int cur_y = 0;

    for (int j = -draw->thickness / 2; j <= draw->thickness / 2; j++) {
        cur_x = x + i;
        cur_y = y + j;
        if (cur_x >= 0 && cur_y >= 0 && cur_x < 800 && cur_y < 450) {
            index = (cur_y * 800 + cur_x) * 4;
            draw->pixels[index] = draw->pen_color.r;
            draw->pixels[index + 1] = draw->pen_color.g;
            draw->pixels[index + 2] = draw->pen_color.b;
            draw->pixels[index + 3] = draw->pen_color.a;
        }
    }
}

static void paint(draw_t *draw, sfVector2i m)
{
    int err = abs(m.x - draw->prev_mouse_x) - abs(m.y - draw->prev_mouse_y);
    int e2;
    int x = draw->prev_mouse_x;
    int y = draw->prev_mouse_y;

    while (1) {
        for (int i = -draw->thickness / 2; i <= draw->thickness / 2; i++)
            change_color(draw, x, y, i);
        if (x == m.x && y == m.y)
            break;
        e2 = 2 * err;
        if (e2 > -abs(m.y - draw->prev_mouse_y)) {
            err -= abs(m.y - draw->prev_mouse_y);
            x += draw->prev_mouse_x < m.x ? 1 : -1;
        }
        if (e2 < abs(m.x - draw->prev_mouse_x)) {
            err += abs(m.x - draw->prev_mouse_x);
            y += draw->prev_mouse_y < m.y ? 1 : -1;
        }
    }
}

void save_paint(sfRenderWindow *window, char *filename, draw_t *draw)
{
    sfImage *image = sfTexture_copyToImage(draw->canvas_t);

    sfImage_saveToFile(image, filename);
    sfImage_destroy(image);
}

void paint_canvas(win_t *win, find_tools_t *tools, draw_t *draw,
    find_button_t *button)
{
    sfVector2i mouse_pos = {sfMouse_getPositionRenderWindow(win->window).x -
        145, sfMouse_getPositionRenderWindow(win->window).y - 97};

    edit_thickness(tools, draw, win, button);
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if (draw->prev_mouse_x != -1 && draw->prev_mouse_y != -1) {
            paint(draw, mouse_pos);
        }
        draw->prev_mouse_x = mouse_pos.x;
        draw->prev_mouse_y = mouse_pos.y;
        sfTexture_updateFromPixels(draw->canvas_t, draw->pixels,
            800, 450, 0, 0);
    } else {
        draw->prev_mouse_x = -1;
        draw->prev_mouse_y = -1;
    }
    sfRenderWindow_drawSprite(win->window, draw->draw_s, NULL);
}

void init_paint(win_t *win, draw_t *draw, char *filename)
{
    draw->pixels = (sfUint8*)malloc(1920 * 1080 * 4);
    draw->draw_s = sfSprite_create();
    if (open(filename, O_RDONLY) == -1) {
        draw->canvas_t = sfTexture_create(800, 450);
        sfTexture_updateFromPixels(draw->canvas_t, draw->pixels,
            800, 450, 0, 0);
    } else
        draw->canvas_t = sfTexture_createFromFile(filename, NULL);
    sfSprite_setTexture(draw->draw_s, draw->canvas_t, sfTrue);
    sfSprite_setPosition(draw->draw_s, (sfVector2f){136, 95});
    draw->prev_mouse_x = -1;
    draw->prev_mouse_y = -1;
    draw->thickness = 5;
    draw->is_pen = sfTrue;
}
