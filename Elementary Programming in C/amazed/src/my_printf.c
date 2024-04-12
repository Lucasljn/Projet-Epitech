/*
** EPITECH PROJECT, 2023
** printf
** File description:
** d
*/

#include "../include/maze.h"

int count_char_int(int count, long nb)
{
    while (nb / 10 != 0) {
        if (nb < 0) {
            count++;
            nb = nb * (- 1);
        }
        count++;
        nb = nb / 10;
    }
    return count + 1;
}

static int show_nbr(int nb, int n)
{
    if (nb > 0) {
        n = nb % 10 + '0';
        show_nbr(nb / 10, n);
        write(1, &n, 1);
    }
    if (nb < 0) {
        write(1, "-", 1);
        n = nb % 10 * (- 1) + '0';
        show_nbr(nb / (- 10), n);
        write(1, &n, 1);
    }
}

int my_put_nbr(int nb)
{
    int n = 0;

    if (nb == 0) {
        write(1, "0", 1);
        return 0;
    }
    show_nbr(nb, n);
    return 0;
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
    return 0;
}

static int pstr(va_list list, int i, const char *s, int count)
{
    char *str = va_arg(list, char *);

    my_putstr(str);
    return my_strlen(str);
}

static int pnb(va_list list, int i, const char *s, int count)
{
    int nb = va_arg(list, int);

    my_put_nbr(nb);
    return count_char_int(0, (long)nb);
}

static int pchar(va_list list, int i, const char *s, int count)
{
    char d = va_arg(list, int);

    write(1, &d, 1);
    return 1;
}

int type(va_list list, int i, const char *s, int count)
{
    int j = 0;
    char type_poss[] = "csid";
    int (*f[17])(va_list, int, const char *, int) = {pchar, pstr, pnb, pnb};

    for (int j = 0; type_poss[j] != '\0'; j++) {
        if (type_poss[j] == s[i]) {
            count = f[j](list, i, s, count);
            return count;
        }
    }
    write(1, "%", 1);
    write(1, &s[i], 1);
    return 2;
}

int my_printf(const char *format, ...)
{
    int count = 0;
    va_list list;

    if (format[0] == '\0')
        return 84;
    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            count += type(list, i + 1, format, count);
            i++;
        } else {
            count++;
            write(1, &format[i], 1);
        }
    }
    va_end(list);
    return count;
}
