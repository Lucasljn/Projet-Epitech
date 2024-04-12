/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** main.c
*/
#include "../include/maze.h"

static void rm_comment(char *str, int i)
{
    if (str[i] == '#' && str[i + 1] != '#' && str[i + 1] != 's'
        && str[i + 1] != 'e' && str[i + 1] != 't' && str[i + 1] != 'n') {
            while (str[i - 1] == ' ')
                i--;
            str[i] = '\n';
            str[i + 1] = '\0';
    }
}

static int is_tiret(char **tab, int i)
{
    for (int j = 0; tab[i][j] != '\0'; j++) {
        if (tab[i][j] == '-') {
            return 1;
        }
    }
    return 0;
}

void stock_room_tunnel(char **tab, maze_t *maze)
{
    int count = 0;

    maze->stock_room = malloc(sizeof(char) * 1024);
    maze->stock_tunnel = malloc(sizeof(char) * 1024);
    maze->stock_room[0] = '\0';
    maze->stock_tunnel[0] = '\0';
    for (int i = 1; tab[i] != NULL; i++) {
        if (is_tiret(tab, i))
            break;
        count++;
    }
    for (int i = 1; i < count + 1; i++) {
        my_strcat(maze->stock_room, tab[i]);
        my_strcat(maze->stock_room, "\n");
    }
    for (int i = count + 1; tab[i] != NULL; i++) {
        my_strcat(maze->stock_tunnel, tab[i]);
        my_strcat(maze->stock_tunnel, "\n");
    }
}

char **file_to_tab(char **tab, maze_t *maze)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *buffer = malloc(sizeof(char) * 1024);

    buffer[0] = '\0';
    read = getline(&line, &len, stdin);
    while (read != -1) {
        for (int i = 0; line[i] != '\0'; i++)
            rm_comment(line, i);
        buffer = my_strcat(buffer, line);
        read = getline(&line, &len, stdin);
    }
    tab = my_str_to_array(buffer, "\n");
    free(buffer);
    stock_room_tunnel(tab, maze);
    free(line);
    return tab;
}

void find_pos(char **tab, maze_t *maze)
{
    char **tab_pos = NULL;

    for (int i = 0; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], "##start") == 0) {
            tab_pos = my_str_to_array(tab[i + 1], " ");
            maze->start = my_getnbr(tab_pos[0]);
        }
        if (my_strcmp(tab[i], "##end") == 0) {
            tab_pos = my_str_to_array(tab[i + 1], " ");
            maze->end = my_getnbr(tab_pos[0]);
        }
    }
    for (int i = 0; tab_pos[i] != NULL; i++)
        free(tab_pos[i]);
    free(tab_pos);
}

void free_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}

static void free_maze(maze_t *maze)
{
    tunnel_t *tmp = maze->tunnels;

    while (tmp != NULL) {
        tmp = maze->tunnels->next;
        free(maze->tunnels);
        maze->tunnels = tmp;
    }
    free(maze->stock_room);
    free(maze->stock_tunnel);
    free(maze);
}

int main(int ac, char **av)
{
    maze_t *maze = malloc(sizeof(maze_t));
    tunnel_t *tmp;
    char **tab = file_to_tab(tab, maze);

    if (check_error(tab, maze) == 84)
        return 84;
    find_pos(tab, maze);
    parsing_edge(my_str_to_array(maze->stock_tunnel, "\n"), maze);
    find_path(maze->tunnels, maze);
    free_tab(tab);
    free_maze(maze);
    return 0;
}
