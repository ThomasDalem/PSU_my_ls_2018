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
#include <time.h>
#include "my_ls.h"
#include "my_printf.h"

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
            my_printf("%s %d ", file->rights, file->nbr_of_links);
            my_printf("%s %s ", file->owner_name, file->owner_group);
            my_printf("%d %s ", file->file_size, file->time_modified);
            my_printf("%s\n", file->name);
        }
        file = file->next;
    }
}
