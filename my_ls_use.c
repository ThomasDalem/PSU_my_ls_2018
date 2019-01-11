/*
** EPITECH PROJECT, 2019
** PSU_my_ls_2018
** File description:
** Uses the my_ls function and gives it the arguments
*/
#include <unistd.h>
#include "my_ls.h"
#include "my_printf.h"

int use_my_ls(int ac, char **av)
{
    flags_t *flags = NULL;
    int i = 0;
    int print_name = 0;

    flags = get_flags(ac, av);
    i++;
    while (av[i][0] == '-' && i < ac - 1)
        i++;
    if (ac - i > 1)
        print_name = 1;
    while (i < ac) {
        if (print_name == 1)
            my_printf("%s:\n", av[i]);
        if (my_ls(av[i], flags) == 84)
            return (84);
        i++;
        if (print_name == 1 && i < ac)
            write(1, "\n", 1);
    }
    return (0);
}
