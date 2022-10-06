#include "my_rpg.h"
#include <unistd.h>
#include "my_lib.h"
#include "struct.h"

void print_usage()
{
    my_printf("%sUSAGE:\n"
              "-h                   :      help, print the usage and quit "
              "the program\n"
              "-d [number]          :      difficulty, adjust difficulty from "
              "1-10 any"
              " number given superior to ten will be put at 10\n"
              "-p [number]          :      players, adjust the number of"
              " players (not "
              "optional yep) max 2\n"
              "-m [number][number]  :      adjust the number of rooms"
              " 10x1 default\n%s", BISGREEN, RESET);
}

static int my_init(game_t *game, char **av)
{
    if (game->flag->help == 1) {
        print_usage();
        free(game->flag);
        free(game);
        return 0;
    }
    if (game->flag->game_difficulty > 10)
        game->flag->game_difficulty = 10;
    if (game->flag->map_size[0] > 100)
        game->flag->map_size[0] = 100;
    if (game->flag->map_size[1] > 100)
        game->flag->map_size[1] = 100;
    if (game->flag->nb_players > 2)
        game->flag->nb_players = 2;
    free(game->flag);
    free(game);
    return 0;
}

int main(int ac, char **av, char **env)
{
    struct game_t *game = NULL;
    if (env[0] == NULL) {
        my_printf("Error: No environment found.");
        return (84);
    }
    game = malloc(sizeof(game_t));
    if (game == NULL) {
        my_printf("Error: Malloc failed.");
        return (84);
    }
    game->flag = malloc(sizeof(struct flag));
    if (game->flag == NULL) {
        my_printf("Error: Malloc failed.%f", game);
        return (84);
    }
    get_arguments(game, ac, av);
    return my_init(game, av);
}
