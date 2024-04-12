/*
** EPITECH PROJECT, 2023
** Robot Factory
** File description:
** label.c
*/

#include "my.h"
#include "op.h"

char *create_name_label(char *full_name)
{
    char *name = malloc(sizeof(char) * my_strlen(full_name));
    int follow = 0;

    for (int j = 2; full_name[j] != '\0'; j++) {
        name[follow] = full_name[j];
        follow++;
    }
    name[follow] = '\0';
    return name;
}

static int upgrade_i(op_t *op, int i)
{
    i += op->nbr_args;
    return i;
}

int jump_byte2(char **tab, op_t *op, int nb_byte, int i)
{
    if (my_strcmp(tab[i], op->mnemonique) == 0) {
        if (op->nbr_args != 1)
            nb_byte++;
        nb_byte = label_param(tab, op, i, nb_byte);
    }
}

static int jump_byte3(int i_bis, op_t *op, char **tab, int nb_byte)
{
    for (op = op_tab; op->mnemonique != 0; op++) {
        if (my_strcmp(tab[i_bis], op->mnemonique) == 0)
            nb_byte = label_param(tab, op, i_bis, nb_byte);
        if (my_strcmp(tab[i_bis], op->mnemonique) == 0 && my_strcmp(tab[i_bis]
            , "zjmp") != 0 && my_strcmp(tab[i_bis],
                "live") != 0 && my_strcmp(tab[i_bis], "fork") != 0 &&
                    my_strcmp(tab[i_bis], "lfork") != 0)
            nb_byte++;
    }
    return nb_byte;
}

static int condi_byte_code(int nb_byte, char **tab, int i)
{
    if (my_strcmp(tab[i], "zjmp") != 0 && my_strcmp(tab[i],
        "live") != 0 && my_strcmp(tab[i], "fork") != 0 &&
            my_strcmp(tab[i], "lfork") != 0)
        nb_byte++;
    return nb_byte;
}

int jump_byte(char **tab, int i, op_t *op, char *name)
{
    int nb_byte = 1;
    int i_bis = i;

    for (; tab[i] != 0; i++) {
        if (my_strcmp(tab[i], my_strcat(name, ":")) == 0)
            return nb_byte;
        if (tab[i][my_strlen(tab[i]) - 1] == ':')
            i += 1;
        for (op = op_tab; my_strcmp(tab[i], op->mnemonique) != 0; op++);
        nb_byte = condi_byte_code(nb_byte, tab, i);
        nb_byte = label_param(tab, op, i, nb_byte);
        i = i + op->nbr_args;
    }
    nb_byte = 0;
    for (; tab[i_bis] != 0; i_bis--) {
        if (my_strcmp(tab[i_bis], my_strcat(name, ":")) == 0)
            return nb_byte * -1;
        nb_byte = jump_byte3(i_bis, op, tab, nb_byte);
    }
}

int label_exception(int exception, char *param)
{
    char *excepte[] = {"zjmp", "ldi", "sti", "fork", "lldi", "lfork", 0};

    for (int exe = 0; excepte[exe] != 0; exe++) {
        if (my_strcmp(excepte[exe], param) == 0)
            return 2;
    }
    return 4;
}

int label_param(char **tab, op_t *op, int i, int nb_byte)
{
    char *param_hexa;
    char *excepte[] = {"zjmp", "ldi", "sti", "fork", "lldi", "lfork", 0};
    int exception = 4;

    for (int param = 0; param != op->nbr_args; param++) {
        if (str_is_num(tab[param + i + 1]) == 0)
            nb_byte += 2;
        if (tab[param + i + 1][0] == 'r')
            nb_byte += 1;
        if (tab[param + i + 1][0] == '%') {
            exception = label_exception(exception, tab[i]);
            nb_byte += exception;
        }
    }
    return nb_byte;
}
