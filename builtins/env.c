/*
** EPITECH PROJECT, 2026
** env.c
** File description:
** minishell1
*/

#include "../include/minishell1.h"
#include "../include/my.h"

int env_size(char **env)
{
    int i = 0;

    while (env[i]) {
        i++;
    }
    return i;
}

int my_env(shell_t *shell)
{
    int i = 0;

    while (shell->env_cpy[i]) {
        my_putstr(shell->env_cpy[i]);
        write(1, "\n", 1);
        i++;
    }
    return 0;
}
