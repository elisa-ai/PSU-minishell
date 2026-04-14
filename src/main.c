/*
** EPITECH PROJECT, 2026
** main.c
** File description:
** minishell1
*/

#include "../include/my.h"
#include "../include/minishell1.h"

void free_array(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++) {
        free(tab[i]);
    }
    free(tab);
}

int handle_exec_errno(shell_t *shell)
{
    if (errno == ENOEXEC) {
        mini_printf("%s: Exec format error. Binary file not executable.\n",
            shell->tab[0]);
    }
    return 0;
}

static void check_parsing(shell_t *shell)
{
    if (shell->tab && shell->tab[0]) {
        if (check_builtins(shell) == 0)
            execute_command(shell);
    }
}

static int main_loop(shell_t *shell)
{
    vars_t var = {0};

    while (1) {
        if (isatty(0))
            write(1, "$> ", 3);
        if (getline(&var.line, &var.size, stdin) == -1) {
            return 0;
        }
        if (var.line[0] != '\0' && var.line[my_strlen(var.line) - 1] == '\n')
            var.line[my_strlen(var.line) - 1] = '\0';
        parse_command(var.line, shell);
        check_parsing(shell);
    }
    return 0;
}

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av,
    char **env)
{
    int i = 0;
    shell_t shell = {0};
    int len = env_size(env);

    signal(SIGINT, handle_signal);
    shell.env_cpy = malloc(sizeof(char *) * (len + 1));
    if (!shell.env_cpy) {
        return 84;
    }
    while (env[i]) {
        shell.env_cpy[i] = my_strdup(env[i]);
        i++;
    }
    shell.env_cpy[i] = NULL;
    shell.path_dirs = path(&shell);
    main_loop(&shell);
    free_array(shell.path_dirs);
    free_array(shell.env_cpy);
    return 0;
}
