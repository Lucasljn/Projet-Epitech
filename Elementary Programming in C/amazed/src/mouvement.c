/*
** EPITECH PROJECT, 2023
** delivery
** File description:
** mouvement.c
*/

#include "../include/maze.h"

void int_to_str(int num, maze_t *maze)
{
    int digits = 0;
    char *str;
    int temp = num;

    if (num == 0) {
        maze->line = my_strcat(maze->line, "0");
        return;
    }
    while (temp > 0) {
        temp /= 10;
        digits++;
    }
    str = malloc((digits + 1) * sizeof(char));
    str[digits] = '\0';
    for (int i = digits - 1; i >= 0; i--) {
        str[i] = '0' + num % 10;
        num /= 10;
    }
    maze->line = my_strcat(maze->line, str);
    free(str);
}

static void print_mouv(robot_t *robot, maze_t *maze)
{
    my_strcat(maze->line, "P");
    int_to_str(robot->id, maze);
    my_strcat(maze->line, "-");
    int_to_str(robot->current_room->nb, maze);
    my_strcat(maze->line, " ");
}

robot_t *create_robots(tunnel_t *current, maze_t *maze)
{
    robot_t *new_robots = malloc(sizeof(robot_t));
    robot_t *tmp = maze->robots;

    new_robots->current_room = current;
    new_robots->id = maze->count;
    new_robots->nb_way = 2;
    new_robots->next = NULL;
    if (tmp == NULL) {
        print_mouv(new_robots, maze);
        return new_robots;
    }
    while (tmp != NULL) {
        if (tmp->next == NULL) {
            tmp->next = new_robots;
            break;
        }
        tmp = tmp->next;
    }
    print_mouv(new_robots, maze);
    return maze->robots;
}

robot_t *add_start_robots(maze_t *maze, path_t *path, int init_robot)
{
    tunnel_t *current;

    for (int i = 0; i < path->num_path && maze->count <= init_robot; i++) {
        current = find_start(maze->tunnels, path->all_path[i][1]);
        if (current->is_taken == 0) {
            current->is_taken = 1;
            maze->robots = create_robots(current, maze);
            maze->count += 1;
            maze->del = 0;
        }
    }
    return maze->robots;
}

static robot_t *is_del(path_t *path, maze_t *maze, robot_t *tmp,
    robot_t *previous)
{
    print_mouv(tmp, maze);
    if (tmp->current_room->nb == maze->end) {
        maze->del = 1;
        find_start(maze->tunnels, tmp->current_room->nb)->is_taken = 0;
        maze->nb_robot -= 1;
        return maze->robots->next;
    }
    return maze->robots;
}

static void change_pos(robot_t *tmp, maze_t *maze, path_t *path,
    robot_t *previous)
{
    tunnel_t *tu = maze->tunnels;
    tunnel_t *search;
    tunnel_t *next;

    for (int i = 0; i < path->num_path; i++) {
        if (tmp->current_room->nb == find_start(tu, path->all_path[i]
            [tmp->nb_way - 1])->nb && !find_start(tu, path->all_path[i]
            [tmp->nb_way])->is_taken) {
            next = find_start(maze->tunnels, path->all_path[i][tmp->nb_way]);
            find_start(maze->tunnels, tmp->current_room->nb)->is_taken = 0;
            tmp->current_room = next;
            next->is_taken = 1;
            tmp->nb_way += 1;
            maze->robots = is_del(path, maze, tmp, previous);
            return;
        }
    }
}

robot_t *mouv_robot(maze_t *maze, path_t *path)
{
    robot_t *tmp = maze->robots;
    robot_t *previous = NULL;

    while (tmp != NULL) {
        change_pos(tmp, maze, path, previous);
        previous = tmp;
        tmp = tmp->next;
    }
    return maze->robots;
}

void mouvement_robots(path_t *path, maze_t *maze)
{
    int nb_robot_init = maze->nb_robot;

    maze->count = 1;
    maze->robots = NULL;
    maze->line = malloc(sizeof(char) * 1000);
    while (maze->nb_robot != 0) {
        maze->del = 0;
        maze->line[0] = '\0';
        maze->robots = mouv_robot(maze, path);
        maze->robots = add_start_robots(maze, path, nb_robot_init);
        maze->line[my_strlen(maze->line) - 1] = '\n';
        my_printf("%s", maze->line);
    }
    free(maze->line);
}
