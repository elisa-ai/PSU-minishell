/*
** EPITECH PROJECT, 2025
** my_str_to_word_array
** File description:
** function
*/

#include "../include/my.h"

int count_word(char *str)
{
    int count = 0;
    int i = 0;
    int len = 0;
    char c;

    len = my_strlen(str);
    if (len > 0) {
        c = str[0];
    }
    while (i <= len) {
        if ((str[i] == ' ' || str[i] == '\0') && c != ' ') {
            count++;
        }
        c = str[i];
    }
    return count;
}

int replace_space(char *str)
{
    int i = 0;

    if (str[i] == ' ') {
        str[i] == '\0';
    }
    return 0;
}

// int main(void)
// {
//     char *src = "el mordjene";

//     printf("%s", my_strdup(src));
//     return 0;
// }
