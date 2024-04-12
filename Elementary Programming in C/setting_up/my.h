/*
** EPITECH PROJECT, 2023
** my-ls
** File description:
** my.h
*/

struct big {
    int x;
    int y;
    int sizex;
    int sizey;
};

#ifndef MY_H
    #define MY_H

int mini_printf(const char *, ...);
int my_strlen(char *);
int my_putstr(char *);
void my_putchar(char);
int my_put_nbr(int);
int my_numlen(int);
char *my_strcat(char *, char *);
int my_getnbr(char *);
int signe1(char, int);
int minmax(long, int);
int file_len(char const *);
char *fs_open_file(char const *);
char **str_to_square(char *);
char **display_square(char *, char **);
char *generatormap(char *, char *);
int lenrow(char **);
int lencol(char **);
int **createsquare(char **, int, int);
int min(int, int, int);
int **squaretomatrix(char **, int **, int, int);
void numsquare(char **, int **, int, int);
void findmaxsquare(char **);
void squarewithx(char **, struct big *);
void findsquare(int, int **, struct big *, int);
int destroyfirstrow(char *);
int my_strlen(char *);
int error(int, char **);
int diff_nbr_char(int, char **, int);
int my_str_isnum(char const *);
int errorrow(char *, char **);

#endif /* MY_H*/
