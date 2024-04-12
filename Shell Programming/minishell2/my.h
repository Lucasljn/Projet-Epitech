/*
** EPITECH PROJECT, 2023
** B2
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

    #include <unistd.h>
    #include <sys/wait.h>
    #include <sys/types.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <signal.h>
    #include "errno.h"
    #include "my_printf/printf.h"
    #include <fcntl.h>

typedef struct environnement_s {
    char *variable;
    char *valeur;
    struct environnement_s *next;
} environnement_t;

char *my_strdnup(int, char *, int);
int my_char_isalpha(char);
int len_tab(char *);
char **my_str_to_array(char *, char *);
void my_putchar(char);
int my_putstr(char *);
int my_strcmp(char *, char *);
char *my_strcat(char *, char *);
int my_strlen(char *);
void cd_function(char **, environnement_t *);
environnement_t *my_str_to_list(char *);
environnement_t *list_env(char **);
environnement_t *use_setenv(environnement_t *, char **);
environnement_t *show_env(environnement_t *);
environnement_t *use_unsetenv(environnement_t *, char *);
void execute(pid_t child, char **envp, char **tab, environnement_t *);
void execution2(char **, environnement_t *, char **);
void choose_execution(char **, environnement_t *, char **);
environnement_t *use_setenv2(environnement_t *, environnement_t *,
    environnement_t *);
char *found_bincom(environnement_t *, char **);
char *my_strdup(char *);
int len_tab2(char **);
void bin_error(int, char **);
environnement_t *oldpath(environnement_t *, char *);
environnement_t *init_envp(environnement_t *);
void free_function(char **, environnement_t *, char *);
int case_setenv(char **);
char *token_bincom(environnement_t *, char *, char **);
void separator(char *, environnement_t *, char **);
void com_with_pipe(char *, environnement_t *, char **, int);
void function_execution(char **, environnement_t *, char **);
void redirections(char **, environnement_t *, char **);
char *give_commande(int);
int choose_exit(char **);
int command_not_found(environnement_t *, char **, int);

#endif /*MY_H*/
