/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_ls
*/
#include <unistd.h>
#include <dirent.h>
#include "my_ls.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

int my_ls(char const *filepath)
{
    file_info_t *filesinfos = retrieve_directory_infos(filepath);

    display_informations(filesinfos);
    return (0);
}
