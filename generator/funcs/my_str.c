/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include "../headers/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i += 1;
    while (src[j] != '\0') {
        dest[i] = src[j];
        j += 1;
        i += 1;
    }
    dest[i + 1] = '\0';
    return (dest);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int diff;

    while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
        i += 1;
    diff = s1[i] - s2[i];
    return (diff);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] += 32;
        }
        i += 1;
    }
    return (str);
}
