/*
** EPITECH PROJECT, 2022
** lib_print
** File description:
** lib_print
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src, int len)
{
    for (int i = 0; src[i]; i = i + 1)
        dest[i] = src[i];
    dest[len] = '\0';
    return (dest);
}