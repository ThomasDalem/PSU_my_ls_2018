/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Gets the differents groups rights of a file
*/
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

void get_usr_rights(char *rights, struct stat sb)
{
    if (sb.st_mode & S_IRUSR)
        rights[1] = 'r';
    else
        rights[1] = '-';
    if (sb.st_mode & S_IWUSR)
        rights[2] = 'w';
    else
        rights[2] = '-';
    if (sb.st_mode & S_IXUSR)
        rights[3] = 'x';
    else
        rights[3] = '-';
}

void get_grp_rights(char *rights, struct stat sb)
{
    if (sb.st_mode & S_IRGRP)
        rights[4] = 'r';
    else
        rights[4] = '-';
    if (sb.st_mode & S_IWGRP)
        rights[5] = 'w';
    else
        rights[5] = '-';
    if (sb.st_mode & S_IXGRP)
        rights[6] = 'x';
    else
        rights[6] = '-';
}

void get_oth_rights(char *rights, struct stat sb)
{
    if (sb.st_mode & S_IROTH)
        rights[7] = 'r';
    else
        rights[7] = '-';
    if (sb.st_mode & S_IWOTH)
        rights[8] = 'w';
    else
        rights[8] = '-';
    if (sb.st_mode & S_IXOTH)
        rights[8] = 'x';
    else
        rights[8] = '-';
}

char *get_rights(struct stat sb)
{
    char *rights = malloc(sizeof(char) * 10);

    if (rights == NULL)
        return (rights);
    if (S_ISREG(sb.st_mode))
        rights[0] = '-';
    else
        rights[0] = 'd';
    get_usr_rights(rights, sb);
    get_grp_rights(rights, sb);
    get_oth_rights(rights, sb);
    rights[9] = '\0';
    return (rights);
}