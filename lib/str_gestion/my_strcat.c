/*
** EPITECH PROJECT, 2022
** lib_print
** File description:
** lib_print
*/

#include "printf.h"

char *my_strcat(char *dest, char const *src)
{
    int len_dest = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[len_dest] = src[i];
        len_dest++;
        i++;
    }
    dest[len_dest] = '\0';
    return dest;
}
