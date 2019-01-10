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
#include <time.h>
#include <fcntl.h>
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
    char *time_modified;
    int nb_blocks;
    struct file_info_s *next;
} file_info_t;

int my_ls(char *filepath, flags_t *flags);
void get_infos(char *filepath);
file_info_t *get_dir_infos(char *filepath, struct dirent *dir, DIR *dirp);
int my_strlen(char *str);
void display_informations(file_info_t *file, flags_t *flags);
char *get_rights(struct stat sb);
char *my_strcpy(char *dest, char *src);
char *change_date_format(char *date);
flags_t *get_flags(int ac, char **av);


void has_r1(flags_t *flags);
void has_l(flags_t *flags);
void has_t(flags_t *flags);
void has_d(flags_t *flags);
void has_r2(flags_t *flags);

#endif /* MY_LS_H_ */
