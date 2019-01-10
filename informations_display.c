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

int get_number_of_blocks(file_info_t *file_head)
{
    int blocks = 0;

    while (file_head != NULL) {
        if (file_head->name[0] != '.')
            blocks += file_head->nb_blocks;
        file_head = file_head->next;
    }
    return (blocks);
}

void display_informations(file_info_t *file)
{
    int blocks = get_number_of_blocks(file);

    my_printf("total %d\n", blocks / 2);
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
