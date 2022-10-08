/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** start menu
*/

#include "my_rpg.h"

static void check_all_button_menu(button_t **button, game_t *g)
{
    sfVector2i mouse = g->window->mouse;

    for (int i = 0; button[i] != NULL; ++i) {
        if (sfFloatRect_contains(&(button[i]->rect), mouse.x, mouse.y)) {
            g->cursor_status = 1;
            update_calque(button[i], g->calque);
            return;
        }
    }
    reset_claque(g->calque);
    g->cursor_status = 0;
}

static void draw_all_button_menu(button_t **button, sfRenderWindow *window)
{
    for (int i = 0; button[i] != NULL; ++i) {
        sfRenderWindow_drawText(window, button[i]->text, NULL);
    }
}

static void play_music_menu(game_t *g)
{
    sfSoundStatus bob = sfSound_getStatus(g->menu->theme);

    if (bob == sfPlaying) {
        return;
    }
    sfSound_play(g->menu->theme);
}

int start_menu(game_t *g)
{
    sfSoundStatus bob = sfSound_getStatus(g->menu->music);

    if (bob == sfPlaying) {
        sfRenderWindow_drawSprite(g->window->window, g->menu->back, NULL);
        return 0;
    }
    play_music_menu(g);
    sfRenderWindow_drawSprite(g->window->window, g->menu->dark_back, NULL);
    sfRenderWindow_drawText(g->window->window, g->menu->title, NULL);
    draw_all_button_menu(g->menu->button, g->window->window);
    check_all_button_menu(g->menu->button, g);
    update_cursor(g);
    return 0;
}
