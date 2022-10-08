/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** text
*/

#include "my_rpg.h"

static void up(sfUint8 *colo)
{
    int tmp = (SCREEN_WIDTH * 4);

    for (int i = 0; i < (SCREEN_WIDTH * SCREEN_WIDTH * 4) / 2; i += 4) {
        tmp = rand() % 2;
        tmp = tmp == 0 ? -4 : 4;
        if (colo[i + 1] != 0 && colo[i + 3] > 20) {
            colo[i - tmp] = 0;
            colo[i - tmp + 1] = 255;
            colo[i - tmp + 2] = 255;
            colo[i - tmp + 3] = colo[i + 3] - 20;
        }
        colo[i] = 0;
        colo[i + 1] = 0;
        colo[i + 2] = 0;
        colo[i + 3] = 0;
    }
}

static void check_rand(int tmp, sfUint8 *colo)
{
    int rand_num = rand() % 500;

    if (rand_num == 0) {
        colo[tmp] = 0;
        colo[tmp + 1] = 255;
        colo[tmp + 2] = 255;
        colo[tmp + 3] = 255;
    }
}

void rain(sfUint8 *colo)
{
    int tmp = (SCREEN_WIDTH * 4);

    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT * 4; i += 4) {
        if (colo[i] != 0 ) {
            colo[i - tmp] = colo[i];
            colo[i - tmp + 1] = colo[i + 1];
            colo[i - tmp + 2] = colo[i + 2];
            colo[i - tmp + 3] = colo[i + 3];
        }
        colo[i] = 0;
        colo[i + 1] = 0;
        colo[i + 2] = 0;
        colo[i + 3] = 0;
    }
}

void init_rain(sfUint8 *colo)
{
    for (int i = 0; i < 4 * SCREEN_WIDTH * SCREEN_HEIGHT; i += 4) {
        if (i % SCREEN_WIDTH <= 25 || i % SCREEN_WIDTH >=  SCREEN_WIDTH - 50)
            colo[i + 1] = 255;
        else
            colo[i + 1] = 0;
        colo[i] = 255;
        colo[i + 2] = 0;
        colo[i + 3] = 255;
    }
}

void update_calque(button_t *button, sfUint8 *colo)
{
    sfFloatRect rect = sfText_getGlobalBounds(button->text);
    int tmp = (SCREEN_WIDTH * 4) * rect.top;
    int k = 0;

    up(colo);
    for (int i = 0; i < rect.height; i += 1) {
        for (int j = 0; j < rect.width; j += 1) {
            k = j * 4 + rect.left * 4 ;
            check_rand(tmp + k - rect.width * 4, colo);
            check_rand(tmp + k + rect.width * 4, colo);
        }
        tmp += SCREEN_WIDTH * 4;
    }
}
