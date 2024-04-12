/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** miniprintf
*/

#include "my.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

static int flagd(va_list list)
{
    int num = va_arg(list, int);

    my_put_nbr(num);
    return my_numlen(num);
}

static int flagpercent(va_list)
{
    my_putchar('%');
    return 1;
}

static int flags(va_list list)
{
    char *str = va_arg(list, char *);

    my_putstr(str);
    return my_strlen(str);
}

static int flagc(va_list list)
{
    my_putchar(va_arg(list, int));
    return 1;
}

static int flag_find(char c, va_list list)
{
    char *flag = "disc%";
    int (*f[5])(va_list) = {flagd, flagd, flags, flagc, flagpercent};
    int stock = 0;

    for (int i = 0; flag[i] != '\0'; i++) {
        if (c == flag[i])
            stock = f[i](list);
    }
    return stock;
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int total = 0;
    int now = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i = i + 1;
            total = total + flag_find(format[i], list);
        } else {
            my_putchar(format[i]);
            total = total + 1;
        }
    }
    va_end(list);
    return total;
}
