/*
** EPITECH PROJECT, 2026
** my_exit.c
** File description:
** minishell
*/

#include "../include/my.h"
#include "../include/minishell1.h"

int my_exit(shell_t *shell)
{
    int status = shell->last_status;

    if (isatty(0))
        write(1, "exit\n", 6);
    status = shell->last_status;
    exit(status);
    return 0;
}
