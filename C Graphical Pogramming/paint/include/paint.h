/*
** EPITECH PROJECT, 2023
** game.h
** File description:
** structure
*/

#ifndef PAINT_
    #define PAINT_
    #include "my.h"

typedef struct sprite_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfCircleShape *radius;
    sfVector2i location;
} sprite_t;

enum e_gui_state {
    NONE = 0,
    HOVER,
    PRESSED,
    RELEASED
};

typedef struct button_s {
    sfRectangleShape *rect;
    sfCircleShape *circle;
    sfVector2f position;
    sfVector2f size;
    sfColor color;
    sfVector2f scale;
    sfSprite *button_sprite;
    sfBool (*is_clicked)(struct button_s *, sfMouseButtonEvent *);
    sfBool (*is_hover)(struct button_s *, sfMouseMoveEvent *);
    sfBool is_mouse_pressed;
    sfBool is_pen;
    sfBool is_eraser;
    sfBool is_edit;
    sfVector2f start_position;
    sfColor selected_colour;
    sfEvent event;
    bool clicked;
    enum e_gui_state state;
} button_t;

typedef struct find_button_s {
    button_t *pencil;
    button_t *eraser;
    button_t *menu;
    button_t *clear;
    button_t *file;
    button_t *edit;
    button_t *help;
    button_t *savefile;
    button_t *openfile;
    button_t *newfile;
    button_t *size_plus;
    button_t *size_min;
    button_t *black;
    button_t *white;
    button_t *red;
    button_t *green;
    button_t *blue;
    button_t *yellow;
    button_t *purple;
    button_t *orange;
    button_t *grey;
    button_t *pink;
} find_button_t;

typedef struct set_tools_s {
    sfTexture *texture;
    sfColor color;
    sfSprite *sprite;
    sfVector2f scale;
    sfVector2f scale_fix;
    sfVector2f pos;
    int size;
    int shape;
} set_tools_t;

typedef struct find_tools_s {
    set_tools_t *pencil;
    set_tools_t *eraser;
    set_tools_t *menu;
} find_tools_t;

typedef struct draw_s {
    sfUint8 *pixels;
    sfSprite *draw_s;
    sfTexture *canvas_t;
    sfVector2f pos;
    int prev_mouse_x;
    int prev_mouse_y;
    int thickness;
    sfFont *font;
    sfText *text;
    sfColor pen_color;
    sfBool is_pen;
} draw_t;

typedef struct s_gui_drop_menu_s {
    sfVector2f position;
    sfVector2f size;
    struct s_gui_option_s *options;
    int num_options;
} s_gui_drop_menu_t;

typedef struct window {
    sfVideoMode mode;
    sfRenderWindow *win;
    sfEvent event;
} window_t;

typedef struct win_s {
    sfRenderWindow *window;
    sfEvent *event;
    sprite_t *menu;
    int is_sprite;
    sfClock *main_time;
    unsigned int seconds;
    unsigned int minutes;
    sfClock *clock_plane;
    float seconds_plane;
    sfText *time_text;
    sfRectangleShape *time_rect;
    sfClock *fps_clock;
    sfText *fps_text;
    sfTexture *texture;
    sfVector2u size;
    sfMouseButtonEvent *mouseEvent;
} win_t;
#endif //PAINT_
