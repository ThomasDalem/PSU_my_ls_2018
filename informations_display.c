/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Functions to displays severals information on the files
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_ls.h"

char *change_date_format(char *date)
{
    char *new_date = malloc(sizeof(char) * 18);
    int i = 4;
    int j = 0;

    while (i < 16) {
        new_date[j] = date[i];
        j++;
        i++;
    }
    new_date[j] = '\0';
    return (new_date);
}

void display_informations(file_info_t *file)
{
    while (file != NULL) {
        if (file->name[0] != '.') {
            write(1, file->rights, my_strlen(file->rights));
            write(1, " ", 1);
            my_put_nbr(file->nbr_of_links);
            write(1, " ", 1);
            write(1, file->owner_name, my_strlen(file->owner_name));
            write(1, " ", 1);
            write(1, file->owner_group, my_strlen(file->owner_group));
            write(1, " ", 1);
            my_put_nbr(file->file_size);
            write(1, " ", 1);
            file->last_time_modified = change_date_format(file->last_time_modified);
            write(1, file->last_time_modified, my_strlen(file->last_time_modified));
            free(file->last_time_modified);
            write(1, " ", 1);
            write(1, file->name, my_strlen(file->name));
            write(1, "\n", 1);
        }
        file = file->next;
    }
}
