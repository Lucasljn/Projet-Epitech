/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** algo_find.c
*/

#include "../include/maze.h"

tunnel_t *find_start(tunnel_t *tunnels, int start)
{
    tunnel_t *tmp = tunnels;

    while (tmp != NULL) {
        if (tmp->nb == start) {
            return tmp;
        }
        tmp = tmp->next;
    }
}

int find_all_paths2(tunnel_t *start, int i, tunnel_t *all, path_t *path)
{
    tunnel_t *neighbor = find_start(all, start->link[i]);

    for (int j = 0; j < path->path_len; j++) {
        if (path->path[j] == neighbor->nb) {
            return 1;
        }
    }
    return 0;
}

void find_all_paths(tunnel_t *start, tunnel_t *end, path_t *path,
    tunnel_t *all)
{
    tunnel_t *neighbor;

    if (start->nb == end->nb) {
        for (int i = 0; i < path->path_len; i++) {
            path->all_path[path->num_path][i] = path->path[i];
        }
        path->all_path[path->num_path][path->path_len] = end->nb;
        path->all_path[path->num_path][path->path_len + 1] = -1;
        path->num_path++;
        return;
    }
    for (int i = 0; i < len_int(start->link); i++) {
        neighbor = find_start(all, start->link[i]);
        if (!find_all_paths2(start, i, all, path)) {
            path->path[path->path_len] = start->nb;
            path->path_len++;
            find_all_paths(neighbor, end, path, all);
            path->path_len--;
        }
    }
}

static void free_path(path_t *path)
{
    for (int i = 0; i < 100; i++)
        free(path->all_path[i]);
    free(path->all_path);
    free(path->path);
    free(path);
}

void find_path(tunnel_t *tunnels, maze_t *maze)
{
    path_t *path = malloc(sizeof(path_t));
    tunnel_t *start = find_start(tunnels, maze->start);
    tunnel_t *end = find_start(tunnels, maze->end);

    path->all_path = malloc(100 * sizeof(int *));
    for (int i = 0; i < 100; i++)
        path->all_path[i] = malloc((100 + 1) * sizeof(int));
    path->path = malloc((100 + 1) * sizeof(int));
    path->num_path = 0;
    path->path_len = 0;
    find_all_paths(start, end, path, tunnels);
    sort_path(path);
    mouvement_robots(path, maze);
    free_path(path);
}
