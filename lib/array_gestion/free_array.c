/*
** EPITECH PROJECT, 2022
** lib_print
** File description:
** lib_print
*/

#include "my_lib.h"

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}
