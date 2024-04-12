/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** parsing_edge.c
*/

#include "../include/maze.h"

int is_edge(char *tab)
{
    for (int j = 0; tab[j] != '\0'; j++) {
        if (tab[j] == '-')
            return 1;
    }
    return 0;
}

int len_int(int *link)
{
    int i = 0;

    while (link[i] >= 0) {
        i++;
    }
    return i;
}

void add_new_node(int edge_nb, int edge_exit, maze_t *maze)
{
    tunnel_t *new_edge = malloc(sizeof(tunnel_t));

    new_edge->nb = edge_nb;
    new_edge->link = malloc(sizeof(int) * 200);
    new_edge->link[0] = edge_exit;
    new_edge->link[1] = -1;
    new_edge->is_taken = 0;
    if (maze->tunnels == NULL)
        new_edge->next = NULL;
    else
        new_edge->next = maze->tunnels;
    maze->tunnels = new_edge;
}

void create_edge(char *str, maze_t *maze, int a, int b)
{
    char **tab = my_str_to_array(str, "-");
    int edge_nb = my_getnbr(tab[a]);
    int edge_exit = my_getnbr(tab[b]);
    tunnel_t *tmp = maze->tunnels;
    int len_i;

    while (tmp != NULL) {
        if (edge_nb == tmp->nb) {
            len_i = len_int(tmp->link);
            tmp->link[len_i] = edge_exit;
            tmp->link[len_i + 1] = -1;
            return;
        }
        tmp = tmp->next;
    }
    add_new_node(edge_nb, edge_exit, maze);
    free_tab(tab);
}

void parsing_edge(char **tab, maze_t *maze)
{
    maze->tunnels = NULL;
    for (int i = 0; tab[i] != NULL; i++) {
        if (is_edge(tab[i])) {
            create_edge(tab[i], maze, 0, 1);
            create_edge(tab[i], maze, 1, 0);
        }
    }
}
