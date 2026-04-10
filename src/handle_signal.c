/*
** EPITECH PROJECT, 2026
** handle_signal.c
** File description:
** minishell1
*/

#include "../include/my.h"
#include "../include/minishell1.h"

static int check_signal_loop(int status)
{
    if (WTERMSIG(status) == SIGSEGV) {
        mini_printf("Segmentation fault");
        if (WCOREDUMP(status))
            mini_printf(" (core dumped)");
        mini_printf("\n");
    }
    if (WTERMSIG(status) == SIGFPE) {
        mini_printf("Floating exception");
        if (WCOREDUMP(status))
            mini_printf(" (core dumped)");
        mini_printf("\n");
    }
    return 0;
}

int check_signal(int status)
{
    if (WIFSIGNALED(status)) {
        if (check_signal_loop(status) == 1)
            return 1;
    }
    return 0;
}

void handle_signal(__attribute__((unused)) int sig)
{
    my_putchar('\n');
    my_putstr("$> ");
}
