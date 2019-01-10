/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Functions for my_printf
*/
#include <stdlib.h>

char *my_revstr(char *str);
void my_putstr(char const *str);

void display_octal2(int nb)
{
    char *oct;
    int i = 0;
    int quot = nb;
    int remainder = 0;

    oct = malloc(sizeof(char) * 11);
    while (quot != 0) {
        remainder = quot % 8;
        oct[i] = remainder + '0';
        i++;
        quot /= 8;
    }
    my_revstr(oct);
    my_putstr(oct);
}
