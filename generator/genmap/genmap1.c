/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include "../headers/my.h"

void back_track(struct s_val *val)
{
    if (val->intersec[0][0] == -1) {
        clean(val);
        for (int i = 0; i < val->y - 1; my_printf("%s\n", val->maze[i]), i++);
        my_printf("%s", val->maze[val->y - 1]);
        exit(0);
    } else {
        if (val->nb_intersec > 1) {
            val->nb_intersec--;
            val->j = val->intersec[val->nb_intersec][0];
            val->i = val->intersec[val->nb_intersec][1];
            val->intersec[val->nb_intersec][0] = -1;
            val->intersec[val->nb_intersec][1] = -1;
        } else {
            val->nb_intersec--;
            val->intersec[val->nb_intersec][0] = -1;
            val->intersec[val->nb_intersec][1] = -1;
        }
    }
}

void clean(struct s_val *val)
{
    for (int j = 0, i = 0; j < val->y; j++)
        for (i = 0; i < val->x; i++)
            val->maze[j][i] = (val->maze[j][i] == 'v' ||
            val->maze[j][i] == 'c') ? '*' : val->maze[j][i];
    val->maze[val->y - 1][val->x - 1] = '*';
}

void count_poss_path(struct s_val *val)
{
    if (val->j != 0 && (val->maze[val->j - 1][val->i] == '*'))
        val->nb_path++;
    if (val->i != val->x - 1 && (val->maze[val->j][val->i + 1] == '*'))
        val->nb_path++;
    if (val->j != val->y - 1 && (val->maze[val->j + 1][val->i] == '*'))
        val->nb_path++;
    if (val->i != 0 && (val->maze[val->j][val->i - 1] == '*'))
        val->nb_path++;
}

int count_path(struct s_val *val)
{
    val->nb_path = 0;
    count_poss_path(val);
    if (val->nb_path >= 3) {
        val->intersec[val->nb_intersec][0] = val->j;
        val->intersec[val->nb_intersec][1] = val->i;
        val->nb_intersec++;
    }
    if (val->nb_path == 0) {
        back_track(val);
        return 1;
    } else {
        val->path = rand() % val->nb_path;
        return 0;
    }
}

void wall2(struct s_val *val, int way)
{
    if (val->j != val->y - 1 && way != 2 &&
        (val->maze[val->j + 1][val->i] == '*')) {
        val->maze[val->j + 1][val->i] = 'X';
        return;
    }
    if (val->i != 0 && way != 3 &&
        (val->maze[val->j][val->i - 1] == '*')) {
        val->maze[val->j][val->i - 1] = 'X';
        return;
    }
}
