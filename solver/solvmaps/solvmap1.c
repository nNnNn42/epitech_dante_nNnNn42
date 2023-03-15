/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include "../headers/my.h"

int setup_path_taken(struct s_val *val)
{
    char *last_char = malloc(sizeof(char) * 2);
    int nb;

    if (val->path_taken[0] == '\0') {
        clean(val);
        my_printf("no solution found");
        exit(84);
    } else {
        nb = val->path_taken[my_strlen(val->path_taken) - 1] - 48;
        val->path_taken[my_strlen(val->path_taken) - 1] = '\0';
        val->nb_path_taken--;
        return nb;
    }
}

void back_track(struct s_val *val)
{
    int pos = setup_path_taken(val);

    if (pos == 0) {
        val->maze[val->j][val->i] = 'c';
        val->j++;
    } else if (pos == 1) {
        val->maze[val->j][val->i] = 'c';
        val->i--;
    }
    if (pos == 2) {
        val->maze[val->j][val->i] = 'c';
        val->j--;
    } else if (pos == 3) {
        val->maze[val->j][val->i] = 'c';
        val->i++;
    }
}

void clean(struct s_val *val)
{
    for (int i = 0, j = 0; i < val->y; i++) {
        for (j = 0; j < val->x; j++) {
            val->maze[j][i] = (val->maze[j][i] == 'c') ?
            '*' : val->maze[j][i];
        }
    }
}

int test_all_path(struct s_val *val)
{
    if (val->j != 0 && (val->maze[val->j - 1][val->i] == '*'))
        return 1;
    if (val->i != val->x - 1 && (val->maze[val->j][val->i + 1] == '*'))
        return 1;
    if (val->j != val->y - 1 && (val->maze[val->j + 1][val->i] == '*'))
        return 1;
    if (val->i != 0 && (val->maze[val->j][val->i - 1] == '*'))
        return 1;
    return 0;
}
