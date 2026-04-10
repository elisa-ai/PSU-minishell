/*
** EPITECH PROJECT, 2025
** mini_printf
** File description:
** function
*/

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

#include "../include/my.h"

int print_av(const char *format, va_list list, int count)
{
    char params = *format;

    if (params == 'c') {
        count = count + my_putchar(va_arg(list, int));
    }
    if (params == 's') {
        count = count + my_putstr(va_arg(list, char *));
    }
    if (params == 'd' || params == 'i') {
        count = count + my_put_nbr(va_arg(list, int));
    }
    if (params == '%') {
        count = count + my_putchar('%');
    }
    if (params != 'c' && params != 's' &&
        params != 'd' && params != 'i' && params != '%') {
        write(2, "invalid parameter\n", 18);
        return -1;
    }
    return count;
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    int count = 0;
    int b = 0;

    va_start(list, format);
    while (format[i] != 0) {
        if (format[i] == '%' && format[i + 1]) {
            count = count + print_av(&format[i + 1], list, count);
            i++;
        } else {
            count = count + write(1, &format[i], 1);
        }
        if (count < b)
            return -1;
        b = count;
        i++;
    }
    va_end(list);
    return count;
}
