/*
** EPITECH PROJECT, 2023
** B2
** File description:
** exit.c
*/

#include "my.h"

char *give_commande(int exit_status)
{
    char *commande = NULL;
    size_t len = 0;
    ssize_t read;
    char **tab;

    if (isatty(STDIN_FILENO) == 1)
        my_putstr("$> ");
    read = getline(&commande, &len, stdin);
    if (read == -1)
        exit(0);
    if (commande[read - 1] == '\n')
        commande[read - 1] = '\0';
    return commande;
}

static int my_str_is_num(char *str)
{
    for (int i; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return 1;
    }
    return 0;
}

static int minmax(long nbr, int signe)
{
    if (-2147483648 > nbr) {
        return 0;
    }
    if (2147483647 < nbr) {
        return 0;
    }
    return ((int)(nbr * signe));
}

int signe1(char i, int signe)
{
    if (i == '-') {
        signe = signe * -1;
    }
    return signe;
}

int my_getnbr(char *str)
{
    int signe = 1;
    int i = 0;
    long getnbr = 0;
    int signe3 = 1;

    while (str[i] == '-' || str[i] == '+'){
        signe3 = signe1(str[i], signe);
        i++;
    }
    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57) {
            getnbr = getnbr * 10;
            getnbr = getnbr + str[i] - 48;
            i = i + 1;
        } else {
            return (getnbr * signe3);
        }
    }
    return minmax(getnbr, signe3);
}

int command_not_found(environnement_t *elm, char **com_pipe, int i)
{
    char **com = my_str_to_array(com_pipe[i], " \t");

    if (access(found_bincom(elm, my_str_to_array(com_pipe[i], " \t")),
        F_OK) != 0 && my_strcmp(found_bincom(elm, my_str_to_array(com_pipe[i],
            " \t")), "exit") != 0) {
        my_printf("%s: Command not found.\n", com[0]);
        i++;
    }
    return i;
}

int choose_exit(char **tab)
{
    int exit = 0;
    int i = 0;

    if (tab == NULL)
        return 1;
    while (tab[i] != 0) {
        if (my_strcmp(tab[i], "exit") == 0) {
            exit = 1;
            break;
        }
        i++;
    }
    if (exit != 1)
        return 1;
    if (tab[i + 1] == NULL)
        return 0;
    if (my_str_is_num(tab[i + 1]) == 0)
        return my_getnbr(tab[i + 1]);
}
