/*
** EPITECH PROJECT, 2021
** headers
** File description:
** lib
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>

static const char flag[] = "disaf";

typedef struct print_s {
    char **strings;
    va_list arg;
} print_t;

void my_putchar(char c);
int my_strlen(char const *str);
void my_put_nbr(long long nb);
void my_putstr(char const *str);
int my_printf(char const *str, ...);
void my_puterror(char const *str);
void my_print_free(void *obj);

#endif /* !MY_H_ */
