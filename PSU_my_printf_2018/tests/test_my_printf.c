/*
** EPITECH PROJECT, 2018
** my_printf
** File description:
** Tests the function my_printf
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_printf.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, displayed_value_equal, .init = redirect_all_std)
{
    my_printf("%s32%s%i\n", "salut", "moulinette", 43);
    cr_assert_stdout_eq_str("salut32moulinette43\n");
}

Test(my_printfflags1, displayed_value_equal, .init = redirect_all_std)
{
    my_printf("%i%u%d%c%s%p%d", -21, 42, 913, 'M', "WOW", 2000, 0);
    cr_assert_stdout_eq_str("-2142913MWOW0x7d00");
}

Test(my_printfflags2, displayed_value_is_equal, .init = redirect_all_std)
{
    my_printf("%x -> %X -> %o %b test %S", 2000, 2000, 2000, 2000, "Bonj\nour");
    cr_assert_stdout_eq_str("7d0 -> 7D0 -> 3720 11111010000 test Bonj\\12our");
}

Test(my_printf_spec_cases, displayed_value_is_equal, .init = redirect_all_std)
{
    my_printf("%% %M");
    cr_assert_stdout_eq_str("% ");
}
