/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** input_keyboard
*/

#include "my_rpg.h"

static void skip_intro(game_t *game, sfEvent evt)
{
    sfSoundStatus bob = sfSound_getStatus(game->menu->music);

    if (evt.key.code == sfKeySpace || evt.key.code == sfKeyEscape) {
        if (bob == sfPlaying) {
            sfSound_stop(game->menu->music);
            return;
        }
    }
}

void move_events(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        move_player(game->player, -1, 0);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        move_player(game->player, 1, 0);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move_player(game->player, 0, -1);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move_player(game->player, 0, 1);
}

static void game_event(game_t *game, sfEvent evt)
{
    if (evt.key.code == sfKeyEscape)
        game->status = 2;
}

static void pause_events(game_t *game, sfEvent evt)
{
    if (evt.key.code == sfKeyEscape)
        game->status = 1;
}

int event_keyboard(game_t *game, sfEvent evt)
{
    if (game->status == 0)
        skip_intro(game, evt);
    if (game->status == 1)
        game_event(game, evt);
    else if (game->status == 2)
        pause_events(game, evt);
    return 0;
}
