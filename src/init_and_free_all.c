/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** init struct
*/

#include "my_rpg.h"
#include "init.h"

game_t *init_struct_2(game_t *g)
{
    g->player = malloc(sizeof(sprite_t));
    g->window = malloc(sizeof(window_t));
    g->my_clock = malloc(sizeof(my_clock_t));
    g->flags = malloc(sizeof(flag_t));
    g->map = malloc(sizeof(map_t));
    g->window = malloc(sizeof(window_t));
    g->music = malloc(sizeof(music_t));
    g->my_clock = malloc(sizeof(my_clock_t));
    g->music->sound = malloc(sizeof(sound_t));
    if (g->music == NULL || g->player == NULL || g->window == NULL ||
        g->my_clock == NULL)
        return NULL;
    return g;
}

game_t *init_struct(game_t *g)
{
    init_struct_2(g);
    g->obj = malloc(sizeof(object_t));
    g->menu = init_menu();
    g->player = init_player();
    g->enemies = init_enemies(3);
    g->difficulties = 3;
    g->hud = init_hud();
    g->end = init_end();
    set_cursor(g);
    if (g->music == NULL || g->flags == NULL || g->player == NULL ||
        g->window == NULL || g->menu == NULL || g->obj == NULL)
        return NULL;
    g->status = 0;
    g->cursor_status = 0;
    g->map->size_x = 10;
    g->calque = init_color();
    return g;
}

void destroy_music(game_t *g)
{
    sfMusic_destroy(g->music->game);
    sfMusic_destroy(g->music->menu);
    sfMusic_destroy(g->music->fights);
    free(g->music->sound);
}

void destroy_all(game_t *g)
{
    sfRenderWindow_destroy(g->window->window);
}

void free_struct(game_t *g)
{
    destroy_all(g);
    free(g->player);
    free(g->music);
    free(g->flags);
    free(g->my_clock);
    free(g->window);
    free(g->menu);
    free(g);
}
