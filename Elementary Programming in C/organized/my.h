/*
** EPITECH PROJECT, 2023
** projects
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include "my.h"
    #include <stdlib.h>
    #include <stdarg.h>
    #include <unistd.h>

typedef struct organized_s {
    char *name;
    char *type;
    int id;
    struct organized_s *next;
    struct organized_s *previous;
} organized_t;

typedef struct fusion_s {
    struct organized_s *result;
    struct organized_s *temp;
    struct organized_s *tail;
} fusion_t;

char *my_strdup(char *);
int my_strlen(char *);
int my_numlen(int);
int my_put_nbr(int);
int my_putstr(char *);
void my_putchar(char);
int minmax(long, int);
int signe1(char, int);
int my_getnbr(char *);
char *my_strcat(char *, char *);
int my_strcmp(char *, char *);
int mini_printf(const char *, ...);
void conddel(organized_t *, organized_t **, char **, int);
void deleted(organized_t **, organized_t *, organized_t *);
int maxplace(organized_t *);
int lenargs(char **);
int erroradd(char **);
int comparecate(int, char **, int);
int errordel(organized_t *, char **);
int lenlistchaine(organized_t *);
organized_t *fusionname(organized_t *, organized_t *);
organized_t *tri_fusion(organized_t *, int);
organized_t *fusion_droite(organized_t *, int);
organized_t *fusion_gauche(organized_t *, int);
fusion_t *resulttail(fusion_t *);
fusion_t *finishresult(fusion_t *, organized_t *, organized_t *);
organized_t *fusionid(organized_t *, organized_t *);
organized_t *fusiontype(organized_t *, organized_t *);
int conddelerror(int, int, char **);
int errorsort(char **);
organized_t *reverse_list(organized_t *);

#endif /*MY_H*/
