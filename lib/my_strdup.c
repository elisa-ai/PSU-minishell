/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** function
*/

#include "../include/my.h"

char *my_strdup(char *src)
{
    int i = 0;
    int len = my_strlen(src);
    char *dest = NULL;

    dest = malloc(sizeof(char) * (len));
    if (dest == NULL) {
        free(dest);
        return NULL;
    }
    while (src[i] != 0) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
