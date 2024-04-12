/*
** EPITECH PROJECT, 2023
** B-CPE-110-NCE-1-1-settingup-lucas.lejeune
** File description:
** bootstrap.c
*/

#include "my.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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

char **str_to_square(char *str)
{
    int line = 0;
    char **square;
    int colum = 0;
    int tempo = destroyfirstrow(str);

    while (str[tempo] != '\0') {
        if (str[tempo] == '\n')
            line = line + 1;
        if (line == 0)
            colum = colum + 1;
        tempo++;
    }
    square = malloc(sizeof(char *) * (line + 1));
    for (int j = 0; j < line; j++) {
        square[j] = malloc(sizeof(char) * (colum + 1));
    }
    square[line] = 0;
    return square;
}

char **display_square(char *str, char **square)
{
    int line = 0;
    int colum = 0;
    int firstline = destroyfirstrow(str);
    char tmp;

    for (int i = firstline; str[i] != '\0'; i++) {
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

int main(int argc, char **argv)
{
    char *filename;
    char *buff;
    char **square;

    error(argc, argv);
    if (argc == 3) {
        filename = generatormap(argv[1], argv[2]);
    } else {
        filename = argv[1];
    }
    buff = fs_open_file(filename);
    square = display_square(buff, str_to_square(buff));
    errorrow(buff, square);
    findmaxsquare(square);
    for (int display = 0; square[display] != 0; display++) {
        mini_printf("%s", square[display]);
    }
    free(buff);
    return 0;
}
