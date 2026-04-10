/*
** EPITECH PROJECT, 2026
** my.h
** File description:
** minishell1
*/

#include <stddef.h>

#ifndef _STRUCT_H_
    #define _STRUCT_H_

typedef struct shell_s {
    char **env_cpy;
    char **tab;
    int last_status;
    char **path_dirs;
    char *old_pwd;
} shell_t;

typedef struct vars_s {
    char *line;
    size_t size;
} vars_t;

#endif //_STRUCT_H_
