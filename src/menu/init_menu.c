/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** init_menu
*/

#include "my_rpg.h"
#include "init.h"

sfSprite *create_sprite(char *pathfile)
{
    sfTexture *texture = sfTexture_createFromFile(pathfile, NULL);
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    return sprite;
}

static void create_music(menu_t *menu)
{
    sfSoundBuffer *buff = sfSoundBuffer_createFromFile("assets/intro.ogg");
    sfSound *music = sfSound_create();

    sfSound_setBuffer(music, buff);
    menu->buf_theme = sfSoundBuffer_createFromFile("assets/theme_menu.ogg");
    menu->intro = buff;
    menu->music = music;
    menu->theme = sfSound_create();
    sfSound_setBuffer(menu->theme ,menu->buf_theme);
}

static sfText *init_title(sfVector2f pos)
{
    sfFont *font = sfFont_createFromFile("assets/menu.otf");
    sfText *text = sfText_create();

    sfText_setString(text, "Castlevachat");
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setColor(text, sfBlack);
    sfText_setOutlineThickness(text, 5);
    sfText_setOutlineColor(text, sfWhite);
    sfText_setCharacterSize(text, 150);
    return text;
}

menu_t *init_menu(void)
{
    sfFloatRect rect = {850, 300, 100, 100};
    menu_t *menu = malloc(sizeof(menu_t));
    sfVector2f pos = {850, 300};

    menu->button = malloc(sizeof(button_t) * 3);
    if (!menu || !menu->button)
        return NULL;
    menu->title = init_title((sfVector2f) {400, 100});
    menu->back = create_sprite("assets/background_menu_light.png");
    menu->dark_back = create_sprite("assets/background_menu_red.png");
    menu->button[START] = create_button(rect, START, pos);
    rect.top += 200;
    pos.y  += 200;
    menu->button[QUIT] = create_button(rect, QUIT, pos);
    add_text_to_button(menu->button[QUIT], "assets/menu.otf", "Quit");
    add_text_to_button(menu->button[START], "assets/menu.otf", "Start");
    menu->button[2] = NULL;
    menu->status = 0;
    create_music(menu);
    return menu;
}
