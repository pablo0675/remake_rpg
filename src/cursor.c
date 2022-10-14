/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** cursor
*/

#include "my_rpg.h"
#include "init.h"

void update_cursor(game_t *g)
{
    sfIntRect rect = {0, 0, 270, 274};
    sfVector2f pos = {g->window->mouse.x, g->window->mouse.y};

    g->window->mouse.x = sfMouse_getPositionRenderWindow(g->window->window).x;
    g->window->mouse.y = sfMouse_getPositionRenderWindow(g->window->window).y;
    rect.left = g->cursor_status * 270;
    sfSprite_setTextureRect(g->cursor, rect);
    sfSprite_setPosition(g->cursor, pos);
    sfRenderWindow_drawSprite(g->window->window, g->cursor, NULL);
}

void set_cursor(game_t *g)
{
    sfVector2f scale = {CURSOR_SIZE, CURSOR_SIZE};

    g->cursor = malloc(sizeof(object_t));
    if (!g->cursor)
        return;
    g->cursor_status = 0;
    g->cursor = create_sprite("assets/cursor.png");
    sfSprite_setScale(g->cursor, scale);
    return;
}
