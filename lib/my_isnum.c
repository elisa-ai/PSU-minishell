/*
** EPITECH PROJECT, 2025
** my_isnum
** File description:
** function
*/

#include "../include/my.h"

int my_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
