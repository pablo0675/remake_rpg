/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** effect_button
*/

#include "my_rpg.h"

static int make_effect(int fct, game_t *game)
{
    if (fct == QUIT) {
        sfRenderWindow_close(game->window->window);
        return 1;
    } else if (fct == START) {
        sfSound_stop(game->menu->theme);
        ++game->status;
    }
    return 0;
}

static int check_event_button(button_t **button, game_t *g,
sfMouseButtonEvent act)
{
    sfSoundStatus bob = sfSound_getStatus(g->menu->music);

    if (bob == sfPlaying) {
        sfSound_stop(g->menu->music);
        return 0;
    }
    for (int i = 0; button[i] != NULL; ++i) {
        if (sfFloatRect_contains(&button[i]->rect, act.x, act.y)) {
            g->cursor_status = 0;
            return make_effect(button[i]->fct, g);
        }
    }
    return 0;
}

int event_button(game_t *game, sfMouseButtonEvent act)
{
    if (game->status == 0)
        return check_event_button(game->menu->button, game, act);
    return 0;
}
