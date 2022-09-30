/*
** EPITECH PROJECT, 2022
** lib_array
** File description:
** array_cat
*/

#include "my_lib.h"

int my_array_len(char **array)
{
    int i = 0;

    while (array[i] != NULL)
        i++;
    return i;
}

void array_str_cat(char ***array, char *str)
{
    int len = my_array_len(*array);
    char **tmp = malloc((len + 2) * sizeof(char *));

    if (tmp == NULL)
        return;
    tmp[len + 1] = NULL;
    for (int i = 0; i < len; i++)
        tmp[i] = (*array)[i];
    tmp[len] = str;
    free(*array);
    *array = tmp;
}

void array_cat(char ***array, char **array_2)
{
    for (int i = 0; array_2[i]; i++) {
        array_str_cat(array, array_2[i]);
    }
}

void remove_str_in_array(char ***array, char *str, int line)
{
    int len = my_array_len(*array);
    char **tmp = malloc((len - 1) * sizeof(char *));

    if (tmp == NULL)
        return;
    tmp[len - 1] = NULL;
    for (int i = 0; i < line; i++)
        tmp[i] = (*array)[i];
    for (int i = line; i < len - 1; i++)
        tmp[i] = (*array)[i + 1];
    free(*array);
    *array = tmp;
}
