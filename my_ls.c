/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_ls
*/
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include "my_ls.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

void destroy_files_infos(file_info_t *files_head)
{
    file_info_t *next_file = NULL;

    while (files_head != NULL) {
        free(files_head->rights);
        //free(files_head->last_time_modified);
        next_file = files_head->next;
        free(files_head);
        files_head = next_file;
    }
    //free(files_head);
}

int my_ls(char const *filepath)
{
    struct stat sb;
    DIR *dirp = NULL;
    struct dirent *dir = NULL;
    file_info_t *filesinfos = NULL;

    if (stat(filepath, &sb) == -1)
        return (84);
    dirp = opendir(filepath);
    filesinfos = retrieve_directory_infos(filepath, dir, dirp);
    display_informations(filesinfos);
    destroy_files_infos(filesinfos);
    closedir(dirp);
    return (0);
}
