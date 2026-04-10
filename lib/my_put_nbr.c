/*
** EPITECH PROJECT, 2025
** my_put_nbr.c
** File description:
** function
*/

#include "../include/my.h"

int my_put_nbr(int nb)
{
    int count = 0;

    if (nb < 0) {
        count = count + my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10) {
        count = count + my_put_nbr(nb / 10);
    }
    count = count + my_putchar((nb % 10) + '0');
    return count;
}
