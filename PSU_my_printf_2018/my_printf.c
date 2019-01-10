/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Copy of the printf function
*/
#include <unistd.h>
#include <stdarg.h>

void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
void display_integer(va_list *nb);
void display_char(va_list *c);
void display_string(va_list *str);
void display_hex_lower(va_list *nb);
void display_hex_upper(va_list *nb);
void display_unsigned_int(va_list *nb);
void display_pointer(va_list *addr);
void display_octal(va_list *nb);
void display_binary(va_list *nb);
void display_string_ascii(va_list *str);

void disp_argument(char flag, va_list *ap)
{
    int i = 0;
    void (*fptr[11]) (va_list *) = {&display_char, &display_integer,
                                    &display_integer,
                                    &display_unsigned_int,
                                    &display_string,
                                    &display_hex_lower,
                                    &display_hex_upper,
                                    &display_pointer,
                                    &display_octal,
                                    &display_binary,
                                    &display_string_ascii};
    int flags[11] = {'c', 'd', 'i', 'u', 's', 'x', 'X', 'p', 'o', 'b', 'S'};

    while (flags[i] != flag && i < 10)
        i++;
    if (flags[i] != flag && i >= 10)
        return;
    (*fptr[i]) (ap);
}

int check_flag(const char *format, int pos, va_list *ap)
{
    int i = pos;
    int y = 0;
    int flags[12] = {'c', 'd', 'i', 'u', 's', 'x', 'X', 'p', 'o', 'b',
                     'S', '%'};

    while (format[i] != flags[y] && format[i] != '\0') {
        if (y >= 11) {
            y = 0;
            i++;
        }
        y++;
    }
    if (format[i] == flags[y]) {
        if (format[i] != 's' && format[i - 1] != '%')
            write(1, " ", 1);
        if (format[i] == '%')
            write(1, "%", 1);
        disp_argument(format[i], ap);
    }
    return (i);
}

int my_printf(const char *format, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, format);
    while (format[i] != '\0') {
        if (format[i] == '%' && format[i + 1] != '%') {
            i++;
            i = check_flag(format, i, &ap);
        }
        else if (format[i] == '%' && format[i + 1] == '%') {
            my_putchar('%');
            i++;
        }
        else
            my_putchar(format[i]);
        i++;
    }
    va_end(ap);
    return (0);
}
