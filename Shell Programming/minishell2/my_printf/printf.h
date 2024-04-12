/*
** EPITECH PROJECT, 2023
** B2
** File description:
** printf.h
*/


#ifndef PRINTF_H
    #define PRINTF_H

    #include <stdarg.h>
    #include "../my.h"


int my_printf(const char *, ...);
int type(va_list, int, const char *, int);
int pstr(va_list, int, const char *, int);
int pnb(va_list, int, const char *, int);
int count_char_int(int count, long nb);
int show_nbr(int, int);
int my_put_nbr(int);
int my_getnbr(char *);
char *my_strcpy(char *, char *);
int my_is_prime(int);

#endif /*PRINTF_H*/
