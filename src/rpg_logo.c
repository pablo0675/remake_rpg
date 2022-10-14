/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** print logo
*/

#include "my_rpg.h"

void print_help(void)
{
    my_printf("             %smy_rpg%s\n\n", underlined_yellow, RESET);
    my_printf("%sUSAGE%s:       ./my_rpg\n", RED, RESET);
    my_printf("             -s save file -s1 save file_size\n");
    my_printf("             -h for help\n");
    my_printf("             -m x y for map\n");
    my_printf("             -c config file -c1 config file_size");
}

void print_logo(void)
{
    my_printf("%sMADE BY : \n"
    "         Clement Martin,\n"
    "         Stanislas Commenge,\n"
    "         Pablo Levy,\n"
    "         Viktor Bruggeman\n", BLUE, RESET);
    my_printf("%s         /\\_____/\\\n"
    "        /  o   o  \\\n"
    "       ( ==  ^  == )\n"
    "        )         (\n"
    "       (           )\n"
    "      ( (  )   (  ) )\n"
    "     (__(__)___(__)__)%s\n", RED, RESET);
}
