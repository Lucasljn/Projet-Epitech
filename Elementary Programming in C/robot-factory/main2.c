/*
** EPITECH PROJECT, 2023
** B2
** File description:
** main.c
*/

#include "op.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char *add_byte(char **tab, int i, char *byte)
{
    int len = my_strlen(byte);

    if (tab[i][0] == 'r') {
        byte[len] = '0';
        byte[len + 1] = '1';
        byte[len + 2] = '\0';
        return byte;
    }
    if (tab[i][0] == '%') {
        byte[len] = '1';
        byte[len + 1] = '0';
        byte[len + 2] = '\0';
        return byte;
    }
    if (str_is_num(tab[i]) == 0) {
        byte[len] = '1';
        byte[len + 1] = '1';
        byte[len + 2] = '\0';
        return byte;
    }
}

int binaire_to_decimal(char *chaine_binaire)
{
    int resultat = 0;
    int puissance = 1;

    for (int i = my_strlen(chaine_binaire) - 1; i >= 0; i--) {
        resultat += (chaine_binaire[i] - '0') * puissance;
        puissance *= 2;
    }
    return resultat;
}

static int len_hexa(long nbr2)
{
    int i = 0;

    while (nbr2 != 0) {
        nbr2 = nbr2 / 16;
        i++;
    }
    return i;
}

char *coding_byte(char **tab, op_t *op, int i)
{
    char *cod_in_byte = malloc(sizeof(char) * 9);
    char *hexa = malloc(sizeof(char) * 2);
    char *param;

    cod_in_byte[0] = '\0';
    for (int com = 0; com != op->nbr_args; com++)
        cod_in_byte = add_byte(tab, com + i + 1, cod_in_byte);
    while (my_strlen(cod_in_byte) != 8)
        cod_in_byte[my_strlen(cod_in_byte)] = '0';
    cod_in_byte[8] = '\0';
    hexa[0] = binaire_to_decimal(cod_in_byte);
    return hexa;
}

static void cod_param3(char **tab, int i, int param, int fd)
{
    char *param_hexa = malloc(sizeof(char) * 2);
    int tmp = 0;

    if (str_is_num(tab[param + i + 1]) == 0) {
        tmp = my_getnbr(tab[param + i + 1]);
        tmp = conv(tmp);
        write(fd, &tmp, 2);
    }
}

int exception_byte(char **excepte, char **tab, int i)
{
    for (int exe = 0; excepte[exe] != 0; exe++) {
        if (my_strcmp(excepte[exe], tab[i]) == 0)
            return 2;
    }
    return 4;
}

static int cod_param2(int exception, int nb, int fd)
{
    char *param_hexa = malloc(sizeof(char) * 2);

    nb = conv(nb);
    if (exception == 2)
        nb = nb >> 16;
    write(fd, &nb, exception);
}

static void cod_param4(int exception, char **tab, int i, int fd)
{
    op_t *op = op_tab;
    int nb_byte = 0;

    nb_byte = jump_byte(tab, i, op,
        create_name_label(tab[exception + i + 1]));
    nb_byte = conv(nb_byte);
    exception = label_exception(exception, tab[i]);
    if (exception == 2)
        nb_byte = nb_byte >> 16;
    write(fd, &nb_byte, exception);
}

char *cod_param(char **tab, op_t *op, int i, int fd)
{
    int nb = 0;
    char *excepte[] = {"zjmp", "ldi", "sti", "fork", "lldi", "lfork", 0};
    int exception = exception_byte(excepte, tab, i);
    char *label = malloc(sizeof(char) * 2);

    for (int param = 0; param != op->nbr_args; param++) {
        for (int j = 1; tab[param + i + 1][j] != '\0'; j++)
            nb = nb * 10 + tab[param + i + 1][j] - '0';
        cod_param3(tab, i, param, fd);
        if (tab[param + i + 1][0] == 'r')
            write(fd, &nb, 1);
        if (tab[param + i + 1][0] == '%' && tab[param + i + 1][1] != ':') {
            exception = exception_byte(excepte, tab, i);
            cod_param2(exception, nb, fd);
        }
        if (tab[param + i + 1][0] == '%' && tab[param + i + 1][1] == ':') {
            cod_param4(param, tab, i, fd);
        }
        nb = 0;
    }
}
