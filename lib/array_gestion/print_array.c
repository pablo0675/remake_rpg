/*
** EPITECH PROJECT, 2022
** lib_print
** File description:
** lib_print
*/

#include "my_lib.h"

void print_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        for (int x = 0; array[i][x] != '\0'; x++)
            my_putchar(array[i][x]);
        my_putchar('a');
        my_putchar('\n');
    }
}