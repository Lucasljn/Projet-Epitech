/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** main
*/

#include "my.h"

navy_t *navy;

static int flag_h(int argc, char **argv)
{
    int fd = open("help.txt", O_RDONLY);
    char buffer;
    ssize_t bytesRead;

    bytesRead = read(fd, &buffer, 1);
    for (int i = 0; bytesRead > 0; i++) {
        write(1, &buffer, 1);
        bytesRead = read(fd, &buffer, 1);
    }
    close(fd);
    return 0;
}

int init(void)
{
    navy = malloc(sizeof(navy_t));
    navy->is_next = 0;
    navy->coord = malloc(sizeof(char) * 3);
    my_strcpy(navy->coord, "@1");
    navy->is_hit = 0;
    navy->map = create_map();
    navy->map_ad = create_map();
    return 0;
}

void reset(void)
{
    navy->coord[0] = '@';
    navy->coord[1] = '1';
    navy->is_hit = 0;
}

static int game(int argc, char **argv)
{
    if (argc == 2) {
        if (verif_map(argv[1]) == 84)
            return 1;
        player1(argv[1]);
    }
    if (argc == 3) {
        if (verif_map(argv[2]) == 84)
            return 1;
        player2(argv[2], argv[1]);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2 && argc != 3)
        return 84;
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h')
        return flag_h(argc, argv);
    init();
    if (game(argc, argv) == 1)
        return 84;
    win();
    return 0;
}
