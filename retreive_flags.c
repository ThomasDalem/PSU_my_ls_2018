/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Functions to retreive the flags given by the user
*/

#include <stdlib.h>
#include "my_ls.h"

void init_flags(flags_t *flags)
{
    flags->d = 0;
    flags->l = 0;
    flags->r1 = 0;
    flags->r2 = 0;
    flags->t = 0;
}

void check_flags(char *arg, flags_t *flags)
{
    char *flags_char = "lrRdt";
    void (*fptr[5]) (flags_t*) = {&has_l, &has_r1, &has_r2, &has_d, &has_t};
    int i = 0;
    int j = 0;

    while (arg[i] != '\0') {
        j = 0;
        while (arg[i] != flags_char[j] && j < 5)
            j++;
        if (arg[i] == flags_char[j])
            fptr[j](flags);
        i++;
    }
}

flags_t *get_flags(int ac, char **av)
{
    flags_t *flags = malloc(sizeof(flags_t));
    int i = 0;

    if (flags == NULL)
        return (NULL);
    init_flags(flags);
    while (i < ac) {
        if (av[i][0] == '-')
            check_flags(av[i], flags);
        i++;
    }
    return (flags);
}
