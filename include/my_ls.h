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

int my_ls(char const *filepath);
void display_files(DIR *fd);

#endif /* !MY_LS_H_ */
