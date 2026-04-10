/*
** EPITECH PROJECT, 2026
** parsing.c
** File description:
** minishell1
*/

#include "../include/my.h"
#include "../include/minishell1.h"

char *my_path_concat(char *dir, char *cmd)
{
    char *res = malloc(my_strlen(dir) + my_strlen(cmd) + 2);

    my_strcpy(res, dir);
    my_strcat(res, "/");
    my_strcat(res, cmd);
    return res;
}

char *find_command_path(shell_t *shell)
{
    char *full_path = NULL;

    if (access(shell->tab[0], X_OK) == 0)
        return (shell->tab[0]);
    for (int i = 0; shell->path_dirs[i]; i++) {
        full_path = my_path_concat(shell->path_dirs[i], shell->tab[0]);
        if (access(full_path, X_OK) == 0)
            return (full_path);
        free(full_path);
    }
    return NULL;
}

int execute_command(shell_t *shell)
{
    char *path = find_command_path(shell);
    int status = 0;

    if (!path) {
        mini_printf("%s: Command not found.\n", shell->tab[0]);
        return 1;
    }
    if (fork() == 0) {
        if (execve(path, shell->tab, shell->env_cpy) == -1)
            handle_exec_errno(shell);
        exit(1);
    } else {
        wait(&status);
        if (WIFSIGNALED(status)) {
            shell->last_status = 128 + WTERMSIG(status);
            check_signal(status);
        } else {
            shell->last_status = WEXITSTATUS(status);
        }
    }
    return 0;
}

char **split(char *str, char *delim)
{
    int i = 0;
    char *token = NULL;
    char **tab = malloc(sizeof(char *) * (my_strlen(str) + 1));

    token = strtok(str, delim);
    while (token) {
        tab[i] = my_strdup(token);
        i++;
        token = strtok(NULL, delim);
    }
    tab[i] = NULL;
    return tab;
}

char **path(shell_t *shell)
{
    int i = 0;
    char *tmp = NULL;
    char **res = NULL;

    while (shell->env_cpy[i]) {
        if (my_strncmp(shell->env_cpy[i], "PATH") == 0) {
            tmp = my_strdup(shell->env_cpy[i] + 5);
            res = split(tmp, ":");
            free(tmp);
            return res;
        }
        i++;
    }
    return NULL;
}
