/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <time.h>
#pragma once

typedef struct s_val {
    int x;
    int y;
    int i;
    int j;
    int nb_path;
    char **maze;
    char *path_taken;
    int nb_path_taken;
} t_val;

int verif_file(char *file);
void init_all(struct s_val *val, char *file);
int test_all_path(struct s_val *val);
void movement(struct s_val *val);
void back_track(struct s_val *val);
void clean(struct s_val *val);
void my_putchar(char c);
int my_isneg(int n);
int my_put_nbr(int nb);
int my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char *str);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
int my_show_word_array(char * const *tab);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_compute_power_rec(int nb, int p);
char **my_str_to_word_array(char const *str);
void calculus(int numb);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg (char *s , ... );
int base8(int nb);
char *base16(int nb);
char *base16_min(int nb);
char *base2(int nb);
char *fill_str(char *str, char fill);
int my_printf(char *flags, ...);
int base16to10(char *str);
int my_isint(char *str);
char **strswap(char **l_a, int fst, int ac);
char **strswap_b(char **l_a, int fst, int ac);
char **makel_a(int ac_a, int ac_b, char **l_a, char **l_b);
int isorder(int ac, char **l_a);
int rev_isorder(int ac, char **l_b);
int my_nb_prime(int nb_test);
int non_alpha_char_test(char const *str, int i);
void handle_percent(char *flags, int *i, va_list ap);
