#pragma once
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include "variables.h"

struct flag {
    int nb_players;
    int game_difficulty;
    int map_size[2];
    int help;
};

typedef struct window_s {
    sfRenderWindow *window;
    int width;
    int height;
    char *title;
    sfVector2i mouse;
    sfMusic **filepath_sound;
    char **filepath_sprite;
} window_t;

typedef struct {
    sfText *text;
    sfFont *font;
    sfSound *sound;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    int status;
    int fct;
    sfFloatRect rect;
} button_t;

typedef struct {
    sfSprite *back;
    sfSprite *dark_back;
    sfSoundBuffer *intro;
    sfSoundBuffer *buf_theme;
    sfSound *music;
    sfSound *theme;
    button_t **button;
    sfText *title;
    int status;
} menu_t;

typedef struct game_t {
    struct flag *flag;
    menu_t *menu;
    window_t *window;
    int cursor_status;
    sfUint8 *calque;
    int status;
} game_t;

