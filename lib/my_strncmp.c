/*
** EPITECH PROJECT, 2025
** my_strncmp
** File description:
** function
*/

#include "../include/my.h"

int my_strncmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}
