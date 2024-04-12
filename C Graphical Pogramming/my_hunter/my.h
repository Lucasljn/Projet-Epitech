/*
** EPITECH PROJECT, 2023
** projects
** File description:
** my.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Clock.h>
#include <stdlib.h>
#include <time.h>

typedef struct meteorsprite_s {
    sfSprite *meteor1;
    sfSprite *meteor2;
    sfSprite *meteor3;
    sfSprite *meteor4;
    sfIntRect rectmeteor;
    sfVector2f posmeteor1;
    sfVector2f posmeteor2;
    sfVector2f posmeteor3;
    sfVector2f posmeteor4;
    sfVector2f pos;
    sfClock *clock;
    int meteorpass;
    int frameinit;
    float frametime;
    float elasped;
    int level;
    int score;
    sfText *scorestr;
} meteorsprite_t;

typedef struct create_s {
    sfSprite *menufond;
    sfSprite *fond;
    sfSprite *viseur;
    sfVector2f scalevisor;
    sfMusic *music;
    sfSprite *gameover;
}create_t;

typedef struct window_s{
    sfVideoMode mode;
    sfEvent event;
    sfRenderWindow *window;
} window_t;

#ifndef MY_H
    #define MY_H

int clicklevel(window_t window);
int analyse_events_menu(window_t window);
void close_window(window_t window);
void createmenu(sfSprite *);
meteorsprite_t on_sprite(meteorsprite_t, sfVector2i);
meteorsprite_t click_meteor(window_t, meteorsprite_t);
meteorsprite_t initspritemeteor(meteorsprite_t);
meteorsprite_t drawmeteorsprite(meteorsprite_t, sfRenderWindow *);
void destroy_all(create_t, window_t, meteorsprite_t);
void createspriterect(sfSprite *, sfIntRect, sfVector2f);
meteorsprite_t clockspritemeteor(meteorsprite_t);
meteorsprite_t respawnmeteor(meteorsprite_t, sfRenderWindow *);
void createfond(sfSprite *);
void createsprite(sfSprite *, char *);
meteorsprite_t createclock(meteorsprite_t);
meteorsprite_t clockmeteor(meteorsprite_t, int);
int display_menu(window_t, create_t, int);
meteorsprite_t game(meteorsprite_t, window_t, create_t, sfSprite *);
sfVector2f analyseevent(window_t, sfVector2f);
void createover(sfSprite *);
int analyse_events_over(window_t);
int clickover(window_t);
meteorsprite_t displaygameover(meteorsprite_t, window_t, create_t);
void spritelife(sfSprite *, sfIntRect, sfVector2f);
meteorsprite_t score(meteorsprite_t, sfVector2i);
void drawscore(meteorsprite_t, sfRenderWindow *);
char *int_to_str(int);
char *my_strcat( char *, char *);
int my_putstr(char const *);
int my_strcmp(char *, char *);
int help(int, char **);
void my_putchar(char);

#endif /*MY_H*/
