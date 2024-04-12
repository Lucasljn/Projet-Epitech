/*
** EPITECH PROJECT, 2023
** projects
** File description:
** openandmap.c
*/

#include "my.h"

char *fs_open_file(char const *filepath, char *str)
{
    int fd;
    char buff[40];
    int off = 0;
    int len = 0;

    str = malloc(sizeof(char) * 40 + 1);
    str[0] = '\0';
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return NULL;
    len = read(fd, buff, 40);
    while (len > 0) {
        off += len;
        str = my_strcat(str, buff);
        len = read(fd, buff, 40);
    }
    close(fd);
    str[off] = '\0';
    return str;
}

static int erreur(char *square)
{
    if (square[0] != '2' && square[0] != '3' &&
        square[0] != '4' && square[0] != '5' || square[1] != ':' ||
        square[4] != ':')
        return 1;
    if (square[2] < 'A' || square[2] > 'H' || square[5] < 'A' ||
        square[5] > 'H' || square[3] < '1' || square[3] > '8' ||
        square[6] < '1' || square[6] > '8')
        return 1;
    if (square[2] != square[5] && square[3] != square[6])
        return 1;
    return 0;
}

char **square_map_create(void)
{
    navy->map = malloc(sizeof(char *) * 9);
    for (int i = 0; i != 8; i++) {
        navy->map[i] = malloc(sizeof(char) * 18);
        for (int j = 0; j != 16; j += 2) {
            navy->map[i][j] = '.';
            navy->map[i][j + 1] = ' ';
        }
        navy->map[i][17] = '\0';
    }
    navy->map[8] = 0;
    return navy->map;
}

char **place_boat(char *square)
{
    if (erreur(square) == 1)
        return NULL;
    if (square[2] == square[5]) {
        for (int i = 0; i < square[0] - 48; i++)
            navy->map[square[3] - 49 + i][(square[2] - 65) * 2] = square[0];
    } else {
        for (int i = 0; i < square[0] - 48; i++)
            navy->map[square[3] - 49][(square[2] - 65 + i) * 2] = square[0];
    }
    return navy->map;
}

char **map_with_boat(char *str)
{
    char *configue_map = fs_open_file(str, configue_map);
    char *square = malloc(sizeof(char) * 9);

    navy->map = square_map_create();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            square[j] = configue_map[j + (i * 8)];
        }
        square[8] = '\0';
        navy->map = place_boat(square);
        if (place_boat(square) == NULL)
            return NULL;
    }
    return navy->map;
}
