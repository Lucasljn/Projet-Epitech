/*
** EPITECH PROJECT, 2023
** projects
** File description:
** openfile.c
*/

#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ncurses.h>

int file_len(char const *filename)
{
    int fd;
    struct stat *docu;

    docu = (struct stat *) malloc(sizeof(struct stat));
    fd = stat(filename, docu);
    return docu->st_size;
}

char *fs_open_file(char const *filepath)
{
    int fd;
    char buff[file_len(filepath)];
    char *str = malloc(sizeof(char) * (file_len(filepath) + 1));
    int off = 0;
    int len = 0;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        exit(84);
    len = read(fd, buff, file_len(filepath));
    while (len > 0) {
        off += len;
        str = my_strcat(str, buff);
        len = read(fd, buff, file_len(filepath));
    }
    close(fd);
    str[off] = '\0';
    return str;
}

char **columsquare(char **square, char *str)
{
    int tempo = 0;
    int j = 0;
    int colum = 0;

    while (str[tempo] != '\0') {
        if (str[tempo] != '\n')
            colum++;
        if (str[tempo] == '\n') {
            square[j] = malloc(sizeof(char) * (colum + 2));
            j++;
            colum = 0;
        }
        tempo++;
    }
    return square;
}

char **str_to_square(char *str)
{
    int line = 0;
    int tempo = 0;
    char **square;

    while (str[tempo] != '\0') {
        if (str[tempo] == '\n')
            line = line + 1;
        tempo++;
    }
    square = malloc(sizeof(char *) * (line + 1));
    columsquare(square, str);
    square[line] = 0;
    return square;
}

char **display_square(char *str, char **square)
{
    int line = 0;
    int colum = 0;
    char tmp;

    error_map(str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n'){
            square[line][colum] = '\n';
            square[line][colum + 1] = '\0';
            line++;
            colum = 0;
        } else {
            tmp = str[i];
            square[line][colum] = tmp;
            colum++;
        }
    }
    square[line] = 0;
    return square;
}
