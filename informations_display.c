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
#include "my_ls.h"

void display_informations(file_info_t *file)
{
    while (file != NULL) {
        write(1, file->name, my_strlen(file->name));
        write(1, "\n", 1);
        file = file->next;
    }
}
