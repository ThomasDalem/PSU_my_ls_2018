/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Main function of the my_ls project
*/
#include <unistd.h>
#include "my_printf.h"
#include "my_ls.h"

int main(int ac, char **av)
{
    flags_t *flags = NULL;
    int i = 0;

    if (ac == 1) {
        write(1, "Wrong number of arguments.\nUsage : \n", 37);
        write(1, "./my_ls, -[flags] [file|directory]\n", 35);
        return (84);
    }
    flags = get_flags(ac, av);
    while (av[i][0] != '-' && i < ac - 1)
        i++;
    while (av[i][0] == '-' && i < ac - 1)
        i++;
    return (my_ls(av[i], flags));
}
