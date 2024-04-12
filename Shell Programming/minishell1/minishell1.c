/*
** EPITECH PROJECT, 2023
** B2
** File description:
** minishell1.c
*/

#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "my.h"
#include <stdio.h>
#include <stdlib.h>

void len_commande(char **tab, char *bincom, char **envp)
{
    if (execve(bincom, tab, envp) == -1) {
        if (my_strcmp(strerror(errno), "Exec format error") == 0) {
            my_printf("%s: %s. Wrong Architecture.\n",
                tab[0], strerror(errno));
        } else
            my_printf("%s: %s.\n", tab[0], strerror(errno));
        exit(EXIT_FAILURE);
    }
}

void execute(pid_t child, char **envp, char **tab, environnement_t *elm)
{
    char *bincom = found_bincom(elm, tab);
    int status;

    if (access(bincom, F_OK) == 0) {
        child = fork();
        if (child == 0) {
            len_commande(tab, bincom, envp);
        } else {
            waitpid(child, &status, 0);
            bin_error(status, tab);
        }
    } else
        my_printf("%s: Command not found.\n", bincom);
    free(bincom);
}

void execution2(char **tab, environnement_t *elm, char **envp)
{
    pid_t child;

    if (my_strcmp("unsetenv", tab[0]) == 0) {
        if (tab[1] == NULL) {
            my_putstr("unsetenv: Too few arguments.\n");
            return;
        }
        for (int i = 0; tab[i] != 0; i++)
            use_unsetenv(elm, tab[i]);
        return;
    }
    if (my_strcmp("env", tab[0]) == 0) {
        elm = show_env(elm);
        return;
    }
    execute(child, envp, tab, elm);
}

void choose_execution(char **tab, environnement_t *elm, char **envp)
{
    if (my_strcmp("exit", tab[0]) == 0)
        exit(0);
    if (my_strcmp(tab[0], "cd") == 0) {
        cd_function(tab, elm);
        return;
    }
    if (my_strcmp("setenv", tab[0]) == 0) {
        if (tab[1] == NULL) {
            show_env(elm);
            return;
        }
        if (len_tab2(tab) > 1 && case_setenv(tab) == 0) {
            elm = use_setenv(elm, tab);
        } else {
            my_putstr("setenv: Variable name must countain");
            my_putstr(" alphanumeric characters.\n");
        }
        return;
    }
    execution2(tab, elm, envp);
}

int main(int argc, char **argv, char **envp)
{
    char *commande = NULL;
    size_t len = 0;
    ssize_t read;
    char **tab;
    environnement_t *elm = list_env(envp);

    while (1) {
        if (isatty(STDIN_FILENO) == 1)
            my_putstr("$> ");
        read = getline(&commande, &len, stdin);
        if (read == -1)
            return 0;
        if (commande[read - 1] == '\n')
            commande[read - 1] = '\0';
        if (my_strcmp(commande, "") != 0) {
            tab = my_str_to_array(commande);
            choose_execution(tab, elm, envp);
        }
    }
    free_function(tab, elm, commande);
}
