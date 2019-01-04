/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Functions to displays severals information on the files
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

void display_files(DIR *fd)
{
    struct dirent *dir = readdir(fd);

    while (dir != NULL) {
        write(1, dir->d_name, my_strlen(dir->d_name));
        write(1, "\n", 1);
        dir = readdir(fd);
    }
}
