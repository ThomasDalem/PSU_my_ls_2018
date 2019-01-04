/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Main function of the my_ls project
*/
#include <unistd.h>
#include "my_ls.h"

int main(int ac, char **av)
{
    if (ac == 1) {
        write(1, "Wrong number of arguments.\nUsage : \n", 37);
        write(1, "./my_ls, -[flags] [file|directory]\n", 35);
    }
    return (my_ls(av[1]));
}