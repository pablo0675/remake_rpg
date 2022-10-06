#include "../includes/my_rpg.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void get_arguments(game_t *game, int ac, char **av)
{
    game->flag->nb_players = 1;
    game->flag->game_difficulty = 1;
    game->flag->map_size[0] = 10;
    game->flag->map_size[1] = 10;
    game->flag->help = 0;

    for (int i = 0; i < ac; i++) {
        if (av[i][0] == '-' && av[i][1] == 'h')
            game->flag->help = 1;
        if (av[i][0] == '-' && av[i][1] == 'p' && isdigit(av[i + 1][0]))
            game->flag->nb_players = atoi(av[i + 1]);
        if (av[i][0] == '-' && av[i][1] == 'd' && isdigit(av[i + 1][0]))
            game->flag->game_difficulty = atoi(av[i + 1]);
        if (av[i][0] == '-' && av[i][1] == 'm' && (isdigit(av[i + 1][0]) && isdigit(av[i + 2][0]))) {
            game->flag->map_size[0] = atoi(av[i + 1]);
            game->flag->map_size[1] = atoi(av[i + 2]);
        }
    }
}
