/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** send sig
*/

#include "my.h"

int my_in(char c, char *str)
{
    for (int i = 0; str[i]; i++)
        if (c == str[i])
            return 1;
    return 0;
}

void send_value(char *coord)
{
    for (int i = 0; i != coord[0] - 'A'; i++) {
        kill(navy->pid_ad, SIGUSR1);
        usleep(10);
    }
    kill(navy->pid_ad, SIGUSR2);
    for (int j = 0; j != coord[1] - '0'; j++) {
        kill(navy->pid_ad, SIGUSR1);
        usleep(10);
    }
    kill(navy->pid_ad, SIGUSR2);
}

char *get_send_line(void)
{
    size_t n = 1024;
    char *buffer;
    char lettre[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    char nombre[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};

    while (1) {
        buffer = malloc(n);
        my_printf("attack: ");
        getline(&buffer, &n, stdin);
        if (my_in(buffer[0], lettre) && my_in(buffer[1], nombre))
            break;
        free(buffer);
        my_printf("wrong position\n");
    }
    send_value(buffer);
    return buffer;
}

char *is_touch(char *coord)
{
    if (navy->is_hit == 1)
        navy->map_ad[coord[1] - '0' - 1][coord[0] - 'A'] = 'x';
    if (navy->map_ad[coord[1] - '0' - 1][coord[0] - 'A'] != 'x')
        navy->map_ad[coord[1] - '0' - 1][coord[0] - 'A'] = 'o';
    return navy->is_hit == 1 ? "hit\n" : "missed\n";
}
