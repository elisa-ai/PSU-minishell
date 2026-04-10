/*
** EPITECH PROJECT, 2026
** setenv.c
** File description:
** minishell1
*/

#include "../include/minishell1.h"
#include "../include/my.h"

static int check_var_syntax(char *name)
{
    if (!my_is_alpha(name[0])) {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        return 1;
    }
    for (int i = 0; name[i]; i++) {
        if (!is_alphanum(name[i])) {
            write(2,
                "setenv: Variable name must contain alphanumeric characters.\n",
                60);
            return 1;
        }
    }
    return 0;
}

void add_to_env(shell_t *shell, char *new_var)
{
    int size = 0;
    char **new_env = NULL;
    int i = 0;

    while (shell->env_cpy[size])
        size++;
    new_env = malloc(sizeof(char *) * (size + 2));
    if (!new_env)
        return;
    for (i = 0; i < size; i++)
        new_env[i] = shell->env_cpy[i];
    new_env[i] = new_var;
    new_env[i + 1] = NULL;
    free(shell->env_cpy);
    shell->env_cpy = new_env;
}

int my_setenv_loop(shell_t *shell, int tab_len)
{
    while (shell->tab[tab_len])
        tab_len++;
    if (tab_len == 1) {
        my_env(shell);
        return 1;
    }
    if (tab_len > 3) {
        write(2, "setenv: Too many arguments.\n", 28);
        return 84;
    }
    if (check_var_syntax(shell->tab[1]) != 0)
        return 1;
    return 0;
}

static int update_env_var(shell_t *shell, char *new_var)
{
    for (int i = 0; shell->env_cpy[i]; i++) {
        if (my_strncmp(shell->env_cpy[i], shell->tab[1]) == 0 &&
            shell->env_cpy[i][my_strlen(shell->tab[1])] == '=') {
            free(shell->env_cpy[i]);
            shell->env_cpy[i] = new_var;
            return 1;
        }
    }
    return 0;
}

int my_setenv(shell_t *shell)
{
    char *new_var = NULL;
    int check = my_setenv_loop(shell, 0);

    if (check != 0)
        return check;
    new_var = malloc(my_strlen(shell->tab[1]) + (shell->tab[2] ?
            my_strlen(shell->tab[2]) : 0) + 2);
    if (!new_var)
        return 84;
    my_strcpy(new_var, shell->tab[1]);
    my_strcat(new_var, "=");
    if (shell->tab[2])
        my_strcat(new_var, shell->tab[2]);
    if (update_env_var(shell, new_var))
        return 0;
    add_to_env(shell, new_var);
    return 0;
}
