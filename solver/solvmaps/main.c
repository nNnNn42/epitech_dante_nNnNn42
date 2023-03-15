/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include "../headers/my.h"

void movement3(struct s_val *val)
{
    if (val->i != 0) {
        if (val->maze[val->j][val->i - 1] == '*') {
            val->maze[val->j][val->i] = 'o';
            val->i--;
            val->path_taken[val->nb_path_taken] = '3';
            val->path_taken[val->nb_path_taken + 1] = '\0';
            val->nb_path_taken++;
            return;
        }
    }
    if (val->j != 0) {
        if (val->maze[val->j - 1][val->i] == '*') {
            val->maze[val->j][val->i] = 'o';
            val->j--;
            val->path_taken[val->nb_path_taken] = '0';
            val->path_taken[val->nb_path_taken + 1] = '\0';
            val->nb_path_taken++;
            return;
        }
    }
}

void movement2(struct s_val *val)
{
    if (val->j != val->y - 1) {
        if (val->maze[val->j + 1][val->i] == '*') {
            val->maze[val->j][val->i] = 'o';
            val->j++;
            val->path_taken[val->nb_path_taken] = '2';
            val->path_taken[val->nb_path_taken + 1] = '\0';
            val->nb_path_taken++;
            return;
        }
    }
    movement3(val);
}

void movement(struct s_val *val)
{
    if (val->i != val->x - 1) {
        if (val->maze[val->j][val->i + 1] == '*') {
            val->maze[val->j][val->i] = 'o';
            val->i++;
            val->path_taken[val->nb_path_taken] = '1';
            val->path_taken[val->nb_path_taken + 1] = '\0';
            val->nb_path_taken++;
            return;
        }
    }
    movement2(val);
}

void solver(struct s_val *val)
{
    for (; val->maze[val->y - 1][val->x - 1] != 'o';) {
        if (test_all_path(val) == 0)
            back_track(val);
        movement(val);
    }
    return;
}

int main(int ac, char **av)
{
    struct s_val *val = malloc(sizeof(struct s_val));

    if (ac != 2)
        return 84;
    verif_file(av[1]);
    init_all(val, av[1]);
    if (val->maze[0][0] == 'X') {
        my_printf("no solution found");
        return 84;
    }
    solver(val);
    clean(val);
    for (int i = 0; i < val->y - 1; my_printf("%s\n", val->maze[i]), i++);
    my_printf("%s", val->maze[val->y - 1]);
    return 0;
}
