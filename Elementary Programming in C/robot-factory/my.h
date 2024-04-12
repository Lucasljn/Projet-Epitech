/*
** EPITECH PROJECT, 2024
** projects
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H
    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <errno.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <signal.h>
    #include <string.h>
    #include "op.h"

int my_printf(const char *, ...);
int count_char_int(int count, long nb);
int my_put_nbr(int);
int my_putstr(char const *);
int my_arrlen(char **);
int my_getnbr(char *);
char *my_strcat(char *, char *);
char *my_strdup(char *);
int my_strncmp(char *, char *, int);
int my_is_prime(int);
char *rm_space(char *str);
char **clean_str(char *);
int my_char_isalpha(char);
int len_tab(char *);
int my_strcmp(char *, char *);
char *my_strtok(char *, char *);
char *my_strdup(char *);
char **my_str_to_array(char *, char *);
char *my_revstr(char *);
int str_is_num(char *);
char *create_name_label(char *);
int jump_byte(char **, int, op_t *, char *);
int label_param(char **, op_t *, int, int);
int my_strlen(char *);
char **my_str_to_word_array(char *, char);
int file_len(char const *);
char *fs_open_file(char const *, char *);
int conv(int nb);

int parsing_header(header_t *header, char *buffer, char **header_tab);
int name_file(int argc, char **argv, int fd);

char *cod_param(char **tab, op_t *op, int i, int fd);
char *coding_byte(char **tab, op_t *op, int i);
char *my_put_hexa(long nbr, int lennum);
int binaire_to_decimal(char *chaine_binaire);
char *add_byte(char **tab, int i, char *byte);
int label_exception(int exception, char *param);

#endif /*MY_H*/
