/*
** EPITECH PROJECT, 2026
** my_cd.c
** File description:
** minishell
*/

#include "../include/my.h"
#include "../include/minishell1.h"

char *get_env_val(shell_t *shell, char *var)
{
    int len = my_strlen(var);

    for (int i = 0; shell->env_cpy[i]; i++) {
        if (my_strncmp(shell->env_cpy[i], var) == 0 &&
            shell->env_cpy[i][len] == '=') {
            return (shell->env_cpy[i] + len + 1);
        }
    }
    return NULL;
}

static void handle_cd_errors(char *dest)
{
    if (errno == ENOTDIR) {
        mini_printf("%s: Not a directory.\n", dest);
    }
    if (errno == ENOENT) {
        mini_printf("%s: No such file or directory.\n", dest);
    }
    if (errno == EACCES) {
        mini_printf("%s: Permission denied.\n", dest);
    }
}

static void change_dir(shell_t *shell, char *dest)
{
    char *current_pwd = getcwd(NULL, 0);

    if (chdir(dest) == -1) {
        handle_cd_errors(dest);
        if (current_pwd)
            free(current_pwd);
        shell->last_status = 1;
        return;
    }
    if (shell->old_pwd)
        free(shell->old_pwd);
    shell->old_pwd = current_pwd;
    shell->last_status = 0;
}

void my_cd(shell_t *shell)
{
    int tab_len = 0;
    char *dest = NULL;

    while (shell->tab[tab_len]) {
        tab_len++;
    }
    if (tab_len > 2) {
        write(2, "cd: Too many arguments.\n", 24);
        return;
    }
    if (tab_len == 1 || my_strcmp(shell->tab[1], "~") == 0)
        dest = get_env_val(shell, "HOME");
    else if (my_strcmp(shell->tab[1], "-") == 0)
        dest = shell->old_pwd;
    else
        dest = shell->tab[1];
    change_dir(shell, dest);
}
