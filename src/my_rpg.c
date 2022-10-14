/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** parse flag
*/

#include "../include/my_rpg.h"

game_t *parse_flag(char *str, game_t *g, char *str2)
{
    if (my_strcmp(str, "-h", 2) == 0) {
        print_help();
        return NULL;
    }
    if (my_strcmp(str, "-s", 2) == 0)
         g = retrieve_save(g, str2);
    if (my_strcmp(str, "-c", 2) == 0) {
        g = retrieve_config(g, str2);
    }
    return g;
}

/*STATUS :
0 = menu
1 = ingame
2 = pause
3 = inventoy
4 = win
5 = lose*/
void manage_status(game_t *g)
{
    switch (g->status) {
    case 0:
        start_menu(g);
        break;
    case 1:
        run_game(g);
        break;
    case 2:
        run_pause(g);
        break;
    case 4:
        run_win(g);
        break;
    case 5:
        run_lose(g);
        break;
    }
}

void my_loop(game_t *g)
{
    sfEvent evt;
    sfTexture *text_calque = sfTexture_create(SCREEN_WIDTH, SCREEN_HEIGHT);
    sfSprite *calque = sfSprite_create();;

    g->my_clock->clock = sfClock_create();
    my_create_window(1080, 1920, "castlevachat", g);
    sfRenderWindow_setFramerateLimit(g->window->window, 45);
    sfRenderWindow_setMouseCursorVisible(g->window->window, sfFalse);
    sfSound_play(g->menu->music);
    while (sfRenderWindow_isOpen(g->window->window)) {
        update_sprite_frompixel(text_calque, g->calque, calque);
        g->my_clock->time = sfClock_getElapsedTime(g->my_clock->clock);
        g->my_clock->seconds = g->my_clock->time.microseconds / 1000000.0;
        sfRenderWindow_clear(g->window->window, sfBlack);
        check_event(g, evt);
        manage_status(g);
        sfRenderWindow_drawSprite(g->window->window, calque, NULL);
        sfRenderWindow_display(g->window->window);
    }
}

int my_rpg(char **av)
{
    game_t *g = malloc(sizeof(game_t));

    if (g == NULL)
        return 0;
    if (init_struct(g) == NULL)
        return 0;
    g->difficulties = 1;
    for (int i = 0; av[i] != NULL; i++)
        g = parse_flag(av[i], g, av[i + 1]);
    if (g == NULL)
        return 84;
    g->map->actual_room = g->map->size_x - 1;
    init_map(g);
    my_loop(g);
    free_struct(g);
    return 0;
}
