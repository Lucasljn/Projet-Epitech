/*
** EPITECH PROJECT, 2024
** Robot Factory
** File description:
** main.c
*/

#include "op.h"
#include "my.h"

static int flag_h(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        my_printf("USAGE\n./asm file_name[.s]\nDESCRIPTION\nfile_name file");
        my_printf(" in assembly language to be converted into file_name.cor,");
        my_printf(" an executable in the Virtual Machine.\n");
        return 0;
    }
    return 1;
}

int conv(int nb)
{
    int x = nb;

    x = (((x >> 24) & 0xff) | ((x << 8) & 0xff0000) |
    ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000));
    return x;
}

int is_num(char *c)
{
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] < '0' || c[i] > '9')
            return 84;
    }
    return 0;
}

static int calcul_prog3(char *param, op_t *op, int prog_size, int exception)
{
    if (str_is_num(param) == 0)
        prog_size += 2;
    if (param[0] == 'r')
        prog_size += 1;
    if (param[0] == '%') {
        exception = label_exception(exception, param);
        prog_size += exception;
    }
    return prog_size;
}

int calcul_prog2(char **tab, op_t *op, int j, int exception)
{
    int prog_size = 0;

    if (my_strcmp(tab[j], op->mnemonique) == 0) {
        prog_size++;
        if (my_strcmp(tab[j], "zjmp") != 0 && my_strcmp(tab[j],
            "live") != 0 && my_strcmp(tab[j], "fork") != 0 &&
                my_strcmp(tab[j], "lfork") != 0)
            prog_size++;
        for (int param = 0; param != op->nbr_args; param++) {
            prog_size = calcul_prog3(tab[param + j + 1], op,
                prog_size, exception);
        }
    }
    return prog_size;
}

int calcul_prog(char **tab, op_t *op)
{
    int exception = 4;
    char *excepte[] = {"zjmp", "ldi", "sti", "fork", "lldi", "lfork", 0};
    int prog_size = 0;

    for (int j = 0; tab[j] != 0; j++) {
        for (op = op_tab; op->mnemonique != 0; op++) {
            prog_size = calcul_prog2(tab, op, j, exception);
        }
        j += op->nbr_args;
    }
    return prog_size;
}

static int main2(int j, char **tab, op_t *op, int fd)
{
    char *code_str = malloc(sizeof(char) * 10);

    if (my_strcmp(tab[j], op->mnemonique) == 0) {
        write(fd, &op->code, 1);
        if (op->nbr_args != 1) {
            write(fd, coding_byte(tab, op, j), 1);
        }
        cod_param(tab, op, j, fd);
        j += op->nbr_args;
    }
}

static void call_main2(header_t *header, char **tab, op_t *op, int fd)
{
    header->prog_size = conv(calcul_prog(tab, op));
    write(fd, header, sizeof(header_t));
    for (int j = 0; tab[j] != 0; j++) {
        for (op = op_tab; op->mnemonique != 0; op++)
            main2(j, tab, op, fd);
    }
}

int main(int argc, char *argv[])
{
    header_t *header = malloc(sizeof(header_t));
    op_t *op = malloc(sizeof(op_t));
    char *buffer = fs_open_file(argv[1], buffer);
    int fd = name_file(argc, argv, fd);
    char **header_tab;
    char **tab;

    if (flag_h(argc, argv) == 0)
        return 0;
    if (fd == 84)
        return 84;
    header_tab = my_str_to_word_array(buffer, '"');
    tab = my_str_to_array(header_tab[4], " .,\t\n\"");
    if (parsing_header(header, buffer, header_tab) == 84)
        return 84;
    call_main2(header, tab, op, fd);
    close(fd);
    return 0;
}
