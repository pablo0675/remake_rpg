#pragma once

struct flag {
    int nb_players;
    int game_difficulty;
    int map_size[2];
    int help;
};

typedef struct game_t {
    struct flag *flag;
} game_t;

