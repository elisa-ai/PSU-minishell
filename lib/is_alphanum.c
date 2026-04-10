/*
** EPITECH PROJECT, 2025
** is_alphanum
** File description:
** function
*/

#include "../include/my.h"

int is_alphanum(char c)
{
    if (my_is_alpha(c) || my_isnum(c) || c == '_')
        return 1;
    return 0;
}
