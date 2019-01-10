/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Functions to fill the flag struct
*/
#include "my_ls.h"

void has_l(flags_t *flags)
{
    flags->l = 1;
}

void has_r1(flags_t *flags)
{
    flags->r1 = 1;
}

void has_r2(flags_t *flags)
{
    flags->r2 = 1;
}

void has_d(flags_t *flags)
{
    flags->d = 1;
}

void has_t(flags_t *flags)
{
    flags->t = 1;
}
