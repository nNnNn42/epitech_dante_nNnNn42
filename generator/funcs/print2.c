/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include "../headers/my.h"

void print_char(char c)
{
    my_putchar(c);
}

int my_printf(char *flags, ...)
{
    va_list ap;
    int j;

    va_start(ap, flags);
    for (int i = 0; i < my_strlen(flags); i++) {
        if (flags[i] == '%') {
            handle_percent(flags, &i, ap);
        } else {
            print_char(flags[i]);
        }
    }
    va_end(ap);
    return 0;
}
