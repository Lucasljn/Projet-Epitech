/*
** EPITECH PROJECT, 2023
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
typedef struct element_s {
    int key_hash;
    char *value;
    struct element_s *next;
} element_t;

typedef struct hashtable_s {
    int size;
    int (*hash_function)(char *, int);
    element_t **array;
} hashtable_t;

int my_printf(const char *, ...);
int type(va_list, int, const char *, int);
int pstr(va_list, int, const char *, int);
int pnb(va_list, int, const char *, int);
int count_char_int(int count, long nb);
int show_nbr(int, int);
int my_put_nbr(int);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
char *my_strcat(char *, char *);
char *my_strdup(char *);
char *my_strcpy(char *, char *);
int my_is_prime(int);

void delete_hashtable(hashtable_t *);
void ht_dump(hashtable_t *);
char *ht_search(hashtable_t *, char *);
int ht_delete(hashtable_t *, char *);
int ht_insert(hashtable_t *, char *, char *);
hashtable_t *new_hashtable(int (*)(char *, int), int);
int hash(char *, int);
element_t *neweleminsert(hashtable_t *, int, char *, element_t *);

#endif /*MY_H*/
