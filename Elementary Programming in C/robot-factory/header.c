/*
** EPITECH PROJECT, 2024
** Robot Factory
** File description:
** header.c
*/

#include "op.h"
#include "my.h"

int verif_header(char *buffer, char **clean)
{
    int count_n = 0;
    int count_c = 0;

    for (int i = 0; i < my_strlen(buffer); i++) {
        if (buffer[i] == '.' && buffer[i + 1] == 'n' && buffer[i + 5] == ' ')
            count_n += 1;
        if (buffer[i] == '.' && buffer[i + 1] == 'c' && buffer[i + 8] == ' ')
            count_c += 1;
    }
    if (count_n != 1 || count_c != 1 || my_strcmp(clean[0], ".name") != 0)
        return 84;
}

int error_header(header_t *header, char *buffer)
{
    char **clean = my_str_to_array(buffer, " \t\n");
    char **buffer_line = my_str_to_array(buffer, "\n");

    if (verif_header(buffer, clean) == 84)
        return 84;
    for (int c = 0; buffer_line[1][c] != '\0'; c++) {
        if (buffer_line[1][c] == '.')
            break;
        if (buffer_line[1][c + 1] == '\0')
            return 84;
    }
    if (my_strlen(header->prog_name) > PROG_NAME_LENGTH
        || my_strlen(header->comment) > COMMENT_LENGTH)
            return 84;
    return 0;
}

int parsing_header(header_t *header, char *buffer, char **header_tab)
{
    int ind = 0;

    if (error_header(header, buffer) == 84)
        return 84;
    header->magic = conv(COREWAR_EXEC_MAGIC);
    for (int i = 0; header_tab[1][i] != '\0'; i++) {
        header->prog_name[ind] = header_tab[1][i];
        ind++;
    }
    header->prog_name[ind] = '\0';
    header->prog_name[PROG_NAME_LENGTH - 1] = '\0';
    ind = 0;
    for (int i = 0; header_tab[3][i] != '\0'; i++) {
        header->comment[ind] = header_tab[3][i];
        ind++;
    }
    header->comment[ind] = '\0';
    header->comment[COMMENT_LENGTH - 1] = '\0';
    return 0;
}
