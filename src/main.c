#include "my_rpg.h"
#include <unistd.h>
#include <malloc.h>
#include "printf.h"
#include "struct.h"

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
    return 0;
}
