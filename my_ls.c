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

int my_strlen(char *str)
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
        free(files_head->time_modified);
        next_file = files_head->next;
        free(files_head);
        files_head = next_file;
    }
}

int check_directory(char *filepath)
{
    int i = my_strlen(filepath);
    struct stat sb;

    if (stat(filepath, &sb) == -1)
        return (84);
    if (!S_ISREG(sb.st_mode) && filepath[i - 1] != '/')
        return (2);
    else if (!S_ISREG(sb.st_mode) && filepath[i - 1] == '/')
        return (1);
    else
        return (-1);
    return (0);
}

char *change_filepath(char *filepath)
{
    int size = my_strlen(filepath);
    char *new_filepath = malloc(sizeof(char) * (size + 1));

    new_filepath = my_strcpy(new_filepath, filepath);
    new_filepath[size] = '/';
    new_filepath[size + 1] = '\0';
    return (new_filepath);
}

int my_ls(char *filepath, flags_t *flags)
{
    DIR *dirp = NULL;
    struct dirent *dir = NULL;
    file_info_t *filesinfos = NULL;
    int is_dir = check_directory(filepath);

    if (is_dir == 84) {
        write(1, "Cannot access the requested file\n", 33);
        return (84);
    }
    else if (is_dir == 2)
        filepath = change_filepath(filepath);
    else if (is_dir == -1) {
        write(1, "This is a file\n", 15);
        return (84);
    }
    dirp = opendir(filepath);
    filesinfos = get_dir_infos(filepath, dir, dirp);
    display_informations(filesinfos, flags);
    destroy_files_infos(filesinfos);
    closedir(dirp);
    return (0);
}
