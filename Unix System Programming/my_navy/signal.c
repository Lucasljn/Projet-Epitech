/*
** EPITECH PROJECT, 2023
** my_navy
** File description:
** wait signal
*/

#include "my.h"

void handle_signal(int sig, siginfo_t *info, void *no)
{
    (void)no;
    navy->pid_ad = info->si_pid;
    if (navy->is_start == 0)
        navy->is_start = 1;
    if (sig == SIGUSR1 && navy->is_start)
        navy->coord[navy->index_coord]++;
    if (sig == SIGUSR2 && navy->index_coord != 2)
        navy->index_coord++;
    if (sig == SIGUSR2 && navy->index_coord == 2)
        navy->is_next = 1;
}

void handle_response(int sig, siginfo_t *info, void *no)
{
    (void)info;
    (void)no;
    if (sig == SIGUSR1)
        navy->is_hit = 1;
    else
        navy->is_hit = 2;
}

void wait_start(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    pause();
}

void wait_response(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handle_response;
    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (navy->is_hit == 0);
}

void wait_reception(void)
{
    struct sigaction sa;

    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO | SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (navy->is_next == 0);
}
