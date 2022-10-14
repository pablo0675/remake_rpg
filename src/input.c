/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** input
*/

#include "my_rpg.h"
#include <stdio.h>

void manage_click(game_t *game, sfEvent evt)
{
    if (game->status == 0)
        event_button(game, evt.mouseButton);
    if (game->status == 1 && evt.mouseButton.button == sfMouseLeft)
        player_attack(game);

}

int check_event(game_t *game, sfEvent evt)
{
    if (game->status == 1)
        move_events(game);
    while (sfRenderWindow_pollEvent(game->window->window, &evt)) {
        if (evt.type == sfEvtClosed) {
            sfRenderWindow_close(game->window->window);
            return 0;
        }
        if (evt.type == sfEvtMouseButtonPressed)
            manage_click(game, evt);
        if (evt.type == sfEvtKeyPressed)
            event_keyboard(game, evt);
        if (evt.type == sfEvtKeyReleased && (evt.key.code == sfKeyQ
        || evt.key.code == sfKeyD
        || evt.key.code == sfKeyZ
        || evt.key.code == sfKeyS))
            game->player->status = 0;
    }
    return 0;
}
