/*
** EPITECH PROJECT, 2023
** Amazed
** File description:
** Robustness
*/

#include "../include/maze.h"

static int is_num(char str)
{
    if (str >= '0' && str <= '9')
        return 0;
    return 84;
}

int valid_room(char *str)
{
    char **tab = my_str_to_array(str, " ");
    int count = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        count++;
        if (is_num(tab[i][0]) == 84)
            return 84;
    }
    if (count != 3)
        return 84;
    return 0;
}

int valid_tunnel(char *str)
{
    char **tab = my_str_to_array(str, "\n");
    char **tab2 = NULL;
    int j = 0;

    for (int i = 0; tab[i] != NULL; i++) {
        tab2 = my_str_to_array(tab[i], "-");
        for (j; tab2[j] != NULL; j++);
        if (j != 2 || is_num(tab2[0][0]) == 84 || is_num(tab2[1][0]) == 84)
            return 84;
        j = 0;
    }
    return 0;
}

int verif_start_end(char **tab_room)
{
    int count = 0;
    int count2 = 0;
    int s = 0;
    int e = 0;

    for (int i = 0; tab_room[i] != NULL; i++) {
        if (my_strcmp(tab_room[i], "##start") == 0) {
            s = i;
            count++;
        }
        if (my_strcmp(tab_room[i], "##end") == 0) {
            e = i;
            count2++;
        }
    }
    if (count != 1 || count2 != 1 || (is_num(tab_room[s + 1][0]) == 84)
        || valid_room(tab_room[s + 1]) == 84 || (is_num(tab_room[e + 1][0])
            == 84) || valid_room(tab_room[e + 1]) == 84) {
        return 84;
    }
}

static int count_room_tunnel(char **tab, int i)
{
    static int nbr_room = 0;
    static int nbr_pipe = 0;

    for (int j = 0; tab[i][j] != '\0'; j++) {
        if (tab[i][j] == '-')
            nbr_pipe++;
        if (tab[i][j] == ' ')
            nbr_room++;
    }
    if (nbr_pipe == 0 || nbr_room % 2 != 0)
        return 84;
    return 0;
}

static int tunnel_is_valid(char **tab, maze_t *maze)
{
    char **tab2 = my_str_to_array(maze->stock_tunnel, "\n-");
    int count = 0;

    for (int i = 0; tab2[i] != NULL; i++) {
        if (my_strcmp(tab[0], tab2[i]) == 0) {
            count++;
            break;
        }
    }
    if (count == 0)
        return 84;
    return 0;
}

static int multiple_room2(int i, int count, char **tab_room, char **tab)
{
    char **tab2 = NULL;

    for (int j = i + 1; j < count; j++) {
        tab2 = my_str_to_array(tab_room[j], " ##startend");
        if (tab2[0] != NULL && my_strcmp(tab[0], tab2[0]) == 0
            || tab2[0] != NULL && (my_strcmp(tab[1], tab2[1]) == 0
                && my_strcmp(tab[2], tab2[2]) == 0))
            return 84;
    }
    return 0;
}

int multiple_room_with_same(char **tab_room, maze_t *maze)
{
    char **tab = NULL;
    int count = 0;

    for (int i = 0; maze->stock_room[i] != '\0'; i++) {
        if (maze->stock_room[i] == '\n')
            count++;
    }
    for (int i = 0; i < count; i++) {
        tab = my_str_to_array(tab_room[i], " ##startend");
        if (tab[0] != NULL && multiple_room2(i, count, tab_room, tab) == 84
            || tab[0] != NULL && tunnel_is_valid(tab, maze) == 84)
            return 84;
    }
    return 0;
}

int check_error(char **tab, maze_t *maze)
{
    char **tab_room = my_str_to_array(maze->stock_room, "\n");

    if (tab[0] == NULL || is_num(tab[0][0]) == 84 || my_getnbr(tab[0]) < 1)
        return 84;
    maze->nb_robot = my_getnbr(tab[0]);
    if (verif_start_end(tab_room) == 84)
        return 84;
    for (int i = 1; tab[i] != NULL; i++) {
        if (count_room_tunnel(tab, i) == 84 && tab[i + 1] == NULL)
            return 84;
    }
    if (valid_tunnel(maze->stock_tunnel) == 84)
        return 84;
    if (multiple_room_with_same(tab_room, maze) == 84)
        return 84;
    my_printf("#number_of_robots\n%d\n#rooms\n%s#tunnels\n%s#moves\n",
        maze->nb_robot, maze->stock_room, maze->stock_tunnel);
    return 0;
}
