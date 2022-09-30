/*
** EPITECH PROJECT, 2022
** lib_print
** File description:
** lib_print
*/

#include "printf.h"

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i]; i = i + 1);
    return (i);
}
