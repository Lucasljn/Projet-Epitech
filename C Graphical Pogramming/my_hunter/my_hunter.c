/*
** EPITECH PROJECT, 2023
** projects
** File description:
** my_hunter.c
*/

#include "my.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include <time.h>

sfVector2f viseur_mouse_pos(sfEvent event, sfVector2f position)
{
    position.x = event.mouseMove.x - 33;
    position.y = event.mouseMove.y - 33;
    return position;
}

sfVector2f analyseevent(window_t window, sfVector2f pos)
{
    sfMouseButtonEvent position;

    while (sfRenderWindow_pollEvent(window.window, &window.event)) {
        close_window(window);
        if (window.event.type == sfEvtMouseMoved)
            pos = viseur_mouse_pos(window.event, pos);
    }
    return pos;
}

window_t createwindow(window_t window)
{
    window.mode = (sfVideoMode){960, 540};
    window.window = sfRenderWindow_create(window.mode, "hunter",
        sfDefaultStyle, NULL);
    return window;
}

create_t create_all(create_t create)
{
    create.gameover = sfSprite_create();
    create.menufond = sfSprite_create();
    create.fond = sfSprite_create();
    create.viseur = sfSprite_create();
    create.scalevisor = (sfVector2f){0.13, 0.13};
    create.music = sfMusic_createFromFile("musicepic.ogg");
    sfMusic_setLoop(create.music, sfFalse);
    sfMusic_play(create.music);
    createmenu(create.menufond);
    createfond(create.fond);
    createsprite(create.viseur, "viseur.png");
    sfSprite_setScale(create.viseur, create.scalevisor);
    createover(create.gameover);
    return create;
}

int main(int argc, char **argv)
{
    sfSprite *life = sfSprite_create();
    window_t window;
    create_t create;
    meteorsprite_t meteor;
    int errorhelp = help(argc, argv);

    spritelife(life, (sfIntRect){28, 22, 197, 34}, (sfVector2f){735, 20});
    window = createwindow(window);
    create = create_all(create);
    meteor = createclock(meteor);
    meteor = initspritemeteor(meteor);
    while (sfRenderWindow_isOpen(window.window)) {
        sfRenderWindow_clear(window.window, sfBlack);
        meteor.level = display_menu(window, create, meteor.level);
        meteor = game(meteor, window, create, life);
        meteor = displaygameover(meteor, window, create);
        sfRenderWindow_display(window.window);
    }
    destroy_all(create, window, meteor);
    return errorhelp;
}
