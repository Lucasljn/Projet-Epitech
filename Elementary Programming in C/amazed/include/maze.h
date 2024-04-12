/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** maze.h
*/

#ifndef MAZE_H
    #define MAZE_H
    #include <fcntl.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <string.h>
    #include <errno.h>
    #include <sys/stat.h>
    #include <stdarg.h>
    #include <dirent.h>
typedef struct path_s {
    int *path;
    int path_len;
    int **all_path;
    int num_path;
} path_t;

typedef struct tunnel_s {
    int nb;
    int *link;
    int is_taken;
    struct tunnel_s *next;
} tunnel_t;

typedef struct robot_s {
    tunnel_t *current_room;
    int id;
    int nb_way;
    struct robot_s *next;
} robot_t;

typedef struct maze_s {
    tunnel_t *tunnels;
    robot_t *robots;
    char *line;
    int start;
    int end;
    int nb_robot;
    int count;
    int del;
    char *stock_room;
    char *stock_tunnel;
} maze_t;

int my_strlen(char *);
char *my_strcat(char *, char *);
char *my_strdup(char *);
int my_strcmp(char *, char *);
char **my_str_to_array(char *, char *);
char **file_to_tab(char **, maze_t *);
int my_getnbr(char const *);
int my_printf(const char *, ...);

void sort_path(path_t *path);
tunnel_t *find_start(tunnel_t *tunnels, int start);
void mouvement_robots(path_t *path, maze_t *maze);
void free_tab(char **tab);

void find_all_paths(tunnel_t *start, tunnel_t *end, path_t *path,
    tunnel_t *all);
void find_path(tunnel_t *tunnels, maze_t *maze);
int len_int(int *link);
void parsing_edge(char **tab, maze_t *maze);

int check_error(char **tab, maze_t *maze);
#endif /* MAZE_H */
