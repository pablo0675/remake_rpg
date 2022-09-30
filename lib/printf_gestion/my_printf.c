/*
** EPITECH PROJECT, 2022
** lib_print
** File description:
** lib_print
*/

#include "my_lib.h"

int is_modulo(va_list arg, char *strings[2], void (*tab[])(), int i)
{
    int a = 0;
    int x = 0;

    if (strings[0][i + 1] == '%') {
        my_putchar('%');
        x = 2;
    } else {
        ++i;
        for (a = 0; strings[1][a] != strings[0][i]; a++);
        tab[a](va_arg(arg, void *));
        x = 1;
    }
    return x;
}

int my_check(char *strings[2], int i)
{
    int a = 0;

    if (strings[0][i] != '%') {
        return 1;
    }
    if (strings[0][i] == '%' && strings[0][i + 1] == '%')
        return 1;
    for (int check = 0; strings[1][check] != '\0'; check++) {
        if (strings[1][check] == strings[0][i + 1])
            a = 1;
    }
    return a;
}

void my_free(print_t *print)
{
    free(print->strings[0]);
    free(print->strings[1]);
    free(print->strings);
    free(print);
}

char **my_init(char **strings, char const *str, char const *str2)
{
    strings[0] = my_strdup(str);
    strings[1] = my_strdup(str2);
    return strings;
}

int my_printf(char const *str, ...)
{
    print_t *print = malloc(sizeof(print_t));
    print->strings = malloc(sizeof(char *) * 2);
    void (*tab[])() = {my_put_nbr, my_put_nbr, my_putstr,
                       print_array, my_print_free};
    va_start(print->arg, str);
    print->strings = my_init(print->strings, str, flag);
    for (int i = 0; print->strings[0][i] != '\0'; i++) {
        if (my_check(print->strings, i) == 0)
            return 84;
        if (print->strings[0][i] == '%' && print->strings[0][i + 1] != '%')
            i = i + is_modulo(print->arg, print->strings, tab, i);
        else
            my_putchar(print->strings[0][i]);
    }
    va_end(print->arg);
    my_free(print);
    return 0;
}
