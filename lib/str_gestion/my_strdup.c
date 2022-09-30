/*
** EPITECH PROJECT, 2022
** lib_print
** File description:
** lib_print
*/

#include <stdlib.h>
#include "printf.h"

char *my_strcpy(char *dest, char const *src, int len2);

int my_strlen(char const *str);

char *my_strdup(char const *str)
{
    int len = my_strlen(str) + 1;
    char *dup = malloc(len);

    dup = my_strcpy(dup, str, len - 1);
    dup[len - 1] = '\0';
    return dup;
}

char *my_strndup(char const *str, int n)
{
    char *dup = malloc(sizeof(char) * (n + 1));

    dup = my_strcpy(dup, str, n);
    dup[n] = '\0';
    return dup;
}
