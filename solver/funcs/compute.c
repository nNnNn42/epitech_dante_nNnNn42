/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include "../headers/my.h"

int my_compute_power_rec(int nb, int p)
{
    if (p == 0) {
        return (1);
    } else if (p < 0) {
        return (0);
    } else {
        return (nb * my_compute_power_rec(nb, p - 1));
    }
}

int my_compute_square_root(int nb)
{
    int odd = 1;
    int count = 0;

    while (nb != 0) {
        if (nb < 0)
            return (0);
        nb = nb - odd;
        odd += 2;
        count += 1;
    }
    nb = count;
    return (nb);
}

int disp_stdarg (char *s , ... )
{
    va_list ap;

    va_start(ap, s);
    for (int i = 0; i < my_strlen(s); i++) {
        if (s[i] == 's')
            my_putstr(va_arg(ap, char *));
        if (s[i] == 'c')
            my_putchar(va_arg(ap, int));
        else
            my_put_nbr(va_arg(ap, int));
        my_putchar('\n');
    }
    va_end(ap);
    return (0);
}

char *fill_str(char *str, char fill)
{
    for (int i = 0; i < my_strlen(str); i++)
        str[i] = fill;
    return (str);
}

int my_nb_prime(int nb_test)
{
    int mod = 1;
    int mod_test;

    if (nb_test <= 1)
        return (0);
    while (mod < nb_test - 1) {
        mod += 1;
        mod_test = nb_test % mod;
        if (mod_test == 0)
            return (0);
    }
    return (1);
}
