/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Functions to retreive several information of a file
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "my_ls.h"
#include "my_printf.h"

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
    if (file_head == NULL)
        return (NULL);
    while (file_head->next != NULL)
        file_head = file_head->next;
    return (file_head);
}

void get_groups_names(file_info_t *file, struct stat sb)
{
    struct passwd *pwd = getpwuid(sb.st_uid);
    struct group *grp = getgrgid(sb.st_gid);

    file->owner_name = pwd->pw_name;
    file->owner_group = grp->gr_name;
}

file_info_t *retrieve_info(file_info_t **file_hd, char *filename, char *filepath, struct stat sb)
{
    file_info_t *file = malloc(sizeof(file_info_t));
    file_info_t *last_node = get_last_node(*file_hd);

    if (file == NULL || stat(filepath, &sb) == -1)
        return (NULL);
    get_groups_names(file, sb);
    file->rights = get_rights(sb);
    file->nbr_of_links = sb.st_nlink;
    file->name = filename;
    file->file_size = sb.st_size;
    file->time_modified = ctime(&sb.st_mtime);
    file->time_modified = change_date_format(file->time_modified);
    file->nb_blocks = sb.st_blocks;
    if (*file_hd == NULL)
        *file_hd = file;
    else
        last_node->next = file;
    file->next = NULL;
    return (file);
}

file_info_t *get_dir_infos(char const *filepath, struct dirent *dir, DIR *dirp)
{
    file_info_t *file_head = NULL;
    char *file_path = NULL;
    struct stat sb;

    dir = readdir(dirp);
    while (dir != NULL) {
        file_path = create_filepath(filepath, dir->d_name);
        if (stat(file_path, &sb) == -1)
            return (NULL);
        retrieve_info(&file_head, dir->d_name, file_path, sb);
        dir = readdir(dirp);
        free(file_path);
    }
    return (file_head);
}
