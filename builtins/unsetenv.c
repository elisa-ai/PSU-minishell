/*
** EPITECH PROJECT, 2026
** setenv.c
** File description:
** minishell1
*/

#include "../include/minishell1.h"
#include "../include/my.h"

static int my_unsetenv_loop(int j, int i, shell_t *shell)
{
    if (my_strncmp(shell->env_cpy[i], shell->tab[1]) == 0 &&
        shell->env_cpy[i][my_strlen(shell->tab[1])] == '=') {
        free(shell->env_cpy[i]);
        for (j = i; shell->env_cpy[j]; j++)
            shell->env_cpy[j] = shell->env_cpy[j + 1];
        return 1;
    }
    return 0;
}

int my_unsetenv(shell_t *shell)
{
    int i = 0;
    int j = 0;
    int tab_len = 0;

    while (shell->tab[tab_len])
        tab_len++;
    if (tab_len == 1) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        return 0;
    }
    for (i = 0; shell->env_cpy[i]; i++) {
        if (my_unsetenv_loop(j, i, shell) == 1)
            return 1;
    }
    return 0;
}
