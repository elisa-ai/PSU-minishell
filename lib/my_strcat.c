/*
** EPITECH PROJECT, 2025
** strcat
** File description:
** function
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[j] != '\0') {
        j++;
    }
    while (src[i] != '\0') {
        dest[j] = src[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return dest;
}
