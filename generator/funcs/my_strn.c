/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include "../headers/my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i += 1;
    while (src[j] != '\0' && nb > 0) {
        dest[i] = src[j];
        j += 1;
        i += 1;
        nb -= 1;
    }
    dest[i + 1] = '\0';
    return (dest);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int diff;

    while (s1[i] == s2[i] && n == 0) {
        i += 1;
        n -= 1;
    }
    diff = s1[i] - s2[i];
    return (diff);
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        if (src[i] == '\0') {
            dest[i] = src[i];
            break;
        }
        dest[i] = src[i];
        i += 1;
    }
    return (dest);
}

char *my_strstr(char *str, const char *to_find)
{
    while (*str) {
        const char *beginning = str;
        const char *pattern = to_find;
        while (*str && *pattern && *str == *pattern) {
            str++;
            pattern++;
        }
        if (!*pattern)
            return (char *) beginning;
        beginning++;
    }
    return NULL;
}

int non_alpha_char_test(char const *str, int i)
{
    if (str[i] >= 48 && str[i] <= 57 || str[i] >= 65 && str[i] <= 90)
        return (1);
    else if (str[i] >= 97 && str[i] <= 122)
        return (1);
    return (0);
}
