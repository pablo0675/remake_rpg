/*
** EPITECH PROJECT, 2022
** lib_print
** File description:
** lib_print
*/

#include "my_lib.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
