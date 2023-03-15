/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include "../headers/my.h"

char *base2(int nb)
{
    char *res = malloc(sizeof(char) * nb);
    int i = 0;

    while (nb != 0) {
        res[i] = (nb % 2) + 48;
        nb /= 2;
        i++;
    }
    return (res);
}

int my_find_prime_sup(int nb)
{
    while (my_nb_prime(nb) == 0) {
        nb += 1;
    }
    return (nb);
}

char **my_str_to_word_array(char const *str)
{
    int j = 0;
    char *new_str;
    int argc = my_strlen(str);
    int i = 0;

    new_str = malloc(sizeof(char) * (argc));
    while (i < argc) {
        new_str[i] = str[i];
        i += 1;
    }
    new_str[i] = '\0';
    while (new_str[j] != '\0') {
        if (non_alpha_char_test(new_str, j) == 0)
            new_str[j] = '\n';
        j += 1;
    }
}
