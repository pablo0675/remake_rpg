/*
** EPITECH PROJECT, 2021
** int_to_str
** File description:
** convert an int into a str
*/

#include "my_rpg.h"

int my_intlen(int nb)
{
    int rep;

    if (nb == 0)
        return 1;
    for (int i = 1; nb != 0; i = i + 1) {
        nb = (nb - nb % 10) / 10;
        rep = i;
    }
    return rep;
}

char *int_to_str(int nb)
{
    char *res = malloc(sizeof(char) * (my_intlen(nb) + 1));
    int i = 0;
    int n = 1;
    int len = my_intlen(nb);

    if (nb < 0)
        n = -1;
    for (; i < len; i++) {
        res[i] = DTOA(nb % 10);
        nb = (nb - nb % 10) / 10;
    }
    if (n == -1) {
        res[i] = '-';
        i += 1;
    }
    res[i] = '\0';
    res = my_revstr(res);
    return res;
}
