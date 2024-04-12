/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** strcat
*/

#include <stdlib.h>

char *my_strcat( char *dest, char *src )
{
    int len = 0;
    int i = 0;
    char *final;

    for ( int j = 0; dest[j] != '\0'; j++ ) {
        len++;
    }
    for ( int j = 0; src[j] != '\0'; j++ ) {
        len++;
    }
    final = malloc(sizeof(char) * len + 1);
    while ( dest[i] != '\0' ) {
        final[i] = dest[i];
        i++;
    }
    for (int j = 0; src[j] != '\0'; j++) {
        final[i] = src[j];
        i++;
    }
    return final;
}
