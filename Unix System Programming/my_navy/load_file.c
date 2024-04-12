/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** file + place boat
*/

#include "my.h"

void append_map(char x, char y, char sym)
{
    int x_pos = x - 'A';
    int y_pos = y - '1';

    navy->map[y_pos][x_pos] = sym;
}

void sub_place(int index, char *place)
{
    char symbole = place[index - 2];
    char l1 = place[index];
    char n1 = place[index + 1];
    char l2 = place[index + 3];
    char n2 = place[index + 4];

    if (l1 == l2) {
        while (n1 != n2 + 1) {
            append_map(l1, n1, symbole);
            n1++;
        }
    } else {
        while (l1 != l2 + 1) {
            append_map(l1, n1, symbole);
            l1++;
        }
    }
}

void set_boat(char *place)
{
    sub_place(2, place);
    sub_place(10, place);
    sub_place(18, place);
    sub_place(26, place);
}
