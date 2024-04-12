/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** player 1, 2
*/

#include "my.h"

void loop_p1(void)
{
    char *buff;

    reset();
    show_all();
    buff = get_send_line();
    wait_response();
    my_printf("result: %c%c:%s", buff[0], buff[1], is_touch(buff));
    my_printf("waiting for enemy's attack...\n");
    reset();
    wait_reception();
    my_printf("result: %s:", navy->coord);
    edit_map();
    navy->is_next = 0;
    navy->index_coord = 0;
}

int player1(char *filepath)
{
    set_boat(load_file(filepath));
    my_printf("my_pid: %d\nwaiting for enemy...", getpid());
    wait_start();
    my_printf("enemy connected\n");
    while (left(1) != 0 && left(2) != 0)
        loop_p1();
    show_all();
    return 0;
}

void loop_p2(void)
{
    char *coord;

    reset();
    show_all();
    my_printf("waiting for enemy's attack...\n");
    wait_reception();
    my_printf("result: %s:", navy->coord);
    edit_map();
    navy->is_next = 0;
    navy->index_coord = 0;
    reset();
    coord = get_send_line();
    wait_response();
    my_printf("result: %c%c:%s", coord[0], coord[1], is_touch(coord));
}

int player2(char *filepath, char *pid)
{
    set_boat(load_file(filepath));
    navy->pid_ad = my_getnbr(pid);
    if (kill(navy->pid_ad, SIGUSR1) == -1)
        return 84;
    my_printf("my_pid: %d\nsuccessfully connected to enemy\n", getpid());
    while (left(1) != 0 && left(2) != 0)
        loop_p2();
    show_all();
    return 0;
}
