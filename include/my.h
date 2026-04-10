/*
** EPITECH PROJECT, 2026
** my.h
** File description:
** minishell1
*/

#include "minishell1.h"
#ifndef _MY_H_
    #define _MY_H_
    #include <unistd.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include <errno.h>
    #include <sys/stat.h>
    #include <stdarg.h>
    #include <errno.h>

int my_exit(shell_t *shell);
int my_strcmp(char const *s1, char const *s2);
int my_putchar(char c);
int my_strlen(char *str);
char *my_strdup(char *src);
int my_putstr(char const *str);
int count_word(char *str);
int replace_space(char *str);
void parse_command(char *line, shell_t *shell);
int check_builtins(shell_t *shell);
int my_strncmp(char const *s1, char const *s2);
int my_env(shell_t *shell);
int env_size(char **env);
char *my_strcpy(char *dest, char const *src);
char **path(shell_t *shell);
char **split(char *str, char *delim);
char *my_path_concat(char *dir, char *cmd);
char *find_command_path(shell_t *shell);
int execute_command(shell_t *shell);
char *my_strcat(char *dest, char const *src);
void handle_signal(int sig);
int my_put_nbr(int nb);
int print_av(const char *format, va_list list, int count);
int mini_printf(const char *format, ...);
int my_setenv(shell_t *shell);
void add_to_env(shell_t *shell, char *new_var);
int my_unsetenv(shell_t *shell);
void my_cd(shell_t *shell);
int check_builtins_loop(shell_t *shell);
int check_signal(int status);
int my_setenv_loop(shell_t *shell, int tab_len);
int is_alphanum(char c);
int my_is_alpha(char c);
int my_isnum(char c);
int handle_exec_errno(shell_t *shell);
void free_array(char **tab);
#endif //_MY_H_
