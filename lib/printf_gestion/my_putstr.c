/*
** EPITECH PROJECT, 2022
** lib_print
** File description:
** lib_print
*/

#include "my_lib.h"

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i = i + 1)
        my_putchar(str[i]);
}

void my_puterror(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(2, &str[i], 1);
}
