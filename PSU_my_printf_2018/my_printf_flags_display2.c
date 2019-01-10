/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Functions for my_printf
*/
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

char *my_revstr(char *str);
void my_putstr(char const *str);
void display_octal2(int nb);

void display_hex_lower(va_list *nb)
{
    char *hex;
    int i = 0;
    int quot = va_arg(*nb, int);
    int remainder = 0;

    hex = malloc(sizeof(char) * 11);
    while (quot != 0) {;
        remainder = quot % 16;
        if (remainder < 10)
            hex[i++] = 48 + remainder;
        else
            hex[i++] = 87 + remainder;
        quot /= 16;
    }
    my_revstr(hex);
    my_putstr(hex);
}

void display_hex_upper(va_list *nb)
{
    char *hex;
    int i = 0;
    int quot = va_arg(*nb, int);
    int remainder = 0;

    hex = malloc(sizeof(char) * 11);
    while (quot != 0) {
        remainder = quot % 16;
        if (remainder < 10)
            hex[i++] = 48 + remainder;
        else
            hex[i++] = 55 + remainder;
        quot /= 16;
    }
    my_revstr(hex);
    my_putstr(hex);
}

void display_octal(va_list *nb)
{
    char *oct;
    int i = 0;
    int quot = va_arg(*nb, int);
    int remainder = 0;

    oct = malloc(sizeof(char) * 10);
    while (quot != 0) {
        remainder = quot % 8;
        oct[i] = remainder + '0';
        i++;
        quot /= 8;
    }
    my_revstr(oct);
    my_putstr(oct);
}

void display_binary(va_list *nb)
{
    char *binary;
    int i = 0;
    int quot = va_arg(*nb, int);
    int remainder = 0;

    binary = malloc(sizeof(char) * 11);
    while (quot != 0) {
        remainder = quot % 2;
        binary[i] = remainder + '0';
        i++;
        quot /= 2;
    }
    my_revstr(binary);
    my_putstr(binary);
}

void display_string_ascii(va_list *str)
{
    int i = 0;
    char *disp_str = va_arg(*str, char *);

    while (disp_str[i] != '\0') {
        if (disp_str[i] >= 32 && disp_str[i] <= 127)
            write(1, &disp_str[i], 1);
        else {
            write(1, "\\", 1);
            display_octal2(disp_str[i]);
        }
        i++;
    }
}
