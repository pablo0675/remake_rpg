/*
** EPITECH PROJECT, 2022
** lib_print
** File description:
** lib_print
*/

#include "printf.h"

static int my_compare(char const *s1, char const *s2, int n)
{
    for (int i = 0; s1[i] != '\0' && i < n; i = i + 1)
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    return 0;
}

int my_strcmp(char const *s1, char const *s2, int n)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);

    if (len1 < len2)
        return (0 - s2[len1]);
    if (len2 < len1)
        return (s1[len2]);
    if (len1 < n)
        n = len1;
    else
        return (my_compare(s1, s2, n));
}
