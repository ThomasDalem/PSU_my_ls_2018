/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Functions to retreive several information of a file
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "my_ls.h"

char *create_filepath(char const *filepath, char *filename)
{
    int size_path = my_strlen(filepath);
    int size_name = my_strlen(filename);
    char *full_path = malloc(sizeof(char) * (size_path + size_name) + 1);
    int i = 0;
    int j = 0;

    if (full_path == NULL)
        return (NULL);
    while (filepath[i] != '\0') {
        full_path[i] = filepath[i];
        i++;
    }
    while (filename[j] != '\0') {
        full_path[i + j] = filename[j];
        j++;
    }
    full_path[i + j] = '\0';
    return (full_path);
}

file_info_t *get_last_node(file_info_t *file_head)
{
    file_info_t *last_file = file_head;

    while (last_file != NULL && last_file->next != NULL)
        last_file = last_file->next;
    return (last_file);
}

int retrieve_info(file_info_t **file_hd, char const *filepath, char *filename)
{
    char *full_path = create_filepath(filepath, filename);
    file_info_t *last_node = get_last_node(*file_hd);
    file_info_t *file = malloc(sizeof(file_info_t));
    struct stat sb;

    if (file == NULL || full_path == NULL)
        return (84);
    if (stat(filepath, &sb) == -1)
        return (84);
    file->name = filename;
    if (last_node != NULL)
        last_node->next = file;
    else
        *file_hd = file;
    return (0);
}

file_info_t *retrieve_directory_infos(char const *filepath)
{
    file_info_t *file = NULL;
    DIR *dirp = opendir(filepath);
    struct dirent *dir= NULL;

    if (dirp == NULL)
        return (NULL);
    dir = readdir(dirp);
    while (dir != NULL) {
        retrieve_info(&file, filepath, dir->d_name);
        dir = readdir(dirp);
    }
    closedir(dirp);
    return (file);
}
