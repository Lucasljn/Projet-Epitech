/*
** EPITECH PROJECT, 2023
** B2
** File description:
** separator.c
*/

#include "my.h"

static void in_file(char **tab, int i, environnement_t *elm, char **envp)
{
    int fd;
    int pid;

    if (tab[i + 1] != NULL) {
        fd = open(tab[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
        pid = fork();
        if (pid == 0) {
            dup2(fd, STDOUT_FILENO);
            tab[i] = NULL;
            tab[i + 1] = NULL;
            choose_execution(tab, elm, envp);
            exit(0);
        } else
            wait(NULL);
    } else
        my_printf("Missing name for redirect.\n");
}

static void in_file_double(char **tab, int i, environnement_t *elm,
    char **envp)
{
    int fd;
    int pid;

    if (tab[i + 1] != NULL) {
        fd = open(tab[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0666);
        if (fd == -1) {
            my_printf("%s: No such file or directory.\n", tab[i + 1]);
            return;
        }
        pid = fork();
        if (pid == 0) {
            dup2(fd, STDOUT_FILENO);
            tab[i] = NULL;
            tab[i + 1] = NULL;
            choose_execution(tab, elm, envp);
            exit(0);
        } else
            wait(NULL);
    } else
        my_printf("Missing name for redirect.\n");
}

static void on_file(char **tab, int i, environnement_t *elm, char **envp)
{
    int fd;
    int save_out = dup(1);
    int pid;

    if (tab[i + 1] != NULL)
        fd = open(tab[i + 1], O_RDONLY, 0644);
    if (fd != -1) {
        tab[i] = NULL;
        tab[i + 1] = NULL;
        dup2(fd, STDIN_FILENO);
        choose_execution(tab, elm, envp);
        dup2(save_out, 1);
        close(fd);
    } else
        my_printf("%s: No such file or directory.\n", tab[i + 1]);
}

static void double_red(char **tab, int i, environnement_t *elm, char **envp)
{
    char *attemp = NULL;
    int read;
    size_t len;

    while (1) {
        if (isatty(STDIN_FILENO) == 1)
            my_putstr("? ");
        read = getline(&attemp, &len, stdin);
        if (read == -1)
            return;
        if (attemp[read - 1] == '\n')
            attemp[read - 1] = '\0';
        if (my_strcmp(tab[i + 1], attemp) == 0)
            break;
    }
    tab[i] = NULL;
    tab[i + 1] = NULL;
    choose_execution(tab, elm, envp);
}

void redirections(char **tab, environnement_t *elm, char **envp)
{
    for (int i = 0; tab[i] != 0; i ++) {
        if (my_strcmp(tab[i], "<<") == 0) {
            double_red(tab, i, elm, envp);
            return;
        }
        if (my_strcmp(tab[i], ">") == 0) {
            in_file(tab, i, elm, envp);
            return;
        }
        if (my_strcmp(tab[i], ">>") == 0) {
            in_file_double(tab, i, elm, envp);
            return;
        }
        if (my_strcmp(tab[i], "<") == 0) {
            on_file(tab, i, elm, envp);
            return;
        }
    }
    choose_execution(tab, elm, envp);
}

void function_execution(char **tab, environnement_t *elm, char **envp)
{
    for (int i = 0; tab[i] != 0; i++)
        com_with_pipe(tab[i], elm, envp, STDIN_FILENO);
    for (int i = 0; tab[i] != 0; i++)
        free(tab[i]);
    free(tab);
}

void condition_dup(int prev_stdin, int i, char **com_pipe, int pipefd[2])
{
    close(pipefd[0]);
    if (i > 0)
        dup2(prev_stdin, STDIN_FILENO);
    if (com_pipe[i + 1] != NULL)
        dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[1]);
}

static int cond_wait(int pipefd[2], int prev_in, char *com_pipei)
{
    if (com_pipei == 0)
        wait(NULL);
    close(pipefd[1]);
    prev_in = pipefd[0];
    return prev_in;
}

void com_with_pipe(char *com, environnement_t *elm, char **envp, int prev_in)
{
    char **com_pipe = my_str_to_array(com, "|");
    int pipefd[2];
    pid_t pid;

    if (my_strcmp(com_pipe[0], com) == 0) {
        redirections(my_str_to_array(com_pipe[0], " \t"), elm, envp);
        return;
    }
    for (int i = 0; com_pipe[i] != 0; i++) {
        i = command_not_found(elm, com_pipe, i);
        pipe(pipefd);
        pid = fork();
        if (pid == 0) {
            condition_dup(prev_in, i, com_pipe, pipefd);
            redirections(my_str_to_array(com_pipe[i], " \t"), elm, envp);
            exit(EXIT_FAILURE);
        }
        prev_in = cond_wait(pipefd, prev_in, com_pipe[i + 1]);
    }
}
