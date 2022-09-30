/*
** EPITECH PROJECT, 2022
** lib_print
** File description:
** lib_print
*/

#include "my_lib.h"

static char *my_itoa_neg(long long number, int i, char *str)
{
    str = malloc(sizeof(char) * (i + 2));
    number *= -1;
    for (int x = 0; number != 0; x++) {
        str[x] = number % 10;
        number = number / 10;
    }
    str[i + 1] = '-';
    str[i + 2] = '\0';
    str = my_revstr(str);
    return str;
}

char *my_itoa(long long number)
{
    int i = 0;
    char *str = NULL;
    long long nb = number;

    for (; nb != 0; i++)
        nb = nb / 10;
    if (number < 0)
        return (my_itoa_neg(number, i , str));
    str = malloc(sizeof(char) * (i + 1));
    for (int x = 0; number != 0; x++) {
        str[x] = number % 10;
        number = number / 10;
    }
    str[i + 1] = '\0';
    str = my_revstr(str);
    return str;
}

long long my_atoi(char *av)
{
    long long i = 0;

    for (int a = 0; av[a] != '\0'; a++) {
        if (av[a] >= '0' && av[a] <= '9') {
            i *= 10;
            i += av[a] - '0';
        } else
            return (i);
    }
    return (i);
}

long long my_get_nbr(char *av)
{
    while ((av[0] > '9' || av[0] < '0') && av[0])
        av++;
    return (my_atoi(av));
}