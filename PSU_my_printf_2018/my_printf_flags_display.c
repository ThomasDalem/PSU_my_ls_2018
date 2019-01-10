/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Functions to display the flags in my_printf
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
char my_revstr(char *str);

void display_integer(va_list *nb)
{
    my_put_nbr(va_arg(*nb, int));
}

void display_unsigned_int(va_list *number)
{
    my_put_nbr(va_arg(*number, unsigned int));
}

void display_char(va_list *c)
{
    my_putchar(va_arg(*c, int));
}

void display_string(va_list *str)
{
    my_putstr(va_arg(*str, char *));
}

void display_pointer(va_list *addr)
{
    char *hex;
    int i = 0;
    int quot = va_arg(*addr, int);
    int remainder = 0;

    hex = malloc(sizeof(char) * 10);
    while (quot != 0) {;
        remainder = quot % 16;
        if (remainder < 10)
            hex[i++] = 48 + remainder;
        else
            hex[i++] = 87 + remainder;
        quot /= 16;
    }
    my_revstr(hex);
    my_putstr("0x");
    my_putstr(hex);
}
