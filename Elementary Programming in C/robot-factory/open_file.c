/*
** EPITECH PROJECT, 2024
** Robot Factory
** File description:
** open_file.c
*/

#include "op.h"
#include "my.h"

int file_len(char const *filename)
{
    int fd;
    struct stat *docu;

    docu = (struct stat *) malloc(sizeof(struct stat));
    fd = stat(filename, docu);
    return docu->st_size;
}

char *fs_open_file(char const *filepath, char *str)
{
    int fd;
    int size;
    char *buffer;
    int i = 0;

    size = file_len(filepath);
    buffer = malloc(sizeof(char) * (size + 1));
    fd = open(filepath, O_RDONLY);
    read(fd, buffer, size);
    buffer[size] = '\0';
    return buffer;
}

int name_file(int argc, char **argv, int fd)
{
    if (argc != 2 || my_strlen(argv[1]) < 3
        || my_strcmp(argv[1] + my_strlen(argv[1]) - 2, ".s") != 0)
            return 84;
    for (int i = 0; argv[1][i] != '\0'; i++) {
        if (argv[1][i] == '.')
            argv[1][i] = '\0';
    }
    fd = open(my_strcat(argv[1], ".cor"), O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
        return 84;
    return fd;
}
