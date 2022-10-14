/*
** EPITECH PROJECT, 2022
** lib
** File description:
** lib
*/

#include "my_rpg.h"
#include <stdlib.h>

sfRenderWindow *my_create_window2(char *name, int width, int height)
{
    sfRenderWindow *window;
    sfVideoMode mode;
    int flags = sfClose | sfTitlebar | sfResize;

    mode.height = height;
    mode.width = width;
    mode.bitsPerPixel = 32;

    window = sfRenderWindow_create(mode, name, flags, NULL);
    return (window);
}

game_t *my_create_window(int height, int width, char *name, game_t *game)
{
    game->window = malloc(sizeof(window_t));
    if (game->window == NULL) {
        return (NULL);
    }
    game->window->height = height;
    game->window->width = width;
    game->window->window = my_create_window2(name, game->window->width,
    game->window->height);
    return (game);
}
