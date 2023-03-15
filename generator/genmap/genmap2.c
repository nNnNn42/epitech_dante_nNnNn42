/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include "../headers/my.h"

void wall(struct s_val *val, int way)
{
    if (val->nb_path == 1)
        return;
    if (val->j != 0 && way != 0 && (val->maze[val->j - 1][val->i] == '*')) {
        val->maze[val->j - 1][val->i] = 'X';
        return;
    }
    if (val->i != val->x - 1 && way != 1 &&
        (val->maze[val->j][val->i + 1] == '*')) {
        val->maze[val->j][val->i + 1] = 'X';
        return;
    }
    wall2(val, way);
}

int move_l(struct s_val *val)
{
    if (val->i != 0 && (val->path != 0)) {
        if (test_path(val, 3) == 1){
            wall(val, 3);
            val->i--;
            return 1;
        }
    } else
        val->path--;
    return 0;
}

int move_d(struct s_val *val)
{
    if (val->j != val->y - 1 && (val->path != 0)) {
        if (test_path(val, 2) == 1){
            wall(val, 2);
            val->j++;
            return 1;
        }
    } else
        val->path--;
    if (move_l(val) == 1)
        return 1;
    else
        return 0;
}

int move_r(struct s_val *val)
{
    if (val->i != val->x - 1 && (val->path != 0)) {
        if (test_path(val, 1) == 1){
            wall(val , 1);
            val->i++;
            return 1;
        }
    } else
        val->path--;
    if (move_d(val) == 1)
        return 1;
    else
        return 0;
}

void move(struct s_val *val)
{
    val->maze[val->j][val->i] = 'v';
    for (int i = 0; i < 10; i++) {
        if (val->j != 0 && (val->path != 0)) {
            if (test_path(val, 0) == 1){
                wall(val, 0);
                val->j--;
                return;
            }
        } else
            val->path--;
        if (move_r(val) == 1)
            return;
    }
}
