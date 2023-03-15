/*
** EPITECH PROJECT, 2023
** hehe
** File description:
** hehe
*/

#include "../headers/my.h"

void init_x(struct s_val *val , char *file)
{
    int fd;
    char buff[1];

    val->x = -1;
    fd = open(file, O_RDONLY);
    buff[0] = 'a';
    for (int test = 1; buff[0] != '\n'; val->x++)
        test = read(fd, buff, 1);
    close(fd);
}

void init_y(struct s_val *val , char *file)
{
    int fd;
    char buff[1];

    val->y = 1;
    fd = open(file, O_RDONLY);
    buff[0] = 'a';
    for (int test = 1; test != 0;) {
        if (buff[0] == '\n')
            val->y++;
        test = read(fd, buff, 1);
    }
    close(fd);
}

void init_all(struct s_val *val, char *file)
{
    int fd;

    init_x(val, file);
    init_y(val, file);
    val->maze = malloc(sizeof(char *) * val->y);
    for (int i = 0; i < val->y; val->maze[i] = malloc(sizeof(char) *
        val->x + 1), i++);
    fd = open(file, O_RDONLY);
    for (int k = 0; k < val->y; k++) {
        read(fd, val->maze[k], val->x + 1);
        val->maze[k][val->x] = '\0';
    }
    close(fd);
    val->i = 0;
    val->j = 0;
    val->path_taken = malloc(sizeof(char) * (val->x * val->y));
    val->path_taken[0] = '\0';
    val->nb_path_taken = 0;
}

int exist(char *fd)
{
    int file;

    file = open(fd, O_RDONLY);
    if (file == -1)
        exit(84);
    close(file);
    return 0;
}

int verif_file(char *file)
{
    int fd;
    char buff[1];
    int len = 0;
    char *maze;

    exist(file);
    fd = open(file, O_RDONLY);
    for (int test = 1; test != 0; len++)
        test = read(fd, buff, 1);
    close(fd);
    maze = malloc(sizeof(char) * len);
    fd = open(file, O_RDONLY);
    read(fd, maze, len);
    for (int i = 0; i < len - 1; i++)
        if (maze[i] != 'X' && maze[i] != '*' && maze[i] != '\n')
            exit(84);
    close(fd);
    return 0;
}
