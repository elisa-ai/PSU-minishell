/*
** EPITECH PROJECT, 2026
** parsing.c
** File description:
** minishell1
*/

#include "../include/my.h"
#include "../include/minishell1.h"

void parse_command(char *line, shell_t *shell)
{
    shell->tab = split(line, " \t\n");
}

int check_builtins_loop(shell_t *shell)
{
    if (my_strcmp(shell->tab[0], "cd") == 0) {
        my_cd(shell);
        return 1;
    }
    if (my_strcmp(shell->tab[0], "setenv") == 0) {
        my_setenv(shell);
        return 1;
    }
    return 0;
}

int check_builtins(shell_t *shell)
{
    if (shell->tab[0] == NULL)
        return 84;
    if (my_strcmp(shell->tab[0], "exit") == 0) {
        my_exit(shell);
        return 1;
    }
    if (my_strcmp(shell->tab[0], "env") == 0) {
        my_env(shell);
        return 1;
    }
    if (my_strcmp(shell->tab[0], "unsetenv") == 0) {
        my_unsetenv(shell);
        return 1;
    }
    if (check_builtins_loop(shell) == 1) {
        return 1;
    }
    return 0;
}
