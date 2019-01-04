/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_ls
*/
#include <unistd.h>
#include <dirent.h>
#include "my_ls.h"

int my_ls(char const *filepath)
{
    struct stat sb;
    DIR *fd= opendir(filepath);

    if (fd == NULL)
        return (84);
    if (stat(filepath, &sb) == -1) {
        write(1, "Can't find the file\n", 20);
        return(84);
    }
    display_files(fd);
    closedir(fd);
    return (0);
}
