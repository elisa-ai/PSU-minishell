/*
** EPITECH PROJECT, 2025
** my_is_alpha
** File description:
** function
*/

#include "../include/my.h"

int my_is_alpha(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    return 0;
}
