/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include "../headers/my.h"

int my_is_prime(int nb)
{
    int mod = 1;
    int mod_test;

    if (nb <= 1)
        return (0);
    while (mod < nb - 1) {
        mod += 1;
        mod_test = nb % mod;
        if (mod_test == 0) {
            return (0);
        }
    }
    return (1);
}

int my_show_word_array(char * const *tab)
{
    int i = 0;
    int j = 0;
    int arr = 0;

    while (tab[arr] != NULL)
        arr += 1;
    while (j < arr) {
        while (tab[j][i] != '\0') {
            write(1, &tab[j][i], 1);
            i += 1;
        }
        j += 1;
        i = 0;
        write(1, "\n", 1);
    }
    return (0);
}

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
        }
        i += 1;
    }
    return (str);
}

int my_swap(int *a, int *b)
{
    int d;

    d = *a;
    *a = *b;
    *b = d;
    return (0);
}

int sum_stdarg(int i, int nb, ...)
{
    va_list ap;
    int res = 0;

    if (i != 0 && i != 1)
        return (84);
    va_start(ap, nb);
    if (i == 0) {
        for (; nb > 0; nb--)
            res += va_arg(ap, int);
    }else {
        for (; nb > 0; nb--)
            res += my_strlen(va_arg(ap, char *));
    }
    va_end(ap);
    my_put_nbr(res);
    my_putchar('\n');
    return (0);
}
