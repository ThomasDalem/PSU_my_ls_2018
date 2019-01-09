/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** my_ls header
*/

#ifndef MY_LS_H_
#define MY_LS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

typedef struct flags_s
{
    int l;
    int r1;
    int d;
    int r2;
    int t;
} flags_t;

typedef struct file_info_s
{
    char *name;
    char *rights;
    char *owner_name;
    char *owner_group;
    int nbr_of_links;
    int file_size;
    char *last_time_modified;
    struct file_info_s *next;
} file_info_t;

int my_ls(char const *filepath);
void get_infos(char const *filepath);
file_info_t *retrieve_directory_infos(char const *filepath, struct dirent *dir, DIR *dirp);
int my_strlen(char const *str);
void my_put_nbr(int nbr);
void display_informations(file_info_t *file);
char *get_rights(struct stat sb);

#endif /* MY_LS_H_ */
