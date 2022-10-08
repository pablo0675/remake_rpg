/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_calque
*/

#include "my_rpg.h"
#include <stdio.h>

sfUint8 *init_color(void)
{
    sfUint8 *colo = malloc(sizeof(sfUint8) *
    (4 * SCREEN_WIDTH * SCREEN_WIDTH));

    for (int i = 0; i < 4 * SCREEN_WIDTH * SCREEN_WIDTH; ++i) {
        colo[i] = 0;
    }
    return colo;
}

void reset_claque(sfUint8 *colo)
{
    for (int i = 0; i < 4 * SCREEN_WIDTH * SCREEN_WIDTH; ++i) {
        colo[i] = 0;
    }
}

sfSprite *update_sprite_frompixel(sfTexture *texture,
    sfUint8 *colo, sfSprite *sprite)
{
    sfTexture_updateFromPixels(texture, colo,
    SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0);
    sfSprite_setTexture(sprite, texture, sfFalse);
    return sprite;
}
