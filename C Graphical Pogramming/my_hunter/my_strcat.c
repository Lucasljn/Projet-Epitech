/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** strcat
*/

char *my_strcat( char *dest, char *src )
{
    int len = 0;
    int i = 0;
    char tmp;

    for ( int j = 0; dest[j] != '\0'; j++ ) {
        len++;
    }
    while ( src[i] != '\0' ) {
        tmp = src[i];
        dest[len + i] = tmp;
        i++;
    }
    dest[len + i] = '\0';
    return dest;
}
