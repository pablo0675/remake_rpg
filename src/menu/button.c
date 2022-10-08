/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** button
*/

#include "my_rpg.h"

void add_text_to_button(button_t *button, char *fontpath, char *str)
{
    sfFont *font = sfFont_createFromFile(fontpath);
    sfText *text = sfText_create();
    sfVector2f pos;

    pos.x  = button->pos.x;
    pos.y = button->pos.y + button->rect.height / 2;
    sfText_setFont(text, font);
    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    button->font = font;
    button->text = text;
}

void add_sprite_to_button(button_t *button, char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfFalse);
    button->texture = texture;
    button->sprite = sprite;
}

button_t *create_button(sfFloatRect rect, int fct, sfVector2f pos)
{
    button_t *button = malloc(sizeof(button_t));

    if (!button)
        return NULL;
    button->fct = fct;
    button->sprite = NULL;
    button->texture = NULL;
    button->sprite = NULL;
    button->rect = rect;
    button->pos = pos;
    return button;
}
