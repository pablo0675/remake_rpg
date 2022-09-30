/*
** EPITECH PROJECT, 2022
** lib_print
** File description:
** lib_print
*/

#include "my_lib.h"

void my_put_nbr(long long nb)
{
    long long nb2 = (long long)nb;
    if (nb2 < 0) {
        my_putchar('-');
        nb2 = nb2 * (-1);
    }
    if (nb2 >= 10)
        my_put_nbr(nb2 / 10);
    my_putchar((nb2 % 10) + '0');
}
