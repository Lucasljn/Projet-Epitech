/*
** EPITECH PROJECT, 2023
** B-CPE-110 : Setting Up Shell
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stddef.h>
    #include <signal.h>
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/shm.h>
    #include <string.h>
    #include <semaphore.h>
    #define _GNU_SOURCE
typedef struct navy_s {
    int argc;
    char **argv;
    int pid;
    int pid_ad;
    char **map;
    char **map_ad;
    char *str;
    char *str2;
    int boat;
    int turn;
    int is_next;
    int is_start;
    char *coord;
    int index_coord;
    int is_hit;
} navy_t;

extern navy_t *navy;

int my_printf(const char *format, ...);
int type(va_list list, int i, const char *s, int count);
int count_char_int(int count, long nb);
int pstr(va_list list, int i, const char *s, int count);
int pnb(va_list list, int i, const char *s, int count);
int my_strlen(char const *str);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int show_nbr(int nb, int n);
int my_str_isnum(char const *str);
char *my_strdup(const char *src);
int my_getnbr(const char *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char *s1, char *s2);
char *my_strcat(char *dest, char *src);
char **my_str_to_word_array(char *str);
int my_in(char want, char *source);

int file_len(char const *);
char **open_file(char *filepath);
int error(char *filepath);
int verif_map(char *str);
char *fs_open_file(char const *, char *);
char **square_map_create(void);
char **map_with_boat(char *);
char **place_boat(char *);
int left(int);

int get_error(char *filepath);
int init(void);
int player1(char *filepath);
int player2(char *filepath, char *pid);
void reset(void);

void show_all(void);
void show_map(char **map);
void color_map(char map_cell, int j);
void edit_map(void);
void set_boat(char *place);
char **create_map(void);
void append_map(char x, char y, char sym);
void sub_place(int index, char *place);

void wait_reception(void);
void wait_start(void);
void wait_response(void);
void handle_response(int sig, siginfo_t *info, void *no);
void handle_signal(int sig, siginfo_t *info, void *no);
void send_value(char *coord);
void win(void);
char *load_file(char const *filepath);
char *get_send_line(void);
char *is_touch(char *coord);

#endif
