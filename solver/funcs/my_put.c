/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include "../headers/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void calculus(int numb)
{
    if (numb > 0) {
        calculus(numb / 10);
        my_putchar(numb % 10 + 48);
    }
}

int my_put_nbr(int nb)
{
    if (nb == 0) {
        my_putchar('0');
        return (0);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    calculus(nb);
    return (0);
}

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        write(1, &str[i], 1);
        i += 1;
    }
    return (0);
}

char *my_revstr(char *str)
{
    char c[1];
    int n = 0;
    int i = 0;

    while (str[i] != '\0')
        i = i + 1;
    while (i > n){
        c[0] = str[n];
        str[n] = str[i - 1];
        str[i - 1] = c[0];
        i = i - 1;
        n = n + 1;
    }
    return (str);
}
