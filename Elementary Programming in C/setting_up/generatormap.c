/*
** EPITECH PROJECT, 2023
** projects
** File description:
** generatormap.c
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int writeorrettun(char *patern, int fd, int tmp, int len)
{
    if (tmp == len) {
        write(fd, &patern[tmp], 1);
        tmp = 0;
    } else {
        write(fd, &patern[tmp], 1);
        tmp++;
    }
    return tmp;
}

void writesize(char *size, int fd, char backn)
{
    for (int i = 0; size[i] != '\0'; i++) {
        write(fd, &size[i], 1);
    }
    write(fd, &backn, 1);
}

char *generatormap(char *size, char *patern)
{
    int len = my_strlen(patern) - 1;
    int fd;
    int tmp = 0;
    int size1 = my_getnbr(size);
    char backn = '\n';
    char *path = "mapgenerate.txt";

    fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 00777);
    writesize(size, fd, backn);
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size1; j++){
            tmp = writeorrettun(patern, fd, tmp, len);
        }
        write(fd, &backn, 1);
    }
    close(fd);
    return path;
}
